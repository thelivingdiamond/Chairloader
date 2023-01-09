// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryPhysics/primitives.h>
#include <Prey/GameDll/ark/player/ArkPlayerLight.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLift.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h>

enum class EArkPsiPowers;
struct IEntity;

// CArkPsiPowerLift
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerLift.h
class CArkPsiPowerLift : public CArkPsiPower<LiftPowerProperties>
{ // Size=368 (0x170)
public:
	using LiftVolume = ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>;
	using LiftVolumeZeroG = ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>;

	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> > m_playerLiftVolumeManager;
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> > m_playerLiftVolumeZeroGManager;
	ArkPsiLift m_targetingLift;
	ArkPlayerLightVFX m_playerLight;
	Vec3 m_avgCylinderPosition;
	primitives::cylinder m_targetingCylinder;

	CArkPsiPowerLift();
	virtual ~CArkPsiPowerLift();
	virtual bool Start_Derived();
	virtual bool StartTargeting();
	virtual void Cancel();
	virtual void Update(const float _frameTime);
	virtual void UpdateTargeting(const float _frameTime);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual Vec3 GetTargetPosition() const;
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual EArkPsiPowers GetEnum() const;
	void OnPlayerEnterLift() const { FOnPlayerEnterLift(this); }
	void OnPlayerExitLift() const { FOnPlayerExitLift(this); }
	bool UpdateTargetingCylinder(const float _frameTime) { return FUpdateTargetingCylinder(this, _frameTime); }
	bool UpdateTargetingCylinderZeroG(const float _frameTime) { return FUpdateTargetingCylinderZeroG(this, _frameTime); }

#if 0
	void DrawTargetingInfo(const Vec3& _arg0_, const Vec3& _arg1_, const ColorB& _arg2_);
	void DrawTargetingInfo(const Vec3& _arg0_, const float _arg1_, const ColorB& _arg2_);
#endif

	static inline auto FCArkPsiPowerLift = PreyFunction<void(CArkPsiPowerLift* const _this)>(0x1596040);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerLift* const _this)>(0x1598620);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerLift* const _this)>(0x1598490);
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerLift* const _this)>(0x1596A60);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerLift* const _this, const float _frameTime)>(0x15993B0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerLift* const _this, const float _frameTime)>(0x1599580);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerLift* const _this, TSerialize _ser)>(0x1598330);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerLift* const _this)>(0x1597B20);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerLift* const _this, Vec3* _return_value_)>(0x1596E40);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerLift* const _this, std::vector<IEntity*>* _return_value_)>(0x1596C60);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerLift* const _this)>(0x13F8580);
	static inline auto FOnPlayerEnterLift = PreyFunction<void(const CArkPsiPowerLift* const _this)>(0x15979A0);
	static inline auto FOnPlayerExitLift = PreyFunction<void(const CArkPsiPowerLift* const _this)>(0x1597A60);
	static inline auto FUpdateTargetingCylinder = PreyFunction<bool(CArkPsiPowerLift* const _this, const float _frameTime)>(0x1599730);
	static inline auto FUpdateTargetingCylinderZeroG = PreyFunction<bool(CArkPsiPowerLift* const _this, const float _frameTime)>(0x159A220);
};

