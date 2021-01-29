// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class RhinoInside_vBeta : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string AerDNAPath
    {
        get { return Path.GetFullPath("D:/Repos/AerDNA"); }
    }

    private string RhinoPath
    {
        get { return Path.GetFullPath("C:/Program Files/Rhino 6 SDK"); }
    }

    private string RhinoDLL
    {
        get { return Path.GetFullPath("C:/Program Files/Rhino 7 WIP"); }
        //get { return Path.GetFullPath("D:/DOCUMENTS/UNREAL/RhinoInside/RhinoInside_vBeta/Binaries"); }
    }



    public RhinoInside_vBeta(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        LoadzSpace(Target);
    }

    public bool LoadzSpace(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = false;

        Definitions.Add("WIN64");

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;

            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
            string AerDNALibrariesPath = Path.Combine(AerDNAPath, "cpp/compiled/UnrealLib/");
            string RhinoLibrariesPath = Path.Combine(RhinoPath, "lib/Release/");
            string RhinoDLLPath = Path.Combine(RhinoDLL, "System/");
            //string RhinoDLLPath = Path.Combine(RhinoDLL, "");

            if (File.Exists(RhinoDLLPath + "RhinoCore.dll"))
            {
                System.Console.WriteLine("Rhino DLL Path exists");
            }
            else
            {
                System.Console.WriteLine("NO Rhino DLL ");

            }
            PublicDelayLoadDLLs.Add("opennurbs.dll");
            RuntimeDependencies.Add(RhinoDLLPath + "opennurbs.dll");
            PublicDelayLoadDLLs.Add("RhinoCore.dll");
            RuntimeDependencies.Add(RhinoDLLPath + "RhinoCore.dll");
            PublicDelayLoadDLLs.Add("RhinoLibrary.dll");
            RuntimeDependencies.Add(RhinoDLLPath + "RhinoLibrary.dll");
            // PublicDelayLoadDLLs.Add("rhcommon_c.dll");
            //RuntimeDependencies.Add(RhinoDLLPath + "rhcommon_c.dll");


            PublicAdditionalLibraries.Add(Path.Combine(AerDNALibrariesPath, "AerDNA" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(RhinoLibrariesPath, "opennurbs" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(RhinoLibrariesPath, "rdk" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(RhinoLibrariesPath, "RhinoCore" + ".lib"));
            PublicAdditionalLibraries.Add(Path.Combine(RhinoLibrariesPath, "RhinoLibrary" + ".lib"));
        }

        if (isLibrarySupported)
        {
            // Include path
            PublicIncludePaths.Add(Path.Combine(AerDNAPath, "cpp"));
            PublicIncludePaths.Add(Path.Combine(RhinoPath, "inc"));
        }

        return isLibrarySupported;
    }
}
