// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

#include "Components/BoxComponent.h"
#include "MyPlayer.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AGoal::AGoal()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// デフォルトシーンルートの設定------------------------------
	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;
	//-----------------------------------------------------------

	// StaticMeshの設定-------------------------------------------------------
	Ring = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ring"));
	Ring->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	Ring->SetupAttachment(DefaultSceneRoot);

	UStaticMesh* RingStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/SM_Ring.SM_Ring"));
	Ring->SetStaticMesh(RingStaticMesh);

	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/MapTemplates/Materials/BasicAsset01"));
	Ring->SetMaterial(0, Material);
	// StaticMeshの設定-------------------------------------------------------

	// BoxColliderの設定-------------------------------------------------------
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	BoxCollider->SetRelativeScale3D(FVector(0.25f, 5.0f, 5.0f));

	BoxCollider->SetupAttachment(Ring);

	// BoxColliderの設定-------------------------------------------------------


	// OnComponentBeginOverlapをBindする
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnBoxBeginOverlap);


}


void AGoal::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 接触したActorがBallPlayerか判定する
	if (AMyPlayer* Player = Cast<AMyPlayer>(OtherActor))
	{
		Player->GoalIn(FVector(2000, 0, 0));

		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Result %f"), Timer)
			, true
			, true
			, FColor::Cyan
			, 100.f);

	}
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer += DeltaTime;
}

// Called to bind functionality to input
void AGoal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

