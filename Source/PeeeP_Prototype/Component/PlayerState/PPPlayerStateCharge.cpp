// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateCharge.h"

void UPPPlayerStateCharge::Enter()
{
	if (!OwnerPlayer)
	{
		return;
	}
}

void UPPPlayerStateCharge::Update(float DeltaTime)
{
}

void UPPPlayerStateCharge::Exit()
{
}

void UPPPlayerStateCharge::HandleMove(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();

	if (Input.IsNearlyZero())
	{
		return;
	}

	OwnerPlayer->ApplyMovement(Input);
}
