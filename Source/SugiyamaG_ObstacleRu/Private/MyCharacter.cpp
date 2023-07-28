// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

	// デフォルト値の設定
AMyCharacter::AMyCharacter()
{

 	// 毎フレーム実行する処理がある場合はこれをオンにする。
	PrimaryActorTick.bCanEverTick = false;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

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
	Super::Tick(DeltaTime);

}

// 機能を入力にバインドするために呼び出される
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}