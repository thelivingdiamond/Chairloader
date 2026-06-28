// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/ArkInterval.h>

class ArkNpc;
struct CEffectAttachment;
struct IAttachment;
struct IEntity;
struct IParticleEmitter;

// Header: Override
// Prey/GameDll/ark/ArkAirJetManager.h
struct ArkAirJet // Id=801442C Size=16
{
	IAttachment* m_pAttachment;
	float m_toggleTimer;

#if 0
	CEffectAttachment* GetEffectAttachment() const;
	IParticleEmitter* GetEmitter() const;
	void Activate(const bool arg0) const;
#endif
};

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>

class ArkNpc;
struct CEffectAttachment;
struct IAttachment;
struct IEntity;
struct IParticleEffect;
struct IParticleEmitter;

// ArkAirJet
// Header:  Prey/GameDll/ark/ArkAirJetManager.h
struct ArkAirJet
{ // Size=16 (0x10)
	IAttachment* m_pAttachment;
	float m_toggleTimer;

#if 0
	ArkAirJet(IAttachment* const _arg0_);
	CEffectAttachment* GetEffectAttachment() const;
	IParticleEmitter* GetEmitter() const;
	void Activate(const bool _arg0_) const;
#endif
};

// ArkAirJetManager
// Header:  Prey/GameDll/ark/ArkAirJetManager.h
class ArkAirJetManager
{ // Size=48 (0x30)
public:
	std::vector<ArkAirJet> m_airJets;
	Vec3 m_prevForward;
	ArkInterval<float> m_airJetActiveToggleTime;
	float m_airJetOffTime;

	void InitializeEmittersFromScript(const ArkNpc& _npc) { FInitializeEmittersFromScript(this, _npc); }
	void Update(IEntity& _entity, float _elapsedTime) { FUpdate(this, _entity, _elapsedTime); }
	void Clear() { FClear(this); }
	void DeactivateAll() { FDeactivateAll(this); }

#if 0
	ArkAirJetManager();
	~ArkAirJetManager();
	void InitializeEmitters(IEntity& _arg0_, const _smart_ptr<IParticleEffect>& _arg1_, const ArkInterval<float>& _arg2_, const float _arg3_);
#endif

	static inline auto FInitializeEmittersFromScript = PreyFunction<void(ArkAirJetManager* const _this, const ArkNpc& _npc)>(0x118FA60);
	static inline auto FUpdate = PreyFunction<void(ArkAirJetManager* const _this, IEntity& _entity, float _elapsedTime)>(0x118FBE0);
	static inline auto FClear = PreyFunction<void(ArkAirJetManager* const _this)>(0x118F980);
	static inline auto FDeactivateAll = PreyFunction<void(ArkAirJetManager* const _this)>(0x118FA00);
};
#endif // !MOONCRASH
