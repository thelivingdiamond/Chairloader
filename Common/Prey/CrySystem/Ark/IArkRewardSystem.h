// Header file automatically created from a PDB.
#pragma once

// IArkRewardSystemCallbackHandler
// Header:  Prey/CrySystem/Ark/IArkRewardSystem.h
struct IArkRewardSystemCallbackHandler
{ // Size=8 (0x8)
	virtual void OnChangedTrackable(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, unsigned _arg3_) = 0;
	virtual void OnRewardUnlocked(unsigned _arg0_, unsigned _arg1_) = 0;
};

// IArkRewardSystem
// Header:  CryEngine/CrySystem/Ark/IArkRewardSystem.h
// Include: Prey/CrySystem/Ark/IArkRewardSystem.h
struct IArkRewardSystem
{ // Size=8 (0x8)
	virtual ~IArkRewardSystem() {}
	virtual bool Init() = 0;
	virtual void SetActiveUserId(unsigned _userId) = 0;
	virtual bool LoadRewardData(const string& _strRewardFile) = 0;
	virtual void SetInitialTrackableValue(unsigned _trackable, unsigned _value) = 0;
	virtual void SetInitialTrackableValue(uint64_t _associatedMetric, unsigned _value) = 0;
	virtual unsigned IncrementTrackableValue(unsigned _trackable) = 0;
	virtual unsigned IncrementTrackableValue(uint64_t _associatedMetric) = 0;
	virtual unsigned UpdateTrackableValueMax(uint64_t _associatedMetric, unsigned _value) = 0;
	virtual void UnlockReward(unsigned _reward) = 0;
	virtual void ResetTrackableData() = 0;
	virtual void SetCallbackHandler(IArkRewardSystemCallbackHandler* _arg0_) = 0;
	virtual void InternalTrackableUpdated(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_) = 0;
	virtual void InternalRewardUnlocked(unsigned _arg0_) = 0;
};

