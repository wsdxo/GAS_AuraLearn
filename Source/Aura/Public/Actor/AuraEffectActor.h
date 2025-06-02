// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActiveGameplayEffectHandle.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;
class USphereComponent;

UENUM()
enum class EEffectApplicationPolicy
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	NotApply,
};

UENUM()
enum class EEffectRemovalPolicy
{
	RemoveOnEndOverlap,
	NotRemove,
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void ApplyEffectToTarget(AActor* TargetActor,TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor*TargetActor);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	bool bDestroyOnEffectRemoval=false;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	EEffectApplicationPolicy InstantEffectApplicationPolicy=EEffectApplicationPolicy::NotApply;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	EEffectApplicationPolicy DurationEffectApplicationPolicy=EEffectApplicationPolicy::NotApply;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	TSubclassOf<UGameplayEffect> InfiniteGameplayeffectClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy=EEffectApplicationPolicy::NotApply;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy=EEffectRemovalPolicy::RemoveOnEndOverlap;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effect")
	float ActorLevel=1.f;
	
	TMap<FActiveGameplayEffectHandle,UAbilitySystemComponent*>ActiveEffectHandles;
private:

};
