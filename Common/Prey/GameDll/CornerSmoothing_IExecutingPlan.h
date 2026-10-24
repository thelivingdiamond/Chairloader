// Header file automatically created from a PDB.
#pragma once

namespace CornerSmoothing
{
enum EPlanExecutionResult;
struct SOutput;
struct SState;
} // namespace CornerSmoothing

namespace CornerSmoothing
{

// CornerSmoothing::IExecutingPlan
// Header:  _unknown/CornerSmoothing__IExecutingPlan.h
struct IExecutingPlan
{ // Size=8 (0x8)
	virtual ~IExecutingPlan();
	virtual bool IsValidFor(const CornerSmoothing::SState& state) const = 0;
	virtual CornerSmoothing::EPlanExecutionResult Execute(const CornerSmoothing::SState& state, CornerSmoothing::SOutput& output) = 0;
};


} // namespace CornerSmoothing

