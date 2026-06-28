// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryInput/IInput.h>
#include <_unknown/PodArray.h>
#include <_unknown/SGameRulesListener.h>

struct ICVar;
struct IGameEffect;
struct IGameRenderNode;
struct IItemParamsNode;
struct SInputEvent;

// CGameEffectsSystem
// Header:  Prey/GameDll/effects/GameEffectsSystem.h
class CGameEffectsSystem : public IInputEventListener, public SGameRulesListener
{ // Size=48 (0x30)
public:
	// CGameEffectsSystem::SRegisterDataCallbacks
	// Header:  Prey/GameDll/effects/GameEffectsSystem.h
	struct SRegisterDataCallbacks
	{ // Size=1 (0x1)
	#if 0
		SRegisterDataCallbacks(void (*_arg0_)(IItemParamsNode*), void (*_arg1_)(), void (*_arg2_)(IItemParamsNode*));
	#endif
	};

	// CGameEffectsSystem::SRegisterGameCallbacks
	// Header:  Prey/GameDll/effects/GameEffectsSystem.h
	struct SRegisterGameCallbacks
	{ // Size=1 (0x1)
	#if 0
		SRegisterGameCallbacks(void (*_arg0_)());
	#endif
	};

	static inline auto s_singletonInstance = PreyGlobal<CGameEffectsSystem*>(0x2D82338);
	static inline auto s_postEffectCVarNameOffset = PreyGlobal<int>(0x2D82340);
	IGameEffect* m_effectsToUpdate;
	IGameEffect* m_effectsNotToUpdate;
	IGameEffect* m_nextEffectToUpdate;
	bool m_isInitialised;
	static inline auto s_hasLoadedData = PreyGlobal<bool>(0x2D82344);

	static void Destroy() { FDestroy(); }
	void Initialise() { FInitialise(this); }
	void LoadData() { FLoadData(this); }
	void ReleaseData() { FReleaseData(this); }
	void RegisterEffect(IGameEffect* effect) { FRegisterEffect(this, effect); }
	void UnRegisterEffect(IGameEffect* effect) { FUnRegisterEffect(this, effect); }
	void Update(float frameTime) { FUpdate(this, frameTime); }
	virtual bool OnInputEvent(const SInputEvent& inputEvent);
	void GameRulesInitialise() { FGameRulesInitialise(this); }
	virtual void EnteredGame();
	void ReloadData() { FReloadData(this); }
	CGameEffectsSystem();
	virtual ~CGameEffectsSystem();
	void AutoReleaseAndDeleteFlaggedEffects(IGameEffect* effectList) { FAutoReleaseAndDeleteFlaggedEffects(this, effectList); }
	static void RegisterDataLoadCallback(void (*dataLoadCallback)(IItemParamsNode*)) { FRegisterDataLoadCallback(dataLoadCallback); }
	static void RegisterDataReleaseCallback(void (*dataReleaseCallback)()) { FRegisterDataReleaseCallback(dataReleaseCallback); }
	static void RegisterDataReloadCallback(void (*dataReloadCallback)(IItemParamsNode*)) { FRegisterDataReloadCallback(dataReloadCallback); }

#if 0
	static CGameEffectsSystem& Instance();
	static bool Exists();
	void RegisterGameRenderNode(_smart_ptr<IGameRenderNode>& _arg0_);
	void UnregisterGameRenderNode(_smart_ptr<IGameRenderNode>& _arg0_);
	void RegisterGameRenderElement(_smart_ptr<IGameRenderElement>& _arg0_);
	void UnregisterGameRenderElement(_smart_ptr<IGameRenderElement>& _arg0_);
	void Reset();
	void AutoDeleteEffects(IGameEffect* _arg0_);
	void SetPostEffectCVarCallbacks();
	static void PostEffectCVarCallback(ICVar* _arg0_);
	static void RegisterEnteredGameCallback(void (*_arg0_)());
#endif

	static inline auto FDestroy = PreyFunction<void()>(0x17DA590);
	static inline auto FInitialise = PreyFunction<void(CGameEffectsSystem* const _this)>(0x17DA8E0);
	static inline auto FLoadData = PreyFunction<void(CGameEffectsSystem* const _this)>(0x17DA900);
	static inline auto FReleaseData = PreyFunction<void(CGameEffectsSystem* const _this)>(0x17DAD00);
	static inline auto FRegisterEffect = PreyFunction<void(CGameEffectsSystem* const _this, IGameEffect* effect)>(0x17DAB60);
	static inline auto FUnRegisterEffect = PreyFunction<void(CGameEffectsSystem* const _this, IGameEffect* effect)>(0x17DAF50);
	static inline auto FUpdate = PreyFunction<void(CGameEffectsSystem* const _this, float frameTime)>(0x17DB050);
	static inline auto FOnInputEvent = PreyFunction<bool(CGameEffectsSystem* const _this, const SInputEvent& inputEvent)>(0x13B0900);
	static inline auto FGameRulesInitialise = PreyFunction<void(CGameEffectsSystem* const _this)>(0x17DA6A0);
	static inline auto FEnteredGame = PreyFunction<void(SGameRulesListener* const _this)>(0x17DA5E0);
	static inline auto FReloadData = PreyFunction<void(CGameEffectsSystem* const _this)>(0x17DADE0);
	static inline auto FCGameEffectsSystemOv1 = PreyFunction<void(CGameEffectsSystem* const _this)>(0x17DA3F0);
	static inline auto FAutoReleaseAndDeleteFlaggedEffects = PreyFunction<void(CGameEffectsSystem* const _this, IGameEffect* effectList)>(0x17DA4F0);
	static inline auto FRegisterDataLoadCallback = PreyFunction<void(void (*dataLoadCallback)(IItemParamsNode*))>(0x17DAA10);
	static inline auto FRegisterDataReleaseCallback = PreyFunction<void(void (*dataReleaseCallback)())>(0x17DAA80);
	static inline auto FRegisterDataReloadCallback = PreyFunction<void(void (*dataReloadCallback)(IItemParamsNode*))>(0x17DAAF0);
};

// SGameEffectSystemStaticData
// Header:  Prey/GameDll/effects/GameEffectsSystem.h
struct SGameEffectSystemStaticData
{ // Size=1 (0x1)
	static PodArray<void (__cdecl*)(IItemParamsNode *),0>& GetDataLoadCallbackList() { return FGetDataLoadCallbackList(); }
	static PodArray<void (__cdecl*)(void),0>& GetDataReleaseCallbackList() { return FGetDataReleaseCallbackList(); }
	static PodArray<void (__cdecl*)(IItemParamsNode *),0>& GetDataReloadCallbackList() { return FGetDataReloadCallbackList(); }
	static PodArray<void (__cdecl*)(void),0>& GetEnteredGameCallbackList() { return FGetEnteredGameCallbackList(); }

	static inline auto FGetDataLoadCallbackList = PreyFunction<PodArray<void (__cdecl*)(IItemParamsNode *),0>& ()>(0x17DA6E0);
	static inline auto FGetDataReleaseCallbackList = PreyFunction<PodArray<void (__cdecl*)(void),0>& ()>(0x17DA760);
	static inline auto FGetDataReloadCallbackList = PreyFunction<PodArray<void (__cdecl*)(IItemParamsNode *),0>& ()>(0x17DA7E0);
	static inline auto FGetEnteredGameCallbackList = PreyFunction<PodArray<void (__cdecl*)(void),0>& ()>(0x17DA860);
};
#endif // MOONCRASH
