// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingBar.h"

// Sets default values
ARotatingBar::ARotatingBar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �f�t�H���g�V�[�����[�g�̐ݒ�------------------------------
	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// PrincipalPost�̐ݒ�--------------------------------
	// StaticMeshComponent���쐬����
	PrincipalPost = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrincipalPostMesh"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* PrincipalPostMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cylinder"), NULL, LOAD_None, NULL);
	PrincipalPost->SetRelativeScale3D(FVector(1.0f, 1.0f, 2.5f));
	PrincipalPost->SetStaticMesh(PrincipalPostMesh);

	// StaticMeshComponent��RootComponent��Attach����
	PrincipalPost->SetupAttachment(RootComponent);
	//-----------------------------------------------------------
	
	//// Bar�̐ݒ�--------------------------------
	//// StaticMeshComponent���쐬����
	Bar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarMesh"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* BarMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cylinder"), NULL, LOAD_None, NULL);
	Bar->SetStaticMesh(BarMesh);

	Bar->SetRelativeScale3D(FVector(0.5f, 0.5f, 4.0));
	Bar->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	// StaticMeshComponent��PrincipalPost��Attach����
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
		//	���t���[��2�x����]������
		Rotation += 2;
	}
	else
	{
		//	���t���[��-2�x����]������
		Rotation -= 2;
	}
	PrincipalPost->SetWorldRotation(FRotator(0.0f, Rotation, 0.0f));

}

