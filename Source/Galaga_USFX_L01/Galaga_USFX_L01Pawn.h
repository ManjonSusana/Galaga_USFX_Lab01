// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "Barrera.h"
#include "ComponenteBarrera.h"	
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Character.h"
#include "ComponenteInventario.h"
#include "CapsulaMotor.h"
#include "CapsulaArma.h"
#include "CapsulaVida.h"
#include "Galaga_USFX_L01Pawn.generated.h"

UCLASS(Blueprintable)
class AGalaga_USFX_L01Pawn : public APawn
{
	GENERATED_BODY()
	

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;



public:
	AGalaga_USFX_L01Pawn();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite )
	FVector GunOffset; 
	FVector GunOffset2;
	
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float salud;

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;



	void crearBarrera();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ComponenteBarrera; //Componente de la barrera
	ABarrera* barrera; //Barrera

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection); 

	/* Handler for the fire timer expiry */
	void ShotTimerExpired(); 

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;
public:
	UPROPERTY()
	UComponenteInventario* MiInventario; //Componente de inventario
	UPROPERTY()
	UComponenteInventario* MiInventarioArma;

	UPROPERTY()
	UComponenteInventario* MiInventarioVida;

	UFUNCTION()
	void DropItem(); //Funcion para soltar el item
	UFUNCTION()
	void DropItemArma();
	UFUNCTION()
	void DropItemVida();

	UFUNCTION()
	void TakeItem(ACapsulaMotor* InventarioItem); //Funcion para tomar el item
	UFUNCTION()
	void TakeItemArma(ACapsulaArma* InventarioItemArma);
	UFUNCTION()
	void TakeItemVida(ACapsulaVida* InventarioItemVida);

	UFUNCTION()
	virtual void NotifyHit(class UPrimitiveComponent* MyComp,
		AActor* Other, class UPrimitiveComponent* OtherComp, bool
		bSelfMoved, FVector HitLocation, FVector
		HitNormal, FVector NormalImpulse, const FHitResult&
		Hit) override;
private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	FTimerHandle DestruirBarrera;

public:
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	//FORCEINLINE float GetVida() const { return vida; }
    
	virtual void Regresar();
	virtual void VelocidadNormal();

};

