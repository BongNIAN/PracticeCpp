// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MyPawn.h"
#include "MyPlayerController.h" 

AMyGameMode::AMyGameMode() 
{
	DefaultPawnClass = AMyPawn::StaticClass();
	//여기에서 블루프린트 게임모드 변수 디폴트폰클래스말고 다른게 또 뭐가있었지?
	PlayerControllerClass = AMyPlayerController::StaticClass();
}