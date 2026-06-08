// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Character/PPCharacterPlayer.h"
#include "Component/PPPlayerFSMComponent.h"
#include "PPPlayerStateBase.generated.h"

/**
 * 
 */
UCLASS()
class PEEEP_PROTOTYPE_API UPPPlayerStateBase : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(class APPCharacterPlayer* InOwnerPlayer, class UPPPlayerFSMComponent* InOwnerFSM);

	virtual void Enter();
	virtual void Update(float DeltaTime);
	virtual void Exit();

	virtual void HandleMove(const struct FInputActionValue& Value);
	virtual void HandleJump();

	virtual void HandleRunStart();
	virtual void HandleRunEnd();

protected:
	UPROPERTY()
	TObjectPtr<class APPCharacterPlayer> OwnerPlayer;

	UPROPERTY()
	TObjectPtr<class UPPPlayerFSMComponent> OwnerFSM;
};
