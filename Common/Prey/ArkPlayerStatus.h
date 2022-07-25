#pragma once
#include "ArkReflectedObject.h"
#include "ArkStats.h"
#include "Prey/CryCore/StdAfx.h"

class ArkProperty {
public:
	void* ptr;
	CryStringT<char> m_name;
	char* m_typeStr;
	EArkType m_arkType;
	char pad[4];
};
class ArkSignalModifer : ArkReflectedObject {
	bool m_IsInbound;
	unsigned __int64 m_ModifierId;
};




class ArkConditionalSignalModifier : ArkSignalModifer {
public:
	bool m_IsActiveInAlternateForm;
};

class ArkTraumaPhase : ArkReflectedObject
{
public:
	float m_DamageThreshold;
	CryStringT<char> m_Description;
	CryStringT<char> m_AltOxygenDescription;
	CryStringT<char> m_HudIcon;
	std::vector<ArkConditionalSignalModifier> m_SignalModifiers;
	std::vector<ArkConditionalStatModifier> m_StatModifiers;
};
class ArkTrauma : public ArkReflectedObject// Size=0xb0 (Id=120859)
{
public:
	class ArkIDProperty : public ArkProperty// Size=0x20 (Id=761699)
	{};
	// static ArkIDProperty s_ArkIDProperty;// Offset=0x0 Size=0x20
	uint64_t m_ID;// Offset=0x0 Size=0x8

	class ArkNameProperty : public ArkProperty// Size=0x20 (Id=761738)
	{};
	// static ArkNameProperty s_ArkNameProperty;// Offset=0x0 Size=0x20
	CCryName m_Name;// Offset=0x8 Size=0x8

	class ArkLabelProperty : public ArkProperty// Size=0x20 (Id=761795)
	{};
	// static ArkLabelProperty s_ArkLabelProperty;// Offset=0x0 Size=0x20
	CCryName m_Label;// Offset=0x10 Size=0x8

	class ArkSurvivalModeProperty : public ArkProperty// Size=0x20 (Id=761850)
	{};
	// static ArkSurvivalModeProperty s_ArkSurvivalModeProperty;// Offset=0x0 Size=0x20
	bool m_SurvivalMode;// Offset=0x18 Size=0x1

	class ArkHowToRemoveProperty : public ArkProperty// Size=0x20 (Id=761890)
	{};
	// static ArkHowToRemoveProperty s_ArkHowToRemoveProperty;// Offset=0x0 Size=0x20
	CryStringT<char> m_HowToRemove;// Offset=0x20 Size=0x8

	class ArkDoesStackProperty : public ArkProperty// Size=0x20 (Id=761939)
	{};
	// static ArkDoesStackProperty s_ArkDoesStackProperty;// Offset=0x0 Size=0x20
	bool m_DoesStack;// Offset=0x28 Size=0x1
	class ArkMaxAccumulationProperty : public ArkProperty// Size=0x20 (Id=761977)
	{
	};
	// static ArkMaxAccumulationProperty s_ArkMaxAccumulationProperty;// Offset=0x0 Size=0x20
	float m_MaxAccumulation;// Offset=0x2c Size=0x4

	class ArkDrainRateProperty : public ArkProperty// Size=0x20 (Id=762017)
	{
	};
	// static ArkDrainRateProperty s_ArkDrainRateProperty;// Offset=0x0 Size=0x20
	float m_DrainRate;// Offset=0x30 Size=0x4

	class ArkRemoveOnDrainProperty : public ArkProperty// Size=0x20 (Id=762055)
	{
	};
	// static ArkRemoveOnDrainProperty s_ArkRemoveOnDrainProperty;// Offset=0x0 Size=0x20
	bool m_RemoveOnDrain;// Offset=0x34 Size=0x1

	class ArkFillHudIconProperty : public ArkProperty// Size=0x20 (Id=762093)
	{
	};
	// static ArkFillHudIconProperty s_ArkFillHudIconProperty;// Offset=0x0 Size=0x20
	bool m_FillHudIcon;// Offset=0x35 Size=0x1

