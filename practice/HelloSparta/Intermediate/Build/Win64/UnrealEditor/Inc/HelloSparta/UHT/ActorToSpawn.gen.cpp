// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/ActorToSpawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorToSpawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
HELLOSPARTA_API UClass* Z_Construct_UClass_AActorToSpawn();
HELLOSPARTA_API UClass* Z_Construct_UClass_AActorToSpawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class AActorToSpawn
void AActorToSpawn::StaticRegisterNativesAActorToSpawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AActorToSpawn);
UClass* Z_Construct_UClass_AActorToSpawn_NoRegister()
{
	return AActorToSpawn::StaticClass();
}
struct Z_Construct_UClass_AActorToSpawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ActorToSpawn.h" },
		{ "ModuleRelativePath", "ActorToSpawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereComp_MetaData[] = {
		{ "Category", "Spawning|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ActorToSpawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComp_MetaData[] = {
		{ "Category", "Spawning|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ActorToSpawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParticleComp_MetaData[] = {
		{ "Category", "Spawning|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ActorToSpawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParticleComp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActorToSpawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorToSpawn_Statics::NewProp_SphereComp = { "SphereComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorToSpawn, SphereComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereComp_MetaData), NewProp_SphereComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorToSpawn_Statics::NewProp_StaticMeshComp = { "StaticMeshComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorToSpawn, StaticMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMeshComp_MetaData), NewProp_StaticMeshComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorToSpawn_Statics::NewProp_ParticleComp = { "ParticleComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorToSpawn, ParticleComp), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParticleComp_MetaData), NewProp_ParticleComp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActorToSpawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorToSpawn_Statics::NewProp_SphereComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorToSpawn_Statics::NewProp_StaticMeshComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorToSpawn_Statics::NewProp_ParticleComp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActorToSpawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AActorToSpawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActorToSpawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AActorToSpawn_Statics::ClassParams = {
	&AActorToSpawn::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AActorToSpawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AActorToSpawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AActorToSpawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AActorToSpawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AActorToSpawn()
{
	if (!Z_Registration_Info_UClass_AActorToSpawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActorToSpawn.OuterSingleton, Z_Construct_UClass_AActorToSpawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AActorToSpawn.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<AActorToSpawn>()
{
	return AActorToSpawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AActorToSpawn);
AActorToSpawn::~AActorToSpawn() {}
// End Class AActorToSpawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_ActorToSpawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActorToSpawn, AActorToSpawn::StaticClass, TEXT("AActorToSpawn"), &Z_Registration_Info_UClass_AActorToSpawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActorToSpawn), 465385793U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_ActorToSpawn_h_2916292583(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_ActorToSpawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_practiceCpp_PracticeCpp_practice_HelloSparta_Source_HelloSparta_ActorToSpawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
