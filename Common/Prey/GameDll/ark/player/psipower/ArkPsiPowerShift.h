// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowershift.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
struct IEntity;
struct IParticleEffect;
class ArkEtherDuplicate;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowershift.h
class ArkPsiPowerShiftUniqueProperties : public ArkReflectedObject // Id=8019313 Size=24
{
public:
	class ArkSpawnDuplicateParticleEffectProperty : public ArkProperty // Id=8019314 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty s_ArkSpawnDuplicateParticleEffectProperty;
	string m_SpawnDuplicateParticleEffect;
	
	class ArkDestroyDuplicateParticleEffectProperty : public ArkProperty // Id=8019315 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty s_ArkDestroyDuplicateParticleEffectProperty;
	string m_DestroyDuplicateParticleEffect;
	
	class ArkDuplicateParticleEffectAttachmentProperty : public ArkProperty // Id=8019316 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty s_ArkDuplicateParticleEffectAttachmentProperty;
	string m_DuplicateParticleEffectAttachment;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetSpawnDuplicateParticleEffect(string arg0);
	string const &GetSpawnDuplicateParticleEffect() const;
	void SetDestroyDuplicateParticleEffect(string arg0);
	string const &GetDestroyDuplicateParticleEffect() const;
	void SetDuplicateParticleEffectAttachment(string arg0);
	string const &GetDuplicateParticleEffectAttachment() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13261C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x13266C0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowershift.h
class ArkPsiPowerShiftLevelProperties : public ArkReflectedObject // Id=8019317 Size=40
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=8019318 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=8019319 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801931A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkShiftDistanceProperty : public ArkProperty // Id=801931B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty s_ArkShiftDistanceProperty;
	float m_ShiftDistance;
	
	class ArkShiftDelaySecProperty : public ArkProperty // Id=801931C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty s_ArkShiftDelaySecProperty;
	float m_ShiftDelaySec;
	
	class ArkDuplicateDurationSecProperty : public ArkProperty // Id=801931D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty s_ArkDuplicateDurationSecProperty;
	float m_DuplicateDurationSec;
	
	class ArkOmniDirectionalProperty : public ArkProperty // Id=801931E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty s_ArkOmniDirectionalProperty;
	bool m_OmniDirectional;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetShiftDistance(float arg0);
	const float &GetShiftDistance() const;
	void SetShiftDelaySec(float arg0);
	const float &GetShiftDelaySec() const;
	void SetDuplicateDurationSec(float arg0);
	const float &GetDuplicateDurationSec() const;
	void SetOmniDirectional(bool arg0);
	const bool &GetOmniDirectional() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1326180);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1326620);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowershift.h
class ShiftPowerProperties : public ArkReflectedLibrary // Id=801931F Size=264
{
public:
	using LevelProperties = ArkPsiPowerShiftLevelProperties;
	using UniqueProperties = ArkPsiPowerShiftUniqueProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=8019320 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ShiftPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ShiftPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ShiftPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=8019321 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ShiftPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1324D60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ShiftPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static ShiftPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerShiftUniqueProperties m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=8019322 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ShiftPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1324E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ShiftPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1324EC0);
		static inline auto FIsArray = PreyFunction<bool(ShiftPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ShiftPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1324F10);
	};

	static ShiftPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerShiftLevelProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ShiftPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(ArkPsiPowerShiftUniqueProperties arg0);
	ArkPsiPowerShiftUniqueProperties const &GetUnique() const;
	std::vector<ArkPsiPowerShiftLevelProperties> &GetLevels();
	std::vector<ArkPsiPowerShiftLevelProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13261F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1326760);
	static inline auto FInit = PreyFunction<bool(ShiftPowerProperties *const _this)>(0x1326A60);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
class ArkPsiPowerShift : public CArkPsiPower<ShiftPowerProperties> // Id=8019332 Size=136
{
public:
	ArkSimpleTimer m_shiftDelayTimer;
	ArkSimpleTimer m_duplicateTimer;
	Vec3 m_initialPosition;
	Vec3 m_desiredPosition;
	std::unique_ptr<ArkEtherDuplicate> m_pDuplicate;
	_smart_ptr<IParticleEffect> m_pSpawnDuplicateEffect;
	_smart_ptr<IParticleEffect> m_pDestroyDuplicateEffect;
	bool m_bPendingShift;
	
	ArkPsiPowerShift();
	virtual ~ArkPsiPowerShift();
	virtual void OnReset();
	virtual bool StartTargeting();
	virtual void Update(const float _frameTime);
	virtual void UpdateTargeting(const float _frameTime);
	virtual void Serialize(TSerialize _ser);
	virtual EArkPsiPowers GetEnum() const;
	unsigned GetDuplicateEntityId() const { return FGetDuplicateEntityId(this); }
	static bool IsEtherDuplicate(IEntity const &_entity) { return FIsEtherDuplicate(_entity); }
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	virtual const char *GetErrorString() const;
	bool PerformShift() { return FPerformShift(this); }
	void SpawnDuplicate() { FSpawnDuplicate(this); }
	void ComputeShiftTarget() { FComputeShiftTarget(this); }
	void SpawnEffect(IParticleEffect *_pEffect) const { FSpawnEffect(this,_pEffect); }
	bool DuplicateCanFit(Vec3 const &_position) const { return FDuplicateCanFit(this,_position); }
	
#if 0
	void DrawDebug() const;
#endif
	
	static inline auto FOnReset = PreyFunction<void(ArkPsiPowerShift *const _this)>(0x1326D60);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerShift *const _this)>(0x1593E70);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerShift *const _this, const float _frameTime)>(0x1327B10);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerShift *const _this, const float _frameTime)>(0xA13080);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerShift *const _this, TSerialize _ser)>(0x1326F70);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(ArkPsiPowerShift const *const _this)>(0x1907EE0);
	static inline auto FGetDuplicateEntityId = PreyFunction<unsigned(ArkPsiPowerShift const *const _this)>(0x1326A10);
	static inline auto FIsEtherDuplicate = PreyFunction<bool(IEntity const &_entity)>(0x1326C40);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerShift *const _this)>(0x1327AA0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerShift *const _this, const int _level)>(0x13271E0);
	static inline auto FGetErrorString = PreyFunction<const char *(ArkPsiPowerShift const *const _this)>(0x158AEF0);
	static inline auto FPerformShift = PreyFunction<bool(ArkPsiPowerShift *const _this)>(0x1326DA0);
	static inline auto FSpawnDuplicate = PreyFunction<void(ArkPsiPowerShift *const _this)>(0x1327260);
	static inline auto FComputeShiftTarget = PreyFunction<void(ArkPsiPowerShift *const _this)>(0x1325CD0);
	static inline auto FSpawnEffect = PreyFunction<void(ArkPsiPowerShift const *const _this, IParticleEffect *_pEffect)>(0x1327780);
	static inline auto FDuplicateCanFit = PreyFunction<bool(ArkPsiPowerShift const *const _this, Vec3 const &_position)>(0x1326290);
};

