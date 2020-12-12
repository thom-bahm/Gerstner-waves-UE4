// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMesh.h"

AProcMesh::AProcMesh()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	ThisScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = ThisScene;

	ThisMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GenerateMesh"));
	ThisMesh->SetupAttachment(RootComponent);
}
// Called when the game starts or when spawned
void AProcMesh::BeginPlay()
{
	Super::BeginPlay();
}

void AProcMesh::PostActorCreated()
{
	Super::PostActorCreated();
	GenerateMesh();
}

void AProcMesh::PostLoad()
{
	Super::PostLoad();
	GenerateMesh();
}


void AProcMesh::GenerateMesh()
{
	Vertices.Reset();
	Triangles.Reset();
	Tangents.Reset();
	Normals.Reset();
	UV0.Reset();
	Colors.Reset();
	VertexColors.Reset();

	FProcMeshTangent TangentSetup = FProcMeshTangent(0.f, 1.f, 0.f);
	
	FVector shape = (FVector(Radius.X, Radius.Y, Radius.Z));
	FVector shape1 = (FVector(Radius.X, Radius.Y, -Radius.Z));
	FVector shape2 = (FVector(Radius.X, -Radius.Y, Radius.Z));
	FVector shape3 = (FVector(Radius.X, -Radius.Y, -Radius.Z));

	AddCube();
	ThisMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, Colors, Tangents, true);

}

// Called every frame
void AProcMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GenerateMesh();
}

void AProcMesh::AddTriangleMesh(FProcMeshTangent TangentSetup)
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

void AProcMesh::AddQuadMesh(FProcMeshTangent TangentSetup, FVector p0, FVector p1, FVector p2, FVector p3)
{
	//Vertices
	Vertices.Add(p0);
	Vertices.Add(p1);
	Vertices.Add(p2);
	Vertices.Add(p3);

	//Triangles
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);

	FVector ThisNorm = FVector::CrossProduct(p0-p3, p0-p2);

	for (int i = 0; i < 4; i++)
	{
		Normals.Add(ThisNorm);
		Tangents.Add(TangentSetup);
		Colors.Add(FLinearColor::Green);
		VertexColors.Add(FColor::Green);
	}

	UV0.Add(FVector2D(0.0f, 1.0f));  //TL
	UV0.Add(FVector2D(0.0f, 0.0f));  //BL
	UV0.Add(FVector2D(1.0f, 1.0f));  //TR
	UV0.Add(FVector2D(1.0f, 0.0f));  //BR
}

void AProcMesh::AddCube()
{
	FVector CubeVerts[8];
	CubeVerts[0] = (FVector(Radius.X, Radius.Y, Radius.Z));
	CubeVerts[1] = (FVector(Radius.X, Radius.Y, -Radius.Z));
	CubeVerts[2] = (FVector(Radius.X, -Radius.Y, Radius.Z));
	CubeVerts[3] = (FVector(Radius.X, -Radius.Y, -Radius.Z));

	CubeVerts[4] = (FVector(-Radius.X, -Radius.Y, -Radius.Z));
	CubeVerts[5] = (FVector(-Radius.X, -Radius.Y, Radius.Z));
	CubeVerts[6] = (FVector(-Radius.X, Radius.Y, -Radius.Z));
	CubeVerts[7] = (FVector(-Radius.X, Radius.Y, Radius.Z));

	FProcMeshTangent Tangent;
	Tangent = FProcMeshTangent(0.f, 1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[0], CubeVerts[1], CubeVerts[2], CubeVerts[3]); //Front

	Tangent = FProcMeshTangent(1.f, 0.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[2], CubeVerts[3], CubeVerts[4], CubeVerts[3]); //Left

	Tangent = FProcMeshTangent(0.f, -1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[4], CubeVerts[5], CubeVerts[6], CubeVerts[7]); //Back

	Tangent = FProcMeshTangent(-1.f, 0.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[6], CubeVerts[7], CubeVerts[0], CubeVerts[1]); //Right

	Tangent = FProcMeshTangent(0.f, 1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[6], CubeVerts[0], CubeVerts[4], CubeVerts[2]); //Top

	Tangent = FProcMeshTangent(0.f, -1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[1], CubeVerts[7], CubeVerts[3], CubeVerts[5]); //Bottom
}

void AProcMesh::AddCube(FProcMeshTangent TangentSetup, FVector p0, FVector p1, FVector p2, FVector p3)
{
	FVector CubeVerts[8];
	CubeVerts[0] = (FVector(Radius.X, Radius.Y, Radius.Z));
	CubeVerts[1] = (FVector(Radius.X, Radius.Y, -Radius.Z));
	CubeVerts[2] = (FVector(Radius.X, -Radius.Y, Radius.Z));
	CubeVerts[3] = (FVector(Radius.X, -Radius.Y, -Radius.Z));

	CubeVerts[4] = (FVector(-Radius.X, -Radius.Y, -Radius.Z));
	CubeVerts[5] = (FVector(-Radius.X, -Radius.Y, Radius.Z));
	CubeVerts[6] = (FVector(-Radius.X, Radius.Y, -Radius.Z));
	CubeVerts[7] = (FVector(-Radius.X, Radius.Y, Radius.Z));

	FProcMeshTangent Tangent = FProcMeshTangent(0.f, 1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[0], CubeVerts[1], CubeVerts[2], CubeVerts[3]); //Front

	Tangent = FProcMeshTangent(1.f, 0.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[2], CubeVerts[3], CubeVerts[4], CubeVerts[3]); //Left

	Tangent = FProcMeshTangent(0.f, -1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[4], CubeVerts[5], CubeVerts[6], CubeVerts[7]); //Back

	Tangent = FProcMeshTangent(-1.f, 0.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[6], CubeVerts[7], CubeVerts[0], CubeVerts[1]); //Right

	Tangent = FProcMeshTangent(0.f, 1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[6], CubeVerts[0], CubeVerts[4], CubeVerts[2]); //Top

	Tangent = FProcMeshTangent(0.f, -1.f, 0.f);
	AddQuadMesh(Tangent, CubeVerts[1], CubeVerts[7], CubeVerts[3], CubeVerts[5]); //Bottom
}

void AProcMesh::AddBasicSphere()
{
	
}

