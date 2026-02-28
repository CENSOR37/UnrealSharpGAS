#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "StructUtils/InstancedStruct.h"
#include "CSGameplayEffectContext.generated.h"

USTRUCT()
struct FCSGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()
	
	// FGameplayEffectContext interface
	virtual UScriptStruct* GetScriptStruct() const override;
	virtual FGameplayEffectContext* Duplicate() const override;
	virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;
	// End of FGameplayEffectContext interface

	UNREALSHARPGAS_API void SetPayload(const FInstancedStruct& InPayload) { Payload = InPayload; }
	UNREALSHARPGAS_API const FInstancedStruct& GetPayload() const { return Payload; }
	
private:
	UPROPERTY()
	FInstancedStruct Payload;
};

template <>
struct TStructOpsTypeTraits<FCSGameplayEffectContext> : TStructOpsTypeTraitsBase2<FCSGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};
