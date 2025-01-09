// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" // 항상 먼저 포함
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "MyActor.generated.h" // 마지막에 위치


UCLASS()
class HELLOWORLD_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();
	void move();
	void printLocation();

	int32 step(int a);

	int32 createEvent(float Probability);


	float distance(FVector2D tmp);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector2D start;
	int32 evCnt;
	int32 evXCnt;
	int32 evYCnt;

	float totDist;

};