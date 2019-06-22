// Copyright Ali El Saleh 2019

#pragma once

#include "GameFramework/Pawn.h"
#include "MenuPawn.generated.h"

UCLASS(HideCategories=("Rendering", "Replication", "Actor", "Collision", "LOD", "Cooking"))
class MENUSYSTEM_API AMenuPawn : public APawn
{
	GENERATED_BODY()

public:
	AMenuPawn();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Enables the input mode to UI only
	void EnableUIMode();

	// UPROPERTY Components
	UPROPERTY(EditAnywhere, Category = "Components")
		class UCameraComponent* CameraComponent;


	// UPROPERTY Properties (Details Panel)
};
