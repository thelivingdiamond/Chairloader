#pragma once

//! Patches CArkFlowGraphManager to restore "ce" command used by cheats in gameDebug.xml.
class ConsoleEventPatch
{
public:
    static void InitHooks();
};
