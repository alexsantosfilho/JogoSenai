// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MyProject2.h"
#include "MyProject2GameMode.h"
#include "MyProject2Character.h"

AMyProject2GameMode::AMyProject2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
