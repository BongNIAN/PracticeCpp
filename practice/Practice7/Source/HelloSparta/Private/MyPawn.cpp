


#include "MyPawn.h"
#include "MyPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/ArrowComponent.h" 
#include "GameFramework/SpringArmComponent.h"



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

	/** Set ControllerRotation*/
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	if (AMyPlayerController* PC = Cast<AMyPlayerController>(GetController()))
	{
		PC->OnParentZEvent.AddUObject(this, &AMyPawn::OnZEventHandler);
	}
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
	FVector ResultMove = (Forward * MoveInput.X + Right * MoveInput.Y)
		* CurrentSpeed * GetWorld()->GetDeltaSeconds();
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
			UE_LOG(LogTemp, Warning, TEXT("Hit And Slide Collision : %s"), *Hit.GetActor()->GetName());
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
		UE_LOG(LogTemp, Warning, TEXT("Tick Collision : %s"), *HitTick.GetActor()->GetName());
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



/**Memo*/
/**1차 버전*/
/*const FVector2D MoveInput = Value.Get<FVector2D>();
FVector Forward = GetActorForwardVector();
FVector Right = GetActorRightVector();

FVector ResultMoveAir = (Forward * MoveInput.X + Right * MoveInput.Y)
    * CurrentSpeed * GetWorld()->GetDeltaSeconds();*/
    //HitAndSlide(&ResultMoveAir);

////ArrowComponent의 Vector는 World기반 
//Local로 바꾸고 addLocaloffset하니깐 맵뚫버그 발생..ㅠ
//그냥 Actor의 방향 가져와서 확실하게 완성을 해놓고 실험을해보자 
//Worldoffset으로 해보기
// 


    //Human Velocity
  /*  FVector ResultMove2 = (Forward * MoveInput.X + Right * MoveInput.Y)
        * CurrentSpeed;

    if (PawnVelocity.Size() <= MaxSpeed)
    {
        PawnVelocity.X = ResultMove2.X;
        PawnVelocity.Y = ResultMove2.Y;

    }*/
    //Up Velocity
   /* if (PawnVelocity.Size() <= MaxSpeed)
    {
        PawnVelocity.Z = AccelInput * CurrentSpeed;
    }*/
    //   //Move Air Velocity
     // // if (PawnVelocity.Size() <= MaxSpeed)
     //   {
     //       PawnVelocity = CombinedDir * ChangedCurrent;
        //}
 //아..이게  Hit에 저장시켜주는거구나..
    /*
    * 만약에 여기에서 Hit판정이 나면 추가적인 offset은 잘리게 된다. 더이상 움직이지 않음
    * 사실체크 필요 (GPT)
    */

////루트 컴포넌트를 감싸고 안의 컴포넌트를 돌리면 어차피 캡슐 컴포넌트는 아래에 있기때문에 무조건 지면의 바닥에 Trace한다 .
// 
  //프로필을 설정하면 lineTrace에서 프로필 기준으로도 설정할 수 잇따. 오브젝트 타입도 가능하다 
    //unrealCollision 공식문서에 대해서 둘중에 하나가 오버렙이면 뚫린다
    //그래서 블락블락처리해줘야한다. 

    //라인트레이스는 자기 자신도 항상 탐지하기때문에
    // 자기자신을 무시하게 파라미터를 조정해줘야한다
