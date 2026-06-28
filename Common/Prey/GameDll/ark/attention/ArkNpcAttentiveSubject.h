// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkAttentiveSubject.h>
#include <Prey/GameDll/ark/perception/ArkVisualPerceiver.h>
#include <_unknown/ArkAuralPerceiver.h>
#include <_unknown/ArkRoomPerceiver.h>
#include <_unknown/ArkSeismicPerceiver.h>
#include <_unknown/TNavigationID.h>

struct ArkAttentionLevelChange;
struct ArkComplexAuralPerceptionInfo;
struct ArkComplexRoomPerceptionInfo;
struct ArkComplexSeismicPerceptionInfo;
struct ArkComplexVisualPerceptionInfo;
class ArkNpc;
struct ArkSimpleAuralPerceptionInfo;
struct ArkSimpleSeismicPerceptionInfo;
struct ArkVisualPerceiverVisionParams;
struct IPhysicalEntity;

// ArkNpcAttentiveSubject
// Header:  Prey/GameDll/ark/attention/ArkNpcAttentiveSubject.h
class ArkNpcAttentiveSubject
	: public ArkAttentiveSubject
	, public ArkAuralPerceiver
	, public ArkSeismicPerceiver
	, public ArkVisualPerceiver
	, public ArkRoomPerceiver
{ // Size=64 (0x40)
public:
	ArkNpc* m_pNpc;
	float m_complexHearingGain;
	float m_complexVisionGain;
	EArkNpcVisionDirection m_visionDirection;

	ArkNpcAttentiveSubject(ArkNpc& _npc);
	void EnableAttentiveSubject() { FEnableAttentiveSubject(this); }
	void DisableAttentiveSubject() { FDisableAttentiveSubject(this); }
	bool IsAttentiveSubjectEnabled() const { return FIsAttentiveSubjectEnabled(this); }
	void EnableAuralPerceiver() { FEnableAuralPerceiver(this); }
	void DisableAuralPerceiver() { FDisableAuralPerceiver(this); }
	bool IsAuralPerceiverEnabled() const { return FIsAuralPerceiverEnabled(this); }
	void EnableSeismicPerceiver() { FEnableSeismicPerceiver(this); }
	void DisableSeismicPerceiver() { FDisableSeismicPerceiver(this); }
	bool IsSeismicPerceiverEnabled() const { return FIsSeismicPerceiverEnabled(this); }
	void EnableVisualPerceiver() { FEnableVisualPerceiver(this); }
	void DisableVisualPerceiver() { FDisableVisualPerceiver(this); }
	bool IsVisualPerceiverEnabled() const { return FIsVisualPerceiverEnabled(this); }
	void EnableRoomPerceiver() { FEnableRoomPerceiver(this); }
	void DisableRoomPerceiver() { FDisableRoomPerceiver(this); }
	bool IsRoomPerceiverEnabled() const { return FIsRoomPerceiverEnabled(this); }
	void SetComplexHearingGain(float _gain) { FSetComplexHearingGain(this, _gain); }
	float GetComplexHearingGain() const { return FGetComplexHearingGain(this); }
	void SetComplexVisionGain(float _gain) { FSetComplexVisionGain(this, _gain); }
	float GetComplexVisionGain() const { return FGetComplexVisionGain(this); }
	void SetVisionDirection(EArkNpcVisionDirection _visionDirection) { FSetVisionDirection(this, _visionDirection); }
	virtual unsigned DoGetEntityId() const;
	virtual uint64_t DoGetAttentionModelId() const;
	virtual void DoGetAttentiveSubjectInfo(bool& _bUpdateAttentionLevels, Vec3& _position) const;
	virtual void DoOnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange);
	virtual void DoOnAttentionProxiesUpdated(const unsigned* _pFirstEntityId, const unsigned* _pLastEntityId);
	virtual Vec3 DoGetHearingPosition() const;
	virtual void DoUpdateAuralPerception(const ArkSimpleAuralPerceptionInfo* _pFirstSimpleAuralPerceptionInfo, const ArkSimpleAuralPerceptionInfo* _pLastSimpleAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pFirstComplexAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pLastComplexAuralPerceptionInfo);
	virtual TNavigationID<0> DoGetNavigationMeshId(TNavigationID<1> _navigationAgentTypeId) const;
	virtual void DoUpdateSeismicPerception(const ArkSimpleSeismicPerceptionInfo* _pFirstSimpleSeismicPerceptionInfo, const ArkSimpleSeismicPerceptionInfo* _pLastSimpleSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pFirstComplexSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pLastComplexSeismicPerceptionInfo);
	virtual uint64_t* DoGetVisionConeIds(uint64_t* _pFirstVisionConeId, uint64_t* _pLastVisionConeId) const;
	virtual ArkVisualPerceiverVisionParams DoGetVisionParams() const;
	virtual IPhysicalEntity* * DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const;
	virtual void DoUpdateVisualPerception(const unsigned* _pFirstSimpleStartPerceivingEntityId, const unsigned* _pFirstSimpleContinuePerceivingEntityId, const unsigned* _pFirstSimpleStopPerceivingEntityId, const unsigned* _pLastSimpleStopPerceivingEntityId, const ArkComplexVisualPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pLastComplexPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId);
	virtual uint64_t DoGetRoomPerceptionModelId() const;
	virtual Vec3 DoGetRoomPosition() const;
	virtual unsigned DoGetRoomPerceiverEntityId() const;
	virtual unsigned DoFindCurrentRoomEntityId() const;
	virtual unsigned DoGetAreaContainerEntityId() const;
	virtual void DoUpdateRoomPerception(const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexPContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId);
	virtual bool DoGetDoesIgnoredGloodTargets() const;

