// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFPCharacter.h"

// Sets default values
AMyFPCharacter::AMyFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->SetupAttachment(RootComponent);
	cam->SetRelativeLocation(FVector(0, 0, 40));
}

// Called when the game starts or when spawned
void AMyFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LockRot();
}

// Called to bind functionality to input
void AMyFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Hori", this, &AMyFPCharacter::HoriMove);
	InputComponent->BindAxis("Vert", this, &AMyFPCharacter::VertMove);

	InputComponent->BindAxis("HoriRot", this, &AMyFPCharacter::HoriRot);
	InputComponent->BindAxis("VertRot", this, &AMyFPCharacter::VertRot);
}

void AMyFPCharacter::HoriMove(float value)
{
	if (value) //If we receive value, then Addmovement
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}
void AMyFPCharacter::VertMove(float value)
{
	if (value) //If we receive value, then Addmovement
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}


void AMyFPCharacter::HoriRot(float value)
{
	if (value) //If we receive value, then Addmovement
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}
void AMyFPCharacter::VertRot(float value)
{
	float temp = cam->GetRelativeRotation().Pitch + value;
	if (temp < 65 && temp >-65)
	{
		AddActorLocalRotation(FRotator(value, 0, 0));
	}
}

void AMyFPCharacter::LockRot()
{
	cam->SetRelativeRotation(FQuat(0,0,0,0));
}