#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "ComponenteMovimiento.h"
#include "FacadeGenerador.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode() {

	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

}
void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGalaga_USFX_L01GameMode::BeginPlay() {
	Super::BeginPlay();

	Facade= GetWorld()->SpawnActor<AFacadeGenerador>(AFacadeGenerador::StaticClass());
	//solo Fabrica de de las naves Enemiags
	Facade-> FabricarNaves();
	Facade->FaabricarBuider();
	Facade->FabricarNavesAtaque();
	Facade->FabricarNavesDisparo();
	//solo de las torres enemigas
	Facade-> TorresEnemigas();

}