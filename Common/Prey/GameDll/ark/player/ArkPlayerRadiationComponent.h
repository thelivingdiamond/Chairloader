// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arksimpletimer.h>

class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerRadiationComponent.h
class ArkPlayerRadiationComponent // Id=801707C Size=80
{
public:
	enum class EArkRadiationLevel
	{
		None = 0,
		Low = 1,
		Medium = 2,
		High = 3,
		Count = 4,
	};

	class RadiationData // Id=801707D Size=8
	{
	public:
		ArkTimeRemaining m_timeRemaining;
		float m_radiationAmount;
		
#if 0
		void Serialize(TSerialize arg0);
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
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ReceiveRadiation(float _amount) { FReceiveRadiation(this,_amount); }
	float GetRadiationPercent() const { return FGetRadiationPercent(this); }
	void ForceRadiationLevel(float _magnitude) { FForceRadiationLevel(this,_magnitude); }
	float UpdateCurrentLevel() { return FUpdateCurrentLevel(this); }
	void OpenUI() { FOpenUI(this); }
	
#if 0
	ArkPlayerRadiationComponent::EArkRadiationLevel GetRadiationLevel(float arg0) const;
#endif
	
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerRadiationComponent *const _this, XmlNodeRef const &_node)>(0x12FB0C0);
	static inline auto FReset = PreyFunction<void(ArkPlayerRadiationComponent *const _this)>(0x12FB590);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerRadiationComponent *const _this, const float _frameTime)>(0x12FB720);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerRadiationComponent *const _this, TSerialize _ser)>(0x12FB6C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerRadiationComponent *const _this)>(0x12FB310);
	static inline auto FReceiveRadiation = PreyFunction<void(ArkPlayerRadiationComponent *const _this, float _amount)>(0x12FB4E0);
	static inline auto FGetRadiationPercent = PreyFunction<float(ArkPlayerRadiationComponent const *const _this)>(0x12FB090);
	static inline auto FForceRadiationLevel = PreyFunction<void(ArkPlayerRadiationComponent *const _this, float _magnitude)>(0x12FAF20);
	static inline auto FUpdateCurrentLevel = PreyFunction<float(ArkPlayerRadiationComponent *const _this)>(0x12FBC30);
	static inline auto FOpenUI = PreyFunction<void(ArkPlayerRadiationComponent *const _this)>(0x12FB200);
};

