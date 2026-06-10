// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PlayerState/PPPlayerStateBase.h"
#include "PPPlayerStateHit.generated.h"

/**
 * 
 */
UCLASS()
class PEEEP_PROTOTYPE_API UPPPlayerStateHit : public UPPPlayerStateBase
{
	GENERATED_BODY()
	
public:
	virtual void Enter() override;
	virtual void Update(float DeltaTime) override;
	virtual void Exit() override;

protected:
	FTimerHandle HitStateTimerHandle;

	void OnHitFinished();
};
