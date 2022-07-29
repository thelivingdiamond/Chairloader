// Header file automatically created from a PDB.

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkUnanimous // Id=801348B Size=16
{
public:
	uint64_t m_trueCount;
	uint64_t m_falseCount;

	ArkUnanimous();
	ArkUnanimous(uint64_t _trueCount);
	bool PushTrue() { return FPushTrue(this); }
	bool PopTrue() { return FPopTrue(this); }
	bool PushFalse() { return FPushFalse(this); }
	bool PopFalse() { return FPopFalse(this); }
	bool IsUnanimous() const { return FIsUnanimous(this); }
	void SetTrueCount(uint64_t _trueCount) { FSetTrueCount(this, _trueCount); }
	void SetFalseCount(uint64_t _falseCount) { FSetFalseCount(this, _falseCount); }
	uint64_t GetTrueCount() const { return FGetTrueCount(this); }
	uint64_t GetFalseCount() const { return FGetFalseCount(this); }

#if 0
	int* operator int ArkSafeBool<class ArkUnanimous>::* () const;
#endif

	static inline auto FPushTrue = PreyFunction<bool(ArkUnanimous* const _this)>(0x1056F20);
	static inline auto FPopTrue = PreyFunction<bool(ArkUnanimous* const _this)>(0x1056EE0);
	static inline auto FPushFalse = PreyFunction<bool(ArkUnanimous* const _this)>(0x1056F00);
	static inline auto FPopFalse = PreyFunction<bool(ArkUnanimous* const _this)>(0x1056EC0);
	static inline auto FIsUnanimous = PreyFunction<bool(ArkUnanimous const* const _this)>(0x1056EA0);
	static inline auto FSetTrueCount = PreyFunction<void(ArkUnanimous* const _this, uint64_t _trueCount)>(0x10BE320);
	static inline auto FSetFalseCount = PreyFunction<void(ArkUnanimous* const _this, uint64_t _falseCount)>(0x414F30);
	static inline auto FGetTrueCount = PreyFunction<uint64_t(ArkUnanimous const* const _this)>(0x12E5E70);
	static inline auto FGetFalseCount = PreyFunction<uint64_t(ArkUnanimous const* const _this)>(0x12AAC70);
};

#pragma once
#if 0
#include <_unknown/ArkNpcBodyStateEnterParams.h>

class ArkNpc;
class ArkNpcBodyStateObserver_Busy;

// Header: FromCpp
// Prey/ArkCommon/arkunanimous.h
struct ArkNpcBodyStateEnterParams_Busy : public ArkNpcBodyStateEnterParams // Id=8014178 Size=16
{
	ArkNpcBodyStateObserver_Busy *const m_pObserver;
	
	ArkNpcBodyStateEnterParams_Busy(ArkNpc &_npc);
	ArkNpcBodyStateEnterParams_Busy(ArkNpc &_npc, ArkNpcBodyStateObserver_Busy &_observer);
};
#endif

