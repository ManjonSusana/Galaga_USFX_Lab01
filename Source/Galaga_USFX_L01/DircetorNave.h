// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveBuilder.h"
#include "DircetorNave.generated.h"

class INaveBuilder;

UCLASS()
class GALAGA_USFX_L01_API ADircetorNave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADircetorNave();
private:
	INaveBuilder* NaveBuilder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//MANDANOD A CONSTRUIR NAVE MEJORAS
	void ConstruirNaveMejoras(FVector ubiNaveMejoras);

	void SetNavesBuilder(AActor* Builder);

	class ANaveMejora* getNaveMejora();

};
