#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "ReverseItem.generated.h"

UCLASS()
class HELLOSPARTA_API AReverseItem : public ABaseItem
{
	GENERATED_BODY()
public:
    AReverseItem();
protected:
    virtual void ActivateItem(AActor* Activator) override;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Buff")
    float DebuffDuration = 10.f;
};
