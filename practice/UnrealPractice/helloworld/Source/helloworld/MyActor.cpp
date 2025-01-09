// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"



// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start.X = 0;
	start.Y = 0;
	evCnt = 0;
	totDist = 0;
	evXCnt = 0;
	evYCnt = 0;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	move();
	printLocation();
}



// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move() {
	UE_LOG(LogTemp, Warning, TEXT("moveStart"));

	for (int i = 0; i < 10; i++) {
		FVector2D tmp;
		tmp.X = static_cast<float> (step(0));
		tmp.Y = static_cast<float> (step(1));

		UE_LOG(LogTemp, Warning, TEXT("I START  : %d: "), i);
		UE_LOG(LogTemp, Warning, TEXT("Temporary vector: %f, %f"), tmp.X, tmp.Y);
		UE_LOG(LogTemp, Warning, TEXT("Before addition: %f, %f"), start.X, start.Y);
		
		this->totDist += distance(tmp);
		this->start += tmp;
		UE_LOG(LogTemp, Warning, TEXT("After addition: %f, %f"), start.X, start.Y);
		UE_LOG(LogTemp, Warning, TEXT("Distance: , totalDistance %f, %f"), distance(tmp), this->totDist);

		UE_LOG(LogTemp, Warning, TEXT("I END  : %d: "), i);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("MoveEnd !!! evCnt  is %d"),this->evCnt);
	UE_LOG(LogTemp, Warning, TEXT("MoveEnd !!! ev  X   Cnt  is %d"), this->evXCnt);
	UE_LOG(LogTemp, Warning, TEXT("MoveEnd !!! ev   Y   Cnt  is %d"), this->evYCnt);
	UE_LOG(LogTemp, Warning, TEXT("MoveEnd !!! totDist  is %d"), static_cast<int>(this->totDist));
}

void AMyActor::printLocation() {
	UE_LOG(LogTemp, Warning, TEXT("Actor Location is  %f , %f"), start.X, start.Y);
}
int32 AMyActor::step(int a) {
	int32 RandomValue = static_cast<int32>(FMath::RandRange(0, 1));

	if (a == 0) { //x일경우 

		if (createEvent(50)) {
			this->evXCnt++;

			UE_LOG(LogTemp, Warning, TEXT("X CreateRandomEvent => RandomValue :  %d"), RandomValue);

			if (RandomValue) {
				UE_LOG(LogTemp, Warning, TEXT("X Success + 1 "));
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Sorry, X is remain "));
			}

			return RandomValue;
			

		}
		else {
			
			return 0;
		}
	}

	else if (a == 1) { //y 일경우

		if (createEvent(50)) {
			this->evYCnt++;

			UE_LOG(LogTemp, Warning, TEXT("Y CreateRandomEvent =>  RandomValue : %d"), RandomValue);

			if (RandomValue) {
				UE_LOG(LogTemp, Warning, TEXT("Y Success + 1 "));
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Sorry, Y is remain "));
			}

			return RandomValue;


		}
		else {

			return 0;
		}
	}

	else {
	throw std::logic_error("Invalid condition encountered");
	}

}

int32 AMyActor::createEvent(float Probability) {
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	UE_LOG(LogTemp, Warning, TEXT("RandomValue: %d "), RandomValue, Probability);
	if (RandomValue >= Probability)
	{
		
		this->evCnt++;
		return 1;
	}
	else
	{
		
		return 0;
	}
}

//TODO : TEMP XCONT

float AMyActor::distance(FVector2D tmp)
{
	float dx = tmp.X;
	float dy = tmp.Y ;
	// 새로 만들어질 벡터와 기존의 벡터의 x의 차이는 tmp.x,
	// y의 차이는 tmp.y
	// cuz ) before.x + tmp.x = after.x
	return FMath::Sqrt(dx * dx + dy * dy);
}