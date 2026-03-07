#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSTargetTagRequirementsGameplayEffectComponentExtensions.generated.h"

class UTargetTagsGameplayEffectComponent;

UCLASS(meta = (InternalType))
class UCSTargetTagRequirementsGameplayEffectComponentExtensions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(meta = (ScriptMethod))
	static void SetAndApplyTargetTagChanges(UTargetTagsGameplayEffectComponent* TagsGameplayEffectComponent, const FGameplayTagContainer& Added, const FGameplayTagContainer& Removed);
};
