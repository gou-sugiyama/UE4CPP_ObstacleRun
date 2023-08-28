// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

	// �f�t�H���g�l�̐ݒ�
AMyCharacter::AMyCharacter()
{

 	// ���t���[�����s���鏈��������ꍇ�͂�����I���ɂ���B
	PrimaryActorTick.bCanEverTick = false;
	//AutoPossessPlayer = EAutoReceiveInput::Player0;

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
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%.1f,%.1f,%.1f")
		, GetActorLocation().X
		, GetActorLocation().Y
		, GetActorLocation().Z)
		, true, true, FColor::Cyan, 1.0f);
	// �ړ��ɐݒ肵�����Ɋ�Â��č��W��ς���
	{
		if (!(CurrentVelocity.IsZero()))
		{

			UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%.1f,%.1f,%.1f")
				, GetActorLocation().X
				, GetActorLocation().Y
				, GetActorLocation().Z)
				, true, true, FColor::Cyan, 1.0f);

			FVector ProgressionVector = FVector(CameraComponent->GetForwardVector());
			FVector* pVector = &ProgressionVector;
			//VectorNormalize(pVector);
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}
	}
}

// �@�\����͂Ƀo�C���h���邽�߂ɌĂяo�����
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// MoveRight, MoveForward �ɕR�Â���ꂽ�L�[�ɖ��t���[����������
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
}

// X���W�ɑ΂��鎲�}�b�s���O�̐���
void AMyCharacter::MoveRight(float AxisValue)
{
	if (AxisValue)
	{
		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("MoveRight"))
			, true
			, true
			, FColor::Cyan
			, 0.f);
	}
	// 1 �b�ԂɑO��� 100 �P�ʈړ�
	// FMath::Clamp �֐����g���� AxisValue �̒l�� -1.0 ~ 1.0 �͈̔͂ɐ��䂵�Ă���
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%f"), CurrentVelocity.X)
		, true
		, true
		, FColor::Cyan
		, 0.f);
}

// Y���W�ɑ΂��鎲�}�b�s���O�̐���
void AMyCharacter::MoveForward(float AxisValue)
{
	if (AxisValue)
	{
		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("MoveForward"))
			, true
			, true
			, FColor::Cyan
			, 0.f);
	}
	// 1 �b�Ԃɍ��E�� 100 �P�ʈړ�
	// FMath::Clamp �֐����g���� AxisValue �̒l�� -1.0 ~ 1.0 �͈̔͂ɐ��䂵�Ă���
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyCharacter::InputTest(float test)
{
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f);
}