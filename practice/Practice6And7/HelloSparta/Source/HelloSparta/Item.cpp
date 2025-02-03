// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Static Mesh를 코드에서 설정
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	// Material을 코드에서 설정
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
	
		
	
	// 타이머가 액터 소멸후에도 남아있으면 안된다
	//그래서 유효한지를 검증하고 함수값을 넘겨준다
	//이때 SetTimer의 값에2,3번째 인자에 
	//SetTimer는 람다함수를 사용하게되면 2번째 this는 생략해준다
	//오버로딩 같은데 
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
				if (IsValid(this)) // 객체 유효성 확인
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
// BlueprintCallable 함수 구현
void AItem::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
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

	// 타이머 정리
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(Timer);
	}

	UE_LOG(LogTemp, Warning, TEXT("Timer cleared in BeginDestroy"));
}
