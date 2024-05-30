// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TorreEnemiga.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ATorreEnemiga : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorreEnemiga();
protected:
	UStaticMeshComponent* TorreMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void CrearEvento(const FString& Evento, class AFacadeGenerador* Facade);

	/*virtual void CambioEnergia();
	ACCESOSRES A LA ENERGIA DE LA TORRE
	void SetEnergiaTorre(int _energia) { energia = _energia; }*/

public:
	//metodos virtuales puros
	virtual void CrearTorreEnemiga(class AFacadeGenerador* Fachada) PURE_VIRTUAL(ATorreEnemiga::CrearTorreEnemiga, );
	virtual void AnadirMovimiento() PURE_VIRTUAL(ATorreEnemiga::AnadirMovimiento, );
	virtual void AnadirDisparo() PURE_VIRTUAL(ATorreEnemiga::AnadirDisparo, );

	virtual void RecibirEvento(const TArray<FString>& Evento, AFacadeGenerador* Facha);
};
