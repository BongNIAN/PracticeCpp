


#include "MyPawn.h"
#include "MyPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/ArrowComponent.h" 
#include "GameFramework/SpringArmComponent.h"

//ArrowComponent�� Vector�� World��� 
//Local�� �ٲٰ� addLocaloffset�ϴϱ� �ʶչ��� �߻�..��
//�׳� Actor�� ���� �����ͼ� Ȯ���ϰ� �ϼ��� �س��� �������غ��� 
//Worldoffset���� �غ��� 

AMyPawn::AMyPawn()
{
   
    PrimaryActorTick.bCanEverTick = true;

    /**CapsuleComp*/
    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    RootComponent = CapsuleComp;
    CapsuleComp->SetSimulatePhysics(false);
    CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    //�� ���� ����� ���ظ� �� ���� ������ ä���� �ٸ��� �浹�� �Ͼ�� �ʴ±���..
    //��� ä�ο� ���� Block�ϵ��� ���� (Ȥ�� ������ ����)
    CapsuleComp->SetCollisionResponseToAllChannels(ECR_Block);


    CapsuleComp->InitCapsuleSize(100.0f, 22.0f);



    /**SkeletalMesh*/
    SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    SkeletalMeshComp->SetupAttachment(CapsuleComp);
    SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -CapsuleComp->GetScaledCapsuleHalfHeight()));
    
    /**ArrowComp*/
    ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
    ArrowComp->SetupAttachment(CapsuleComp);
    ArrowComp->SetRelativeLocation(FVector::ZeroVector);
    ArrowComp->SetHiddenInGame(false);
    /**SpringArmComp*/
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArmComp->SetupAttachment(CapsuleComp);
    SpringArmComp->TargetArmLength = 500.0f;
    SpringArmComp->bUsePawnControlRotation = true; 
    /**CameraComp*/
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
    CameraComp->bUsePawnControlRotation = false; //ī�޶� ���� ȸ������ �ʰ� ����

    /** Pawn�� ��Ʈ�ѷ� ȸ���� �������� ����*/
    bUseControllerRotationYaw = true;
    bUseControllerRotationPitch = false;
    /**Toggle PitchControll by IMC*/
    bIsZEvent = false;
    /**�����緯 ���� ����*/
    Propeller = FVector(0, 0, 1);

    CurrentSpeed = 180.0f;
    MaxSpeed = 500.0f;
    MaxPitch = 15.0f;
    AtMovePitch = 0.0f;
    MaxYaw = 15.0f;
    AtMoveYaw = 0.0f;
}

void AMyPawn::BeginPlay()
{
    Super::BeginPlay();
    if (AMyPlayerController* PC = Cast<AMyPlayerController>(GetController()))
    {   //������ ��� 
        PC->OnParentZEvent.AddUObject(this, &AMyPawn::OnZEventHandler);
    }
}



// �Է� ���ε�
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    UE_LOG(LogTemp, Warning, TEXT("Input start"));
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
                    &AMyPawn::Accel
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
            //Todo  : Roll
        }
    }
}

/** Look: ���콺 �Է��� �޾� Yaw, Pitch�� ����*/
void AMyPawn::Look(const FInputActionValue& Value)
{
    FVector2D LookInput = Value.Get<FVector2D>();
    AddControllerYawInput(LookInput.X);
    AddControllerPitchInput(LookInput.Y);
    
    //TODO: Propeller
}

/**Move : �ΰ������̵�  */ 
void AMyPawn::Move(const FInputActionValue& Value)
{
    const FVector2D MoveInput = Value.Get<FVector2D>(); // X: ��/��, Y: ��/��
    FVector Forward = GetActorForwardVector();
    FVector Right = GetActorRightVector();
    FVector ResultMove = (Forward * MoveInput.X + Right * MoveInput.Y)
        * CurrentSpeed * GetWorld()->GetDeltaSeconds();
    AddActorWorldOffset(ResultMove);
    HitAndSlide(&ResultMove);
}

