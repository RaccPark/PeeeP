// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateDead.h"

void UPPPlayerStateDead::Enter()
{
	if (!IsValid(OwnerPlayer))
	{
		return;
	}
	OwnerPlayer->HandleDeath();
}

void UPPPlayerStateDead::Update(float DeltaTime)
{
}

void UPPPlayerStateDead::Exit()
{
}
