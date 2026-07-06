// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkFabricationPlanListener.h
class IArkFabricationPlanListener // Id=8015541 Size=8
{
public:
	virtual void OnFabricationPlanAdded(const uint64_t arg0) = 0;
	virtual void OnFabricationPlanUsed(const uint64_t arg0) = 0;
	virtual void OnFabricationErrorSet(const uint64_t arg0);
	virtual void OnFabricationErrorCleared(const uint64_t arg0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkFabricationPlanListener
// Header:  Prey/GameDll/ark/iface/IArkFabricationPlanListener.h
class IArkFabricationPlanListener
{ // Size=8 (0x8)
public:
	virtual void OnFabricationPlanAdded(const uint64_t _id);
	virtual void OnFabricationPlanUsed(const uint64_t _id);
	virtual void OnFabricationPlanReverseEngineered(const uint64_t _arg0_, const uint64_t _arg1_);
	virtual void OnFabricationErrorSet(const uint64_t _id);
	virtual void OnFabricationErrorCleared(const uint64_t _id);
	virtual void OnFabricationPlanPostSerialize();

	static inline auto FOnFabricationPlanAdded = PreyFunction<void(IArkFabricationPlanListener* const _this, const uint64_t _id)>(0x1333E90);
	static inline auto FOnFabricationPlanUsed = PreyFunction<void(IArkFabricationPlanListener* const _this, const uint64_t _id)>(0x1333E90);
	static inline auto FOnFabricationErrorSet = PreyFunction<void(IArkFabricationPlanListener* const _this, const uint64_t _id)>(0x1333E90);
	static inline auto FOnFabricationErrorCleared = PreyFunction<void(IArkFabricationPlanListener* const _this, const uint64_t _id)>(0x1333E90);
	static inline auto FOnFabricationPlanPostSerialize = PreyFunction<void(IArkFabricationPlanListener* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
