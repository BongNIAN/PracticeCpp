// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToSpawn.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"



// Sets default values
AActorToSpawn::AActorToSpawn()
{
 	
	/**��� ����*/
	//SphereComp(Scene��ӹ�����) -> StaticMesh -> ParticleComp

	/**Create Component*/
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(SphereComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	
	/**�浹 ����*/
	SphereComp->SetSimulatePhysics(true);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	/**�������Ʈ �����ص� �浹���� ����*/
	SphereComp->SetCollisionProfileName(TEXT("BlockAll")); 
	SphereComp->SetCollisionResponseToAllChannels(ECR_Block);

	/**Link to Component*/
	StaticMeshComp->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleComp->AttachToComponent(StaticMeshComp, FAttachmentTransformRules::KeepRelativeTransform);
	
	/**Concrete Settings*/
	SphereComp->SetSphereRadius(16.0f); // ��ü ������Ʈ ����
	StaticMeshComp->SetRelativeLocation(FVector(0.0, 0.0, -12.0f)); // ����ƽ�Žø� ��ü���� z������ -12��ŭ �̵�
	StaticMeshComp->SetRelativeScale3D(FVector(0.8, 0.8, 0.8)); // ũ�� ����

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
