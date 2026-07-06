// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CornerSmoothing__IExecutingPlan.h>
#include <_unknown/CornerSmoothing__SOutput.h>
#include <_unknown/CornerSmoothing__SShootOutData.h>

namespace CornerSmoothing
{
class CStopPlan;
class CTakeCornerPlan;
enum EPlanExecutionResult;
struct SState;
} // namespace CornerSmoothing

namespace CornerSmoothing
{

// CornerSmoothing::CCornerSmoother2
// Header:  Prey/GameDll/cornersmoother.h
class CCornerSmoother2
{ // Size=24 (0x18)
public:
	CornerSmoothing::IExecutingPlan* m_pCurrentPlan;
	CornerSmoothing::CTakeCornerPlan* m_pTakeCornerPlan;
	CornerSmoothing::CStopPlan* m_pStopPlan;

	CCornerSmoother2();
	~CCornerSmoother2();
	bool Update(const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output) { return FUpdate(this, state, output); }

#if 0
	void Reset();
#endif

	static inline auto FCCornerSmoother2 = PreyFunction<void(CornerSmoothing::CCornerSmoother2* const _this)>(0x1F4DF0);
	static inline auto FBitNotCCornerSmoother2 = PreyFunction<void(CornerSmoothing::CCornerSmoother2* const _this)>(0x17BBE60);
	static inline auto FUpdate = PreyFunction<bool(CornerSmoothing::CCornerSmoother2* const _this, const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output)>(0x17BD950);
};

// CornerSmoothing::CStopPlan
// Header:  Prey/GameDll/cornersmoother.h
class CStopPlan : public CornerSmoothing::IExecutingPlan
{ // Size=8 (0x8)
public:
	virtual bool IsValidFor(const CornerSmoothing::SState& state) const;
	virtual CornerSmoothing::EPlanExecutionResult Execute(const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output);

#if 0
	CStopPlan();
#endif

	static inline auto FIsValidFor = PreyFunction<bool(const CornerSmoothing::CStopPlan* const _this, const CornerSmoothing::SState& state)>(0x1A302A0);
	static inline auto FExecute = PreyFunction<CornerSmoothing::EPlanExecutionResult(CornerSmoothing::CStopPlan* const _this, const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output)>(0x17BC210);
};

// CornerSmoothing::CTakeCornerPlan
// Header:  Prey/GameDll/cornersmoother.h
class CTakeCornerPlan : public CornerSmoothing::IExecutingPlan
{ // Size=832 (0x340)
public:
	const CornerSmoothing::SShootOutData m_data;
	const Vec3 m_startPosition;
	float m_lastDistToTargetSq;
	float m_lastAlpha;
	Vec2 m_lastPositionOnSpline2D;
	CornerSmoothing::SOutput m_lastOutput;

	CTakeCornerPlan(const CornerSmoothing::SState& state, const CornerSmoothing::SShootOutData& data);
	virtual bool IsValidFor(const CornerSmoothing::SState& state) const;
	virtual CornerSmoothing::EPlanExecutionResult Execute(const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output);

	static inline auto FCTakeCornerPlanOv2 = PreyFunction<void(CornerSmoothing::CTakeCornerPlan* const _this, const CornerSmoothing::SState& state, const CornerSmoothing::SShootOutData& data)>(0x17BBC60);
	static inline auto FIsValidFor = PreyFunction<bool(const CornerSmoothing::CTakeCornerPlan* const _this, const CornerSmoothing::SState& state)>(0x17BC720);
	static inline auto FExecute = PreyFunction<CornerSmoothing::EPlanExecutionResult(CornerSmoothing::CTakeCornerPlan* const _this, const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output)>(0x17BC230);
};


} // namespace CornerSmoothing
#endif // MOONCRASH
