#include "MyPawn.h"
#include "MyPlayerController.h"
#include "MyGameState.h"
#include "TimerManager.h"
#include "MyGameInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/ArrowComponent.h" 
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

AMyPawn::AMyPawn()
{

	PrimaryActorTick.bCanEverTick = true;
	/**Set CapsuleComp*/
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComp;
	CapsuleComp->SetSimulatePhysics(false);
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Block);
	CapsuleComp->InitCapsuleSize(100.0f, 22.0f);

	/**Set SkeletalMesh*/
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComp->SetupAttachment(CapsuleComp);
	SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -CapsuleComp->GetScaledCapsuleHalfHeight()));

	/**Set ArrowComp*/
	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComp->SetupAttachment(CapsuleComp);
	ArrowComp->SetRelativeLocation(FVector::ZeroVector);
	ArrowComp->SetHiddenInGame(false);

	/**Set SpringArmComp*/
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->TargetArmLength = 500.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	/**Set CameraComp*/
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false; //카메라에 의해 회전되지 않게 조정

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	OverheadWidget->SetupAttachment(SkeletalMeshComp);
	OverheadWidget->SetWidgetSpace(EWidgetSpace::Screen);

	/** Set ControllerRotation*/
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	UpdateOverheadHP();
	if (AMyPlayerController* PC = Cast<AMyPlayerController>(GetController()))
	{
		PC->OnParentZEvent.AddUObject(this, &AMyPawn::OnZEventHandler);
	}
	if (UMyGameInstance* GI = Cast<UMyGameInstance>(GetGameInstance()))
	{
		float RemainSpeedBuffDuration = GI->LoadedBuffDuration();
		float RemainReverseDebuffDuration = GI->LoadedDebuffDuration();

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Level Start Remain time is %.1f"), RemainSpeedBuffDuration));
		
		if (RemainSpeedBuffDuration > 1.f)
		{
			CurrentSpeed += 500.f;
			GetWorldTimerManager().SetTimer(SpeedBuffTimerHandle, this, &AMyPawn::ResetSpeed, RemainSpeedBuffDuration, false);
		}
		if (RemainReverseDebuffDuration > 1.f)
		{
			bIsReverse = true;
			GetWorldTimerManager().SetTimer(ReverseDebuffTimerHandle, this, &AMyPawn::ResetDirection, RemainReverseDebuffDuration, false);
		}

	}
	GetWorldTimerManager().SetTimer(
		PawnHUDUpdateTimerHandle,
		this,
		&AMyPawn::UpdateHUD,
		0.1f,
		true
	);

}
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Move
				);
			}
			if (PlayerController->AccelAction)
			{
				EnhancedInput->BindAction(
					PlayerController->AccelAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Up
				);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Look
				);
			}
			if (PlayerController->MoveAirAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAirAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::MoveAir
				);
			}
			if (PlayerController->StopGravityAction)
			{
				EnhancedInput->BindAction(
					PlayerController->StopGravityAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::StopGravity
				);
			}
		}
	}
}
void AMyPawn::Look(const FInputActionValue& Value)
{
	FVector2D LookInput = Value.Get<FVector2D>();
	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}