	class ArkSuitVOProperty : public ArkProperty// Size=0x20 (Id=762131)
	{
	};
	// static ArkSuitVOProperty s_ArkSuitVOProperty;// Offset=0x0 Size=0x20
	uint64_t m_SuitVO;// Offset=0x38 Size=0x8

	class ArkPlayerMaterialProperty : public ArkProperty// Size=0x20 (Id=762169)
	{
	};
	// static ArkPlayerMaterialProperty s_ArkPlayerMaterialProperty;// Offset=0x0 Size=0x20
	CryStringT<char> m_PlayerMaterial;// Offset=0x40 Size=0x8

	class ArkPlayerMaterialPriorityProperty : public ArkProperty// Size=0x20 (Id=762216)
	{
	};
	// static ArkPlayerMaterialPriorityProperty s_ArkPlayerMaterialPriorityProperty;// Offset=0x0 Size=0x20
	int m_PlayerMaterialPriority;// Offset=0x48 Size=0x4

	class ArkTraumaSFXProperty : public ArkProperty// Size=0x20 (Id=762256)
	{
	};
	// static ArkTraumaSFXProperty s_ArkTraumaSFXProperty;// Offset=0x0 Size=0x20
	CryStringT<char> m_TraumaSFX;// Offset=0x50 Size=0x8

	class ArkTraumaStopSFXProperty : public ArkProperty// Size=0x20 (Id=762303)
	{};
	// static ArkTraumaStopSFXProperty s_ArkTraumaStopSFXProperty;// Offset=0x0 Size=0x20
	CryStringT<char> m_TraumaStopSFX;// Offset=0x58 Size=0x8

	class ArkDurationProperty : public ArkProperty// Size=0x20 (Id=762350)
	{};
	// static ArkDurationProperty s_ArkDurationProperty;// Offset=0x0 Size=0x20
	float m_Duration;// Offset=0x60 Size=0x4

	class ArkPostEffectProperty : public ArkProperty// Size=0x20 (Id=762388)
	{};
	// static ArkPostEffectProperty s_ArkPostEffectProperty;// Offset=0x0 Size=0x20
	uint64_t m_PostEffect;// Offset=0x68 Size=0x8

	class ArkPostEffectParamProperty : public ArkProperty// Size=0x20 (Id=762426)
	{
	};
	// static ArkPostEffectParamProperty s_ArkPostEffectParamProperty;// Offset=0x0 Size=0x20
	uint64_t m_PostEffectParam;// Offset=0x70 Size=0x8

	class ArkRepeatMinProperty : public ArkProperty// Size=0x20 (Id=762464)
	{
	};
	// static ArkRepeatMinProperty s_ArkRepeatMinProperty;// Offset=0x0 Size=0x20
	float m_RepeatMin;// Offset=0x78 Size=0x4

	class ArkRepeatMaxProperty : public ArkProperty// Size=0x20 (Id=762502)
	{
	};
	// static ArkRepeatMaxProperty s_ArkRepeatMaxProperty;// Offset=0x0 Size=0x20
	float m_RepeatMax;// Offset=0x7c Size=0x4

	class ArkTagStateProperty : public ArkProperty// Size=0x20 (Id=762540)
	{
	};
	// static ArkTagStateProperty s_ArkTagStateProperty;// Offset=0x0 Size=0x20
	class CryStringT<char> m_TagState;// Offset=0x80 Size=0x8

	class ArkRemoveSignalProperty : public ArkProperty// Size=0x20 (Id=762587)
	{
	};
	// static ArkRemoveSignalProperty s_ArkRemoveSignalProperty;// Offset=0x0 Size=0x20
	uint64_t m_RemoveSignal;// Offset=0x88 Size=0x8

	class ArkAccumulateSignalProperty : public ArkProperty// Size=0x20 (Id=762625)
	{
	};
	// static ArkAccumulateSignalProperty s_ArkAccumulateSignalProperty;// Offset=0x0 Size=0x20
	uint64_t m_AccumulateSignal;// Offset=0x90 Size=0x8

