// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkInterval.h>

class ArkNpc;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/ArkAirJetManager.h
class ArkAirJetManager // Id=8014428 Size=48
{
public:
	std::vector<ArkAirJet> m_airJets;
	Vec3 m_prevForward;
	ArkInterval<float> m_airJetActiveToggleTime;
	float m_airJetOffTime;
	
	void InitializeEmittersFromScript(ArkNpc const &_npc) { FInitializeEmittersFromScript(this,_npc); }
	void Update(IEntity &_entity, float _elapsedTime) { FUpdate(this,_entity,_elapsedTime); }
	void Clear() { FClear(this); }
	void DeactivateAll() { FDeactivateAll(this); }
	
#if 0
	void InitializeEmitters(IEntity &arg0, _smart_ptr<IParticleEffect> const &arg1, ArkInterval<float> const &arg2, const float arg3);
#endif
	
	static inline auto FInitializeEmittersFromScript = PreyFunction<void(ArkAirJetManager *const _this, ArkNpc const &_npc)>(0x1148CE0);
	static inline auto FUpdate = PreyFunction<void(ArkAirJetManager *const _this, IEntity &_entity, float _elapsedTime)>(0x1148E60);
	static inline auto FClear = PreyFunction<void(ArkAirJetManager *const _this)>(0x1148C00);
	static inline auto FDeactivateAll = PreyFunction<void(ArkAirJetManager *const _this)>(0x1148C80);
};

