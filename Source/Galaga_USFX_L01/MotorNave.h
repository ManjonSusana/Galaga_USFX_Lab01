// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveBuilder.h"
#include "MotorNave.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AMotorNave : public AActor, public INaveBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMotorNave();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MotorNave")
	class ANaveMejora* NaveMejora;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Metodos de la interfaz DE INaveBuilder 
	virtual void builNaveMejoras(FVector ubicacionNaveMejoras) override;
	virtual void buildVidaNave() override;
	virtual void buildMotorNave() override;
	virtual void buildArmaNave() override;
	virtual void buildMallaNave() override;
	class UStaticMesh* MotorNave = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/MALLAS/MOTORNAVE/735e7079a452_capsula_de_velocida.735e7079a452_capsula_de_velocida'"));
	virtual class ANaveMejora* getNaveMejora() override;

};
