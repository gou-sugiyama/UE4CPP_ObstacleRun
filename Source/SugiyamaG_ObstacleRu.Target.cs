// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SugiyamaG_ObstacleRuTarget : TargetRules
{
	public SugiyamaG_ObstacleRuTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "SugiyamaG_ObstacleRu" } );
	}
}
