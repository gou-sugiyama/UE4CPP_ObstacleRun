// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.generated.h"

UCLASS()
class SUGIYAMAG_OBSTACLERU_API AMyCharacter : public AActor
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


private:
	// Scene Component
	//UPROPERTY(EditAnywhere) <- �B���Ė��Ȃ������H�H�H
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

};