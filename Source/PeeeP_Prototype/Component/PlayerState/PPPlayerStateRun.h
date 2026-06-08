// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/PlayerState/PPPlayerStateBase.h"
#include "PPPlayerStateRun.generated.h"

/**
 * 
 */
UCLASS()
class PEEEP_PROTOTYPE_API UPPPlayerStateRun : public UPPPlayerStateBase
{
	GENERATED_BODY()
	
public:
	virtual void Enter() override;
	virtual void Update(float DeltaTime) override;
	virtual void Exit() override;
	virtual void HandleMove(const struct FInputActionValue& Value) override;
	virtual void HandleJump() override;

	virtual void HandleRunEnd() override;
};
