// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ProjectileBase.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable)
class ALPHA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION()
	void MoveForward(float v);
	UFUNCTION()
	void MoveRight(float v);
	UFUNCTION()
	void LookUp(float v);
	UFUNCTION()
	void LookRight(float v);
	UFUNCTION()
	void JumpPress();
	UFUNCTION()
	void JumpRelease();
	UFUNCTION()
	void Shoot();
	
	UFUNCTION(BlueprintCallable, Category="Health")
	void Die();

	UFUNCTION(BlueprintCallable, Category="Health")
	float TakeDamage(float damage,
				     const FDamageEvent& dmg_event,
					 AController* dmg_instigator,
					 AActor* dmg_causer) override;
	float TakeDamageTest(float damage);

protected:
	UPROPERTY(EditAnywhere, Category=Projectile)
	TSubclassOf<AProjectileBase> _ProjectileClass;
	
	UPROPERTY(EditAnywhere, Category=Gameplay)
	FVector _MuzzleOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Status)
	float _Health;
};
