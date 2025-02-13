// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/LotatedActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLotatedActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
HELLOSPARTA_API UClass* Z_Construct_UClass_ALotatedActor();
HELLOSPARTA_API UClass* Z_Construct_UClass_ALotatedActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class ALotatedActor
void ALotatedActor::StaticRegisterNativesALotatedActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALotatedActor);
UClass* Z_Construct_UClass_ALotatedActor_NoRegister()
{
	return ALotatedActor::StaticClass();
}
struct Z_Construct_UClass_ALotatedActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "LotatedActor.h" },
		{ "ModuleRelativePath", "LotatedActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Item|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**Set Reflection*/" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LotatedActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set Reflection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComp_MetaData[] = {
		{ "Category", "Item|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**Set Reflection*/" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LotatedActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set Reflection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "Item|Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**Set Reflection*/" },
#endif
		{ "ModuleRelativePath", "LotatedActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set Reflection" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALotatedActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALotatedActor_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALotatedActor, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALotatedActor_Statics::NewProp_StaticMeshComp = { "StaticMeshComp", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALotatedActor, StaticMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMeshComp_MetaData), NewProp_StaticMeshComp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ALotatedActor_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALotatedActor, RotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSpeed_MetaData), NewProp_RotationSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALotatedActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALotatedActor_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALotatedActor_Statics::NewProp_StaticMeshComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALotatedActor_Statics::NewProp_RotationSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALotatedActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ALotatedActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALotatedActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALotatedActor_Statics::ClassParams = {
	&ALotatedActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ALotatedActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ALotatedActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALotatedActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ALotatedActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALotatedActor()
{
	if (!Z_Registration_Info_UClass_ALotatedActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALotatedActor.OuterSingleton, Z_Construct_UClass_ALotatedActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALotatedActor.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<ALotatedActor>()
{
	return ALotatedActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALotatedActor);
ALotatedActor::~ALotatedActor() {}
// End Class ALotatedActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_LotatedActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALotatedActor, ALotatedActor::StaticClass, TEXT("ALotatedActor"), &Z_Registration_Info_UClass_ALotatedActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALotatedActor), 2623671707U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_LotatedActor_h_3262791986(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_LotatedActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_LotatedActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
