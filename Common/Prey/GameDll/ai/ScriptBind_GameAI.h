// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class ICrySizer;
struct IFunctionHandler;
struct IGameFramework;
struct IScriptSystem;
struct ISystem;
struct SEntityProximityQuery;
union ScriptHandle;

// CScriptBind_GameAI
// Header:  Prey/GameDll/ai/ScriptBind_GameAI.h
class CScriptBind_GameAI : public CScriptableBase
{ // Size=120 (0x78)
public:
	ISystem* m_system;
	IGameFramework* m_gameFramework;
	IScriptSystem* m_scriptSystem;

	CScriptBind_GameAI(ISystem* system, IGameFramework* gameFramework);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	void RegisterMethods() { FRegisterMethods(this); }
	void RegisterGlobals() { FRegisterGlobals(this); }
	int RegisterWithModule(IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID) { return FRegisterWithModule(this, pH, moduleName, entityID); }
	int UnregisterWithModule(IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID) { return FUnregisterWithModule(this, pH, moduleName, entityID); }
	int UnregisterWithAllModules(IFunctionHandler* pH, ScriptHandle entityID) { return FUnregisterWithAllModules(this, pH, entityID); }
	int PauseModule(IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID) { return FPauseModule(this, pH, moduleName, entityID); }
	int PauseAllModules(IFunctionHandler* pH, ScriptHandle entityID) { return FPauseAllModules(this, pH, entityID); }
	int ResumeModule(IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID) { return FResumeModule(this, pH, moduleName, entityID); }
	int ResumeAllModules(IFunctionHandler* pH, ScriptHandle entityID) { return FResumeAllModules(this, pH, entityID); }
	int GetClosestEntityToTarget(IFunctionHandler* funcHandler, Vec3 attackerPos, Vec3 targetPos, const char* pClassName, float radius, float maxAngle) { return FGetClosestEntityToTarget(this, funcHandler, attackerPos, targetPos, pClassName, radius, maxAngle); }
	int GetBattleFrontPosition(IFunctionHandler* pH, int groupID) { return FGetBattleFrontPosition(this, pH, groupID); }
	int ResetAdvantagePointOccupancyControl(IFunctionHandler* pH) { return FResetAdvantagePointOccupancyControl(this, pH); }
	int OccupyAdvantagePoint(IFunctionHandler* pH, ScriptHandle entityID, Vec3 point) { return FOccupyAdvantagePoint(this, pH, entityID, point); }
	int ReleaseAdvantagePointFor(IFunctionHandler* pH, ScriptHandle entityID) { return FReleaseAdvantagePointFor(this, pH, entityID); }
	int IsAdvantagePointOccupied(IFunctionHandler* pH, Vec3 point) { return FIsAdvantagePointOccupied(this, pH, point); }
	int StartSearchModuleFor(IFunctionHandler* pH, int groupID, Vec3 targetPos) { return FStartSearchModuleFor(this, pH, groupID, targetPos); }
	int StopSearchModuleFor(IFunctionHandler* pH, int groupID) { return FStopSearchModuleFor(this, pH, groupID); }
	int GetNextSearchSpot(IFunctionHandler* pH, ScriptHandle entityID, float closenessToAgentWeight, float closenessToTargetWeight, float minDistanceFromAgent) { return FGetNextSearchSpot(this, pH, entityID, closenessToAgentWeight, closenessToTargetWeight, minDistanceFromAgent); }
	int MarkAssignedSearchSpotAsUnreachable(IFunctionHandler* pH, ScriptHandle entityID) { return FMarkAssignedSearchSpotAsUnreachable(this, pH, entityID); }
	int ResetRanges(IFunctionHandler* pH, ScriptHandle entityID) { return FResetRanges(this, pH, entityID); }
	int AddRange(IFunctionHandler* pH, ScriptHandle entityID, float range, const char* enterSignal, const char* leaveSignal) { return FAddRange(this, pH, entityID, range, enterSignal, leaveSignal); }
	int GetRangeState(IFunctionHandler* pH, ScriptHandle entityID, int rangeID) { return FGetRangeState(this, pH, entityID, rangeID); }
	int ChangeRange(IFunctionHandler* pH, ScriptHandle entityID, int rangeID, float distance) { return FChangeRange(this, pH, entityID, rangeID, distance); }
	int ResetAloneDetector(IFunctionHandler* pH, ScriptHandle entityID) { return FResetAloneDetector(this, pH, entityID); }
	int SetupAloneDetector(IFunctionHandler* pH, ScriptHandle entityID, float range, const char* aloneSignal, const char* notAloneSignal) { return FSetupAloneDetector(this, pH, entityID, range, aloneSignal, notAloneSignal); }
	int AddActorClassToAloneDetector(IFunctionHandler* pH, ScriptHandle entityID, const char* entityClassName) { return FAddActorClassToAloneDetector(this, pH, entityID, entityClassName); }
	int RemoveActorClassFromAloneDetector(IFunctionHandler* pH, ScriptHandle entityID, const char* entityClassName) { return FRemoveActorClassFromAloneDetector(this, pH, entityID, entityClassName); }
	int IsAloneForAloneDetector(IFunctionHandler* pH, ScriptHandle entityID) { return FIsAloneForAloneDetector(this, pH, entityID); }
	int RegisterObjectVisible(IFunctionHandler* pH, ScriptHandle entityID) { return FRegisterObjectVisible(this, pH, entityID); }
	int UnregisterObjectVisible(IFunctionHandler* pH, ScriptHandle entityID) { return FUnregisterObjectVisible(this, pH, entityID); }
	int IsAISystemEnabled(IFunctionHandler* pH) { return FIsAISystemEnabled(this, pH); }

#if 0
	bool GetEntitiesInRange(const Vec3& _arg0_, float _arg1_, const char* _arg2_, SEntityProximityQuery* _arg3_) const;
#endif

