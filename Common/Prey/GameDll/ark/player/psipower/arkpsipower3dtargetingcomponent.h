// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryParticleSystem/IParticles.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>

class ArkPsiTargetingData;
class CCryName;
class IArkPsiPower;
struct IParticleEmitter;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipower3dtargetingcomponent.h
class CArkPsiPower3DTargetingComponent : public ArkPsiPowerTargetingComponent, public IParticleEffectListener // Id=80192D5 Size=464
{
public:
	Vec3 m_targetPosition;
	ArkLooseEffect m_targetingEffect;
	ArkLooseEffect m_crosshairEffect;
	
	CArkPsiPower3DTargetingComponent(IArkPsiPower const *_pPower);
	virtual ~CArkPsiPower3DTargetingComponent();
	ArkPsiTargetingData &GetTargetingData() const { return FGetTargetingData(this); }
	void Update(const float _fDt) { FUpdate(this,_fDt); }
	Vec3 GetTargetPos() const { return FGetTargetPos(this); }
	Vec3 GetTargetDir() const { return FGetTargetDir(this); }
	virtual bool Start();
	virtual void Stop();
	std::vector<IEntity *> GetEntitiesInSphere(const float _fRadius) const { return FGetEntitiesInSphere(this,_fRadius); }
	virtual void OnCreateEmitter(IParticleEmitter *pEmitter);
	virtual void OnDeleteEmitter(IParticleEmitter *_pEmitter);
	virtual bool UsePositionEmitter() const;
	void UpdatePsiTargets() { FUpdatePsiTargets(this); }
	
#if 0
	void ProcessInput(CCryName const &arg0, int arg1, float arg2);
#endif
	
	static inline auto FBitNotCArkPsiPower3DTargetingComponent = PreyFunction<void(CArkPsiPower3DTargetingComponent *const _this)>(0x1582830);
	static inline auto FGetTargetingData = PreyFunction<ArkPsiTargetingData &(CArkPsiPower3DTargetingComponent const *const _this)>(0x1582A80);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPower3DTargetingComponent *const _this, const float _fDt)>(0x1582CF0);
	static inline auto FGetTargetPos = PreyFunction<Vec3(CArkPsiPower3DTargetingComponent const *const _this)>(0x1582A60);
	static inline auto FGetTargetDir = PreyFunction<Vec3(CArkPsiPower3DTargetingComponent const *const _this)>(0x1582970);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower3DTargetingComponent *const _this)>(0x1582AF0);
	static inline auto FStop = PreyFunction<void(CArkPsiPower3DTargetingComponent *const _this)>(0x1582C90);
	static inline auto FGetEntitiesInSphere = PreyFunction<std::vector<IEntity *>(CArkPsiPower3DTargetingComponent const *const _this, const float _fRadius)>(0x1582950);
	static inline auto FOnCreateEmitter = PreyFunction<void(CArkPsiPower3DTargetingComponent *const _this, IParticleEmitter *pEmitter)>(0xA13080);
	static inline auto FOnDeleteEmitter = PreyFunction<void(CArkPsiPower3DTargetingComponent *const _this, IParticleEmitter *_pEmitter)>(0x1582AB0);
	static inline auto FUsePositionEmitter = PreyFunction<bool(CArkPsiPower3DTargetingComponent const *const _this)>(0x1B933B0);
	static inline auto FUpdatePsiTargets = PreyFunction<void(CArkPsiPower3DTargetingComponent *const _this)>(0x1582D00);
};

