// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBallProject.h"
#include "MovingObject.h"

// Sets default values
AMovingObject::AMovingObject()
{
    radius = 100.0f;
    angle = 0.0f;
	dAngle = FMath::DegreesToRadians(5.0f);
    center = GetActorLocation();
    position = FVector(center.X, (center.Y + radius), center.Z);
    velocity = FVector(0.0f, 0.0f, 0.0f);
    acceleration = FVector(0.0f, 0.0f, 0.0f);

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
    Super::BeginPlay();
}

void AMovingObject::updatePosition()
{
    angle = FMath::Fmod((angle + dAngle), (2.0f * PI));
    velocity.Y = radius * FMath::Cos(angle);
    velocity.Z = radius * FMath::Sin(angle);
    position = center + velocity;
}

void AMovingObject::Move()
{
    updatePosition();
    SetActorLocation(position);
}

// Called every frame
void AMovingObject::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
    Move();
}

