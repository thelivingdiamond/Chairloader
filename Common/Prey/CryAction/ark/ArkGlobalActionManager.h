// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include "IArkGlobalActionManager.h"
#include <Prey/CryCore/StdAfx.h>
#include <ChairLoader/PreyFunction.h>
#include <Prey/CryFlowGraph/IFlowGraph.h>

class ArkGlobalAction : public IArkGlobalAction // Id=8004665 Size=24
{
public:
    _smart_ptr<IFlowGraph> m_pFlowGraph;
    string m_fileName;

    ArkGlobalAction(string _fileName);
    virtual _smart_ptr<IFlowGraph> GetFlowGraph() const {return FGetFlowGraph(this);};
    virtual string GetFileName() const {return FGetFileName(this);};

#if 0
    void Serialize(XmlNodeRef const &arg0, bool arg1);
#endif

    static inline auto FGetFlowGraph = PreyFunction<_smart_ptr<IFlowGraph>(ArkGlobalAction const *const _this)>(0x2A3BE0);
    static inline auto FGetFileName = PreyFunction<string(ArkGlobalAction const *const _this)>(0xE93430);
};

// Header: FromCpp
// CryEngine/cryaction/ark/ArkGlobalActionManager.h
class ArkGlobalActionManager : public IArkGlobalActionManager // Id=8004666 Size=32
{
public:
	std::vector<ArkGlobalAction> m_actions;
	
	void LoadActions() { FLoadActions(this); }
	void Reset() { FReset(this); }
	virtual _smart_ptr<IFlowGraph> CreateAction(string const &_fileName);
	virtual std::vector<IArkGlobalAction const *> GetActions() const;
	
#if 0
	void Serialize(TSerialize arg0) const;
	void PostSerialize() const;
#endif
	
	static inline auto FLoadActions = PreyFunction<void(ArkGlobalActionManager *const _this)>(0x2A44B0);
	static inline auto FReset = PreyFunction<void(ArkGlobalActionManager *const _this)>(0x2A47B0);
	static inline auto FCreateAction = PreyFunction<_smart_ptr<IFlowGraph>(ArkGlobalActionManager *const _this, string const &_fileName)>(0x2A43C0);
	static inline auto FGetActions = PreyFunction<std::vector<IArkGlobalAction const *>(ArkGlobalActionManager const *const _this)>(0x2A4400);
};

