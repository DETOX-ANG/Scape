// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReportChair.h"


// Sets default values for this component's properties
UPositionReportChair::UPositionReportChair()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReportChair::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("Position Report Chair"));
	// ...
	
}


// Called every frame
void UPositionReportChair::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

