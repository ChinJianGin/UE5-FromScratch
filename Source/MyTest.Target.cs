
using UnrealBuildTool;
using System.Collections.Generic;

public class MyTestTarget : TargetRules
{
	public MyTestTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "MyTestCore" } );
	}
}