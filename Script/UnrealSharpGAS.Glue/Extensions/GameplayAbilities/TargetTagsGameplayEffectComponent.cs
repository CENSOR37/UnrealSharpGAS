using UnrealSharp.GameplayTags;
using UnrealSharp.UnrealSharpGAS;

namespace UnrealSharp.GameplayAbilities;

public partial class UTargetTagsGameplayEffectComponent
{
    public void SetAndApplyTargetTagChanges(FGameplayTagContainer added, FGameplayTagContainer removed)
    {
        UCSTargetTagRequirementsGameplayEffectComponentExtensions.SetAndApplyTargetTagChanges(this, added, removed);
    }
}