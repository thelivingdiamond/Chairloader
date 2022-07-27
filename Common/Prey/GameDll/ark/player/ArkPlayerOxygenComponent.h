// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
struct IConsoleCmdArgs;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerOxygenComponent.h
class ArkPlayerOxygenComponent : private IArkStatsListener // Id=80174B4 Size=88
{
public:
	float m_oxygen;
	float m_oxygenUI;
	bool m_bConsumingOxygen;
	bool m_bAsphyxiating;
	bool m_bPlayingDepletionAudio;
	bool m_bUIVisible;
	bool m_bStatusVisible;
	bool m_bUpdateDepletionAudio;
	ArkAudioTrigger m_triggerStartAsphyxiating;
	ArkAudioTrigger m_triggerStopAsphyxiating;
	ArkAudioTrigger m_triggerDeathFromAsphyxiation;
	ArkAudioRtpc m_rtpcAsphyxiation;
	ArkAudioTrigger m_triggerStartDepleting;
	ArkAudioTrigger m_triggerStopDepleting;
	ArkAudioRtpc m_rtpcOxygenAmount;
	ArkAudioTrigger m_triggerSuitPatched;
	
	class OxygenAlarm // Id=80174B5 Size=12
	{
	public:
		float m_threshold;
		ArkAudioTrigger m_trigger;
		ArkAudioTrigger m_stopTrigger;
		
#if 0
		bool operator<(ArkPlayerOxygenComponent::OxygenAlarm const &arg0) const;
#endif
	};

	std::vector<ArkPlayerOxygenComponent::OxygenAlarm> m_alarms;
	int m_currentAlarm;
	
	ArkPlayerOxygenComponent();
	virtual ~ArkPlayerOxygenComponent();
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	float GetMaxOxygen() const { return FGetMaxOxygen(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void RefillOxygen() { FRefillOxygenOv1(this); }
	static void RefillOxygen(IConsoleCmdArgs *_pCmdArgs) { FRefillOxygenOv0(_pCmdArgs); }
	void GiveOxygen(float _oxygen) { FGiveOxygen(this,_oxygen); }
	void UpdateUIVisible() { FUpdateUIVisible(this); }
	void SetConsumingOxygen(const bool _bConsuming, const bool _bReset) { FSetConsumingOxygen(this,_bConsuming,_bReset); }
	void SetOxygen(float _oxygen) { FSetOxygen(this,_oxygen); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	void UpdateHUD(float _frameTime) { FUpdateHUD(this,_frameTime); }
	void TutorialCallbackTriggered() const { FTutorialCallbackTriggered(this); }
	void UpdateDepletionAudio() { FUpdateDepletionAudio(this); }
	void UpdateAlarmAudio() { FUpdateAlarmAudio(this); }
	
#if 0
	float GetOxygen() const;
	bool GetConsumingOxygen() const;
	float GetStat(CCryName const &arg0) const;
#endif
	
	static inline auto FReset = PreyFunction<void(ArkPlayerOxygenComponent *const _this)>(0x1573090);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerOxygenComponent *const _this, const float _frameTime)>(0x15734E0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerOxygenComponent *const _this, XmlNodeRef const &_node)>(0x1572CB0);
	static inline auto FGetMaxOxygen = PreyFunction<float(ArkPlayerOxygenComponent const *const _this)>(0x1572C20);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerOxygenComponent *const _this, TSerialize _ser)>(0x1573120);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerOxygenComponent *const _this)>(0x1572FB0);
	static inline auto FRefillOxygenOv1 = PreyFunction<void(ArkPlayerOxygenComponent *const _this)>(0x1573010);
	static inline auto FRefillOxygenOv0 = PreyFunction<void(IConsoleCmdArgs *_pCmdArgs)>(0x1572FE0);
	static inline auto FGiveOxygen = PreyFunction<void(ArkPlayerOxygenComponent *const _this, float _oxygen)>(0x1572C40);
	static inline auto FUpdateUIVisible = PreyFunction<void(ArkPlayerOxygenComponent *const _this)>(0x1573C90);
	static inline auto FSetConsumingOxygen = PreyFunction<void(ArkPlayerOxygenComponent *const _this, const bool _bConsuming, const bool _bReset)>(0x15733D0);
	static inline auto FSetOxygen = PreyFunction<void(ArkPlayerOxygenComponent *const _this, float _oxygen)>(0x1573430);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerOxygenComponent *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x1572F20);
	static inline auto FUpdateHUD = PreyFunction<void(ArkPlayerOxygenComponent *const _this, float _frameTime)>(0x1573950);
	static inline auto FTutorialCallbackTriggered = PreyFunction<void(ArkPlayerOxygenComponent const *const _this)>(0x1573490);
	static inline auto FUpdateDepletionAudio = PreyFunction<void(ArkPlayerOxygenComponent *const _this)>(0x1573850);
	static inline auto FUpdateAlarmAudio = PreyFunction<void(ArkPlayerOxygenComponent *const _this)>(0x1573730);
};

