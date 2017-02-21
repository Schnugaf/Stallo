// Hailstone Studio

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STALLO_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public: 
	TArray<AActor*>GetPatrolPoint() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patroll Route")
		TArray<AActor*>PatrolPoints;
		
	
};
