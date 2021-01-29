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


	RhinoCore rhinoCore;

	int year = 0, month = 0, day = 0;
	RhinoApp().GetBuildDate(year, month, day);

	UE_LOG(LogTemp, Warning, TEXT("Rhino: %i.%i"), RhinoApp().ExeVersion(), RhinoApp().ExeServiceRelease());


	//////////////////////////////////////////////////////////////////////////

	

	//ON_ClassArray<ON_NurbsCurve> nc;
	//ON_3dPointArray points0;
	//points0.Append(ON_3dPoint(0, 0, 0));
	//// points0.Append(ON_3dPoint(0.25, 0, 0));
	// //points0.Append(ON_3dPoint(0.5, 0, 0));
	//// points0.Append(ON_3dPoint(0.75, 0, 0));
	//points0.Append(ON_3dPoint(1, 0, 0));
	//nc.AppendNew();
	//nc[0].CreateClampedUniformNurbs(3, 2, points0.Count(), points0);
	//ON_3dPointArray points1;
	//points1.Append(ON_3dPoint(1, 0, 0));
	//// points1.Append(ON_3dPoint(1, 0.25, 0));
	// //points1.Append(ON_3dPoint(1, 0.5, 0));
	//// points1.Append(ON_3dPoint(1, 0.75, 0));
	//points1.Append(ON_3dPoint(1, 1, 0));
	//nc.AppendNew();
	//nc[1].CreateClampedUniformNurbs(3, 2, points1.Count(), points1);
	//ON_3dPointArray points2;
	//points2.Append(ON_3dPoint(1, 1, 0));
	//// points2.Append(ON_3dPoint(0.75, 1, 0));
	// //points2.Append(ON_3dPoint(0.5, 1, 0));
	// //points2.Append(ON_3dPoint(0.25, 1, 0));
	//points2.Append(ON_3dPoint(0, 1, 0));
	//nc.AppendNew();
	//nc[2].CreateClampedUniformNurbs(3, 2, points2.Count(), points2);
	//ON_3dPointArray points3;
	//points3.Append(ON_3dPoint(0, 1, 0));
	////points3.Append(ON_3dPoint(0, 0.75, 0));
	////points3.Append(ON_3dPoint(0, 0.5, 0));
	////points3.Append(ON_3dPoint(0, 0.25, 0));
	//points3.Append(ON_3dPoint(0, 0, 0));
	//nc.AppendNew();
	//nc[3].CreateClampedUniformNurbs(3, 2, points3.Count(), points3);
	//const ON_Curve* c[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	c[i] = &nc[i];
	//	double length = ON_UNSET_VALUE;
	//	if (c[i]->GetLength(&length))
	//	{
	//		// RhinoApp().Print(L"Curve with %f length created\n", length);
	//		//std::cout << "curve with " << length << " length created" << std::endl;
	//		UE_LOG(LogTemp, Warning, TEXT("Length: %1.2f"), length);

	//	}
	//}
	//ON_Brep* brep = RhinoCreateEdgeSrf(4, c);
	//if (nullptr != brep)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Brep faces: %i"), brep->m_F.Count());
	//	//UE_LOG(LogTemp, Warning, TEXT("Length: %1.2f"), length);

	//	/*std::cout << "Brep with " << brep->m_F.Count() << " faces created" << std::endl;
	//	std::cout << "Surface with " << brep->BoundingBox().Area() << " area created" << std::endl;*/
	//	//RhinoApp().Print(L"Brep with %f area created\n", brep->BoundingBox().Area());
	//	//  ON_Surface* sur = brep->m_F[0].Offset(0.1, 0.001);
	//	 // std::cout << "Surface with " << sur->BoundingBox().Area() << " area created" << std::endl;
	//	  //RhinoApp().Print(L"Surface with %f area created\n", sur->BoundingBox().Area());
	//	  //delete sur;
	//	delete brep; // Don't leak...
	//}



	///////////////////////////////////////////////////////
	ArchManager manager;
	ON_Mesh mesh;

	manager.CreateMesh(mesh);

	vector<double> vertices;
	//if (manager.mesh == nullptr) cout << "mesh null" << endl;
	vertices = manager.GetVertices(mesh);

	UE_LOG(LogTemp, Warning, TEXT("vertices count: %i"), vertices.size());
	for (auto v : vertices)
	{
		//std::cout << "vertices: " << std::to_string(v) << std::endl;
		UE_LOG(LogTemp, Warning, TEXT("vertices: %f"), v);
	}

	//ON_Mesh* m = &mesh;

	//const ON_3dPoint a(0, 0, 0);
	//const ON_3dPoint b(20, 0, 0);
	//ON_3dPoint c(20, 20, 20);
	//ON_3dPoint d(0, 20, 0);

	//ON_NurbsSurface* srf = RhinoCreateSurfaceFromCorners(a, b, c, d);

	//ON_MeshParameters mp = ON_MeshParameters();
	//srf->CreateMesh(mp, m);

	////cout << endl << "vCount:" << mesh.VertexCount() << endl;
	//UE_LOG(LogTemp, Warning, TEXT("vertices: %i"), mesh.VertexCount());
}

// Called every frame
void AzRhino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

