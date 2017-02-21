// Hailstone Studio

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChoseNextWayPoint.generated.h"

/**
 * 
 */
UCLASS()
class STALLO_API UChoseNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IndexKey;
	
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WayPointKey;
};
