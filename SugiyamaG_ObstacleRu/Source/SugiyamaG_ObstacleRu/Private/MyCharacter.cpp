// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

	// �f�t�H���g�l�̐ݒ�
AMyCharacter::AMyCharacter()
{
 	// ���t���[�����s���鏈��������ꍇ�͂�����I���ɂ���B
	PrimaryActorTick.bCanEverTick = false;

	// �f�t�H���g�V�[�����[�g�̐ݒ�------------------------------
	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// �X�^�e�B�b�N���b�V���̐ݒ�--------------------------------
	// StaticMeshComponent���쐬����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/EditorMeshes/EditorCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	StaticMesh->SetupAttachment(RootComponent);
	//-----------------------------------------------------------
}

// �Q�[���J�n���A�܂��̓X�|�[�����ɌĂ΂��
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// ���t���[���Ă΂��
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

