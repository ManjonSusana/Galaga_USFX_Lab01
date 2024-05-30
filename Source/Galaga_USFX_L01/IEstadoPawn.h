// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEstadoPawn.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIEstadoPawn : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IIEstadoPawn
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void EstablecerJugador(class AGalaga_USFX_L01Pawn* _jugador) = 0;
	//metodos del estado del jugador
	virtual void Confundir() = 0;
	virtual void Aturdir() = 0;
	virtual void Danadar() = 0;
	virtual void Normalizar() = 0;
	//obtener el estado del jugador
	virtual void RegresarEstado() = 0;
	virtual FString ObtenerEstado() = 0;
};
