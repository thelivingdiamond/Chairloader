// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/attention/ArkComplexAttentionObject.h>
#include <Prey/GameDll/ark/perception/ArkAttentiveSubject.h>
#include <Prey/GameDll/ark/perception/arkvisualperceiver.h>

struct ArkAttentionLevelChange;
struct ArkComplexVisualPerceptionInfo;
class ArkTurret;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkTurretAttentiveSubject.h
class ArkTurretAttentiveSubject : public ArkAttentiveSubject, public ArkVisualPerceiver // Id=80152EC Size=56
{
public:
	ArkTurret *m_pTurret;
	
	struct VisionConeSemiangles // Id=80152ED Size=12
	{
		float m_horizontalSemiangle;
		float m_upSemiangle;
		float m_downSemiangle;
	};

	ArkTurretAttentiveSubject::VisionConeSemiangles m_defaultVisionConeSemiangles;
	ArkTurretAttentiveSubject::VisionConeSemiangles m_zeroGVisionConeSemiangles;
	bool m_bVisionConeSemianglesCached;
	
	ArkTurretAttentiveSubject(ArkTurret &_turret);
	void EnableAttentiveSubject() { FEnableAttentiveSubject(this); }
	void DisableAttentiveSubject() { FDisableAttentiveSubject(this); }
	bool IsAttentiveSubjectEnabled() const { return FIsAttentiveSubjectEnabled(this); }
	void EnableVisualPerceiver() { FEnableVisualPerceiver(this); }
	void DisableVisualPerceiver() { FDisableVisualPerceiver(this); }
	bool IsVisualPerceiverEnabled() const { return FIsVisualPerceiverEnabled(this); }
	virtual unsigned DoGetEntityId() const;
	virtual uint64_t DoGetAttentionModelId() const;
	virtual void DoGetAttentiveSubjectInfo(bool &_bUpdateAttentionLevels, Vec3 &_position) const;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange);
	virtual void DoOnAttentionProxiesUpdated(const unsigned *_pFirstEntityId, const unsigned *_pLastEntityId);
	virtual uint64_t *DoGetVisionConeIds(uint64_t *_pFirstVisionConeId, uint64_t *_pLastVisionConeId) const;
	virtual ArkVisualPerceiverVisionParams DoGetVisionParams() const;
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const;
	virtual void DoUpdateVisualPerception(const unsigned *_pFirstSimpleStartPerceivingEntityId, const unsigned *_pFirstSimpleContinuePerceivingEntityId, const unsigned *_pFirstSimpleStopPerceivingEntityId, const unsigned *_pLastSimpleStopPerceivingEntityId, ArkComplexVisualPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pLastComplexPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId);
	void CacheVisionConeSemiangles() { FCacheVisionConeSemiangles(this); }
	
#ifdef MOONCRASH
	void SetIgnoresGloodTargets(bool _bIgnoresGloodTargets) { FSetIgnoresGloodTargets(this, _bIgnoresGloodTargets); }
#endif
#ifndef MOONCRASH
	static inline auto FEnableAttentiveSubject = PreyFunction<void(ArkTurretAttentiveSubject *const _this)>(0x11B35A0);
	static inline auto FDisableAttentiveSubject = PreyFunction<void(ArkTurretAttentiveSubject *const _this)>(0x11B2D10);
	static inline auto FIsAttentiveSubjectEnabled = PreyFunction<bool(ArkTurretAttentiveSubject const *const _this)>(0x11B3610);
	static inline auto FEnableVisualPerceiver = PreyFunction<void(ArkTurretAttentiveSubject *const _this)>(0x11B35C0);
	static inline auto FDisableVisualPerceiver = PreyFunction<void(ArkTurretAttentiveSubject *const _this)>(0x11B2D30);
	static inline auto FIsVisualPerceiverEnabled = PreyFunction<bool(ArkTurretAttentiveSubject const *const _this)>(0x11B3630);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkTurretAttentiveSubject const *const _this)>(0x11B2E60);
	static inline auto FDoGetAttentionModelId = PreyFunction<uint64_t(ArkTurretAttentiveSubject const *const _this)>(0x11B2D90);
	static inline auto FDoGetAttentiveSubjectInfo = PreyFunction<void(ArkTurretAttentiveSubject const *const _this, bool &_bUpdateAttentionLevels, Vec3 &_position)>(0x11B2E00);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkTurretAttentiveSubject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x11B3260);
	static inline auto FDoOnAttentionProxiesUpdated = PreyFunction<void(ArkTurretAttentiveSubject *const _this, const unsigned *_pFirstEntityId, const unsigned *_pLastEntityId)>(0xA13080);
	static inline auto FDoGetVisionConeIds = PreyFunction<uint64_t *(ArkTurretAttentiveSubject const *const _this, uint64_t *_pFirstVisionConeId, uint64_t *_pLastVisionConeId)>(0x11B2E80);
	static inline auto FDoGetVisionParams = PreyFunction<ArkVisualPerceiverVisionParams(ArkTurretAttentiveSubject const *const _this)>(0x11B3060);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkTurretAttentiveSubject const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x11B2E70);
	static inline auto FDoUpdateVisualPerception = PreyFunction<void(ArkTurretAttentiveSubject *const _this, const unsigned *_pFirstSimpleStartPerceivingEntityId, const unsigned *_pFirstSimpleContinuePerceivingEntityId, const unsigned *_pFirstSimpleStopPerceivingEntityId, const unsigned *_pLastSimpleStopPerceivingEntityId, ArkComplexVisualPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pLastComplexPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId)>(0x11B32C0);
	static inline auto FCacheVisionConeSemiangles = PreyFunction<void(ArkTurretAttentiveSubject *const _this)>(0x11B2830);
