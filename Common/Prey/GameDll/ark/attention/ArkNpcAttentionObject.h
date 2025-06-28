// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/attention/ArkComplexAttentionObject.h>
#include <Prey/GameDll/ark/perception/ArkAuralPerceivable.h>
#include <Prey/GameDll/ark/perception/ArkSimpleVisualPerceivable.h>

class ArkNpc;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkNpcAttentionObject.h
class ArkNpcAttentionObject : public ArkSimpleAttentionObject, public ArkSimpleVisualPerceivable, public ArkAuralPerceivable // Id=8014317 Size=32
{
public:
	ArkNpc *m_pNpc;
	
	ArkNpcAttentionObject(ArkNpc &_npc);
	void EnableAttentionObject() { FEnableAttentionObject(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	bool IsAttentionObjectEnabled() const { return FIsAttentionObjectEnabled(this); }
	void EnableVisualPerceivable() { FEnableVisualPerceivable(this); }
	void DisableVisualPerceivable() { FDisableVisualPerceivable(this); }
	bool IsVisualPerceivableEnabled() const { return FIsVisualPerceivableEnabled(this); }
	void EnableAuralPerceivable() { FEnableAuralPerceivable(this); }
	void DisableAuralPerceivable() { FDisableAuralPerceivable(this); }
	bool IsAuralPerceivableEnabled() const { return FIsAuralPerceivableEnabled(this); }
	virtual unsigned DoGetEntityId() const;
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const;
	virtual Vec3 *DoGetSimpleVisualPerceivableWorldPoints(Vec3 *_pFirstWorldPoint, Vec3 *_pLastWorldPoint) const;
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkNpcAttentionObject *const _this)>(0x13F2C00);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkNpcAttentionObject *const _this)>(0x13F2AD0);
	static inline auto FIsAttentionObjectEnabled = PreyFunction<bool(ArkNpcAttentionObject const *const _this)>(0x13F2C80);
	static inline auto FEnableVisualPerceivable = PreyFunction<void(ArkNpcAttentionObject *const _this)>(0x13F2C50);
	static inline auto FDisableVisualPerceivable = PreyFunction<void(ArkNpcAttentionObject *const _this)>(0x13F2B10);
	static inline auto FIsVisualPerceivableEnabled = PreyFunction<bool(ArkNpcAttentionObject const *const _this)>(0x13F2CC0);
	static inline auto FEnableAuralPerceivable = PreyFunction<void(ArkNpcAttentionObject *const _this)>(0x13F2C20);
	static inline auto FDisableAuralPerceivable = PreyFunction<void(ArkNpcAttentionObject *const _this)>(0x13F2AF0);
	static inline auto FIsAuralPerceivableEnabled = PreyFunction<bool(ArkNpcAttentionObject const *const _this)>(0x13F2CA0);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkNpcAttentionObject const *const _this)>(0x13F2B30);
	static inline auto FDoGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3(ArkNpcAttentionObject const *const _this)>(0x13F2B60);
	static inline auto FDoGetSimpleVisualPerceivableWorldPoints = PreyFunction<Vec3 *(ArkNpcAttentionObject const *const _this, Vec3 *_pFirstWorldPoint, Vec3 *_pLastWorldPoint)>(0x13F2B90);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkNpcAttentionObject const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x13F2B50);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkNpcAttentionObject const *const _this)>(0xDD23F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkNpcAttentionObject const *const _this)>(0xDD23F0);
};

