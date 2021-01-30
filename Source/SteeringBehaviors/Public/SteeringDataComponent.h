// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SteeringDataComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEERINGBEHAVIORS_API USteeringDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USteeringDataComponent();

	FVector GetLinearAcceleration() const;
	FRotator GetAngularAcceleration() const;

	void SetLinearAcceleration(FVector NewLinearAcceleration);
	void SetAngularAcceleration(FRotator NewAngularAcceleration);

private:
	FVector LinearAcceleration;
	FRotator AngularAcceleration;
};
