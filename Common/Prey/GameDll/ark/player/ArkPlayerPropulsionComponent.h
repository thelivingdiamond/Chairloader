// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleCharge.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
class XmlNodeRef;

// ArkPlayerPropulsionComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerPropulsionComponent.h
class ArkPlayerPropulsionComponent : public IArkStatsListener
{ // Size=88 (0x58)
public:
	uint64_t m_jetPackNoiseTypeId;
	uint64_t m_jetPackNoiseLoudness;
	int m_jetPackNoiseId;
	unsigned m_cameraRotationHandle;
	float m_glideCameraAmplitude;
	float m_glideCameraFrequency;
	float m_glideCameraNoise;
	float m_glideCameraMinFalloff;
	bool m_bShowingUI;
	bool m_bPropulsionActive;
	bool m_bDisrupted;
	ArkSimpleTimer m_cameraFallOffTimer;
	ArkSimpleCharge m_glideCharge;
	ArkAudioTrigger m_triggerGlideStart;
	ArkAudioTrigger m_triggerGlideStop;

	ArkPlayerPropulsionComponent();
	virtual ~ArkPlayerPropulsionComponent();
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Reset() { FReset(this); }
	bool StartPropulsion(bool _bForce) { return FStartPropulsion(this, _bForce); }
	void StopPropulsion() { FStopPropulsion(this); }
	void SetDisrupted(bool _bDisrupted) { FSetDisrupted(this, _bDisrupted); }
	void Serialize(TSerialize& _ser) { FSerialize(this, _ser); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void StartEmittingGameNoise() { FStartEmittingGameNoise(this); }
	void StopEmittingGameNoise() { FStopEmittingGameNoise(this); }
	void UpdateGameNoisePosition() const { FUpdateGameNoisePosition(this); }
	void HandlePropulsionCameraRotation(Ang3& _rotation, float _frameTime) { FHandlePropulsionCameraRotation(this, _rotation, _frameTime); }

#if 0
	bool IsEnabled() const;
	bool CanStartPropulsion() const;
	bool IsShowingUI() const;
#endif

	static inline auto FArkPlayerPropulsionComponentOv1 = PreyFunction<void(ArkPlayerPropulsionComponent* const _this)>(0x1244F10);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerPropulsionComponent* const _this, const XmlNodeRef& _node)>(0x1245140);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerPropulsionComponent* const _this, const float _frameTime)>(0x12459F0);
	static inline auto FReset = PreyFunction<void(ArkPlayerPropulsionComponent* const _this)>(0x1245410);
	static inline auto FStartPropulsion = PreyFunction<bool(ArkPlayerPropulsionComponent* const _this, bool _bForce)>(0x1245770);
	static inline auto FStopPropulsion = PreyFunction<void(ArkPlayerPropulsionComponent* const _this)>(0x1245910);
	static inline auto FSetDisrupted = PreyFunction<void(ArkPlayerPropulsionComponent* const _this, bool _bDisrupted)>(0x1245600);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerPropulsionComponent* const _this, TSerialize& _ser)>(0x1245490);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerPropulsionComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x1245370);
	static inline auto FStartEmittingGameNoise = PreyFunction<void(ArkPlayerPropulsionComponent* const _this)>(0x12456C0);
	static inline auto FStopEmittingGameNoise = PreyFunction<void(ArkPlayerPropulsionComponent* const _this)>(0x12458D0);
	static inline auto FUpdateGameNoisePosition = PreyFunction<void(const ArkPlayerPropulsionComponent* const _this)>(0x1245C50);
	static inline auto FHandlePropulsionCameraRotation = PreyFunction<void(ArkPlayerPropulsionComponent* const _this, Ang3& _rotation, float _frameTime)>(0x1245050);
};

