// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeDisparos.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AFacadeDisparos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeDisparos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Array de municion 
	TArray<AActor*> municion;

	class ABomba* bomba;
	class ALaser* laser;
	class AFoton* foton;
	//facade adicionla
	class AFacadeAdRecargar* recargar;

public:
	void launch();  //LANZAR DISPARO
};
