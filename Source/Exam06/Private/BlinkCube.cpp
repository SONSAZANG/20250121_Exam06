#include "BlinkCube.h"

ABlinkCube::ABlinkCube()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void ABlinkCube::ChangeActive()
{
	isActive = !isActive;
	SetActorHiddenInGame(isActive);
}

void ABlinkCube::BeginPlay()
{
	Super::BeginPlay();
	isActive = true;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABlinkCube::ChangeActive, BlinkSpeed, true);
}