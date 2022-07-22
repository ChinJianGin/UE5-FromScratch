#include "MapGenerator.h"

#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"

#include "Log.h"

AMapGenerator::AMapGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));
    Sprite = ObjectInitializer.CreateDefaultSubobject<UBillboardComponent>(this, TEXT("Sprite"));
    Sprite->SetupAttachment(RootComponent);

    float _x = 110, _y = 110;
    UStaticMeshComponent* _mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Map_1"));
    _mesh->SetWorldScale3D(FVector(.2f));
    _mesh->SetWorldLocation(FVector(_x, _y, 20.f));
    Map.AddUnique(_mesh);

    _mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Map_2"));
    _mesh->SetWorldScale3D(FVector(.2f));
    _mesh->SetWorldLocation(FVector(-_x, _y, 20.f));
    Map.AddUnique(_mesh);

    _mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Map_3"));
    _mesh->SetWorldScale3D(FVector(.2f));
    _mesh->SetWorldLocation(FVector(_x, -_y, 20.f));
    Map.AddUnique(_mesh);
    
    _mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Map_4"));
    _mesh->SetWorldScale3D(FVector(.2f));
    _mesh->SetWorldLocation(FVector(-_x, -_y, 20.f));
    Map.AddUnique(_mesh);
}

void AMapGenerator::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Place generator"));
}