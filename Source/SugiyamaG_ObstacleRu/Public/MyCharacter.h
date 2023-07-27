// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyCharacter.generated.h"

UCLASS()
class SUGIYAMAG_OBSTACLERU_API AMyCharacter : public APawn
{
	GENERATED_BODY()
	
public:	
	// �f�t�H���g�l�̐ݒ�
	AMyCharacter();

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

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

};
