// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/SubscriptorEnemigo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSubscriptorEnemigo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_USubscriptorEnemigo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_USubscriptorEnemigo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void USubscriptorEnemigo::StaticRegisterNativesUSubscriptorEnemigo()
	{
	}
	UClass* Z_Construct_UClass_USubscriptorEnemigo_NoRegister()
	{
		return USubscriptorEnemigo::StaticClass();
	}
	struct Z_Construct_UClass_USubscriptorEnemigo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USubscriptorEnemigo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USubscriptorEnemigo_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "SubscriptorEnemigo.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USubscriptorEnemigo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISubscriptorEnemigo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USubscriptorEnemigo_Statics::ClassParams = {
		&USubscriptorEnemigo::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_USubscriptorEnemigo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USubscriptorEnemigo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USubscriptorEnemigo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USubscriptorEnemigo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USubscriptorEnemigo, 2731766358);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<USubscriptorEnemigo>()
	{
		return USubscriptorEnemigo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USubscriptorEnemigo(Z_Construct_UClass_USubscriptorEnemigo, &USubscriptorEnemigo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("USubscriptorEnemigo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USubscriptorEnemigo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
