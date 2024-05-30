// Fill out your copyright notice in the Description page of Project Settings.


#include "TorreEnemiga1.h"
#include "FacadeGenerador.h"
#include "Galaga_USFX_L01Projectile.h"
#include "ProyectilEnemigo.h"

ATorreEnemiga1::ATorreEnemiga1()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	TorreMesh->SetStaticMesh(ShipMesh.Object);

	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.5f, 1.5f, 1.05f));
	
	//ubicacion inicial
	PosicionInicialTorre_1 = FVector(-800.0f, 1600.0f, 250.f);

	tiempoTranscurrido = 0.0f;
	
	// Inicializar variables de movimiento
	velocidadTorre = 200.0f;
	Direccion = 1.0f; // Comienza moviéndose hacia la derecha
	LimiteDerecha = 1600.0f;
	LimiteIzquierda = 100.0f;

}

void ATorreEnemiga1::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATorreEnemiga1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	if (verificacionMovimiento)
	{
		// Lógica de movimiento
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.Y += Direccion * velocidadTorre * DeltaTime;

		// Verificar límites y cambiar dirección si es necesario
		if (CurrentLocation.Y >= LimiteDerecha || CurrentLocation.Y <= LimiteIzquierda)
		{
			Direccion *= -1;
		}

		SetActorLocation(CurrentLocation);

		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("LA TORRE SE MUEVEEE")));
		

		
	}
	AnadirDisparo();
	
}

void ATorreEnemiga1::CrearTorreEnemiga(AFacadeGenerador* Fachada)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("se creo la Torre_1")));
	//creanod la Torre1
	FVector SpawnLocation = FVector(FMath::RandRange(-1000.0f, 500.0f), FMath::RandRange(-1200.0f, -1000.0f), 215.0f);
	ATorreEnemiga1* Torre_1 = GetWorld()->SpawnActor<ATorreEnemiga1>(PosicionInicialTorre_1, FRotator::ZeroRotator);
	AFacadeGenerador* Facade = Cast<AFacadeGenerador>(Fachada);
	Facade->Edificios.Add(Torre_1);
}	



void ATorreEnemiga1::AnadirMovimiento()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT(" Movimienot Torres")));
	verificacionMovimiento = true;
}

void ATorreEnemiga1::AnadirDisparo()
{
	
	tiempoTranscurrido++;
	if (tiempoTranscurrido>= 490.0f && tiempoTranscurrido<=500.0f) {


		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("LA TORRE DISOARRA")));

		verificacionDisparo = true;
		if (verificacionDisparo)
		{
			//DISPAROS.
			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				FVector PosicionProyectilEnemigo = GetActorLocation() + FVector(0.0f, 0.0f, 0.0f); // posición del proyectil enemigo
				World->SpawnActor<AProyectilEnemigo>(PosicionProyectilEnemigo, FRotator::ZeroRotator); // spawneo proyectil
			}
			

		}
		
		//tiempoTranscurrido = 0.0f;
	}
	

}

