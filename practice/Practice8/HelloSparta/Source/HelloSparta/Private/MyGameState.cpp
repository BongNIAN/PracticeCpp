#include "MyGameState.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "CoinItem.h"
#include "WavePassItem.h"
#include "SpikeTrapItem.h"

AMyGameState::AMyGameState()
{
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	LevelDuration = 30.0f;
	CurrentLevelIndex = 0;
	WaveCount = 1;
	MaxLevels = 3;
}

void AMyGameState::BeginPlay()
{
	Super::BeginPlay();
	StartLevel();
	GetWorldTimerManager().SetTimer(
		HUDUpdateTimerHandle,
		this,
		&AMyGameState::UpdateHUD,
		0.1f,
		true
	);
}

int32 AMyGameState::GetScore() const
{
	return Score;
}

void AMyGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance))
		{
			MyGameInstance->AddToScore(Amount);
		}
	}
}

void AMyGameState::StartLevel()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		AMyPlayerController* CastToMyController = Cast<AMyPlayerController>(PlayerController);
		if (CastToMyController)
		{
			CastToMyController->ShowGameHUD();
		}
	}
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance))
		{
			CurrentLevelIndex = MyGameInstance->CurrentLevelIndex;
		}

	}
	SpawnRandom();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Wave %d Start"), WaveCount));
	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AMyGameState::OnLevelTimeUp,
		LevelDuration,
		false
	);
}

void AMyGameState::OnLevelTimeUp()
{
	EndLevel();
}
void AMyGameState::OnCoinCollected()
{
	CollectedCoinCount++;
	if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
	{
		EndLevel();
	}
}
void AMyGameState::EndLevel()
{
	if (WaveCount < 4)
	{
		OnGameOver();
		return;
	}
	GetWorldTimerManager().ClearTimer(LevelTimerHandle);
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance))
		{
			AddScore(Score);
			CurrentLevelIndex++;
			MyGameInstance->CurrentLevelIndex = CurrentLevelIndex;
		}
	}
	if (CurrentLevelIndex >= MaxLevels)
	{
		OnGameOver();
		return;
	}
	if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
	{
		if (UMyGameInstance* GI = Cast<UMyGameInstance>(GetGameInstance()))
		{
			float CurrentTime = GetWorld()->GetTimeSeconds();
			float RemainBuffDuration = GI->GetRemainingBuffTime(CurrentTime);
			float RemainDebuffDuration = GI->GetRemainingDebuffTime(CurrentTime);
			GI->SavedBuffDuration(RemainBuffDuration);
			GI->SavedDebuffDuration(RemainDebuffDuration);
		}
		UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
	}
	else
	{
		OnGameOver();
	}
}
void AMyGameState::OnGameOver()
{
	TObjectPtr<APlayerController> PlayerController =
		GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		TObjectPtr<AMyPlayerController> CastToMyController
			= Cast<AMyPlayerController>(PlayerController);
		if (CastToMyController)
		{
			CastToMyController->SetPause(true);
			CastToMyController->ShowMainMenu(true);
		}
	}
}
void AMyGameState::UpdateHUD()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController);
		{
			if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
			{
				if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time"))))
				{
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);
					TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
				}
				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score"))))
				{
					if (UGameInstance* GameInstance = GetGameInstance())
					{
						UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
						if (MyGameInstance)
						{
							ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), MyGameInstance->TotalScore)));
						}
					}
				}

				if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level"))))
				{
					LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("Stage: %d"), CurrentLevelIndex + 1)));
				}
				if (UTextBlock* WaveIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Wave"))))
				{
					WaveIndexText->SetText(FText::FromString(FString::Printf(TEXT("- %d"), WaveCount)));
				}
			}
		}
	}
}
void AMyGameState::OnPassItemCollected()
{
	NextWave();
}
void AMyGameState::SpawnRandom()
{
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);
	int32 ItemToSpawn = 0;
	if (WaveCount == 1) 
	{
		ItemToSpawn = 40;
	}
	if (WaveCount == 2)
	{
		ItemToSpawn = 50;
	}
	if (WaveCount == 3)
	{
		ItemToSpawn = 55;
	}
	bool bIsSpawningPassItem = false;
	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();

				SpawnedItems.Add(SpawnedActor);
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}
				if (SpawnedActor && SpawnedActor->IsA(AWavePassItem::StaticClass()))
				{
					bIsSpawningPassItem = true;
				}
			}
		}
	}
	//designed it for additional logic.
	//Example ) Setting the probability of WavePassItem per wave
	if (!bIsSpawningPassItem)
	{
		if (FoundVolumes.Num() > 0) 
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				SpawnVolume->SpawnItem(PassItem);
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("!bIsSpawningPassItem")));
			}
		}
	}
	if (WaveCount == 2)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				for (int i = 0; i < 5; i++) 
				{
					SpawnVolume->SpawnItem(TrapItem);
				}
			}
		}
		
	}
	if (WaveCount == 3)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				for (int i = 0; i < 10; i++)
				{
					SpawnVolume->SpawnItem(TrapItem);
				}
			}
		}
	}
}
void AMyGameState::NextWave()
{
	if (WaveCount >= 3)
	{
		WaveCount++;
		EndLevel();
	}
	else {
		if (!SpawnedItems.IsEmpty())
		{
			for (AActor* SpawnedItem : SpawnedItems)
			{
				if (IsValid(SpawnedItem))
				{
					SpawnedItem->Destroy();
				}
			}
			SpawnedItems.Reset();
		}
		WaveCount++;
		SpawnRandom();
		
	}
}

