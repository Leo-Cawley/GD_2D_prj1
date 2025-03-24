// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Enemy.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIMovement.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GD_2D_PRJ1_API UAI_Movement : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAI_Movement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Array of patrol nodes for the AI to follow, we will simply ping pong between these nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Pathfinding")
	TArray<AActor*> PatrolNodes;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	int CurrentPatrolNodeIndex = 0;
	AEnemy* OwnerPawn;
	void MoveToNextPatrolNode();

};
