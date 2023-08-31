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
	// デフォルト値の設定
	ARotatingBar();

protected:
	// ゲーム開始時、またはスポーン時に呼ばれる
	virtual void BeginPlay() override;

public:
	// 毎フレーム呼ばれる
	virtual void Tick(float DeltaTime) override;

protected:

	// Scene Component
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;

	//	主柱
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PrincipalPost;

	//	障害になる棒
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Bar;

	//	水平回転させるための角度
	float Rotation = 0;

	UPROPERTY(EditAnywhere)
	bool bIsRight = true;
};
