// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingBar.h"

// Sets default values
ARotatingBar::ARotatingBar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// デフォルトシーンルートの設定------------------------------
	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// PrincipalPostの設定--------------------------------
	// StaticMeshComponentを作成する
	PrincipalPost = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrincipalPostMesh"));

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* PrincipalPostMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cylinder"), NULL, LOAD_None, NULL);
	PrincipalPost->SetRelativeScale3D(FVector(1.0f, 1.0f, 2.5f));
	PrincipalPost->SetStaticMesh(PrincipalPostMesh);

	// StaticMeshComponentをRootComponentにAttachする
	PrincipalPost->SetupAttachment(RootComponent);
	//-----------------------------------------------------------
	
	//// Barの設定--------------------------------
	//// StaticMeshComponentを作成する
	Bar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarMesh"));

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* BarMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cylinder"), NULL, LOAD_None, NULL);
	Bar->SetStaticMesh(BarMesh);

	Bar->SetRelativeScale3D(FVector(0.5f, 0.5f, 4.0));
	Bar->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	// StaticMeshComponentをPrincipalPostにAttachする
	Bar->SetupAttachment(PrincipalPost);
	//-----------------------------------------------------------

}

// Called when the game starts or when spawned
void ARotatingBar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingBar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsRight)
	{
		//	毎フレーム2度ずつ回転させる
		Rotation += 2;
	}
	else
	{
		//	毎フレーム-2度ずつ回転させる
		Rotation -= 2;
	}
	PrincipalPost->SetWorldRotation(FRotator(0.0f, Rotation, 0.0f));

}

