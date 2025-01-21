// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationCube.generated.h"

UCLASS()
class EXAM06_API ARotationCube : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationCube();

	UPROPERTY(EditAnywhere, Category = "RotationCube")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, Category = "RotationCube")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, Category = "RotationCube")
	float RotationSpeed;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
