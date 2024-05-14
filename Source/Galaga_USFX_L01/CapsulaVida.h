// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CapsulaVida.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ACapsulaVida : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ACapsulaVida();
	virtual void PickUp(); //es para recoger el objeto
	virtual void PutDown(FTransform TargetLocation); //es para dejar el objeto

	
};
