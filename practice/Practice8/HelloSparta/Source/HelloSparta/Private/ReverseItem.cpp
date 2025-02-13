#include "ReverseItem.h"
#include "MyPawn.h" 

AReverseItem::AReverseItem()
{
    ItemType = "ReverseItem";
}

void AReverseItem::ActivateItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
        if (AMyPawn* Player = Cast<AMyPawn>(Activator))
        {
            Player->ChangeReverseDirection(DebuffDuration);
        }
    }
    DestroyItem();
}


