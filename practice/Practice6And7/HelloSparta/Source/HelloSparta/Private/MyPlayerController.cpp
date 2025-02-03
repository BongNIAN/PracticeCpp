// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AMyPlayerController::AMyPlayerController()
	:InputMappingContextAir(nullptr),
    InputMappingContextHuman(nullptr),
    MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr),
    AccelAction(nullptr),
    ToggleAction(nullptr),
    MoveAirAction(nullptr),
    bIsHumanMapping(true)
{

}
void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("MyPlayerStart"));
    // 디폴트 값 설정  
    // 현재 플레이어에게서 EnhancedInputSystem을 가져와서 매핑시키는 단계
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (InputMappingContextHuman)
            {
                // Subsystem을 통해 우리가 할당한 IMC를 활성화
                Subsystem->AddMappingContext(InputMappingContextHuman, 0);
                UE_LOG(LogTemp, Warning, TEXT("MyPlayerEnd"));
            }
        }
    }
}
void AMyPlayerController::SwitchContext(bool bIsHuman)
{
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            // 만약 인간 모드를 원한다면
            if (bIsHuman)
            {
                // Air IMC가 있다면 제거
                if (InputMappingContextAir)
                {
                    Subsystem->RemoveMappingContext(InputMappingContextAir);
                }
                // Human IMC가 있다면 활성화 
                if (InputMappingContextHuman)
                {
                    Subsystem->AddMappingContext(InputMappingContextHuman, 0);
                }
            }
            else
            {
                // 위와 반대
                if (InputMappingContextHuman)
                {
                    Subsystem->RemoveMappingContext(InputMappingContextHuman);
                }
                if (InputMappingContextAir)
                {
                    Subsystem->AddMappingContext(InputMappingContextAir, 0);
                }
            }
        }
    }
}
void AMyPlayerController::ToggleContext(const FInputActionValue& Value)
{
    
    bIsHumanMapping = !bIsHumanMapping;

    SwitchContext(bIsHumanMapping);

    //구독자에게 알림
    OnParentZEvent.Broadcast();
    UE_LOG(LogTemp, Warning, TEXT("now Context is  %s"), bIsHumanMapping ? TEXT("Human") : TEXT("Air"));
}
void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    //Bind Z키를 누르면 PlayerController단계에서 바인드 
    //Setup Input Componenet , 문자그대로 Bind
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
    {
        if (ToggleAction)
        {
            EnhancedInput->BindAction(ToggleAction,
                ETriggerEvent::Triggered,
                this,
                &AMyPlayerController::ToggleContext);
        }
    }
}