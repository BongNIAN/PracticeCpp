// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloSparta/Public/MyGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
HELLOSPARTA_API UClass* Z_Construct_UClass_UMyGameInstance();
HELLOSPARTA_API UClass* Z_Construct_UClass_UMyGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_HelloSparta();
// End Cross Module References

// Begin Class UMyGameInstance Function AddToScore
struct Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics
{
	struct MyGameInstance_eventAddToScore_Parms
	{
		int32 Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventAddToScore_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "AddToScore", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::MyGameInstance_eventAddToScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::MyGameInstance_eventAddToScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_AddToScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_AddToScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execAddToScore)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddToScore(Z_Param_Amount);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function AddToScore

// Begin Class UMyGameInstance Function GetRemainingBuffTime
struct Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics
{
	struct MyGameInstance_eventGetRemainingBuffTime_Parms
	{
		float CurrentTime;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::NewProp_CurrentTime = { "CurrentTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventGetRemainingBuffTime_Parms, CurrentTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventGetRemainingBuffTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::NewProp_CurrentTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "GetRemainingBuffTime", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::MyGameInstance_eventGetRemainingBuffTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::MyGameInstance_eventGetRemainingBuffTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execGetRemainingBuffTime)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CurrentTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetRemainingBuffTime(Z_Param_CurrentTime);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function GetRemainingBuffTime

// Begin Class UMyGameInstance Function GetRemainingDebuffTime
struct Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics
{
	struct MyGameInstance_eventGetRemainingDebuffTime_Parms
	{
		float CurrentTime;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::NewProp_CurrentTime = { "CurrentTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventGetRemainingDebuffTime_Parms, CurrentTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventGetRemainingDebuffTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::NewProp_CurrentTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "GetRemainingDebuffTime", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::MyGameInstance_eventGetRemainingDebuffTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::MyGameInstance_eventGetRemainingDebuffTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execGetRemainingDebuffTime)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CurrentTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetRemainingDebuffTime(Z_Param_CurrentTime);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function GetRemainingDebuffTime

// Begin Class UMyGameInstance Function LoadedBuffDuration
struct Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics
{
	struct MyGameInstance_eventLoadedBuffDuration_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventLoadedBuffDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "LoadedBuffDuration", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::MyGameInstance_eventLoadedBuffDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::MyGameInstance_eventLoadedBuffDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execLoadedBuffDuration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->LoadedBuffDuration();
	P_NATIVE_END;
}
// End Class UMyGameInstance Function LoadedBuffDuration

// Begin Class UMyGameInstance Function LoadedDebuffDuration
struct Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics
{
	struct MyGameInstance_eventLoadedDebuffDuration_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventLoadedDebuffDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "LoadedDebuffDuration", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::MyGameInstance_eventLoadedDebuffDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::MyGameInstance_eventLoadedDebuffDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execLoadedDebuffDuration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->LoadedDebuffDuration();
	P_NATIVE_END;
}
// End Class UMyGameInstance Function LoadedDebuffDuration

// Begin Class UMyGameInstance Function OnGameOverSetDebuff
struct Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics
{
	struct MyGameInstance_eventOnGameOverSetDebuff_Parms
	{
		float SetDebuffStartTime;
		float SetDebuffTotalDuration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SetDebuffStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SetDebuffTotalDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::NewProp_SetDebuffStartTime = { "SetDebuffStartTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventOnGameOverSetDebuff_Parms, SetDebuffStartTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::NewProp_SetDebuffTotalDuration = { "SetDebuffTotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventOnGameOverSetDebuff_Parms, SetDebuffTotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::NewProp_SetDebuffStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::NewProp_SetDebuffTotalDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "OnGameOverSetDebuff", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::MyGameInstance_eventOnGameOverSetDebuff_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::MyGameInstance_eventOnGameOverSetDebuff_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execOnGameOverSetDebuff)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SetDebuffStartTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SetDebuffTotalDuration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGameOverSetDebuff(Z_Param_SetDebuffStartTime,Z_Param_SetDebuffTotalDuration);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function OnGameOverSetDebuff

// Begin Class UMyGameInstance Function OnGameOverSetSpeed
struct Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics
{
	struct MyGameInstance_eventOnGameOverSetSpeed_Parms
	{
		float SetBuffStartTime;
		float SetBuffTotalDuration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SetBuffStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SetBuffTotalDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::NewProp_SetBuffStartTime = { "SetBuffStartTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventOnGameOverSetSpeed_Parms, SetBuffStartTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::NewProp_SetBuffTotalDuration = { "SetBuffTotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventOnGameOverSetSpeed_Parms, SetBuffTotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::NewProp_SetBuffStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::NewProp_SetBuffTotalDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "OnGameOverSetSpeed", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::MyGameInstance_eventOnGameOverSetSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::MyGameInstance_eventOnGameOverSetSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execOnGameOverSetSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SetBuffStartTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SetBuffTotalDuration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGameOverSetSpeed(Z_Param_SetBuffStartTime,Z_Param_SetBuffTotalDuration);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function OnGameOverSetSpeed

// Begin Class UMyGameInstance Function SavedBuffDuration
struct Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics
{
	struct MyGameInstance_eventSavedBuffDuration_Parms
	{
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventSavedBuffDuration_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "SavedBuffDuration", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::MyGameInstance_eventSavedBuffDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::MyGameInstance_eventSavedBuffDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execSavedBuffDuration)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SavedBuffDuration(Z_Param_Duration);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function SavedBuffDuration

// Begin Class UMyGameInstance Function SavedDebuffDuration
struct Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics
{
	struct MyGameInstance_eventSavedDebuffDuration_Parms
	{
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventSavedDebuffDuration_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "SavedDebuffDuration", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::MyGameInstance_eventSavedDebuffDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::MyGameInstance_eventSavedDebuffDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execSavedDebuffDuration)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SavedDebuffDuration(Z_Param_Duration);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function SavedDebuffDuration

// Begin Class UMyGameInstance Function SetBuffInformation
struct Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics
{
	struct MyGameInstance_eventSetBuffInformation_Parms
	{
		float InStartTime;
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::NewProp_InStartTime = { "InStartTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventSetBuffInformation_Parms, InStartTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventSetBuffInformation_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::NewProp_InStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "SetBuffInformation", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::MyGameInstance_eventSetBuffInformation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::MyGameInstance_eventSetBuffInformation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_SetBuffInformation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_SetBuffInformation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execSetBuffInformation)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InStartTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBuffInformation(Z_Param_InStartTime,Z_Param_Duration);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function SetBuffInformation

// Begin Class UMyGameInstance Function SetDebuffInformation
struct Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics
{
	struct MyGameInstance_eventSetDebuffInformation_Parms
	{
		float InStartTime;
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::NewProp_InStartTime = { "InStartTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventSetDebuffInformation_Parms, InStartTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameInstance_eventSetDebuffInformation_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::NewProp_InStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyGameInstance, nullptr, "SetDebuffInformation", nullptr, nullptr, Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::MyGameInstance_eventSetDebuffInformation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::MyGameInstance_eventSetDebuffInformation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyGameInstance::execSetDebuffInformation)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InStartTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDebuffInformation(Z_Param_InStartTime,Z_Param_Duration);
	P_NATIVE_END;
}
// End Class UMyGameInstance Function SetDebuffInformation

// Begin Class UMyGameInstance
void UMyGameInstance::StaticRegisterNativesUMyGameInstance()
{
	UClass* Class = UMyGameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddToScore", &UMyGameInstance::execAddToScore },
		{ "GetRemainingBuffTime", &UMyGameInstance::execGetRemainingBuffTime },
		{ "GetRemainingDebuffTime", &UMyGameInstance::execGetRemainingDebuffTime },
		{ "LoadedBuffDuration", &UMyGameInstance::execLoadedBuffDuration },
		{ "LoadedDebuffDuration", &UMyGameInstance::execLoadedDebuffDuration },
		{ "OnGameOverSetDebuff", &UMyGameInstance::execOnGameOverSetDebuff },
		{ "OnGameOverSetSpeed", &UMyGameInstance::execOnGameOverSetSpeed },
		{ "SavedBuffDuration", &UMyGameInstance::execSavedBuffDuration },
		{ "SavedDebuffDuration", &UMyGameInstance::execSavedDebuffDuration },
		{ "SetBuffInformation", &UMyGameInstance::execSetBuffInformation },
		{ "SetDebuffInformation", &UMyGameInstance::execSetDebuffInformation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyGameInstance);
UClass* Z_Construct_UClass_UMyGameInstance_NoRegister()
{
	return UMyGameInstance::StaticClass();
}
struct Z_Construct_UClass_UMyGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyGameInstance.h" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalScore_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLevelIndex_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffTotalDuration_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffTotalDurationMax_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffStartTime_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebuffTotalDuration_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebuffTotalDurationMax_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebuffStartTime_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedBuffTime_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedDebuffTime_MetaData[] = {
		{ "Category", "Buff" },
		{ "ModuleRelativePath", "Public/MyGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalScore;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentLevelIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffTotalDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffTotalDurationMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebuffTotalDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebuffTotalDurationMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebuffStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedBuffTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SavedDebuffTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyGameInstance_AddToScore, "AddToScore" }, // 592497686
		{ &Z_Construct_UFunction_UMyGameInstance_GetRemainingBuffTime, "GetRemainingBuffTime" }, // 524647100
		{ &Z_Construct_UFunction_UMyGameInstance_GetRemainingDebuffTime, "GetRemainingDebuffTime" }, // 1303720396
		{ &Z_Construct_UFunction_UMyGameInstance_LoadedBuffDuration, "LoadedBuffDuration" }, // 1573244617
		{ &Z_Construct_UFunction_UMyGameInstance_LoadedDebuffDuration, "LoadedDebuffDuration" }, // 4040304770
		{ &Z_Construct_UFunction_UMyGameInstance_OnGameOverSetDebuff, "OnGameOverSetDebuff" }, // 559664396
		{ &Z_Construct_UFunction_UMyGameInstance_OnGameOverSetSpeed, "OnGameOverSetSpeed" }, // 1312245944
		{ &Z_Construct_UFunction_UMyGameInstance_SavedBuffDuration, "SavedBuffDuration" }, // 2220694013
		{ &Z_Construct_UFunction_UMyGameInstance_SavedDebuffDuration, "SavedDebuffDuration" }, // 1595144166
		{ &Z_Construct_UFunction_UMyGameInstance_SetBuffInformation, "SetBuffInformation" }, // 15568145
		{ &Z_Construct_UFunction_UMyGameInstance_SetDebuffInformation, "SetDebuffInformation" }, // 843283237
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_TotalScore = { "TotalScore", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, TotalScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalScore_MetaData), NewProp_TotalScore_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_CurrentLevelIndex = { "CurrentLevelIndex", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, CurrentLevelIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLevelIndex_MetaData), NewProp_CurrentLevelIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_BuffTotalDuration = { "BuffTotalDuration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, BuffTotalDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffTotalDuration_MetaData), NewProp_BuffTotalDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_BuffTotalDurationMax = { "BuffTotalDurationMax", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, BuffTotalDurationMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffTotalDurationMax_MetaData), NewProp_BuffTotalDurationMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_BuffStartTime = { "BuffStartTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, BuffStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffStartTime_MetaData), NewProp_BuffStartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_DebuffTotalDuration = { "DebuffTotalDuration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, DebuffTotalDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebuffTotalDuration_MetaData), NewProp_DebuffTotalDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_DebuffTotalDurationMax = { "DebuffTotalDurationMax", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, DebuffTotalDurationMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebuffTotalDurationMax_MetaData), NewProp_DebuffTotalDurationMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_DebuffStartTime = { "DebuffStartTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, DebuffStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebuffStartTime_MetaData), NewProp_DebuffStartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_SavedBuffTime = { "SavedBuffTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, SavedBuffTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedBuffTime_MetaData), NewProp_SavedBuffTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_SavedDebuffTime = { "SavedDebuffTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, SavedDebuffTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedDebuffTime_MetaData), NewProp_SavedDebuffTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_TotalScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_CurrentLevelIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_BuffTotalDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_BuffTotalDurationMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_BuffStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_DebuffTotalDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_DebuffTotalDurationMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_DebuffStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_SavedBuffTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_SavedDebuffTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_HelloSparta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyGameInstance_Statics::ClassParams = {
	&UMyGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMyGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyGameInstance()
{
	if (!Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton, Z_Construct_UClass_UMyGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton;
}
template<> HELLOSPARTA_API UClass* StaticClass<UMyGameInstance>()
{
	return UMyGameInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyGameInstance);
UMyGameInstance::~UMyGameInstance() {}
// End Class UMyGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_MyGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyGameInstance, UMyGameInstance::StaticClass, TEXT("UMyGameInstance"), &Z_Registration_Info_UClass_UMyGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyGameInstance), 1422704624U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_MyGameInstance_h_3937180161(TEXT("/Script/HelloSparta"),
	Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_MyGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloSparta_Source_HelloSparta_Public_MyGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
