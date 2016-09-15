// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "MyProjectHud.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "MyProject2Character.h"

AMyProjectHud::AMyProjectHud() {
	static ConstructorHelpers::FObjectFinder<UFont>
		Font(TEXT("Font'/Engine/EngineFonts/RobotoDistanceField.RobotoDistanceField'"));
	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture(TEXT("Texture2D'/Game/Green_Texture.Green_Texture'"));
	if (Texture.Succeeded()) {
		MyTexture = Texture.Object;
	}
	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture2(TEXT("Texture2D'/Game/Green_Texture.Green_Texture'"));
	if (Texture2.Succeeded()) {
		MyTexture2 = Texture2.Object;
	}
}

void AMyProjectHud::DrawHUD() {
	Super::DrawHUD();

	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX,
		Canvas->SizeY);

	AMyProject2Character* MyCharacter = Cast<AMyProject2Character>(
		UGameplayStatics::GetPlayerPawn(this, 0));

	//FString ColetavelLifeString = FString::Printf(TEXT("ColetavelLife: %d"),
	//	MyCharacter->GetColetavel());
//	DrawText(ColetavelLifeString, FColor::Red, 50, 50, HUDFont);

	FString ColetavelLifeString = FString::Printf(TEXT("ColetavelLife: %d"),
		MyCharacter->GetColetavelLife());
	DrawText(ColetavelLifeString, FColor::Blue, 50, 140, HUDFont);













	//DrawTextureSimple(MyTexture, 50, 50, 1.0f, false);

	DrawTexture(MyTexture, 200, 50, MyCharacter->GetColetavel() * 35,
		MyTexture->GetSizeY(), 0, 0, MyCharacter->GetColetavel() * 4,
		MyTexture->GetSizeY(), FLinearColor::White,
		EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f,
		FVector2D::ZeroVector);



	DrawTexture(MyTexture2, 200, 140, MyCharacter->GetColetavelLife() * 35,
		MyTexture2->GetSizeY(), 0, 0, MyCharacter->GetColetavelLife() * 4,
		MyTexture2->GetSizeY(), FLinearColor::White,
		EBlendMode::BLEND_Translucent, 1.0f, false, 0.0f,
		FVector2D::ZeroVector);
}