/**Accel : ���� �̵�*/  
void AMyPawn::Accel(const FInputActionValue& Value)
{
    float AccelInput = Value.Get<float>();
    if (!FMath::IsNearlyZero(AccelInput)) {

        // ���: ���, ����: �ϰ�
        FVector Up = FVector(0.0f, 0.0f, AccelInput);
        FVector ResultAccel = Up * CurrentSpeed * GetWorld()->GetDeltaSeconds();
        /*AddActorWorldOffset(ResultAccel, true);*/
        HitAndSlide(&ResultAccel);
    }
}

/**MoveAir : ����� �̵�*/ 
void AMyPawn::MoveAir(const FInputActionValue& Value)
{
    const FVector2D MoveInput = Value.Get<FVector2D>();
    //x�� ������ ������ ������ �������� 
    // �̰� roll x=yaw ,y = yaw�� ���߰ڳ� ?
    //pitch�� ���� ���� 
    //�¿�� Yaw�ε� ������ ���� ������ pitch�ε�?
    //Roll�� ����

    AtMoveYaw += MoveInput.Y * 0.1f;
    if (AtMoveYaw > MaxYaw)
    {
        AtMoveYaw = MaxYaw;
        AddControllerYawInput(AtMoveYaw);
    }
    AtMovePitch += MoveInput.X * 0.1f;
    if (AtMovePitch > MaxPitch)
    {
        AtMovePitch = MaxPitch;
        AddControllerPitchInput(AtMovePitch);
    }
    FVector Forward = GetActorForwardVector();
    FVector Right = GetActorRightVector();
    FVector Up = GetActorUpVector();
    FVector ResultVector = Forward + Right + Up;
    FVector ResultMoveAir = ResultVector
        * CurrentSpeed * GetWorld()->GetDeltaSeconds();
    HitAndSlide(&ResultMoveAir);

    /*const FVector2D MoveInput = Value.Get<FVector2D>();
    FVector Forward = GetActorForwardVector();
    FVector Right = GetActorRightVector();
    FVector Up = GetActorUpVector();
    FVector ResultMoveAir = (Forward * MoveInput.X + Right * MoveInput.Y)
        * CurrentSpeed * GetWorld()->GetDeltaSeconds();*/
    //HitAndSlide(&ResultMoveAir);
}

/**TODO : ���ڰ� ����ü�ϱ� ���۷����� �����ͷ� �ٲ��� */
void AMyPawn::HitAndSlide(const FVector *Result) 
{
    FHitResult Hit;
    AddActorWorldOffset(*Result, true, &Hit);
    /*
    * ���࿡ ���⿡�� Hit������ ���� �߰����� offset�� �߸��� �ȴ�. ���̻� �������� ����
    * ���üũ �ʿ� (GPT)
    */

    if (Hit.bBlockingHit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Collision Start"));

        if (Hit.GetActor())
        {
            UE_LOG(LogTemp, Warning, TEXT("Collision : %s"), *Hit.GetActor()->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("No Valid Actor"));
        }
        // �浹 ǥ���� ���� ���͸� �����´�.
        FVector ImpactNormal = Hit.ImpactNormal;
        //�浹�� ����� �������͸� �̿��ϸ� ���翵���͸� ���� �� �ִ�.
        FVector SlidingResult = FVector::VectorPlaneProject(*Result, ImpactNormal);
        AddActorWorldOffset(SlidingResult, true);
    }
}

/**������ �ൿ*/
void AMyPawn::OnZEventHandler()
{
    UE_LOG(LogTemp, Warning, TEXT("im EventHandler After Broadcasting"));
    bIsZEvent = !bIsZEvent;
    /**Pawn�� ȸ���� Pitch�� ������ ������ �ƴ��� ����*/
    bUseControllerRotationPitch = bIsZEvent;
}

void AMyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 //���⿡ �ް� �ƴѰͰ����� �����غ��ϱ�
    // �ֳ��ϸ� Pitch�� 15�� �����Ǿ���� ��ǲ�� ���ݾ� 
    /*   if (AtMovePitch >= MaxPitch)
    {
        AtMovePitch = MaxPitch;
    }
    if (AtMoveYaw >= MaxYaw)
    {
        AtMoveYaw = MaxYaw;
    }*/

}





