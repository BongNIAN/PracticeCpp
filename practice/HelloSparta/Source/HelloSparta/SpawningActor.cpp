// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawningActor.h"
#include "ActorToSpawn.h"


void ASpawningActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("SpawnedActor Start"));
	/**이벤트 핸들러를 부모클래스에 연결, 이때 함수포인터의 주소를 연결해준다(구독)*/
	OnParentEvent.AddUObject(this, &ASpawningActor::OnParentEventHandler);
	/**20초 후에 소환된 액터를 일정간격으로 모은다=>충돌 설정이 되어있기 때문에 부딪히면서 떨어진다*/
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			SpawnTimer, [this]() 
			{
				for (int i = 0; i < SpawnedActors.Num(); i++)
					if (IsValid(SpawnedActors[i])) {
						SpawnedActors[i]->SetActorLocation(FVector(i * 20, 0, 400));
					}
			},20.0f,false
		);
	}
}

void ASpawningActor::OnParentEventHandler()
{
	//두번 소환 
	for (int i = 0; i < 2; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor is %s"), *GetActorLocation().ToString());
		/**Set Location*/
		FVector tmpLocation = GetActorLocation() + FVector(FMath::FRandRange(50.0f, 200.0f)  , FMath::FRandRange(50.0f, 200.0f) , 100);
		UE_LOG(LogTemp, Warning, TEXT("After Actor is %s"), *tmpLocation.ToString());
		FRotator tmpRotation = GetActorRotation();
	
		//만일 소환할 액터가 디폴트가 설정되어있지 않다면
		if (!ActorToSpawnClass)
		{
			/**동적으로 ActorToSpawn을 상속받은 Bp로 설정해준다*/
			/**생성자에서 Find 쓰는건 컴파일단계에서 로드되기때문에 동적으로 추가해줘야한다*/
			ActorToSpawnClass = LoadClass<AActorToSpawn>(nullptr, TEXT("/Game/Blueprints/Bp_ActorToSpawn.Bp_ActorToSpawn_C"));
			if (ActorToSpawnClass)
			{
				UE_LOG(LogTemp, Warning, TEXT("ActorToSpawnClas loaded"));
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Fail to load"));
			}
		}

		/**Spawn Actor*/
		AActorToSpawn* tmp = GetWorld()->SpawnActor<AActorToSpawn>(ActorToSpawnClass,tmpLocation, tmpRotation);
		if (tmp)
		{
			/**스폰된 액터를 관리하는 TArray*/
			SpawnedActors.Add(tmp);
		}
	}

}
