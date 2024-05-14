// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponenteMovimiento.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UComponenteMovimiento : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponenteMovimiento();

	UPROPERTY(EditAnywhere)
	float velocidad;
	UPROPERTY(EditAnywhere)
	float limiteIzquierda;
	UPROPERTY(EditAnywhere)
	float limiteDerecha;
	UPROPERTY(EditAnywhere)
	bool verificacion;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
