// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "AIPatrol.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "MyProject2Character.h"
#include "ProjectActor.h"
#include "Inimigo.h"



// Sets default values
AAIPatrol::AAIPatrol()
{
	// Initalize Senses

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);

	PrimaryActorTick.bCanEverTick = true;





	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AAIPatrol::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp) {
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIPatrol::OnPlayerCaught);


	}
}



// Called to bind functionality to input
void AAIPatrol::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AAIPatrol::OnPlayerCaught(APawn * Pawn)
{

	AAIPatrolController* AIController = Cast<AAIPatrolController>(GetController());


	if (AIController)

	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("vc esta sendo seguido"));
		AIController->SetPlayerCaught(Pawn);
	}
}

void AAIPatrol::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	//if (OtherActor->IsA(AProjectActor::StaticClass())) {

	//	Destroy();
		//UE_LOG(LogTemp, Warning, TEXT("NORMAL"));
	//}


	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AProjectActor::StaticClass()))) {

		AProjectActor* MyProject2Character = Cast<AProjectActor>(OtherActor);

		UE_LOG(LogTemp, Warning, TEXT("Destruiu Parabens o personagem"));
		Destroy();

	}
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyProject2Character::StaticClass()))) {

		AMyProject2Character* MyProject2Character = Cast<AMyProject2Character>(OtherActor);
		MyProject2Character->SetColetavelLife(MyProject2Character->GetColetavelLife() - DamageAmount);
		MyProject2Character->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("ColetavelLife = %d /10"), MyProject2Character->GetColetavelLife());

		Destroy();

		UE_LOG(LogTemp, Warning, TEXT("Encostou"));
	}

}

//void AAIPatrol::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
//if	((OtherActor != nullptr) && (OtherActor != this) &&
		//(OtherComp != nullptr) && (OtherActor->IsA(AAIPatrol::StaticClass())))
	//{

	//	Destroy();
	//	UE_LOG(LogTemp, Warning, TEXT("OnHit"));
	//}
//}