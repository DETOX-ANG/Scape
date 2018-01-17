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
	Super::BeginPlay();
	//ActorOpenDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


void UOpenDoor::OpenDoor()
{
	//Create a Owner
	AActor* Owner = GetOwner();

	// Create a rotator
	FRotator rotation = FRotator(0.f, 60.f, 0.f);

	//Create a rotation
	Owner->SetActorRotation(rotation);
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ActorOpenDoor = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PressurePlate->IsOverlappingActor(ActorOpenDoor)) {
		OpenDoor();
	}
	// ...
}

