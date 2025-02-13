#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SpikeTrapItem.generated.h"

UCLASS()
class HELLOSPARTA_API ASpikeTrapItem : public ABaseItem
{
	GENERATED_BODY()
public:
	ASpikeTrapItem();
	virtual void ActivateItem(AActor* Activator) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float Frequency;
	virtual void BeginPlay() override;
	FVector InitialLocation;
	float Damage;
public:
	virtual void Tick(float DeltaTime) override;
};
