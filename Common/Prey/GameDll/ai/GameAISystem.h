// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ai/AdvantagePointOccupancyControl.h>

class CAICorpseManager;
namespace GameAI
{
class DeathManager;
} // namespace GameAI
struct IGameAIModule;

// CGameAISystem
// Header:  Prey/GameDll/ai/GameAISystem.h
class CGameAISystem
{ // Size=64 (0x40)
public:
	enum class State
	{
		Idle = 0,
		UpdatingModules = 1,
	};

	using Modules = std::vector<IGameAIModule*>;

	std::vector<IGameAIModule*> m_modules;
	CAdvantagePointOccupancyControl m_advantagePointOccupancyControl;
	GameAI::DeathManager* m_pDeathManager;
	CGameAISystem::State m_state;
	CAICorpseManager* m_pCorpsesManager;

	CGameAISystem();
	~CGameAISystem();
	IGameAIModule* FindModule(const char* moduleName) const { return FFindModule(this, moduleName); }
	void EnterModule(unsigned entityID, const char* moduleName) { FEnterModule(this, entityID, moduleName); }
	void LeaveModule(unsigned entityID, const char* moduleName) { FLeaveModule(this, entityID, moduleName); }
	void LeaveAllModules(unsigned entityID) { FLeaveAllModules(this, entityID); }
	void PauseModule(unsigned entityID, const char* moduleName) { FPauseModule(this, entityID, moduleName); }
	void PauseAllModules(unsigned entityID) { FPauseAllModules(this, entityID); }
	void ResumeModule(unsigned entityID, const char* moduleName) { FResumeModule(this, entityID, moduleName); }
	void ResumeAllModules(unsigned entityID) { FResumeAllModules(this, entityID); }
	void Update(float frameTime) { FUpdate(this, frameTime); }
	void Reset(bool bUnload) { FReset(this, bUnload); }
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	void PostSerialize() { FPostSerialize(this); }

#if 0
	CAdvantagePointOccupancyControl& GetAdvantagePointOccupancyControl();
	GameAI::DeathManager* GetDeathManager();
	void UpdateModules(float _arg0_);
	void UpdateSubSystems(float _arg0_);
	void ResetModules(bool _arg0_);
	void ResetSubSystems(bool _arg0_);
	void Error(const char* _arg0_) const;
	void InformContentCreatorOfError(string _arg0_) const;
	void GetCallStack(string& _arg0_) const;
#endif

	static inline auto FCGameAISystemOv1 = PreyFunction<void(CGameAISystem* const _this)>(0x10C5370);
	static inline auto FBitNotCGameAISystem = PreyFunction<void(CGameAISystem* const _this)>(0x10C55A0);
	static inline auto FFindModule = PreyFunction<IGameAIModule* (const CGameAISystem* const _this, const char* moduleName)>(0x10C6820);
	static inline auto FEnterModule = PreyFunction<void(CGameAISystem* const _this, unsigned entityID, const char* moduleName)>(0x10C5F20);
	static inline auto FLeaveModule = PreyFunction<void(CGameAISystem* const _this, unsigned entityID, const char* moduleName)>(0x10C6EB0);
	static inline auto FLeaveAllModules = PreyFunction<void(CGameAISystem* const _this, unsigned entityID)>(0x10C6E40);
	static inline auto FPauseModule = PreyFunction<void(CGameAISystem* const _this, unsigned entityID, const char* moduleName)>(0x10C6F80);
	static inline auto FPauseAllModules = PreyFunction<void(CGameAISystem* const _this, unsigned entityID)>(0x10C6F10);
	static inline auto FResumeModule = PreyFunction<void(CGameAISystem* const _this, unsigned entityID, const char* moduleName)>(0x10C75E0);
	static inline auto FResumeAllModules = PreyFunction<void(CGameAISystem* const _this, unsigned entityID)>(0x10C7570);
	static inline auto FUpdate = PreyFunction<void(CGameAISystem* const _this, float frameTime)>(0x10C77E0);
	static inline auto FReset = PreyFunction<void(CGameAISystem* const _this, bool bUnload)>(0x10C7450);
	static inline auto FSerialize = PreyFunction<void(CGameAISystem* const _this, TSerialize ser)>(0x10C7640);
	static inline auto FPostSerialize = PreyFunction<void(CGameAISystem* const _this)>(0x10C6FE0);
};
#endif // MOONCRASH
