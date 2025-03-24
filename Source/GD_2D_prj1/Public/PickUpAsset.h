// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PaperSpriteComponent.h"
#include "PickUpAsset.generated.h"

/**
 * 
 */
UCLASS()
class GD_2D_PRJ1_API UPickUpAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPickUpAsset();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "itemShiz")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "itemShiz")
	int Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "itemShiz")
	UPaperSprite* Icon;
	
};
