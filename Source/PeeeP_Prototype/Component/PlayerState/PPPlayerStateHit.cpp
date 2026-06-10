// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerState/PPPlayerStateHit.h"
#include "Parts/PartsComponent/PPPartsBase.h"

void UPPPlayerStateHit::Enter()
{
	if (OwnerPlayer)
	{

		if (IsValid(OwnerPlayer->GetParts()))
		{
			OwnerPlayer->GetParts()->PlayHitAnimation();
		}
		else
		{
			OwnerPlayer->PlayAnimation(OwnerPlayer->HitAnimMontage);
		}

		// Temp Hit Time
		const float HitDuration = 0.3f;
		GetWorld()->GetTimerManager().SetTimer(HitStateTimerHandle, this, &UPPPlayerStateHit::OnHitFinished, HitDuration, false);
	}
}

void UPPPlayerStateHit::Update(float DeltaTime)
{
}

void UPPPlayerStateHit::Exit()
{
	// Clear Timer
	GetWorld()->GetTimerManager().ClearTimer(HitStateTimerHandle);
}

void UPPPlayerStateHit::OnHitFinished()
{
	if(!OwnerFSM)
	{
		return;
	}

	// Clear Timer
	GetWorld()->GetTimerManager().ClearTimer(HitStateTimerHandle);

	OwnerFSM->ChangeState(EPlayerStateType::Idle);
}
