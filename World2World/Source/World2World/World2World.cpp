// Copyright Epic Games, Inc. All Rights Reserved.

#include "World2World.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"

void FShaderLabModule::StartupModule()
{
	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);
}

void FShaderLabModule::ShutdownModule()
{
	ResetAllShaderSourceDirectoryMappings();
}

IMPLEMENT_PRIMARY_GAME_MODULE( FShaderLabModule, World2World, "World2World" );
