// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkEtherDuplicate;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
struct IParticleEffect;

// ArkPsiPowerShiftLevelProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
class ArkPsiPowerShiftLevelProperties : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkShiftDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkShiftDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkShiftDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkShiftDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkDuplicateDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDuplicateDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
	};

	// ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkOmniDirectionalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOmniDirectionalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkDisplayNameProperty>(0x2BDA7F8);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkDescriptionProperty>(0x2BDA818);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkCooldownDurationSecProperty>(0x2BDA838);
	float m_CooldownDurationSec;
	static inline auto s_ArkShiftDistanceProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkShiftDistanceProperty>(0x2BDA858);
	float m_ShiftDistance;
	static inline auto s_ArkShiftDelaySecProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkShiftDelaySecProperty>(0x2BDA878);
	float m_ShiftDelaySec;
	static inline auto s_ArkDuplicateDurationSecProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkDuplicateDurationSecProperty>(0x2BDA898);
	float m_DuplicateDurationSec;
	static inline auto s_ArkOmniDirectionalProperty = PreyGlobal<ArkPsiPowerShiftLevelProperties::ArkOmniDirectionalProperty>(0x2BDA8B8);
	bool m_OmniDirectional;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetShiftDistance(float _arg0_);
	const float& GetShiftDistance() const;
	void SetShiftDelaySec(float _arg0_);
	const float& GetShiftDelaySec() const;
	void SetDuplicateDurationSec(float _arg0_);
	const float& GetDuplicateDurationSec() const;
	void SetOmniDirectional(bool _arg0_);
	const bool& GetOmniDirectional() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1326180);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1326620);
};

// ArkPsiPowerShiftUniqueProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
class ArkPsiPowerShiftUniqueProperties : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkSpawnDuplicateParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSpawnDuplicateParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkDestroyDuplicateParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDestroyDuplicateParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkDuplicateParticleEffectAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDuplicateParticleEffectAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	static inline auto s_ArkSpawnDuplicateParticleEffectProperty = PreyGlobal<ArkPsiPowerShiftUniqueProperties::ArkSpawnDuplicateParticleEffectProperty>(0x2BDA798);
	string m_SpawnDuplicateParticleEffect;
	static inline auto s_ArkDestroyDuplicateParticleEffectProperty = PreyGlobal<ArkPsiPowerShiftUniqueProperties::ArkDestroyDuplicateParticleEffectProperty>(0x2BDA7B8);
	string m_DestroyDuplicateParticleEffect;
	static inline auto s_ArkDuplicateParticleEffectAttachmentProperty = PreyGlobal<ArkPsiPowerShiftUniqueProperties::ArkDuplicateParticleEffectAttachmentProperty>(0x2BDA7D8);
	string m_DuplicateParticleEffectAttachment;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetSpawnDuplicateParticleEffect(string _arg0_);
	const string& GetSpawnDuplicateParticleEffect() const;
	void SetDestroyDuplicateParticleEffect(string _arg0_);
	const string& GetDestroyDuplicateParticleEffect() const;
	void SetDuplicateParticleEffectAttachment(string _arg0_);
	const string& GetDuplicateParticleEffectAttachment() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13261C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13266C0);
};

// ShiftPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
class ShiftPowerProperties : public ArkReflectedLibrary
{ // Size=264 (0x108)
public:
	// ShiftPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ShiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ShiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// ShiftPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ShiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1324D60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ShiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// ShiftPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
	class ArkLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLevelsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ShiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1324E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ShiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1324EC0);
		static inline auto FIsArray = PreyFunction<bool(const ShiftPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ShiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1324F10);
	};

	using LevelProperties = ArkPsiPowerShiftLevelProperties;
	using UniqueProperties = ArkPsiPowerShiftUniqueProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<ShiftPowerProperties::ArkCommonProperty>(0x2BDA8D8);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<ShiftPowerProperties::ArkUniqueProperty>(0x2BDA8F8);
	ArkPsiPowerShiftUniqueProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<ShiftPowerProperties::ArkLevelsProperty>(0x2BDA918);
	std::vector<ArkPsiPowerShiftLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerShiftUniqueProperties _arg0_);
	const ArkPsiPowerShiftUniqueProperties& GetUnique() const;
	std::vector<ArkPsiPowerShiftLevelProperties>& GetLevels();
	const std::vector<ArkPsiPowerShiftLevelProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13261F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1326760);
	static inline auto FInit = PreyFunction<bool(ShiftPowerProperties* const _this)>(0x1326A60);
};

// ArkPsiPowerShift
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerShift.h
class ArkPsiPowerShift : public CArkPsiPower<ShiftPowerProperties>
{ // Size=136 (0x88)
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
	static bool IsEtherDuplicate(const IEntity& _entity) { return FIsEtherDuplicate(_entity); }
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	virtual const char* GetErrorString() const;
	bool PerformShift() { return FPerformShift(this); }
	void SpawnDuplicate() { FSpawnDuplicate(this); }
	void ComputeShiftTarget() { FComputeShiftTarget(this); }
	void SpawnEffect(IParticleEffect* _pEffect) const { FSpawnEffect(this, _pEffect); }
	bool DuplicateCanFit(const Vec3& _position) const { return FDuplicateCanFit(this, _position); }

#if 0
	void DrawDebug() const;
#endif

	static inline auto FArkPsiPowerShift = PreyFunction<void(ArkPsiPowerShift* const _this)>(0x1325580);
	static inline auto FOnReset = PreyFunction<void(ArkPsiPowerShift* const _this)>(0x1326D60);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerShift* const _this)>(0x1593E70);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerShift* const _this, const float _frameTime)>(0x1327B10);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerShift* const _this, const float _frameTime)>(0xA13080);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerShift* const _this, TSerialize _ser)>(0x1326F70);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerShift* const _this)>(0x1907EE0);
	static inline auto FGetDuplicateEntityId = PreyFunction<unsigned(const ArkPsiPowerShift* const _this)>(0x1326A10);
	static inline auto FIsEtherDuplicate = PreyFunction<bool(const IEntity& _entity)>(0x1326C40);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerShift* const _this)>(0x1327AA0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerShift* const _this, const int _level)>(0x13271E0);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkPsiPowerShift* const _this)>(0x158AEF0);
	static inline auto FPerformShift = PreyFunction<bool(ArkPsiPowerShift* const _this)>(0x1326DA0);
	static inline auto FSpawnDuplicate = PreyFunction<void(ArkPsiPowerShift* const _this)>(0x1327260);
	static inline auto FComputeShiftTarget = PreyFunction<void(ArkPsiPowerShift* const _this)>(0x1325CD0);
	static inline auto FSpawnEffect = PreyFunction<void(const ArkPsiPowerShift* const _this, IParticleEffect* _pEffect)>(0x1327780);
	static inline auto FDuplicateCanFit = PreyFunction<bool(const ArkPsiPowerShift* const _this, const Vec3& _position)>(0x1326290);
};

