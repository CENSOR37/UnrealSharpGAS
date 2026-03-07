#include "Libraries/CSGameplayEffectLibrary.h"
#include <GameplayEffectComponents/AdditionalEffectsGameplayEffectComponent.h>
#include <GameplayEffectComponents/AssetTagsGameplayEffectComponent.h>

#include "UnrealSharpGAS.h"

bool UCSGameplayEffectLibrary::IsValidGameplayEffectHandle(const FActiveGameplayEffectHandle& Handle)
{
	return Handle.IsValid();
}

UGameplayEffectComponent* UCSGameplayEffectLibrary::K2_FindOrAddComponent(UGameplayEffect* GameplayEffect, TSubclassOf<UGameplayEffectComponent> ComponentClass, FName ComponentName)
{
	if (!IsValid(GameplayEffect))
	{
		UE_LOGFMT(LogUnrealSharpGAS, Warning, "GameplayEffect was null");
		return nullptr;
	}
	
	static FArrayProperty* ArrayProperty = FindFProperty<FArrayProperty>(UGameplayEffect::StaticClass(), TEXT("GEComponents"));
	TArray<TObjectPtr<UGameplayEffectComponent>>* Components = ArrayProperty->ContainerPtrToValuePtr<TArray<TObjectPtr<UGameplayEffectComponent>>>(GameplayEffect);
	
	UGameplayEffectComponent* FoundComponent = nullptr;
	for (UGameplayEffectComponent* Component : *Components)
	{
		if (Component->GetClass() != ComponentClass || Component->GetFName() != ComponentName)
		{
			continue;
		}
		
		FoundComponent = Component;
		break;
	}
	
	if (!IsValid(FoundComponent))
	{
		FoundComponent = NewObject<UGameplayEffectComponent>(GameplayEffect, ComponentClass, ComponentName);
		Components->Add(FoundComponent);
	}
	
	return FoundComponent;
}
