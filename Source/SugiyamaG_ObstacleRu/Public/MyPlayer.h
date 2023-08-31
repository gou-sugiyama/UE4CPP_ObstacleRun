// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UArrowComponent;

UCLASS()
class SUGIYAMAG_OBSTACLERU_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Hit Event��Binding����֐�
	virtual void NotifyHit(class UPrimitiveComponent* MyComp
		, class AActor* Other
		, class UPrimitiveComponent* OtherComp
		, bool bSelfMoved, FVector HitLocation
		, FVector HitNormal
		, FVector NormalImpulse
		, const FHitResult& Hit) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ���͂ɋ@�\���o�C���h���邽�߂ɌĂяo�����
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//	�S�[���������ɉ�������
	void GoalIn(FVector Boost);


private:
	/** Character�p��StaticMesh : Sphere */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Sphere;

	/** Camera��z�u���邽�߂�SpringArm */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** SpringArm�̐�[�ɔz�u����J���� */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	/** �i�s������\������ArrowComponent */
	UPROPERTY(VisibleAnywhere, Category = Control, meta = (AllowPrivateAccess = "true"))
		UArrowComponent* Arrow;

	//Input functions (���͊֐�)
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void CameraAction(float AxisValue);
	void Jump(float AxisValue);

	//	�ړ�����֐�
	void ControlBall();

	// ���x
	float Speed = 500.0f;
	
	//Input variables (���͕ϐ�)
	FVector CurrentVelocity;

	// �W�����v�ɉ������
	float JumpImpluse = 500.0f;

	// �W�����v���ł��邩���肷��t���O
	bool bCanJump = false;

	//	�S�[���������i����s�\�ɂ���]�T���Ȃ��̂ł��艟���j
	bool bIsGoal = false;
};
