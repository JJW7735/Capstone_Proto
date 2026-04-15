// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Capstone_Proto : ModuleRules
{
	public Capstone_Proto(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Capstone_Proto",
			"Capstone_Proto/Variant_Platforming",
			"Capstone_Proto/Variant_Platforming/Animation",
			"Capstone_Proto/Variant_Combat",
			"Capstone_Proto/Variant_Combat/AI",
			"Capstone_Proto/Variant_Combat/Animation",
			"Capstone_Proto/Variant_Combat/Gameplay",
			"Capstone_Proto/Variant_Combat/Interfaces",
			"Capstone_Proto/Variant_Combat/UI",
			"Capstone_Proto/Variant_SideScrolling",
			"Capstone_Proto/Variant_SideScrolling/AI",
			"Capstone_Proto/Variant_SideScrolling/Gameplay",
			"Capstone_Proto/Variant_SideScrolling/Interfaces",
			"Capstone_Proto/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
