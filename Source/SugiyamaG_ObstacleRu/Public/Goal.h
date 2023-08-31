// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Goal.generated.h"

class UBoxComponent;

UCLASS()
class SUGIYAMAG_OBSTACLERU_API AGoal : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoal();

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	// Scene Component
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;

	//	�����O
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Ring;

	//	��Q�ɂȂ�_
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollider;

	float Timer = 0;
};
