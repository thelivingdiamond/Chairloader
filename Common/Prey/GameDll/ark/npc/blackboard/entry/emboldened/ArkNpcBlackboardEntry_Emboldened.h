// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNpcBlackboardEntryTemplate_LazyGetUpdate.h>
#include <_unknown/ArkNpcEmboldenParams.h>

class ArkNpcBlackboardEntryKey_Emboldened;
class ArkNpcBlackboardKey_Emboldened;

// ArkNpcBlackboardEntry_Emboldened
// Header:  Prey/GameDll/ark/npc/blackboard/entry/emboldened/ArkNpcBlackboardEntry_Emboldened.h
class ArkNpcBlackboardEntry_Emboldened : public ArkNpcBlackboardEntryTemplate_LazyGetUpdate<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardEntryKey_Emboldened,ArkNpcBlackboardEntry_Emboldened,bool,bool>
{ // Size=32 (0x20)
public:
	ArkNpcEmboldenParams m_params;

	ArkNpcBlackboardEntry_Emboldened();
	void Evaluate(const ArkNpcBlackboardKey_Emboldened& _blackboardKey, const ArkNpcEmboldenParams& _params) { FEvaluate(this, _blackboardKey, _params); }
	bool Get() const { return FGet(this); }
	void Update(const ArkNpcBlackboardEntryKey_Emboldened& _entryKey, float _elapsedTime) { FUpdate(this, _entryKey, _elapsedTime); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }

	static inline auto FArkNpcBlackboardEntry_EmboldenedOv2 = PreyFunction<void(ArkNpcBlackboardEntry_Emboldened* const _this)>(0x129EF10);
	static inline auto FEvaluate = PreyFunction<void(ArkNpcBlackboardEntry_Emboldened* const _this, const ArkNpcBlackboardKey_Emboldened& _blackboardKey, const ArkNpcEmboldenParams& _params)>(0x129F0F0);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_Emboldened* const _this)>(0x129F1D0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_Emboldened* const _this, const ArkNpcBlackboardEntryKey_Emboldened& _entryKey, float _elapsedTime)>(0x129F230);
	static inline auto FSerialize = PreyFunction<void(ArkNpcBlackboardEntry_Emboldened* const _this, TSerialize _serializer)>(0x129F1E0);
};
#endif // MOONCRASH
