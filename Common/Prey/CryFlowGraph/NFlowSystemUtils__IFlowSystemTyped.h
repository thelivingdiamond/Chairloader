// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryFlowGraph/NFlowSystemUtils__Wrapper.h>
#include "SFlowSystemVoid.h"

struct SFlowAddress;

namespace NFlowSystemUtils
{

// Header: MadeUp
// _unknown/NFlowSystemUtils__IFlowSystemTyped.h
struct IFlowSystemTyped // Id=8000F54 Size=8
{
	virtual ~IFlowSystemTyped();
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<SFlowSystemVoid> const &arg1) = 0;
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<int> const &arg1) = 0;
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<float> const &arg1) = 0;
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<unsigned int> const &arg1) = 0;
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<Vec3> const &arg1) = 0;
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<string> const &arg1) = 0;
	virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<bool> const &arg1) = 0;
};

} // namespace NFlowSystemUtils

