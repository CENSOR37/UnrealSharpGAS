#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "CSAbilitySystemGlobals.generated.h"

UCLASS()
class UCSAbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()
public:
	// UAbilitySystemGlobals interface
	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
	// End of UAbilitySystemGlobals interface
};
