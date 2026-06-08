// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateBase.h"
#include "Character/PPCharacterPlayer.h"
#include "Component/PPPlayerFSMComponent.h"

void UPPPlayerStateBase::Initialize(APPCharacterPlayer* InOwnerPlayer, UPPPlayerFSMComponent* InOwnerFSM)
{
	OwnerPlayer = InOwnerPlayer;
	OwnerFSM = InOwnerFSM;
}

void UPPPlayerStateBase::Enter()
{
}

void UPPPlayerStateBase::Update(float DeltaTime)
{
}

void UPPPlayerStateBase::Exit()
{
}

void UPPPlayerStateBase::HandleMove(const FInputActionValue& Value)
{
}

void UPPPlayerStateBase::HandleJump()
{
}

void UPPPlayerStateBase::HandleRunStart()
{
}

void UPPPlayerStateBase::HandleRunEnd()
{
}
