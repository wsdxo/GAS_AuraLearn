// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

#include "AbilitiesSystem/AuraAbilitySystemComponent.h"
#include "AbilitiesSystem/AuraAttributeSet.h"


AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent=CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet=CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(180.f);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
