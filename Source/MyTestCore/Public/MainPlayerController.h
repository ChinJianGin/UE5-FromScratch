// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYTESTCORE_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
		AMainPlayerController(const FObjectInitializer& ObjectInitializer);
		virtual ~AMainPlayerController() = default;


	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ACameraActor> DefaultCamera;

		virtual void BeginPlay() override;

	
};
