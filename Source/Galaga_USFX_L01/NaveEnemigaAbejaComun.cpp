// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaAbejaComun.h"

ANaveEnemigaAbejaComun::ANaveEnemigaAbejaComun()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaAbejaComun::BeginPlay()
{
	Super::BeginPlay();

}

void ANaveEnemigaAbejaComun::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);
}


void ANaveEnemigaAbejaComun::Mover(float DeltaTime)
{
}

void ANaveEnemigaAbejaComun::Disparar()
{
}

void ANaveEnemigaAbejaComun::Atacar()
{
}

void ANaveEnemigaAbejaComun::Escapar()
{
}
