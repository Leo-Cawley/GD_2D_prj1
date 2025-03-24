// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "InputActionValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaperCharacter.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Enemy.generated.h"

class UAI_Movement;
UCLASS()
class AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Shiz")
	UAI_Movement* AIMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* Collider;



public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveRight(const FInputActionValue& value);
	void MoveUp(const FInputActionValue& value);

};

