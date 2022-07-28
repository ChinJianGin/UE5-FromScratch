// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPawn.h"

// Sets default values
AMainPawn::AMainPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));

	PlayerMesh->SetupAttachment(RootComponent);

	bVertical = false;
	bHorizontal = false;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	Super::BeginPlay();

	CurrentPosition = this->PlayerMesh->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentPosition.ToString());
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Up", IE_Pressed, this, &AMainPawn::MoveUp);
	PlayerInputComponent->BindAction("Down", IE_Pressed, this, &AMainPawn::MoveDown);
	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &AMainPawn::MoveLeft);
	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &AMainPawn::MoveRight);
}


void AMainPawn::MoveUp(){
	if(bVertical){
		const FVector NextPosition = FVector(-CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z);
		CurrentPosition = NextPosition;
		this->SetActorLocation(NextPosition);
		bVertical = !bVertical;
	}
}

void AMainPawn::MoveDown(){
	if(!bVertical){
		const FVector NextPosition = FVector(-CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z);
		CurrentPosition = NextPosition;
		this->SetActorLocation(NextPosition);
		bVertical = !bVertical;
	}
}

void AMainPawn::MoveLeft(){
	if(bHorizontal){
		const FVector NextPosition = FVector(CurrentPosition.X, -CurrentPosition.Y, CurrentPosition.Z);
		CurrentPosition = NextPosition;
		this->SetActorLocation(NextPosition);
		bHorizontal = !bHorizontal;
	}
}

void AMainPawn::MoveRight(){
	if(!bHorizontal){
		const FVector NextPosition = FVector(CurrentPosition.X, -CurrentPosition.Y, CurrentPosition.Z);
		CurrentPosition = NextPosition;
		this->SetActorLocation(NextPosition);
		bHorizontal = !bHorizontal;
	}
}
