#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlinkCube.generated.h"

UCLASS()
class EXAM06_API ABlinkCube : public AActor
{
	GENERATED_BODY()
	
	

public:	
	ABlinkCube();
	void ChangeActive();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkCube")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkCube")
	UStaticMeshComponent* StaticMeshComp;

protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle TimerHandle;
	UPROPERTY(EditAnywhere, Category = "BlinkCube")
	float BlinkSpeed;
	bool isActive;
};
