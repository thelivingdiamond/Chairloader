// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkObjectiveStateListener.h
class IArkObjectiveStateListener // Id=80136A8 Size=8
{
public:
	virtual void OnObjectiveAssigned(uint64_t _objectiveId);
	virtual void OnObjectiveUnassigned(uint64_t _objectiveId);
	virtual void OnObjectiveCompleted(uint64_t _objectiveId);
	virtual void OnObjectiveFailed(uint64_t _objectiveId);
	virtual void OnTaskActivated(uint64_t arg0);
	virtual void OnTaskDeactivated(uint64_t arg0);
	virtual void OnTaskCompleted(uint64_t arg0);
	virtual void OnTaskFailed(uint64_t arg0);
	
	static inline auto FOnObjectiveAssigned = PreyFunction<void(IArkObjectiveStateListener *const _this, uint64_t _objectiveId)>(0xA13080);
	static inline auto FOnObjectiveUnassigned = PreyFunction<void(IArkObjectiveStateListener *const _this, uint64_t _objectiveId)>(0xA13080);
	static inline auto FOnObjectiveCompleted = PreyFunction<void(IArkObjectiveStateListener *const _this, uint64_t _objectiveId)>(0xA13080);
	static inline auto FOnObjectiveFailed = PreyFunction<void(IArkObjectiveStateListener *const _this, uint64_t _objectiveId)>(0xA13080);
};

