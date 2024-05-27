// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaMariposa.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveEnemigaMariposa::ANaveEnemigaMariposa()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO2.TwinStickUFO2'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	PrimaryActorTick.bCanEverTick = true;
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));


	TiempoDeCambioDeEtapas = 10.0f;  // Cambiado a 5 segundos para el ciclo de movimiento
	bPersecucionActiva = false;
	bRegresando = false;

	PosicionInicial = FVector::ZeroVector;
	PawnTarget = nullptr;

	MoveSpeed = 10.0f;

}

// Called when the game starts or when spawned
void ANaveEnemigaMariposa::BeginPlay()
{
	Super::BeginPlay();

	// Inicializamos la posici�n inicial
	PosicionInicial = GetActorLocation();

	// Configura el TargetPawn aqu� o mediante otra l�gica de detecci�n
	SetPawnTarget(Cast<AGalaga_USFX_L01Pawn>(UGameplayStatics::GetPlayerPawn(this, 0)));

	// Configurar el temporizador para activar la persecuci�n despu�s de 5 segundos de inicio
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Persecucion, this, &ANaveEnemigaMariposa::ActivarPersecucion, 5.0f, false);
	
}

// Called every frame
void ANaveEnemigaMariposa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPersecucionActiva && PawnTarget)
	{
		PerseguirPawn(DeltaTime);
	}
	else if (bRegresando)
	{
		RegresarAInicio(DeltaTime);
	}
	else
	{
		Mover(DeltaTime);
	}

}

void ANaveEnemigaMariposa::Mover(float DeltaTime)
{
	// Movimiento circular por defecto
	MoverEnCirculo(DeltaTime);
}

void ANaveEnemigaMariposa::MoverEnCirculo(float DeltaTime)
{
	static float TiempoAcumulado = 0.0f;
	TiempoAcumulado += DeltaTime;
	float Radio = 500.0f;
	float VelocidadAngular = MoveSpeed / 100.0f; // Velocidad de rotaci�n (radianes por segundo)

	FVector NuevaPosicion = PosicionInicial + FVector(FMath::Cos(TiempoAcumulado * VelocidadAngular) * Radio, FMath::Sin(TiempoAcumulado * VelocidadAngular) * Radio, 0.0f);
	SetActorLocation(NuevaPosicion);
}
void ANaveEnemigaMariposa::Atacar()
{
	if (PawnTarget)
	{
		bPersecucionActiva = true;
	}
	
}

void ANaveEnemigaMariposa::SetPawnTarget(AGalaga_USFX_L01Pawn* NewPawn)
{
	PawnTarget = NewPawn;
}

void ANaveEnemigaMariposa::ActivarPersecucion()
{
	bPersecucionActiva = true;

	// Configurar el temporizador para activar el regreso despu�s de 5 segundos de persecuci�n
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Regreso, this, &ANaveEnemigaMariposa::ActivarRegreso, TiempoDeCambioDeEtapas, false);

}

void ANaveEnemigaMariposa::ActivarRegreso()
{
	bPersecucionActiva = false;
	bRegresando = true;
}

void ANaveEnemigaMariposa::ReanudarMovimientoCircular()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_CambioDeEtapas, this, &ANaveEnemigaMariposa::ActivarPersecucion, TiempoDeCambioDeEtapas, false);
}

void ANaveEnemigaMariposa::PerseguirPawn(float DeltaTime)
{
	if (PawnTarget)
	{
		FVector Direction = (PawnTarget->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		FVector NewLocation = GetActorLocation() + Direction * MoveSpeed * DeltaTime;
		SetActorLocation(NewLocation);
	}
}

void ANaveEnemigaMariposa::RegresarAInicio(float DeltaTime)
{
	FVector Direction = (PosicionInicial - GetActorLocation()).GetSafeNormal();
	FVector NewLocation = GetActorLocation() + Direction * MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);

	if (FVector::Dist(GetActorLocation(), PosicionInicial) < 10.0f)  // Si est� lo suficientemente cerca de la posici�n inicial
	{
		bRegresando = false;
		ReanudarMovimientoCircular();
	}
}


