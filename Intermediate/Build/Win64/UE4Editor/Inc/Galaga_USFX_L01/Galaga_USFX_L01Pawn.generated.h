// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
class ACapsulaVida;
class ACapsulaArma;
class ACapsulaMotor;
#ifdef GALAGA_USFX_L01_Galaga_USFX_L01Pawn_generated_h
#error "Galaga_USFX_L01Pawn.generated.h already included, missing '#pragma once' in Galaga_USFX_L01Pawn.h"
#endif
#define GALAGA_USFX_L01_Galaga_USFX_L01Pawn_generated_h

#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_SPARSE_DATA
#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execNotifyHit); \
	DECLARE_FUNCTION(execTakeItemVida); \
	DECLARE_FUNCTION(execTakeItemArma); \
	DECLARE_FUNCTION(execTakeItem); \
	DECLARE_FUNCTION(execDropItemVida); \
	DECLARE_FUNCTION(execDropItemArma); \
	DECLARE_FUNCTION(execDropItem);


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNotifyHit); \
	DECLARE_FUNCTION(execTakeItemVida); \
	DECLARE_FUNCTION(execTakeItemArma); \
	DECLARE_FUNCTION(execTakeItem); \
	DECLARE_FUNCTION(execDropItemVida); \
	DECLARE_FUNCTION(execDropItemArma); \
	DECLARE_FUNCTION(execDropItem);


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGalaga_USFX_L01Pawn(); \
	friend struct Z_Construct_UClass_AGalaga_USFX_L01Pawn_Statics; \
public: \
	DECLARE_CLASS(AGalaga_USFX_L01Pawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Galaga_USFX_L01"), NO_API) \
	DECLARE_SERIALIZER(AGalaga_USFX_L01Pawn)


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAGalaga_USFX_L01Pawn(); \
	friend struct Z_Construct_UClass_AGalaga_USFX_L01Pawn_Statics; \
public: \
	DECLARE_CLASS(AGalaga_USFX_L01Pawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Galaga_USFX_L01"), NO_API) \
	DECLARE_SERIALIZER(AGalaga_USFX_L01Pawn)


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGalaga_USFX_L01Pawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGalaga_USFX_L01Pawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGalaga_USFX_L01Pawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGalaga_USFX_L01Pawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGalaga_USFX_L01Pawn(AGalaga_USFX_L01Pawn&&); \
	NO_API AGalaga_USFX_L01Pawn(const AGalaga_USFX_L01Pawn&); \
public:


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGalaga_USFX_L01Pawn(AGalaga_USFX_L01Pawn&&); \
	NO_API AGalaga_USFX_L01Pawn(const AGalaga_USFX_L01Pawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGalaga_USFX_L01Pawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGalaga_USFX_L01Pawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGalaga_USFX_L01Pawn)


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__posicionInicial() { return STRUCT_OFFSET(AGalaga_USFX_L01Pawn, posicionInicial); }


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_18_PROLOG
#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_PRIVATE_PROPERTY_OFFSET \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_SPARSE_DATA \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_RPC_WRAPPERS \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_INCLASS \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_PRIVATE_PROPERTY_OFFSET \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_SPARSE_DATA \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_INCLASS_NO_PURE_DECLS \
	Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GALAGA_USFX_L01_API UClass* StaticClass<class AGalaga_USFX_L01Pawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Galaga_USFX_LAB01_Source_Galaga_USFX_L01_Galaga_USFX_L01Pawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
