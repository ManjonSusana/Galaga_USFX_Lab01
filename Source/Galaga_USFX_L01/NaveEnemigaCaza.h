// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()

private:
	int cantidadBombas;

	uint32 bCanFire : 1;// Variable para controlar el tiempo de disparo
	float FireRate; // Velocidad de disparo

	int TiempoTranscurrido;

	//fACADE DISPAROS 
	class AFacadeDisparos* disparos; 

	// Variables para el movimiento
	FVector PosicionInicial;
	float MoveSpeed;
	float VerticalSpeed;
	float MaxVerticalOffset;
	float CurrentVerticalOffset;
	bool MovingUp;


public:
	ANaveEnemigaCaza();
	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int cantidad) { cantidadBombas = cantidad; }

	FORCEINLINE float Getvelocidad() const { return velocidad; }
	FORCEINLINE void Setvelocidad(float _velocidad) { velocidad = _velocidad; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// Velocidad de la nave de caza
	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Velocidad = 500.0f;

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
