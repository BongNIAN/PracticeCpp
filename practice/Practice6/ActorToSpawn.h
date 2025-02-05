// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorToSpawn.generated.h"

UCLASS()
class HELLOSPARTA_API AActorToSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorToSpawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning|Components")
	class USphereComponent* SphereComp; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning|Components")
	class UParticleSystemComponent* ParticleComp;
	//TODO :  ���������� ����� �ҽ������� �������� ����?
protected:
	virtual void BeginPlay() override;
};
