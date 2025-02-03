// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Static Mesh�� �ڵ忡�� ����
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	// Material�� �ڵ忡�� ����
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
	MoveSpeed = 0.1f;

	MaxRange=10.0f;

	StartLocation = FVector(3,3,3);
	
		
	
	// Ÿ�̸Ӱ� ���� �Ҹ��Ŀ��� ���������� �ȵȴ�
	//�׷��� ��ȿ������ �����ϰ� �Լ����� �Ѱ��ش�
	//�̶� SetTimer�� ����2,3��° ���ڿ� 
	//SetTimer�� �����Լ��� ����ϰԵǸ� 2��° this�� �������ش�
	//�����ε� ������ 
	/*GetWorld()->GetTimerManager().SetTimer(
		Timer, this, &AItem::ResetActorPosition, 2.0f, true, 5.0f
	);*/

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			Timer,
			[this]()
			{
				if (IsValid(this)) // ��ü ��ȿ�� Ȯ��
				{
					ResetActorPosition();
				}
			},
			2.0f, true, 5.0f
		);
	}
	GetWorld()->GetTimerManager().SetTimer(
		Timer, this, &AItem::ResetActorPosition, 2.0f, true, 5.0f
	);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}
// BlueprintCallable �Լ� ����
void AItem::ResetActorPosition()
{
	// (0, 0, 0) ��ġ�� �ǵ����ϴ�.
	FVector vec(3,3,3);
	SetActorLocation(vec);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}

void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("%s EndPlay"), *GetName());
	

	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(Timer);
}

void AItem::BeginDestroy()
{
	Super::BeginDestroy();

	// Ÿ�̸� ����
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(Timer);
	}

	UE_LOG(LogTemp, Warning, TEXT("Timer cleared in BeginDestroy"));
}
