#include "SpeedUpItem.h"
#include "MyPawn.h" 

ASpeedUpItem::ASpeedUpItem()
{
    ItemType = "SpeedUpItem";
}

void ASpeedUpItem::ActivateItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
		if (AMyPawn* Player = Cast<AMyPawn>(Activator))
		{
			Player->AddSpeed(SpeedUpAmount, BuffDuration);
		}
        DestroyItem();
    }
}
