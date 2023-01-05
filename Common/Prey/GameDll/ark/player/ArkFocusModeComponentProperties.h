// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkClass;
class ArkReflectedObject;
class IArkValueBase;

// ArkFocusModeComponentProperties
// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
class ArkFocusModeComponentProperties : public ArkReflectedLibrary
{ // Size=192 (0xC0)
public:
	// ArkFocusModeComponentProperties::ArkMouseSensitivityProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkMouseSensitivityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMouseSensitivityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkMouseSensitivityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkMouseSensitivityProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkMouseRotationSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMouseRotationSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1360080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6320);
	};

	// ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkMouseRotationDampingProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMouseRotationDampingProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty* const _this, ArkReflectedObject* const _pObject)>(0x1068E60);
	};

	// ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkControllerAbsoluteDeadzoneProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkControllerAbsoluteDeadzoneProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221B00);
	};

	// ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkControllerDeltaDeadzoneProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkControllerDeltaDeadzoneProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A6340);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6360);
	};

	// ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkControllerInactiveStickDeadzoneProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkControllerInactiveStickDeadzoneProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221B20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6380);
	};

	// ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkDefaultPostProcessEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultPostProcessEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1360170);
	};

	// ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkPsiPostProcessEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiPostProcessEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1066110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221B60);
	};

	// ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkFocusParticleEffectPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFocusParticleEffectPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x105A980);
	};

	// ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkExitFromFocusParticleEffectPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExitFromFocusParticleEffectPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221C40);
	};

	// ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkPsiParticleEffectPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiParticleEffectPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221C60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x105AA60);
	};

	// ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkExitFromPsiParticleEffectPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExitFromPsiParticleEffectPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x105AA80);
	};

	// ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkFocusToPsiParticleEffectPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFocusToPsiParticleEffectPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105AB00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221D20);
	};

	// ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkPsiToFocusParticleEffectPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiToFocusParticleEffectPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221DA0);
	};

	// ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkSelectPowerLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSelectPowerLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x1066210);
	};

	// ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkSelectWeaponLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSelectWeaponLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221E70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A6230);
	};

	// ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkNoPowersAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoPowersAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1221F90);
	};

	// ArkFocusModeComponentProperties::ArkNoPowersStringsProperty
	// Header:  Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
	class ArkNoPowersStringsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkNoPowersStringsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFocusModeComponentProperties::ArkNoPowersStringsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1221FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFocusModeComponentProperties::ArkNoPowersStringsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1222020);
		static inline auto FIsArray = PreyFunction<bool(const ArkFocusModeComponentProperties::ArkNoPowersStringsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkFocusModeComponentProperties::ArkNoPowersStringsProperty* const _this, ArkReflectedObject* _pObject)>(0x1222070);
	};

	static inline auto s_ArkMouseSensitivityProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkMouseSensitivityProperty>(0x2BD3218);
	float m_MouseSensitivity;
	static inline auto s_ArkMouseRotationSpeedProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty>(0x2BD3238);
	float m_MouseRotationSpeed;
	static inline auto s_ArkMouseRotationDampingProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty>(0x2BD3258);
	float m_MouseRotationDamping;
	static inline auto s_ArkControllerAbsoluteDeadzoneProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty>(0x2BD3278);
	float m_ControllerAbsoluteDeadzone;
	static inline auto s_ArkControllerDeltaDeadzoneProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty>(0x2BD3298);
	float m_ControllerDeltaDeadzone;
	static inline auto s_ArkControllerInactiveStickDeadzoneProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty>(0x2BD32B8);
	float m_ControllerInactiveStickDeadzone;
	static inline auto s_ArkDefaultPostProcessEffectProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty>(0x2BD32D8);
	uint64_t m_DefaultPostProcessEffect;
	static inline auto s_ArkPsiPostProcessEffectProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty>(0x2BD32F8);
	uint64_t m_PsiPostProcessEffect;
	static inline auto s_ArkFocusParticleEffectPathProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty>(0x2BD3318);
	string m_FocusParticleEffectPath;
	static inline auto s_ArkExitFromFocusParticleEffectPathProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty>(0x2BD3338);
	string m_ExitFromFocusParticleEffectPath;
	static inline auto s_ArkPsiParticleEffectPathProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty>(0x2BD3358);
	string m_PsiParticleEffectPath;
	static inline auto s_ArkExitFromPsiParticleEffectPathProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty>(0x2BD3378);
	string m_ExitFromPsiParticleEffectPath;
	static inline auto s_ArkFocusToPsiParticleEffectPathProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty>(0x2BD3398);
	string m_FocusToPsiParticleEffectPath;
	static inline auto s_ArkPsiToFocusParticleEffectPathProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty>(0x2BD33B8);
	string m_PsiToFocusParticleEffectPath;
	static inline auto s_ArkSelectPowerLegendProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty>(0x2BD33D8);
	ArkInputLegend m_SelectPowerLegend;
	static inline auto s_ArkSelectWeaponLegendProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty>(0x2BD33F8);
	ArkInputLegend m_SelectWeaponLegend;
	static inline auto s_ArkNoPowersAudioTriggerProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty>(0x2BD3418);
	string m_NoPowersAudioTrigger;
	static inline auto s_ArkNoPowersStringsProperty = PreyGlobal<ArkFocusModeComponentProperties::ArkNoPowersStringsProperty>(0x2BD3438);
	std::vector<string> m_NoPowersStrings;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetMouseSensitivity(float _arg0_);
	const float& GetMouseSensitivity() const;
	void SetMouseRotationSpeed(float _arg0_);
	const float& GetMouseRotationSpeed() const;
	void SetMouseRotationDamping(float _arg0_);
	const float& GetMouseRotationDamping() const;
	void SetControllerAbsoluteDeadzone(float _arg0_);
	const float& GetControllerAbsoluteDeadzone() const;
	void SetControllerDeltaDeadzone(float _arg0_);
	const float& GetControllerDeltaDeadzone() const;
	void SetControllerInactiveStickDeadzone(float _arg0_);
	const float& GetControllerInactiveStickDeadzone() const;
	void SetDefaultPostProcessEffect(uint64_t _arg0_);
	const uint64_t& GetDefaultPostProcessEffect() const;
	void SetPsiPostProcessEffect(uint64_t _arg0_);
	const uint64_t& GetPsiPostProcessEffect() const;
	void SetFocusParticleEffectPath(string _arg0_);
	const string& GetFocusParticleEffectPath() const;
	void SetExitFromFocusParticleEffectPath(string _arg0_);
	const string& GetExitFromFocusParticleEffectPath() const;
	void SetPsiParticleEffectPath(string _arg0_);
	const string& GetPsiParticleEffectPath() const;
	void SetExitFromPsiParticleEffectPath(string _arg0_);
	const string& GetExitFromPsiParticleEffectPath() const;
	void SetFocusToPsiParticleEffectPath(string _arg0_);
	const string& GetFocusToPsiParticleEffectPath() const;
	void SetPsiToFocusParticleEffectPath(string _arg0_);
	const string& GetPsiToFocusParticleEffectPath() const;
	void SetSelectPowerLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetSelectPowerLegend() const;
	void SetSelectWeaponLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetSelectWeaponLegend() const;
	void SetNoPowersAudioTrigger(string _arg0_);
	const string& GetNoPowersAudioTrigger() const;
	std::vector<string>& GetNoPowersStrings();
	const std::vector<string>& GetNoPowersStrings() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1222DF0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1222EB0);
	static inline auto FInit = PreyFunction<bool(ArkFocusModeComponentProperties* const _this)>(0x1223000);
};

