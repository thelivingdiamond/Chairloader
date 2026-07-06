// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/state.h>

struct SPlayerPrePhysicsData;

// SStateEventJump
// Header:  Prey/GameDll/playerstateevents.h
struct SStateEventJump : public SStateEvent
{ // Size=104 (0x68)
	enum EData
	{
		eD_PrePhysicsData = 0,
		eD_VerticalSpeedMofidier = 1,
	};

	SStateEventJump(const SPlayerPrePhysicsData& data, const float verticalSpeedModifier);

#if 0
	const SPlayerPrePhysicsData& GetPrePhysicsEventData() const;
	float GetVerticalSpeedModifier() const;
#endif

	static inline auto FSStateEventJumpOv2 = PreyFunction<void(SStateEventJump* const _this, const SPlayerPrePhysicsData& data, const float verticalSpeedModifier)>(0x18E6900);
};
#endif // MOONCRASH
