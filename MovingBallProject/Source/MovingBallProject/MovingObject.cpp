// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBallProject.h"
#include "MovingObject.h"
#include <OculusLibrary/Public/IOculusLibraryPlugin.h>

// Sets default values
AMovingObject::AMovingObject()
{
    maxRadius = 400.0f;
    dAngle = FMath::DegreesToRadians(0.5f);
    n = 3;

    angle = 0.0f;
    radius = maxRadius * FMath::Cos(n * angle);

    center = GetActorLocation();
    velocity = FVector(0.0f, 0.0f, 0.0f);
    acceleration = FVector(0.0f, 0.0f, 0.0f);

    updatePosition();

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
    /* See https://en.wikipedia.org/wiki/Kepler%27s_laws_of_planetary_motion#Position_as_a_function_of_time
    float period = 10.0f;
    float meanMotion = 2.0f * PI / period;
    float meanAnomaly = meanMotion * deltaTime;
    float epsilon = 0.0f;
    float eccentricAnomaly;
    */

    angle = FMath::Fmod((angle + dAngle), (2.0f * PI));
    if (FMath::IsNearlyZero(angle, dAngle))
    {
        n = 3 + ((n + 2) % (11 - 3));
    }
    radius = maxRadius * FMath::Cos(n * angle);
    FMath::PolarToCartesian(radius, angle, velocity.Y, velocity.Z);
    position = center + velocity;

    FVector a, gyro, magnetometer;
    float temperature, timeInSeconds;
    IOculusLibraryPlugin oculus = IOculusLibraryPlugin::Get();
    oculus.GetRawSensorData(a, gyro, magnetometer, temperature, timeInSeconds);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Position: <%f, %f, %f>"), a.X, a.Y, a.Z));
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

