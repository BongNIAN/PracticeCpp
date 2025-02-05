// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{
	/**Create Components*/
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SCENE"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	/**Setup Node*/
	SetRootComponent(SceneComp);
	StaticMeshComp->SetupAttachment(SceneComp);

	/**Default Value Of Component*/
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset2(TEXT("/Script/Engine.StaticMesh'/Game/Resources/Props/SM_TableRound.SM_TableRound'"));
	if (MeshAsset2.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset2.Object);
		StaticMeshAssets.Add(MeshAsset2.Object);
		
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Resources/Materials/M_Power_Sphere_Inst.M_Power_Sphere_Inst'"));
	if (MaterialAsset.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("MTMTMTMTMTMTMTMT"));
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NOPE"));
	}

	/**Iv*/
	MoveSpeed=40.0f;
	MaxRange = 400.0f;
	StartLocation=GetActorLocation();
	/**Default MeshAsset2*/
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if (MeshAsset.Succeeded())
	{
	
		StaticMeshAssets.Add(MeshAsset.Object);
	}
	/**Activate Tick*/
	PrimaryActorTick.bCanEverTick = true;



}
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	//Link to Timer
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(MoveTimer, [this]()
			{
				if (IsValid(this)) // ��ü ��ȿ�� Ȯ��
				{
					ChangeMesh();
				}
			}
			, 3.0f, true, 5.0f
		);
	}


}
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//������ �Ÿ��� �ִ�Ÿ��� �Ѵ´ٸ� ChangeActorVector ȣ��
	if (IsMaxRange(GetActorLocation()))
	{
		ChangeActorVector();
		
	}
	FVector Movement = FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f); // X�� ���� �̵�
	AddActorLocalOffset(Movement, false); // �浹 ���� ��Ȱ��ȭ + Set New Location
}
bool AMoveActor::IsMaxRange(FVector NowActorLocation){

	//���� ������ �Ÿ��� �ִ밪�� �Ѵ´ٸ�
	if (FVector::DistSquared(StartLocation, NowActorLocation) >= MaxRange * MaxRange)
	{
		/**�������� �ʱ�ȭ ���ְ� */
		StartLocation = GetActorLocation();
		/**��������Ʈ�� ����Ǿ��ִ� �Լ� ȣ��(�˸�)*/
		OnParentEvent.Broadcast();
		return true;
	}
	return false;
}
void AMoveActor::ChangeActorVector() 
{
	/**y������ 90����ŭ ȸ��*/
	AddActorLocalRotation(FQuat(FRotator(0.0f, 90.0f, 0.0f)));
	
}
void AMoveActor::ChangeMesh() 
{
	if (StaticMeshAssets.Num() > 0)
	{
		/**�迭�� ����� MeshAsset�� �������� �ҷ��´�*/
		int32 Index = FMath::RandRange(0, StaticMeshAssets.Num() - 1);
		StaticMeshComp->SetStaticMesh(StaticMeshAssets[Index]);
		UE_LOG(LogTemp, Warning, TEXT("Selected Mesh: %s"), *StaticMeshAssets[Index]->GetName());
	}
}