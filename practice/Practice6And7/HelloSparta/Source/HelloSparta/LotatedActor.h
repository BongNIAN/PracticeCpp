// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LotatedActor.generated.h"

UCLASS()
class HELLOSPARTA_API ALotatedActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ALotatedActor();

protected:
	
	virtual void BeginPlay() override;

	/**Set Reflection*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;
	/**Set Reflection*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	


public:	
	
	/**Set Reflection*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float RotationSpeed;
	virtual void Tick(float DeltaTime) override;

};
