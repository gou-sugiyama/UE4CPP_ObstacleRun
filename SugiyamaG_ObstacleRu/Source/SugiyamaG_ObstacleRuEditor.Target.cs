// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SugiyamaG_ObstacleRuEditorTarget : TargetRules
{
	public SugiyamaG_ObstacleRuEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "SugiyamaG_ObstacleRu" } );
	}
}
