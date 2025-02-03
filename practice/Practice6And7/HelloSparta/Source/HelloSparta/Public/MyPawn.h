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

// ���� ���⿡ �����̴� �Լ��� �־����
	//Arrow���ͷ� ���� �ٶ󺸴� ������ ���ϰ� 
	//���⿡�ٰ� ���� ���ϴ� �̵������� �ް�, 
	// ��ü���� ������ ��� ������ �غ���?
	// ��ü���� ������ ����� �޾Ƽ� �����ϸ� �ǰڴ�.
	// �ϴ� BeginPlay�� ������ ��� �ϱ��ؾ��ϰ�
	//IA�� ��� �������ϳ� 
	//�ٵ� �ñ��Ѱ� ���࿡ Ű�� ������ ���Ǹ� �����ϸ� ���ɵǳ�?


	//Ű ���� wasd
	//Space ���� , LeftShift ���� // ��� �� �ϰ�
	//���콺x,���콺y Yaw,Pitch
	//Roll :   q ,e
	//Action : z �õ�Ű, x �߷����� Ű ,
	// DebugMode : b ���� Ű ,c ���� ����Ű  
	// �̰� �÷��̾� ��Ʈ�ѷ����� �ϴ°ǰ�?
	// �ƴϸ� ĳ���Ϳ��� �ϴ°ǰ�?
	//�׳� ĳ���Ϳ��� Delegate�� �˷��� ��Ʈ�ѷ����� �����ұ�?
	//�װ� �´°� �����ѵ� 
	//�׳� ���͸� �ϳ������ �װɷ� �ӷ������� �ϰ�,
	// ȸ���Ҷ����� �� ���͵� ������ ��ӵǾ��־ ���� �������״ϱ�
	// 
	//ArrowVector�� ���⿡ �����ָ� �ɰͰ���
	//�ӷ������� �ϴ� �װͰ� MaxSpeed,�� ���ϸ�ɰͰ�����?
	// �õ�Ű�� ���⼭ �����ϰ� ,
	// �߷����� ���� ���� ������ ��ӹ޾Ƽ� �����ؾ߰ڴ�.
	// �׷��� 1,2

	//�ð� �ȴٸ� Ű �ϳ� ������ �ΰ��� ���� 
	// �ٸ�Ű������ ����� ���� �̷��� ������ ��հڴ�?
