// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "AMPPlayerController.generated.h"

class UInputAction;

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPPlayerController : public APlayerController
{
	GENERATED_BODY()

	AAMPPlayerController();

protected:
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* FireAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* ThrustAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* HyperSpaceAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* PauseGameAction;

	virtual void BeginPlay() override;

	bool bIsGamePaused;
	
	UFUNCTION(BlueprintNativeEvent)
	void PauseGame();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ResumeGame();
	
private:
	void Fire();
	void Rotate(const FInputActionValue& Value);
	void Thrust();
	void HyperspaceJump();
	
public:
	virtual void SetupInputComponent() override;
};
