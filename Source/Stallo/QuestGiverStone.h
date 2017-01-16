// Hailstone Studio

#pragma once

#include "GameFramework/Actor.h"
#include "QuestGiverStone.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStoneEvent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	


	UPROPERTY(BlueprintAssignable)
	FStoneEvent StoneActivatet;

	UPROPERTY(BlueprintAssignable)
	FStoneEvent OpClose;

};
