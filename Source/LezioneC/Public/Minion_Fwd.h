// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Minion_Base.h"
#include "Minion_Fwd.generated.h"

/**
 * 
 */
UCLASS()
class LEZIONEC_API AMinion_Fwd : public AMinion_Base
{
	GENERATED_BODY()

	
public:

	UPROPERTY(EditAnywhere,Category="Settings")
	float movSpeed = 10;

protected:
	
	virtual void OnActivate() override;
	virtual void OnDeactivate() override;
	
private:

	UPROPERTY(EditAnywhere, Category="Settings")
	float LifeTime = 5;
	
	UPROPERTY(VisibleAnywhere, Category="Variables")
	float timeUntilDeath = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};