// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion_Fwd.h"


void AMinion_Fwd::OnActivate()
{
	Super::OnActivate();
	
	SetActorLocation(FVector(0,0,50));
	timeUntilDeath = 0;	
	
}

void AMinion_Fwd::OnDeactivate()
{
	Super::OnDeactivate();
	
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Called every frame
void AMinion_Fwd::Tick(float DeltaTime)
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
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * movSpeed);
	}

}