#include "WavePassItem.h"
#include "Engine/World.h"
#include "MyGameState.h"
#include "MyPlayerController.h" 
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"

AWavePassItem::AWavePassItem()
{
    ItemType = "WavePassItem"; 
    InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
    InteractionWidget->SetupAttachment(Scene);
    InteractionWidget->SetWidgetSpace(EWidgetSpace::World);
    InteractionWidget->SetVisibility(false);
    AutoReceiveInput = EAutoReceiveInput::Player0;
}

void AWavePassItem::ActivateItem(AActor* Activator)
{
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("When Collect WavePassItem")));
    if (Activator && Activator->ActorHasTag("Player"))
    {
        if (InteractionWidget)
        {
            InteractionWidget->SetVisibility(true);
        }
        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        if (PC)
        {
            EnableInput(PC);
            if (InputComponent)
            {
                InputComponent->BindAction("Interact", IE_Pressed, this, &AWavePassItem::OnInteractPressed);
            }
        } 
    }
}
void AWavePassItem::OnInteractPressed()
{
    if (UWorld* World = GetWorld())
    {
        if (AMyGameState* GameState = World->GetGameState<AMyGameState>())
        {
            GameState->OnPassItemCollected();
            DestroyItem();
        }
    }
}
