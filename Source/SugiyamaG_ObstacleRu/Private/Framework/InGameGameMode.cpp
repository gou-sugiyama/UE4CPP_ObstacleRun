// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/InGameGameMode.h"


#include "MyPlayer.h"

AInGameGameMode::AInGameGameMode()
{
	//	�f�t�H���g�|�[���N���X�̐ݒ�
	DefaultPawnClass = AMyPlayer::StaticClass();
}