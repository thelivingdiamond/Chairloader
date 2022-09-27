// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>

// Header: MadeUp
// _unknown/IArkGlobalActionManager.h
class IFlowGraph;
class IArkGlobalAction // Id=8001C7A Size=8
{
public:
    virtual _smart_ptr<IFlowGraph> GetFlowGraph() const = 0;
    virtual string GetFileName() const = 0;
};



class IArkGlobalActionManager // Id=8001C76 Size=8
{
public:
	virtual std::vector<IArkGlobalAction const *> GetActions() const = 0;
	virtual _smart_ptr<IFlowGraph> CreateAction(string const &arg0) = 0;
};

