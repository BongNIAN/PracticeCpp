#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class HELLOSPARTA_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 TotalScore = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 CurrentLevelIndex = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float BuffTotalDuration = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float BuffTotalDurationMax = 100.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float BuffStartTime = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float DebuffTotalDuration = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float DebuffTotalDurationMax = 100.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float DebuffStartTime = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float SavedBuffTime = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	float SavedDebuffTime = 0.f;

	UFUNCTION(BlueprintCallable, Category = "Buff")
	float GetRemainingBuffTime(float CurrentTime);

	UFUNCTION(BlueprintCallable, Category = "Buff")
	void SetBuffInformation(float InStartTime, float Duration);

	UFUNCTION(BlueprintCallable, Category = "Buff")
	float GetRemainingDebuffTime(float CurrentTime);

	UFUNCTION(BlueprintCallable, Category = "Buff")
	void SetDebuffInformation(float InStartTime, float Duration);
	
	UFUNCTION(BlueprintCallable, Category = "Buff")
	void OnGameOverSetSpeed(float SetBuffStartTime, float SetBuffTotalDuration);
	
	UFUNCTION(BlueprintCallable, Category = "Buff")
	void OnGameOverSetDebuff(float SetDebuffStartTime, float SetDebuffTotalDuration);

	UFUNCTION(BlueprintCallable, Category = "Buff")
	void SavedBuffDuration(float Duration);

	UFUNCTION(BlueprintCallable, Category = "Buff")
	void SavedDebuffDuration(float Duration);

	UFUNCTION(BlueprintCallable, Category = "Buff")
	float LoadedDebuffDuration() const;

	UFUNCTION(BlueprintCallable, Category = "Buff")
	float LoadedBuffDuration() const;

};
