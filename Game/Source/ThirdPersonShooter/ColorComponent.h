// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Game/TPSGameMode.h"
#include "ColorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatedMeshColor, FColor, OutColor);

UCLASS(SpatialType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONSHOOTER_API UColorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UColorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FOnUpdatedMeshColor OnUpdatedMeshColor;

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable)
		void Server_UpdateColorComponent();

	UFUNCTION(Client, Reliable)
		void Client_UpdateColorComponent(FColor InColor);

	UPROPERTY()
		FColor CurrentMeshColor;

	
};
