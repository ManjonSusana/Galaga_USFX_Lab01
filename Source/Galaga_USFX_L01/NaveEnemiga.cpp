// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//mallaNaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;
	velocidad = 1;

	// Inicializa el componente de movimiento de naves
	MovimientoNavesComponent = CreateDefaultSubobject<UComponenteMovimiento>(TEXT("MovimientoNavesComponent"));

	// Establece el componente de movimiento como tickeable
	MovimientoNavesComponent->PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// Llamar al m�todo de tick del componente de movimiento
	MovimientoNavesComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);

}


