#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/ark/flowgraph/ArkFlowGraphManager.h>
#include <Prey/GameDll/ark/flowgraph/ArkFlowConsoleEvent.h>
#include <mem.h>
#include "ConsoleEventPatch.h"

static auto g_CArkFlowConsoleEvent_vftable = PreyGlobal<uintptr_t[11]>(0x1E38B28);

void CArkFlowGraphManager_RegisterConsoleEvent(CArkFlowGraphManager* _this, unsigned _graphID, uint16_t _nodeID)
{
    auto it = std::find_if(_this->m_consoleEvents.begin(), _this->m_consoleEvents.end(),
        [&](const CArkFlowGraphManager::ConsoleEvent& x)
        {
            return x.m_graphID == _graphID && x.m_nodeID == _nodeID;
        });

    if (it == _this->m_consoleEvents.end())
    {
        _this->m_consoleEvents.push_back({ _graphID, _nodeID });
    }
}

void CArkFlowConsoleEvent_ProcessEvent_Hook(CArkFlowConsoleEvent* _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)
{
    switch (event)
    {
    case IFlowNode::eFE_Update:
    {
        // Disable updates (enabled by CArkFlowGraphManager::ExecuteConsoleEvent)
        pActInfo->pGraph->SetRegularlyUpdated(pActInfo->myID, false);

        // Get this node's command
        TFlowInputData data = GetPortAny(pActInfo, CArkFlowConsoleEvent::IN_COMMAND);
        string command;
        data.GetValueWithConversion(command);

        // m_attemptedCommand is set by SetExecutionString, which is called from CArkFlowGraphManager::ExecuteConsoleEvent
        if (command == _this->m_attemptedCommand)
        {
            // Activate the command
            ActivateOutput(pActInfo, CArkFlowConsoleEvent::OUT_TRIGGERED, true);
        }

        break;
    }
    case IFlowNode::eFE_Activate:
    case IFlowNode::eFE_Initialize:
    {
        if (g_pGame && pActInfo->pGraph)
        {
            _this->m_graphId = pActInfo->pGraph->GetGraphId();
            _this->m_id = pActInfo->myID;
            CArkFlowGraphManager_RegisterConsoleEvent(g_pGame->m_pArkFlowGraphManager.get(), _this->m_graphId, _this->m_id);
        }

        break;
    }
    }
}

void ConsoleEventPatch::InitHooks()
{
    // Hook ProcessEvent in vtable (index = 8)
    uint8_t* pVTableEntry = (uint8_t*)((*g_CArkFlowConsoleEvent_vftable) + 8);
    void* pFunc = &CArkFlowConsoleEvent_ProcessEvent_Hook;
    uint8_t ppFunc[sizeof(pFunc)];
    memcpy(ppFunc, &pFunc, sizeof(pFunc));

    mem::Patch(pVTableEntry, ppFunc, sizeof(ppFunc));
}
