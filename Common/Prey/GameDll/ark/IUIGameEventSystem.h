// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IUIPseudoRTTI.h>

struct SViewParams;

// IUIGameEventSystem
// Header:  Prey/GameDll/ark/IUIGameEventSystem.h
struct IUIGameEventSystem : public IUIPseudoRTTI
{ // Size=8 (0x8)
	virtual ~IUIGameEventSystem();
	virtual void InitEventSystem() = 0;
	virtual void UnloadEventSystem() = 0;
	virtual void UpdateView(const SViewParams& viewParams);
	virtual void OnUpdate(float fDelta);

	static inline auto FUpdateView = PreyFunction<void(IUIGameEventSystem* const _this, const SViewParams& viewParams)>(0x1333E90);
	static inline auto FOnUpdate = PreyFunction<void(IUIGameEventSystem* const _this, float fDelta)>(0x1333E90);
};
#endif // MOONCRASH
