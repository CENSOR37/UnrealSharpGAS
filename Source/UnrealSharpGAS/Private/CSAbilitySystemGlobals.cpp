#include "CSAbilitySystemGlobals.h"
#include "CSGameplayEffectContext.h"

FGameplayEffectContext* UCSAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FCSGameplayEffectContext();
}
