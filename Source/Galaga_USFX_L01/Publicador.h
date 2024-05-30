// Fill out your copyright notice in the Description page of Project Settings
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Publicador.generated.h"

class ISubscriptorEnemigo;

UCLASS()
class GALAGA_USFX_L01_API APublicador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Publicador Enemigo")
	//Array para las naves enemigas
	TArray<AActor*> SubscriptorEnemigas;
	//Subscriptor
	class ISubscriptorEnemigo* Subscriptor;

	class ATorreEnemiga2* TorreEnemiga;

	//subscribir y desubscribir naves enemigas
	void subscribirNaveEnemiga(AActor* _subscribriNave);
	void desubscribirNaveEnemiga(AActor* _desubcribirNave);

	//notificar a las naves enemigas
	void Notificar();

};
