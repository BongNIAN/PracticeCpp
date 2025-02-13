// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UUserWidget;
#ifdef HELLOSPARTA_MyPlayerController_generated_h
#error "MyPlayerController.generated.h already included, missing '#pragma once' in MyPlayerController.h"
#endif
#define HELLOSPARTA_MyPlayerController_generated_h

#define FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStartGame); \
	DECLARE_FUNCTION(execShowMainMenu); \
	DECLARE_FUNCTION(execShowGameHUD); \
	DECLARE_FUNCTION(execGetHUDWidget);


#define FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPlayerController(); \
	friend struct Z_Construct_UClass_AMyPlayerController_Statics; \
public: \
	DECLARE_CLASS(AMyPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HelloSparta"), NO_API) \
	DECLARE_SERIALIZER(AMyPlayerController)


#define FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyPlayerController(AMyPlayerController&&); \
	AMyPlayerController(const AMyPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPlayerController) \
	NO_API virtual ~AMyPlayerController();


#define FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_13_PROLOG
#define FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_INCLASS_NO_PURE_DECLS \
	FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HELLOSPARTA_API UClass* StaticClass<class AMyPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HelloSparta_Source_HelloSparta_Public_MyPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
