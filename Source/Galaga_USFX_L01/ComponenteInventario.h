// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CapsulaMotor.h"
#include "CapsulaArma.h"
#include "CapsulaVida.h"
#include "ComponenteInventario.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UComponenteInventario : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponenteInventario();

	UPROPERTY()
	TArray<ACapsulaMotor*> CurrentInventory;
	UPROPERTY()
	TArray<ACapsulaArma*> CurrentInventoryArma;
	UPROPERTY()
	TArray<ACapsulaVida*> CurrentInventoryVida;


	UFUNCTION()
	int32 AgregarAlInventario(ACapsulaMotor* AgregarCapsula);
	UFUNCTION()
	int32 AgregarAlInventarioArma(ACapsulaArma* AgregarCapsulaArma);
	UFUNCTION()
	int32 AgregarAlInventarioVida(ACapsulaVida* AgregarCapsulaVida);

	UFUNCTION()
	void RemoverDeInventario(ACapsulaMotor* RemoverCapsula);
	UFUNCTION()
	void RemoverDeInventarioArma(ACapsulaArma* RemoverCapsulaArma);
	UFUNCTION()
	void RemoverDeInventarioVida(ACapsulaVida* RemoverCapsulaVida);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
