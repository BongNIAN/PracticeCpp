#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SpeedUpItem.generated.h"

UCLASS()
class HELLOSPARTA_API ASpeedUpItem : public ABaseItem
{
	GENERATED_BODY()
public:
	ASpeedUpItem();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Buff")
	float BuffDuration = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	int32 SpeedUpAmount = 200;
	
	virtual void ActivateItem(AActor* Activator) override;
};
