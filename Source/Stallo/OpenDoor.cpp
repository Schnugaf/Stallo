// Hailstone Studio

#include "Stallo.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();


	//actorthatopens = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing PressurePlate"), *GetOwner()->GetName());
	}

	// ...

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	//if (PressurePlate->IsOverlappingActor(actorthatopens))
	
	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		OpOpen.Broadcast();
	}
	else
	{
		OpClose.Broadcast();
	}



	// ...
}




float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;
	if (!PressurePlate) { return TotalMass; }
	TArray<AActor*> OverLanppingActor;
	PressurePlate->GetOverlappingActors(OUT OverLanppingActor);

	for (const auto& Actor : OverLanppingActor)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Actor->GetName())
	}
	return TotalMass;
}

