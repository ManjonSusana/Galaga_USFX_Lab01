// Fill out your copyright notice in the Description page of Project Settings.


#include "DircetorNave.h"
#include "NaveMejora.h"
// Sets default values
ADircetorNave::ADircetorNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADircetorNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADircetorNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADircetorNave::ConstruirNaveMejoras(FVector ubiNaveMejoras)
{
	if (!NaveBuilder) { UE_LOG(LogTemp, Error, TEXT("ConstructLodging(): LodgingBuilder is NULL, make sure it's initialized.")); return; }

	NaveBuilder->builNaveMejoras(ubiNaveMejoras);
	NaveBuilder->buildVidaNave();
	NaveBuilder->buildMotorNave();
	NaveBuilder->buildArmaNave();
	NaveBuilder->buildMallaNave();
}

void ADircetorNave::SetNavesBuilder(AActor* Builder)
{
	NaveBuilder = Cast<INaveBuilder>(Builder);
	if (!NaveBuilder) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetLodgingBuilder(): The Actor isnot a LodgingBuilder!Are you sure that the Actor implements that interface ? "));
	}
}

ANaveMejora* ADircetorNave::getNaveMejora()
{
		if (NaveBuilder)
		{
			return NaveBuilder->getNaveMejora();
		}
		UE_LOG(LogTemp, Error, TEXT("GetLodging(): Return nullptr"));

	return nullptr;
}

