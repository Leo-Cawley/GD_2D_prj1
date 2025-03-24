// Copyright Epic Games, Inc. All Rights Reserved.


#include "Enemy.h"
#include "AIMovement.h"
#include "PaperFlipbookComponent.h"

// Sets default values
AEnemy::AEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	RootComponent = Sprite;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));

	Collider->SetupAttachment(RootComponent);

	AIMovement = CreateDefaultSubobject<UAI_Movement>(TEXT("AIMovement"));
	/*AIMovement->SetupAttachment(RootComponent);*/
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

}



// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::MoveRight(const FInputActionValue& Value) {
	SetActorLocation(GetActorLocation() + FVector::ForwardVector * Value.Get<float>());
}
void AEnemy::MoveUp(const FInputActionValue& Value) {
	SetActorLocation(GetActorLocation() + FVector::UpVector * Value.Get<float>());
}

