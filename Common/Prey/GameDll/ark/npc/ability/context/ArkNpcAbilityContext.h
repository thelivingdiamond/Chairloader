// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpc;
class ArkNpcAbility;
class ArkNpcAbilityContextInstance;
class ArkNpcAbilityContextInstanceStorage;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereq;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityContext
// Header:  Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContext.h
class ArkNpcAbilityContext
{ // Size=48 (0x30)
public:
	uint64_t m_id;
	const uint64_t* m_pFirstPrereqUnsortedIndex;
	const uint64_t* m_pLastPrereqUnsortedIndex;
	const ArkNpcAbilityPrereq* const * m_ppFirstPrereq;
	const ArkNpcAbilityPrereq* const * m_ppLastPrereq;
	const ArkNpcAbility* m_pAbility;

	ArkNpcAbilityContext(uint64_t _id, const uint64_t* _pFirstPrereqUnsortedIndex, const uint64_t* _pLastPrereqUnsortedIndex, const ArkNpcAbilityPrereq* const * _ppFirstPrereq, const ArkNpcAbilityPrereq* const * _ppLastPrereq, const ArkNpcAbility& _ability);
	uint64_t GetId() const { return FGetId(this); }
	const ArkNpcAbility& GetAbility() const { return FGetAbility(this); }
	ArkNpcAbilityContextInstance MakeContextInstance(ArkNpcAbilityContextInstanceStorage& _storage) const { alignas(ArkNpcAbilityContextInstance) std::byte _return_buf_[sizeof(ArkNpcAbilityContextInstance)]; return *FMakeContextInstance(this, reinterpret_cast<ArkNpcAbilityContextInstance*>(_return_buf_), _storage); }
	bool CanBePerformed(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextInstance& _contextInstance) const { return FCanBePerformed(this, _npc, _params, _contextInstance); }
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextInstance& _contextInstance) const { return FPerform(this, _npc, _params, _contextInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, const ArkNpcAbilityContextInstance& _contextInstance) const { FUpdate(this, _npc, _elapsedTime, _contextInstance); }
	void OnContextStarted(uint64_t _contextId, const ArkNpcAbilityContextInstance& _contextInstance) const { FOnContextStarted(this, _contextId, _contextInstance); }
	void Interrupt(ArkNpc& _npc, const ArkNpcAbilityContextInstance& _contextInstance) const { FInterrupt(this, _npc, _contextInstance); }
	bool GetMaxTargetDistancePrereq(float& _maxDist) const { return FGetMaxTargetDistancePrereq(this, _maxDist); }
	void Serialize(TSerialize _serializer, const ArkNpcAbilityContextInstance& _contextInstance) const { FSerialize(this, _serializer, _contextInstance); }

	static inline auto FArkNpcAbilityContext = PreyFunction<void(ArkNpcAbilityContext* const _this, uint64_t _id, const uint64_t* _pFirstPrereqUnsortedIndex, const uint64_t* _pLastPrereqUnsortedIndex, const ArkNpcAbilityPrereq* const * _ppFirstPrereq, const ArkNpcAbilityPrereq* const * _ppLastPrereq, const ArkNpcAbility& _ability)>(0x13999F0);
	static inline auto FGetId = PreyFunction<uint64_t(const ArkNpcAbilityContext* const _this)>(0x1112EA0);
	static inline auto FGetAbility = PreyFunction<const ArkNpcAbility& (const ArkNpcAbilityContext* const _this)>(0x7E3C90);
	static inline auto FMakeContextInstance = PreyFunction<ArkNpcAbilityContextInstance*(const ArkNpcAbilityContext* const _this, ArkNpcAbilityContextInstance* _return_value_, ArkNpcAbilityContextInstanceStorage& _storage)>(0x1399BC0);
	static inline auto FCanBePerformed = PreyFunction<bool(const ArkNpcAbilityContext* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextInstance& _contextInstance)>(0x1399A20);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbilityContext* const _this, ArkNpc& _npc, const ArkNpcAbilityParams& _params, const ArkNpcAbilityContextInstance& _contextInstance)>(0x1399C80);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbilityContext* const _this, ArkNpc& _npc, float _elapsedTime, const ArkNpcAbilityContextInstance& _contextInstance)>(0x1399EF0);
	static inline auto FOnContextStarted = PreyFunction<void(const ArkNpcAbilityContext* const _this, uint64_t _contextId, const ArkNpcAbilityContextInstance& _contextInstance)>(0x1399BF0);
	static inline auto FInterrupt = PreyFunction<void(const ArkNpcAbilityContext* const _this, ArkNpc& _npc, const ArkNpcAbilityContextInstance& _contextInstance)>(0x1399B80);
	static inline auto FGetMaxTargetDistancePrereq = PreyFunction<bool(const ArkNpcAbilityContext* const _this, float& _maxDist)>(0x1399AF0);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcAbilityContext* const _this, TSerialize _serializer, const ArkNpcAbilityContextInstance& _contextInstance)>(0x1399D00);
};
#endif // MOONCRASH