#else
	static inline auto FArkTurretAttentiveSubjectOv1 = PreyFunction<void(ArkTurretAttentiveSubject* const _this, ArkTurret& _turret)>(0x122FFC0);
	static inline auto FEnableAttentiveSubject = PreyFunction<void(ArkTurretAttentiveSubject* const _this)>(0x1230D70);
	static inline auto FDisableAttentiveSubject = PreyFunction<void(ArkTurretAttentiveSubject* const _this)>(0x12304D0);
	static inline auto FIsAttentiveSubjectEnabled = PreyFunction<bool(const ArkTurretAttentiveSubject* const _this)>(0x1230DE0);
	static inline auto FEnableVisualPerceiver = PreyFunction<void(ArkTurretAttentiveSubject* const _this)>(0x1230D90);
	static inline auto FDisableVisualPerceiver = PreyFunction<void(ArkTurretAttentiveSubject* const _this)>(0x12304F0);
	static inline auto FIsVisualPerceiverEnabled = PreyFunction<bool(const ArkTurretAttentiveSubject* const _this)>(0x1230E00);
	static inline auto FSetIgnoresGloodTargets = PreyFunction<void(ArkTurretAttentiveSubject* const _this, bool _bIgnoresGloodTargets)>(0x1230E20);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(const ArkTurretAttentiveSubject* const _this)>(0x1230630);
	static inline auto FDoGetDoesIgnoredGloodTargets = PreyFunction<bool(const ArkTurretAttentiveSubject* const _this)>(0x1230620);
	static inline auto FDoGetAttentionModelId = PreyFunction<uint64_t(const ArkTurretAttentiveSubject* const _this)>(0x1230550);
	static inline auto FDoGetAttentiveSubjectInfo = PreyFunction<void(const ArkTurretAttentiveSubject* const _this, bool& _bUpdateAttentionLevels, Vec3& _position)>(0x12305C0);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkTurretAttentiveSubject* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x1230A30);
	static inline auto FDoOnAttentionProxiesUpdated = PreyFunction<void(ArkTurretAttentiveSubject* const _this, const unsigned* _pFirstEntityId, const unsigned* _pLastEntityId)>(0x1333E90);
	static inline auto FDoGetVisionConeIds = PreyFunction<uint64_t* (const ArkVisualPerceiver* const _this, uint64_t* _pFirstVisionConeId, uint64_t* _pLastVisionConeId)>(0x1230650);
	static inline auto FDoGetVisionParams = PreyFunction<ArkVisualPerceiverVisionParams*(const ArkVisualPerceiver* const _this, ArkVisualPerceiverVisionParams* _return_value_)>(0x1230830);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkVisualPerceiver* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x1230640);
	static inline auto FDoUpdateVisualPerception = PreyFunction<void(ArkVisualPerceiver* const _this, const unsigned* _pFirstSimpleStartPerceivingEntityId, const unsigned* _pFirstSimpleContinuePerceivingEntityId, const unsigned* _pFirstSimpleStopPerceivingEntityId, const unsigned* _pLastSimpleStopPerceivingEntityId, const ArkComplexVisualPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pLastComplexPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId)>(0x1230A90);
	static inline auto FCacheVisionConeSemiangles = PreyFunction<void(ArkTurretAttentiveSubject* const _this)>(0x122FFF0);
#endif
};
