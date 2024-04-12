// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "AMPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	class UInputAction* FireAction;

private:
	void Fire();
	
public:
	virtual void SetupInputComponent() override;
};
