// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HELLOWORLD_MyActor_generated_h
#error "MyActor.generated.h already included, missing '#pragma once' in MyActor.h"
#endif
#define HELLOWORLD_MyActor_generated_h

#define FID_unrealPractice_helloworld_Source_helloworld_MyActor_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyActor(); \
	friend struct Z_Construct_UClass_AMyActor_Statics; \
public: \
	DECLARE_CLASS(AMyActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/helloworld"), NO_API) \
	DECLARE_SERIALIZER(AMyActor)


#define FID_unrealPractice_helloworld_Source_helloworld_MyActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyActor(AMyActor&&); \
	AMyActor(const AMyActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyActor) \
	NO_API virtual ~AMyActor();


#define FID_unrealPractice_helloworld_Source_helloworld_MyActor_h_11_PROLOG
#define FID_unrealPractice_helloworld_Source_helloworld_MyActor_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_unrealPractice_helloworld_Source_helloworld_MyActor_h_14_INCLASS_NO_PURE_DECLS \
	FID_unrealPractice_helloworld_Source_helloworld_MyActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HELLOWORLD_API UClass* StaticClass<class AMyActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_unrealPractice_helloworld_Source_helloworld_MyActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS