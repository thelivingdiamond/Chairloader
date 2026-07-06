// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CArkGameObjectExtension.h>

struct IGameObject;
struct SGameObjectEvent;

// ArkWorldUI
// Header:  Prey/GameDll/ark/worldui/ArkWorldUI.h
class ArkWorldUI : public CArkGameObjectExtension<ArkWorldUI>
{ // Size=64 (0x40)
public:
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Release();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	void EnableCollisions() { FEnableCollisions(this); }

	static inline auto FInit = PreyFunction<bool(ArkWorldUI* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FRelease = PreyFunction<void(ArkWorldUI* const _this)>(0x3E3960);
	static inline auto FHandleEvent = PreyFunction<void(ArkWorldUI* const _this, const SGameObjectEvent& _event)>(0x14B83F0);
	static inline auto FEnableCollisions = PreyFunction<void(ArkWorldUI* const _this)>(0x14B82F0);
};
#endif // MOONCRASH
