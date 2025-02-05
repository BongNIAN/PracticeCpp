// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class USpringArmComponent; 
class UCameraComponent;
class USkeletalMeshComponent;
class UCapsuleComponent;
class UArrowComponent;
struct FInputActionValue;
struct FHitResult;

UCLASS()
class HELLOSPARTA_API AMyPawn : public APawn
{
	GENERATED_BODY()
public:
	AMyPawn();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	bool bIsGround();
	void HitAndSlide(const FVector* Result);
	FHitResult GetImpactObject();
	void OnZEventHandler();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> CameraComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn|Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn|Capsule")
	TObjectPtr<UCapsuleComponent> CapsuleComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn|Arrow")
	TObjectPtr<UArrowComponent> ArrowComp;
	
	UFUNCTION()
	void Move(const FInputActionValue& value);
	
	UFUNCTION()
	void MoveAir(const FInputActionValue& value);
	
	UFUNCTION()
	void Up(const FInputActionValue& value);
	
	UFUNCTION()
	void Look(const FInputActionValue& value);

	UFUNCTION()
	void StopGravity(const FInputActionValue& Value);
	
	//Handle Value
	bool bIsZEvent= false;
	bool StopGravityOffset = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "pawn|Speed")
	float CurrentSpeed=1400.f;
	float MaxSpeed = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone")
	float MaxPitch=15.f; 
	float AtMovePitch=0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone")
	float MaxYaw=15.f; 
	float AtMoveYaw=0.f;
	
	float MaxRoll = 15.f;
	float AtMoveRoll = 0.f;
	
	FVector GravityVelocity = FVector::ZeroVector;
	FVector GravityAcceleration = FVector(0.f,0.f,-98.0f);

	//Unimplemented because of deadline
	FVector PawnVelocity = FVector::ZeroVector;
	FVector2D SaveInput = FVector2D::ZeroVector;
};


