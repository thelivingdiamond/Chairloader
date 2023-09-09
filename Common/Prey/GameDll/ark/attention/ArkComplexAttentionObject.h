// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/arkvisualperceiver.h>

struct ArkAttentionLevelChange;
struct ArkComplexAuralPerceptionInfo;
struct ArkComplexVisualPerceptionInfo;
struct ArkSimpleAuralPerceptionInfo;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/attention/arkcomplexattentionobject.h
class ArkAuralPerceiver // Id=801430E Size=8
{
public:
	unsigned GetEntityId() const { return FGetEntityId(this); }
	Vec3 GetHearingPosition() const { return FGetHearingPosition(this); }
	void UpdateAuralPerception(ArkSimpleAuralPerceptionInfo const *_pFirstSimpleAuralPerceptionInfo, ArkSimpleAuralPerceptionInfo const *_pLastSimpleAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pFirstComplexAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pLastComplexAuralPerceptionInfo) { FUpdateAuralPerception(this,_pFirstSimpleAuralPerceptionInfo,_pLastSimpleAuralPerceptionInfo,_pFirstComplexAuralPerceptionInfo,_pLastComplexAuralPerceptionInfo); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetHearingPosition() const = 0;
	virtual void DoUpdateAuralPerception(ArkSimpleAuralPerceptionInfo const *arg0, ArkSimpleAuralPerceptionInfo const *arg1, ArkComplexAuralPerceptionInfo const *arg2, ArkComplexAuralPerceptionInfo const *arg3) = 0;
	
	static inline auto FGetEntityId = PreyFunction<unsigned(ArkAuralPerceiver const *const _this)>(0x13B26F0);
	static inline auto FGetHearingPosition = PreyFunction<Vec3(ArkAuralPerceiver const *const _this)>(0x13EF180);
	static inline auto FUpdateAuralPerception = PreyFunction<void(ArkAuralPerceiver *const _this, ArkSimpleAuralPerceptionInfo const *_pFirstSimpleAuralPerceptionInfo, ArkSimpleAuralPerceptionInfo const *_pLastSimpleAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pFirstComplexAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pLastComplexAuralPerceptionInfo)>(0x1457570);
};

// Header: FromCpp
// Prey/GameDll/ark/attention/arkcomplexattentionobject.h
class ArkVisualPerceiver // Id=8014312 Size=8
{
public:
	uint64_t *GetVisionConeIds(uint64_t *_pFirstVisionConeId, uint64_t *_pLastVisionConeId) const { return FGetVisionConeIds(this,_pFirstVisionConeId,_pLastVisionConeId); }
	ArkVisualPerceiverVisionParams GetVisionParams() const { return FGetVisionParams(this); }
	IPhysicalEntity **GetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const { return FGetIgnoredPhysicalEntitiesInLineOfSight(this,_ppFirstPhysicalEntity,_ppLastPhysicalEntity); }
	void UpdateVisualPerception(const unsigned *_pFirstSimpleStartPerceivingEntityId, const unsigned *_pFirstSimpleContinuePerceivingEntityId, const unsigned *_pFirstSimpleStopPerceivingEntityId, const unsigned *_pLastSimpleStopPerceivingEntityId, ArkComplexVisualPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pLastComplexPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId) { FUpdateVisualPerception(this,_pFirstSimpleStartPerceivingEntityId,_pFirstSimpleContinuePerceivingEntityId,_pFirstSimpleStopPerceivingEntityId,_pLastSimpleStopPerceivingEntityId,_pFirstComplexStartPerceivingPerceptionInfo,_pFirstComplexContinuePerceivingPerceptionInfo,_pLastComplexPerceptionInfo,_pFirstComplexStopPerceivingEntityId,_pLastComplexStopPerceivingEntityId); }
	virtual uint64_t *DoGetVisionConeIds(uint64_t *arg0, uint64_t *arg1) const = 0;
	virtual ArkVisualPerceiverVisionParams DoGetVisionParams() const = 0;
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **arg0, IPhysicalEntity **arg1) const = 0;
	virtual void DoUpdateVisualPerception(const unsigned *arg0, const unsigned *arg1, const unsigned *arg2, const unsigned *arg3, ArkComplexVisualPerceptionInfo const *arg4, ArkComplexVisualPerceptionInfo const *arg5, ArkComplexVisualPerceptionInfo const *arg6, const unsigned *arg7, const unsigned *arg8) = 0;
	
	static inline auto FGetVisionConeIds = PreyFunction<uint64_t *(ArkVisualPerceiver const *const _this, uint64_t *_pFirstVisionConeId, uint64_t *_pLastVisionConeId)>(0x13B26F0);
	static inline auto FGetVisionParams = PreyFunction<ArkVisualPerceiverVisionParams(ArkVisualPerceiver const *const _this)>(0x13EF180);
	static inline auto FGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkVisualPerceiver const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x15AAEA0);
	static inline auto FUpdateVisualPerception = PreyFunction<void(ArkVisualPerceiver *const _this, const unsigned *_pFirstSimpleStartPerceivingEntityId, const unsigned *_pFirstSimpleContinuePerceivingEntityId, const unsigned *_pFirstSimpleStopPerceivingEntityId, const unsigned *_pLastSimpleStopPerceivingEntityId, ArkComplexVisualPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pLastComplexPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId)>(0x15287F0);
};

// Header: FromCpp
// Prey/GameDll/ark/attention/arkcomplexattentionobject.h
class ArkSimpleAttentionObject : private boost::noncopyable_::noncopyable // Id=8014318 Size=8
{
public:
	Vec3 GetSimpleAttentionObjectWorldPos() const { return FGetSimpleAttentionObjectWorldPos(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetSimpleAttentionObjectWorldPos() const = 0;
	
#if 0
	unsigned GetEntityId() const;
#endif
	
	static inline auto FGetSimpleAttentionObjectWorldPos = PreyFunction<Vec3(ArkSimpleAttentionObject const *const _this)>(0x13EF180);
};

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkComplexAttentionObject.h
class ArkComplexAttentionObject : private boost::noncopyable_::noncopyable // Id=8014DAE Size=8
{
public:
	Vec3 GetAttentionPosition() const { return FGetAttentionPosition(this); }
	void OnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange) { FOnAttentionLevelsChanged(this,_pFirstChange,_pLastChange); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetAttentionPosition() const = 0;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *arg0, ArkAttentionLevelChange const *arg1) = 0;
	
#if 0
	unsigned GetEntityId() const;
#endif
	
	static inline auto FGetAttentionPosition = PreyFunction<Vec3(ArkComplexAttentionObject const *const _this)>(0x13EF180);
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkComplexAttentionObject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x15AAEA0);
};

