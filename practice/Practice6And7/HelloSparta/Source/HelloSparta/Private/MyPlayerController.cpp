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
    // ����Ʈ �� ����  
    // ���� �÷��̾�Լ� EnhancedInputSystem�� �����ͼ� ���ν�Ű�� �ܰ�
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (InputMappingContextHuman)
            {
                // Subsystem�� ���� �츮�� �Ҵ��� IMC�� Ȱ��ȭ
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
            // ���� �ΰ� ��带 ���Ѵٸ�
            if (bIsHuman)
            {
                // Air IMC�� �ִٸ� ����
                if (InputMappingContextAir)
                {
                    Subsystem->RemoveMappingContext(InputMappingContextAir);
                }
                // Human IMC�� �ִٸ� Ȱ��ȭ 
                if (InputMappingContextHuman)
                {
                    Subsystem->AddMappingContext(InputMappingContextHuman, 0);
                }
            }
            else
            {
                // ���� �ݴ�
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

    //�����ڿ��� �˸�
    OnParentZEvent.Broadcast();
    UE_LOG(LogTemp, Warning, TEXT("now Context is  %s"), bIsHumanMapping ? TEXT("Human") : TEXT("Air"));
}
void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    //Bind ZŰ�� ������ PlayerController�ܰ迡�� ���ε� 
    //Setup Input Componenet , ���ڱ״�� Bind
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