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

	PlayerInputComponent->BindAction("Lompat", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("GerakPlayer_Horizontal", this, &AKarakterPemain::GerakPlayer_Horizontal);
	PlayerInputComponent->BindAxis("GerakPlayer_Vertical", this, &AKarakterPemain::GerakPlayer_Vertical);
	PlayerInputComponent->BindAxis("ArahKamera_Horizontal", this, &AKarakterPemain::ArahKamera_Horizontal);
	PlayerInputComponent->BindAxis("ArahKamera_Vertical", this, &AKarakterPemain::ArahKamera_Vertical);
}

void AKarakterPemain::GerakPlayer_Horizontal(float Nilai_X_dari_GerakPlayer)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, Nilai_X_dari_GerakPlayer);
}

void AKarakterPemain::GerakPlayer_Vertical(float Nilai_Y_dari_GerakPlayer)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, Nilai_Y_dari_GerakPlayer);
}

void AKarakterPemain::ArahKamera_Horizontal(float Nilai_X_dari_ArahKamera)
{
	AddControllerYawInput(Nilai_X_dari_ArahKamera);
}

void AKarakterPemain::ArahKamera_Vertical(float Nilai_Y_dari_ArahKamera)
{
	AddControllerPitchInput(Nilai_Y_dari_ArahKamera);
}
