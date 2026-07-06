// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CArkGameObjectExtension.h>

struct IGameObject;

// CArkRetreatPoint
// Header:  Prey/GameDll/ark/npc/ArkRetreatPoint.h
class CArkRetreatPoint : public CArkGameObjectExtension<CArkRetreatPoint>
{ // Size=64 (0x40)
public:
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Release();

	static inline auto FInit = PreyFunction<bool(CArkRetreatPoint* const _this, IGameObject* _pGameObject)>(0x129D880);
	static inline auto FRelease = PreyFunction<void(CArkRetreatPoint* const _this)>(0x129D8C0);
};
#endif // MOONCRASH
