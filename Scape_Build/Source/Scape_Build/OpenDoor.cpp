// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{	
	Owner = GetOwner();
	Super::BeginPlay();
	//ActorOpenDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


void UOpenDoor::OpenDoor()
{

	//Create a rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	
	Owner->SetActorRotation(FRotator(0.f, -90.f, 0.f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ActorOpenDoor = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PressurePlate->IsOverlappingActor(ActorOpenDoor)) {
		OpenDoor();
		//gettime pega o tempo atual
		LastTimeOpen = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds() - LastTimeOpen > CloseDoorDelay)
	{
		CloseDoor();
	}


	// ...
}

