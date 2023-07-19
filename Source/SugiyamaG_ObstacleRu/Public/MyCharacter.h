// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class SUGIYAMAG_OBSTACLERU_API AMyCharacter : public APawn
{
	GENERATED_BODY()
	
public:	
	// デフォルト値の設定
	AMyCharacter();

protected:
	// ゲーム開始時、またはスポーン時に呼ばれる
	virtual void BeginPlay() override;

public:	
	// 毎フレーム呼ばれる
	virtual void Tick(float DeltaTime) override;


private:
	// Scene Component
	//UPROPERTY(EditAnywhere) <- 隠して問題なさそう？？？
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

};
