// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHelloSparta_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_HelloSparta;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_HelloSparta()
	{
		if (!Z_Registration_Info_UPackage__Script_HelloSparta.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/HelloSparta",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x79F71013,
				0x98BE16E8,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_HelloSparta.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_HelloSparta.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_HelloSparta(Z_Construct_UPackage__Script_HelloSparta, TEXT("/Script/HelloSparta"), Z_Registration_Info_UPackage__Script_HelloSparta, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x79F71013, 0x98BE16E8));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
