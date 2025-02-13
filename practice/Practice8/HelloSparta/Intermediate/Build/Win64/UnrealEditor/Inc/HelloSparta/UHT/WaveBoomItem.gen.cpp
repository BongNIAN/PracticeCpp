// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/Public/WaveBoomItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaveBoomItem() {}

// Begin Cross Module References
HELLOSPARTA_API UClass* Z_Construct_UClass_ABaseItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_AWaveBoomItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_AWaveBoomItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class AWaveBoomItem
void AWaveBoomItem::StaticRegisterNativesAWaveBoomItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWaveBoomItem);
UClass* Z_Construct_UClass_AWaveBoomItem_NoRegister()
{
	return AWaveBoomItem::StaticClass();
}
struct Z_Construct_UClass_AWaveBoomItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "WaveBoomItem.h" },
		{ "ModuleRelativePath", "Public/WaveBoomItem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaveBoomItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AWaveBoomItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveBoomItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWaveBoomItem_Statics::ClassParams = {
	&AWaveBoomItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveBoomItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AWaveBoomItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWaveBoomItem()
{
	if (!Z_Registration_Info_UClass_AWaveBoomItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWaveBoomItem.OuterSingleton, Z_Construct_UClass_AWaveBoomItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWaveBoomItem.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<AWaveBoomItem>()
{
	return AWaveBoomItem::StaticClass();
}
AWaveBoomItem::AWaveBoomItem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWaveBoomItem);
AWaveBoomItem::~AWaveBoomItem() {}
// End Class AWaveBoomItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWaveBoomItem, AWaveBoomItem::StaticClass, TEXT("AWaveBoomItem"), &Z_Registration_Info_UClass_AWaveBoomItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWaveBoomItem), 3308642188U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_1130864455(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
