// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UTO8Character.generated.h"

UCLASS()
class MYPROJECT_API AUTO8Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUTO8Character();

public:	
	UPROPERTY(BlueprintReadWrite)
	FString PlayerName;
	UPROPERTY(BlueprintReadWrite)
	int64 PlayerID;

};
