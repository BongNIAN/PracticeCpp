#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "MineItem.generated.h"

UCLASS()
class HELLOSPARTA_API AMineItem : public ABaseItem
{
	GENERATED_BODY()
public:
	AMineItem();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* ExplosionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Effects")
	UParticleSystem* ExplosionParticle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionDelay = 5.f;
	// ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float ExplosionRadius = 300.f;
	// ���� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	int ExplosionDamage = 30.f;
	bool bHasExploded = false;
	FTimerHandle ExplosionTimerHandle;
	virtual void ActivateItem(AActor* Activator) override;
	void Explode();
};
