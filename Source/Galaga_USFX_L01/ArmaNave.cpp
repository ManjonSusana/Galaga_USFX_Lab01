// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmaNave.h"
#include "NaveMejora.h"

// Sets default values
AArmaNave::AArmaNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetActorRelativeScale3D();
	SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));

}

// Called when the game starts or when spawned
void AArmaNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmaNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AArmaNave::builNaveMejoras(FVector ubicacionNaveMejoras)
{
	NaveMejora = GetWorld()->SpawnActor<ANaveMejora>(ANaveMejora::StaticClass(), ubicacionNaveMejoras, FRotator:: ZeroRotator);
	NaveMejora->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AArmaNave::buildVidaNave()
{
	/*if (!NaveMejoras) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejoras->SetVidaNave("VidaNave");*/
}

void AArmaNave::buildMotorNave()
{
	/*if (!NaveMejoras) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejoras->SetMotorNave("MotorNave");*/
}

void AArmaNave::buildArmaNave()
{
	if (!NaveMejora) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	NaveMejora->SetArmaNave("ArmaNave");
}

void AArmaNave::buildMallaNave()
{
	NaveMejora->MallaNave->SetStaticMesh(ArmaNave);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Arma"));
}

ANaveMejora* AArmaNave::getNaveMejora()
{
	return NaveMejora;
}



