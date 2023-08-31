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

	// Hit EventをBindingする関数
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

	// 入力に機能をバインドするために呼び出される
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//	ゴールした時に加速する
	void GoalIn(FVector Boost);


private:
	/** Character用のStaticMesh : Sphere */
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Sphere;

	/** Cameraを配置するためのSpringArm */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** SpringArmの先端に配置するカメラ */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	/** 進行方向を表示するArrowComponent */
	UPROPERTY(VisibleAnywhere, Category = Control, meta = (AllowPrivateAccess = "true"))
		UArrowComponent* Arrow;

	//Input functions (入力関数)
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void CameraAction(float AxisValue);
	void Jump(float AxisValue);

	//	移動制御関数
	void ControlBall();

	// 速度
	float Speed = 500.0f;
	
	//Input variables (入力変数)
	FVector CurrentVelocity;

	// ジャンプに加える力
	float JumpImpluse = 500.0f;

	// ジャンプができるか判定するフラグ
	bool bCanJump = false;

	//	ゴールしたか（操作不能にする余裕がないのでごり押し）
	bool bIsGoal = false;
};
