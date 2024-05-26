// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaBicho.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaBicho : public ANaveEnemiga
{
	GENERATED_BODY()

private:

	uint32 bCanFire : 1;// Variable para controlar el tiempo de disparo
	float FireRate; // Velocidad de disparo
	float FireCooldown; // Tiempo restante para el próximo disparo


	int TiempoTranscurrido;
	FVector PosicionInicial;

	enum class EstadoMovimiento { ArribaDerecha, AbajoDerecha, AbajoIzquierda, ArribaIzquierda };
	EstadoMovimiento EstadoActual;

public:
		ANaveEnemigaBicho();

		FORCEINLINE float Getvelocidad() const { return velocidad; }
		FORCEINLINE void Setvelocidad(float _velocidad) { velocidad = _velocidad; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



protected:
	void Mover(float DeltaTime);
	void Disparar();
	
	FTimerHandle TimerHandle_ShotTimerExpired; // Timer para controlar el tiempo de disparo

private:
	void Atacar() {};
	void Escapar() {};

};
