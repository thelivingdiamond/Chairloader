// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arksimplecharge.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerFatigueComponent.h
class ArkPlayerFatigueComponent : private IArkStatsListener // Id=8017079 Size=56
{
public:
	bool m_bExhausted;
	bool m_bPlayingAudio;
	bool m_bShowingUI;
	int m_bInfiniteStamina;
	ArkChargeAmount m_fatigue;
	float m_staminaPercentStartAudio;
	float m_staminaPercentStopAudio;
	float m_showUIPercent;
	ArkSimpleTimer m_drainDelay;
	ArkAudioRtpc m_rtpcFatigue;
	ArkAudioTrigger m_triggerStart;
	ArkAudioTrigger m_triggerStop;
	
	ArkPlayerFatigueComponent();
	virtual ~ArkPlayerFatigueComponent();
	void Init() { FInit(this); }
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Reset() { FReset(this); }
	bool TestExhaustion() const { return FTestExhaustion(this); }
	bool TestStamina() const { return FTestStamina(this); }
	void AdjustFatigue(float _fatigueAmount) { FAdjustFatigue(this,_fatigueAmount); }
	void PreviewFatigue(float _fatigueAmount) { FPreviewFatigue(this,_fatigueAmount); }
	void OnPreviewAnimationFinished() { FOnPreviewAnimationFinished(this); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	
#if 0
	bool IsExhausted() const;
	bool IsShowingUI() const;
	float GetFatigue() const;
	void SetExhausted(bool arg0);
	void ActivateTrauma(bool arg0);
#endif
	
	static inline auto FInit = PreyFunction<void(ArkPlayerFatigueComponent *const _this)>(0x1234900);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerFatigueComponent *const _this, XmlNodeRef const &_root)>(0x12349C0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerFatigueComponent *const _this, float _frameTime)>(0x12351A0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerFatigueComponent *const _this, TSerialize _ser)>(0x1234EC0);
	static inline auto FReset = PreyFunction<void(ArkPlayerFatigueComponent *const _this)>(0x1234D60);
	static inline auto FTestExhaustion = PreyFunction<bool(ArkPlayerFatigueComponent const *const _this)>(0x1235100);
	static inline auto FTestStamina = PreyFunction<bool(ArkPlayerFatigueComponent const *const _this)>(0x1235150);
	static inline auto FAdjustFatigue = PreyFunction<void(ArkPlayerFatigueComponent *const _this, float _fatigueAmount)>(0x1234580);
	static inline auto FPreviewFatigue = PreyFunction<void(ArkPlayerFatigueComponent *const _this, float _fatigueAmount)>(0x1234B90);
	static inline auto FOnPreviewAnimationFinished = PreyFunction<void(ArkPlayerFatigueComponent *const _this)>(0x1234B00);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerFatigueComponent *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x1234B40);
};

