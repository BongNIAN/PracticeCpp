// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawningActor.h"
#include "ActorToSpawn.h"


void ASpawningActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("SpawnedActor Start"));
	/**�̺�Ʈ �ڵ鷯�� �θ�Ŭ������ ����, �̶� �Լ��������� �ּҸ� �������ش�(����)*/
	OnParentEvent.AddUObject(this, &ASpawningActor::OnParentEventHandler);
	/**20�� �Ŀ� ��ȯ�� ���͸� ������������ ������=>�浹 ������ �Ǿ��ֱ� ������ �ε����鼭 ��������*/
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
	//�ι� ��ȯ 
	for (int i = 0; i < 2; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor is %s"), *GetActorLocation().ToString());
		/**Set Location*/
		FVector tmpLocation = GetActorLocation() + FVector(FMath::FRandRange(50.0f, 200.0f)  , FMath::FRandRange(50.0f, 200.0f) , 100);
		UE_LOG(LogTemp, Warning, TEXT("After Actor is %s"), *tmpLocation.ToString());
		FRotator tmpRotation = GetActorRotation();
	
		//���� ��ȯ�� ���Ͱ� ����Ʈ�� �����Ǿ����� �ʴٸ�
		if (!ActorToSpawnClass)
		{
			/**�������� ActorToSpawn�� ��ӹ��� Bp�� �������ش�*/
			/**�����ڿ��� Find ���°� �����ϴܰ迡�� �ε�Ǳ⶧���� �������� �߰�������Ѵ�*/
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
			/**������ ���͸� �����ϴ� TArray*/
			SpawnedActors.Add(tmp);
		}
	}

}
