// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryNetwork/ISerialize.h>

struct SViewParams;

// Header: FromCpp
// Prey/GameDll/ark/ArkCameraShakeManager.h
class ArkCameraShakeManager // Id=8016986 Size=56
{
public:
	class CameraShakeEntry // Id=8016987 Size=64
	{
	public:
		ArkCameraShake const *m_pCameraShake;
		ArkSimpleTimer m_phaseTimeRemaining;
		ArkAutoResetTimer m_horizontalTimer;
		ArkAutoResetTimer m_verticalTimer;
		EArkCameraShakePhase m_currentPhase;
		Vec3 m_sourcePosition;
		float m_intensity;
		uint16_t m_forceFeedbackId;
		_smart_ptr<TAction<SAnimationContext> > m_pAnimAction;
		
		void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
		float GetDistanceIntensity() const { return FGetDistanceIntensity(this); }
		
#if 0
		float GetHorizontalMagnitude(const float arg0) const;
		float GetVerticalMagnitude(const float arg0) const;
#endif
		
		static inline auto FSerialize = PreyFunction<void(ArkCameraShakeManager::CameraShakeEntry *const _this, TSerialize _ser)>(0x114E050);
		static inline auto FGetDistanceIntensity = PreyFunction<float(ArkCameraShakeManager::CameraShakeEntry const *const _this)>(0x114DDD0);
	};

	class ChannelEntry // Id=8016989 Size=16
	{
	public:
		uint64_t m_channelId;
		unsigned m_disabledCount;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const uint64_t arg0) const;
#endif
	};

	std::vector<ArkCameraShakeManager::CameraShakeEntry> m_cameraShakes;
	std::vector<ArkCameraShakeManager::ChannelEntry> m_channels;
	float m_horizontalUIOffset;
	float m_verticalUIOffset;
	
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void TriggerCameraShake(const uint64_t _id, Vec3 _sourcePos) { FTriggerCameraShake(this,_id,_sourcePos); }
	void EnableChannel(uint64_t _channelId, bool _bEnable) { FEnableChannel(this,_channelId,_bEnable); }
	void UpdatePlayerCamera(SViewParams &_viewParams) const { FUpdatePlayerCamera(this,_viewParams); }
	void AnimationFinished(TAction<SAnimationContext> *_pAnimAction) { FAnimationFinished(this,_pAnimAction); }
	void StartCameraShake(ArkCameraShakeManager::CameraShakeEntry &_cameraShake) { FStartCameraShake(this,_cameraShake); }
	void StopCameraShake(ArkCameraShakeManager::CameraShakeEntry &_cameraShake) { FStopCameraShake(this,_cameraShake); }
	
#if 0
	bool IsChannelEnabled(uint64_t arg0) const;
#endif
	
	static inline auto FReset = PreyFunction<void(ArkCameraShakeManager *const _this)>(0x114DEE0);
	static inline auto FUpdate = PreyFunction<void(ArkCameraShakeManager *const _this, float _frameTime)>(0x114E500);
	static inline auto FSerialize = PreyFunction<void(ArkCameraShakeManager *const _this, TSerialize _ser)>(0x114DF90);
	static inline auto FTriggerCameraShake = PreyFunction<void(ArkCameraShakeManager *const _this, const uint64_t _id, Vec3 _sourcePos)>(0x114E490);
	static inline auto FEnableChannel = PreyFunction<void(ArkCameraShakeManager *const _this, uint64_t _channelId, bool _bEnable)>(0x114DC40);
	static inline auto FUpdatePlayerCamera = PreyFunction<void(ArkCameraShakeManager const *const _this, SViewParams &_viewParams)>(0x114E840);
	static inline auto FAnimationFinished = PreyFunction<void(ArkCameraShakeManager *const _this, TAction<SAnimationContext> *_pAnimAction)>(0x114DBE0);
	static inline auto FStartCameraShake = PreyFunction<void(ArkCameraShakeManager *const _this, ArkCameraShakeManager::CameraShakeEntry &_cameraShake)>(0x114E220);
	static inline auto FStopCameraShake = PreyFunction<void(ArkCameraShakeManager *const _this, ArkCameraShakeManager::CameraShakeEntry &_cameraShake)>(0x114E3C0);
};

