// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitBox.generated.h"

UENUM(BlueprintType)
enum class EHitboxEnum : uint8
{
	HB_PROXIMITY UMETA(DisplayName = "Proximity"),
	HB_STRIKE    UMETA(DisplayName = "Strike"),
	HB_HURTBOX   UMETA(DisplayName = "HurtBox")
};

UCLASS()
class INFINITY_API AHitBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHitBox();

	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable)
	EHitboxEnum getType();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
	EHitboxEnum hitboxType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox");
	FVector HitboxLocation;

	UPROPERTY(BlueprintReadOnly)
	bool overlappingEnemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
