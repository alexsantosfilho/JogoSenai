// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "ProjectActor.h"
#include "MyProject2Character.h"
#include "AIPatrol.h"




// Sets default values
AProjectActor::AProjectActor()
{

	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->bGenerateOverlapEvents = true;
	Root->OnComponentBeginOverlap.AddDynamic(this, &AProjectActor::OnOverlapBegin);



//	this->OnActorHit.AddDynamic(this, &AProjectActor::OnHit);

	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/Shape_WideCapsule.Shape_WideCapsule'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f));
	MeshComp->AttachTo(RootComponent);

	Particle = CreateDefaultSubobject<UParticleSystemComponent>
		(TEXT("Particle"));
	Particle->bAutoActivate = true;
	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		ParticleSystem(TEXT("ParticleSystem'/Game/particulas/P_Fire.P_Fire'"));
	if (ParticleSystem.Succeeded()) {
		Particle->SetTemplate(ParticleSystem.Object);
	}
	Particle->SetupAttachment(RootComponent);
	//Particle->ToggleActive();

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = Root;
	ProjectileMovement->InitialSpeed = 10000.0f;
	ProjectileMovement->MaxSpeed = 10000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	InitialLifeSpan = 1.0f;
}
void AProjectActor::BeginPlay()
{
	Super::BeginPlay();

	DefaultY = GetActorLocation().Y;
	DefaultX = GetActorLocation().X;
	DefaultZ = GetActorLocation().Z;



}

void AProjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	FVector Location2 = GetActorLocation();
	FVector Location3 = GetActorLocation();



	Location.Y = DefaultY;
	SetActorLocation(Location);

	Location.X = DefaultX;
	SetActorLocation(Location2);

	Location.Z = DefaultZ;
	SetActorLocation(Location3);

	RunningTime += DeltaTime;
	float DestroyTime = 1.0f * RunningTime;
	if (DestroyTime > 10.0f) {
		Destroy();
	}
}


void AProjectActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	

	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AProjectActor::StaticClass()))) {

		AProjectActor* MyProject2Character = Cast<AProjectActor>(OtherActor);

		UE_LOG(LogTemp, Warning, TEXT("Destruiu Parabens"));
		Destroy();

	}

	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AAIPatrol::StaticClass()))) {

		AAIPatrol* MyProject2Character = Cast<AAIPatrol>(OtherActor);
		MyProject2Character->SetColetavelLife2(MyProject2Character->GetColetavelLife2() - DamageAmount); // DANO NO PERSONAGEM
		MyProject2Character->OnDeath2();

		UE_LOG(LogTemp, Warning, TEXT("Destruiu o personagem inimigo!!!!!!"));
	//	MyProject2Character->Destroy();
		//Destroy();



		


	}




	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AProjectActor::StaticClass()))) {

		AProjectActor* MyProject2Character = Cast<AProjectActor>(OtherActor);

		UE_LOG(LogTemp, Warning, TEXT("Destruiu Parabens o personagem"));
		//MyProject2Character->Destroy();
		Destroy();

	}



}

void AProjectActor::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AAIPatrol::StaticClass())))
	{
		AAIPatrol* MyProject2Character = Cast<AAIPatrol>(OtherActor);

		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("OnHit"));
	}
}