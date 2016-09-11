// Fill out your copyright notice in the Description page of Project Settings.

#include "PrimeiroCodigo.h"
#include "AIPatrol.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AAIPatrol::AAIPatrol()
{
 	// Initalize Senses

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
	
}

// Called when the game starts or when spawned
void AAIPatrol::BeginPlay()
{
	Super::BeginPlay();
	
	if (PawnSensingComp) {
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIPatrol::OnPlayerCaught);


	}

}

// Called every frame
//void AAIPatrol::Tick( float DeltaTime )
//{
	//Super::Tick( DeltaTime );

//}

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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Vc encostou"));
		AIController->SetPlayerCaught(Pawn);
	}
}

