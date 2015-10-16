// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBallProject.h"
#include "MovingObject.h"


// Sets default values
AMovingObject::AMovingObject()
{
	position = GetActorLocation();
	velocity = FVector(0.0, 0.0, 0.0);
	acceleration = FVector(0.0, 0.0, 0.001);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	Move();
}

