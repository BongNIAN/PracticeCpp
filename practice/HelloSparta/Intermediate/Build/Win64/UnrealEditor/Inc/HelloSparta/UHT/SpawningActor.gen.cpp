// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/SpawningActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpawningActor() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
HELLOSPARTA_API UClass* Z_Construct_UClass_AActorToSpawn_NoRegister();
HELLOSPARTA_API UClass* Z_Construct_UClass_AMoveActor();
HELLOSPARTA_API UClass* Z_Construct_UClass_ASpawningActor();
HELLOSPARTA_API UClass* Z_Construct_UClass_ASpawningActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class ASpawningActor
void ASpawningActor::StaticRegisterNativesASpawningActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpawningActor);
UClass* Z_Construct_UClass_ASpawningActor_NoRegister()
{
	return ASpawningActor::StaticClass();
}
struct Z_Construct_UClass_ASpawningActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "SpawningActor.h" },
		{ "ModuleRelativePath", "SpawningActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorToSpawnClass_MetaData[] = {
		{ "Category", "Spawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**Bp\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd */" },
#endif
		{ "ModuleRelativePath", "SpawningActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bp\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ActorToSpawnClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpawningActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpawningActor_Statics::NewProp_ActorToSpawnClass = { "ActorToSpawnClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawningActor, ActorToSpawnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActorToSpawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorToSpawnClass_MetaData), NewProp_ActorToSpawnClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpawningActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawningActor_Statics::NewProp_ActorToSpawnClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawningActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpawningActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AMoveActor,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawningActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpawningActor_Statics::ClassParams = {
	&ASpawningActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASpawningActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpawningActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawningActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpawningActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpawningActor()
{
	if (!Z_Registration_Info_UClass_ASpawningActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpawningActor.OuterSingleton, Z_Construct_UClass_ASpawningActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpawningActor.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<ASpawningActor>()
{
	return ASpawningActor::StaticClass();
}
ASpawningActor::ASpawningActor() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawningActor);
ASpawningActor::~ASpawningActor() {}
// End Class ASpawningActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_SpawningActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpawningActor, ASpawningActor::StaticClass, TEXT("ASpawningActor"), &Z_Registration_Info_UClass_ASpawningActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpawningActor), 2948612335U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_SpawningActor_h_2066035502(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_SpawningActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_SpawningActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
