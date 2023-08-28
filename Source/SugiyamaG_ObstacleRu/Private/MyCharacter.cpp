// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

	// デフォルト値の設定
AMyCharacter::AMyCharacter()
{

 	// 毎フレーム実行する処理がある場合はこれをオンにする。
	PrimaryActorTick.bCanEverTick = false;
	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	// デフォルトシーンルートの設定------------------------------
	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// スタティックメッシュの設定--------------------------------
	// StaticMeshComponentを作成する
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/EditorMeshes/EditorCube"), NULL, LOAD_None, NULL);
	StaticMeshComponent->SetStaticMesh(Mesh);

	// StaticMeshComponentをRootComponentにAttachする
	StaticMeshComponent->SetupAttachment(RootComponent);
	//-----------------------------------------------------------

	// カメラの設定---------------------------------------------------------------
	// スプリングアームコンポーネントを作成
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(StaticMeshComponent);
	SpringArmComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.0f), FRotator(-10.0f, 0.0f, 0.0f));
	SpringArmComponent->TargetArmLength = 800.f;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->CameraLagSpeed = 15.0f;
		
	// カメラコンポーネントを作成
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// ルートコンポーネントとしてカメラをアタッチ
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	//CameraComponent->SetRelativeLocation(FVector(-420.f, 0.0f, 140.0f));
	//FVector Rotation(0.f, -20.f, 0.f);
	//FQuat QuatRotation = FQuat::MakeFromEuler(Rotation);
	//CameraComponent->SetRelativeRotation(QuatRotation);

	//メインカメラに設定する
	

	//---------------------------------------------------------------

}

// ゲーム開始時、またはスポーン時に呼ばれる
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// 毎フレーム呼ばれる
void AMyCharacter::Tick(float DeltaTime)
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%.1f,%.1f,%.1f")
		, GetActorLocation().X
		, GetActorLocation().Y
		, GetActorLocation().Z)
		, true, true, FColor::Cyan, 1.0f);
	// 移動に設定した軸に基づいて座標を変える
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

// 機能を入力にバインドするために呼び出される
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// MoveRight, MoveForward に紐づけられたキーに毎フレーム反応する
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
}

// X座標に対する軸マッピングの制御
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
	// 1 秒間に前後へ 100 単位移動
	// FMath::Clamp 関数を使って AxisValue の値を -1.0 ~ 1.0 の範囲に制御している
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%f"), CurrentVelocity.X)
		, true
		, true
		, FColor::Cyan
		, 0.f);
}

// Y座標に対する軸マッピングの制御
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
	// 1 秒間に左右へ 100 単位移動
	// FMath::Clamp 関数を使って AxisValue の値を -1.0 ~ 1.0 の範囲に制御している
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyCharacter::InputTest(float test)
{
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f);
}