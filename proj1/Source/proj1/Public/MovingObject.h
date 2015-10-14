// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class PROJ1_API AMovingObject : public AActor
{
	GENERATED_BODY()

private:
	//Coordinate
	FVector position;

	//Velocity
	FVector velocity = FVector(0.0, 0.0, 0.0);
	FVector acceleration = FVector(0.1, 0.1, 0.0);

	FVector generateNextPosition(FVector position) {
		//path function
		velocity += acceleration;
		position += velocity;
		return position;
	};

public:	
	// Sets default values for this actor's properties
	AMovingObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Move() {
		position = generateNextPosition(position);
	}
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
};
