// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>

struct IConsoleCmdArgs;
class IFlowNode;

// Header: FromCpp
// Prey/GameDll/ark/flowgraph/arkflowgraphmanager.h
class CArkFlowGraphManager // Id=8015322 Size=136
{
public:
	struct ConsoleEvent // Id=8015328 Size=8
	{
		unsigned m_graphID;
		uint16_t m_nodeID;
	};

	using CommandHandler = std::pair<char const *,std::function<void __cdecl(CryStringT<char> const &)> >;
	
	std::vector<CommandHandler> m_commandHandlers;
	std::vector<CArkFlowGraphManager::ConsoleEvent> m_consoleEvents;
	std::vector<CArkFlowGraphManager::ConsoleEvent> m_remoteEvents;
	std::function<unsigned __int64 __cdecl(char const *)> m_remoteEventIdLookupFn;
	
	CArkFlowGraphManager();
	~CArkFlowGraphManager();
	void UnregisterConsoleEvent(unsigned _graphID, uint16_t _nodeID) { FUnregisterConsoleEvent(this,_graphID,_nodeID); }
	void RegisterRemoteEvent(unsigned _graphID, uint16_t _nodeID) { FRegisterRemoteEvent(this,_graphID,_nodeID); }
	void UnregisterRemoteEvent(unsigned _graphID, uint16_t _nodeID) { FUnregisterRemoteEvent(this,_graphID,_nodeID); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool unnamed) { FReset(this, unnamed); }
	static void OnConsoleEvent(IConsoleCmdArgs *_pCmdArgs) { FOnConsoleEvent(_pCmdArgs); }
	void ExecuteConsoleEvent(string const &_eventName) const { FExecuteConsoleEvent(this,_eventName); }
	void ExecuteRemoteEvent(string const &_eventName) const { FExecuteRemoteEvent(this,_eventName); }
	void ExecuteEvent(std::vector<CArkFlowGraphManager::ConsoleEvent> const &_events, uint16_t _typeId, std::function<void __cdecl(IFlowNode *)> _executeFn) const { FExecuteEvent(this,_events,_typeId,_executeFn); }
	
#if 0
	void RegisterConsoleEvent(unsigned arg0, uint16_t arg1);
	void SetRemoteEventIdLookupFn(std::function<unsigned __int64 __cdecl(char const *)> const &arg0);
	void ExecuteCommand(IConsoleCmdArgs *arg0) const;
#endif
	
	static inline auto FBitNotCArkFlowGraphManager = PreyFunction<void(CArkFlowGraphManager *const _this)>(0x14A6D90);
	static inline auto FUnregisterConsoleEvent = PreyFunction<void(CArkFlowGraphManager *const _this, unsigned _graphID, uint16_t _nodeID)>(0x14A7410);
	static inline auto FRegisterRemoteEvent = PreyFunction<void(CArkFlowGraphManager *const _this, unsigned _graphID, uint16_t _nodeID)>(0x14A73A0);
	static inline auto FUnregisterRemoteEvent = PreyFunction<void(CArkFlowGraphManager *const _this, unsigned _graphID, uint16_t _nodeID)>(0x14A74C0);
	static inline auto FOnLevelUnload = PreyFunction<void(CArkFlowGraphManager *const _this)>(0xA13080);
	static inline auto FReset = PreyFunction<void(CArkFlowGraphManager *const _this, bool )>(0x14A73F0);
	static inline auto FOnConsoleEvent = PreyFunction<void(IConsoleCmdArgs *_pCmdArgs)>(0x14A7230);
	static inline auto FExecuteConsoleEvent = PreyFunction<void(CArkFlowGraphManager const *const _this, string const &_eventName)>(0x14A6E10);
	static inline auto FExecuteRemoteEvent = PreyFunction<void(CArkFlowGraphManager const *const _this, string const &_eventName)>(0x14A70F0);
	static inline auto FExecuteEvent = PreyFunction<void(CArkFlowGraphManager const *const _this, std::vector<CArkFlowGraphManager::ConsoleEvent> const &_events, uint16_t _typeId, std::function<void __cdecl(IFlowNode *)> _executeFn)>(0x14A6FA0);
};

