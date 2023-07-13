// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SugiyamaG_ObstacleRu/SugiyamaG_ObstacleRuGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSugiyamaG_ObstacleRuGameModeBase() {}
// Cross Module References
	SUGIYAMAG_OBSTACLERU_API UClass* Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_NoRegister();
	SUGIYAMAG_OBSTACLERU_API UClass* Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_SugiyamaG_ObstacleRu();
// End Cross Module References
	void ASugiyamaG_ObstacleRuGameModeBase::StaticRegisterNativesASugiyamaG_ObstacleRuGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_NoRegister()
	{
		return ASugiyamaG_ObstacleRuGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SugiyamaG_ObstacleRu,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SugiyamaG_ObstacleRuGameModeBase.h" },
		{ "ModuleRelativePath", "SugiyamaG_ObstacleRuGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASugiyamaG_ObstacleRuGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::ClassParams = {
		&ASugiyamaG_ObstacleRuGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASugiyamaG_ObstacleRuGameModeBase, 3337821415);
	template<> SUGIYAMAG_OBSTACLERU_API UClass* StaticClass<ASugiyamaG_ObstacleRuGameModeBase>()
	{
		return ASugiyamaG_ObstacleRuGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASugiyamaG_ObstacleRuGameModeBase(Z_Construct_UClass_ASugiyamaG_ObstacleRuGameModeBase, &ASugiyamaG_ObstacleRuGameModeBase::StaticClass, TEXT("/Script/SugiyamaG_ObstacleRu"), TEXT("ASugiyamaG_ObstacleRuGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASugiyamaG_ObstacleRuGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
