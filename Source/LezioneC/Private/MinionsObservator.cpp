// Fill out your copyright notice in the Description page of Project Settings.


#include "MinionsObservator.h"

// Sets default values
AMinionsObservator::AMinionsObservator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	checkInterval = 1.f;

	MaximumActiveMinions = 5;
	minionIndex = 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void AMinionsObservator::GetRandomValidInt()
{
	// Get a Random index in range and check if it's valid, then Activate a minion with that index 
	int minionAmount = Minions.Num() - 1;
	minionIndex = FMath::RandRange(0, minionAmount);
	if (Minions[minionIndex]->isActive == true)
	{
		GetRandomValidInt();
		
	}	else	{
		ActivateMinion();
		
	}
	
}

void AMinionsObservator::ActivateMinion()
{
	// Call the Activate function of The minion of the same index of "minionIndex"
	Minions[minionIndex]->Activate();
	
}

void AMinionsObservator::CheckTotalActiveMinions()
{
	// Check the Array of Minion_Base and if there's already an active minion add 1 to the total int
	int activeMinions = 0;
	for (int i = 0; i < Minions.Num(); i++)
	{
		if (Minions[i]->isActive == true)
		{
			activeMinions++;
		}
	}
	
	UE_LOG(LogTemp, Display, TEXT("Current active minions: %d"), activeMinions);

	// If the Total Active Minions are less than the Maximum possible activate a random Minion
	if (activeMinions < MaximumActiveMinions)
	{
		GetRandomValidInt();
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void AMinionsObservator::BeginPlay()
{
	Super::BeginPlay();
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void AMinionsObservator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Check the total of active minions every interval
	if (timeSinceLastCheck >= checkInterval)
	{

		UE_LOG(LogTemp, Display, TEXT("CheckingMinions"));
		CheckTotalActiveMinions();
		timeSinceLastCheck = 0;
		
	}
	else
	{
		timeSinceLastCheck += DeltaTime;
	}

}

