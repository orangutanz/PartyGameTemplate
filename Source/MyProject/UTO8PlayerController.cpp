// Fill out your copyright notice in the Description page of Project Settings.


#include "UTO8PlayerController.h"
#include "UTO8InstanceReplicationManager.h"

void AUTO8PlayerController::SERVER_NotifyInstance_PlayerChange_Implementation(AUTO8PlayerController* UTO8PlayerController, AUTO8InstanceReplicationManager* instanceManager, bool isJoining, const FString& targetName, const int64 playerID)
{
	if (IsValid(instanceManager))
	{
		instanceManager->OnInstancePlayerChange(UTO8PlayerController, isJoining, targetName, playerID);
	}
}
