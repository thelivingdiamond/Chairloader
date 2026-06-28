// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpcAbility;
class ArkNpcAbilityInstance;
class ArkNpcAbilityManager;
class ArkNpcAbilityPrereq;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityContextInstanceStorage
// Header:  Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextInstanceStorage.h
class ArkNpcAbilityContextInstanceStorage
{ // Size=24 (0x18)
public:
	using PrereqInstanceMap = std::unordered_map<const ArkNpcAbilityPrereq*, ArkNpcAbilityPrereqInstance*>;
	using AbilityInstanceMap = std::unordered_map<const ArkNpcAbility*, ArkNpcAbilityInstance*>;

	const ArkNpcAbilityManager* m_pAbilityManager;
	const std::unordered_map<const ArkNpcAbilityPrereq*, ArkNpcAbilityPrereqInstance*>* m_pLocalPrereqInstanceMap;
	const std::unordered_map<const ArkNpcAbility*, ArkNpcAbilityInstance*>* m_pAbilityInstanceMap;

	ArkNpcAbilityContextInstanceStorage(const std::unordered_map<const ArkNpcAbilityPrereq*, ArkNpcAbilityPrereqInstance*>& _localPrereqInstanceMap, const std::unordered_map<const ArkNpcAbility*, ArkNpcAbilityInstance*>& _abilityInstanceMap);
	ArkNpcAbilityPrereqInstance& GetGlobalPrereqInstance(const ArkNpcAbilityPrereq& _prereq) { return FGetGlobalPrereqInstance(this, _prereq); }
	ArkNpcAbilityPrereqInstance& GetLocalPrereqInstance(const ArkNpcAbilityPrereq& _prereq) { return FGetLocalPrereqInstance(this, _prereq); }
	ArkNpcAbilityInstance& GetAbilityInstance(const ArkNpcAbility& _ability) { return FGetAbilityInstance(this, _ability); }

#if 0
	ArkNpcAbilityContextInstanceStorage(const ArkNpcAbilityContextInstanceStorage& _arg0_);
	ArkNpcAbilityContextInstanceStorage& operator=(const ArkNpcAbilityContextInstanceStorage& _arg0_);
#endif

	static inline auto FArkNpcAbilityContextInstanceStorageOv1 = PreyFunction<void(ArkNpcAbilityContextInstanceStorage* const _this, const std::unordered_map<const ArkNpcAbilityPrereq*, ArkNpcAbilityPrereqInstance*>& _localPrereqInstanceMap, const std::unordered_map<const ArkNpcAbility*, ArkNpcAbilityInstance*>& _abilityInstanceMap)>(0x139A1C0);
	static inline auto FGetGlobalPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (ArkNpcAbilityContextInstanceStorage* const _this, const ArkNpcAbilityPrereq& _prereq)>(0x139A2F0);
	static inline auto FGetLocalPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (ArkNpcAbilityContextInstanceStorage* const _this, const ArkNpcAbilityPrereq& _prereq)>(0x139A300);
	static inline auto FGetAbilityInstance = PreyFunction<ArkNpcAbilityInstance& (ArkNpcAbilityContextInstanceStorage* const _this, const ArkNpcAbility& _ability)>(0x139A1E0);
};
#endif // MOONCRASH
