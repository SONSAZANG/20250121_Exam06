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
	// 해당 변수는 SetTimer로 실행되서 처음 이후로 변하지 않습니다.
	UPROPERTY(EditDefaultsOnly, Category = "BlinkCube")
	float BlinkSpeed;
	bool isActive;
};
