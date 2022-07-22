// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoGameModeBase.h"


ADemoGameModeBase::ADemoGameModeBase(const FObjectInitializer& ObjectInitializer)
{

}

void ADemoGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Begin play"));
}