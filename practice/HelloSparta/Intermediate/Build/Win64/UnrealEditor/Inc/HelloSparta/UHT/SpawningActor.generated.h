// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpawningActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HELLOSPARTA_SpawningActor_generated_h
#error "SpawningActor.generated.h already included, missing '#pragma once' in SpawningActor.h"
#endif
#define HELLOSPARTA_SpawningActor_generated_h

#define FID_HelloSparta_Source_HelloSparta_SpawningActor_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpawningActor(); \
	friend struct Z_Construct_UClass_ASpawningActor_Statics; \
public: \
	DECLARE_CLASS(ASpawningActor, AMoveActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HelloSparta"), NO_API) \
	DECLARE_SERIALIZER(ASpawningActor)


#define FID_HelloSparta_Source_HelloSparta_SpawningActor_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpawningActor(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASpawningActor(ASpawningActor&&); \
	ASpawningActor(const ASpawningActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpawningActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpawningActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpawningActor) \
	NO_API virtual ~ASpawningActor();


#define FID_HelloSparta_Source_HelloSparta_SpawningActor_h_12_PROLOG
#define FID_HelloSparta_Source_HelloSparta_SpawningActor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HelloSparta_Source_HelloSparta_SpawningActor_h_15_INCLASS_NO_PURE_DECLS \
	FID_HelloSparta_Source_HelloSparta_SpawningActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HELLOSPARTA_API UClass* StaticClass<class ASpawningActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HelloSparta_Source_HelloSparta_SpawningActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
