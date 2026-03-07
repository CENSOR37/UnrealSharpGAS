using UnrealSharp.Core;
using UnrealSharp.UnrealSharpGAS;

namespace UnrealSharp.GameplayAbilities;

public partial class UGameplayEffect
{
    public T FindOrAddComponent<T>(FName componentName) where T : UGameplayEffectComponent
    {
        return UCSGameplayEffectLibrary.FindOrAddComponent<T>(this, componentName);
    }
    
    public T FindOrAddComponent<T>(TSubclassOf<T> componentClass, FName componentName) where T : UGameplayEffectComponent
    {
        return UCSGameplayEffectLibrary.FindOrAddComponent(this, componentClass, componentName);
    }
}