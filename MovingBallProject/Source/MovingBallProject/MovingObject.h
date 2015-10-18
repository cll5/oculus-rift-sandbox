// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class MOVINGBALLPROJECT_API AMovingObject : public AActor
{
	GENERATED_BODY()

	FVector position;
	FVector velocity;
	FVector acceleration;
	FVector center;
	int n;
	float radius;
	float maxRadius;
	float angle;
	float dAngle;

protected:
	virtual void updatePosition();
	virtual void Move();

public:	
	// Sets default values for this actor's properties
	AMovingObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
};
