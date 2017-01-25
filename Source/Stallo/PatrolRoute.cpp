// Hailstone Studio

#include "Stallo.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoint() const
{
	return PatrolPoints;
}

