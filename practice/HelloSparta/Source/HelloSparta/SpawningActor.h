// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveActor.h"
#include "SpawningActor.generated.h"

/**
* 
*/
UCLASS()
class HELLOSPARTA_API ASpawningActor : public AMoveActor
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;
	/**������ ���͸� �����ϴ� �迭*/
	TArray<class AActorToSpawn*> SpawnedActors;
	FTimerHandle SpawnTimer;
	/**����Handler*/
	void OnParentEventHandler();
	/**Bp�� ��� Ŭ���� */
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActorToSpawn> ActorToSpawnClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	UClass* ActorToSpawnUclass;
	

};

/**
* TSubClassOf��?
* TSubclassOf�� **Ŭ���� Ÿ��(��, Ŭ���� ��ü�� ���� ����)**�� �����ϱ� ���� ���˴ϴ�. �̴� �ν��Ͻ�(��, ������ ��ü)�� �ƴ϶�, Ŭ���� Ÿ��(Ŭ������ ����)�� ������ �� ����մϴ�.

��: TSubclassOf<class AActor>�� AActor �Ǵ� AActor�� �ڽ� Ŭ������ ������ �� �ֽ��ϴ�.
SpawnActor�� ��ȯ��
SpawnActor�� Ŭ������ �ν��Ͻ�(������ ��ü)�� ��ȯ�մϴ�. ��ȯ���� AActor* �Ǵ� �ش� Ŭ������ �������Դϴ�.
���� TsubClass�� �ش� Ŭ������ �ڽı��� �� �����ݴϴ�.
* 

*/