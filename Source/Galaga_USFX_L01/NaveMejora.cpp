// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveMejora.h"
#include "CapsulaMotor.h"
#include "CapsulaArma.h"
#include "CapsulaVida.h"

// Sets default values
ANaveMejora::ANaveMejora()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaNave = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaNave"));
	MallaNave->SetupAttachment(RootComponent);
	RootComponent = MallaNave;

	// Inicializa el componente de movimiento de naves
	MovimientoNavesComponent = CreateDefaultSubobject<UComponenteMovimiento>(TEXT("MovimientoNavesComponent"));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MovimientoNavesupper"));

}

// Called when the game starts or when spawned
void ANaveMejora::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ANaveMejora::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//spawn de cápsulas en la nave mejora cada 5 segundos
	TiempoTranscurrido++;

	if (TiempoTranscurrido >= 500)
	{
		if (Verificacion) {

			CapsulaMotor01 = GetWorld()->SpawnActor<ACapsulaMotor>(GetActorLocation() + FVector(100.0f, 50.0f, 0.0f), FRotator::ZeroRotator);

			// Iniciar el temporizador para destruir la cápsula después de 5 segundos
			GetWorld()->GetTimerManager().SetTimer(DestruirCapsulaTimerHandle, this, &ANaveMejora::DestruirCapsulaMotor, 5.0f, false);

		}

		if (VerificacionArma) {

			CapsulaArma01 = GetWorld()->SpawnActor<ACapsulaArma>(GetActorLocation() + FVector(150.0f, 100.0f, 0.0f), FRotator::ZeroRotator);

			//Iniciar el temporizador para destruir la cápsula después de 5 segundos
			GetWorld()->GetTimerManager().SetTimer(DestruirCapsulaTimerHandle, this, &ANaveMejora::DestruirCapsulaArma, 5.0f, false);

		}
		if (VerificacionVida) {


			CapsulaVida01 = GetWorld()->SpawnActor<ACapsulaVida>(GetActorLocation() + FVector(0.0f, 150.0f, 0.0f), FRotator::ZeroRotator);

			//iniciar el temporizador para destruir la cápsula después de 5 segundos
			GetWorld()->GetTimerManager().SetTimer(DestruirCapsulaTimerHandle, this, &ANaveMejora::DestruirCapsulaVida, 5.0f, false);

		}
		TiempoTranscurrido = 0;
	}
	
}

void ANaveMejora::SetVidaNave(FString NewVidaNave)
{
	VidaNave = NewVidaNave;

	VerificacionVida = true;
}

void ANaveMejora::SetMotorNave(FString NewVelocidadNave)
{
	VelocidadNave = NewVelocidadNave;

	Verificacion = true;


}

void ANaveMejora::SetArmaNave(FString NewArmaNave)
{
	ArmaNave = NewArmaNave;


	VerificacionArma = true;
}

void ANaveMejora::SetMalla(UStaticMeshComponent* NewMallaNave)
{
	MallaNave = NewMallaNave;

	Verificacion= true;
}

void ANaveMejora::DestruirCapsulaMotor()
{
	if (CapsulaMotor01 != nullptr)
	{
		CapsulaMotor01->Destroy();
		CapsulaMotor01 = nullptr;
	}
}

void ANaveMejora::DestruirCapsulaArma()
{
	if (CapsulaArma01 != nullptr)
	{
		CapsulaArma01->Destroy();
		CapsulaArma01 = nullptr;
	}
}

void ANaveMejora::DestruirCapsulaVida()
{
	if (CapsulaVida01 != nullptr)
	{
		CapsulaVida01->Destroy();
		CapsulaVida01 = nullptr;
	}
}

void ANaveMejora::CaracteristicasNave()
{
	UE_LOG(LogTemp, Warning, TEXT("Vida de la nave: %s"), *VidaNave);
	UE_LOG(LogTemp, Warning, TEXT("Velocidad de la nave: %s"), *VelocidadNave);
	UE_LOG(LogTemp, Warning, TEXT("Arma de la nave: %s"), *ArmaNave);
}


