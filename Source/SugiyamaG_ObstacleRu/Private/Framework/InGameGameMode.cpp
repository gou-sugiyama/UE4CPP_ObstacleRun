// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/InGameGameMode.h"


#include "MyPlayer.h"

AInGameGameMode::AInGameGameMode()
{
	DefaultPawnClass = AMyPlayer::StaticClass();
}