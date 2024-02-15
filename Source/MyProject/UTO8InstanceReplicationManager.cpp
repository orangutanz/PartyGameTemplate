// Fill out your copyright notice in the Description page of Project Settings.


#include "UTO8InstanceReplicationManager.h"
#include "UTO8PlayerController.h"

// Sets default values
AUTO8InstanceReplicationManager::AUTO8InstanceReplicationManager()
{
	bReplicates = true;
}

bool AUTO8InstanceReplicationManager::GenerateRandomTeamByAmount(int32 Amount, const TArray<AUTO8PlayerController*>& PlayerPCs, TArray<int32>& PlayerTeams)
{
	if (Amount == 0 || Amount == 1 || Amount > 4)
	{
		return false;
	}
	TArray<int> TeamNums;
	int totalPlayers = PlayerPCs.Num();
	PlayerTeams.Reset(totalPlayers);

	int payersPerTeam = totalPlayers / Amount;
	for (int i = 0; i < Amount; ++i)
	{
		for (int j = 0; j < payersPerTeam; ++j)
		{
			TeamNums.Add(i + 1);
			// Example
			// Team[1,1, 2,2]
			// Team[1,1,1,1,1,1, 2,2,2,2,2,2]
			// Team[1,1,1, ,2,2,2, 3,3,3, 4,4,4...]
		}
	}
	int extraTeam = 1;
	while (TeamNums.Num() < totalPlayers)
	{
		TeamNums.Add(extraTeam);
		extraTeam += 1;
	}
	for (int i = 0; i < totalPlayers; ++i)
	{
		int32 RndIdx = FMath::RandRange(int32(0), int32(TeamNums.Num() - 1));
		PlayerTeams.Add(TeamNums[RndIdx]);
		TeamNums.RemoveAtSwap(RndIdx);
	}
	return true;
}

bool AUTO8InstanceReplicationManager::GenerateRandomTeamBySize(int32 Size, const TArray<AUTO8PlayerController*>& PlayerPCs, TArray<int32>& PlayerTeams)
{
	if (Size == 0 || Size == 1 || Size > 5)
	{
		return false;
	}

	TArray<int> TeamNums;
	int totalPlayers = PlayerPCs.Num();
	PlayerTeams.Reset(totalPlayers);
	int amountOfTeams = totalPlayers / Size;
	//int payersPerTeam = totalPlayers / Amount;
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < amountOfTeams; ++j)
		{
			TeamNums.Add(i + 1);
			// Example
			// Team[1,1, 2,2]
			// Team[1,1,1,1,1, 2,2,2,2,2]
			// Team[1,1,1,1, 2,2,2,2, 3,3,3,3, 4,4,4,4...]
		}
	}
	while (TeamNums.Num() < totalPlayers) //  [1,1,1, 2,2,2 ,3,3]
	{
		TeamNums.Add(amountOfTeams + 1);
	}
	for (int i = 0; i < totalPlayers; ++i)
	{
		int32 RndIdx = FMath::RandRange(int32(0), int32(TeamNums.Num() - 1));
		PlayerTeams.Add(TeamNums[RndIdx]);
		TeamNums.RemoveAtSwap(RndIdx);
	}

	return true;
}

void AUTO8InstanceReplicationManager::OnInstancePlayerChange(AUTO8PlayerController* Player, bool isJoining, const FString& targetName, const int64 playerID)
{
	if (isJoining)
	{
		InstancePlayerList.Add(Player);
		Player->mInstanceManager = this;
		OnNotifyPlayerChange.Broadcast(true, targetName, playerID);
	}
	else
	{
		int targetIndex = InstancePlayerList.Remove(Player);
		if (targetIndex == INDEX_NONE) //not removed
		{
			return;
		}
		OnNotifyPlayerChange.Broadcast(false, targetName, playerID);
	}
}


