// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ZoomyZoomGameMode.h"
#include "ZoomyZoomPawn.h"
#include "ZoomyZoomHud.h"

AZoomyZoomGameMode::AZoomyZoomGameMode()
{
	DefaultPawnClass = AZoomyZoomPawn::StaticClass();
	HUDClass = AZoomyZoomHud::StaticClass();
}
