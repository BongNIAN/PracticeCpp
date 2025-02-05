// Fill out your copyright notice in the Description page of Project Settings.


#include "LotatedActor.h"

// Sets default values
ALotatedActor::ALotatedActor()
{
	/**Link To Component*/
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	/**Iv*/
	RotationSpeed = 90.0f;
	/**Activate Tick*/
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void ALotatedActor::BeginPlay()
{
	Super::BeginPlay();
	/**�������Ʈ���� ������ ���Ͽ��� �� Default ����*/
	//ConstructorHelpers::FObjectFinder...�� �����ϴܰ迡�� �ε��
	//���� ������ �ܰ迡�� Default�� �����ϰ� ������ �����ε� 
	//�������� ������ ���ϴ� ��쵵 ����,SpawningActoró��
	//SetupAttachment = ����, AttachToComponent = ���� + RegisterComponent => ����ƽ�Žø� �������� �����ϴ� ���
	//LoadObject�� �������� StaticMesh�� �����ش�  
	

	if (!StaticMeshComp)
	{
		StaticMeshComp = NewObject<UStaticMeshComponent>(this, TEXT("StaticMeshComp"));
		StaticMeshComp->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		StaticMeshComp->RegisterComponent();
	}

	
	// StaticMesh�� �������� �ε�
	if (!StaticMeshComp->GetStaticMesh()) {
		UStaticMesh* LoadedStaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
		if (LoadedStaticMesh)
		{
			StaticMeshComp->SetStaticMesh(LoadedStaticMesh);
			UE_LOG(LogTemp, Warning, TEXT("Load StaticMesh"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load Static Mesh"));
		}
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Already Set StaticMesh"));
	}
	
	if (!StaticMeshComp->GetMaterial(0)) {

		// Material�� �������� �ε�
		UMaterial* LoadedMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
		if (LoadedMaterial)
		{
			StaticMeshComp->SetMaterial(0, LoadedMaterial);
			UE_LOG(LogTemp, Warning, TEXT("Load Material"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load Material"));
		}
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Already Set Material"));
	}

}


void ALotatedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

