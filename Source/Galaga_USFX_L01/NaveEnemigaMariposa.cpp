// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaMariposa.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ANaveEnemigaMariposa::ANaveEnemigaMariposa()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO2.TwinStickUFO2'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	PrimaryActorTick.bCanEverTick = true;
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));

	// Inicializa los parámetros de movimiento circular
	TiempoDeCambioDeEtapas = 10.0f;
	TiempoDePersecucion = 10.0f;
	TiempoEntrePersecuciones = 20.0f;
	bPersecucionActiva = false;

}

// Called when the game starts or when spawned
void ANaveEnemigaMariposa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemigaMariposa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANaveEnemigaMariposa::Mover(float DeltaTime)
{
	
}

void ANaveEnemigaMariposa::MoverEnCirculo(float DeltaTime)
{
	
}
void ANaveEnemigaMariposa::Atacar()
{
	
}

void ANaveEnemigaMariposa::SetPawnTarget(AGalaga_USFX_L01Pawn* NewPawn)
{
	
}

void ANaveEnemigaMariposa::PerseguirPawn(float DeltaTime)
{
	
}


