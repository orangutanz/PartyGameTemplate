// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UTO8PlayerController.generated.h"

class AUTO8Character;

/**
 * 
 */
UCLASS()
class MYPROJECT_API AUTO8PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	// Called by Clients
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void SERVER_NotifyInstance_PlayerChange(class AUTO8PlayerController* UTO8PlayerController, class AUTO8InstanceReplicationManager* instanceManager, bool isJoining, const FString& targetName, const int64 playerID);


public:
	UPROPERTY(BlueprintReadWrite)
	AUTO8InstanceReplicationManager* mInstanceManager;
};
