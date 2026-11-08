// FIKIFOW INFINITE CREATION


#include "KarakterPemain.h"
#include "Camera/CameraComponent.h"

// Sets default values
AKarakterPemain::AKarakterPemain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VAR_Kamera_untuk_Pemain = CreateDefaultSubobject<UCameraComponent>(TEXT("COM-Kamera_untuk_Pemain"));
	VAR_Kamera_untuk_Pemain->SetupAttachment(RootComponent);
	VAR_Kamera_untuk_Pemain->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AKarakterPemain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKarakterPemain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKarakterPemain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

