// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/attention/ArkComplexAttentionObject.h>
#include <Prey/GameDll/ark/perception/ArkComplexVisualPerceivable.h>

struct ArkAttentionLevelChange;
class ArkEtherDuplicate;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkEtherDuplicateAttentionObject.h
class ArkEtherDuplicateAttentionObject : public ArkComplexAttentionObject, public ArkComplexVisualPerceivable // Id=8019311 Size=24
{
public:
	ArkEtherDuplicate const *m_pEtherDuplicate;
	
	ArkEtherDuplicateAttentionObject(ArkEtherDuplicate const &_etherDuplicate);
	~ArkEtherDuplicateAttentionObject();
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	virtual unsigned DoGetEntityId() const;
	virtual Vec3 DoGetAttentionPosition() const;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange);
	virtual std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *> DoGetComplexVisualPerceivableWorldPoints(Vec3 *_pFirstAnyWorldPoint, Vec3 *_pLastAnyWorldPoint, Vec3 *_pFirstAcuteWorldPoint, Vec3 *_pLastAcuteWorldPoint, Vec3 *_pFirstAllWorldPoint, Vec3 *_pLastAllWorldPoint) const;
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const;
	virtual float DoGetVisibilityScalar() const;
	
	static inline auto FBitNotArkEtherDuplicateAttentionObject = PreyFunction<void(ArkEtherDuplicateAttentionObject *const _this)>(0x13EF1E0);
	static inline auto FEnable = PreyFunction<void(ArkEtherDuplicateAttentionObject *const _this)>(0x13EF3B0);
	static inline auto FDisable = PreyFunction<void(ArkEtherDuplicateAttentionObject *const _this)>(0x13EF200);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkEtherDuplicateAttentionObject const *const _this)>(0x13EF340);
	static inline auto FDoGetAttentionPosition = PreyFunction<Vec3(ArkEtherDuplicateAttentionObject const *const _this)>(0x13EF240);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkEtherDuplicateAttentionObject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0xA13080);
	static inline auto FDoGetComplexVisualPerceivableWorldPoints = PreyFunction<std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *>(ArkEtherDuplicateAttentionObject const *const _this, Vec3 *_pFirstAnyWorldPoint, Vec3 *_pLastAnyWorldPoint, Vec3 *_pFirstAcuteWorldPoint, Vec3 *_pLastAcuteWorldPoint, Vec3 *_pFirstAllWorldPoint, Vec3 *_pLastAllWorldPoint)>(0x13EF280);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkEtherDuplicateAttentionObject const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x13EF350);
	static inline auto FDoGetVisibilityScalar = PreyFunction<float(ArkEtherDuplicateAttentionObject const *const _this)>(0x18C0850);
};

