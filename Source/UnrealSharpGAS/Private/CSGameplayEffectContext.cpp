#include "CSGameplayEffectContext.h"

UScriptStruct* FCSGameplayEffectContext::GetScriptStruct() const
{
	return StaticStruct();
}

FGameplayEffectContext* FCSGameplayEffectContext::Duplicate() const
{
	FCSGameplayEffectContext* Context = static_cast<FCSGameplayEffectContext*>(FGameplayEffectContext::Duplicate());
	Context->Payload = Payload;
	return Context;
}

bool FCSGameplayEffectContext::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
{
	bool Success = true;
	FGameplayEffectContext::NetSerialize(Ar, Map, Success);
	Payload.NetSerialize(Ar, Map, Success);
	
	bOutSuccess = Success;
	return bOutSuccess;
}
