#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "WavePassItem.generated.h"

class UWidgetComponent;

UCLASS()
class HELLOSPARTA_API AWavePassItem : public ABaseItem
{
	GENERATED_BODY()
public:
    AWavePassItem();
    
protected:
    virtual void ActivateItem(AActor* Activator) override;
    void OnInteractPressed();
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UWidgetComponent* InteractionWidget;
};
