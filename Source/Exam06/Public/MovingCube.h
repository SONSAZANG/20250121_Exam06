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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingCube")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingCube")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingCube")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingCube")
	float MoveSpeed;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
