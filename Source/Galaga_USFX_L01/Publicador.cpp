// Fill out your copyright notice in the Description page of Project Settings.


#include "Publicador.h"
#include "SubscriptorEnemigo.h"
#include "TorreEnemiga2.h"
#include "EngineUtils.h"

// Sets default values
APublicador::APublicador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APublicador::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ATorreEnemiga2> It(GetWorld()); It; ++It)
	{
		TorreEnemiga = *It;
		break;  // Asumiendo que solo hay una instancia de AEnemigasFacade en el nivel
	}
	

}

// Called every frame
void APublicador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TorreEnemiga->GetEnergiaTorre() <= 50) {
		Notificar();
	}

}

void APublicador::subscribirNaveEnemiga(AActor* _subscribriNave)
{
	SubscriptorEnemigas.Add(_subscribriNave);
}

void APublicador::desubscribirNaveEnemiga(AActor* _desubcribirNave)
{
	SubscriptorEnemigas.Remove(_desubcribirNave);
}

void APublicador::Notificar()
{
	for (AActor* Enemiga : SubscriptorEnemigas)
	{
		ISubscriptorEnemigo* Subscriptora = Cast<ISubscriptorEnemigo>(Enemiga);
		if (Subscriptora)
		{
			Subscriptora->ActualizarEnemigo();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Fallo al castear a ISubscriptorEnemigo: %s"), *Enemiga->GetName());
		}
	}
}




