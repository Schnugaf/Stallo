// Hailstone Studio

#include "Stallo.h"
#include "ChoseNextWayPoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChoseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//1
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) {
		return EBTNodeResult::Failed;
	}

	auto PatrollPoints = PatrolRoute->GetPatrolPoint();
	if (PatrollPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing patrol Points"));
		return EBTNodeResult::Failed;
	}

	//2
	

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName,PatrollPoints[Index]);


	//3
	auto NextIndex = (Index + 1) % PatrollPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);



	
	return EBTNodeResult::Succeeded;
}