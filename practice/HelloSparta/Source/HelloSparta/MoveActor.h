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
	/**SceneComp는 리플렉션을 안해도 자동으로 등록*/
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
	FVector StartLocation; //getActor으로 초기화 
	/**구독자 등록*/
	FOnParentEvent OnParentEvent;
	/**스태틱매시를 담고있는 배열*/
	UPROPERTY(EditAnywhere, Category = "MoveActor|Meshes")
	TArray<UStaticMesh*> StaticMeshAssets;
	FTimerHandle MoveTimer;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
};
/**1.타이머에 따라 매쉬바뀌어야함 , 틱을 통해 MaxRange넘어가면 회전 180도 or 뒤로 움직이기*/