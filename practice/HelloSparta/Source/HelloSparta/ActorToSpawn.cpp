// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToSpawn.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"



// Sets default values
AActorToSpawn::AActorToSpawn()
{
 	
	/**노드 순서*/
	//SphereComp(Scene상속받은애) -> StaticMesh -> ParticleComp

	/**Create Component*/
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(SphereComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	
	/**충돌 설정*/
	SphereComp->SetSimulatePhysics(true);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	/**블루프린트 변경해도 충돌설정 유지*/
	SphereComp->SetCollisionProfileName(TEXT("BlockAll")); 
	SphereComp->SetCollisionResponseToAllChannels(ECR_Block);

	/**Link to Component*/
	StaticMeshComp->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleComp->AttachToComponent(StaticMeshComp, FAttachmentTransformRules::KeepRelativeTransform);
	
	/**Concrete Settings*/
	SphereComp->SetSphereRadius(16.0f); // 구체 컴포넌트 조정
	StaticMeshComp->SetRelativeLocation(FVector(0.0, 0.0, -12.0f)); // 스태틱매시를 구체에서 z축으로 -12만큼 이동
	StaticMeshComp->SetRelativeScale3D(FVector(0.8, 0.8, 0.8)); // 크기 조정

	/**Set Default*/
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if (SphereMeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(SphereMeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Script/Engine.ParticleSystem'/Game/Resources/Particles/P_Explosion.P_Explosion'"));
	if (ParticleAsset.Succeeded())
	{
		ParticleComp->SetTemplate(ParticleAsset.Object);
	}
	



}


void AActorToSpawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello im Actor to spawn "));

	
}
