// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkClass;
class ArkReflectedObject;

// Header: Exact
// Prey/GameDll/ark/player/ArkFocusModeComponentProperties.h
class ArkFocusModeComponentProperties : public ArkReflectedLibrary // Id=801729E Size=192
{
public:
	class ArkMouseSensitivityProperty : public ArkProperty // Id=801729F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkMouseSensitivityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkMouseSensitivityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkFocusModeComponentProperties::ArkMouseSensitivityProperty s_ArkMouseSensitivityProperty;
	float m_MouseSensitivity;
	
	class ArkMouseRotationSpeedProperty : public ArkProperty // Id=80172A0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6320);
	};

	static ArkFocusModeComponentProperties::ArkMouseRotationSpeedProperty s_ArkMouseRotationSpeedProperty;
	float m_MouseRotationSpeed;
	
	class ArkMouseRotationDampingProperty : public ArkProperty // Id=80172A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkFocusModeComponentProperties::ArkMouseRotationDampingProperty s_ArkMouseRotationDampingProperty;
	float m_MouseRotationDamping;
	
	class ArkControllerAbsoluteDeadzoneProperty : public ArkProperty // Id=80172A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B00);
	};

	static ArkFocusModeComponentProperties::ArkControllerAbsoluteDeadzoneProperty s_ArkControllerAbsoluteDeadzoneProperty;
	float m_ControllerAbsoluteDeadzone;
	
	class ArkControllerDeltaDeadzoneProperty : public ArkProperty // Id=80172A3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A6340);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkFocusModeComponentProperties::ArkControllerDeltaDeadzoneProperty s_ArkControllerDeltaDeadzoneProperty;
	float m_ControllerDeltaDeadzone;
	
	class ArkControllerInactiveStickDeadzoneProperty : public ArkProperty // Id=80172A4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221B20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6380);
	};

	static ArkFocusModeComponentProperties::ArkControllerInactiveStickDeadzoneProperty s_ArkControllerInactiveStickDeadzoneProperty;
	float m_ControllerInactiveStickDeadzone;
	
	class ArkDefaultPostProcessEffectProperty : public ArkProperty // Id=80172A5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
	};

	static ArkFocusModeComponentProperties::ArkDefaultPostProcessEffectProperty s_ArkDefaultPostProcessEffectProperty;
	uint64_t m_DefaultPostProcessEffect;
	
	class ArkPsiPostProcessEffectProperty : public ArkProperty // Id=80172A6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B60);
	};

	static ArkFocusModeComponentProperties::ArkPsiPostProcessEffectProperty s_ArkPsiPostProcessEffectProperty;
	uint64_t m_PsiPostProcessEffect;
	
	class ArkFocusParticleEffectPathProperty : public ArkProperty // Id=80172A7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105A980);
	};

	static ArkFocusModeComponentProperties::ArkFocusParticleEffectPathProperty s_ArkFocusParticleEffectPathProperty;
	string m_FocusParticleEffectPath;
	
	class ArkExitFromFocusParticleEffectPathProperty : public ArkProperty // Id=80172A8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221C40);
	};

	static ArkFocusModeComponentProperties::ArkExitFromFocusParticleEffectPathProperty s_ArkExitFromFocusParticleEffectPathProperty;
	string m_ExitFromFocusParticleEffectPath;
	
	class ArkPsiParticleEffectPathProperty : public ArkProperty // Id=80172A9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221C60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA60);
	};

	static ArkFocusModeComponentProperties::ArkPsiParticleEffectPathProperty s_ArkPsiParticleEffectPathProperty;
	string m_PsiParticleEffectPath;
	
	class ArkExitFromPsiParticleEffectPathProperty : public ArkProperty // Id=80172AA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA80);
	};

	static ArkFocusModeComponentProperties::ArkExitFromPsiParticleEffectPathProperty s_ArkExitFromPsiParticleEffectPathProperty;
	string m_ExitFromPsiParticleEffectPath;
	
	class ArkFocusToPsiParticleEffectPathProperty : public ArkProperty // Id=80172AB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AB00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221D20);
	};

	static ArkFocusModeComponentProperties::ArkFocusToPsiParticleEffectPathProperty s_ArkFocusToPsiParticleEffectPathProperty;
	string m_FocusToPsiParticleEffectPath;
	
	class ArkPsiToFocusParticleEffectPathProperty : public ArkProperty // Id=80172AC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221DA0);
	};

	static ArkFocusModeComponentProperties::ArkPsiToFocusParticleEffectPathProperty s_ArkPsiToFocusParticleEffectPathProperty;
	string m_PsiToFocusParticleEffectPath;
	
	class ArkSelectPowerLegendProperty : public ArkProperty // Id=80172AD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1066210);
	};

	static ArkFocusModeComponentProperties::ArkSelectPowerLegendProperty s_ArkSelectPowerLegendProperty;
	ArkInputLegend m_SelectPowerLegend;
	
	class ArkSelectWeaponLegendProperty : public ArkProperty // Id=80172AE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221E70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6230);
	};

	static ArkFocusModeComponentProperties::ArkSelectWeaponLegendProperty s_ArkSelectWeaponLegendProperty;
	ArkInputLegend m_SelectWeaponLegend;
	
	class ArkNoPowersAudioTriggerProperty : public ArkProperty // Id=80172AF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221F90);
	};

	static ArkFocusModeComponentProperties::ArkNoPowersAudioTriggerProperty s_ArkNoPowersAudioTriggerProperty;
	string m_NoPowersAudioTrigger;
	
	class ArkNoPowersStringsProperty : public ArkProperty // Id=80172B0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFocusModeComponentProperties::ArkNoPowersStringsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFocusModeComponentProperties::ArkNoPowersStringsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1222020);
		static inline auto FIsArray = PreyFunction<bool(ArkFocusModeComponentProperties::ArkNoPowersStringsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkFocusModeComponentProperties::ArkNoPowersStringsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1222070);
	};

	static ArkFocusModeComponentProperties::ArkNoPowersStringsProperty s_ArkNoPowersStringsProperty;
	std::vector<string> m_NoPowersStrings;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetMouseSensitivity(float arg0);
	const float &GetMouseSensitivity() const;
	void SetMouseRotationSpeed(float arg0);
	const float &GetMouseRotationSpeed() const;
	void SetMouseRotationDamping(float arg0);
	const float &GetMouseRotationDamping() const;
	void SetControllerAbsoluteDeadzone(float arg0);
	const float &GetControllerAbsoluteDeadzone() const;
	void SetControllerDeltaDeadzone(float arg0);
	const float &GetControllerDeltaDeadzone() const;
	void SetControllerInactiveStickDeadzone(float arg0);
	const float &GetControllerInactiveStickDeadzone() const;
	void SetDefaultPostProcessEffect(uint64_t arg0);
	const uint64_t &GetDefaultPostProcessEffect() const;
	void SetPsiPostProcessEffect(uint64_t arg0);
	const uint64_t &GetPsiPostProcessEffect() const;
	void SetFocusParticleEffectPath(string arg0);
	string const &GetFocusParticleEffectPath() const;
	void SetExitFromFocusParticleEffectPath(string arg0);
	string const &GetExitFromFocusParticleEffectPath() const;
	void SetPsiParticleEffectPath(string arg0);
	string const &GetPsiParticleEffectPath() const;
	void SetExitFromPsiParticleEffectPath(string arg0);
	string const &GetExitFromPsiParticleEffectPath() const;
	void SetFocusToPsiParticleEffectPath(string arg0);
	string const &GetFocusToPsiParticleEffectPath() const;
	void SetPsiToFocusParticleEffectPath(string arg0);
	string const &GetPsiToFocusParticleEffectPath() const;
	void SetSelectPowerLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetSelectPowerLegend() const;
	void SetSelectWeaponLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetSelectWeaponLegend() const;
	void SetNoPowersAudioTrigger(string arg0);
	string const &GetNoPowersAudioTrigger() const;
	std::vector<string> &GetNoPowersStrings();
	std::vector<string> const &GetNoPowersStrings() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1222DF0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1222EB0);
	static inline auto FInit = PreyFunction<bool(ArkFocusModeComponentProperties *const _this)>(0x1223000);
};

