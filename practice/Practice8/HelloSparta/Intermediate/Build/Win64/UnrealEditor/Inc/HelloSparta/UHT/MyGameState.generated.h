// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyGameState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HELLOSPARTA_MyGameState_generated_h
#error "MyGameState.generated.h already included, missing '#pragma once' in MyGameState.h"
#endif
#define HELLOSPARTA_MyGameState_generated_h

#define FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnGameOver); \
	DECLARE_FUNCTION(execAddScore); \
	DECLARE_FUNCTION(execGetScore);


#define FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyGameState(); \
	friend struct Z_Construct_UClass_AMyGameState_Statics; \
public: \
	DECLARE_CLASS(AMyGameState, AGameState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HelloSparta"), NO_API) \
	DECLARE_SERIALIZER(AMyGameState)


#define FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyGameState(AMyGameState&&); \
	AMyGameState(const AMyGameState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyGameState) \
	NO_API virtual ~AMyGameState();


#define FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_11_PROLOG
#define FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_INCLASS_NO_PURE_DECLS \
	FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HELLOSPARTA_API UClass* StaticClass<class AMyGameState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HelloSparta_Source_HelloSparta_Public_MyGameState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
