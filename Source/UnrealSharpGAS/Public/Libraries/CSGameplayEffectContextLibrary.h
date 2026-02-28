#pragma once

#include "CoreMinimal.h"
#include "CSGameplayEffectContext.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSGameplayEffectContextLibrary.generated.h"

UCLASS(DisplayName=GameplayEffectContextLibrary)
class UCSGameplayEffectContextLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(meta = (ScriptMethod))
	static UNREALSHARPGAS_API FGameplayEffectContextHandle AddPayLoad(FGameplayEffectContextHandle& EffectContext, const FInstancedStruct& Payload);
	
	UFUNCTION(meta = (ScriptMethod))
	static UNREALSHARPGAS_API FInstancedStruct GetPayload(const FGameplayEffectContextHandle& EffectContext);
	
	UFUNCTION(meta = (ScriptMethod))
	static UNREALSHARPGAS_API FGameplayEffectContextHandle CreateWithPayLoad(const UAbilitySystemComponent* OwningComponent, const FInstancedStruct& Payload);
};
