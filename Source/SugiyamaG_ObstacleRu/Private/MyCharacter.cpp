// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

	// �f�t�H���g�l�̐ݒ�
AMyCharacter::AMyCharacter()
{

 	// ���t���[�����s���鏈��������ꍇ�͂�����I���ɂ���B
	PrimaryActorTick.bCanEverTick = false;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// �f�t�H���g�V�[�����[�g�̐ݒ�------------------------------
	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// �X�^�e�B�b�N���b�V���̐ݒ�--------------------------------
	// StaticMeshComponent���쐬����
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/EditorMeshes/EditorCube"), NULL, LOAD_None, NULL);
	StaticMeshComponent->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	StaticMeshComponent->SetupAttachment(RootComponent);
	//-----------------------------------------------------------

	// �J�����̐ݒ�---------------------------------------------------------------
	// �X�v�����O�A�[���R���|�[�l���g���쐬
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(StaticMeshComponent);
	SpringArmComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.0f), FRotator(-10.0f, 0.0f, 0.0f));
	SpringArmComponent->TargetArmLength = 800.f;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->CameraLagSpeed = 15.0f;

	// �J�����R���|�[�l���g���쐬
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// ���[�g�R���|�[�l���g�Ƃ��ăJ�������A�^�b�`
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	//CameraComponent->SetRelativeLocation(FVector(-420.f, 0.0f, 140.0f));
	//FVector Rotation(0.f, -20.f, 0.f);
	//FQuat QuatRotation = FQuat::MakeFromEuler(Rotation);
	//CameraComponent->SetRelativeRotation(QuatRotation);

	//���C���J�����ɐݒ肷��
	

	//---------------------------------------------------------------
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

// �@�\����͂Ƀo�C���h���邽�߂ɌĂяo�����
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}