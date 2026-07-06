// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ai/gameaihelpers.h>
#include <_unknown/CGameAIInstanceBase.h>

// RangeContainer
// Header:  Prey/GameDll/ai/RangeModule.h
class RangeContainer : public CGameAIInstanceBase
{ // Size=32 (0x20)
public:
	// RangeContainer::Range
	// Header:  Prey/GameDll/ai/RangeModule.h
	struct Range
	{ // Size=32 (0x20)
		enum class State
		{
			Inside = 0,
			Outside = 1,
		};

		enum class TargetMode
		{
			UseAttentionTargetDistance = 0,
			UseLiveTargetDistance = 1,
		};

		string enterSignal;
		string leaveSignal;
		float rangeSq;
		RangeContainer::Range::State state;
		RangeContainer::Range::TargetMode targetMode;

	#if 0
		Range();
	#endif
	};

	using RangeID = uint8_t;
	using Ranges = std::vector<RangeContainer::Range>;

	std::vector<RangeContainer::Range> m_ranges;

	void Update(float frameTime) { FUpdate(this, frameTime); }
	uint8_t AddRange(const RangeContainer::Range& range) { return FAddRange(this, range); }

#if 0
	void ResetRanges();
	const RangeContainer::Range* GetRange(uint8_t _arg0_) const;
	void ChangeRange(uint8_t _arg0_, float _arg1_);
	bool GetTargetDistances(float& _arg0_, float& _arg1_) const;
#endif

	static inline auto FUpdate = PreyFunction<void(RangeContainer* const _this, float frameTime)>(0x10CC060);
	static inline auto FAddRange = PreyFunction<uint8_t(RangeContainer* const _this, const RangeContainer::Range& range)>(0x10CC030);
};

// RangeModule
// Header:  Prey/GameDll/ai/RangeModule.h
class RangeModule : public AIModuleWithInstanceUpdate<RangeModule,RangeContainer,16,8>
{ // Size=56 (0x38)
public:
	virtual const char* GetName() const;

	static inline auto FGetName = PreyFunction<const char* (const RangeModule* const _this)>(0x10C68C0);
};
#endif // MOONCRASH
