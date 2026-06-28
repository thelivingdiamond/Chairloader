// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkCameraShake;
struct SViewParams;

// ArkCameraShakeManager
// Header:  Prey/GameDll/ark/ArkCameraShakeManager.h
class ArkCameraShakeManager
{ // Size=56 (0x38)
public:
	// ArkCameraShakeManager::CameraShakeEntry
	// Header:  Prey/GameDll/ark/ArkCameraShakeManager.h
	class CameraShakeEntry
	{ // Size=72 (0x48)
	public:
		const ArkCameraShake* m_pCameraShake;
		ArkSimpleTimer m_phaseTimeRemaining;
		ArkAutoResetTimer m_horizontalTimer;
		ArkAutoResetTimer m_verticalTimer;
		EArkCameraShakePhase m_currentPhase;
		Vec3 m_sourcePosition;
		float m_intensity;
		uint16_t m_forceFeedbackId;
		unsigned m_sourceEntityId;
		_smart_ptr<TAction<SAnimationContext>> m_pAnimAction;

		void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
		float GetDistanceIntensity() const { return FGetDistanceIntensity(this); }

	#if 0
		CameraShakeEntry();
		CameraShakeEntry(const ArkCameraShake* _arg0_, const Vec3 _arg1_);
		CameraShakeEntry(const ArkCameraShake* _arg0_, const unsigned _arg1_);
		float GetHorizontalMagnitude(const float _arg0_) const;
		float GetVerticalMagnitude(const float _arg0_) const;
		void EndIndefiniteHold();
	#endif

		static inline auto FSerialize = PreyFunction<void(ArkCameraShakeManager::CameraShakeEntry* const _this, TSerialize _ser)>(0x11954A0);
		static inline auto FGetDistanceIntensity = PreyFunction<float(const ArkCameraShakeManager::CameraShakeEntry* const _this)>(0x11951A0);
	};

	// ArkCameraShakeManager::ChannelEntry
	// Header:  Prey/GameDll/ark/ArkCameraShakeManager.h
	class ChannelEntry
	{ // Size=16 (0x10)
	public:
		uint64_t m_channelId;
		unsigned m_disabledCount;

	#if 0
		ChannelEntry();
		ChannelEntry(const uint64_t _arg0_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const uint64_t _arg0_) const;
	#endif
	};

	std::vector<ArkCameraShakeManager::CameraShakeEntry> m_cameraShakes;
	std::vector<ArkCameraShakeManager::ChannelEntry> m_channels;
	float m_horizontalUIOffset;
	float m_verticalUIOffset;

	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void TriggerCameraShake(const uint64_t _id, unsigned _sourceEntityId) { FTriggerCameraShakeOv1(this, _id, _sourceEntityId); }
	void TriggerCameraShake(const uint64_t _id, Vec3 _sourcePos) { FTriggerCameraShakeOv0(this, _id, _sourcePos); }
	void ForceStopCameraShakes(const uint64_t _id) { FForceStopCameraShakes(this, _id); }
	void EnableChannel(uint64_t _channelId, bool _bEnable) { FEnableChannel(this, _channelId, _bEnable); }
	bool HasEntitySourceShake(const uint64_t _cameraShakeId, unsigned _sourceEntityId) const { return FHasEntitySourceShake(this, _cameraShakeId, _sourceEntityId); }
	void EndEntityShakeEntryHold(const uint64_t _cameraShakeId, unsigned _sourceEntityId) { FEndEntityShakeEntryHold(this, _cameraShakeId, _sourceEntityId); }
	void UpdatePlayerCamera(SViewParams& _viewParams) const { FUpdatePlayerCamera(this, _viewParams); }
	void AnimationFinished(TAction<SAnimationContext>* _pAnimAction) { FAnimationFinished(this, _pAnimAction); }
	void StartCameraShake(ArkCameraShakeManager::CameraShakeEntry& _cameraShake) { FStartCameraShake(this, _cameraShake); }
	void StopCameraShake(ArkCameraShakeManager::CameraShakeEntry& _cameraShake) { FStopCameraShake(this, _cameraShake); }

#if 0
	ArkCameraShakeManager();
	bool IsChannelEnabled(uint64_t _arg0_) const;
#endif

	static inline auto FReset = PreyFunction<void(ArkCameraShakeManager* const _this)>(0x1195330);
	static inline auto FUpdate = PreyFunction<void(ArkCameraShakeManager* const _this, float _frameTime)>(0x1195B10);
	static inline auto FSerialize = PreyFunction<void(ArkCameraShakeManager* const _this, TSerialize _ser)>(0x11953E0);
	static inline auto FTriggerCameraShakeOv1 = PreyFunction<void(ArkCameraShakeManager* const _this, const uint64_t _id, unsigned _sourceEntityId)>(0x1195A30);
	static inline auto FTriggerCameraShakeOv0 = PreyFunction<void(ArkCameraShakeManager* const _this, const uint64_t _id, Vec3 _sourcePos)>(0x1195AA0);
	static inline auto FForceStopCameraShakes = PreyFunction<void(ArkCameraShakeManager* const _this, const uint64_t _id)>(0x1195040);
	static inline auto FEnableChannel = PreyFunction<void(ArkCameraShakeManager* const _this, uint64_t _channelId, bool _bEnable)>(0x1194E20);
	static inline auto FHasEntitySourceShake = PreyFunction<bool(const ArkCameraShakeManager* const _this, const uint64_t _cameraShakeId, unsigned _sourceEntityId)>(0x11952B0);
	static inline auto FEndEntityShakeEntryHold = PreyFunction<void(ArkCameraShakeManager* const _this, const uint64_t _cameraShakeId, unsigned _sourceEntityId)>(0x1194EA0);
	static inline auto FUpdatePlayerCamera = PreyFunction<void(const ArkCameraShakeManager* const _this, SViewParams& _viewParams)>(0x1195ED0);
	static inline auto FAnimationFinished = PreyFunction<void(ArkCameraShakeManager* const _this, TAction<SAnimationContext>* _pAnimAction)>(0x1194DC0);
	static inline auto FStartCameraShake = PreyFunction<void(ArkCameraShakeManager* const _this, ArkCameraShakeManager::CameraShakeEntry& _cameraShake)>(0x1195690);
	static inline auto FStopCameraShake = PreyFunction<void(ArkCameraShakeManager* const _this, ArkCameraShakeManager::CameraShakeEntry& _cameraShake)>(0x1195960);
};
#endif // !MOONCRASH
