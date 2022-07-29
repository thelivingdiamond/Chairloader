// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/attention/ArkComplexAttentionObject.h>
#include <Prey/GameDll/ark/perception/ArkAuralPerceivable.h>
#include <Prey/GameDll/ark/perception/ArkComplexRoomPerceivable.h>
#include <Prey/GameDll/ark/perception/ArkComplexVisualPerceivable.h>

struct ArkAttentionLevelChange;
class ArkPlayerMimicRigidEntity;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkPlayerMimicRigidEntityAttentionObject.h
class ArkPlayerMimicRigidEntityAttentionObject : public ArkComplexAttentionObject, public ArkAuralPerceivable, public ArkComplexVisualPerceivable, public ArkComplexRoomPerceivable // Id=80195DF Size=48
{
public:
	ArkPlayerMimicRigidEntity *m_pPlayerMimicRigidEntity;
	unsigned m_roomEntityId;
	
	ArkPlayerMimicRigidEntityAttentionObject(ArkPlayerMimicRigidEntity &_playerMimicRigidEntity);
	void EnableAttentionObject() { FEnableAttentionObject(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	bool IsAttentionObjectEnabled() const { return FIsAttentionObjectEnabled(this); }
	void EnableVisualPerceivable() { FEnableVisualPerceivable(this); }
	void DisableVisualPerceivable() { FDisableVisualPerceivable(this); }
	void EnableAuralPerceivable() { FEnableAuralPerceivable(this); }
	void DisableAuralPerceivable() { FDisableAuralPerceivable(this); }
	void EnableRoomPerceivable() { FEnableRoomPerceivable(this); }
	void DisableRoomPerceivable() { FDisableRoomPerceivable(this); }
	virtual unsigned DoGetEntityId() const;
	virtual Vec3 DoGetAttentionPosition() const;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange);
	virtual std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *> DoGetComplexVisualPerceivableWorldPoints(Vec3 *_pFirstAnyWorldPoint, Vec3 *_pLastAnyWorldPoint, Vec3 *_pFirstAcuteWorldPoint, Vec3 *_pLastAcuteWorldPoint, Vec3 *_pFirstAllWorldPoint, Vec3 *_pLastAllWorldPoint) const;
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const;
	virtual float DoGetVisibilityScalar() const;
	virtual bool DoGetIsInMimicryHidden() const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	virtual unsigned DoGetCurrentRoomEntityId() const;
	
#if 0
	bool IsVisualPerceivableEnabled() const;
	bool IsAuralPerceivableEnabled() const;
	bool IsRoomPerceivableEnabled() const;
	unsigned GetRoomEntityId() const;
	void SetRoomEntityId(unsigned arg0);
#endif
	
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B26A0);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B2170);
	static inline auto FIsAttentionObjectEnabled = PreyFunction<bool(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x11B27E0);
	static inline auto FEnableVisualPerceivable = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B2790);
	static inline auto FDisableVisualPerceivable = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B2260);
	static inline auto FEnableAuralPerceivable = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B26F0);
	static inline auto FDisableAuralPerceivable = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B21C0);
	static inline auto FEnableRoomPerceivable = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B2740);
	static inline auto FDisableRoomPerceivable = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this)>(0x11B2210);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x11B2390);
	static inline auto FDoGetAttentionPosition = PreyFunction<Vec3(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x11B22B0);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkPlayerMimicRigidEntityAttentionObject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x11B2600);
	static inline auto FDoGetComplexVisualPerceivableWorldPoints = PreyFunction<std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *>(ArkPlayerMimicRigidEntityAttentionObject const *const _this, Vec3 *_pFirstAnyWorldPoint, Vec3 *_pLastAnyWorldPoint, Vec3 *_pFirstAcuteWorldPoint, Vec3 *_pLastAcuteWorldPoint, Vec3 *_pFirstAllWorldPoint, Vec3 *_pLastAllWorldPoint)>(0x11B2310);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkPlayerMimicRigidEntityAttentionObject const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x11B23B0);
	static inline auto FDoGetVisibilityScalar = PreyFunction<float(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x11B2410);
	static inline auto FDoGetIsInMimicryHidden = PreyFunction<bool(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x11B23E0);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x11B22F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x1B933B0);
	static inline auto FDoGetCurrentRoomEntityId = PreyFunction<unsigned(ArkPlayerMimicRigidEntityAttentionObject const *const _this)>(0x985E40);
};

