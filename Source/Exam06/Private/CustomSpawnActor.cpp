#include "CustomSpawnActor.h"
#include "Kismet/GameplayStatics.h"
#include "MovingCube.h"
#include "RotationCube.h"
#include "BlinkCube.h"
#include "GameFramework/Character.h"

ACustomSpawnActor::ACustomSpawnActor()
{
}

void ACustomSpawnActor::SpawnActors()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();
	int RandY = FMath::RandRange(-800, 800);
	int RandZ = FMath::RandRange(0, 300);
	UE_LOG(LogTemp, Display, TEXT("RandY %d"), RandY);
	int RandInt = FMath::RandRange(1, 3);
	switch (RandInt)
	{
		case 1:
			GetWorld()->SpawnActor<AMovingCube>(myMovingCubeClass, SpawnLocation + FVector(0, RandY, RandZ), SpawnRotation);
			break;
		case 2:
			GetWorld()->SpawnActor<ARotationCube>(myRotationCubeClass, SpawnLocation + FVector(0, RandY, RandZ), SpawnRotation);
			break;
		case 3:
			GetWorld()->SpawnActor<ABlinkCube>(myBlinkCubeClass, SpawnLocation + FVector(0, RandY, RandZ), SpawnRotation);
			break;
	}
}

void ACustomSpawnActor::DestroyActors()
{
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMovingCube::StaticClass(), FoundActors);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARotationCube::StaticClass(), FoundActors);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlinkCube::StaticClass(), FoundActors);
	
	for (AActor* ActorFound : FoundActors) 
	{
		ActorFound->Destroy();
	}
}

void ACustomSpawnActor::BeginPlay()
{
	Super::BeginPlay();
	SpawnActors();
}