	static inline auto FCScriptBind_GameAIOv2 = PreyFunction<void(CScriptBind_GameAI* const _this, ISystem* system, IGameFramework* gameFramework)>(0x10CC8F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_GameAI* const _this, ICrySizer* pSizer)>(0x159E480);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_GameAI* const _this)>(0x10CDEC0);
	static inline auto FRegisterGlobals = PreyFunction<void(CScriptBind_GameAI* const _this)>(0x10CDA70);
	static inline auto FRegisterWithModule = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID)>(0x10CEA80);
	static inline auto FUnregisterWithModule = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID)>(0x10CEC10);
	static inline auto FUnregisterWithAllModules = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x10CEBE0);
	static inline auto FPauseModule = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID)>(0x10CDA40);
	static inline auto FPauseAllModules = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x10CDA10);
	static inline auto FResumeModule = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, const char* moduleName, ScriptHandle entityID)>(0x10CEBB0);
	static inline auto FResumeAllModules = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x10CEB80);
	static inline auto FGetClosestEntityToTarget = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* funcHandler, Vec3 attackerPos, Vec3 targetPos, const char* pClassName, float radius, float maxAngle)>(0x10CD300);
	static inline auto FGetBattleFrontPosition = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, int groupID)>(0x77DB10);
	static inline auto FResetAdvantagePointOccupancyControl = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH)>(0x10CEAF0);
	static inline auto FOccupyAdvantagePoint = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, Vec3 point)>(0x10CD9D0);
	static inline auto FReleaseAdvantagePointFor = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x10CEAB0);
	static inline auto FIsAdvantagePointOccupied = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, Vec3 point)>(0x10CD990);
	static inline auto FStartSearchModuleFor = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, int groupID, Vec3 targetPos)>(0x77DB10);
	static inline auto FStopSearchModuleFor = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, int groupID)>(0x77DB10);
	static inline auto FGetNextSearchSpot = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, float closenessToAgentWeight, float closenessToTargetWeight, float minDistanceFromAgent)>(0x77DB10);
	static inline auto FMarkAssignedSearchSpotAsUnreachable = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x77DB10);
	static inline auto FResetRanges = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x10CEB20);
	static inline auto FAddRange = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, float range, const char* enterSignal, const char* leaveSignal)>(0x10CCAA0);
	static inline auto FGetRangeState = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, int rangeID)>(0x10CD740);
	static inline auto FChangeRange = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, int rangeID, float distance)>(0x10CCC50);
	static inline auto FResetAloneDetector = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x77DB10);
	static inline auto FSetupAloneDetector = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, float range, const char* aloneSignal, const char* notAloneSignal)>(0x77DB10);
	static inline auto FAddActorClassToAloneDetector = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, const char* entityClassName)>(0x77DB10);
	static inline auto FRemoveActorClassFromAloneDetector = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID, const char* entityClassName)>(0x77DB10);
	static inline auto FIsAloneForAloneDetector = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x77DB10);
	static inline auto FRegisterObjectVisible = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x78FD70);
	static inline auto FUnregisterObjectVisible = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH, ScriptHandle entityID)>(0x78FD70);
	static inline auto FIsAISystemEnabled = PreyFunction<int(CScriptBind_GameAI* const _this, IFunctionHandler* pH)>(0x10CD900);
};
#endif // MOONCRASH
