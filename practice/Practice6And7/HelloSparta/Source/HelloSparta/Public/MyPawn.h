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

UCLASS()
class HELLOSPARTA_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:

	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn|Mesh")
	USkeletalMeshComponent* SkeletalMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn|Capsule")
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn|Arrow")
	UArrowComponent* ArrowComp;
	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void MoveAir(const FInputActionValue& value);
	UFUNCTION()
	void Accel(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	
	
	FVector Propeller;
	float MaxSpeed;

	//Behavior After BroadCast
	bool bIsZEvent;
	//Behavior After BroadCast
	void OnZEventHandler();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "pawn|Speed")
	float CurrentSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone")
	float MaxPitch; 

	float AtMovePitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drone")
	float MaxYaw; 

	float AtMoveYaw;

	void HitAndSlide(const FVector *Result);


};

// 이제 여기에 움직이는 함수를 넣어야지
	//Arrow벡터로 내가 바라보는 방향을 정하고 
	//여기에다가 내가 원하는 이동로직을 받고, 
	// 구체적인 구현은 어떻게 진행을 해볼까?
	// 구체적인 구현은 상속을 받아서 진행하면 되겠다.
	// 일단 BeginPlay는 무조건 상속 하긴해야하고
	//IA를 어떻게 나눠야하나 
	//근데 궁금한게 만약에 키를 누르면 빙의를 해제하면 어케되나?


	//키 구현 wasd
	//Space 가속 , LeftShift 감속 // 상승 및 하강
	//마우스x,마우스y Yaw,Pitch
	//Roll :   q ,e
	//Action : z 시동키, x 중력적용 키 ,
	// DebugMode : b 빙의 키 ,c 빙의 해제키  
	// 이건 플레이어 컨트롤러에서 하는건가?
	// 아니면 캐릭터에서 하는건가?
	//그냥 캐릭터에서 Delegate로 알려서 컨트롤러에서 구현할까?
	//그게 맞는것 같긴한데 
	//그냥 벡터를 하나만들고 그걸로 속력조절을 하고,
	// 회전할때마다 이 벡터도 어차피 상속되어있어서 같이 움직일테니깐
	// 
	//ArrowVector의 방향에 더해주면 될것같고
	//속력조절을 하는 그것과 MaxSpeed,를 정하면될것같은데?
	// 시동키는 여기서 구현하고 ,
	// 중력적용 빙의 빙의 해제는 상속받아서 구현해야겠다.
	// 그러면 1,2

	//시간 된다면 키 하나 누르면 인간폼 빙의 
	// 다른키누르면 드론폼 빙의 이런거 있으면 재밌겠다?
