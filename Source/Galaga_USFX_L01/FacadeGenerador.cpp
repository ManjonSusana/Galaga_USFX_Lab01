// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeGenerador.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCazaFactory.h"
#include "NaveEnemigaTransporteFactory.h"
#include "NaveEnemigaBichoFactory.h"
#include "NaveEnemigaAbejaFactory.h"
#include "NaveEnemigaMariposaFactory.h"
#include "VidaNave.h"
#include "DircetorNave.h"
#include "NaveMejora.h"
#include "SuperNave.h"
#include "MotorNave.h"
#include "ArmaNave.h"
#include "CapsulaMotor.h"
#include "CapsulaArma.h"
#include "CapsulaVida.h"

// Sets default values
AFacadeGenerador::AFacadeGenerador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacadeGenerador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacadeGenerador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFacadeGenerador::FabricarNaves()
{
	// spawneo naves enemigas
	FVector ubicacionInicioNavesEnemigasCaza = FVector(200.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasTransporte = FVector(400.0f, -900.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasBicho = FVector(600.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasAbeja = FVector(800.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasMariposa = FVector(1000.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasAbejaComun = FVector(200.0f, -900.0f, 250.f);

	FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);

	//const int32 NumeroDeColumnasCaza = 1; // N� COLUMNAS
	//const int32 NumeroDeFilasCaza = 5;    //  N� FILAS

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 1; j++) {
				FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasTransporte.X + j * 200, ubicacionInicioNavesEnemigasTransporte.Y + i * 200, ubicacionInicioNavesEnemigasTransporte.Z);
				ANaveEnemiga* NuevaNaveCaza = ANaveEnemigaCazaFactory::CrearNave("Caza", World, PosicionNaveActual, FRotator::ZeroRotator);
			}
			float nuevaposicionTransporte = ubicacionInicioNavesEnemigasTransporte.X + 300.0f;
			for (int j = 0; j < 6; j++) {

				FVector PosicionNaveActual = FVector(nuevaposicionTransporte, ubicacionInicioNavesEnemigasTransporte.Y + j * 200, ubicacionInicioNavesEnemigasTransporte.Z);
				ANaveEnemiga* NuevaNaveTransporte = ANaveEnemigaTransporteFactory::CrearNave("Transporte", World, PosicionNaveActual, FRotator::ZeroRotator);

			}
			float nuevaposicionBicho = ubicacionInicioNavesEnemigasBicho.X + 300.0f;
			for (int j = 0; j < 6; j++) {

				FVector PosicionNaveActual = FVector(nuevaposicionBicho, ubicacionInicioNavesEnemigasBicho.Y + j * 200, ubicacionInicioNavesEnemigasBicho.Z);
				ANaveEnemiga* NuevaNaveBicho = ANaveEnemigaBichoFactory::CrearNave("Bicho", World, PosicionNaveActual, FRotator::ZeroRotator);


			}
			float nuevaposicionAbeja = ubicacionInicioNavesEnemigasAbeja.X + 300.0f;
			for (int j = 0; j < 6; j++) {

				FVector PosicionNaveActual = FVector(nuevaposicionAbeja, ubicacionInicioNavesEnemigasAbeja.Y + j * 200, ubicacionInicioNavesEnemigasAbeja.Z);
				ANaveEnemiga* NuevaNaveAbeja = ANaveEnemigaAbejaFactory::CrearNave("Abeja", World, PosicionNaveActual, FRotator::ZeroRotator);
			}

			float nuevaposicionMariposa = ubicacionInicioNavesEnemigasMariposa.X + 300.0f;
			for (int j = 0; j < 6; j++) {

				FVector PosicionNaveActual = FVector(nuevaposicionMariposa, ubicacionInicioNavesEnemigasMariposa.Y + j * 200, ubicacionInicioNavesEnemigasMariposa.Z);
				ANaveEnemiga* NuevaNaveMariposa = ANaveEnemigaMariposaFactory::CrearNave("Mariposa", World, PosicionNaveActual, FRotator::ZeroRotator);


			}
			float nuevaposicionAbejaComun = ubicacionInicioNavesEnemigasAbejaComun.X + 300.0f;
			for (int j = 0; j < 6; j++) {

				FVector PosicionNaveActual = FVector(nuevaposicionAbejaComun, ubicacionInicioNavesEnemigasAbejaComun.Y + j * 200, ubicacionInicioNavesEnemigasAbejaComun.Z);
				ANaveEnemiga* NuevaNaveAbejaComun = ANaveEnemigaAbejaFactory::CrearNave("AbejaComun", World, PosicionNaveActual, FRotator::ZeroRotator);
			}
		}
	}
}

void AFacadeGenerador::FaabricarBuider()
{
	DirectorNave01 = GetWorld()->SpawnActor<ADircetorNave>(ADircetorNave::StaticClass());  //staticclass es para que sepa que clase es y lo cree--bisca en todoas las clases de unreal para llegar a spawnear

	SuperNave01 = GetWorld()->SpawnActor<ASuperNave>(ASuperNave::StaticClass());
	DirectorNave01->SetNavesBuilder(SuperNave01);
	DirectorNave01->ConstruirNaveMejoras(FVector(-500.0f, 500.0f, 250.0f));



	VidaNave01 = GetWorld()->SpawnActor<AVidaNave>(AVidaNave::StaticClass());
	DirectorNave01->SetNavesBuilder(VidaNave01);
	DirectorNave01->ConstruirNaveMejoras(FVector(-1000.0f, 500.0f, 250.0f));

	MotorNave01 = GetWorld()->SpawnActor<AMotorNave>(AMotorNave::StaticClass());
	DirectorNave01->SetNavesBuilder(MotorNave01);
	DirectorNave01->ConstruirNaveMejoras(FVector(-1200.0f, 500.0f, 250.0f));

	ArmaNave01 = GetWorld()->SpawnActor<AArmaNave>(AArmaNave::StaticClass());
	DirectorNave01->SetNavesBuilder(ArmaNave01);
	DirectorNave01->ConstruirNaveMejoras(FVector(-1400.0f, 500.0f, 250.0f));


	ANaveMejora* NaveMejora = DirectorNave01->getNaveMejora();
	NaveMejora->CaracteristicasNave();

}

void AFacadeGenerador::FabricarNavesAtaque()
{
}

void AFacadeGenerador::FabricarNavesDisparo()
{
}

