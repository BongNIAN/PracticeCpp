// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/Public/SpikeTrapItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpikeTrapItem() {}

// Begin Cross Module References
HELLOSPARTA_API UClass* Z_Construct_UClass_ABaseItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_ASpikeTrapItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_ASpikeTrapItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class ASpikeTrapItem
void ASpikeTrapItem::StaticRegisterNativesASpikeTrapItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpikeTrapItem);
UClass* Z_Construct_UClass_ASpikeTrapItem_NoRegister()
{
	return ASpikeTrapItem::StaticClass();
}
struct Z_Construct_UClass_ASpikeTrapItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SpikeTrapItem.h" },
		{ "ModuleRelativePath", "Public/SpikeTrapItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Amplitude_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/SpikeTrapItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Frequency_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/SpikeTrapItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amplitude;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Frequency;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpikeTrapItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpikeTrapItem_Statics::NewProp_Amplitude = { "Amplitude", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpikeTrapItem, Amplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Amplitude_MetaData), NewProp_Amplitude_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpikeTrapItem_Statics::NewProp_Frequency = { "Frequency", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpikeTrapItem, Frequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Frequency_MetaData), NewProp_Frequency_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpikeTrapItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpikeTrapItem_Statics::NewProp_Amplitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpikeTrapItem_Statics::NewProp_Frequency,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpikeTrapItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpikeTrapItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpikeTrapItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpikeTrapItem_Statics::ClassParams = {
	&ASpikeTrapItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASpikeTrapItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpikeTrapItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpikeTrapItem_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpikeTrapItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpikeTrapItem()
{
	if (!Z_Registration_Info_UClass_ASpikeTrapItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpikeTrapItem.OuterSingleton, Z_Construct_UClass_ASpikeTrapItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpikeTrapItem.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<ASpikeTrapItem>()
{
	return ASpikeTrapItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpikeTrapItem);
ASpikeTrapItem::~ASpikeTrapItem() {}
// End Class ASpikeTrapItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpikeTrapItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpikeTrapItem, ASpikeTrapItem::StaticClass, TEXT("ASpikeTrapItem"), &Z_Registration_Info_UClass_ASpikeTrapItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpikeTrapItem), 927423995U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpikeTrapItem_h_150442039(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpikeTrapItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_SpikeTrapItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
