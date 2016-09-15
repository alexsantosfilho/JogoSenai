// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyProjectHud.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AMyProjectHud : public AHUD
{
	GENERATED_BODY()
	
	
public:
	AMyProjectHud();

	UPROPERTY(EditAnywhere)
		UFont* HUDFont;
	UPROPERTY(EditAnywhere)
		UTexture2D* MyTexture;
	UPROPERTY(EditAnywhere)
		UTexture2D* MyTexture2;

	virtual void DrawHUD() override;
	
};
