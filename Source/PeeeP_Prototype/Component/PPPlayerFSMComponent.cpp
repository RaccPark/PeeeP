// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PPPlayerFSMComponent.h"
#include "Character/PPCharacterPlayer.h"

#include "Component/PlayerState/PPPlayerStateBase.h"
#include "Component/PlayerState/PPPlayerStateIdle.h"
#include "Component/PlayerState/PPPlayerStateWalk.h"
#include "Component/PlayerState/PPPlayerStateRun.h"
//#include "Component/PlayerState/PPPlayerStateJump.h"
//#include "Component/PlayerState/PPPlayerStateFall.h"
#include "Component/PlayerState/PPPlayerStateCharge.h"
#include "Component/PlayerState/PPPlayerStateHit.h"
#include "Component/PlayerState/PPPlayerStateDead.h"

// Sets default values for this component's properties
UPPPlayerFSMComponent::UPPPlayerFSMComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentStateType = EPlayerStateType::None;
	CurrentState = nullptr;
}


// Called when the game starts
void UPPPlayerFSMComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeFSM();
}


// Called every frame
void UPPPlayerFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentState)
	{
		CurrentState->Update(DeltaTime);
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			1,
			0.0f,
			FColor::Green,
			FString::Printf(
				TEXT("State : %s"),
				*GetCurrentStateName()
			)
		);
	}
}

void UPPPlayerFSMComponent::ChangeState(EPlayerStateType NewStateType)
{
	if(CurrentStateType == NewStateType)
	{
		return;
	}

	if (CurrentState)
	{
		CurrentState->Exit();
	}

	UPPPlayerStateBase* NewState = PlayerStateMap.FindRef(NewStateType);
	if (!NewState)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPPPlayerFSMComponent: No state found for type %d"), static_cast<uint8>(NewStateType));
		return;
	}

	CurrentStateType = NewStateType;
	CurrentState = NewState;

	CurrentState->Enter();
}

void UPPPlayerFSMComponent::HandleMove(const FInputActionValue& Value)
{
	if (CurrentState)
	{
		CurrentState->HandleMove(Value);
	}
}

void UPPPlayerFSMComponent::HandleJump()
{
	if (CurrentState)
	{
		CurrentState->HandleJump();
	}
}

void UPPPlayerFSMComponent::HandleRunStart()
{
	if (CurrentState)
	{
		CurrentState->HandleRunStart();
	}
}

void UPPPlayerFSMComponent::HandleRunEnd()
{
	if (CurrentState)
	{
		CurrentState->HandleRunEnd();
	}
}

EPlayerStateType UPPPlayerFSMComponent::GetCurrentStateType() const
{
	return CurrentStateType;
}

FString UPPPlayerFSMComponent::GetCurrentStateName() const
{
	return StaticEnum<EPlayerStateType>()->GetNameStringByValue((int64)CurrentStateType);
}

void UPPPlayerFSMComponent::InitializeFSM()
{
	OwnerPlayer = Cast<APPCharacterPlayer>(GetOwner());
	if (!OwnerPlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPPPlayerFSMComponent: Owner is not APPCharacterPlayer"));
		return;
	}

	CreateStates();
	ChangeState(EPlayerStateType::Idle);
}

void UPPPlayerFSMComponent::CreateStates()
{
	UPPPlayerStateIdle* IdleState		= NewObject<UPPPlayerStateIdle>(this);
	UPPPlayerStateWalk* WalkState		= NewObject<UPPPlayerStateWalk>(this);
	UPPPlayerStateRun* RunState			= NewObject<UPPPlayerStateRun>(this);
	UPPPlayerStateCharge* ChargeState	= NewObject<UPPPlayerStateCharge>(this);
	UPPPlayerStateHit* HitState			= NewObject<UPPPlayerStateHit>(this);
	UPPPlayerStateDead* DeadState		= NewObject<UPPPlayerStateDead>(this);

	PlayerStateMap.Add(EPlayerStateType::Idle, IdleState);
	PlayerStateMap.Add(EPlayerStateType::Walk, WalkState);
	PlayerStateMap.Add(EPlayerStateType::Run, RunState);
	PlayerStateMap.Add(EPlayerStateType::Charge, ChargeState);
	PlayerStateMap.Add(EPlayerStateType::Hit, HitState);
	PlayerStateMap.Add(EPlayerStateType::Dead, DeadState);

	// Initialize stats
	for (auto& State : PlayerStateMap)
	{
		State.Value->Initialize(OwnerPlayer, this);
	}

}

