// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Windows/WindowsHWrapper.h"
#include "Windows/AllowWindowsPlatformTypes.h"


//#include <rhinoSdkStdafxPreamble.h>

#include <include/RhinoCore.h>
//#include <source/RhinoCore.cpp>

#include <include/ArchManager.h>

#include "Windows/HideWindowsPlatformTypes.h"


#include "zRhino.generated.h"

UCLASS()
class RHINOINSIDE_VBETA_API AzRhino : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AzRhino();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
