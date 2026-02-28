#include "Libraries/CSGameplayEffectContextLibrary.h"

#include "AbilitySystemComponent.h"

FGameplayEffectContextHandle UCSGameplayEffectContextLibrary::AddPayLoad(FGameplayEffectContextHandle& EffectContext, const FInstancedStruct& Payload)
{
	if (!EffectContext.IsValid())
	{
		return EffectContext;
	}
	
	FGameplayEffectContext* Context = EffectContext.Get();
	if (!Context->GetScriptStruct()->IsChildOf(FCSGameplayEffectContext::StaticStruct()))
	{
		return EffectContext;
	}
	
	FCSGameplayEffectContext* CSContext = static_cast<FCSGameplayEffectContext*>(Context);
	CSContext->SetPayload(Payload);
	return EffectContext;
}

FInstancedStruct UCSGameplayEffectContextLibrary::GetPayload(const FGameplayEffectContextHandle& EffectContext)
{
	if (!EffectContext.IsValid())
	{
		return FInstancedStruct();
	}
	
	const FGameplayEffectContext* Context = EffectContext.Get();
	if (!Context->GetScriptStruct()->IsChildOf(FCSGameplayEffectContext::StaticStruct()))
	{
		return FInstancedStruct();
	}
	
	const FCSGameplayEffectContext* CSContext = static_cast<const FCSGameplayEffectContext*>(Context);
	return CSContext->GetPayload();
}

FGameplayEffectContextHandle UCSGameplayEffectContextLibrary::CreateWithPayLoad(const UAbilitySystemComponent* OwningComponent, const FInstancedStruct& Payload)
{
	if (!IsValid(OwningComponent))
	{
		return FGameplayEffectContextHandle();
	}
	
	FGameplayEffectContextHandle EffectContext = OwningComponent->MakeEffectContext();
	return AddPayLoad(EffectContext, Payload);
}
