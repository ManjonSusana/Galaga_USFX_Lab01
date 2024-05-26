// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaBicho.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "ProyectilEnemigo.h"
#include "Kismet/GameplayStatics.h" 


// Sets default values
ANaveEnemigaBicho::ANaveEnemigaBicho()
{	
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO3.TwinStickUFO3'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	PrimaryActorTick.bCanEverTick = true;
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));

	bCanFire = false;//puede disparar

	TiempoTranscurrido = 0.0f; //tiempo transcurrido
	FireRate = 1.0f; // Un disparo por segundo
	FireCooldown = FireRate;

	EstadoActual = EstadoMovimiento::ArribaDerecha;

}

// Called when the game starts or when spawned
void ANaveEnemigaBicho::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // Guardar la posición inicial
	
}

void ANaveEnemigaBicho::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	Mover(DeltaTime);
	//Disparar();
	
	//
	TiempoTranscurrido++;
	if (TiempoTranscurrido > 300) {
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			FVector PosicionProyectilEnemigo = GetActorLocation() + FVector(0.0f, 0.0f, 0.0f); //posicion del proyectil enemigo
			World->SpawnActor <AProyectilEnemigo>(PosicionProyectilEnemigo, FRotator::ZeroRotator); //spawneo proyectil
	
		}
		TiempoTranscurrido = 0;
	
	}


	
}


void ANaveEnemigaBicho::Mover(float DeltaTime)
{
	velocidad = 100.0f; // ajustar la velocidad según sea necesario

	FVector UbicacionActual = GetActorLocation();
	FVector NuevaUbicacion = UbicacionActual;

	switch (EstadoActual)
	{
	case EstadoMovimiento::ArribaDerecha:
		NuevaUbicacion.X += velocidad * DeltaTime;
		NuevaUbicacion.Y += velocidad * DeltaTime;
		if (FMath::Abs(NuevaUbicacion.X - PosicionInicial.X) >= 500.0f || FMath::Abs(NuevaUbicacion.Y - PosicionInicial.Y) >= 500.0f)
		{
			EstadoActual = EstadoMovimiento::AbajoDerecha;
		}
		break;

	case EstadoMovimiento::AbajoDerecha:
		NuevaUbicacion.X += velocidad * DeltaTime;
		NuevaUbicacion.Y -= velocidad * DeltaTime;
		if (FMath::Abs(NuevaUbicacion.X - PosicionInicial.X) >= 1000.0f)
		{
			EstadoActual = EstadoMovimiento::AbajoIzquierda;
		}
		break;

	case EstadoMovimiento::AbajoIzquierda:
		NuevaUbicacion.X -= velocidad * DeltaTime;
		NuevaUbicacion.Y -= velocidad * DeltaTime;
		if (FMath::Abs(NuevaUbicacion.X - PosicionInicial.X) <= 500.0f)
		{
			EstadoActual = EstadoMovimiento::ArribaIzquierda;
		}
		break;

	case EstadoMovimiento::ArribaIzquierda:
		NuevaUbicacion.X -= velocidad * DeltaTime;
		NuevaUbicacion.Y += velocidad * DeltaTime;
		if (FMath::Abs(NuevaUbicacion.X - PosicionInicial.X) <= 0.0f && FMath::Abs(NuevaUbicacion.Y - PosicionInicial.Y) >= 500.0f)
		{
			EstadoActual = EstadoMovimiento::ArribaDerecha;
		}
		break;
	}

	SetActorLocation(NuevaUbicacion);
}

void ANaveEnemigaBicho::Disparar()
{
	//if (bCanFire)
	//{
	//	FireCooldown -= GetWorld()->GetDeltaSeconds();
	//	if (FireCooldown <= 0.0f)
	//	{
	//		// Obtener la ubicación de la nave
	//		FVector Location = GetActorLocation();
	//		FRotator Rotation = GetActorRotation();

	//		// Crear el proyectil
	//		GetWorld()->SpawnActor<AProyectilEnemigo>(Location, Rotation);

	//		// Resetear el temporizador de disparo
	//		FireCooldown = FireRate;
	//	}
	//}
	
}


//
//TiempoTranscurrido++;
//if (TiempoTranscurrido > 50) {
//	UWorld* const World = GetWorld();
//	if (World != nullptr)
//	{
//		FVector PosicionProyectilEnemigo = GetActorLocation() + FVector(0.0f, 0.0f, 0.0f); //posicion del proyectil enemigo
//		World->SpawnActor <AProyectilEnemigo>(PosicionProyectilEnemigo, FRotator::ZeroRotator); //spawneo proyectil
//
//	}
//	TiempoTranscurrido = 0;
//
//}