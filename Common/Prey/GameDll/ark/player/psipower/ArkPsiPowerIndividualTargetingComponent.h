// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/functor.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h>

class IArkPsiPower;
struct IEntity;
struct IParticleEmitter;

// ArkPsiPowerIndividualTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h
class ArkPsiPowerIndividualTargetingComponent : public CArkPsiPower3DTargetingComponent
{ // Size=616 (0x268)
public:
	using SelectionChangedCallback = Functor0;
	using TargetFilter = Functor1wRet<IEntity const &,bool>;

	Functor0 m_callback;
	unsigned m_bestTarget;
	ArkLooseEffect m_individualTargetingEffect;

	ArkPsiPowerIndividualTargetingComponent(const IArkPsiPower* _pPower);
	virtual ~ArkPsiPowerIndividualTargetingComponent();
	void SetCallback(Functor0 _callback) { FSetCallback(this, _callback); }
	virtual void Stop();
	void Reset() { FReset(this); }
	IEntity* GetSelectedEntity() const { return FGetSelectedEntity(this); }
	std::vector<IEntity*> GetUnselectedEntities() const { alignas(std::vector<IEntity*>) std::byte _return_buf_[sizeof(std::vector<IEntity*>)]; return *FGetUnselectedEntities(this, reinterpret_cast<std::vector<IEntity*>*>(_return_buf_)); }
	std::vector<IEntity*> GetSelectedEntities() const { alignas(std::vector<IEntity*>) std::byte _return_buf_[sizeof(std::vector<IEntity*>)]; return *FGetSelectedEntities(this, reinterpret_cast<std::vector<IEntity*>*>(_return_buf_)); }
	void Update(const float _fDt) { FUpdate(this, _fDt); }
	virtual bool UsePositionEmitter() const;
	virtual void OnDeleteEmitter(IParticleEmitter* _pEmitter);
	void GatherTargets(Functor1wRet<IEntity const &,bool> _filter) { FGatherTargets(this, _filter); }
	void SetBestEntity(unsigned _target) { FSetBestEntity(this, _target); }
	virtual bool ValidateTarget(const IEntity& _entity) const;

#if 0
	void CleanUp();
	void KillTargetParticleEmitter();
#endif

	static inline auto FArkPsiPowerIndividualTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x1590A50);
	static inline auto FSetCallback = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this, Functor0 _callback)>(0x1591650);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this)>(0x1591670);
	static inline auto FReset = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this)>(0x1591200);
	static inline auto FGetSelectedEntity = PreyFunction<IEntity* (const ArkPsiPowerIndividualTargetingComponent* const _this)>(0x15911A0);
	static inline auto FGetUnselectedEntities = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerIndividualTargetingComponent* const _this, std::vector<IEntity*>* _return_value_)>(0x146DAD0);
	static inline auto FGetSelectedEntities = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerIndividualTargetingComponent* const _this, std::vector<IEntity*>* _return_value_)>(0x1591150);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this, const float _fDt)>(0x15916D0);
	static inline auto FUsePositionEmitter = PreyFunction<bool(const ArkPsiPowerIndividualTargetingComponent* const _this)>(0xDD23F0);
	static inline auto FOnDeleteEmitter = PreyFunction<void(IParticleEffectListener* const _this, IParticleEmitter* _pEmitter)>(0x15911C0);
	static inline auto FGatherTargets = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this, Functor1wRet<IEntity const &,bool> _filter)>(0x1590DA0);
	static inline auto FSetBestEntity = PreyFunction<void(ArkPsiPowerIndividualTargetingComponent* const _this, unsigned _target)>(0x1591250);
	static inline auto FValidateTarget = PreyFunction<bool(const ArkPsiPowerIndividualTargetingComponent* const _this, const IEntity& _entity)>(0x15917E0);
};

