// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingBar.generated.h"

UCLASS()
class SUGIYAMAG_OBSTACLERU_API ARotatingBar : public AActor
{
	GENERATED_BODY()
	
public:
	// �f�t�H���g�l�̐ݒ�
	ARotatingBar();

protected:
	// �Q�[���J�n���A�܂��̓X�|�[�����ɌĂ΂��
	virtual void BeginPlay() override;

public:
	// ���t���[���Ă΂��
	virtual void Tick(float DeltaTime) override;

protected:

	// Scene Component
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;

	//	�和
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PrincipalPost;

	//	��Q�ɂȂ�_
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Bar;

	//	������]�����邽�߂̊p�x
	float Rotation = 0;

	UPROPERTY(EditAnywhere)
	bool bIsRight = true;
};
