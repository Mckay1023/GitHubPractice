// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"
#include "RTS_Game.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create a root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	//Camera Mesh
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Camera Mesh"));
	CameraMesh->SetupAttachment(RootComponent);
	
	//Create and initialize CameraSpringArm
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Spring Arm"));
	CameraSpringArm->SetupAttachment(CameraMesh);
	CameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.0f), FRotator(-70.0f, 0.0f, 0.0f));
	CameraSpringArm->TargetArmLength = 1000.0f;
	CameraSpringArm->bEnableCameraLag = true;
	CameraSpringArm->CameraLagSpeed = 3.0f;

	//Camera Component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetUpAttachment(CameraSpringArm);
	//CameraComponent->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	//CameraComponent->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	

	//Pawn is possesed by lowest number player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	

}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

