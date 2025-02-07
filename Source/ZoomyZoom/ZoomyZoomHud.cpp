// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ZoomyZoomHud.h"
#include "ZoomyZoomPawn.h"
#include "WheeledVehicle.h"
#include "RenderResource.h"
#include "Shader.h"
#include "Engine/Canvas.h"
#include "WheeledVehicleMovementComponent.h"
#include "Engine/Font.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

#define LOCTEXT_NAMESPACE "VehicleHUD"

AZoomyZoomHud::AZoomyZoomHud()
{
	static ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = Font.Object;
}

void AZoomyZoomHud::DrawHUD()
{
	Super::DrawHUD();

	// Calculate ratio from 720p
	const float HUDXRatio = Canvas->SizeX / 1280.f;
	const float HUDYRatio = Canvas->SizeY / 720.f;

	bool bWantHUD = true;
#if HMD_MODULE_INCLUDED
	bWantHUD = !GEngine->IsStereoscopic3D();
#endif // HMD_MODULE_INCLUDED
	// We dont want the onscreen hud when using a HMD device	
	if (bWantHUD == true)
	{
		// Get our vehicle so we can check if we are in car. If we are we don't want onscreen HUD
		AZoomyZoomPawn* Vehicle = Cast<AZoomyZoomPawn>(GetOwningPawn());
		if ((Vehicle != nullptr) && (Vehicle->bInCarCameraActive == false))
		{
			FVector2D ScaleVec(HUDYRatio * 1.4f, HUDYRatio * 1.4f);

			// Speed
			FCanvasTextItem SpeedTextItem(FVector2D(HUDXRatio * 805.f, HUDYRatio * 455), Vehicle->SpeedDisplayString, HUDFont, FLinearColor::White);
			SpeedTextItem.Scale = ScaleVec;
			Canvas->DrawItem(SpeedTextItem);

			// DragCoefficent (testing)
			//FCanvasTextItem GearTextItem(FVector2D(HUDXRatio * 805.f, HUDYRatio * 500.f), FText::AsNumber(Vehicle->GetVehicleMovementComponent()->DragCoefficient), HUDFont, FLinearColor::White);
			//GearTextItem.Scale = ScaleVec;
			//Canvas->DrawItem(GearTextItem);

			// BoostItemAmount
			FCanvasTextItem BoostItem(FVector2D(HUDXRatio * 805.f, HUDYRatio * 500.f), FText::AsNumber(Vehicle->boostPickupAmount), HUDFont, FLinearColor::White);
			BoostItem.Scale = ScaleVec;
			Canvas->DrawItem(BoostItem);
		}
	}
}


#undef LOCTEXT_NAMESPACE
