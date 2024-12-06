// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion_Hori.h"

void AMinion_Hori::OnActivate()
{
	Super::OnActivate();
	
	SetActorLocation(FVector(0,0,50));
	timeUntilDeath = 0;	
	
}

void AMinion_Hori::OnDeactivate()
{
	Super::OnDeactivate();
	
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void AMinion_Hori::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timeUntilDeath >= LifeTime && isActive == true)
	{
		Deactivate();
		timeUntilDeath = 0;		
	}
	else
	{
		timeUntilDeath += DeltaTime;
		SetActorLocation(GetActorLocation() + GetActorRightVector() * movSpeed);
	}

}