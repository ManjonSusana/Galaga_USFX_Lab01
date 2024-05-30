// Fill out your copyright notice in the Description page of Project Settings.


#include "TorreEnemiga2.h"
#include "FacadeGenerador.h"
#include "Galaga_USFX_L01Projectile.h"
#include "ProyectilEnemigo.h"

ATorreEnemiga2::ATorreEnemiga2()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube1.Shape_Tube1'"));
	TorreMesh->SetStaticMesh(ShipMesh.Object);

	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

	//ubicacion inicial
	PosicionInicialTorre_2 = FVector(1000.0f, 1600.0f, 250.f);

	//tiempoTranscurrido = 0;
	velocidadTorre = 200.0f;
	Direccion = 1.0f; // Comienza moviéndose hacia la derecha
	LimiteInferior = -1600.0f;
	LimiteSuperior = 0.0f;

}

void ATorreEnemiga2::BeginPlay()
{
	Super::BeginPlay();
}

void ATorreEnemiga2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tiempoTranscurrido++;
	if (tiempoTranscurrido >= 100.0f ) {
		
		energia --;
		if(energia==50)
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("LA ENERGIA DE LA TORRE ES DE: %d"), energia));


	} 

	//if (verificacionMovimiento)
	//{
	//	// Lógica de movimiento
	//	FVector CurrentLocation = GetActorLocation();
	//	CurrentLocation.X += Direccion * velocidadTorre * DeltaTime;

	//	// Verificar límites y cambiar dirección si es necesario
	//	if (CurrentLocation.X >= LimiteSuperior || CurrentLocation.X <= LimiteInferior)
	//	{
	//		Direccion *= -1;
	//	}

	//	SetActorLocation(CurrentLocation);


	//	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("LA TORRE SE MUEVEEE")));


	//}
	//AnadirDisparo();

	
}

void ATorreEnemiga2::CrearTorreEnemiga(AFacadeGenerador* Fachada)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("se creo la Torre_2")));
	//creanod la Torre1
	FVector SpawnLocation = FVector(FMath::RandRange(-1000.0f, 500.0f), FMath::RandRange(-1200.0f, -1000.0f), 215.0f);
	ATorreEnemiga2* Torre_2 = GetWorld()->SpawnActor<ATorreEnemiga2>(PosicionInicialTorre_2, FRotator::ZeroRotator);

	AFacadeGenerador* Facade = Cast<AFacadeGenerador>(Fachada);
	Facade->Edificios.Add(Torre_2);;
}

//void ATorreEnemiga2::AnadirMovimiento()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT(" Movimienot Torres")));
//	verificacionMovimiento = true;
//}
//	
//void ATorreEnemiga2::AnadirDisparo()
//{
//	tiempoTranscurrido++;
//	if (tiempoTranscurrido >= 495.0f && tiempoTranscurrido <= 500.0f) {
//
//
//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("LA TORRE DISOARRA")));
//
//		verificacionDisparo = true;
//		if (verificacionDisparo)
//		{
//			//DISPAROS.
//			UWorld* const World = GetWorld();
//			if (World != nullptr)
//			{
//				FVector PosicionProyectilEnemigo = GetActorLocation() + FVector(0.0f, 0.0f, 0.0f); // posición del proyectil enemigo
//				World->SpawnActor<AProyectilEnemigo>(PosicionProyectilEnemigo, FRotator::ZeroRotator); // spawneo proyectil
//			}
//
//
//		}
//
//		//tiempoTranscurrido = 0.0f;
//	}
//
//
//}
