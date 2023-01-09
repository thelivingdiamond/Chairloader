// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class XmlNodeRef;

// ArkPlayerRadiationComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerRadiationComponent.h
class ArkPlayerRadiationComponent
{ // Size=80 (0x50)
public:
	enum class EArkRadiationLevel
	{
		None = 0,
		Low = 1,
		Medium = 2,
		High = 3,
		Count = 4,
	};

	// ArkPlayerRadiationComponent::RadiationData
	// Header:  Prey/GameDll/ark/player/ArkPlayerRadiationComponent.h
	class RadiationData
	{ // Size=8 (0x8)
	public:
		ArkTimeRemaining m_timeRemaining;
		float m_radiationAmount;

	#if 0
		RadiationData();
		RadiationData(float _arg0_);
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::list<ArkPlayerRadiationComponent::RadiationData,std::allocator<ArkPlayerRadiationComponent::RadiationData> > m_radiationData;
	ArkPlayerRadiationComponent::EArkRadiationLevel m_currentLevel;
	ArkPlayerRadiationComponent::EArkRadiationLevel m_forcedLevel;
	float m_forcedMagnitude;
	ArkAutoResetTimer m_uiTimer;
	bool m_bHUDOpen;
	float m_mediumThreshold;
	float m_highThreshold;
	std::array<float,4> m_flashRates;
	ArkAudioTrigger m_triggerRadiation;
	ArkAudioTrigger m_triggerRadiationStop;
	ArkAudioRtpc m_rtpcRadiationPerSec;

	ArkPlayerRadiationComponent();
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ReceiveRadiation(float _amount) { FReceiveRadiation(this, _amount); }
	float GetRadiationPercent() const { return FGetRadiationPercent(this); }
	void ForceRadiationLevel(float _magnitude) { FForceRadiationLevel(this, _magnitude); }
	float UpdateCurrentLevel() { return FUpdateCurrentLevel(this); }
	void OpenUI() { FOpenUI(this); }

#if 0
	ArkPlayerRadiationComponent::EArkRadiationLevel GetRadiationLevel(float _arg0_) const;
#endif

	static inline auto FArkPlayerRadiationComponentOv2 = PreyFunction<void(ArkPlayerRadiationComponent* const _this)>(0x12FAEC0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerRadiationComponent* const _this, const XmlNodeRef& _node)>(0x12FB0C0);
	static inline auto FReset = PreyFunction<void(ArkPlayerRadiationComponent* const _this)>(0x12FB590);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerRadiationComponent* const _this, const float _frameTime)>(0x12FB720);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerRadiationComponent* const _this, TSerialize _ser)>(0x12FB6C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerRadiationComponent* const _this)>(0x12FB310);
	static inline auto FReceiveRadiation = PreyFunction<void(ArkPlayerRadiationComponent* const _this, float _amount)>(0x12FB4E0);
	static inline auto FGetRadiationPercent = PreyFunction<float(const ArkPlayerRadiationComponent* const _this)>(0x12FB090);
	static inline auto FForceRadiationLevel = PreyFunction<void(ArkPlayerRadiationComponent* const _this, float _magnitude)>(0x12FAF20);
	static inline auto FUpdateCurrentLevel = PreyFunction<float(ArkPlayerRadiationComponent* const _this)>(0x12FBC30);
	static inline auto FOpenUI = PreyFunction<void(ArkPlayerRadiationComponent* const _this)>(0x12FB200);
};

