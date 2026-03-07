#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectComponent.h"
#include "CSGameplayEffectComponent.generated.h"

UCLASS()
class UCSGameplayEffectComponent : public UGameplayEffectComponent
{
	GENERATED_BODY()
protected:
	// UGameplayEffectComponent interface
	virtual bool CanGameplayEffectApply(const FActiveGameplayEffectsContainer& ActiveGEContainer, const FGameplayEffectSpec& GESpec) const override;
	virtual bool OnActiveGameplayEffectAdded(FActiveGameplayEffectsContainer& ActiveGEContainer, FActiveGameplayEffect& ActiveGE) const override;
	virtual void OnGameplayEffectExecuted(FActiveGameplayEffectsContainer& ActiveGEContainer, FGameplayEffectSpec& GESpec, FPredictionKey& PredictionKey) const override;
	virtual void OnGameplayEffectApplied(FActiveGameplayEffectsContainer& ActiveGEContainer, FGameplayEffectSpec& GESpec, FPredictionKey& PredictionKey) const override;
	virtual void OnGameplayEffectChanged() override;
	// End of UGameplayEffectComponent interface
	
	UFUNCTION(BlueprintCallable)
	UGameplayEffect* K2_GetOwner() const;
	
	UFUNCTION(BlueprintNativeEvent)
	bool K2_CanGameplayEffectApply(const FGameplayEffectSpec& GESpec) const;
	
	UFUNCTION(BlueprintNativeEvent)
	bool K2_OnActiveGameplayEffectAdded(FActiveGameplayEffect& ActiveGE) const;
	
	UFUNCTION(BlueprintNativeEvent)
	void K2_OnGameplayEffectExecuted(FGameplayEffectSpec& GESpec) const;
	
	UFUNCTION(BlueprintNativeEvent)
	void K2_OnGameplayEffectApplied(FGameplayEffectSpec& GESpec) const;
	
	UFUNCTION(BlueprintNativeEvent)
	void K2_OnGameplayEffectChanged() const;
};
