// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemigaMariposa.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaMariposa : public ANaveEnemiga
{
	GENERATED_BODY()


public:
	ANaveEnemigaMariposa();

private:
	
	FTimerHandle TimerHandle_CambioDeEtapas;
	FTimerHandle TimerHandle_Persecucion;
	FTimerHandle TimerHandle_Regreso;

	bool bPersecucionActiva;
	bool bRegresando;

	FVector PosicionInicial;
	float TiempoDeCambioDeEtapas;
	float MoveSpeed;  // Velocidad de movimiento
	AGalaga_USFX_L01Pawn* PawnTarget; // Variable para almacenar el objetivo Pawn

	void MoverEnCirculo(float DeltaTime);
	void PerseguirPawn(float DeltaTime);
	void RegresarAInicio(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void Mover(float DeltaTime);
	void Atacar();
	void SetPawnTarget(AGalaga_USFX_L01Pawn* NewPawn); // Método para establecer el objetivo Pawn

private:
	void ActivarPersecucion();
	void ActivarRegreso();
	void ReanudarMovimientoCircular();

private:
	void Disparar() {};
	void Escapar() {};
	
};