	class ArkPhasesProperty : public ArkProperty// Size=0x20 (Id=762663)
	{
	};
	// static ArkPhasesProperty s_ArkPhasesProperty;// Offset=0x0 Size=0x20
	class std::vector<ArkTraumaPhase> m_Phases;// Offset=0x98 Size=0x18

	static inline auto getPhase = PreyFunction<ArkTraumaPhase* (ArkTrauma* _this, int _level)>(0x10857E0);

};

class ArkTraumaBase
{
public:
	virtual ~ArkTraumaBase() = 0;
	virtual void Serialize(CSerializeWrapper<ISerialize>) = 0;
	virtual void PostSerialize() = 0;
	virtual void Update(float) = 0;
	virtual void Accumulate(float) = 0;
	virtual void Activate(int level) = 0;
	virtual void ForceRemove(bool) = 0;
	virtual void ReduceAccumulation(float, bool) = 0;
	virtual void Suspend() = 0;
	virtual void Resume() = 0;
	virtual void Reset() = 0;
	virtual bool IsHarmful() = 0;
	virtual bool IsMedical() = 0;
	virtual bool ShowDamageIndicator() = 0;
	virtual float GetMinPostEffectParamValue() = 0;
	virtual bool IsEnabled() = 0;
	virtual bool CanStack(float) = 0;
	virtual void ReevaluatePhase(bool) = 0;
	virtual void UpdateVisuals(bool bImmediate, bool bFromSerialize) = 0;
	virtual void ApplyStatModifiers() = 0;
	virtual void ResumeStatModifiers() = 0;
	virtual void Stack() = 0;
	virtual void RepeatEffect() = 0;
	const unsigned __int64 m_id;
	EArkPlayerStatus m_status;
	bool m_bIsSuspended;
	float m_currentAmount;
	float m_prevActivationAmount;
	int m_currentLevel;
	ArkSimpleTimer m_hudIconTimer;
	ArkTrauma m_desc;
	float m_maxAccumulation;
	ArkAudioTrigger m_traumaSFX;
	ArkAudioTrigger m_traumaStopSFX;
	ArkRandomizedAutoResetTimer m_repeatTimer;
	ArkSimpleTimer m_traumaTimer;
	IMaterial* m_pBlendMaterial;
	std::vector<std::pair<unsigned int, bool>> m_activeStatModifiers;
	const CCryName m_activationChanceStat;

	static inline auto UpdateHudIcon = PreyFunction<void(ArkTraumaBase* _this)>(0x15B0C00);
};

class ArkPlayerStatusComponent
{
public:
	static inline auto GetTraumaForStatus = PreyFunction<ArkTraumaBase * (ArkPlayerStatusComponent * _this, EArkPlayerStatus status)>(0x14624F0);
	static inline auto SetStatus = PreyFunction<void(ArkPlayerStatusComponent*, EArkPlayerStatus status, bool bActivate, bool bSilent)>(0x1463610);
	static inline auto ForceStatus = PreyFunction<void(ArkPlayerStatusComponent*, EArkPlayerStatus, bool)>(0x1462210);
	static inline auto AddHudIcon = PreyFunction<void(ArkPlayerStatusComponent*, CryStringT<char>&)>(0x1461f00);
	struct TArmMaterial// Size=0x10 (Id=676087)
	{
		int m_priority;// Offset=0x0 Size=0x4
		struct IMaterial* m_pMaterial;// Offset=0x8 Size=0x8
	};
	std::vector<std::unique_ptr<ArkTraumaBase>> m_statuses;
	std::vector<EArkPlayerStatus> m_activeStatuses;
	std::vector<TArmMaterial> m_armMaterials;
	ArkSimpleTimer m_blendTimer;
	ArkSimpleTimer m_blendOutTimer;
	float m_hudIconBlinkRate;
};