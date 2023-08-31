// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "Components/ArrowComponent.h" 
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
	//	�X�^�e�B�b�N���b�V���̐ݒ�----------------------------------------------------------
	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ肷��
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Sphere;

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	Sphere->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere")));

	// Material��StaticMesh�ɐݒ肷��
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// Material��StaticMeshComponent�ɐݒ肷��
	Sphere->SetMaterial(0, Material);

	// Simulate Physics��L���ɂ���
	Sphere->SetSimulatePhysics(true);

	// CollisionPreset���uPhysicsActor�v�ɕύX����
	Sphere->SetCollisionProfileName(TEXT("PhysicsActor"));

	// Hit Event��L���ɂ���
	Sphere->BodyInstance.bNotifyRigidBodyCollision = true;
	//	�X�^�e�B�b�N���b�V���̐ݒ�----------------------------------------------------------

	//	�X�v�����O�A�[���̐ݒ�----------------------------------------------------------------
	// SpringArm��ǉ�����
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	// �p�x��ύX���� FRotator(Pitch(Y), Yaw(Z), Roll(X))
	SpringArm->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));

	// Spring Arm�̒����𒲐�����
	SpringArm->TargetArmLength = 550.0f;

	// Pawn��ControllerRotation���g�p����
	SpringArm->bUsePawnControlRotation = true;

	// SpringArm����̊p�x���p�����Ȃ�
	SpringArm->bInheritPitch = false;

	// Camera��Lag��L���ɂ���
	SpringArm->bEnableCameraLag = false;
	//	�X�v�����O�A�[���̐ݒ�----------------------------------------------------------------


	//	�J�����̐ݒ�-------------------------------------------------------------------------
	// Camera��ǉ�����
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// MotionBlur���I�t�ɂ���
	Camera->PostProcessSettings.MotionBlurAmount = 0.0f;
	//	�J�����̐ݒ�-------------------------------------------------------------------------

	//	Arrow�̐ݒ�----------------------------------------------------------------------
	// Arrow��ǉ�����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetupAttachment(Camera);

	// Sphere�̓���Ɉړ�����悤��Location��ݒ肷��
	Arrow->SetRelativeLocation(FVector(400.0f, 0.0f, 130.0f));

	//	Arrow�̐ݒ�----------------------------------------------------------------------
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayer::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	FVector UpVector = FVector(0, 0, 1); // ������̃x�N�g��
	float DotProduct = FVector::DotProduct(HitNormal, UpVector); // �@���x�N�g���Ə�����̃x�N�g���̓���

	float Threshold = 0.7f; // ��ʂƔ��肷�邽�߂̂������l -1.0 < N < 1.0 �ŁA1�ɋ߂��قǗގ����Ă���

	if (DotProduct >= Threshold)
	{
		//	��ʂɓ������Ă����ꍇ
		bCanJump = true;

	}
	else
	{
		//	����ȊO�̖ʂɓ������Ă����ꍇ
	}

}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ControlBall();

}

// �@�\����͂Ƀo�C���h���邽�߂ɌĂяo�����
void AMyPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// MoveRight, MoveForward �ɕR�Â���ꂽ�L�[�ɖ��t���[����������
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("CameraAction", this, &AMyPlayer::CameraAction);
	PlayerInputComponent->BindAxis("Jump", this, &AMyPlayer::Jump);
}

void AMyPlayer::GoalIn(FVector Boost)
{
	Sphere->ComponentVelocity = FVector::ZeroVector;
	//Sphere->AddImpulse(Boost, TEXT("None"), true);
	bIsGoal = true;
}

// X���W�ɑ΂��鎲�}�b�s���O�̐���
void AMyPlayer::MoveRight(float AxisValue)
{
	if (!bIsGoal)
	{
		/*if (AxisValue)
		{
			UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("MoveRight"))
				, true
				, true
				, FColor::Cyan
				, 0.f);
		}*/

		// FMath::Clamp �֐����g���� AxisValue �̒l�� -1.0 ~ 1.0 �͈̔͂ɐ��䂵�Ă���
		CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f);
	}
}

// Y���W�ɑ΂��鎲�}�b�s���O�̐���
void AMyPlayer::MoveForward(float AxisValue)
{
	if (!bIsGoal)
	{
		/*if (AxisValue)
		{
			UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("MoveForward"))
				, true
				, true
				, FColor::Cyan
				, 0.f);
		}*/

		// FMath::Clamp �֐����g���� AxisValue �̒l�� -1.0 ~ 1.0 �͈̔͂ɐ��䂵�Ă���
		CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f);
	}
}

//	�J������X���ɑ΂��鑀��
void AMyPlayer::CameraAction(float AxisValue)
{
	if (!bIsGoal)
	{
		/*if (AxisValue)
		{
			UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("CameraInput %f"), AxisValue)
				, true
				, true
				, FColor::Cyan
				, 0.f);
		}*/


		AddControllerYawInput(AxisValue);

		// Pawn�������Ă���Control�̊p�x���擾����
		FRotator controlRotate = GetControlRotation();

		// PlayerController�̊p�x��ݒ肷��
		UGameplayStatics::GetPlayerController(this, 0)->SetControlRotation(FRotator(controlRotate.Pitch, controlRotate.Yaw, 0.0f));
	}
}

//	�W�����v
void AMyPlayer::Jump(float AxisValue)
{
	if (!bIsGoal)
	{
		if (AxisValue && bCanJump)
		{
			Sphere->AddImpulse(FVector(0.0f, 0.0f, JumpImpluse), TEXT("None"), true);
			bCanJump = false;
		}
	}
}

//	�ړ�����֐�
void AMyPlayer::ControlBall()
{
	//	���͒l��X��Y�����ւ���Ɨ͂̌����Ɛi�s��������v����
	FVector ForceVector = FVector(CurrentVelocity.Y, CurrentVelocity.X, 0.0F) * Speed;

	// Arrow�̐i�s������Vector���v�Z����
	FVector ArrowForceVector = Arrow->GetComponentToWorld().TransformVectorNoScale(ForceVector);

	//	sphere�ɗ͂�������
	Sphere->AddForce(ArrowForceVector, NAME_None, true);
}
