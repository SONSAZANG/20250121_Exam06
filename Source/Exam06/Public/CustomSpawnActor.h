#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.h"
#include "RotationCube.h"
#include "BlinkCube.h"
#include "CustomSpawnActor.generated.h"

UCLASS()
class EXAM06_API ACustomSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACustomSpawnActor();
	void SpawnActors();
	void DestroyActors();

private:
	UPROPERTY(EditAnywhere, Category = "CustomSpawnActor")
	TSubclassOf<AMovingCube> myMovingCubeClass;
	UPROPERTY(EditAnywhere, Category = "CustomSpawnActor")
	TSubclassOf<ARotationCube> myRotationCubeClass;
	UPROPERTY(EditAnywhere, Category = "CustomSpawnActor")
	TSubclassOf<ABlinkCube> myBlinkCubeClass;

protected:
	virtual void BeginPlay() override;
};
