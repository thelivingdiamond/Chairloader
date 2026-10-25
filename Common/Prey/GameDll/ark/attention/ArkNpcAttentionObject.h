#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkAuralPerceivable.h>
#include <Prey/GameDll/ark/attention/ArkComplexAttentionObject.h>
#include <Prey/GameDll/ark/perception/ArkSimpleVisualPerceivable.h>
#include <Prey/GameDll/ark/perception/ArkSeismicPerceivable.h>

class ArkNpc;
struct ArkSeismicBounds;
struct IPhysicalEntity;

// ArkNpcAttentionObject
// Header:  Prey/GameDll/ark/attention/ArkNpcAttentionObject.h
class ArkNpcAttentionObject
	: public ArkSimpleAttentionObject
	, public ArkSimpleVisualPerceivable
	, public ArkAuralPerceivable
	, public ArkSeismicPerceivable
{ // Size=40 (0x28)
public:
	ArkNpc* m_pNpc;

	ArkNpcAttentionObject(ArkNpc& _npc);
	void EnableAttentionObject() { FEnableAttentionObject(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	bool IsAttentionObjectEnabled() const { return FIsAttentionObjectEnabled(this); }
	void EnableVisualPerceivable() { FEnableVisualPerceivable(this); }
	void DisableVisualPerceivable() { FDisableVisualPerceivable(this); }
	bool IsVisualPerceivableEnabled() const { return FIsVisualPerceivableEnabled(this); }
	void EnableAuralPerceivable() { FEnableAuralPerceivable(this); }
	void DisableAuralPerceivable() { FDisableAuralPerceivable(this); }
	bool IsAuralPerceivableEnabled() const { return FIsAuralPerceivableEnabled(this); }
	void EnableSeismicPerceivable() { FEnableSeismicPerceivable(this); }
	void DisableSeismicPerceivable() { FDisableSeismicPerceivable(this); }
	bool IsSeismicPerceivableEnabled() const { return FIsSeismicPerceivableEnabled(this); }
	virtual unsigned DoGetEntityId() const;
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const;
	virtual bool DoGetIsGlood() const;
	virtual Vec3* DoGetSimpleVisualPerceivableWorldPoints(Vec3* _pFirstWorldPoint, Vec3* _pLastWorldPoint) const;
	virtual IPhysicalEntity* * DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	virtual ArkSeismicBounds DoGetSeismicBounds() const;

#if 0
	ArkNpcAttentionObject(const ArkNpcAttentionObject& _arg0_);
	ArkNpcAttentionObject& operator=(const ArkNpcAttentionObject& _arg0_);
#endif

	static inline auto FArkNpcAttentionObjectOv1 = PreyFunction<void(ArkNpcAttentionObject* const _this, ArkNpc& _npc)>(0x15043C0);
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x1504580);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x1504400);
	static inline auto FIsAttentionObjectEnabled = PreyFunction<bool(const ArkNpcAttentionObject* const _this)>(0x1504630);
	static inline auto FEnableVisualPerceivable = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x1504600);
	static inline auto FDisableVisualPerceivable = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x1504460);
	static inline auto FIsVisualPerceivableEnabled = PreyFunction<bool(const ArkNpcAttentionObject* const _this)>(0x1504690);
	static inline auto FEnableAuralPerceivable = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x15045A0);
	static inline auto FDisableAuralPerceivable = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x1504420);
	static inline auto FIsAuralPerceivableEnabled = PreyFunction<bool(const ArkNpcAttentionObject* const _this)>(0x1504650);
	static inline auto FEnableSeismicPerceivable = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x15045D0);
	static inline auto FDisableSeismicPerceivable = PreyFunction<void(ArkNpcAttentionObject* const _this)>(0x1504440);
	static inline auto FIsSeismicPerceivableEnabled = PreyFunction<bool(const ArkNpcAttentionObject* const _this)>(0x1504670);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(const ArkNpcAttentionObject* const _this)>(0x1504480);
	static inline auto FDoGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3*(const ArkNpcAttentionObject* const _this, Vec3* _return_value_)>(0x15044E0);
	static inline auto FDoGetIsGlood = PreyFunction<bool(const ArkNpcAttentionObject* const _this)>(0x15044B0);
	static inline auto FDoGetSimpleVisualPerceivableWorldPoints = PreyFunction<Vec3* (const ArkSimpleVisualPerceivable* const _this, Vec3* _pFirstWorldPoint, Vec3* _pLastWorldPoint)>(0x1504510);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkSimpleVisualPerceivable* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x15044A0);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(const ArkAuralPerceivable* const _this)>(0x13B0900);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(const ArkAuralPerceivable* const _this)>(0x13B0900);
	static inline auto FDoGetSeismicBounds = PreyFunction<ArkSeismicBounds*(const ArkSeismicPerceivable* const _this, ArkSeismicBounds* _return_value_)>(0x1508140);
};
#endif // !MOONCRASH
