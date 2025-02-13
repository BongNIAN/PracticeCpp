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
	/**스폰된 액터를 관리하는 배열*/
	TArray<class AActorToSpawn*> SpawnedActors;
	FTimerHandle SpawnTimer;
	/**구독Handler*/
	void OnParentEventHandler();
	/**Bp를 담는 클래스 */
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActorToSpawn> ActorToSpawnClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	UClass* ActorToSpawnUclass;
	

};

/**
* TSubClassOf란?
* TSubclassOf는 **클래스 타입(즉, 클래스 자체에 대한 참조)**을 저장하기 위해 사용됩니다. 이는 인스턴스(즉, 생성된 객체)가 아니라, 클래스 타입(클래스의 정의)을 저장할 때 사용합니다.

예: TSubclassOf<class AActor>는 AActor 또는 AActor의 자식 클래스를 참조할 수 있습니다.
SpawnActor의 반환값
SpawnActor는 클래스의 인스턴스(생성된 객체)를 반환합니다. 반환값은 AActor* 또는 해당 클래스의 포인터입니다.
또한 TsubClass는 해당 클래스의 자식까지 다 보여줍니다.
* 

*/