// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateWalk.h"

void UPPPlayerStateWalk::Enter()
{
	if (OwnerPlayer->IsRunning())
	{
		OwnerPlayer->SetRunning(false);
	}
}

void UPPPlayerStateWalk::Update(float DeltaTime)
{
	if (OwnerPlayer->GetVelocity().SizeSquared() < 1.f)
	{
		OwnerFSM->ChangeState(EPlayerStateType::Idle);
	}
}

void UPPPlayerStateWalk::Exit()
{
}

void UPPPlayerStateWalk::HandleMove(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	OwnerPlayer->ApplyMovement(Input);
}

void UPPPlayerStateWalk::HandleJump()
{
}

void UPPPlayerStateWalk::HandleRunStart()
{
	OwnerFSM->ChangeState(EPlayerStateType::Run);
}

void UPPPlayerStateWalk::HandleChargeStart()
{
	OwnerFSM->ChangeState(EPlayerStateType::Charge);
}
