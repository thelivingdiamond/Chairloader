// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/functor.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipower3dtargetingcomponent.h>

class IArkPsiPower;
struct IEntity;
struct IParticleEmitter;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h
class ArkPsiPowerIndividualTargetingComponent : public CArkPsiPower3DTargetingComponent // Id=80192D6 Size=616
{
public:
	using SelectionChangedCallback = Functor0;
	using TargetFilter = Functor1wRet<IEntity const &,bool>;
	
	Functor0 m_callback;
	unsigned m_bestTarget;
	ArkLooseEffect m_individualTargetingEffect;
	
	ArkPsiPowerIndividualTargetingComponent(IArkPsiPower const *_pPower);
	void SetCallback(Functor0 _callback) { FSetCallback(this,_callback); }
	virtual void Stop();
	void Reset() { FReset(this); }
	IEntity *GetSelectedEntity() const { return FGetSelectedEntity(this); }
	std::vector<IEntity *> GetUnselectedEntities() const { return FGetUnselectedEntities(this); }
	std::vector<IEntity *> GetSelectedEntities() const { return FGetSelectedEntities(this); }
	void Update(const float _fDt) { FUpdate(this,_fDt); }
	virtual bool UsePositionEmitter() const;
	virtual void OnDeleteEmitter(IParticleEmitter *_pEmitter);
	void GatherTargets(Functor1wRet<IEntity const &,bool> _filter) { FGatherTargets(this,_filter); }
	void SetBestEntity(unsigned _target) { FSetBestEntity(this,_target); }
	virtual bool ValidateTarget(IEntity const &_entity) const;
	
#if 0
	void CleanUp();
	void KillTargetParticleEmitter();
#endif
	
	static inline auto FSetCallback = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this, Functor0 _callback)>(0x1591650);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this)>(0x1591670);
	static inline auto FReset = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this)>(0x1591200);
	static inline auto FGetSelectedEntity = PreyFunction<IEntity *(ArkPsiPowerIndividualTargetingComponent const *const _this)>(0x15911A0);
	static inline auto FGetUnselectedEntities = PreyFunction<std::vector<IEntity *>(ArkPsiPowerIndividualTargetingComponent const *const _this)>(0x146DAD0);
	static inline auto FGetSelectedEntities = PreyFunction<std::vector<IEntity *>(ArkPsiPowerIndividualTargetingComponent const *const _this)>(0x1591150);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this, const float _fDt)>(0x15916D0);
	static inline auto FUsePositionEmitter = PreyFunction<bool(ArkPsiPowerIndividualTargetingComponent const *const _this)>(0xDD23F0);
	static inline auto FOnDeleteEmitter = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this, IParticleEmitter *_pEmitter)>(0x15911C0);
	static inline auto FGatherTargets = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this, Functor1wRet<IEntity const &,bool> _filter)>(0x1590DA0);
	static inline auto FSetBestEntity = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent *const _this, unsigned _target)>(0x1591250);
	static inline auto FValidateTarget = PreyFunction<bool(ArkPsiPowerIndividualTargetingComponent const *const _this, IEntity const &_entity)>(0x15917E0);
};

