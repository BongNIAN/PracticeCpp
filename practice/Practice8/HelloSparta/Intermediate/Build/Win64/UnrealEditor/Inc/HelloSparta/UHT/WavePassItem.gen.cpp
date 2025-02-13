// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/Public/WavePassItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWavePassItem() {}

// Begin Cross Module References
HELLOSPARTA_API UClass* Z_Construct_UClass_ABaseItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_AWavePassItem();
HELLOSPARTA_API UClass* Z_Construct_UClass_AWavePassItem_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class AWavePassItem
void AWavePassItem::StaticRegisterNativesAWavePassItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWavePassItem);
UClass* Z_Construct_UClass_AWavePassItem_NoRegister()
{
	return AWavePassItem::StaticClass();
}
struct Z_Construct_UClass_AWavePassItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "WavePassItem.h" },
		{ "ModuleRelativePath", "Public/WavePassItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WavePassItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWavePassItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWavePassItem_Statics::NewProp_InteractionWidget = { "InteractionWidget", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWavePassItem, InteractionWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionWidget_MetaData), NewProp_InteractionWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWavePassItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWavePassItem_Statics::NewProp_InteractionWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWavePassItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AWavePassItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWavePassItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWavePassItem_Statics::ClassParams = {
	&AWavePassItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AWavePassItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AWavePassItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWavePassItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AWavePassItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWavePassItem()
{
	if (!Z_Registration_Info_UClass_AWavePassItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWavePassItem.OuterSingleton, Z_Construct_UClass_AWavePassItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWavePassItem.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<AWavePassItem>()
{
	return AWavePassItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWavePassItem);
AWavePassItem::~AWavePassItem() {}
// End Class AWavePassItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WavePassItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWavePassItem, AWavePassItem::StaticClass, TEXT("AWavePassItem"), &Z_Registration_Info_UClass_AWavePassItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWavePassItem), 1744863742U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WavePassItem_h_1640779961(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WavePassItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_WavePassItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
