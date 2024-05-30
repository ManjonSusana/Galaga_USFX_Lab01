// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "ProyectilEnemigo.h"
#include "Publicador.h"
#include "EngineUtils.h"
#include "TorreEnemiga2.h"
#include "Kismet/GameplayStatics.h" 

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_2.TwinStickUFO_2'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

	bCanFire = false;//puede disparar

	TiempoTranscurrido = 0.0f; //tiempo transcurrido

	// Inicializar las variables de movimiento
	MoveSpeed = 100.0f;  // Velocidad de avance
	VerticalSpeed = 30.0f;  // Velocidad de movimiento vertical
	MaxVerticalOffset = 30.0f;  // Máximo desplazamiento vertical
	CurrentVerticalOffset = 1.0f;  // Desplazamiento vertical actual
	MovingUp = true;  // Dirección inicial del movimiento vertical


}

void ANaveEnemigaCaza::BeginPlay()
{
		Super::BeginPlay(); 
		//guaradr ka posicion
		PosicionInicial = GetActorLocation();
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Moverse) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("MOVIMIENTO DE LA NAVE CAZA"));
	// Obtener la ubicación actual del actor
		FVector CurrentLocation = GetActorLocation();

		// Verificar si se ha alcanzado el límite
		if (CurrentLocation.X <= -400.0f)
		{
			// Restablecer a la posición inicial
			SetActorLocation(PosicionInicial);
			CurrentVerticalOffset = 0.0f; // Restablecer el desplazamiento vertical
			MovingUp = true; // Restablecer la dirección del movimiento vertical
			return;
		}

		// Avanzar hacia adelante
		float ForwardMovement = MoveSpeed * DeltaTime;
		CurrentLocation.Y += ForwardMovement;

		// Movimiento vertical
		float VerticalMovement = VerticalSpeed * DeltaTime;
		if (MovingUp)
		{
			CurrentLocation.Z += VerticalMovement;
			CurrentVerticalOffset += VerticalMovement;

			// Cambiar la dirección si se alcanza el desplazamiento máximo
			if (CurrentVerticalOffset >= MaxVerticalOffset)
			{
				MovingUp = false;
			}
		}
		else
		{
			CurrentLocation.Z -= VerticalMovement;
			CurrentVerticalOffset -= VerticalMovement;

			// Cambiar la dirección si se alcanza el desplazamiento máximo
			if (CurrentVerticalOffset <= -MaxVerticalOffset)
			{
				MovingUp = true;
			}
		}
		// Establecer la nueva ubicación del actor
		SetActorLocation(CurrentLocation);
	}


	//Mover(DeltaTime);
	//ActualizarEnemigo();
}


void ANaveEnemigaCaza::ActualizarEnemigo()
{
	 
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("FORMACION DE NAVES CAZAA")));
	//Naves se mueven hacia la Torre
	FormacionNaves();
	//BUSCAR DEL MUNDO A LOS AcTORES TIPO PUBLICADOR Y LOS ALMACENA
	publicador = nullptr;
	for (TActorIterator<APublicador> It(GetWorld()); It; ++It)
	{
		publicador = *It;
		break;  // Asumiendo que solo hay una instancia de AEnemigasFacade en el nivel
	}

	publicador->desubscribirNaveEnemiga(this);

}

void ANaveEnemigaCaza::SetTorreEnemiga_2(APublicador* _publicador)
{
	publicador = _publicador;
	
	publicador->subscribirNaveEnemiga(this);
}

void ANaveEnemigaCaza::FormacionNaves()
{
	Moverse = true;
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{


}

void ANaveEnemigaCaza::Disparar()
{
	//disparos->launch();
}