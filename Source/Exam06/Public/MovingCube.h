// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class EXAM06_API AMovingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingCube();

	UPROPERTY(EditAnywhere, Category = "MovingCube")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, Category = "MovingCube")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, Category = "MovingCube")
	float MaxRange;
	UPROPERTY(EditAnywhere, Category = "MovingCube")
	float MoveSpeed;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
