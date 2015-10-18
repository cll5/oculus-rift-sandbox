// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBallProject.h"
#include "MovingObject.h"

// Sets default values
AMovingObject::AMovingObject()
{
    maxRadius = 400.0f;
    dAngle = FMath::DegreesToRadians(0.5f);
    n = 3;

    angle = 0.0f;
    radius = maxRadius * FMath::Cos(n * angle);

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
    if (angle < dAngle) {
        n = 3 + ((n + 2) % (11 - 3));
    }
    radius = maxRadius * FMath::Cos(n * angle);
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

