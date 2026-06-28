// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CPlayer;
class ICrySizer;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;

// CScriptBind_HitDeathReactions
// Header:  Prey/GameDll/ScriptBind_HitDeathReactions.h
class CScriptBind_HitDeathReactions : public CScriptableBase
{ // Size=120 (0x78)
public:
	SmartScriptTable m_pParams;
	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;

	CScriptBind_HitDeathReactions(ISystem* pSystem, IGameFramework* pGameFramework);
	virtual ~CScriptBind_HitDeathReactions();
	int OnHit(IFunctionHandler* pH, SmartScriptTable scriptHitInfo) { return FOnHit(this, pH, scriptHitInfo); }
	int ExecuteHitReaction(IFunctionHandler* pH, SmartScriptTable reactionParams) { return FExecuteHitReaction(this, pH, reactionParams); }
	int ExecuteDeathReaction(IFunctionHandler* pH, SmartScriptTable reactionParams) { return FExecuteDeathReaction(this, pH, reactionParams); }
	int EndCurrentReaction(IFunctionHandler* pH) { return FEndCurrentReaction(this, pH); }
	int IsValidReaction(IFunctionHandler* pH, SmartScriptTable validationParams, SmartScriptTable scriptHitInfo) { return FIsValidReaction(this, pH, validationParams, scriptHitInfo); }
	int StartReactionAnim(IFunctionHandler* pH) { return FStartReactionAnim(this, pH); }
	int EndReactionAnim(IFunctionHandler* pH) { return FEndReactionAnim(this, pH); }
	int StartInteractiveAction(IFunctionHandler* pH, const char* szActionName) { return FStartInteractiveAction(this, pH, szActionName); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	CPlayer* GetAssociatedActor(IFunctionHandler* pH) const { return FGetAssociatedActor(this, pH); }
	std::shared_ptr<CHitDeathReactions> GetHitDeathReactions(IFunctionHandler* pH) const { alignas(std::shared_ptr<CHitDeathReactions>) std::byte _return_buf_[sizeof(std::shared_ptr<CHitDeathReactions>)]; return *FGetHitDeathReactions(this, reinterpret_cast<std::shared_ptr<CHitDeathReactions>*>(_return_buf_), pH); }

	static inline auto FCScriptBind_HitDeathReactionsOv1 = PreyFunction<void(CScriptBind_HitDeathReactions* const _this, ISystem* pSystem, IGameFramework* pGameFramework)>(0x19138A0);
	static inline auto FOnHit = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH, SmartScriptTable scriptHitInfo)>(0x1914530);
	static inline auto FExecuteHitReaction = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH, SmartScriptTable reactionParams)>(0x1914080);
	static inline auto FExecuteDeathReaction = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH, SmartScriptTable reactionParams)>(0x1913FC0);
	static inline auto FEndCurrentReaction = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH)>(0x1913E30);
	static inline auto FIsValidReaction = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH, SmartScriptTable validationParams, SmartScriptTable scriptHitInfo)>(0x19143A0);
	static inline auto FStartReactionAnim = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH)>(0x19146E0);
	static inline auto FEndReactionAnim = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH)>(0x1913F20);
	static inline auto FStartInteractiveAction = PreyFunction<int(CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH, const char* szActionName)>(0x1914690);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_HitDeathReactions* const _this, ICrySizer* pSizer)>(0x159E480);
	static inline auto FGetAssociatedActor = PreyFunction<CPlayer* (const CScriptBind_HitDeathReactions* const _this, IFunctionHandler* pH)>(0x1914140);
	static inline auto FGetHitDeathReactions = PreyFunction<std::shared_ptr<CHitDeathReactions>*(const CScriptBind_HitDeathReactions* const _this, std::shared_ptr<CHitDeathReactions>* _return_value_, IFunctionHandler* pH)>(0x1914280);
};
#endif // MOONCRASH
