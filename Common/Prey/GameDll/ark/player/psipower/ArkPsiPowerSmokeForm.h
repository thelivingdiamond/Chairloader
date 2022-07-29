// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowersmokeform.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkInputLegend;
class CCryName;
struct IParticleEmitter;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowersmokeform.h
class ArkPsiPowerSmokeFormUniqueProperties : public ArkReflectedObject // Id=8019516 Size=40
{
public:
	class ArkSignalModifiersProperty : public ArkProperty // Id=8019517 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A4050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1610DD0);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1073510);
	};

	static ArkPsiPowerSmokeFormUniqueProperties::ArkSignalModifiersProperty s_ArkSignalModifiersProperty;
	std::vector<unsigned __int64> m_SignalModifiers;
	
	class ArkObjectFadeDistanceProperty : public ArkProperty // Id=8019518 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerSmokeFormUniqueProperties::ArkObjectFadeDistanceProperty s_ArkObjectFadeDistanceProperty;
	float m_ObjectFadeDistance;
	
	class ArkPostProcessEffectProperty : public ArkProperty // Id=8019519 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerSmokeFormUniqueProperties::ArkPostProcessEffectProperty s_ArkPostProcessEffectProperty;
	uint64_t m_PostProcessEffect;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	std::vector<unsigned __int64> &GetSignalModifiers();
	std::vector<unsigned __int64> const &GetSignalModifiers() const;
	void SetObjectFadeDistance(float arg0);
	const float &GetObjectFadeDistance() const;
	void SetPostProcessEffect(uint64_t arg0);
	const uint64_t &GetPostProcessEffect() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15A48C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A4CB0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowersmokeform.h
class SmokeFormPowerProperties : public ArkReflectedLibrary // Id=8019520 Size=280
{
public:
	using LevelProperties = ArkPsiPowerSmokeFormLevelProperties;
	using UniqueProperties = ArkPsiPowerSmokeFormUniqueProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=8019521 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(SmokeFormPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(SmokeFormPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static SmokeFormPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=8019522 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(SmokeFormPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A3D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(SmokeFormPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static SmokeFormPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerSmokeFormUniqueProperties m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=8019523 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(SmokeFormPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A3F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(SmokeFormPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A3FC0);
		static inline auto FIsArray = PreyFunction<bool(SmokeFormPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(SmokeFormPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x15A4010);
	};

	static SmokeFormPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerSmokeFormLevelProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~SmokeFormPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(ArkPsiPowerSmokeFormUniqueProperties arg0);
	ArkPsiPowerSmokeFormUniqueProperties const &GetUnique() const;
	std::vector<ArkPsiPowerSmokeFormLevelProperties> &GetLevels();
	std::vector<ArkPsiPowerSmokeFormLevelProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15A4900);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A4D50);
	static inline auto FInit = PreyFunction<bool(SmokeFormPowerProperties *const _this)>(0x15A5100);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h
class ArkPsiPowerSmokeForm : public CArkPsiPower<SmokeFormPowerProperties> // Id=8019533 Size=104
{
public:
	std::vector<unsigned int> m_fadedEntities;
	IParticleEmitter *m_pActiveParticleEmitter;
	bool m_bMorphingIn;
	bool m_bPendingMorphIn;
	
	ArkPsiPowerSmokeForm();
	virtual bool StartTargeting();
	virtual bool CanEnterFocusMode(EArkPsiPowers const &_equippedPower) const;
	virtual void ProcessInput(CCryName const &_actionId, int _activationMode, float _value);
	virtual EArkPsiPowers GetEnum() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	void MorphIn() { FMorphIn(this); }
	void Exit() { FExit(this); }
	void StartActiveParticleEffect(const char *_pEffectName) { FStartActiveParticleEffect(this,_pEffectName); }
	void StopActiveParticleEffect() { FStopActiveParticleEffect(this); }
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void Update(const float _frameTime);
	virtual bool GetCanCancel() const;
	bool TryMorphOut() { return FTryMorphOut(this); }
	bool CanExit() const { return FCanExit(this); }
	void RestoreOpacities() { FRestoreOpacities(this); }
	virtual ~ArkPsiPowerSmokeForm();
	
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerSmokeForm *const _this)>(0x15A5790);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(ArkPsiPowerSmokeForm const *const _this, EArkPsiPowers const &_equippedPower)>(0x15A47E0);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiPowerSmokeForm *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0x15A5540);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(ArkPsiPowerSmokeForm const *const _this)>(0x15A4FC0);
	static inline auto FGetModalLegend = PreyFunction<ArkInputLegend const &(ArkPsiPowerSmokeForm const *const _this)>(0x15A4FF0);
	static inline auto FMorphIn = PreyFunction<void(ArkPsiPowerSmokeForm *const _this)>(0x15A52E0);
	static inline auto FExit = PreyFunction<void(ArkPsiPowerSmokeForm *const _this)>(0x15A49E0);
	static inline auto FStartActiveParticleEffect = PreyFunction<void(ArkPsiPowerSmokeForm *const _this, const char *_pEffectName)>(0x15A5710);
	static inline auto FStopActiveParticleEffect = PreyFunction<void(ArkPsiPowerSmokeForm *const _this)>(0x15A5910);
	static inline auto FStop = PreyFunction<bool(ArkPsiPowerSmokeForm *const _this)>(0x15A58B0);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerSmokeForm *const _this)>(0x15A57F0);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerSmokeForm *const _this, const float _frameTime)>(0x15A5B10);
	static inline auto FGetCanCancel = PreyFunction<bool(ArkPsiPowerSmokeForm const *const _this)>(0x15A4BB0);
	static inline auto FTryMorphOut = PreyFunction<bool(ArkPsiPowerSmokeForm *const _this)>(0x15A5940);
	static inline auto FCanExit = PreyFunction<bool(ArkPsiPowerSmokeForm const *const _this)>(0x15A4800);
	static inline auto FRestoreOpacities = PreyFunction<void(ArkPsiPowerSmokeForm *const _this)>(0x15A55D0);
};

