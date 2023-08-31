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
	//	スタティックメッシュの設定----------------------------------------------------------
	// StaticMeshComponentを追加し、RootComponentに設定する
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Sphere;

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMeshをStaticMeshComponentに設定する
	Sphere->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere")));

	// MaterialをStaticMeshに設定する
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// MaterialをStaticMeshComponentに設定する
	Sphere->SetMaterial(0, Material);

	// Simulate Physicsを有効にする
	Sphere->SetSimulatePhysics(true);

	// CollisionPresetを「PhysicsActor」に変更する
	Sphere->SetCollisionProfileName(TEXT("PhysicsActor"));

	// Hit Eventを有効にする
	Sphere->BodyInstance.bNotifyRigidBodyCollision = true;
	//	スタティックメッシュの設定----------------------------------------------------------

	//	スプリングアームの設定----------------------------------------------------------------
	// SpringArmを追加する
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	// 角度を変更する FRotator(Pitch(Y), Yaw(Z), Roll(X))
	SpringArm->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));

	// Spring Armの長さを調整する
	SpringArm->TargetArmLength = 550.0f;

	// PawnのControllerRotationを使用する
	SpringArm->bUsePawnControlRotation = true;

	// SpringArmからの角度を継承しない
	SpringArm->bInheritPitch = false;

	// CameraのLagを有効にする
	SpringArm->bEnableCameraLag = false;
	//	スプリングアームの設定----------------------------------------------------------------


	//	カメラの設定-------------------------------------------------------------------------
	// Cameraを追加する
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// MotionBlurをオフにする
	Camera->PostProcessSettings.MotionBlurAmount = 0.0f;
	//	カメラの設定-------------------------------------------------------------------------

	//	Arrowの設定----------------------------------------------------------------------
	// Arrowを追加する
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetupAttachment(Camera);

	// Sphereの頭上に移動するようにLocationを設定する
	Arrow->SetRelativeLocation(FVector(400.0f, 0.0f, 130.0f));

	//	Arrowの設定----------------------------------------------------------------------
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayer::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	FVector UpVector = FVector(0, 0, 1); // 上向きのベクトル
	float DotProduct = FVector::DotProduct(HitNormal, UpVector); // 法線ベクトルと上向きのベクトルの内積

	float Threshold = 0.7f; // 上面と判定するためのしきい値 -1.0 < N < 1.0 で、1に近いほど類似している

	if (DotProduct >= Threshold)
	{
		//	上面に当たっていた場合
		bCanJump = true;

	}
	else
	{
		//	それ以外の面に当たっていた場合
	}

}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ControlBall();

}

// 機能を入力にバインドするために呼び出される
void AMyPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// MoveRight, MoveForward に紐づけられたキーに毎フレーム反応する
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

// X座標に対する軸マッピングの制御
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

		// FMath::Clamp 関数を使って AxisValue の値を -1.0 ~ 1.0 の範囲に制御している
		CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f);
	}
}

// Y座標に対する軸マッピングの制御
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

		// FMath::Clamp 関数を使って AxisValue の値を -1.0 ~ 1.0 の範囲に制御している
		CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f);
	}
}

//	カメラのX軸に対する操作
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

		// Pawnが持っているControlの角度を取得する
		FRotator controlRotate = GetControlRotation();

		// PlayerControllerの角度を設定する
		UGameplayStatics::GetPlayerController(this, 0)->SetControlRotation(FRotator(controlRotate.Pitch, controlRotate.Yaw, 0.0f));
	}
}

//	ジャンプ
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

//	移動制御関数
void AMyPlayer::ControlBall()
{
	//	入力値のXとYを入れ替えると力の向きと進行方向が一致する
	FVector ForceVector = FVector(CurrentVelocity.Y, CurrentVelocity.X, 0.0F) * Speed;

	// Arrowの進行方向のVectorを計算する
	FVector ArrowForceVector = Arrow->GetComponentToWorld().TransformVectorNoScale(ForceVector);

	//	sphereに力を加える
	Sphere->AddForce(ArrowForceVector, NAME_None, true);
}
