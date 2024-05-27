// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TorreEnemiga.h"
#include "TorreEnemiga2.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ATorreEnemiga2 : public ATorreEnemiga
{
	GENERATED_BODY()
private:
	// Sets default values for this actor's properties
	ATorreEnemiga2();

	float velocidadTorre;
	FVector PosicionInicialTorre_2;

	float LimiteInferior;
	float LimiteSuperior;
	float tiempoTranscurrido;
	float Direccion; // 1 para derecha, -1 para izquierda

	bool verificacionMovimiento = false;
	bool verificacionDisparo = false;

	//TArray<ATorreEnemiga1>Torre_1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void CrearTorreEnemiga(class AFacadeGenerador* Fachada) override;
	virtual void AnadirMovimiento() override;
	virtual void AnadirDisparo() override;
	
};
