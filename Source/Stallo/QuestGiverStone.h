// Hailstone Studio

#pragma once

#include "GameFramework/Actor.h"
#include "QuestGiverStone.generated.h"

UCLASS()
class STALLO_API AQuestGiverStone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestGiverStone();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
