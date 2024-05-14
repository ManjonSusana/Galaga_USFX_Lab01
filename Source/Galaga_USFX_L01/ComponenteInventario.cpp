// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteInventario.h"

// Sets default values for this component's properties
UComponenteInventario::UComponenteInventario()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
int32 UComponenteInventario::AgregarAlInventario(ACapsulaMotor* AgregarCapsula)
{
	return CurrentInventory.Add(AgregarCapsula);
}

int32 UComponenteInventario::AgregarAlInventarioArma(ACapsulaArma* AgregarCapsulaArma)
{
	return CurrentInventoryArma.Add(AgregarCapsulaArma);
}

int32 UComponenteInventario::AgregarAlInventarioVida(ACapsulaVida* AgregarCapsulaVida)
{
	return CurrentInventoryVida.Add(AgregarCapsulaVida);
}

void UComponenteInventario::RemoverDeInventario(ACapsulaMotor* RemoverCapsula)
{
	CurrentInventory.Remove(RemoverCapsula);
}

void UComponenteInventario::RemoverDeInventarioArma(ACapsulaArma* RemoverCapsulaArma)
{
	CurrentInventoryArma.Remove(RemoverCapsulaArma);
}

void UComponenteInventario::RemoverDeInventarioVida(ACapsulaVida* RemoverCapsulaVida)
{
	CurrentInventoryVida.Remove(RemoverCapsulaVida);
}

// Called when the game starts
void UComponenteInventario::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComponenteInventario::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

