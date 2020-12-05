// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Moon.generated.h"

UCLASS()
class WORLD2WORLD_API AMoon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh Parameters")
		FVector Radius = FVector(100.f, 100.f, 100.f);
		FVector SphereRadius = FVector(500.f, 500.f, 500.f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* ThisScene;
	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* ThisMesh;

	virtual void PostActorCreated() override; //triggers when spawned / dragged to world
	virtual void PostLoad() override; //triggers when you open level/world

	void GenerateMesh();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray < FVector > Normals;
	TArray<FVector2D> UV0;
	TArray <FColor> VertexColors;
	TArray <FProcMeshTangent> Tangents;
	TArray<FLinearColor>Colors;

	void AddTriangleMesh();
	void AddQuadMesh();

	
};
