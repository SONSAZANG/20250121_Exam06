#include "MovingCube.h"

AMovingCube::AMovingCube()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	

}

void AMovingCube::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = FVector(GlobalStartLocation.X + MaxRange, GlobalStartLocation.Y, GlobalStartLocation.Z);
}

void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();

	
	if (FMath::Abs(Location.X - GlobalStartLocation.X) > MaxRange) {
		FVector Temp = GlobalTargetLocation;
		GlobalTargetLocation = GlobalStartLocation;
		GlobalStartLocation = Temp;
	}

	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
	
	Location += Direction * MoveSpeed * DeltaTime;
	SetActorLocation(Location);
}

