// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerKineticBlastProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class ArkPsiPowerKineticBlastProperties : public ArkReflectedObject
{ // Size=248 (0xF8)
public:
	// ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkBlastTypePropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastTypePropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1468700);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty>(0x2BF0070);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty>(0x2BF0090);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty>(0x2BF00B0);
	float m_CooldownDurationSec;
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty>(0x2BF00D0);
	ArkPsiKineticBlastProperties m_BlastTypeProperties;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty>(0x2BF00F0);
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
	void SetBlastTypeProperties(ArkPsiKineticBlastProperties _arg0_);
	const ArkPsiKineticBlastProperties& GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1468D70);
};

// KineticBlastPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class KineticBlastPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// KineticBlastPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// KineticBlastPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// KineticBlastPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
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

		static inline auto FSetValue = PreyFunction<void(const KineticBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468730);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1468830);
		static inline auto FIsArray = PreyFunction<bool(const KineticBlastPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const KineticBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1466DB0);
	};

	using LevelProperties = ArkPsiPowerKineticBlastProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<KineticBlastPowerProperties::ArkCommonProperty>(0x2BF0110);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<KineticBlastPowerProperties::ArkUniqueProperty>(0x2BF0130);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<KineticBlastPowerProperties::ArkLevelsProperty>(0x2BF0150);
	std::vector<ArkPsiPowerKineticBlastProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerKineticBlastProperties>& GetLevels();
	const std::vector<ArkPsiPowerKineticBlastProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1468CF0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1468E10);
	static inline auto FInit = PreyFunction<bool(KineticBlastPowerProperties* const _this)>(0x1468F00);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerKineticBlastProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class ArkPsiPowerKineticBlastProperties : public ArkReflectedObject
{ // Size=248 (0xF8)
public:
	// ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkBlastTypePropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastTypePropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157E5D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157E610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty>(0x2D6ABF8);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty>(0x2D6AC18);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty>(0x2D6AC38);
	float m_CooldownDurationSec;
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty>(0x2D6AC58);
	ArkPsiKineticBlastProperties m_BlastTypeProperties;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty>(0x2D6AC78);
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
	void SetBlastTypeProperties(ArkPsiKineticBlastProperties _arg0_);
	const ArkPsiKineticBlastProperties& GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16AB9E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1580620);
};

// KineticBlastPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class KineticBlastPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// KineticBlastPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// KineticBlastPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// KineticBlastPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
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

		static inline auto FSetValue = PreyFunction<void(const KineticBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157FEE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x157FFE0);
		static inline auto FIsArray = PreyFunction<bool(const KineticBlastPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const KineticBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x157E7A0);
	};

	using LevelProperties = ArkPsiPowerKineticBlastProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<KineticBlastPowerProperties::ArkCommonProperty>(0x2D6AC98);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<KineticBlastPowerProperties::ArkUniqueProperty>(0x2D6ACB8);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<KineticBlastPowerProperties::ArkLevelsProperty>(0x2D6ACD8);
	std::vector<ArkPsiPowerKineticBlastProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerKineticBlastProperties>& GetLevels();
	const std::vector<ArkPsiPowerKineticBlastProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1580550);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15806C0);
	static inline auto FInit = PreyFunction<bool(KineticBlastPowerProperties* const _this)>(0x15807B0);
};
#endif // !MOONCRASH
