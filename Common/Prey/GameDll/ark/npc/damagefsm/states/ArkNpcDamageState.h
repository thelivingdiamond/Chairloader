// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpc;
struct ArkNpcDamageEnterStateParams;
struct ArkNpcDamageExitStateParams;
struct ArkNpcDamagePostSerializeStateParams;
struct ArkNpcDamageSerializeStateParams;
struct ArkNpcDamageUpdateStateParams;

// ArkNpcDamageState
// Header:  Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState.h
class ArkNpcDamageState
{ // Size=1 (0x1)
public:
	static void TryHideAttachment(ArkNpc& _npc, const char* _pAttachmentName, bool _bHidden) { FTryHideAttachment(_npc, _pAttachmentName, _bHidden); }

#if 0
	void Enter(const ArkNpcDamageEnterStateParams& _arg0_);
	void Update(const ArkNpcDamageUpdateStateParams& _arg0_, float _arg1_);
	void Exit(const ArkNpcDamageExitStateParams& _arg0_);
	void Serialize(TSerialize _arg0_, const ArkNpcDamageSerializeStateParams& _arg1_);
	void PostSerialize(const ArkNpcDamagePostSerializeStateParams& _arg0_);
	void OnReactionComplete(ArkNpc& _arg0_);
#endif

	static inline auto FTryHideAttachment = PreyFunction<void(ArkNpc& _npc, const char* _pAttachmentName, bool _bHidden)>(0x12A0F90);
};
#endif // MOONCRASH
