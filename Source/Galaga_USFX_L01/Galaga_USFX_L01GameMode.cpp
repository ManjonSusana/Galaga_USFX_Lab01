#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "ComponenteMovimiento.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaBicho.h"
#include "NaveEnemigaAbeja.h"
#include "NaveEnemigaMariposa.h"
#include "NaveEnemigaAbejaVenenosa.h"
#include "NaveEnemigaAbejaComun.h"
#include "NaveEnemigaBichoAndante.h"
#include "NaveEnemigaBichoVolador.h"
#include "NaveEnemigaTransporteTerrestre.h"
#include "NaveEnemigaTransporteAereo.h"
#include "NaveEnemigaCazaFlechas.h"
#include "NaveEnemigaCazaDisparos.h"
#include "NaveEnemigaMariposaEspia.h" 
#include "NaveEnemigaMariposaAsesina.h"
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

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode() {

	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

	//NaveEnemiga01 = nullptr;

}
void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//tiempo de desaparicion de la nave Enemiga Caza
	TiempoTranscurrido++;
	
	
}

void AGalaga_USFX_L01GameMode::BeginPlay() {
	Super::BeginPlay();

	//creacion de las NAVEMEJORA a traves del builder
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
	//SPAWNEO DE LAS CAPSULAS EN EL GAMEMODE

	/*FVector ubicacionCapsulasMotor = FVector(1000.0f, 0.0f, 250.0f);
	* FVector ubicacionCapsulasArma = FVector(1000.0f, 0.0f, 250.0f);

	CapsulasMotor01 = GetWorld()->SpawnActor<ACapsulasMotor>(ubicacionCapsulasMotor, FRotator::ZeroRotator);
	CapsulasArma01 = GetWorld()->SpawnActor<ACapsulaArma>(ubicacionCapsulasArma, FRotator::ZeroRotator);

	*/
	//Set the game state to playing
	//INICIALIZAR EL TMAP
	//DIMENSIONES DE ARRAYS
	FVector ubicacionInicioNavesEnemigasCaza = FVector(200.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasTransporte = FVector(400.0f, -900.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasBicho = FVector(600.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasAbeja = FVector(800.0f, -900.0f, 250.f);
	FVector ubicacionInicioNavesEnemigasMariposa = FVector(1000.0f, -900.0f, 250.f);

	FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);

	const int32 NumeroDeColumnasCaza = 1; // N° COLUMNAS
	const int32 NumeroDeFilasCaza = 5;    //  N° FILAS

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 2; j++) {
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
		}
	}
}