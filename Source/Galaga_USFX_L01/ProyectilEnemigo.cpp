// Fill out your copyright notice in the Description page of Project Settings.
#include "ProyectilEnemigo.h"
#include "NaveEnemiga.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Galaga_USFX_L01Pawn.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"


AProyectilEnemigo::AProyectilEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	ProyectilEnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0")); //CREA EL MESH
	ProyectilEnemyMesh->SetStaticMesh(ProjectileMeshAsset.Object); //HACE REFERENCIA AL MESH
	ProyectilEnemyMesh->SetupAttachment(RootComponent);

	velocidad = 1000;
	dano = 1;
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

}

// Called when the game starts or when spawned
void AProyectilEnemigo::BeginPlay()
{
	Super::BeginPlay();
	SetTargePawn();
	
}

// Called every frame
void AProyectilEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover();
}
void AProyectilEnemigo::Mover()
{
	if (Pawn)
	{
		FVector Direction = (Pawn->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		FVector NewLocation = GetActorLocation() + Direction * velocidad * GetWorld()->GetDeltaSeconds();
		SetActorLocation(NewLocation);
	}
}

void AProyectilEnemigo::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AGalaga_USFX_L01Pawn* HiPawn = Cast<AGalaga_USFX_L01Pawn>(Other);

	if (HiPawn)
	{
		HiPawn->RecibirDano(dano); // Reduce la salud del Pawn
		Destroy();
	}

}

void AProyectilEnemigo::SetTargePawn()
{
	Pawn = Cast<AGalaga_USFX_L01Pawn>(UGameplayStatics::GetPlayerPawn(this, 0));

}

