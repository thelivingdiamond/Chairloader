// Header file automatically created from a PDB.
#pragma once

class ICrySizer;
struct IFlowGraph;
class SmartScriptTable;
class XmlNodeRef;

// IUIAction
// Header:  _unknown/IUIAction.h
// Include: Prey/CrySystem/Scaleform/IFlashUI.h
struct IUIAction
{ // Size=8 (0x8)
	enum EUIActionType
	{
		eUIAT_FlowGraph = 0,
		eUIAT_LuaScript = 1,
	};

	virtual ~IUIAction();
	virtual IUIAction::EUIActionType GetType() const = 0;
	virtual const char* GetName() const = 0;
	virtual void SetName(const char* sName) = 0;
	virtual bool Init() = 0;
	virtual bool IsValid() const = 0;
	virtual void SetEnabled(bool bEnabled) = 0;
	virtual bool IsEnabled() const = 0;
	virtual _smart_ptr<IFlowGraph> GetFlowGraph() const = 0;
	virtual SmartScriptTable GetScript() const = 0;
	virtual bool Serialize(XmlNodeRef& xmlNode, bool bIsLoading) = 0;
	virtual bool Serialize(const char* scriptFile, bool bIsLoading) = 0;
	virtual void GetMemoryUsage(ICrySizer* s) const = 0;
};

