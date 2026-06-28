// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>

struct ArkDamageInfo;
class ArkResponseQuery;

// ArkPlayerDeathSummarizer
// Header:  Prey/GameDll/ark/dialog/ArkPlayerDeathSummarizer.h
class ArkPlayerDeathSummarizer
{ // Size=264 (0x108)
public:
	ArkSpeaker<ArkDialogPlayerNull> m_speaker;

	ArkPlayerDeathSummarizer();
	~ArkPlayerDeathSummarizer();
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	uint64_t GetSummary(const ArkDamageInfo& _damageInfo) { return FGetSummary(this, _damageInfo); }
	static wstring GetString(uint64_t _summaryId) { return FGetString(_summaryId); }

#if 0
	static void Log(uint64_t _arg0_);
	uint64_t RunQuery(const char* _arg0_, ArkResponseQuery& _arg1_);
#endif

	static inline auto FArkPlayerDeathSummarizerOv1 = PreyFunction<void(ArkPlayerDeathSummarizer* const _this)>(0x11C82C0);
	static inline auto FBitNotArkPlayerDeathSummarizer = PreyFunction<void(ArkPlayerDeathSummarizer* const _this)>(0x11C84C0);
	static inline auto FInit = PreyFunction<void(ArkPlayerDeathSummarizer* const _this)>(0x11C88E0);
	static inline auto FReset = PreyFunction<void(ArkPlayerDeathSummarizer* const _this)>(0x11C8990);
	static inline auto FGetSummary = PreyFunction<uint64_t(ArkPlayerDeathSummarizer* const _this, const ArkDamageInfo& _damageInfo)>(0x11C8640);
	static inline auto FGetString = PreyFunction<wstring(uint64_t _summaryId)>(0x11C8540);
};
#endif // MOONCRASH
