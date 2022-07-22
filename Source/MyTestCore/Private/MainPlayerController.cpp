// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AMainPlayerController::AMainPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){

}

void AMainPlayerController::BeginPlay(){
    Super::BeginPlay();

    AActor* _default_camera = UGameplayStatics::GetActorOfClass(this->GetWorld(), DefaultCamera);

    this->SetViewTarget(_default_camera);
}