// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WaveBoomItem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HELLOSPARTA_WaveBoomItem_generated_h
#error "WaveBoomItem.generated.h already included, missing '#pragma once' in WaveBoomItem.h"
#endif
#define HELLOSPARTA_WaveBoomItem_generated_h

#define FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWaveBoomItem(); \
	friend struct Z_Construct_UClass_AWaveBoomItem_Statics; \
public: \
	DECLARE_CLASS(AWaveBoomItem, ABaseItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HelloSparta"), NO_API) \
	DECLARE_SERIALIZER(AWaveBoomItem)


#define FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWaveBoomItem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AWaveBoomItem(AWaveBoomItem&&); \
	AWaveBoomItem(const AWaveBoomItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaveBoomItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaveBoomItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWaveBoomItem) \
	NO_API virtual ~AWaveBoomItem();


#define FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_12_PROLOG
#define FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_15_INCLASS_NO_PURE_DECLS \
	FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HELLOSPARTA_API UClass* StaticClass<class AWaveBoomItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HelloSparta_Source_HelloSparta_Public_WaveBoomItem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
