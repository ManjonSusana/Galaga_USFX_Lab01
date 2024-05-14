// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanoNave.h"
#include "ComponenteMovimiento.h"
#include "NaveMejora.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveMejora : public AActor, public IPlanoNave
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANaveMejora();

private:
	UPROPERTY(VisibleAnywhere, Category = "VidaNave")
	FString VidaNave;
	UPROPERTY(VisibleAnywhere, Category = "MotorNave")
	FString VelocidadNave;
	UPROPERTY(VisibleAnywhere, Category = "ArmaNave")
	FString ArmaNave;

	bool Verificacion = false;
	bool VerificacionArma = false;
	bool VerificacionVida = false;
	bool VerificacionSuperNave = false;

	float TiempoTranscurrido;

private:
	class ACapsulaMotor* CapsulaMotor01;
	class ACapsulaArma* CapsulaArma01;
	class ACapsulaVida* CapsulaVida01;
private:
	FTimerHandle DestruirCapsulaTimerHandle;

public:
	UPROPERTY(VisibleAnywhere, Category = "MallaNave") //MALLA NAVEMEJORAS
		UStaticMeshComponent* MallaNave;

	// Declaración del componente de movimiento de naves
	UComponenteMovimiento* MovimientoNavesComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//virtual void SetNaveMejoras() override;
	// 
	//creacion de capsulas de motor, arma y vida
	virtual void SetVidaNave(FString NewVidaNave) override;
	virtual void SetMotorNave(FString NewVelocidadNave) override;
	virtual void SetArmaNave(FString NewArmaNave) override;

	virtual void SetMalla(UStaticMeshComponent* NewMallaNave) override;
	//destruir capsulaa
	void DestruirCapsulaMotor();
	void DestruirCapsulaArma();
	void DestruirCapsulaVida();


	void CaracteristicasNave();
};
