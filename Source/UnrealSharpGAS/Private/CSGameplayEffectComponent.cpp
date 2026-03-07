#include "CSGameplayEffectComponent.h"

bool UCSGameplayEffectComponent::CanGameplayEffectApply(const FActiveGameplayEffectsContainer& ActiveGEContainer,
                                                        const FGameplayEffectSpec& GESpec) const
{
	if (!Super::CanGameplayEffectApply(ActiveGEContainer, GESpec))
	{
		return false;
	}
	
	return K2_CanGameplayEffectApply(GESpec);
}

bool UCSGameplayEffectComponent::OnActiveGameplayEffectAdded(FActiveGameplayEffectsContainer& ActiveGEContainer,
	FActiveGameplayEffect& ActiveGE) const
{
	if (!Super::OnActiveGameplayEffectAdded(ActiveGEContainer, ActiveGE))
	{
		return false;
	}
	
	return K2_OnActiveGameplayEffectAdded(ActiveGE);
}

void UCSGameplayEffectComponent::OnGameplayEffectExecuted(FActiveGameplayEffectsContainer& ActiveGEContainer, FGameplayEffectSpec& GESpec, FPredictionKey& PredictionKey) const
{
	Super::OnGameplayEffectExecuted(ActiveGEContainer, GESpec, PredictionKey);
	K2_OnGameplayEffectExecuted(GESpec);
}

void UCSGameplayEffectComponent::OnGameplayEffectApplied(FActiveGameplayEffectsContainer& ActiveGEContainer, FGameplayEffectSpec& GESpec, FPredictionKey& PredictionKey) const
{
	Super::OnGameplayEffectApplied(ActiveGEContainer, GESpec, PredictionKey);
	K2_OnGameplayEffectApplied(GESpec);
}

void UCSGameplayEffectComponent::OnGameplayEffectChanged()
{
	Super::OnGameplayEffectChanged();
	K2_OnGameplayEffectChanged();
}

UGameplayEffect* UCSGameplayEffectComponent::K2_GetOwner() const
{
	return GetOwner();
}

bool UCSGameplayEffectComponent::K2_CanGameplayEffectApply_Implementation(const FGameplayEffectSpec& GESpec) const
{
	return true;
}

bool UCSGameplayEffectComponent::K2_OnActiveGameplayEffectAdded_Implementation(FActiveGameplayEffect& ActiveGE) const
{
	return true;
}

void UCSGameplayEffectComponent::K2_OnGameplayEffectExecuted_Implementation(FGameplayEffectSpec& GESpec) const
{
	
}

void UCSGameplayEffectComponent::K2_OnGameplayEffectApplied_Implementation(FGameplayEffectSpec& GESpec) const
{
	
}

void UCSGameplayEffectComponent::K2_OnGameplayEffectChanged_Implementation() const
{
	
}
