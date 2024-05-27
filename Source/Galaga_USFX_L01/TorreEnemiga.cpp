// Fill out your copyright notice in the Description page of Project Settings.


#include "TorreEnemiga.h"

// Sets default values
ATorreEnemiga::ATorreEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TorreMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	TorreMesh->SetupAttachment(RootComponent);
	RootComponent = TorreMesh;


}

// Called when the game starts or when spawned
void ATorreEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATorreEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//Para ver que tipo de evento recibe
void ATorreEnemiga::CrearEvento(const FString& Evento, AFacadeGenerador* Facade)
{
	if (Evento.Equals("CrearTorreEnemiga"))
	{
		CrearTorreEnemiga(Facade);
	}
	else if (Evento.Equals("AnadirMovimiento"))
	{
		AnadirMovimiento();
	}
	else if (Evento.Equals("AnadirDisparo"))
	{
		AnadirDisparo();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("No hay evento"));
	}
}

void ATorreEnemiga::RecibirEvento(const TArray<FString>& Evento, AFacadeGenerador* Facha)
{
	for (const FString& MiEvento : Evento)
	{
		CrearEvento(MiEvento, Facha);
	}
}