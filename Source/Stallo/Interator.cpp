// Hailstone Studio

#include "Stallo.h"
#include "Interator.h"

#define OUT


// Sets default values for this component's properties
UInterator::UInterator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UInterator::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsComponment();
	FindInputComponment();
}
void UInterator::FindPhysicsComponment()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing UPhysicsHandleComponent"), *GetOwner()->GetName());
	}
}

void  UInterator::FindInputComponment()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Interact", IE_Pressed, this, &UInterator::Grab);
		InputComponent->BindAction("Interact", IE_Released, this, &UInterator::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing UInputComponent"), *GetOwner()->GetName());
	}
}

// Called every frame
void UInterator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle) { return; }
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}


}
void UInterator::Grab()
{

	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit)
	{
		if (!PhysicsHandle) { return; }
		PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);
		UE_LOG(LogTemp, Warning, TEXT("Grab"));
	}
}
void UInterator::Release()
{
	if (!PhysicsHandle) { return; }
	PhysicsHandle->ReleaseComponent();
}

const FHitResult UInterator::GetFirstPhysicsBodyInReach()
{
	//DrawDebugLine(GetWorld(), GetReachLineStart(), GetReachLineEnd(), FColor(255, 0, 0), false, 0.f, 0, 10.f);

	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT HitResult, GetReachLineStart(), GetReachLineEnd(), FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters);

	return HitResult;
}

FVector UInterator::GetReachLineEnd()
{
	FVector Viewcord;
	FRotator ViewrotCord;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT Viewcord, OUT ViewrotCord);

	return Viewcord + ViewrotCord.Vector() * Reach;
}


FVector UInterator::GetReachLineStart()
{
	FVector Viewcord;
	FRotator ViewrotCord;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT Viewcord, OUT ViewrotCord);

	return Viewcord;
}

