// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkWeighted.h>

class ArkNpc;
class ArkNpcAbilityContext;
class ArkNpcAbilityContextProfileInstance;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereq;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityContextProfile
// Header:  Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextProfile.h
class ArkNpcAbilityContextProfile
{ // Size=40 (0x28)
public:
	// ArkNpcAbilityContextProfile::ContextIndexPair
	// Header:  Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextProfile.h
	struct ContextIndexPair
	{ // Size=16 (0x10)
		const ArkNpcAbilityContext* m_pContext;
		uint64_t m_contextIndex;

	#if 0
		ContextIndexPair();
		ContextIndexPair(const ArkNpcAbilityContext& _arg0_, const uint64_t _arg1_);
	#endif
	};

	using PrereqVector = std::vector<const ArkNpcAbilityPrereq*>;

	std::vector<const ArkNpcAbilityPrereq*> m_localPrereqs;
	const ArkWeighted<ArkNpcAbilityContext const *>* m_pFirstWeightedContext;
	const ArkWeighted<ArkNpcAbilityContext const *>* m_pLastWeightedContext;

	ArkNpcAbilityContextProfile(const ArkWeighted<ArkNpcAbilityContext const *>* _pFirstWeightedContext, const ArkWeighted<ArkNpcAbilityContext const *>* _pLastWeightedContext);
	ArkNpcAbilityContextProfileInstance MakeContextProfileInstance() const { alignas(ArkNpcAbilityContextProfileInstance) std::byte _return_buf_[sizeof(ArkNpcAbilityContextProfileInstance)]; return *FMakeContextProfileInstance(this, reinterpret_cast<ArkNpcAbilityContextProfileInstance*>(_return_buf_)); }
	void Initialize(ArkNpc& _npc, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FInitialize(this, _npc, _contextProfileInstance); }
	void Finalize(ArkNpc& _npc, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FFinalize(this, _npc, _contextProfileInstance); }
	void UpdateLocalPrereqs(ArkNpc& _npc, float _elapsedTime, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FUpdateLocalPrereqs(this, _npc, _elapsedTime, _contextProfileInstance); }
	uint64_t ChooseContext(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { return FChooseContext(this, _npc, _params, _contextProfileInstance); }
	bool HasContext(uint64_t _contextId) const { return FHasContext(this, _contextId); }
	bool CanPerformContext(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { return FCanPerformContext(this, _npc, _contextId, _params, _contextProfileInstance); }
	EArkNpcAbilityPerformanceResult PerformContext(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { return FPerformContext(this, _npc, _contextId, _params, _contextProfileInstance); }
	uint64_t GetCurrentContextId(const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { return FGetCurrentContextId(this, _contextProfileInstance); }
	void UpdateCurrentContext(ArkNpc& _npc, float _elapsedTime, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FUpdateCurrentContext(this, _npc, _elapsedTime, _contextProfileInstance); }
	void InterruptCurrentContext(ArkNpc& _npc, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FInterruptCurrentContext(this, _npc, _contextProfileInstance); }
	void OnContextStarted(uint64_t _contextId, ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FOnContextStarted(this, _contextId, _contextProfileInstance); }
	void OnContextFinished(uint64_t _contextId, ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FOnContextFinished(this, _contextId, _contextProfileInstance); }
	void Serialize(TSerialize _serializer, ArkNpcAbilityContextProfileInstance& _contextProfileInstance) const { FSerialize(this, _serializer, _contextProfileInstance); }
	ArkNpcAbilityContextProfile::ContextIndexPair GetContextIndexPair(uint64_t _contextId) const { alignas(ArkNpcAbilityContextProfile::ContextIndexPair) std::byte _return_buf_[sizeof(ArkNpcAbilityContextProfile::ContextIndexPair)]; return *FGetContextIndexPair(this, reinterpret_cast<ArkNpcAbilityContextProfile::ContextIndexPair*>(_return_buf_), _contextId); }

	static inline auto FArkNpcAbilityContextProfileOv2 = PreyFunction<void(ArkNpcAbilityContextProfile* const _this, const ArkWeighted<ArkNpcAbilityContext const *>* _pFirstWeightedContext, const ArkWeighted<ArkNpcAbilityContext const *>* _pLastWeightedContext)>(0x139A530);
	static inline auto FMakeContextProfileInstance = PreyFunction<ArkNpcAbilityContextProfileInstance*(const ArkNpcAbilityContextProfile* const _this, ArkNpcAbilityContextProfileInstance* _return_value_)>(0x139AE80);
	static inline auto FInitialize = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, ArkNpc& _npc, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139AD10);
	static inline auto FFinalize = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, ArkNpc& _npc, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139AAB0);
	static inline auto FUpdateLocalPrereqs = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, ArkNpc& _npc, float _elapsedTime, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139B230);
	static inline auto FChooseContext = PreyFunction<uint64_t(const ArkNpcAbilityContextProfile* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139A8C0);
	static inline auto FHasContext = PreyFunction<bool(const ArkNpcAbilityContextProfile* const _this, uint64_t _contextId)>(0x139ACF0);
	static inline auto FCanPerformContext = PreyFunction<bool(const ArkNpcAbilityContextProfile* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139A830);
	static inline auto FPerformContext = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityContextProfile* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139AF70);
	static inline auto FGetCurrentContextId = PreyFunction<uint64_t(const ArkNpcAbilityContextProfile* const _this, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139ACB0);
	static inline auto FUpdateCurrentContext = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, ArkNpc& _npc, float _elapsedTime, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139B1C0);
	static inline auto FInterruptCurrentContext = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, ArkNpc& _npc, const ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139AE20);
	static inline auto FOnContextStarted = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, uint64_t _contextId, ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139AED0);
	static inline auto FOnContextFinished = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, uint64_t _contextId, ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139AEC0);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcAbilityContextProfile* const _this, TSerialize _serializer, ArkNpcAbilityContextProfileInstance& _contextProfileInstance)>(0x139B000);
	static inline auto FGetContextIndexPair = PreyFunction<ArkNpcAbilityContextProfile::ContextIndexPair*(const ArkNpcAbilityContextProfile* const _this, ArkNpcAbilityContextProfile::ContextIndexPair* _return_value_, uint64_t _contextId)>(0x139ABC0);
};
#endif // MOONCRASH
