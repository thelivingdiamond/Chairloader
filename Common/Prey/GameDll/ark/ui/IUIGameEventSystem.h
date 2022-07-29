// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IUIPseudoRTTI.h>

struct SViewParams;

// Header: Override
// Prey/GameDll/ark/ui/IUIGameEventSystem.h
struct IUIGameEventSystem : public IUIPseudoRTTI // Id=8014CC9 Size=8
{
	virtual ~IUIGameEventSystem();
	virtual void InitEventSystem() = 0;
	virtual void UnloadEventSystem() = 0;
	virtual void UpdateView(SViewParams const &viewParams);
	virtual void OnUpdate(float fDelta);
	
	static inline auto FUpdateView = PreyFunction<void(IUIGameEventSystem *const _this, SViewParams const &viewParams)>(0xA13080);
	static inline auto FOnUpdate = PreyFunction<void(IUIGameEventSystem *const _this, float fDelta)>(0xA13080);
};

