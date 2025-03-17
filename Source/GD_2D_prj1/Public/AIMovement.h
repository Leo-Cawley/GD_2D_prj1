// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIMovement.generated.h"


class AEnemy;

UCLASS()
class GD_2D_PRJ1_API AAIMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIMovement();

	// Array of patrol nodes for the AI to follow, we will simply ping pong between these nodes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Pathfinding")
	TArray<AActor*> PatrolNodes;
	virtual void Tick(float DeltaTime) override;

private:
	AEnemy* OwnerPawn;
	int CurrentPatrolNodeIndex = 0; // track our current node
	// AEnemy* OwnerPawn; // store our owner
	void MoveToNextPatrolNode(); // calculate movement


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
};
