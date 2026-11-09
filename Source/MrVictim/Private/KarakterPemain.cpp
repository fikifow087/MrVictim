// FIKIFOW INFINITE CREATION


#include "KarakterPemain.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AKarakterPemain::AKarakterPemain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VAR_Kamera_untuk_Pemain = CreateDefaultSubobject<UCameraComponent>(TEXT("COM-Kamera_untuk_Pemain"));
	VAR_Kamera_untuk_Pemain->SetupAttachment(RootComponent);
	VAR_Kamera_untuk_Pemain->bUsePawnControlRotation = true;

	VAR_MeshPedang = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("COM-MeshPedang"));
	VAR_MeshPedang->SetupAttachment(GetMesh(), FName("SocketPedang"));
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

	if (bSedangMenyerang && !GetMesh()->IsPlaying())
	{
		bSedangMenyerang = false;
	}
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

	PlayerInputComponent->BindAction("Serang", IE_Pressed, this, &AKarakterPemain::MulaiSerangan);
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

void AKarakterPemain::MulaiSerangan()
{
	// Panggil animasi serangan jika ada, di set ke false agar tidak looping
	if (VAR_AnimasiSerangan && !bSedangMenyerang)
	{
		GetMesh()->PlayAnimation(VAR_AnimasiSerangan, false);
		bSedangMenyerang = true;
	}
}

void AKarakterPemain::LacakGaris()
{
	// Berikan kerusakan kepada musuh dalam jangkauan
	// Dapatkan lokasi socket
	FVector StartLocation = VAR_MeshPedang->GetSocketLocation(FName("Start"));
	FVector EndLocation = VAR_MeshPedang->GetSocketLocation(FName("End"));

	// Setup Lacak garis
	FHitResult HitResult;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this); // Abaikan diri sendiri

	// Lacak garis
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);

	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 1, 0, 1); 

	if (HitResult.bBlockingHit)
	{
		AActor* HitActor = HitResult.GetActor();
		HitActor->Destroy(); // Hancurkan musuh yang terkena


	}
}