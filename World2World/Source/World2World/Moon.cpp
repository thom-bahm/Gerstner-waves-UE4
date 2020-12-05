// Fill out your copyright notice in the Description page of Project Settings.


#include "Moon.h"

// Sets default values
AMoon::AMoon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	ThisScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = ThisScene;

	ThisMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GenerateMesh"));
	ThisMesh->SetupAttachment(RootComponent);
}
// Called when the game starts or when spawned
void AMoon::BeginPlay()
{
	Super::BeginPlay();
}

void AMoon::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateMesh();
}

void AMoon::PostLoad()
{
	Super::PostLoad();
	GenerateMesh();
}


void AMoon::GenerateMesh()
{
	Vertices.Reset();
	Triangles.Reset();
	Tangents.Reset();
	Normals.Reset();
	UV0.Reset();
	Colors.Reset();

	VertexColors.Reset();

	AddTriangleMesh();

	ThisMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, Colors, Tangents, true);
}

// Called every frame
void AMoon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMoon::AddTriangleMesh()
{
	Vertices = {
		FVector(Radius.X, Radius.Y, Radius.Z), 
		FVector(Radius.X, Radius.Y, -Radius.Z),
		FVector(Radius.X, -Radius.Y, -Radius.Z)
	};

	Triangles = {
		0, 1, 2
	};

	FVector ThisNorm = FVector::CrossProduct(Vertices[0], Vertices[2]).GetSafeNormal();

	FProcMeshTangent Tangent = FProcMeshTangent(0.f, 1.f, 0.f);

	for (int i = 0; i < 3; i++)
	{
		Normals.Add(ThisNorm);
		Tangents.Add(Tangent);
		Colors.Add(FLinearColor::Green);
		VertexColors.Add(FColor::Green);
	}

	UV0 = {
		FVector2D(0.0f, 1.0f), //TL
		FVector2D(0.0f, 0.0f), //BL
		FVector2D(1.0f, 0.0f)  //BR
	};
}







void AMoon::AddQuadMesh()
{
	Vertices = {
		FVector(Radius.X, Radius.Y, Radius.Z),
		FVector(Radius.X, Radius.Y, Radius.Z),
		FVector(Radius.X, Radius.Y, Radius.Z),
		FVector(Radius.X, Radius.Y, Radius.Z)
	};

	Triangles = {
		0, 1, 3,
		1, 2, 3
	};

	FVector ThisNorm = FVector::CrossProduct(Vertices[0], Vertices[2]);

	FProcMeshTangent Tangent = FProcMeshTangent(0.f, 1.f, 0.f);

	for (int i = 0; i < 4; i++)
	{
		Normals.Add(ThisNorm);
		Tangents.Add(Tangent);
		Colors.Add(FLinearColor::Green);
		VertexColors.Add(FColor::Green);
	}

	UV0 = {
		FVector2D(0.0f, 1.0f), //TL
		FVector2D(0.0f, 0.0f), //BL
		FVector2D(1.0f, 1.0f), //TR
		FVector2D(1.0f, 0.0f)  //BR
	};
}
