// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryPhysics/primitives.h>
#include <Prey/GameDll/ark/player/arkplayerlight.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLift.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolume.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h>

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class LiftPowerProperties : public ArkReflectedLibrary // Id=8017561 Size=344
{
public:
	using LevelProperties = ArkPsiPowerLiftLevelProperties;
	using UniqueProperties = ArkPsiPowerLiftUniqueProperties;

	class ArkCommonProperty : public ArkProperty // Id=8017562 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(LiftPowerProperties::ArkCommonProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (LiftPowerProperties::ArkCommonProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	static LiftPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;

	class ArkUniqueProperty : public ArkProperty // Id=8017563 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(LiftPowerProperties::ArkUniqueProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x12F5C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (LiftPowerProperties::ArkUniqueProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	static LiftPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerLiftUniqueProperties m_Unique;

	class ArkLevelsProperty : public ArkProperty // Id=8017564 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(LiftPowerProperties::ArkLevelsProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x12F5EA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (LiftPowerProperties::ArkLevelsProperty const* const _this, ArkReflectedObject* const _pObject)>(0x12F5F50);
		static inline auto FIsArray = PreyFunction<bool(LiftPowerProperties::ArkLevelsProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(LiftPowerProperties::ArkLevelsProperty const* const _this, ArkReflectedObject* _pObject)>(0x12F5FA0);
	};

	static LiftPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerLiftLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~LiftPowerProperties();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const& GetCommon() const;
	void SetUnique(ArkPsiPowerLiftUniqueProperties arg0);
	ArkPsiPowerLiftUniqueProperties const& GetUnique() const;
	std::vector<ArkPsiPowerLiftLevelProperties>& GetLevels();
	std::vector<ArkPsiPowerLiftLevelProperties> const& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F64F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F67C0);
	static inline auto FInit = PreyFunction<bool(LiftPowerProperties* const _this)>(0x12F68B0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowerlift.h
class CArkPsiPowerLift : public CArkPsiPower<LiftPowerProperties> // Id=801B7A6 Size=368
{
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
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual EArkPsiPowers GetEnum() const;
	void OnPlayerEnterLift() const { FOnPlayerEnterLift(this); }
	void OnPlayerExitLift() const { FOnPlayerExitLift(this); }
	bool UpdateTargetingCylinder(const float _frameTime) { return FUpdateTargetingCylinder(this,_frameTime); }
	bool UpdateTargetingCylinderZeroG(const float _frameTime) { return FUpdateTargetingCylinderZeroG(this,_frameTime); }
	
#if 0
	void DrawTargetingInfo(Vec3 const &arg0, Vec3 const &arg1, ColorB const &arg2);
	void DrawTargetingInfo(Vec3 const &arg0, const float arg1, ColorB const &arg2);
#endif
	
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerLift *const _this)>(0x1598620);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerLift *const _this)>(0x1598490);
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerLift *const _this)>(0x1596A60);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerLift *const _this, const float _frameTime)>(0x15993B0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerLift *const _this, const float _frameTime)>(0x1599580);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerLift *const _this, TSerialize _ser)>(0x1598330);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerLift *const _this)>(0x1597B20);
	static inline auto FGetTargetPosition = PreyFunction<Vec3(CArkPsiPowerLift const *const _this)>(0x1596E40);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity *>(CArkPsiPowerLift const *const _this)>(0x1596C60);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(CArkPsiPowerLift const *const _this)>(0x13F8580);
	static inline auto FOnPlayerEnterLift = PreyFunction<void(CArkPsiPowerLift const *const _this)>(0x15979A0);
	static inline auto FOnPlayerExitLift = PreyFunction<void(CArkPsiPowerLift const *const _this)>(0x1597A60);
	static inline auto FUpdateTargetingCylinder = PreyFunction<bool(CArkPsiPowerLift *const _this, const float _frameTime)>(0x1599730);
	static inline auto FUpdateTargetingCylinderZeroG = PreyFunction<bool(CArkPsiPowerLift *const _this, const float _frameTime)>(0x159A220);
};

