// Hailstone Studio

#pragma once

#include "Components/ActorComponent.h"
#include "Interator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STALLO_API UInterator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInterator();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	void Grab();
	void Release();
	void FindPhysicsComponment();

	void FindInputComponment();

	const FHitResult GetFirstPhysicsBodyInReach();
	FVector GetReachLineStart();
	FVector GetReachLineEnd();

	
};
