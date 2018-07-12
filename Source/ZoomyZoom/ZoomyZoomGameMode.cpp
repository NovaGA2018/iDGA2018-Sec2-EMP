// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ZoomyZoomGameMode.h"
#include "ZoomyZoomPawn.h"
#include "ZoomyZoomHud.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AZoomyZoomGameMode::AZoomyZoomGameMode()
{
	//DefaultPawnClass = AZoomyZoomPawn::StaticClass();
	//HUDClass = AZoomyZoomHud::StaticClass();
}

void AZoomyZoomGameMode::BeginPlay() {
	Super::BeginPlay();

	//Initialize the HUD when game starts
	if (HUDWidgetClass != nullptr) {

		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);


		if (CurrentWidget != nullptr) {

			CurrentWidget->AddToViewport();

		}
	}
}
