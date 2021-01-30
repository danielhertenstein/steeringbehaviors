// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetSeekSteering.generated.h"

/**
 * 
 */
UCLASS()
class STEERINGBEHAVIORS_API UBTTask_GetSeekSteering : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTTask_GetSeekSteering();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
