// Fill out your copyright notice in the Description page of Project Settings.


#include "MotorNave.h"
#include "NaveMejora.h"

// Sets default values
AMotorNave::AMotorNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMotorNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotorNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//Funcion para construir la nave
void AMotorNave::builNaveMejoras(FVector ubicacionNaveMejoras)
{	
	NaveMejora = GetWorld()->SpawnActor<ANaveMejora>(ANaveMejora::StaticClass(), ubicacionNaveMejoras, FRotator::ZeroRotator);
	NaveMejora->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AMotorNave::buildVidaNave()
{
	/*if (!NaveMejoras) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejoras->SetVidaNave("VidaNave");*/
}

void AMotorNave::buildMotorNave()
{
	if (!NaveMejora) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejora->SetMotorNave("MotorNave");
}

void AMotorNave::buildArmaNave()
{
	/*if (!NaveMejoras) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejoras->SetArmaNave("ArmaNave");*/
}

void AMotorNave::buildMallaNave()
{
	NaveMejora->MallaNave->SetStaticMesh(MotorNave);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Motor"));
}

ANaveMejora* AMotorNave::getNaveMejora()
{
	return NaveMejora;
}



