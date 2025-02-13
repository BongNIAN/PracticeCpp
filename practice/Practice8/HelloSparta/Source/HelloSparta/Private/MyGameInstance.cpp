#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	TotalScore = 0;
	CurrentLevelIndex = 0;
}

void UMyGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updated: %d"), TotalScore);
}
float UMyGameInstance::GetRemainingBuffTime(float CurrentTime)
{
	if (BuffTotalDuration > 0.f)
	{
		float ElapsedTime = CurrentTime - BuffStartTime;
		return FMath::Clamp(BuffTotalDuration - ElapsedTime, 0.f, BuffTotalDurationMax);
	}
	return 0.f;
}

void UMyGameInstance::SetBuffInformation(float InStartTime, float Duration)
{
	float RemainingTime = GetRemainingBuffTime(InStartTime);
	BuffTotalDuration = FMath::Clamp(RemainingTime + Duration, 0.f, BuffTotalDurationMax);
	BuffStartTime = InStartTime;
}
void UMyGameInstance::OnGameOverSetSpeed(float SetBuffStartTime, float SetBuffTotalDuration)
{
	BuffStartTime = SetBuffStartTime;
	BuffTotalDuration = SetBuffTotalDuration;
}

float UMyGameInstance::GetRemainingDebuffTime(float CurrentTime)
{
	if (DebuffTotalDuration > 0.f)
	{
		float ElapsedTime = CurrentTime - DebuffStartTime;
		return FMath::Clamp(DebuffTotalDuration - ElapsedTime, 0.f, DebuffTotalDurationMax);
	}
	return 0.f;
}
void UMyGameInstance::SetDebuffInformation(float InStartTime, float Duration)
{
	float RemainingTime = GetRemainingDebuffTime(InStartTime);
	DebuffTotalDuration = FMath::Clamp(RemainingTime + Duration, 0.f, DebuffTotalDurationMax);
	DebuffStartTime = InStartTime;
}
void UMyGameInstance::OnGameOverSetDebuff(float SetDebuffStartTime, float SetDebuffTotalDuration)
{
	DebuffStartTime = SetDebuffStartTime;
	DebuffTotalDuration = SetDebuffTotalDuration;
}
void UMyGameInstance::SavedBuffDuration(float Duration)
{
	SavedBuffTime = Duration;
}
void UMyGameInstance::SavedDebuffDuration(float Duration)
{
	SavedDebuffTime = Duration;
}
float UMyGameInstance::LoadedDebuffDuration() const
{
	return SavedDebuffTime;
}
float UMyGameInstance::LoadedBuffDuration() const
{
	return SavedBuffTime;
}