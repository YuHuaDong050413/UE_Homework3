// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Homework3 : ModuleRules
{
	public Homework3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
