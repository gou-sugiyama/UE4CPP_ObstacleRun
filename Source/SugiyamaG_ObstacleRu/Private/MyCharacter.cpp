// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

	// デフォルト値の設定
AMyCharacter::AMyCharacter()
{
 	// 毎フレーム実行する処理がある場合はこれをオンにする。
	PrimaryActorTick.bCanEverTick = false;

	// デフォルトシーンルートの設定------------------------------
	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// スタティックメッシュの設定--------------------------------
	// StaticMeshComponentを作成する
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/EditorMeshes/EditorCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponentをRootComponentにAttachする
	StaticMesh->SetupAttachment(RootComponent);
	//-----------------------------------------------------------
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

