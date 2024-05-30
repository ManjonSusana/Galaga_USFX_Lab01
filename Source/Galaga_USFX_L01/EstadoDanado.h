// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstadoPawn.h"
#include "Galaga_USFX_L01Pawn.h"
#include "EstadoDanado.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AEstadoDanado : public AActor, public IIEstadoPawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoDanado();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void EstablecerJugador(class AGalaga_USFX_L01Pawn* _jugador) override;
	virtual void Danadar() override;
	virtual FString ObtenerEstado() override;
	virtual void RegresarEstado() override;
private:
	virtual void Confundir() override {};
	virtual void Aturdir() override {};
	virtual void Normalizar() override {};
	AGalaga_USFX_L01Pawn* jugador;
	void restarvidajugador();


};