/**Human*/
void AMyPawn::Move(const FInputActionValue& Value)
{
	SaveInput = Value.Get<FVector2D>();
	const FVector2D MoveInput = Value.Get<FVector2D>();
	FVector Forward = GetActorForwardVector();
	FVector Right = GetActorRightVector();
	FVector InputMove = (Forward * MoveInput.X + Right * MoveInput.Y)
		* CurrentSpeed * GetWorld()->GetDeltaSeconds();
	FVector ResultMove = InputMove;
	if (bIsReverse) 
	{
		FVector Reverse = FVector(-1, -1, 1);
		ResultMove = InputMove * Reverse;
	}
	HitAndSlide(&ResultMove);
}
void AMyPawn::Up(const FInputActionValue& Value)
{
	float AccelInput = Value.Get<float>();
	if (!FMath::IsNearlyZero(AccelInput))
	{
		FVector Up = FVector(0.0f, 0.0f, AccelInput);
		FVector ResultAccel = Up * CurrentSpeed * GetWorld()->GetDeltaSeconds();
		HitAndSlide(&ResultAccel);
	}
}
void AMyPawn::MoveAir(const FInputActionValue& Value)
{
	SaveInput = Value.Get<FVector2D>();
	const FVector2D MoveInput = Value.Get<FVector2D>();
	float PrevAtMoveYaw = AtMoveYaw;
	float PrevAtMovePitch = AtMovePitch;
	AtMovePitch += MoveInput.X;
	AtMoveYaw += MoveInput.Y;

	float ClampedAtMoveYaw = FMath::Clamp(AtMoveYaw, -MaxYaw, MaxYaw);
	float ClampedAtMovePitch = FMath::Clamp(AtMovePitch, -MaxPitch, MaxPitch);

	float DeltaYaw = ClampedAtMoveYaw - PrevAtMoveYaw;
	float DeltaPitch = ClampedAtMovePitch - PrevAtMovePitch;
	AddControllerYawInput(DeltaYaw);
	AddControllerPitchInput(DeltaPitch);

	AtMoveYaw = ClampedAtMoveYaw;
	AtMovePitch = ClampedAtMovePitch;

	FVector InputBasedDir = (GetActorForwardVector() * MoveInput.X + GetActorRightVector() * MoveInput.Y);
	if (!InputBasedDir.IsNearlyZero())
	{
		InputBasedDir.Normalize();
	}
	FVector InherentDir = GetActorForwardVector() + GetActorRightVector() + GetActorUpVector();
	FVector CombinedDir = (InputBasedDir * 0.7f) + (InherentDir * 0.3f);
	if (!CombinedDir.IsNearlyZero())
	{
		CombinedDir.Normalize();
	}
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	float ChangedCurrent = bIsGround() ? CurrentSpeed : (CurrentSpeed * 0.5f);
	FVector MoveOffset = CombinedDir * ChangedCurrent * DeltaTime;
	HitAndSlide(&MoveOffset);
}
void AMyPawn::HitAndSlide(const FVector* Result)
{
	FHitResult Hit;
	AddActorWorldOffset(*Result, true, &Hit);
	if (Hit.bBlockingHit)
	{
		if (Hit.GetActor()) {
			
			// Get NormalVector(ImpactPlane)
			FVector ImpactNormal = Hit.ImpactNormal;
			// Get Projection Vector 
			FVector SlidingResult = FVector::VectorPlaneProject(*Result, ImpactNormal);
			AddActorWorldOffset(SlidingResult);
		}
	}
}
void AMyPawn::OnZEventHandler()
{
	UE_LOG(LogTemp, Warning, TEXT("im in Pawn EventHandler After Broadcasting"));
	bIsZEvent = !bIsZEvent;
	bUseControllerRotationPitch = bIsZEvent;
}
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult HitTick = GetImpactObject();
	FVector DeltaVelocity = FVector::ZeroVector;
	if (!HitTick.GetActor() && !StopGravityOffset)
	{
		GravityVelocity += GravityAcceleration * DeltaTime;
		DeltaVelocity = GravityVelocity * DeltaTime;
	}
	else if (HitTick.GetActor())
	{
		
		DeltaVelocity = GravityVelocity * DeltaTime;
		GravityVelocity.Z = 0.0f;
	}
	HitAndSlide(&DeltaVelocity);
}
bool AMyPawn::bIsGround()
{
	FHitResult Hit = GetImpactObject();
	if (Hit.GetActor())
	{
		return true;
	}
	else
	{
		return false;
	}
}
FHitResult AMyPawn::GetImpactObject()
{
	FHitResult Hit;
	FVector ActorLocation = GetActorLocation();
	float CapsuleHalf = CapsuleComp->GetScaledCapsuleHalfHeight();
	FVector Start = ActorLocation - FVector(0.f, 0.f, CapsuleHalf);
	FVector MeasureDistance = FVector(0.f, 0.f, 3.f);
	FVector End = Start - MeasureDistance;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, QueryParams);
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.f, 0, 1.f);
	return Hit;
}
void AMyPawn::StopGravity(const FInputActionValue& Value)
{
	StopGravityOffset = !StopGravityOffset;
	UE_LOG(LogTemp, Warning, TEXT("Gravity : %d"), !StopGravityOffset);
}
void AMyPawn::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.f, MaxHealth);
	UpdateOverheadHP();
}

