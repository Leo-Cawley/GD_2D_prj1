// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovement.h"
#include "Enemy.h"

// Sets default values
AAIMovement::AAIMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentPatrolNodeIndex = 0;
}

// Called when the game starts or when spawned
void AAIMovement::BeginPlay()
{
	Super::BeginPlay();

	OwnerPawn = Cast<AEnemy>(GetOwner());
	if (!OwnerPawn) // if the owner of this component is null
	{
		UE_LOG(LogTemp, Error, TEXT("AIMovementComponent can only be attached to a Pawn."));
		this->Destroy();
	}

	
}

void AAIMovement::MoveToNextPatrolNode()
{
	// If we have no patrol nodes, return
	if (PatrolNodes.Num() == 0)
	{
		return;
	}
	else if (PatrolNodes.Num() == 1) // If we have only one patrol node, set the owner's location to that node's location
	{
		OwnerPawn->SetActorLocation(PatrolNodes[0]->GetActorLocation());
		return;
	}


	if (FMath::Abs(PatrolNodes[CurrentPatrolNodeIndex]->GetActorLocation().X - GetActorLocation().X) > 1) {
		OwnerPawn->MoveRight(FMath::Sign(PatrolNodes[CurrentPatrolNodeIndex]->GetActorLocation().X - GetActorLocation().X));
	}

	// check if we have reached the patrol node

}


// Called every frame
void AAIMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToNextPatrolNode();
}

