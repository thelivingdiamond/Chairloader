// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkElectricalBox.h>

struct IGameObject;
struct SEntityUpdateContext;

// ArkTechnopathEMPHazard
// Header:  Prey/GameDll/ark/weapons/ArkTechnopathEMPHazard.h
class ArkTechnopathEMPHazard : public ArkElectricalBox
{ // Size=1080 (0x438)
public:
	bool m_bSetImpendingPlayerDamage;
	ArkSimpleTimer m_lifeTimer;

	ArkTechnopathEMPHazard();
	virtual bool Init(IGameObject* pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void FullSerialize(TSerialize ser);
	virtual bool AddTarget(unsigned _entityId);
	void SetOwnerId(unsigned _ownerId) { FSetOwnerId(this, _ownerId); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);

	static inline auto FArkTechnopathEMPHazardOv2 = PreyFunction<void(ArkTechnopathEMPHazard* const _this)>(0x148C910);
	static inline auto FInit = PreyFunction<bool(ArkTechnopathEMPHazard* const _this, IGameObject* pGameObject)>(0x148CBB0);
	static inline auto FPostInit = PreyFunction<void(ArkTechnopathEMPHazard* const _this, IGameObject* _pGameObject)>(0x148CC10);
	static inline auto FUpdate = PreyFunction<void(ArkTechnopathEMPHazard* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x148CDF0);
	static inline auto FFullSerialize = PreyFunction<void(ArkTechnopathEMPHazard* const _this, TSerialize ser)>(0x148CAF0);
	static inline auto FAddTarget = PreyFunction<bool(ArkTechnopathEMPHazard* const _this, unsigned _entityId)>(0x148C9C0);
	static inline auto FSetOwnerId = PreyFunction<void(ArkTechnopathEMPHazard* const _this, unsigned _ownerId)>(0x148CDE0);
	static inline auto FOnBrokenChanged = PreyFunction<void(IArkRepairableListener* const _this, bool _bBroken, bool _bWasForced)>(0x148CBC0);
};
#endif // MOONCRASH
