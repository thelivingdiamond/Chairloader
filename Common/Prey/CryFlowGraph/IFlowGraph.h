// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/stdafx.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include "NFlowSystemUtils__IFlowSystemTyped.h"
#include "IFlowNodeIterator.h"
#include "IFlowEdgeIterator.h"

class ICrySizer;
struct ICustomAction;
struct IFlowGraphModule;
struct IFlowNode;
struct IFlowNodeData;
struct SFlowAddress;
struct SFlowNodeActivationListener;
struct SFlowNodeConfig;
class TFlowInputData;
class XmlNodeRef;

// Header: MadeUp
// _unknown/IFlowGraph.h
struct IFlowGraph : public NFlowSystemUtils::IFlowSystemTyped // Id=8000F53 Size=8
{
	enum EFlowGraphType
	{
		eFGT_Default = 0,
		eFGT_UIAction = 1,
		eFGT_Module = 2,
		eFGT_CustomAction = 3,
		eFGT_MaterialFx = 4,
		eFGT_GlobalAction = 5,
	};

	struct SGraphToken // Id=8001C48 Size=24
	{
		int id;
		string name;
		EFlowDataTypes type;
	};

	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual _smart_ptr<IFlowGraph> Clone() = 0;
	virtual void Clear() = 0;
	virtual _smart_ptr<IFlowNodeIterator> CreateNodeIterator() = 0;
	virtual _smart_ptr<IFlowEdgeIterator> CreateEdgeIterator() = 0;
	virtual void SetGraphEntity(unsigned arg0, int arg1) = 0;
	virtual unsigned GetGraphEntity(int arg0) const = 0;
	virtual void SetEnabled(bool arg0) = 0;
	virtual bool IsEnabled() const = 0;
	virtual void SetActive(bool arg0) = 0;
	virtual bool IsActive() const = 0;
	virtual void UnregisterFromFlowSystem() = 0;
	virtual void SetType(IFlowGraph::EFlowGraphType arg0) = 0;
	virtual IFlowGraph::EFlowGraphType GetType() const = 0;
	virtual void Update() = 0;
	virtual bool SerializeXML(XmlNodeRef const &arg0, bool arg1) = 0;
	virtual void Serialize(TSerialize arg0) = 0;
	virtual void PostSerialize() = 0;
	virtual void InitializeValues() = 0;
	virtual void PrecacheResources() = 0;
	virtual void EnsureSortedEdges() = 0;
	virtual SFlowAddress ResolveAddress(const char *arg0, bool arg1) = 0;
	virtual uint16_t ResolveNode(const char *arg0) = 0;
	virtual uint16_t CreateNode(uint16_t arg0, const char *arg1, void *arg2) = 0;
	virtual uint16_t CreateNode(const char *arg0, const char *arg1, void *arg2) = 0;
	virtual IFlowNodeData *GetNodeData(uint16_t arg0) = 0;
	virtual bool SetNodeName(uint16_t arg0, const char *arg1) = 0;
	virtual const char *GetNodeName(uint16_t arg0) = 0;
	virtual uint16_t GetNodeTypeId(uint16_t arg0) = 0;
	virtual const char *GetNodeTypeName(uint16_t arg0) = 0;
	virtual void RemoveNode(const char *arg0) = 0;
	virtual void RemoveNode(uint16_t arg0) = 0;
	virtual void SetUserData(uint16_t arg0, XmlNodeRef const &arg1) = 0;
	virtual XmlNodeRef GetUserData(uint16_t arg0) = 0;
	virtual bool LinkNodes(SFlowAddress arg0, SFlowAddress arg1) = 0;
	virtual void UnlinkNodes(SFlowAddress arg0, SFlowAddress arg1) = 0;
	virtual void RegisterFlowNodeActivationListener(SFlowNodeActivationListener *arg0) = 0;
	virtual void RemoveFlowNodeActivationListener(SFlowNodeActivationListener *arg0) = 0;
	virtual bool NotifyFlowNodeActivationListeners(uint16_t arg0, uint8_t arg1, uint16_t arg2, uint8_t arg3, const char *arg4) = 0;
	virtual void SetEntityId(uint16_t arg0, unsigned arg1) = 0;
	virtual unsigned GetEntityId(uint16_t arg0) = 0;
	virtual _smart_ptr<IFlowGraph> GetClonedFlowGraph() const = 0;
	virtual void GetNodeConfiguration(uint16_t arg0, SFlowNodeConfig &arg1) = 0;
	virtual void SetRegularlyUpdated(uint16_t arg0, bool arg1) = 0;
	virtual void RequestFinalActivation(uint16_t arg0) = 0;
	virtual void ActivateNode(uint16_t arg0) = 0;
	virtual void ActivatePortAny(SFlowAddress arg0, TFlowInputData const &arg1) = 0;
	virtual void ActivatePortCString(SFlowAddress arg0, const char *arg1) = 0;
	virtual bool SetInputValue(uint16_t arg0, uint8_t arg1, TFlowInputData const &arg2) = 0;
	virtual bool IsOutputConnected(SFlowAddress arg0) = 0;
	virtual TFlowInputData const *GetInputValue(uint16_t arg0, uint8_t arg1) = 0;
	virtual bool GetActivationInfo(const char *arg0, IFlowNode::SActivationInfo &arg1) = 0;
	virtual void SetSuspended(bool arg0) = 0;
	virtual bool IsSuspended() const = 0;
	virtual void SetCustomAction(ICustomAction *arg0) = 0;
	virtual ICustomAction *GetCustomAction() const = 0;
	virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
	virtual void RemoveGraphTokens(bool arg0) = 0;
	virtual bool UpdateGraphToken(int arg0, const char *arg1, EFlowDataTypes arg2) = 0;
	virtual bool LoadGraphToken(int arg0, const char *arg1, EFlowDataTypes arg2) = 0;
	virtual int CloneGraphToken(IFlowGraph::SGraphToken const &arg0) = 0;
	virtual uint64_t GetGraphTokenCount() const = 0;
	virtual IFlowGraph::SGraphToken const *GetGraphToken(uint64_t arg0) const = 0;
	virtual unsigned GetGraphId() const = 0;
	virtual void OnNodeConfigReload(IFlowNodeData &arg0) = 0;
	virtual void SetOwningModule(IFlowGraphModule *arg0) = 0;
	virtual IFlowGraphModule *GetOwningModule() const = 0;
	virtual void FixCreatePhantomRequestEntityIdOutput(SFlowAddress arg0, unsigned arg1) = 0;
	virtual ~IFlowGraph() {};
	
#if 0
	void ActivatePort(SFlowAddress arg0, TFlowInputData const &arg1);
#endif
};

