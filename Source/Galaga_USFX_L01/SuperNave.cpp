// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperNave.h"
#include "NaveMejora.h"


// Sets default values
ASuperNave::ASuperNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ASuperNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASuperNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//metodo para construir la nave mejora
void ASuperNave::builNaveMejoras(FVector ubicacionNaveMejoras)
{
	NaveMejora = GetWorld()->SpawnActor<ANaveMejora>(ANaveMejora::StaticClass(), ubicacionNaveMejoras, FRotator:: ZeroRotator);
	NaveMejora->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform); //para que la nave mejora se mueva con la nave principal


}

void ASuperNave::buildVidaNave()
{
	if (!NaveMejora) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejora->SetVidaNave("VidaNave");
}

void ASuperNave::buildMotorNave()
{
	if (!NaveMejora) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejora->SetMotorNave("MotorNave");
}

void ASuperNave::buildArmaNave()
{
	if (!NaveMejora) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejora->SetArmaNave("ArmaNave");
}

void ASuperNave::buildMallaNave()
{
	NaveMejora->MallaNave->SetStaticMesh(SuperNave);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("SuperNave"));
}

ANaveMejora* ASuperNave::getNaveMejora()
{
	return NaveMejora;
}