// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/psicommon/arkpsifearblast.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerFearProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
class ArkPsiPowerFearProperties : public ArkReflectedObject
{ // Size=248 (0xF8)
public:
	// ArkPsiPowerFearProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

	// ArkPsiPowerFearProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

	// ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

	// ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkBlastTypePropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastTypePropertiesProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157E5D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

	// ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1468700);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157E610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkDisplayNameProperty>(0x2C034F0);
#else
	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkDisplayNameProperty>(0x2D7DDD8);
#endif
	string m_DisplayName;
#ifndef MOONCRASH
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkDescriptionProperty>(0x2C03510);
#else
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkDescriptionProperty>(0x2D7DDF8);
#endif
	string m_Description;
#ifndef MOONCRASH
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty>(0x2C03530);
#else
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty>(0x2D7DE18);
#endif
	float m_CooldownDurationSec;
#ifndef MOONCRASH
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty>(0x2C03550);
#else
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty>(0x2D7DE38);
#endif
	ArkPsiFearBlastProperties m_BlastTypeProperties;
#ifndef MOONCRASH
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty>(0x2C03570);
#else
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty>(0x2D7DE58);
#endif
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetBlastTypeProperties(ArkPsiFearBlastProperties _arg0_);
	const ArkPsiFearBlastProperties& GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1584910);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16AB9E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x16ABB70);
#endif
};

// FearPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
class FearPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// FearPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const FearPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const FearPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
#else
		static inline auto FSetValue = PreyFunction<void(const FearPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const FearPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
#endif
	};

	// FearPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const FearPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const FearPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
#else
		static inline auto FSetValue = PreyFunction<void(const FearPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const FearPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
#endif
	};

	// FearPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const FearPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15840B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const FearPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x15841B0);
		static inline auto FIsArray = PreyFunction<bool(const FearPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const FearPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1466DB0);
#else
		static inline auto FSetValue = PreyFunction<void(const FearPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16AB440);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const FearPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x16AB540);
		static inline auto FIsArray = PreyFunction<bool(const FearPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const FearPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x157E7A0);
#endif
	};

	using LevelProperties = ArkPsiPowerFearProperties;
	using UniqueProperties = bool;

#ifndef MOONCRASH
	static inline auto s_ArkCommonProperty = PreyGlobal<FearPowerProperties::ArkCommonProperty>(0x2C03590);
#else
	static inline auto s_ArkCommonProperty = PreyGlobal<FearPowerProperties::ArkCommonProperty>(0x2D7DE78);
#endif
	ArkPsiPowerCommonProperties m_Common;
#ifndef MOONCRASH
	static inline auto s_ArkUniqueProperty = PreyGlobal<FearPowerProperties::ArkUniqueProperty>(0x2C035B0);
#else
	static inline auto s_ArkUniqueProperty = PreyGlobal<FearPowerProperties::ArkUniqueProperty>(0x2D7DE98);
#endif
	bool m_Unique;
#ifndef MOONCRASH
	static inline auto s_ArkLevelsProperty = PreyGlobal<FearPowerProperties::ArkLevelsProperty>(0x2C035D0);
#else
	static inline auto s_ArkLevelsProperty = PreyGlobal<FearPowerProperties::ArkLevelsProperty>(0x2D7DEB8);
#endif
	std::vector<ArkPsiPowerFearProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerFearProperties>& GetLevels();
	const std::vector<ArkPsiPowerFearProperties>& GetLevels() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1584890);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15849B0);
	static inline auto FInit = PreyFunction<bool(FearPowerProperties* const _this)>(0x1584AA0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16ABAA0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x16ABC10);
	static inline auto FInit = PreyFunction<bool(FearPowerProperties* const _this)>(0x16ABD00);
#endif
};
