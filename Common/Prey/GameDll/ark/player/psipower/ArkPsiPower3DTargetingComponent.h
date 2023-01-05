// Header file automatically created from a PDB.
#pragma once
//#include <Prey/CryParticleSystem/IParticles.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>

class ArkPsiTargetingData;
class CCryName;
class IArkPsiPower;
struct IEntity;
struct IParticleEmitter;

// CArkPsiPower3DTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h
class CArkPsiPower3DTargetingComponent : public ArkPsiPowerTargetingComponent, public IParticleEffectListener
{ // Size=464 (0x1D0)
public:
	Vec3 m_targetPosition;
	ArkLooseEffect m_targetingEffect;
	ArkLooseEffect m_crosshairEffect;

	CArkPsiPower3DTargetingComponent(const IArkPsiPower* _pPower);
	virtual ~CArkPsiPower3DTargetingComponent();
	ArkPsiTargetingData& GetTargetingData() const { return FGetTargetingData(this); }
	void Update(const float _fDt) { FUpdate(this, _fDt); }
	Vec3 GetTargetPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetTargetPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetTargetDir() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetTargetDir(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	virtual bool Start();
	virtual void Stop();
	std::vector<IEntity*> GetEntitiesInSphere(const float _fRadius) const { alignas(std::vector<IEntity*>) std::byte _return_buf_[sizeof(std::vector<IEntity*>)]; return *FGetEntitiesInSphere(this, reinterpret_cast<std::vector<IEntity*>*>(_return_buf_), _fRadius); }
	virtual void OnCreateEmitter(IParticleEmitter* pEmitter);
	virtual void OnDeleteEmitter(IParticleEmitter* _pEmitter);
	virtual bool UsePositionEmitter() const;
	void UpdatePsiTargets() { FUpdatePsiTargets(this); }

#if 0
	void ProcessInput(const CCryName& _arg0_, int _arg1_, float _arg2_);
#endif

	static inline auto FCArkPsiPower3DTargetingComponentOv1 = PreyFunction<void(CArkPsiPower3DTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x1582780);
	static inline auto FBitNotCArkPsiPower3DTargetingComponent = PreyFunction<void(CArkPsiPower3DTargetingComponent* const _this)>(0x1582830);
	static inline auto FGetTargetingData = PreyFunction<ArkPsiTargetingData& (const CArkPsiPower3DTargetingComponent* const _this)>(0x1582A80);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPower3DTargetingComponent* const _this, const float _fDt)>(0x1582CF0);
	static inline auto FGetTargetPos = PreyFunction<Vec3*(const CArkPsiPower3DTargetingComponent* const _this, Vec3* _return_value_)>(0x1582A60);
	static inline auto FGetTargetDir = PreyFunction<Vec3*(const CArkPsiPower3DTargetingComponent* const _this, Vec3* _return_value_)>(0x1582970);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower3DTargetingComponent* const _this)>(0x1582AF0);
	static inline auto FStop = PreyFunction<void(CArkPsiPower3DTargetingComponent* const _this)>(0x1582C90);
	static inline auto FGetEntitiesInSphere = PreyFunction<std::vector<IEntity*>*(const CArkPsiPower3DTargetingComponent* const _this, std::vector<IEntity*>* _return_value_, const float _fRadius)>(0x1582950);
	static inline auto FOnCreateEmitter = PreyFunction<void(IParticleEffectListener* const _this, IParticleEmitter* pEmitter)>(0xA13080);
	static inline auto FOnDeleteEmitter = PreyFunction<void(IParticleEffectListener* const _this, IParticleEmitter* _pEmitter)>(0x1582AB0);
	static inline auto FUsePositionEmitter = PreyFunction<bool(const CArkPsiPower3DTargetingComponent* const _this)>(0x1B933B0);
	static inline auto FUpdatePsiTargets = PreyFunction<void(CArkPsiPower3DTargetingComponent* const _this)>(0x1582D00);
};

