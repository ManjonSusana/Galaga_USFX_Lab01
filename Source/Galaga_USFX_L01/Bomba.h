// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProyectilEnemigo.h"
#include "Bomba.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ABomba : public AProyectilEnemigo
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomba();

	float velocidad;
	UStaticMeshComponent* BombaMesh;

	FVector PosicionInicial;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void TipoBomba(FString _bomba);
	void RadioExplosion();
	void MovimientoBomba();
	void DestruirBomba();

};
