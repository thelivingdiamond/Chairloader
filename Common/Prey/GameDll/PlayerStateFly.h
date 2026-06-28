// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IHUDEventListener.h>

class CPlayer;
struct SActorFrameMovementParams;
struct SHUDEvent;

// CPlayerStateFly
// Header:  Prey/GameDll/PlayerStateFly.h
class CPlayerStateFly
{ // Size=20 (0x14)
public:
	Vec3 m_originalGravity;
	uint8_t m_flyMode;
	float m_flyModeDisplayTime;

	CPlayerStateFly();
	void OnEnter(CPlayer& player) { FOnEnter(this, player); }
	bool OnPrePhysicsUpdate(CPlayer& player, const SActorFrameMovementParams& movement, float frameTime) { return FOnPrePhysicsUpdate(this, player, movement, frameTime); }
	void OnExit(CPlayer& player) { FOnExit(this, player); }

#if 0
	void ProcessFlyMode(CPlayer& _arg0_, const SActorFrameMovementParams& _arg1_);
#endif

	static inline auto FCPlayerStateFlyOv2 = PreyFunction<void(CPlayerStateFly* const _this)>(0x18E2010);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateFly* const _this, CPlayer& player)>(0x18E2040);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<bool(CPlayerStateFly* const _this, CPlayer& player, const SActorFrameMovementParams& movement, float frameTime)>(0x18E2420);
	static inline auto FOnExit = PreyFunction<void(CPlayerStateFly* const _this, CPlayer& player)>(0x18E2360);
};

// CPlayerStateSpectate
// Header:  Prey/GameDll/PlayerStateFly.h
class CPlayerStateSpectate : public CPlayerStateFly, public IHUDEventListener
{ // Size=40 (0x28)
public:
	using inherited = CPlayerStateFly;

	float m_fFadeOutAmount;
	float m_fFadeForTime;

	CPlayerStateSpectate();
	virtual void OnHUDEvent(const SHUDEvent& event);
	void OnEnter(CPlayer& player) { FOnEnter(this, player); }
	void UpdateFade(float frameTime) { FUpdateFade(this, frameTime); }
	void OnExit(CPlayer& player) { FOnExit(this, player); }

#if 0
	void ResetFadeParameters();
	void DrawSpectatorFade();
#endif

	static inline auto FCPlayerStateSpectateOv2 = PreyFunction<void(CPlayerStateSpectate* const _this)>(0x18E2020);
	static inline auto FOnHUDEvent = PreyFunction<void(CPlayerStateSpectate* const _this, const SHUDEvent& event)>(0x1333E90);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateSpectate* const _this, CPlayer& player)>(0x18E21B0);
	static inline auto FUpdateFade = PreyFunction<void(CPlayerStateSpectate* const _this, float frameTime)>(0x18E2660);
	static inline auto FOnExit = PreyFunction<void(CPlayerStateSpectate* const _this, CPlayer& player)>(0x18E23B0);
};
#endif // MOONCRASH
