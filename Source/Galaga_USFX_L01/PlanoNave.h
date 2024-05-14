// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlanoNave.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlanoNave : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IPlanoNave
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//virtual void SetNaveMejoras() = 0;
	virtual void SetVidaNave(FString VidaNave) = 0;
	virtual void SetMotorNave(FString VelocidadNave) = 0;
	virtual void SetArmaNave(FString ArmaNave) = 0;

	virtual void SetMalla(UStaticMeshComponent* MallaNave) = 0;
};
