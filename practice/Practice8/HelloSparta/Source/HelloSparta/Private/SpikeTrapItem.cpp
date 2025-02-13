#include "SpikeTrapItem.h"
#include "MyPawn.h"
#include "Kismet/GameplayStatics.h"

ASpikeTrapItem::ASpikeTrapItem()
{
    ItemType = "SpikeTrap";
    Amplitude = 50.f;
    Frequency = 1.f;
    Damage = 30.f;
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
    float SineValue = FMath::Sin(GetWorld()->GetTimeSeconds() * Frequency * 2 * PI);
    float DeltaZ = Amplitude * SineValue;
    FVector NewLocation = InitialLocation;
    NewLocation.Z += DeltaZ;
    SetActorLocation(NewLocation);
}