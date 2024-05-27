// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"
#include "CapsulaMotor.h"


ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO1.TwinStickUFO1'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	PrimaryActorTick.bCanEverTick = true;
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

	MoviendoseALaIzquierda = true;
}

void ANaveEnemigaTransporte::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // Guardar la posición inicial
}

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Botar();
}



void ANaveEnemigaTransporte::Mover(float DeltaTime)
{

	velocidad = 200.0f; // ajustar la velocidad según sea necesario

	FVector UbicacionActual = GetActorLocation();
	FVector NuevaUbicacion = UbicacionActual;

	if (MoviendoseALaIzquierda)
	{
		NuevaUbicacion.X -= velocidad * DeltaTime;
		NuevaUbicacion.Y += velocidad * DeltaTime; // Mover hacia adelante

		if (NuevaUbicacion.X <= -500.0f)
		{
			// Si alcanza -500 en el eje X, volver a la posición inicial
			NuevaUbicacion = PosicionInicial;
			MoviendoseALaIzquierda = true; // Resetear el movimiento hacia la izquierda
		}
	}

	SetActorLocation(NuevaUbicacion);
}

void ANaveEnemigaTransporte::Botar()
{
	
}
