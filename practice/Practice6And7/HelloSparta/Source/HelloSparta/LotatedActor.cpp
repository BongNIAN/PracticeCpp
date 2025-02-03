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
	/**블루프린트에서 설정을 안하였을 때 Default 설정*/
	//ConstructorHelpers::FObjectFinder...은 컴파일단계에서 로드됨
	//만일 컴파일 단계에서 Default를 설정하고 싶으면 정적인데 
	//정적으로 설정을 못하는 경우도 있음,SpawningActor처럼
	//SetupAttachment = 정적, AttachToComponent = 동적 + RegisterComponent => 스태틱매시를 동적으로 연결하는 방법
	//LoadObject로 동적으로 StaticMesh를 입혀준다  
	

	if (!StaticMeshComp)
	{
		StaticMeshComp = NewObject<UStaticMeshComponent>(this, TEXT("StaticMeshComp"));
		StaticMeshComp->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		StaticMeshComp->RegisterComponent();
	}

	
	// StaticMesh를 동적으로 로드
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

		// Material을 동적으로 로드
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

