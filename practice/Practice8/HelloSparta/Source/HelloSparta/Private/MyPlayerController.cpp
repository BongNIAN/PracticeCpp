#include "MyPlayerController.h"
#include "MyGameState.h"
#include "MyGameInstance.h" 
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"


AMyPlayerController::AMyPlayerController()
	:InputMappingContextAir(nullptr),
    InputMappingContextHuman(nullptr),
    MoveAction(nullptr),
	LookAction(nullptr),
    AccelAction(nullptr),
    ToggleAction(nullptr),
    MoveAirAction(nullptr),
    StopGravityAction(nullptr),
    HUDWidgetClass(nullptr),
    HUDWidgetInstance(nullptr),
    MainMenuWidgetClass(nullptr),
    MainMenuWidgetInstance(nullptr),
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
    FString CurrentMapName = GetWorld()->GetMapName();
    if (CurrentMapName.Contains("MenuLevel"))
    {
        ShowMainMenu(false);
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
UUserWidget* AMyPlayerController::GetHUDWidget() const
{
    return HUDWidgetInstance;
}
void AMyPlayerController::ShowMainMenu(bool bIsRestart)
{
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}
	if (MainMenuWidgetInstance)
	{
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}
	if (MainMenuWidgetClass)
	{
		MainMenuWidgetInstance = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (MainMenuWidgetInstance)
		{
			MainMenuWidgetInstance->AddToViewport();

			bShowMouseCursor = true;
			SetInputMode(FInputModeUIOnly());
		}

		if (UTextBlock* ButtonText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName(TEXT("StartButtonText"))))
		{
			if (bIsRestart)
			{
				ButtonText->SetText(FText::FromString(TEXT("Restart")));
			}
			else
			{
				ButtonText->SetText(FText::FromString(TEXT("Start")));
			}
		}
		if (bIsRestart)
		{
			UFunction* PlayAnimFunc = MainMenuWidgetInstance->FindFunction(FName("PlayGameOverAnim"));
			if (PlayAnimFunc)
			{
				MainMenuWidgetInstance->ProcessEvent(PlayAnimFunc, nullptr);
			}

			if (UTextBlock* TotalScoreText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName("TotalScoreText")))
			{
				if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this)))
				{
					TotalScoreText->SetText(FText::FromString(
						FString::Printf(TEXT("Total Score: %d"), MyGameInstance->TotalScore)
					));
				}
			}
		}
	}
}
void AMyPlayerController::ShowGameHUD()
{
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}
	if (MainMenuWidgetInstance)
	{
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}
	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance)
		{
			HUDWidgetInstance->AddToViewport();
			bShowMouseCursor = false;
			SetInputMode(FInputModeGameOnly());
			AMyGameState* GameState = GetWorld() ? GetWorld()->GetGameState<AMyGameState>() : nullptr;
			if (GameState)
			{
                GameState->UpdateHUD();
			}
		}
	}
}
void AMyPlayerController::StartGame()
{
	if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
        MyGameInstance->CurrentLevelIndex = 0;
        MyGameInstance->TotalScore = 0;
		MyGameInstance->OnGameOverSetSpeed(0.f, 0.f);
		MyGameInstance->OnGameOverSetDebuff(0.f, 0.f);
	}
	UGameplayStatics::OpenLevel(GetWorld(), FName("BasicLevel"));
	SetPause(false);
}