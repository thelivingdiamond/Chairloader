// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/attention/arkcomplexattentionobject.h>
#include <_unknown/ArkAuralPerceivable.h>
#include <_unknown/ArkSimpleVisualPerceivable.h>

class ArkCystoid;
class ArkCystoidNest;
class ArkTurret;
struct IEntity;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/attention/arkgenericattentionobject.h
class ArkGenericAttentionObjectBase : public ArkSimpleAttentionObject, public ArkSimpleVisualPerceivable, public ArkAuralPerceivable // Id=80152E1 Size=24
{
public:
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	bool IsEnabled() const { return FIsEnabled(this); }
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const;
	virtual Vec3* DoGetSimpleVisualPerceivableWorldPoints(Vec3* _pFirstWorldPoint, Vec3* _pLastWorldPoint) const;
	virtual IPhysicalEntity** DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity** _ppFirstPhysicalEntity, IPhysicalEntity** _ppLastPhysicalEntity) const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	virtual unsigned DoGetEntityId() const = 0;
	virtual IEntity* DoGetEntity() const = 0;

#if 0
	unsigned GetEntityId() const;
	IEntity* GetEntity() const;
#endif

	static inline auto FEnable = PreyFunction<void(ArkGenericAttentionObjectBase* const _this)>(0x13B2860);
	static inline auto FDisable = PreyFunction<void(ArkGenericAttentionObjectBase* const _this)>(0x13B2700);
	static inline auto FIsEnabled = PreyFunction<bool(ArkGenericAttentionObjectBase const* const _this)>(0x13B28D0);
	static inline auto FDoGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3(ArkGenericAttentionObjectBase const* const _this)>(0x13B27A0);
	static inline auto FDoGetSimpleVisualPerceivableWorldPoints = PreyFunction<Vec3* (ArkGenericAttentionObjectBase const* const _this, Vec3* _pFirstWorldPoint, Vec3* _pLastWorldPoint)>(0x13B27F0);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity** (ArkGenericAttentionObjectBase const* const _this, IPhysicalEntity** _ppFirstPhysicalEntity, IPhysicalEntity** _ppLastPhysicalEntity)>(0x13B2760);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkGenericAttentionObjectBase const* const _this)>(0xDD23F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkGenericAttentionObjectBase const* const _this)>(0xDD23F0);
};

// Header: Exact
// Prey/GameDll/ark/attention/arkgenericattentionobject.h
template <typename T>
class ArkGenericAttentionObject : public ArkGenericAttentionObjectBase // Id=80152E0 Size=32
{
public:
	T *m_pOwner;
	
	virtual unsigned DoGetEntityId() const;
	virtual IEntity *DoGetEntity() const;
};

