// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01Pawn.h"
#include "Galaga_USFX_L01Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Barrera.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/EngineTypes.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AGalaga_USFX_L01Pawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFX_L01Pawn::MoveRightBinding("MoveRight");
const FName AGalaga_USFX_L01Pawn::FireForwardBinding("FireForward");
const FName AGalaga_USFX_L01Pawn::FireRightBinding("FireRight");

AGalaga_USFX_L01Pawn::AGalaga_USFX_L01Pawn()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f); 
	GunOffset2 = FVector(90.f, 90.f, 0.f);
	FireRate = 0.1f; //es el tiempo de disparo
	bCanFire = true;

	//salud
	Vidas = 10.0f;


	MiInventario = CreateDefaultSubobject<UComponenteInventario>("MiInventario");
	MiInventarioArma = CreateDefaultSubobject<UComponenteInventario>("MiInventarioArma");
	MiInventarioVida = CreateDefaultSubobject<UComponenteInventario>("MiInventarioVida");
}

void AGalaga_USFX_L01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);


	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);

	//CON LA TECLA INICIAR LA BARRERA
	FInputActionKeyMapping crearBarrera("crearBarrera", EKeys::K, 0, 0, 0, 0);
	UPlayerInput::AddEngineDefinedActionMapping(crearBarrera);

	PlayerInputComponent->BindAction("crearBarrera", IE_Pressed, this, &AGalaga_USFX_L01Pawn::crearBarrera);


	//Asignar la funcion Regresar
	FInputActionKeyMapping Regresar("Regresar", EKeys::B, 0, 0, 0, 0);
	UPlayerInput::AddEngineDefinedActionMapping(Regresar);

	PlayerInputComponent->BindAction("regresar", IE_Pressed, this, &AGalaga_USFX_L01Pawn::Regresar);


}
void AGalaga_USFX_L01Pawn::crearBarrera()
{
	FVector Location = GetActorLocation() + FVector(250.0f, 0.0f, -75.0f);
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);

	//Creamos la barrera en la posicion del componente
	UComponenteBarrera* crearBarrera = GetWorld()->SpawnActor<UComponenteBarrera>(UComponenteBarrera::StaticClass(), Location, Rotation);
	if (crearBarrera != nullptr) {
		crearBarrera->SetWorldLocation(Location);
		crearBarrera->SetWorldRotation(Rotation);
	}
	ABarrera* crearBarreraSpawn = GetWorld()->SpawnActor<ABarrera>(ABarrera::StaticClass(), Location, Rotation);
	if (crearBarreraSpawn != nullptr) {
		crearBarreraSpawn->SetActorLocation(Location);
		crearBarreraSpawn->SetActorRotation(Rotation);


	}
}

void AGalaga_USFX_L01Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;


	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AGalaga_USFX_L01Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L01Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalaga_USFX_L01Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AGalaga_USFX_L01Pawn::RecibirDano(int dano)
{
	Vidas -= dano;
	UE_LOG(LogTemp, Warning, TEXT("Vidas restantes: %d"), Vidas); // Depuraci�n

	if (Vidas <= 0)
	{
		Destroy();
	}
}

void AGalaga_USFX_L01Pawn::DropItem()
{
	if (MiInventario->CurrentInventory.Num() == 0)
	{
		return;
	}
	ACapsulaMotor* Item = MiInventario->CurrentInventory.Last();
	MiInventario->RemoverDeInventario(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AGalaga_USFX_L01Pawn::DropItemArma()
{
	if (MiInventarioArma->CurrentInventoryArma.Num() == 0)
	{
		return;
	}
	ACapsulaArma* Item = MiInventarioArma->CurrentInventoryArma.Last();
	MiInventarioArma->RemoverDeInventarioArma(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AGalaga_USFX_L01Pawn::DropItemVida()
{
	if (MiInventarioVida->CurrentInventoryVida.Num() == 0)
	{
		return;
	}
	ACapsulaVida* Item = MiInventarioVida->CurrentInventoryVida.Last();
	MiInventarioVida->RemoverDeInventarioVida(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AGalaga_USFX_L01Pawn::TakeItem(ACapsulaMotor* InventarioItem)
{
	InventarioItem->PickUp();
	MiInventario->AgregarAlInventario(InventarioItem);
	MoveSpeed = MoveSpeed * 2.0f;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Velocidad maxima"));
	//Velocidad Normal
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L01Pawn::VelocidadNormal, 5.0);

	
}

void AGalaga_USFX_L01Pawn::TakeItemArma(ACapsulaArma* InventarioItemArma)
{
	InventarioItemArma->PickUp();
	MiInventarioArma->AgregarAlInventarioArma(InventarioItemArma);
	//Para la mejora del disparo mas rapido
	FireRate = FireRate* 0.08f;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparo Rapido"));
	//Disparo normal
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L01Pawn::DisparoNormal, 5.0);

	


}
void AGalaga_USFX_L01Pawn::TakeItemVida(ACapsulaVida* InventarioItemVida)
{
	InventarioItemVida->PickUp();
	MiInventarioVida->AgregarAlInventarioVida(InventarioItemVida);

	//Para la mejora de la vida
	salud = salud + 50.0f;
	//mensaje de salud
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("La vida se mejoro"));
}

void AGalaga_USFX_L01Pawn::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	ACapsulaMotor* InventoryItem = Cast<ACapsulaMotor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}
	if (ACapsulaArma* InventoryItemArma = Cast<ACapsulaArma>(Other))
	{
		TakeItemArma(InventoryItemArma);
	}
	if (ACapsulaVida* InventarioItemVida = Cast<ACapsulaVida>(Other))
	{
		TakeItemVida(InventarioItemVida);
	}
}

void AGalaga_USFX_L01Pawn::Regresar()  ///realizar el movimeinto 
{
	//mandar un tipo de dato booleano para mandarlo al tick


}

void AGalaga_USFX_L01Pawn::VelocidadNormal()
{
	MoveSpeed = 1000.0f;
}

void AGalaga_USFX_L01Pawn::DisparoNormal()
{
	FireRate = 0.1f;
}



