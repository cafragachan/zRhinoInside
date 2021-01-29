// Fill out your copyright notice in the Description page of Project Settings.


#include "zRhino.h"

#include "HAL/FileManager.h"

// Sets default values
AzRhino::AzRhino()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AzRhino::BeginPlay()
{
	Super::BeginPlay();

	//
	FString MyLibPath = "C:/Program Files/Rhino 7 WIP/System/";
	//FString MyLibPath = "D:/DOCUMENTS/UNREAL/RhinoInside/RhinoInside_vBeta/Binaries";

	FString AbsPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*MyLibPath);
	FPlatformProcess::AddDllDirectory(*AbsPath);

	void* DLLHandle3 = FPlatformProcess::GetDllHandle(L"RhinoCore.dll");
	//void* DLLHandle2 = FPlatformProcess::GetDllHandle(L"opennurbs.dll");
	//void* DLLHandle1 = FPlatformProcess::GetDllHandle(L"RhinoLibrary.dll");
	////void* DLLHandle0 = FPlatformProcess::GetDllHandle(L"rhcommon_c.dll");

	////

	//RhinoCore rhinoCore;

	int year = 0, month = 0, day = 0;
	RhinoApp().GetBuildDate(year, month, day);

	UE_LOG(LogTemp, Warning, TEXT("Rhino: %i.%i"), RhinoApp().ExeVersion(), RhinoApp().ExeServiceRelease());

	/*std::cout << "\n Rhino " << RhinoApp().ExeVersion() << "." << RhinoApp().ExeServiceRelease() <<
		" (" << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setfill('0') << std::setw(2) << day << ") loaded." << std::endl;*/

	//////////////////////////////////////////////////////////////////////////

	//FString MyLibPath = "C:/Program Files/Rhino 7 WIP/System";
	////FString MyLibPath = "D:/DOCUMENTS/UNREAL/RhinoInside/RhinoInside_vBeta/Binaries";

	//FString AbsPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*MyLibPath);
	//FPlatformProcess::AddDllDirectory(*AbsPath);

	//void* DLLHandle3 = FPlatformProcess::GetDllHandle(L"RhinoCore.dll");
	//void* DLLHandle2 = FPlatformProcess::GetDllHandle(L"opennurbs.dll");
	//void* DLLHandle1 = FPlatformProcess::GetDllHandle(L"RhinoLibrary.dll");
	////void* DLLHandle0 = FPlatformProcess::GetDllHandle(L"rhcommon_c.dll");


	ON_ClassArray<ON_NurbsCurve> nc;

	ON_3dPointArray points0;
	points0.Append(ON_3dPoint(0, 0, 0));
	// points0.Append(ON_3dPoint(0.25, 0, 0));
	 //points0.Append(ON_3dPoint(0.5, 0, 0));
	// points0.Append(ON_3dPoint(0.75, 0, 0));
	points0.Append(ON_3dPoint(1, 0, 0));
	nc.AppendNew();
	nc[0].CreateClampedUniformNurbs(3, 2, points0.Count(), points0);

	UE_LOG(LogTemp, Warning, TEXT("NURBS size: %i"), nc[0].CVCount()); 
	
}

// Called every frame
void AzRhino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

