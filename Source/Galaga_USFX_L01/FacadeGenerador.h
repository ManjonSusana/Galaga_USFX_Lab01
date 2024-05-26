// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeGenerador.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AFacadeGenerador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeGenerador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	class ADircetorNave* DirectorNave01;
	class ASuperNave* SuperNave01;
	class AMotorNave* MotorNave01;
	class AArmaNave* ArmaNave01;
	class AVidaNave* VidaNave01;

	class ACapsulasMotor* CapsulasMotor01;
	class ACapsulasArma* CapsulasArma01;
	class ACapsulasVida* CapsulasVida01;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FabricarNaves();
	void FaabricarBuider();
	void FabricarNavesAtaque();
	void FabricarNavesDisparo();
};