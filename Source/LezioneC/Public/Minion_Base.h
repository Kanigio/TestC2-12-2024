// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Minion_Base.generated.h"

UCLASS()
class LEZIONEC_API AMinion_Base : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AMinion_Base();
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	FString name;

	UPROPERTY(VisibleAnywhere, Category = "Variables")
	bool isActive;

	// Activate/Deactivate, should be called by an observator that is managing the minions
	virtual void Activate();
	virtual void Deactivate();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// OnActivate/OnDeactivate, is called in the Activate/Deactivate function and should be overridden in the children
	virtual void OnActivate();
	virtual void OnDeactivate();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
