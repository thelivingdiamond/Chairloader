// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/AISystemListener.h>
#include <_unknown/GameAI__DeadBody.h>
#include <_unknown/GameAI__DeferredDeathReaction.h>

class Agent;
struct IScriptTable;
struct RayCastResult;

namespace GameAI
{

// GameAI::DeathManager
// Header:  Prey/GameDll/ai/DeathManager.h
class DeathManager : public IAISystemListener
{ // Size=64 (0x40)
public:
	using DeferredDeathReactions = std::vector<GameAI::DeferredDeathReaction>;
	using DeadBodies = std::vector<GameAI::DeadBody>;

	std::vector<GameAI::DeferredDeathReaction> m_deferredDeathReactions;
	std::vector<GameAI::DeadBody> m_unseenDeadBodies;
	AsyncState m_asyncState;
	unsigned m_rayID;

	DeathManager();
	virtual ~DeathManager();
	void Update() { FUpdate(this); }
	void DispatchDeferredDeathReaction(const GameAI::DeferredDeathReaction& ddr) { FDispatchDeferredDeathReaction(this, ddr); }
	void CheckDeadBodyVisibilityFor(Agent& agent) { FCheckDeadBodyVisibilityFor(this, agent); }
	void QueueNextPotentialWitnessRay(GameAI::DeferredDeathReaction& ddr) { FQueueNextPotentialWitnessRay(this, ddr); }
	void PotentialWitnessRayComplete(const unsigned& rayID, const RayCastResult& result) { FPotentialWitnessRayComplete(this, rayID, result); }
	void InjectDeadGroupMemberDataIntoScriptTable(IScriptTable* scriptTable, const unsigned victimID, const unsigned killerID, const Vec3& victimPosition) { FInjectDeadGroupMemberDataIntoScriptTable(this, scriptTable, victimID, killerID, victimPosition); }
	virtual void OnAgentDeath(unsigned deadEntityID, unsigned killerID);
	virtual void OnAgentUpdate(unsigned entityID);

#if 0
	void OnAgentGrabbedByPlayer(const unsigned _arg0_);
	void ProcessDeferredDeathReactions();
	void AddDeferredDeathReactionFor(const Agent& _arg0_, const unsigned _arg1_);
	void AddDeadBodyFor(const Agent& _arg0_, unsigned _arg1_);
	void ClearDeadBodiesForGroup(int _arg0_);
	void ClearDeferredDeathReactionsForGroup(int _arg0_);
	void InitDeadBody(GameAI::DeadBody& _arg0_, const Agent& _arg1_, unsigned _arg2_);
	void DestroyDeadBody(GameAI::DeadBody& _arg0_);
#endif

	static inline auto FDeathManagerOv1 = PreyFunction<void(GameAI::DeathManager* const _this)>(0x10C3DD0);
	static inline auto FUpdate = PreyFunction<void(GameAI::DeathManager* const _this)>(0x10C4AF0);
	static inline auto FDispatchDeferredDeathReaction = PreyFunction<void(GameAI::DeathManager* const _this, const GameAI::DeferredDeathReaction& ddr)>(0x10C4100);
	static inline auto FCheckDeadBodyVisibilityFor = PreyFunction<void(GameAI::DeathManager* const _this, Agent& agent)>(0x10C3FE0);
	static inline auto FQueueNextPotentialWitnessRay = PreyFunction<void(GameAI::DeathManager* const _this, GameAI::DeferredDeathReaction& ddr)>(0x10C4820);
	static inline auto FPotentialWitnessRayComplete = PreyFunction<void(GameAI::DeathManager* const _this, const unsigned& rayID, const RayCastResult& result)>(0x10C47A0);
	static inline auto FInjectDeadGroupMemberDataIntoScriptTable = PreyFunction<void(GameAI::DeathManager* const _this, IScriptTable* scriptTable, const unsigned victimID, const unsigned killerID, const Vec3& victimPosition)>(0x10C4390);
	static inline auto FOnAgentDeath = PreyFunction<void(GameAI::DeathManager* const _this, unsigned deadEntityID, unsigned killerID)>(0x10C4600);
	static inline auto FOnAgentUpdate = PreyFunction<void(GameAI::DeathManager* const _this, unsigned entityID)>(0x10C4730);
};


} // namespace GameAI
#endif // MOONCRASH
