// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Minion_Base.h" // Include Minion_Base to get the Array of the class "Minions_Base"
#include "GameFramework/Actor.h"
#include "MinionsObservator.generated.h"


UCLASS()
class LEZIONEC_API AMinionsObservator : public AActor
{
	GENERATED_BODY()

	
	
	
public:	
	// Sets default values for this actor's properties
	AMinionsObservator();

	UPROPERTY(EditAnywhere,Category="Settings")
	float checkInterval;

	UPROPERTY(EditAnywhere,Category="Settings")
	int MaximumActiveMinions;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Get a random valid minion and activate it
	virtual void GetRandomValidInt();
	virtual void ActivateMinion();

	// Get the total number of active minions and if they are less than the treshold activate one
	virtual void CheckTotalActiveMinions();

private:

	UPROPERTY(EditAnywhere,Category="Settings")
	TArray<class AMinion_Base*> Minions;
	
	UPROPERTY(VisibleAnywhere,Category = "Variables")
	int minionIndex;

	UPROPERTY(VisibleAnywhere,Category = "Variables")
	float timeSinceLastCheck = 0.f;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
