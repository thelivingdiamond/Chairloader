// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class CPlayer;
struct SActorFrameMovementParams;

// CPlayerStateDead
// Header:  Prey/GameDll/PlayerStateDead.h
class CPlayerStateDead
{ // Size=8 (0x8)
public:
	enum EAICorpseUpdateStatus
	{
		eCorpseStatus_WaitingForSwap = 0,
		eCorpseStatus_SwapDone = 1,
	};

	// CPlayerStateDead::UpdateCtx
	// Header:  Prey/GameDll/PlayerStateDead.h
	struct UpdateCtx
	{ // Size=4 (0x4)
		float frameTime;
	};

	float m_swapToCorpseTimeout;
	CPlayerStateDead::EAICorpseUpdateStatus m_corpseUpdateStatus;

	CPlayerStateDead();
	~CPlayerStateDead();
	void OnEnter(CPlayer& player) { FOnEnter(this, player); }
	void OnLeave(CPlayer& player) { FOnLeave(this, player); }
	void OnPrePhysicsUpdate(CPlayer& player, const SActorFrameMovementParams& movement, float frameTime) { FOnPrePhysicsUpdate(this, player, movement, frameTime); }
	void OnUpdate(CPlayer& player, const CPlayerStateDead::UpdateCtx& updateCtx) { FOnUpdate(this, player, updateCtx); }
	void Serialize(TSerialize& serializer) { FSerialize(this, serializer); }

#if 0
	void UpdateAICorpseStatus(CPlayer& _arg0_, const CPlayerStateDead::UpdateCtx& _arg1_);
#endif

	static inline auto FCPlayerStateDead = PreyFunction<void(CPlayerStateDead* const _this)>(0x18E1970);
	static inline auto FBitNotCPlayerStateDead = PreyFunction<void(CPlayerStateDead* const _this)>(0x1333E90);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateDead* const _this, CPlayer& player)>(0x18E1980);
	static inline auto FOnLeave = PreyFunction<void(CPlayerStateDead* const _this, CPlayer& player)>(0x18E1AB0);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<void(CPlayerStateDead* const _this, CPlayer& player, const SActorFrameMovementParams& movement, float frameTime)>(0x18E1AD0);
	static inline auto FOnUpdate = PreyFunction<void(CPlayerStateDead* const _this, CPlayer& player, const CPlayerStateDead::UpdateCtx& updateCtx)>(0x18E1B30);
	static inline auto FSerialize = PreyFunction<void(CPlayerStateDead* const _this, TSerialize& serializer)>(0x18E1D00);
};
#endif // MOONCRASH
