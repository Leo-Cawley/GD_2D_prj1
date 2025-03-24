// Copyright Epic Games, Inc. All Rights Reserved.


#include "AIMovement.h"

// Sets default values for this component's properties
UAI_Movement::UAI_Movement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrentPatrolNodeIndex = 0;
	// ...
}


// Called when the game starts
void UAI_Movement::BeginPlay()
{
	Super::BeginPlay();
	OwnerPawn = Cast<AEnemy>(GetOwner());
	if (!OwnerPawn) // if the owner of this component is null
	{
		UE_LOG(LogTemp, Error, TEXT("AIMovementComponent can only be attached to a Pawn."));
		this->DestroyComponent();
	}
	// ...

}


// Called every frame
void UAI_Movement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToNextPatrolNode();
	// ...
}

void UAI_Movement::MoveToNextPatrolNode()
{
	// If we have no patrol nodes, return
	if (PatrolNodes.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("no nodes"));
		return;
	}
	else if (PatrolNodes.Num() == 1) // If we have only one patrol node, set the owner's location to that node's location
	{
		UE_LOG(LogTemp, Error, TEXT("not enough nodes"));
		OwnerPawn->SetActorLocation(PatrolNodes[0]->GetActorLocation());
		return;
	}
	if (OwnerPawn->GetActorLocation().X > PatrolNodes[CurrentPatrolNodeIndex]->GetActorLocation().X) // are we moving left or right?
	{
		// move left
		OwnerPawn->MoveRight(-1.0f);
	}
	else
	{
		// move right
		OwnerPawn->MoveRight(1.0f);
	}

	// if we have reached the patrol node, move to the next one
	if (FMath::Abs(OwnerPawn->GetActorLocation().X - PatrolNodes[CurrentPatrolNodeIndex]->GetActorLocation().X) < 10.0f)
	{
		CurrentPatrolNodeIndex = (CurrentPatrolNodeIndex + 1) % PatrolNodes.Num();
	}

}