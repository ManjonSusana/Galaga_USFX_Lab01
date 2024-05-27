// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaAbeja.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaAbeja : public ANaveEnemiga
{
	GENERATED_BODY()

private:
	int caniones;

public:


	ANaveEnemigaAbeja();
	

	FORCEINLINE int GetCaniones() const { return caniones; }
	FORCEINLINE void SetCaniones(int cantidad) {caniones = cantidad;}
private:
	float JumpHeight;  // Altura del salto
	float JumpSpeed;   // Velocidad del salto
	float JumpTime;    // Tiempo actual del salto

	float TiempoCambio;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	virtual void Mover(float DeltaTime);
	void Saltar(float DeltaTime);
	
private:

	virtual void Disparar() {};
	virtual void Atacar() {};
	virtual void Escapar() {};

};
