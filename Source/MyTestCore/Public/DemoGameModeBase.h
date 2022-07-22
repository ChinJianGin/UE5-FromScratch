// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYTESTCORE_API ADemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	ADemoGameModeBase(const FObjectInitializer& ObjectInitializer);
	virtual ~ADemoGameModeBase() = default;
	void BeginPlay() override;	
};
