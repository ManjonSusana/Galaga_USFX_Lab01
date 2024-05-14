// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barrera.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ABarrera : public AActor
{
	GENERATED_BODY()
public: 
	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = Proyectile, meta=(AllowPrivateAcces= "true"))
		UStaticMeshComponent* mallaBarrera; //malla de la barrera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Proyectile, meta = (AllowPrivateAcces = "true"))
		class UBoxComponent* colision_BARRERA; //colision de la barrera
		virtual void DestruirBarrera(); //destruir barrera
private:
	float resistencia = 20.0f;
	FVector posicionInicial;
	
public:	
	// Sets default values for this actor's properties
	ABarrera(); //constructor de la barrera

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//void NotifyActorEndOverlap(AActor* OtherActor) override; //cuando se deja de colisionar con algo
	//virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override; //cuando se colisiona con algo
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override; //cuando se colisiona con algo

};

