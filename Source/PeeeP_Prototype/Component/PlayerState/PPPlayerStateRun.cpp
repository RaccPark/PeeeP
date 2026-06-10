// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateRun.h"

void UPPPlayerStateRun::Enter()
{
	if (!OwnerPlayer->IsRunning())
	{
		OwnerPlayer->SetRunning(true);
	}
}

void UPPPlayerStateRun::Update(float DeltaTime)
{
	if (OwnerPlayer->GetVelocity().SizeSquared() < 1.f)
	{
		OwnerFSM->ChangeState(EPlayerStateType::Idle);
	}
}

void UPPPlayerStateRun::Exit()
{
	OwnerPlayer->SetRunning(false);
}

void UPPPlayerStateRun::HandleMove(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	OwnerPlayer->ApplyMovement(Input);
}

void UPPPlayerStateRun::HandleJump()
{
}

void UPPPlayerStateRun::HandleRunEnd()
{
	OwnerFSM->ChangeState(EPlayerStateType::Walk);
}

void UPPPlayerStateRun::HandleChargeStart()
{
	OwnerFSM->ChangeState(EPlayerStateType::Charge);
}
