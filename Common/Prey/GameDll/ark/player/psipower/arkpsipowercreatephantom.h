// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercreatephantom.h
class ArkPsiPowerCreatePhantomCommonProperties : public ArkReflectedObject // Id=80192D8 Size=40
{
public:
	class ArkRaiseHeightProperty : public ArkProperty // Id=80192D9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty s_ArkRaiseHeightProperty;
	float m_RaiseHeight;
	
	class ArkRaiseSpeedProperty : public ArkProperty // Id=80192DA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty s_ArkRaiseSpeedProperty;
	float m_RaiseSpeed;
	
	class ArkRaiseDurationProperty : public ArkProperty // Id=80192DB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty s_ArkRaiseDurationProperty;
	float m_RaiseDuration;
	
	class ArkCorpseDampingProperty : public ArkProperty // Id=80192DC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty s_ArkCorpseDampingProperty;
	float m_CorpseDamping;
	
	class ArkCorpseGravityProperty : public ArkProperty // Id=80192DD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty s_ArkCorpseGravityProperty;
	float m_CorpseGravity;
	
	class ArkCorpseParticleEffectProperty : public ArkProperty // Id=80192DE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty s_ArkCorpseParticleEffectProperty;
	string m_CorpseParticleEffect;
	
	class ArkCorpseParticleEffectAttachmentProperty : public ArkProperty // Id=80192DF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty s_ArkCorpseParticleEffectAttachmentProperty;
	string m_CorpseParticleEffectAttachment;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetRaiseHeight(float arg0);
	const float &GetRaiseHeight() const;
	void SetRaiseSpeed(float arg0);
	const float &GetRaiseSpeed() const;
	void SetRaiseDuration(float arg0);
	const float &GetRaiseDuration() const;
	void SetCorpseDamping(float arg0);
	const float &GetCorpseDamping() const;
	void SetCorpseGravity(float arg0);
	const float &GetCorpseGravity() const;
	void SetCorpseParticleEffect(string arg0);
	string const &GetCorpseParticleEffect() const;
	void SetCorpseParticleEffectAttachment(string arg0);
	string const &GetCorpseParticleEffectAttachment() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1332190);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x13323C0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercreatephantom.h
class ArkPsiPowerCreatePhantomProperties : public ArkReflectedObject // Id=80192E0 Size=128
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=80192E1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=80192E2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=80192E3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=80192E4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1330CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	
	class ArkArchetypesProperty : public ArkProperty // Id=80192E5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1330CF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1330D50);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1330D70);
	};

	static ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty s_ArkArchetypesProperty;
	std::vector<string> m_Archetypes;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
	std::vector<string> &GetArchetypes();
	std::vector<string> const &GetArchetypes() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13321D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1332460);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercreatephantom.h
class CreatePhantomPowerProperties : public ArkReflectedLibrary // Id=80192E7 Size=280
{
public:
	using LevelProperties = ArkPsiPowerCreatePhantomProperties;
	using UniqueProperties = ArkPsiPowerCreatePhantomCommonProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=80192E8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CreatePhantomPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CreatePhantomPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static CreatePhantomPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=80192E9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CreatePhantomPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1330D80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CreatePhantomPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static CreatePhantomPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerCreatePhantomCommonProperties m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=80192EA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CreatePhantomPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1330E90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CreatePhantomPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1330F90);
		static inline auto FIsArray = PreyFunction<bool(CreatePhantomPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(CreatePhantomPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1330FE0);
	};

	static CreatePhantomPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerCreatePhantomProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(ArkPsiPowerCreatePhantomCommonProperties arg0);
	ArkPsiPowerCreatePhantomCommonProperties const &GetUnique() const;
	std::vector<ArkPsiPowerCreatePhantomProperties> &GetLevels();
	std::vector<ArkPsiPowerCreatePhantomProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1332250);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1332500);
	static inline auto FInit = PreyFunction<bool(CreatePhantomPowerProperties *const _this)>(0x13327E0);
};