float AMyPawn::TakeDamage(float DamageAmount, 
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount,
		DamageEvent,
		EventInstigator,
		DamageCauser
	);
	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
	UpdateOverheadHP();

	if (Health <= 0.0f)
	{
		OnDeath();
	}
	return ActualDamage;

}
void AMyPawn::OnDeath()
{
	AMyGameState* MyGameState = GetWorld() ? GetWorld()->GetGameState<AMyGameState>() : nullptr;
	if (MyGameState)
	{
		MyGameState->OnGameOver();
	}
}
int32 AMyPawn::GetHealth() const
{
	return Health;
}
int32 AMyPawn::GetSpeed() const
{
	return CurrentSpeed;
}
void AMyPawn::AddSpeed(float Amount,float Duration)
{
	CurrentSpeed = FMath::Clamp(CurrentSpeed+ Amount, 0.0f, MaxSpeed);
	float CurrentTime = GetWorld()->GetTimeSeconds();

	if (UMyGameInstance* GI = Cast<UMyGameInstance>(GetGameInstance()))
	{
		GI->SetBuffInformation(CurrentTime, Duration);
		float EffectiveDuration = GI->GetRemainingBuffTime(CurrentTime);
		GetWorldTimerManager().ClearTimer(SpeedBuffTimerHandle);
		GetWorldTimerManager().SetTimer(SpeedBuffTimerHandle, this, &AMyPawn::ResetSpeed, EffectiveDuration, false);
	}
}
void AMyPawn::ResetSpeed()
{
	CurrentSpeed = SavedCurrentSpeed;
	if (UMyGameInstance* GI = Cast<UMyGameInstance>(GetGameInstance()))
	{
		GI->BuffTotalDuration = 0.f;
		GI->BuffStartTime = 0.f;
	}
}
void AMyPawn::ChangeReverseDirection(float Duration)
{
	bIsReverse = true;
	float CurrentTime = GetWorld()->GetTimeSeconds();
	if (UMyGameInstance* GI = Cast<UMyGameInstance>(GetGameInstance()))
	{
		GI->SetDebuffInformation(CurrentTime, Duration);
		float EffectiveDuration = GI->GetRemainingDebuffTime(CurrentTime);
		GetWorldTimerManager().ClearTimer(ReverseDebuffTimerHandle);
		GetWorldTimerManager().SetTimer(ReverseDebuffTimerHandle, this, &AMyPawn::ResetDirection, EffectiveDuration, false);
	}
}
void AMyPawn::ResetDirection()
{
	bIsReverse = false;
}
void AMyPawn::UpdateOverheadHP()
{
	if (!OverheadWidget) return;

	UUserWidget* OverheadWidgetInstance = OverheadWidget->GetUserWidgetObject();
	if (!OverheadWidgetInstance) return;

	if (UProgressBar* HPProgressBar = Cast<UProgressBar>(OverheadWidgetInstance->GetWidgetFromName(TEXT("HPProgressBar"))))
	{
		
		const float HPPercent = (MaxHealth > 0.f) ? (Health / MaxHealth) : 0.f;
		HPProgressBar->SetPercent(HPPercent);
	}

	if (UTextBlock* HPText = Cast<UTextBlock>(OverheadWidgetInstance->GetWidgetFromName(TEXT("OverHeadHP"))))
	{
		HPText->SetText(FText::FromString(FString::Printf(TEXT("%.0f / %.0f"), Health, MaxHealth)));
	}
}
void AMyPawn::UpdateHUD()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController);
		{
			if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
			{
				if (UTextBlock* Buff = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Buff"))))
				{
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(SpeedBuffTimerHandle);
					if (RemainingTime < 0)
					{
						RemainingTime = 0.f;
					}
					Buff->SetText(FText::FromString(FString::Printf(TEXT("SpeedBuff: %.1f"), RemainingTime)));
				}

				if (UTextBlock* Debuff = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Debuff"))))
				{
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(ReverseDebuffTimerHandle);
					if (RemainingTime < 0)
					{
						RemainingTime = 0.f;
					}
					Debuff->SetText(FText::FromString(FString::Printf(TEXT("Reverse: %.1f"), RemainingTime)));
				}
			}
		}
	}
}