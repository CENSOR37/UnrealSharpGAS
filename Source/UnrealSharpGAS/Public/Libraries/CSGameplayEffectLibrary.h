#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSGameplayEffectLibrary.generated.h"

UCLASS(meta = (InternalType))
class UCSGameplayEffectLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(meta=(ScriptMethod))
	static bool IsValidGameplayEffectHandle(const FActiveGameplayEffectHandle& Handle);
	
	UFUNCTION(meta=(ScriptMethod, ComponentClass = "/Script/GameplayAbilities.GameplayEffectComponent", DeterminesOutputType = "ComponentClass"))
	static UGameplayEffectComponent* K2_FindOrAddComponent(UGameplayEffect* GameplayEffect, TSubclassOf<UGameplayEffectComponent> ComponentClass, FName ComponentName);
private:
	template<typename T>
	T* FindOrAddComponent(UGameplayEffect* GameplayEffect, FName ComponentName = NAME_None)
	{
		return K2_FindOrAddComponent(GameplayEffect, T::StaticClass(), ComponentName);
	}
};
