#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

class AWavePassItem;
class ABaseItem;
class ASpikeTrapItem;

UCLASS()
class HELLOSPARTA_API AMyGameState : public AGameState
{
	GENERATED_BODY()
public:
	AMyGameState();
	virtual void BeginPlay() override;
	void StartLevel();
	void OnLevelTimeUp();
	void OnCoinCollected();
	void EndLevel();
	void UpdateHUD();
	void OnPassItemCollected();
	void SpawnRandom();
	void NextWave();
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Score")
	int32 Score;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	int32 WaveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AWavePassItem> PassItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ASpikeTrapItem> TrapItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	FTimerHandle LevelTimerHandle;
	FTimerHandle HUDUpdateTimerHandle;
	TArray<AActor*>SpawnedItems;
};
