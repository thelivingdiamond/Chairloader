// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkInputLegend;
class CCryName;
enum class EArkPsiPowers;
class IArkValueBase;
struct IParticleEmitter;

// ArkPsiPowerSmokeFormLevelProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
class ArkPsiPowerSmokeFormLevelProperties : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkPsiCostPerSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiCostPerSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkMaxHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxHeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty>(0x2C04138);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty>(0x2C04158);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty>(0x2C04178);
	float m_CooldownDurationSec;
	static inline auto s_ArkPsiCostPerSecProperty = PreyGlobal<ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty>(0x2C04198);
	float m_PsiCostPerSec;
	static inline auto s_ArkMaxHeightProperty = PreyGlobal<ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty>(0x2C041B8);
	float m_MaxHeight;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetPsiCostPerSec(float _arg0_);
	const float& GetPsiCostPerSec() const;
	void SetMaxHeight(float _arg0_);
	const float& GetMaxHeight() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6460);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A4C10);
};

// ArkPsiPowerSmokeFormUniqueProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
class ArkPsiPowerSmokeFormUniqueProperties : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkSignalModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSignalModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A4050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x1610DD0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x1073510);
	};

	// ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkObjectFadeDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkObjectFadeDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkPostProcessEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostProcessEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkSignalModifiersProperty = PreyGlobal<ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty>(0x2C040D8);
	std::vector<uint64_t> m_SignalModifiers;
	static inline auto s_ArkObjectFadeDistanceProperty = PreyGlobal<ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty>(0x2C040F8);
	float m_ObjectFadeDistance;
	static inline auto s_ArkPostProcessEffectProperty = PreyGlobal<ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty>(0x2C04118);
	uint64_t m_PostProcessEffect;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	std::vector<uint64_t>& GetSignalModifiers();
	const std::vector<uint64_t>& GetSignalModifiers() const;
	void SetObjectFadeDistance(float _arg0_);
	const float& GetObjectFadeDistance() const;
	void SetPostProcessEffect(uint64_t _arg0_);
	const uint64_t& GetPostProcessEffect() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15A48C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A4CB0);
};

// SmokeFormPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
class SmokeFormPowerProperties : public ArkReflectedLibrary
{ // Size=280 (0x118)
public:
	// SmokeFormPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SmokeFormPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SmokeFormPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// SmokeFormPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SmokeFormPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A3D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SmokeFormPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// SmokeFormPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
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

		static inline auto FSetValue = PreyFunction<void(const SmokeFormPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A3F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SmokeFormPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A3FC0);
		static inline auto FIsArray = PreyFunction<bool(const SmokeFormPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const SmokeFormPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x15A4010);
	};

	using LevelProperties = ArkPsiPowerSmokeFormLevelProperties;
	using UniqueProperties = ArkPsiPowerSmokeFormUniqueProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<SmokeFormPowerProperties::ArkCommonProperty>(0x2C041D8);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<SmokeFormPowerProperties::ArkUniqueProperty>(0x2C041F8);
	ArkPsiPowerSmokeFormUniqueProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<SmokeFormPowerProperties::ArkLevelsProperty>(0x2C04218);
	std::vector<ArkPsiPowerSmokeFormLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerSmokeFormUniqueProperties _arg0_);
	const ArkPsiPowerSmokeFormUniqueProperties& GetUnique() const;
	std::vector<ArkPsiPowerSmokeFormLevelProperties>& GetLevels();
	const std::vector<ArkPsiPowerSmokeFormLevelProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15A4900);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A4D50);
	static inline auto FInit = PreyFunction<bool(SmokeFormPowerProperties* const _this)>(0x15A5100);
};

// ArkPsiPowerSmokeForm
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
class ArkPsiPowerSmokeForm : public CArkPsiPower<SmokeFormPowerProperties>
{ // Size=104 (0x68)
public:
	std::vector<unsigned int> m_fadedEntities;
	IParticleEmitter* m_pActiveParticleEmitter;
	bool m_bMorphingIn;
	bool m_bPendingMorphIn;

	ArkPsiPowerSmokeForm();
	virtual bool StartTargeting();
	virtual bool CanEnterFocusMode(const EArkPsiPowers& _equippedPower) const;
	virtual void ProcessInput(const CCryName& _actionId, int _activationMode, float _value);
	virtual EArkPsiPowers GetEnum() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	void MorphIn() { FMorphIn(this); }
	void Exit() { FExit(this); }
	void StartActiveParticleEffect(const char* _pEffectName) { FStartActiveParticleEffect(this, _pEffectName); }
	void StopActiveParticleEffect() { FStopActiveParticleEffect(this); }
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void Update(const float _frameTime);
	virtual bool GetCanCancel() const;
	bool TryMorphOut() { return FTryMorphOut(this); }
	bool CanExit() const { return FCanExit(this); }
	void RestoreOpacities() { FRestoreOpacities(this); }

	static inline auto FArkPsiPowerSmokeFormOv2 = PreyFunction<void(ArkPsiPowerSmokeForm* const _this)>(0x15A4620);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerSmokeForm* const _this)>(0x15A5790);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(const ArkPsiPowerSmokeForm* const _this, const EArkPsiPowers& _equippedPower)>(0x15A47E0);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiPowerSmokeForm* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x15A5540);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerSmokeForm* const _this)>(0x15A4FC0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPsiPowerSmokeForm* const _this)>(0x15A4FF0);
	static inline auto FMorphIn = PreyFunction<void(ArkPsiPowerSmokeForm* const _this)>(0x15A52E0);
	static inline auto FExit = PreyFunction<void(ArkPsiPowerSmokeForm* const _this)>(0x15A49E0);
	static inline auto FStartActiveParticleEffect = PreyFunction<void(ArkPsiPowerSmokeForm* const _this, const char* _pEffectName)>(0x15A5710);
	static inline auto FStopActiveParticleEffect = PreyFunction<void(ArkPsiPowerSmokeForm* const _this)>(0x15A5910);
	static inline auto FStop = PreyFunction<bool(ArkPsiPowerSmokeForm* const _this)>(0x15A58B0);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerSmokeForm* const _this)>(0x15A57F0);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerSmokeForm* const _this, const float _frameTime)>(0x15A5B10);
	static inline auto FGetCanCancel = PreyFunction<bool(const ArkPsiPowerSmokeForm* const _this)>(0x15A4BB0);
	static inline auto FTryMorphOut = PreyFunction<bool(ArkPsiPowerSmokeForm* const _this)>(0x15A5940);
	static inline auto FCanExit = PreyFunction<bool(const ArkPsiPowerSmokeForm* const _this)>(0x15A4800);
	static inline auto FRestoreOpacities = PreyFunction<void(ArkPsiPowerSmokeForm* const _this)>(0x15A55D0);
};
