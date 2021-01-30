// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_UpdateKinematics.generated.h"

/**
 * 
 */
UCLASS()
class STEERINGBEHAVIORS_API UBTTask_UpdateKinematics : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_UpdateKinematics();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
