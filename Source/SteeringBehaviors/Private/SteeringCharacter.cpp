// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.


#include "SteeringCharacter.h"

// Sets default values
ASteeringCharacter::ASteeringCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASteeringCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASteeringCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void ASteeringCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

// Called every frame
void ASteeringCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASteeringCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ASteeringCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASteeringCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnRight", this, &ACharacter::AddControllerYawInput);
}

