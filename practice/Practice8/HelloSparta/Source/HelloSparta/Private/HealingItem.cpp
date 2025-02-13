#include "HealingItem.h"
#include "MyPawn.h" 

AHealingItem::AHealingItem()
{
    HealAmount = 20.0f;
    ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
        if (AMyPawn* Player = Cast<AMyPawn>(Activator))
        {
            Player->AddHealth(HealAmount);
        }
        DestroyItem();
    }
}