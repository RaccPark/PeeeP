// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PPPlayerFSMComponent.generated.h"


UENUM(BlueprintType)
enum class EPlayerStateType : uint8
{
	None,
	Idle,
	Walk,
	Run,
	Jump,
	Fall,
	Charge,
	Discharge,
	Damaged,
	Dead
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PEEEP_PROTOTYPE_API UPPPlayerFSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPPPlayerFSMComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void ChangeState(EPlayerStateType NewStateType);

	void HandleMove(const struct FInputActionValue& Value);
	void HandleJump();

	void HandleRunStart();
	void HandleRunEnd();

	EPlayerStateType GetCurrentStateType() const;

protected:
	void InitializeFSM();

	void CreateStates();

	UPROPERTY()
	TObjectPtr<class APPCharacterPlayer> OwnerPlayer;

	UPROPERTY()
	TMap<EPlayerStateType, TObjectPtr<class UPPPlayerStateBase>> PlayerStateMap;

	UPROPERTY()
	TObjectPtr<class UPPPlayerStateBase> CurrentState;

	EPlayerStateType CurrentStateType;
};
