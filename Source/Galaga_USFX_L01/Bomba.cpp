// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	BombaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBomba"));
	BombaMesh->SetupAttachment(RootComponent);
	RootComponent = BombaMesh;

	velocidad = 4000;
}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	//PARA QUE ESTE DENTRO DE LA NAVE ENEMIGA CAZA
	SetActorRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	SetActorRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

	PosicionInicial = GetActorLocation();


}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABomba::TipoBomba(FString _bomba)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("TIPO DE BOMBA"));
	
}

void ABomba::RadioExplosion()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("radio explision"));
}

void ABomba::MovimientoBomba()
{
	FVector NewLocation = GetActorLocation() + -GetActorForwardVector() * velocidad * GetWorld()->GetDeltaSeconds();
	SetActorLocation(NewLocation);


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("movimiento bomba"));
}

void ABomba::DestruirBomba()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("destruir bomba"));
}

