#include "SpikeTrapItem.h"
#include "MyPawn.h"
#include "Kismet/GameplayStatics.h"

ASpikeTrapItem::ASpikeTrapItem()
{
    ItemType = "SpikeTrap";
    Amplitude = 500.f;
    Frequency = 1.f;
    Damage = 30.f;
    PrimaryActorTick.bCanEverTick = true;
}
void ASpikeTrapItem::ActivateItem(AActor* Activator)
{
    if (APawn* Actor = Cast<AMyPawn>(Activator))
    {
        if (Actor && Actor->ActorHasTag("Player"))
        {
            UGameplayStatics::ApplyDamage(
                Actor,
                Damage,
                nullptr,
                this,
                UDamageType::StaticClass()
            );
        }
    }
        
    
}
void ASpikeTrapItem::BeginPlay()
{
    Super::BeginPlay();
    InitialLocation = GetActorLocation();
    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("스파이크 함정이 활성화되었습니다!"));


}

void ASpikeTrapItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    float TimeSeconds = GetWorld()->GetTimeSeconds();
    float NormalizedValue = (1 - FMath::Cos(2 * PI * Frequency * TimeSeconds)) / 2.0f;
    float DeltaZ = Amplitude * NormalizedValue;
    FVector NewLocation = InitialLocation;
    NewLocation.Z += DeltaZ; 
    SetActorLocation(NewLocation);
}