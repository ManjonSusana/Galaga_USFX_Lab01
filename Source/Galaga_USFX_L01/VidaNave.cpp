// Fill out your copyright notice in the Description page of Project Settings.


#include "VidaNave.h"
#include "NaveMejora.h"

// Sets default values
AVidaNave::AVidaNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetActorRelativeScale3D();
	SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));

}

// Called when the game starts or when spawned
void AVidaNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVidaNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AVidaNave::builNaveMejoras(FVector ubicacionNaveMejoras)
{
	NaveMejora = GetWorld()->SpawnActor<ANaveMejora>(ANaveMejora::StaticClass(), ubicacionNaveMejoras, FRotator::ZeroRotator);
	NaveMejora->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}


void AVidaNave::buildVidaNave()
{
	if (!NaveMejora) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejora->SetVidaNave("VidaNave");// SOLO LA CREACION DE LA VIDA DE LA NAVE
}

void AVidaNave::buildMotorNave()
{
	/*if (!NaveMejoras) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejoras->SetMotorNave("MotorNave");*/
}

void AVidaNave::buildArmaNave()
{
	/*if (!NaveMejoras) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejoras->SetArmaNave("ArmaNave");*/

}

void AVidaNave::buildMallaNave()
{
	NaveMejora->MallaNave->SetStaticMesh(VidaNave);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("VidaNave"));
}

ANaveMejora* AVidaNave::getNaveMejora()
{
	return NaveMejora;
}



