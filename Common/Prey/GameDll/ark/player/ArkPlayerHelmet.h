// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class ArkPlayerOxygenComponent;
class CCryName;
struct IConsoleCmdArgs;
class XmlNodeRef;

// ArkPlayerHelmet
// Header:  Prey/GameDll/ark/player/ArkPlayerHelmet.h
class ArkPlayerHelmet : public IArkStatsListener
{ // Size=80 (0x50)
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
	void SetViewRotation(const Quat& _rotation) { FSetViewRotation(this, _rotation); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ReactToDeploySignal() { FReactToDeploySignal(this); }
	void Pause(const bool _bPause) { FPause(this, _bPause); }
	const ArkPlayerOxygenComponent& GetOxygenComponent() const { return FGetOxygenComponentOv1(this); }
	ArkPlayerOxygenComponent& GetOxygenComponent() { return FGetOxygenComponentOv0(this); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void UpdateCracks(float _value) const { FUpdateCracks(this, _value); }
	void Activate_Internal(const bool _bReset) { FActivate_Internal(this, _bReset); }
	void Deactivate_Internal(const bool _bReset) { FDeactivate_Internal(this, _bReset); }

#if 0
	void Activate(const bool _arg0_);
	void Deactivate(const bool _arg0_);
	bool IsActive() const;
	void PlayAnimation(const char* const _arg0_, bool _arg1_) const;
	static void RefillOxygen(IConsoleCmdArgs* _arg0_);
#endif

	static inline auto FArkPlayerHelmet = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x12F9160);
	static inline auto FBitNotArkPlayerHelmet = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x12F91D0);
	static inline auto FReset = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x12F9B90);
	static inline auto FSetViewRotation = PreyFunction<void(ArkPlayerHelmet* const _this, const Quat& _rotation)>(0x12F9CD0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerHelmet* const _this, const XmlNodeRef& _node)>(0x12F95E0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerHelmet* const _this, const float _frameTime)>(0x12F9CF0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerHelmet* const _this, TSerialize _ser)>(0x12F9C20);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x12F9B00);
	static inline auto FReactToDeploySignal = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x12F9B40);
	static inline auto FPause = PreyFunction<void(ArkPlayerHelmet* const _this, const bool _bPause)>(0x12F9940);
	static inline auto FGetOxygenComponentOv1 = PreyFunction<const ArkPlayerOxygenComponent& (const ArkPlayerHelmet* const _this)>(0xD87500);
	static inline auto FGetOxygenComponentOv0 = PreyFunction<ArkPlayerOxygenComponent& (ArkPlayerHelmet* const _this)>(0xD87500);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerHelmet* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x12F9930);
	static inline auto FUpdateCracks = PreyFunction<void(const ArkPlayerHelmet* const _this, float _value)>(0x12FAAC0);
	static inline auto FActivate_Internal = PreyFunction<void(ArkPlayerHelmet* const _this, const bool _bReset)>(0x12F9310);
	static inline auto FDeactivate_Internal = PreyFunction<void(ArkPlayerHelmet* const _this, const bool _bReset)>(0x12F94D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class ArkPlayerOxygenComponent;
class CCryName;
class XmlNodeRef;

// ArkPlayerHelmet
// Header:  Prey/GameDll/ark/player/ArkPlayerHelmet.h
class ArkPlayerHelmet : public IArkStatsListener
{ // Size=88 (0x58)
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
	string m_helmetType;
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
	void SetHelmet(const string& _helmetType) { FSetHelmet(this, _helmetType); }
	void RefreshHelmetVisuals() { FRefreshHelmetVisuals(this); }
	void Reset() { FReset(this); }
	void SetViewRotation(const Quat& _rotation) { FSetViewRotation(this, _rotation); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void ReactToDeploySignal() { FReactToDeploySignal(this); }
	void Pause(const bool _bPause) { FPause(this, _bPause); }
	ArkPlayerOxygenComponent& GetOxygenComponent() { return FGetOxygenComponentOv0(this); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void UpdateCracks(float _value) const { FUpdateCracks(this, _value); }
	void ShowHelmet(bool _bShow, bool _bReset) { FShowHelmet(this, _bShow, _bReset); }
	void Activate_Internal(const bool _bReset) { FActivate_Internal(this, _bReset); }
	void Deactivate_Internal(const bool _bReset) { FDeactivate_Internal(this, _bReset); }

#if 0
	void Activate(const bool _arg0_);
	void Deactivate(const bool _arg0_);
	bool IsActive() const;
	void PlayAnimation(const char* const _arg0_, bool _arg1_) const;
	const ArkPlayerOxygenComponent& GetOxygenComponent() const;
#endif

	static inline auto FArkPlayerHelmet = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x13D3740);
	static inline auto FBitNotArkPlayerHelmet = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x13D3810);
	static inline auto FSetHelmet = PreyFunction<void(ArkPlayerHelmet* const _this, const string& _helmetType)>(0x13D4550);
	static inline auto FRefreshHelmetVisuals = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x13D4210);
	static inline auto FReset = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x13D4350);
	static inline auto FSetViewRotation = PreyFunction<void(ArkPlayerHelmet* const _this, const Quat& _rotation)>(0x13D4720);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerHelmet* const _this, const XmlNodeRef& _node)>(0x13D3BA0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerHelmet* const _this, const float _frameTime)>(0x13D4990);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerHelmet* const _this, TSerialize _ser)>(0x13D4480);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x13D4100);
	static inline auto FReactToDeploySignal = PreyFunction<void(ArkPlayerHelmet* const _this)>(0x13D41C0);
	static inline auto FPause = PreyFunction<void(ArkPlayerHelmet* const _this, const bool _bPause)>(0x13D3F20);
	static inline auto FGetOxygenComponentOv0 = PreyFunction<ArkPlayerOxygenComponent& (ArkPlayerHelmet* const _this)>(0x598E60);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerHelmet* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x13D3F10);
	static inline auto FUpdateCracks = PreyFunction<void(const ArkPlayerHelmet* const _this, float _value)>(0x13D5750);
	static inline auto FShowHelmet = PreyFunction<void(ArkPlayerHelmet* const _this, bool _bShow, bool _bReset)>(0x13D4740);
	static inline auto FActivate_Internal = PreyFunction<void(ArkPlayerHelmet* const _this, const bool _bReset)>(0x13D3A70);
	static inline auto FDeactivate_Internal = PreyFunction<void(ArkPlayerHelmet* const _this, const bool _bReset)>(0x13D3AE0);
};
#endif // !MOONCRASH
