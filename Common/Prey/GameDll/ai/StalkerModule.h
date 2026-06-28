// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ai/gameaihelpers.h>
#include <_unknown/InstanceInitContext.h>

class Agent;
struct IAIObject;
struct InstanceID;
struct RayCastResult;
struct StalkerInstance;

// StalkerModule
// Header:  Prey/GameDll/ai/StalkerModule.h
class StalkerModule : public AIModuleWithInstanceUpdate<StalkerModule,StalkerInstance,4,4>
{ // Size=56 (0x38)
public:
	virtual void InitializeInstance(const InstanceInitContext<StalkerInstance>& context);
	virtual void DeinitializeInstance(InstanceID instanceID);
	virtual const char* GetName() const;
	virtual void UpdateInstance(StalkerInstance& instance, float frameTime);

#if 0
	void QueueLineOfSightRay(Agent& _arg0_, IAIObject* _arg1_, StalkerInstance& _arg2_);
	void LineOfSightRayComplete(const unsigned& _arg0_, const RayCastResult& _arg1_);
	StalkerInstance* FindInstanceForRay(const unsigned& _arg0_);
#endif

	static inline auto FInitializeInstance = PreyFunction<void(StalkerModule* const _this, const InstanceInitContext<StalkerInstance>& context)>(0x10CEDE0);
	static inline auto FDeinitializeInstance = PreyFunction<void(StalkerModule* const _this, InstanceID instanceID)>(0x10CEC40);
	static inline auto FGetName = PreyFunction<const char* (const StalkerModule* const _this)>(0x10C68D0);
	static inline auto FUpdateInstance = PreyFunction<void(StalkerModule* const _this, StalkerInstance& instance, float frameTime)>(0x10CEE10);
};
#endif // MOONCRASH
