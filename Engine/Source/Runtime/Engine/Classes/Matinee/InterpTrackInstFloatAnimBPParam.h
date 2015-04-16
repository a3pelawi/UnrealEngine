// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.


#pragma once
#include "InterpTrackInstFloatAnimBPParam.generated.h"

UCLASS()
class UInterpTrackInstFloatAnimBPParam : public UInterpTrackInst
{
	GENERATED_UCLASS_BODY()

	/** MIDs we're using to set the desired parameter. */
	UPROPERTY(transient)
	class UAnimInstance* AnimScriptInstance;

	/** Saved values for restoring state when exiting Matinee. */
	UPROPERTY(transient)
	float ResetFloat;

	UProperty* ParamProperty;

	// Begin UInterpTrackInst Instance
	virtual void InitTrackInst(UInterpTrack* Track) override;
	virtual void SaveActorState(UInterpTrack* Track) override;
	virtual void RestoreActorState(UInterpTrack* Track) override;
	// End UInterpTrackInst Instance

	// set/getter for the parameter reading
	void SetValue(float InValue);
	float GetValue() const;
	// refresh parameter setup
	void RefreshParameter(UInterpTrack* Track);
};
