// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateIdle.h"

void UPPPlayerStateIdle::Enter()
{
	if (OwnerPlayer->IsRunning())
	{
		OwnerPlayer->SetRunning(false);
	}
}

void UPPPlayerStateIdle::Update(float DeltaTime)
{
}

void UPPPlayerStateIdle::Exit()
{
}

void UPPPlayerStateIdle::HandleMove(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	if (Input.IsNearlyZero())
	{
		return;
	}

	OwnerPlayer->ApplyMovement(Input);
	OwnerFSM->ChangeState(EPlayerStateType::Walk);
}

void UPPPlayerStateIdle::HandleJump()
{
}
