// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaAbeja.h"

// Sets default values
ANaveEnemigaAbeja::ANaveEnemigaAbeja()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO4.TwinStickUFO4'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	PrimaryActorTick.bCanEverTick = true;
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

	// Inicializa los parámetros del salto
	JumpHeight = 10.0f;  // Ajusta este valor según la altura deseada
	JumpSpeed = 5.0f;     // Ajusta este valor según la velocidad deseada
	JumpTime = 5.0f;  // Inicializa el tiempo del salto

	TiempoCambio = 0.0f; //tiempo transcurrido

}

// Called when the game starts or when spawned
void ANaveEnemigaAbeja::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemigaAbeja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Mover(DeltaTime);
	//Saltar(DeltaTime);
	TiempoCambio ++;
	if (TiempoCambio >= 200.0f) {
		Saltar(DeltaTime);
	}
	else {
		Mover(DeltaTime);
	}
}


void ANaveEnemigaAbeja::Mover(float DeltaTime)
{
	velocidad = 5.0f;
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));
}

void ANaveEnemigaAbeja::Saltar(float DeltaTime)
{
	// Incrementa el tiempo del salto
	JumpTime += DeltaTime * JumpSpeed;

	// Calcula el desplazamiento en el eje Z usando una función sinusoidal
	float DeltaZ = FMath::Sin(JumpTime) * JumpHeight;

	// Obtén la posición actual de la nave
	FVector CurrentLocation = GetActorLocation();

	// Actualiza solo la componente Z de la posición
	CurrentLocation.Z += DeltaZ;

	// Establece la nueva ubicación de la nave
	SetActorLocation(CurrentLocation);

	// Resetea el tiempo del salto si es necesario para evitar valores muy grandes
	if (JumpTime >= 2 * PI)
	{
		JumpTime = 0.0f;
	}
}


