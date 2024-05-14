// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaMariposa.h"
#include "NaveEnemigaMariposaAsesina.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaMariposaAsesina : public ANaveEnemigaMariposa
{
	GENERATED_BODY()

private:
	int amenaza;

public:
	ANaveEnemigaMariposaAsesina();
	
	FORCEINLINE int GetAmenaza() const { return amenaza; }
	FORCEINLINE void SetAmenaza(int _amenaza) { amenaza = _amenaza; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Atacar();
	virtual void Escapar();

	
};
