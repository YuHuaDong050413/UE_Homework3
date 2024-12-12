// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework3GameMode.h"
#include "Homework3Character.h"
#include "UObject/ConstructorHelpers.h"

AHomework3GameMode::AHomework3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
