// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/Public/SpeedUpItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpeedUpItem() {}

// Begin Cross Module References
HELLOSPARTA_API UClass* Z_Construct_UClass_ABaseItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_ASpeedUpItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_ASpeedUpItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class ASpeedUpItem
void ASpeedUpItem::StaticRegisterNativesASpeedUpItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpeedUpItem);
UClass* Z_Construct_UClass_ASpeedUpItem_NoRegister()
{
	return ASpeedUpItem::StaticClass();
}
struct Z_Construct_UClass_ASpeedUpItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SpeedUpItem.h" },
		{ "ModuleRelativePath", "Public/SpeedUpItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffDuration_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/SpeedUpItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedUpAmount_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/SpeedUpItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffDuration;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpeedUpAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpeedUpItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpeedUpItem_Statics::NewProp_BuffDuration = { "BuffDuration", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpeedUpItem, BuffDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffDuration_MetaData), NewProp_BuffDuration_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASpeedUpItem_Statics::NewProp_SpeedUpAmount = { "SpeedUpAmount", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpeedUpItem, SpeedUpAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedUpAmount_MetaData), NewProp_SpeedUpAmount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpeedUpItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpeedUpItem_Statics::NewProp_BuffDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpeedUpItem_Statics::NewProp_SpeedUpAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpeedUpItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpeedUpItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpeedUpItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpeedUpItem_Statics::ClassParams = {
	&ASpeedUpItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASpeedUpItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpeedUpItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpeedUpItem_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpeedUpItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpeedUpItem()
{
	if (!Z_Registration_Info_UClass_ASpeedUpItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpeedUpItem.OuterSingleton, Z_Construct_UClass_ASpeedUpItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpeedUpItem.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<ASpeedUpItem>()
{
	return ASpeedUpItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpeedUpItem);
ASpeedUpItem::~ASpeedUpItem() {}
// End Class ASpeedUpItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpeedUpItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpeedUpItem, ASpeedUpItem::StaticClass, TEXT("ASpeedUpItem"), &Z_Registration_Info_UClass_ASpeedUpItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpeedUpItem), 1093322209U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpeedUpItem_h_3224760503(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpeedUpItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpeedUpItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
