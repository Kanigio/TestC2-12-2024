// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion_Base.h"

// Sets default values
AMinion_Base::AMinion_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isActive = false;
	name = "Minion";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void AMinion_Base::Activate()
{
	// Set this actor active and change the visibility to be visible at the player
	isActive = true;
	SetActorHiddenInGame(false);
	OnActivate();
	
}

void AMinion_Base::Deactivate()
{
	// Set this actor off and change the visibility to be hidden at the player
	isActive = false;
	SetActorHiddenInGame(true);
	OnDeactivate();
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void AMinion_Base::OnActivate()
{
	// Is called in the Activate function and should be overridden in the children
	UE_LOG(LogTemp, Display, TEXT("Activate Minion: %s"), *name);
	
}

void AMinion_Base::OnDeactivate()
{
	// Is called in the Deactivate function and should be overridden in the children
	UE_LOG(LogTemp, Display, TEXT("Deactivate Minion: %s"), *name);
	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void AMinion_Base::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(true);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void AMinion_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

