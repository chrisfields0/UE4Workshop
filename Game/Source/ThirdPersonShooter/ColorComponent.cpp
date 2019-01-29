// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ColorComponent.h"
#include "SpatialNetDriver.h"
#include "Connection/SpatialWorkerConnection.h"
#include"UnrealNetwork.h"

#pragma optimize("", off)
// Sets default values for this component's properties
UColorComponent::UColorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bReplicates = true;
	// ...
}


// Called when the game starts
void UColorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UColorComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UColorComponent, CurrentMeshColor);
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
	UE_LOG(LogTemp, Warning, TEXT("Server%d Server_UpdateColorComponent 0x%x ObjectColor: R: %d G: %d B: %d A: %d"), GPlayInEditorID, this, gameMode->ObjectColor.R, gameMode->ObjectColor.G, gameMode->ObjectColor.B, gameMode->ObjectColor.A);
	UE_LOG(LogTemp, Warning, TEXT("Server%d Server_UpdateColorComponent 0x%x CurrentMeshColor: R: %d G: %d B: %d A: %d"), GPlayInEditorID, this,  CurrentMeshColor.R, CurrentMeshColor.G, CurrentMeshColor.B, CurrentMeshColor.A);
	CurrentMeshColor =  gameMode->ObjectColor;
}

void UColorComponent::OnRep_CurrentMeshColor()
{
	OnUpdatedMeshColor.Broadcast(CurrentMeshColor);
}
