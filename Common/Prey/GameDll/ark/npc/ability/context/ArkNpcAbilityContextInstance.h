// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpcAbility;
class ArkNpcAbilityContextInstanceStorage;
class ArkNpcAbilityInstance;
class ArkNpcAbilityPrereq;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityContextInstance
// Header:  Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextInstance.h
class ArkNpcAbilityContextInstance
{ // Size=32 (0x20)
public:
	using PrereqInstanceVector = std::vector<ArkNpcAbilityPrereqInstance*>;

	std::vector<ArkNpcAbilityPrereqInstance*> m_prereqInstances;
	ArkNpcAbilityInstance* m_pAbilityInstance;

	ArkNpcAbilityContextInstance(const ArkNpcAbilityPrereq* const * _pFirstPrereq, const ArkNpcAbilityPrereq* const * _pLastPrereq, const ArkNpcAbility& _ability, ArkNpcAbilityContextInstanceStorage& _storage);
	ArkNpcAbilityContextInstance(ArkNpcAbilityContextInstance&& _other);
	ArkNpcAbilityInstance& GetAbilityInstance() const { return FGetAbilityInstance(this); }
	ArkNpcAbilityPrereqInstance& GetPrereqInstance(uint64_t _prereqInstanceIndex) const { return FGetPrereqInstance(this, _prereqInstanceIndex); }

#if 0
	ArkNpcAbilityContextInstance& operator=(ArkNpcAbilityContextInstance _arg0_);
#endif

	static inline auto FArkNpcAbilityContextInstanceOv1 = PreyFunction<void(ArkNpcAbilityContextInstance* const _this, const ArkNpcAbilityPrereq* const * _pFirstPrereq, const ArkNpcAbilityPrereq* const * _pLastPrereq, const ArkNpcAbility& _ability, ArkNpcAbilityContextInstanceStorage& _storage)>(0x139A070);
	static inline auto FArkNpcAbilityContextInstanceOv0 = PreyFunction<void(ArkNpcAbilityContextInstance* const _this, ArkNpcAbilityContextInstance&& _other)>(0x139A030);
	static inline auto FGetAbilityInstance = PreyFunction<ArkNpcAbilityInstance& (const ArkNpcAbilityContextInstance* const _this)>(0x598E60);
	static inline auto FGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityContextInstance* const _this, uint64_t _prereqInstanceIndex)>(0x139C310);
};
#endif // MOONCRASH
