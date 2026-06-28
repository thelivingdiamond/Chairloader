// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IActor;
struct ICVar;
struct IConsole;
struct IConsoleCmdArgs;
struct IEntity;

// CBodyManagerCVars
// Header:  Prey/GameDll/BodyManagerCVars.h
class CBodyManagerCVars
{ // Size=1 (0x1)
public:
	static inline auto g_bodyDamage_log = PreyGlobal<int>(0x2D821A8);
	static inline auto g_bodyDestruction_debug = PreyGlobal<int>(0x2D821AC);
	static inline auto g_bodyDestruction_debugFilter = PreyGlobal<ICVar*>(0x2D821B0);

	static void RegisterCommands() { FRegisterCommands(); }
	static void RegisterVariables() { FRegisterVariables(); }
	static void UnregisterCommands(IConsole* pConsole) { FUnregisterCommands(pConsole); }
	static void UnregisterVariables(IConsole* pConsole) { FUnregisterVariables(pConsole); }
	static void ReloadBodyDamage(IConsoleCmdArgs* pArgs) { FReloadBodyDamage(pArgs); }
	static void ReloadBodyDestruction(IConsoleCmdArgs* pArgs) { FReloadBodyDestruction(pArgs); }

#if 0
	static int IsBodyDamageLogEnabled();
	static int IsBodyDestructionDebugEnabled();
	static bool IsBodyDestructionDebugFilterFor(const char* _arg0_);
	static bool IsBodyDestructionDebugFilterEnabled();
	static void Reload(IActor* _arg0_);
	static void Reload(IEntity* _arg0_);
#endif

	static inline auto FRegisterCommands = PreyFunction<void()>(0x17BB830);
	static inline auto FRegisterVariables = PreyFunction<void()>(0x17BB8B0);
	static inline auto FUnregisterCommands = PreyFunction<void(IConsole* pConsole)>(0x17BBBC0);
	static inline auto FUnregisterVariables = PreyFunction<void(IConsole* pConsole)>(0x17BBC00);
	static inline auto FReloadBodyDamage = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x17BB980);
	static inline auto FReloadBodyDestruction = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x17BBB30);
};
#endif // MOONCRASH
