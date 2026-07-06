// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CArkGameObjectExtension.h>

struct IGameObject;

// CArkLurkPoint
// Header:  Prey/GameDll/ark/npc/ArkLurkPoint.h
class CArkLurkPoint : public CArkGameObjectExtension<CArkLurkPoint>
{ // Size=72 (0x48)
public:
	static inline auto s_visibilityCheckBoxWidth = PreyGlobal<float>(0x23E27F8);
	static inline auto s_visibilityCheckBoxHeight = PreyGlobal<float>(0x23E27FC);
	static inline auto s_visibilityCheckHeightAddition = PreyGlobal<float>(0x23E2800);
	static inline auto s_visibilityFrameThreshold = PreyGlobal<unsigned>(0x23E2804);
	unsigned m_visCheckHandle;

	CArkLurkPoint();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Release();
	bool IsVisible() const { return FIsVisible(this); }

	static inline auto FCArkLurkPointOv2 = PreyFunction<void(CArkLurkPoint* const _this)>(0x12811C0);
	static inline auto FInit = PreyFunction<bool(CArkLurkPoint* const _this, IGameObject* _pGameObject)>(0x1281200);
	static inline auto FRelease = PreyFunction<void(CArkLurkPoint* const _this)>(0x1281320);
	static inline auto FIsVisible = PreyFunction<bool(const CArkLurkPoint* const _this)>(0x1281300);
};
#endif // MOONCRASH
