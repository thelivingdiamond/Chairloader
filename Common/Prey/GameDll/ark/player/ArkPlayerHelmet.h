// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class ArkPlayerOxygenComponent;
class CCryName;
struct IConsoleCmdArgs;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerHelmet.h
class ArkPlayerHelmet : public IArkStatsListener // Id=80174B3 Size=80
{
public:
	enum class EQueuedDialog
	{
		none = 0,
		activate = 1,
		deactivate = 2,
	};

	Quat m_target;
	std::unique_ptr<ArkPlayerOxygenComponent> m_pOxygenComponent;
	Vec2 m_tolerance;
	ArkSimpleTimer m_reactTimer;
	uint64_t m_signalModifier;
	float m_catchUpSpeed;
	ArkPlayerHelmet::EQueuedDialog m_queuedDialog;
	int m_crackSubMatId;
	bool m_bActive;
	bool m_bPaused;
	bool m_bNonReactActivated;
	bool m_bCatchUp;
	bool m_bConsideredCaughtUp;
	
	ArkPlayerHelmet();
	~ArkPlayerHelmet();
	void Reset() { FReset(this); }
	void SetViewRotation(Quat const &_rotation) { FSetViewRotation(this,_rotation); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ReactToDeploySignal() { FReactToDeploySignal(this); }
	void Pause(const bool _bPause) { FPause(this,_bPause); }
	ArkPlayerOxygenComponent const &GetOxygenComponent() const { return FGetOxygenComponentOv1(this); }
	ArkPlayerOxygenComponent &GetOxygenComponent() { return FGetOxygenComponentOv0(this); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	void UpdateCracks(float _value) const { FUpdateCracks(this,_value); }
	void Activate_Internal(const bool _bReset) { FActivate_Internal(this,_bReset); }
	void Deactivate_Internal(const bool _bReset) { FDeactivate_Internal(this,_bReset); }
	
#if 0
	void Activate(const bool arg0);
	void Deactivate(const bool arg0);
	bool IsActive() const;
	void PlayAnimation(const char *const arg0, bool arg1) const;
	static void RefillOxygen(IConsoleCmdArgs *arg0);
#endif
	
	static inline auto FBitNotArkPlayerHelmet = PreyFunction<void(ArkPlayerHelmet *const _this)>(0x12F91D0);
	static inline auto FReset = PreyFunction<void(ArkPlayerHelmet *const _this)>(0x12F9B90);
	static inline auto FSetViewRotation = PreyFunction<void(ArkPlayerHelmet *const _this, Quat const &_rotation)>(0x12F9CD0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerHelmet *const _this, XmlNodeRef const &_node)>(0x12F95E0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerHelmet *const _this, const float _frameTime)>(0x12F9CF0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerHelmet *const _this, TSerialize _ser)>(0x12F9C20);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerHelmet *const _this)>(0x12F9B00);
	static inline auto FReactToDeploySignal = PreyFunction<void(ArkPlayerHelmet *const _this)>(0x12F9B40);
	static inline auto FPause = PreyFunction<void(ArkPlayerHelmet *const _this, const bool _bPause)>(0x12F9940);
	static inline auto FGetOxygenComponentOv1 = PreyFunction<ArkPlayerOxygenComponent const &(ArkPlayerHelmet const *const _this)>(0xD87500);
	static inline auto FGetOxygenComponentOv0 = PreyFunction<ArkPlayerOxygenComponent &(ArkPlayerHelmet *const _this)>(0xD87500);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerHelmet *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x12F9930);
	static inline auto FUpdateCracks = PreyFunction<void(ArkPlayerHelmet const *const _this, float _value)>(0x12FAAC0);
	static inline auto FActivate_Internal = PreyFunction<void(ArkPlayerHelmet *const _this, const bool _bReset)>(0x12F9310);
	static inline auto FDeactivate_Internal = PreyFunction<void(ArkPlayerHelmet *const _this, const bool _bReset)>(0x12F94D0);
};

