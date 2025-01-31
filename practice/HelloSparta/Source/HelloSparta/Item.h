// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class HELLOSPARTA_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

protected:
	// Root Scene Component, �����Ϳ��� �� ���� �ְ� ���� �Ұ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	// Static Mesh, �����Ϳ� Blueprint���� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// ȸ�� �ӵ�, Ŭ���� �⺻���� ���� ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Timer")
	FTimerHandle Timer;

	float MoveSpeed;

	float MaxRange;

	FVector StartLocation;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	// �Լ��� �������Ʈ���� ȣ�� �����ϵ��� ����
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	// �������Ʈ���� ���� ��ȯ�ϵ��� ����
	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;

	// C++���� ȣ������� ������ �������Ʈ���� ����
	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void BeginDestroy() override;
};
