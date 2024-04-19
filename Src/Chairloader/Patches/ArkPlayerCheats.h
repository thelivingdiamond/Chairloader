#pragma once

//! Restores cheat CVars and commands that are referenced in gameDebug.xml.
class ArkPlayerCheats
{
public:
    static void InitHooks();
    static void InitGame();

private:
    static void GrantSkill(IConsoleCmdArgs* pArgs);
    static void MaxSkills(IConsoleCmdArgs* pArgs);
};
