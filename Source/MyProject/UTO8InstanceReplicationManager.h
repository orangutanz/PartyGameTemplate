// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HAL/PlatformTime.h"
#include "Net/UnrealNetwork.h"
#include "Misc/DateTime.h"
#include "UTO8InstanceReplicationManager.generated.h"

class AUTO8PlayerController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnNotifyPlayerChange, bool, isJoining, const FString&, targetName, const int64, playerID);


UCLASS()
class MYPROJECT_API AUTO8InstanceReplicationManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUTO8InstanceReplicationManager();


	// ----------------- Helper Functions ---------------------

	/** Suppoerts 2-4 Team Amount	*/
	UFUNCTION(BlueprintCallable, Category = "UTO8_RepManager")
	bool GenerateRandomTeamByAmount(int32 Amount, const TArray<AUTO8PlayerController*>& PlayerPCs, TArray<int32>& PlayerTeams);
	/** Suppoerts 2-5 Team Size	*/
	UFUNCTION(BlueprintCallable, Category = "UTO8_RepManager")
	bool GenerateRandomTeamBySize(int32 Size, const TArray<AUTO8PlayerController*>& PlayerPCs, TArray<int32>& PlayerTeams);

	// ----------------- Mananger Functions ------------------------
	UFUNCTION()
	void OnInstancePlayerChange(AUTO8PlayerController* Player, bool isJoining, const FString& targetName, const int64 playerID);

	UPROPERTY(BlueprintAssignable)
	FOnNotifyPlayerChange OnNotifyPlayerChange;

	UPROPERTY(BlueprintReadOnly)
	TArray<AUTO8PlayerController*> InstancePlayerList;
	UPROPERTY(BlueprintReadWrite)
	TArray<FName> InstancePlayerNames;
	UPROPERTY(BlueprintReadWrite)
	TArray<int64> InstancePlayerIDs;

};
