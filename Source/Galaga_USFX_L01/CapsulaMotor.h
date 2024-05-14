// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CapsulaMotor.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ACapsulaMotor : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ACapsulaMotor();
	virtual void PickUp(); //es para recoger el objeto
	virtual void PutDown(FTransform TargetLocation); //es para dejar el objeto

	
};
