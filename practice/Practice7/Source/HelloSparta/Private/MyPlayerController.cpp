// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AMyPlayerController::AMyPlayerController()
	:InputMappingContextAir(nullptr),
    InputMappingContextHuman(nullptr),
    MoveAction(nullptr),
	LookAction(nullptr),
    AccelAction(nullptr),
    ToggleAction(nullptr),
    MoveAirAction(nullptr),
    StopGravityAction(nullptr),
    bIsHumanMapping(true)
{

}
void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (InputMappingContextHuman)
            {
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
            if (bIsHuman)
            {
                if (InputMappingContextAir)
                {
                    Subsystem->RemoveMappingContext(InputMappingContextAir);
                }
                if (InputMappingContextHuman)
                {
                    Subsystem->AddMappingContext(InputMappingContextHuman, 0);
                }
            }
            else
            {
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
    OnParentZEvent.Broadcast();
    UE_LOG(LogTemp, Warning, TEXT("now Context is  %s"), bIsHumanMapping ? TEXT("Human") : TEXT("Air"));
}
void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
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

//Bind Z키를 누르면 PlayerController단계에서 바인드 
   //Setup Input Componenet , 문자그대로 Bind