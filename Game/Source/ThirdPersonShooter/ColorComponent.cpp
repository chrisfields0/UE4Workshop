// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ColorComponent.h"
#include "SpatialNetDriver.h"
#include "Connection/SpatialWorkerConnection.h"
#include"UnrealNetwork.h"


// Sets default values for this component's properties
UColorComponent::UColorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UColorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UColorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UColorComponent::Server_UpdateColorComponent_Validate()
{
	return true;
}

void UColorComponent::Server_UpdateColorComponent_Implementation()
{
	ATPSGameMode* gameMode = Cast<ATPSGameMode>(GetWorld()->GetAuthGameMode());
	Client_UpdateColorComponent(gameMode->ObjectColor);
}

void UColorComponent::Client_UpdateColorComponent_Implementation(FColor InColor)
{
	CurrentMeshColor = InColor;
	OnUpdatedMeshColor.Broadcast(InColor);
}
