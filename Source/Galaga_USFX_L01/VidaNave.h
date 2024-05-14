// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveBuilder.h"
#include "VidaNave.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AVidaNave : public AActor, public INaveBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVidaNave();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VidaNave")
	
	class ANaveMejora* NaveMejora;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Metodos de la interfaz de INaveBuilder
	virtual void builNaveMejoras(FVector ubicacionNaveMejoras) override;
	virtual void buildVidaNave() override;
	virtual void buildMotorNave() override;
	virtual void buildArmaNave() override;
	virtual void buildMallaNave() override;
	class UStaticMesh* VidaNave = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/MALLAS/0fcbbf768755_necesito_una_maripo.0fcbbf768755_necesito_una_maripo'"));
	virtual class ANaveMejora* getNaveMejora() override;

};