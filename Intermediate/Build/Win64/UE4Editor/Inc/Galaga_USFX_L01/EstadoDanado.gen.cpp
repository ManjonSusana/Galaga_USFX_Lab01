// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstadoDanado.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstadoDanado() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstadoDanado_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstadoDanado();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UIEstadoPawn_NoRegister();
// End Cross Module References
	void AEstadoDanado::StaticRegisterNativesAEstadoDanado()
	{
	}
	UClass* Z_Construct_UClass_AEstadoDanado_NoRegister()
	{
		return AEstadoDanado::StaticClass();
	}
	struct Z_Construct_UClass_AEstadoDanado_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstadoDanado_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstadoDanado_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstadoDanado.h" },
		{ "ModuleRelativePath", "EstadoDanado.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstadoDanado_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIEstadoPawn_NoRegister, (int32)VTABLE_OFFSET(AEstadoDanado, IIEstadoPawn), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstadoDanado_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstadoDanado>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstadoDanado_Statics::ClassParams = {
		&AEstadoDanado::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEstadoDanado_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstadoDanado_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstadoDanado()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstadoDanado_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstadoDanado, 1087219108);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstadoDanado>()
	{
		return AEstadoDanado::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstadoDanado(Z_Construct_UClass_AEstadoDanado, &AEstadoDanado::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstadoDanado"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstadoDanado);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
