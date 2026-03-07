#include "Libraries/CSTargetTagRequirementsGameplayEffectComponentExtensions.h"
#include "GameplayEffectComponents/TargetTagsGameplayEffectComponent.h"
#include "UnrealSharpGAS.h"

void UCSTargetTagRequirementsGameplayEffectComponentExtensions::SetAndApplyTargetTagChanges(UTargetTagsGameplayEffectComponent* TagsGameplayEffectComponent, const FGameplayTagContainer& Added, const FGameplayTagContainer& Removed)
{
	if (!IsValid(TagsGameplayEffectComponent))
	{
		UE_LOGFMT(LogUnrealSharpGAS, Warning, "TagsGameplayEffectComponent was null");
		return;
	}
	
	FInheritedTagContainer InheritedTags;

	for (const FGameplayTag& Tag : Added)
	{
		InheritedTags.AddTag(Tag);
	}

	for (const FGameplayTag& Tag : Removed)
	{
		InheritedTags.RemoveTag(Tag);
	}

	TagsGameplayEffectComponent->SetAndApplyTargetTagChanges(InheritedTags);
}
