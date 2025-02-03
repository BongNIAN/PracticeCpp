


#include "MyPawn.h"
#include "MyPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/ArrowComponent.h" 
#include "GameFramework/SpringArmComponent.h"

//ArrowComponent의 Vector는 World기반 
//Local로 바꾸고 addLocaloffset하니깐 맵뚫버그 발생..ㅠ
//그냥 Actor의 방향 가져와서 확실하게 완성을 해놓고 실험을해보자 
//Worldoffset으로 해보기 

AMyPawn::AMyPawn()
{
   
    PrimaryActorTick.bCanEverTick = true;

    /**CapsuleComp*/
    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    RootComponent = CapsuleComp;
    CapsuleComp->SetSimulatePhysics(false);
    CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    //아 뭔지 제대로 이해를 할 수는 없지만 채널이 다르면 충돌이 일어나지 않는구나..
    //모든 채널에 대해 Block하도록 설정 (혹은 적절히 조정)
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
    CameraComp->bUsePawnControlRotation = false; //카메라에 의해 회전되지 않게 조정

    /** Pawn이 컨트롤러 회전을 따르도록 설정*/
    bUseControllerRotationYaw = true;
    bUseControllerRotationPitch = false;
    /**Toggle PitchControll by IMC*/
    bIsZEvent = false;
    /**프로펠러 역할 수행*/
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
    {   //구독자 등록 
        PC->OnParentZEvent.AddUObject(this, &AMyPawn::OnZEventHandler);
    }
}



// 입력 바인딩
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

/** Look: 마우스 입력을 받아 Yaw, Pitch를 적용*/
void AMyPawn::Look(const FInputActionValue& Value)
{
    FVector2D LookInput = Value.Get<FVector2D>();
    AddControllerYawInput(LookInput.X);
    AddControllerPitchInput(LookInput.Y);
    
    //TODO: Propeller
}

/**Move : 인간형태이동  */ 
void AMyPawn::Move(const FInputActionValue& Value)
{
    const FVector2D MoveInput = Value.Get<FVector2D>(); // X: 좌/우, Y: 전/후
    FVector Forward = GetActorForwardVector();
    FVector Right = GetActorRightVector();
    FVector ResultMove = (Forward * MoveInput.X + Right * MoveInput.Y)
        * CurrentSpeed * GetWorld()->GetDeltaSeconds();
    AddActorWorldOffset(ResultMove);
    HitAndSlide(&ResultMove);
}

/**Accel : 수직 이동*/  
void AMyPawn::Accel(const FInputActionValue& Value)
{
    float AccelInput = Value.Get<float>();
    if (!FMath::IsNearlyZero(AccelInput)) {

        // 양수: 상승, 음수: 하강
        FVector Up = FVector(0.0f, 0.0f, AccelInput);
        FVector ResultAccel = Up * CurrentSpeed * GetWorld()->GetDeltaSeconds();
        /*AddActorWorldOffset(ResultAccel, true);*/
        HitAndSlide(&ResultAccel);
    }
}

/**MoveAir : 비행기 이동*/ 
void AMyPawn::MoveAir(const FInputActionValue& Value)
{
    const FVector2D MoveInput = Value.Get<FVector2D>();
    //x를 누르면 앞으로 가려면 숙여야함 
    // 이게 roll x=yaw ,y = yaw로 들어가야겠네 ?
    //pitch는 위로 가게 
    //좌우는 Yaw인데 전진은 뭐지 전진이 pitch인데?
    //Roll은 뭐지

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

/**TODO : 인자가 구조체니깐 레퍼런스나 포인터로 바꾸자 */
void AMyPawn::HitAndSlide(const FVector *Result) 
{
    FHitResult Hit;
    AddActorWorldOffset(*Result, true, &Hit);
    /*
    * 만약에 여기에서 Hit판정이 나면 추가적인 offset은 잘리게 된다. 더이상 움직이지 않음
    * 사실체크 필요 (GPT)
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
        // 충돌 표면의 법선 벡터를 가져온다.
        FVector ImpactNormal = Hit.ImpactNormal;
        //충돌한 평면의 법선벡터를 이용하면 정사영벡터를 구할 수 있다.
        FVector SlidingResult = FVector::VectorPlaneProject(*Result, ImpactNormal);
        AddActorWorldOffset(SlidingResult, true);
    }
}

/**구독자 행동*/
void AMyPawn::OnZEventHandler()
{
    UE_LOG(LogTemp, Warning, TEXT("im EventHandler After Broadcasting"));
    bIsZEvent = !bIsZEvent;
    /**Pawn의 회전이 Pitch에 영향을 받을지 아닐지 조정*/
    bUseControllerRotationPitch = bIsZEvent;
}

void AMyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 //여기에 달게 아닌것같은데 생각해보니깐
    // 왜냐하면 Pitch가 15로 고정되어봐야 인풋은 들어가잖아 
    /*   if (AtMovePitch >= MaxPitch)
    {
        AtMovePitch = MaxPitch;
    }
    if (AtMoveYaw >= MaxYaw)
    {
        AtMoveYaw = MaxYaw;
    }*/

}





