// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnParentEvent);


UCLASS()
class HELLOSPARTA_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveActor();
protected:
	/**SceneComp�� ���÷����� ���ص� �ڵ����� ���*/
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, Category = "MoveActor|DefalutMesh")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, Category = "MoveActor|ActorSpeed")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, Category = "MoveActor|MaxRange")
	float MaxRange;
	
	bool IsMaxRange(FVector NowActorLocation);
	void ChangeActorVector();
	void ChangeMesh();
	FVector StartLocation; //getActor���� �ʱ�ȭ 
	/**������ ���*/
	FOnParentEvent OnParentEvent;
	/**����ƽ�Žø� ����ִ� �迭*/
	UPROPERTY(EditAnywhere, Category = "MoveActor|Meshes")
	TArray<UStaticMesh*> StaticMeshAssets;
	FTimerHandle MoveTimer;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
};
/**1.Ÿ�̸ӿ� ���� �Ž��ٲ����� , ƽ�� ���� MaxRange�Ѿ�� ȸ�� 180�� or �ڷ� �����̱�*/