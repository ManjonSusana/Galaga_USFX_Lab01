// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTransporte : public ANaveEnemiga
{
	GENERATED_BODY()


public:

	ANaveEnemigaTransporte();
private:
	float TiempoTranscurrido;

	FVector PosicionInicial;
	bool MoviendoseALaIzquierda;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	void Mover(float DeltaTime);
	void Botar();


private:

	void Disparar() {};	
	void Atacar() {};
	void Escapar() {};

};
