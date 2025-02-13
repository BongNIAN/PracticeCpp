#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawnRow.h"   
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class HELLOSPARTA_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
public : 
    ASpawnVolume();

    UFUNCTION(BlueprintCallable, Category = "Spawning")
    AActor* SpawnRandomItem();

    UFUNCTION(BlueprintCallable, Category = "Spawning")
    AActor* SpawnItem(TSubclassOf<AActor> ItemClass);

protected:
   
    FItemSpawnRow* GetRandomItem() const;

    UFUNCTION(BlueprintCallable, Category = "Spawning")
    FVector GetRandomPointInVolume() const;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    USceneComponent* Scene;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    UBoxComponent* SpawningBox;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    UDataTable* ItemDataTable = nullptr;
};