#if 0
	ArkNpcAttentiveSubject(const ArkNpcAttentiveSubject& _arg0_);
	ArkNpcAttentiveSubject& operator=(const ArkNpcAttentiveSubject& _arg0_);
#endif

	static inline auto FArkNpcAttentiveSubjectOv1 = PreyFunction<void(ArkNpcAttentiveSubject* const _this, ArkNpc& _npc)>(0x1504D00);
	static inline auto FEnableAttentiveSubject = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x15075A0);
	static inline auto FDisableAttentiveSubject = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x1505160);
	static inline auto FIsAttentiveSubjectEnabled = PreyFunction<bool(const ArkNpcAttentiveSubject* const _this)>(0x1507790);
	static inline auto FEnableAuralPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x1507610);
	static inline auto FDisableAuralPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x1505180);
	static inline auto FIsAuralPerceiverEnabled = PreyFunction<bool(const ArkNpcAttentiveSubject* const _this)>(0x15077B0);
	static inline auto FEnableSeismicPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x1507690);
	static inline auto FDisableSeismicPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x1505250);
	static inline auto FIsSeismicPerceiverEnabled = PreyFunction<bool(const ArkNpcAttentiveSubject* const _this)>(0x15077F0);
	static inline auto FEnableVisualPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x15076C0);
	static inline auto FDisableVisualPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x15052B0);
	static inline auto FIsVisualPerceiverEnabled = PreyFunction<bool(const ArkNpcAttentiveSubject* const _this)>(0x1507810);
	static inline auto FEnableRoomPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x1507640);
	static inline auto FDisableRoomPerceiver = PreyFunction<void(ArkNpcAttentiveSubject* const _this)>(0x15051E0);
	static inline auto FIsRoomPerceiverEnabled = PreyFunction<bool(const ArkNpcAttentiveSubject* const _this)>(0x15077D0);
	static inline auto FSetComplexHearingGain = PreyFunction<void(ArkNpcAttentiveSubject* const _this, float _gain)>(0x1507830);
	static inline auto FGetComplexHearingGain = PreyFunction<float(const ArkNpcAttentiveSubject* const _this)>(0x1D3580);
	static inline auto FSetComplexVisionGain = PreyFunction<void(ArkNpcAttentiveSubject* const _this, float _gain)>(0x1507890);
	static inline auto FGetComplexVisionGain = PreyFunction<float(const ArkNpcAttentiveSubject* const _this)>(0x88A4B0);
	static inline auto FSetVisionDirection = PreyFunction<void(ArkNpcAttentiveSubject* const _this, EArkNpcVisionDirection _visionDirection)>(0x15078F0);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(const ArkNpcAttentiveSubject* const _this)>(0x1505550);
	static inline auto FDoGetAttentionModelId = PreyFunction<uint64_t(const ArkNpcAttentiveSubject* const _this)>(0x1505350);
	static inline auto FDoGetAttentiveSubjectInfo = PreyFunction<void(const ArkNpcAttentiveSubject* const _this, bool& _bUpdateAttentionLevels, Vec3& _position)>(0x15054F0);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkNpcAttentiveSubject* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x1506610);
	static inline auto FDoOnAttentionProxiesUpdated = PreyFunction<void(ArkNpcAttentiveSubject* const _this, const unsigned* _pFirstEntityId, const unsigned* _pLastEntityId)>(0x1506710);
	static inline auto FDoGetHearingPosition = PreyFunction<Vec3*(const ArkAuralPerceiver* const _this, Vec3* _return_value_)>(0x1505570);
	static inline auto FDoUpdateAuralPerception = PreyFunction<void(ArkAuralPerceiver* const _this, const ArkSimpleAuralPerceptionInfo* _pFirstSimpleAuralPerceptionInfo, const ArkSimpleAuralPerceptionInfo* _pLastSimpleAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pFirstComplexAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pLastComplexAuralPerceptionInfo)>(0x1506780);
	static inline auto FDoGetNavigationMeshId = PreyFunction<TNavigationID<0>*(const ArkSeismicPerceiver* const _this, TNavigationID<0>* _return_value_, TNavigationID<1> _navigationAgentTypeId)>(0x15055B0);
	static inline auto FDoUpdateSeismicPerception = PreyFunction<void(ArkSeismicPerceiver* const _this, const ArkSimpleSeismicPerceptionInfo* _pFirstSimpleSeismicPerceptionInfo, const ArkSimpleSeismicPerceptionInfo* _pLastSimpleSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pFirstComplexSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pLastComplexSeismicPerceptionInfo)>(0x1506FF0);
	static inline auto FDoGetVisionConeIds = PreyFunction<uint64_t* (const ArkVisualPerceiver* const _this, uint64_t* _pFirstVisionConeId, uint64_t* _pLastVisionConeId)>(0x1505810);
	static inline auto FDoGetVisionParams = PreyFunction<ArkVisualPerceiverVisionParams*(const ArkVisualPerceiver* const _this, ArkVisualPerceiverVisionParams* _return_value_)>(0x1505AD0);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkVisualPerceiver* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x15055A0);
	static inline auto FDoUpdateVisualPerception = PreyFunction<void(ArkVisualPerceiver* const _this, const unsigned* _pFirstSimpleStartPerceivingEntityId, const unsigned* _pFirstSimpleContinuePerceivingEntityId, const unsigned* _pFirstSimpleStopPerceivingEntityId, const unsigned* _pLastSimpleStopPerceivingEntityId, const ArkComplexVisualPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pLastComplexPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId)>(0x15072C0);
	static inline auto FDoGetRoomPerceptionModelId = PreyFunction<uint64_t(const ArkRoomPerceiver* const _this)>(0x1505640);
	static inline auto FDoGetRoomPosition = PreyFunction<Vec3*(const ArkRoomPerceiver* const _this, Vec3* _return_value_)>(0x15057E0);
	static inline auto FDoGetRoomPerceiverEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x1505630);
	static inline auto FDoFindCurrentRoomEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x1505310);
	static inline auto FDoGetAreaContainerEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x1505330);
	static inline auto FDoUpdateRoomPerception = PreyFunction<void(ArkRoomPerceiver* const _this, const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexPContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId)>(0x1506DD0);
	static inline auto FDoGetDoesIgnoredGloodTargets = PreyFunction<bool(const ArkNpcAttentiveSubject* const _this)>(0x13B0900);
};
#endif // MOONCRASH
