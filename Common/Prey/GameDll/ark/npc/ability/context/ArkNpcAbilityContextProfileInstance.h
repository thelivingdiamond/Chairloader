// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextInstance.h>
#include <_unknown/ArkWeighted.h>

class ArkNpcAbilityPrereq;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityContextProfileInstance
// Header:  Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextProfileInstance.h
class ArkNpcAbilityContextProfileInstance
{ // Size=80 (0x50)
public:
	using AbilityInstanceVector = std::vector<std::unique_ptr<ArkNpcAbilityInstance>>;
	using ContextInstanceVector = std::vector<ArkNpcAbilityContextInstance>;
	using PrereqInstanceVector = std::vector<std::unique_ptr<ArkNpcAbilityPrereqInstance>>;

	std::vector<std::unique_ptr<ArkNpcAbilityPrereqInstance>> m_localPrereqInstances;
	std::vector<ArkNpcAbilityContextInstance> m_contextInstances;
	std::vector<std::unique_ptr<ArkNpcAbilityInstance>> m_abilityInstances;
	uint64_t m_currentContextIndex;

	ArkNpcAbilityContextProfileInstance();
	ArkNpcAbilityContextProfileInstance(const ArkNpcAbilityPrereq* const * _ppFirstLocalPrereq, const ArkNpcAbilityPrereq* const * _ppLastLocalPrereq, const ArkWeighted<ArkNpcAbilityContext const *>* _pFirstWeightedContext, const ArkWeighted<ArkNpcAbilityContext const *>* _pLastWeightedContext);
	ArkNpcAbilityContextProfileInstance(ArkNpcAbilityContextProfileInstance&& _other);
	~ArkNpcAbilityContextProfileInstance();
	ArkNpcAbilityContextProfileInstance& operator=(ArkNpcAbilityContextProfileInstance _other) { return FoperatorEq(this, _other); }
	ArkNpcAbilityPrereqInstance& GetLocalPrereqInstance(uint64_t _prereqIndex) const { return FGetLocalPrereqInstance(this, _prereqIndex); }
	const ArkNpcAbilityContextInstance& GetContextInstance(uint64_t _contextIndex) const { return FGetContextInstance(this, _contextIndex); }
	void SetCurrentContextIndex(uint64_t _contextIndex) { FSetCurrentContextIndex(this, _contextIndex); }
	bool HasCurrentContext() const { return FHasCurrentContext(this); }
	uint64_t GetCurrentContextIndex() const { return FGetCurrentContextIndex(this); }

	static inline auto FArkNpcAbilityContextProfileInstanceOv2 = PreyFunction<void(ArkNpcAbilityContextProfileInstance* const _this)>(0x139C0E0);
	static inline auto FArkNpcAbilityContextProfileInstanceOv1 = PreyFunction<void(ArkNpcAbilityContextProfileInstance* const _this, const ArkNpcAbilityPrereq* const * _ppFirstLocalPrereq, const ArkNpcAbilityPrereq* const * _ppLastLocalPrereq, const ArkWeighted<ArkNpcAbilityContext const *>* _pFirstWeightedContext, const ArkWeighted<ArkNpcAbilityContext const *>* _pLastWeightedContext)>(0x139BBC0);
	static inline auto FArkNpcAbilityContextProfileInstanceOv0 = PreyFunction<void(ArkNpcAbilityContextProfileInstance* const _this, ArkNpcAbilityContextProfileInstance&& _other)>(0x139BB20);
	static inline auto FBitNotArkNpcAbilityContextProfileInstance = PreyFunction<void(ArkNpcAbilityContextProfileInstance* const _this)>(0x139C1D0);
	static inline auto FoperatorEq = PreyFunction<ArkNpcAbilityContextProfileInstance& (ArkNpcAbilityContextProfileInstance* const _this, ArkNpcAbilityContextProfileInstance _other)>(0x139C200);
	static inline auto FGetLocalPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityContextProfileInstance* const _this, uint64_t _prereqIndex)>(0x139C310);
	static inline auto FGetContextInstance = PreyFunction<const ArkNpcAbilityContextInstance& (const ArkNpcAbilityContextProfileInstance* const _this, uint64_t _contextIndex)>(0x139C300);
	static inline auto FSetCurrentContextIndex = PreyFunction<void(ArkNpcAbilityContextProfileInstance* const _this, uint64_t _contextIndex)>(0x18FAAB0);
	static inline auto FHasCurrentContext = PreyFunction<bool(const ArkNpcAbilityContextProfileInstance* const _this)>(0x139C320);
	static inline auto FGetCurrentContextIndex = PreyFunction<uint64_t(const ArkNpcAbilityContextProfileInstance* const _this)>(0x9F24D0);
};
#endif // MOONCRASH
