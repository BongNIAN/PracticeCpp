// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodehelloworld_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_helloworld;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_helloworld()
	{
		if (!Z_Registration_Info_UPackage__Script_helloworld.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/helloworld",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x52754563,
				0x3A6B6DF6,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_helloworld.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_helloworld.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_helloworld(Z_Construct_UPackage__Script_helloworld, TEXT("/Script/helloworld"), Z_Registration_Info_UPackage__Script_helloworld, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x52754563, 0x3A6B6DF6));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
