// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// CryEngine/cryaisystem/aiobject.h
struct AgentPerceptionParameters // Id=800103C Size=100
{
    float sightRange;
    float sightNearRange;
    float sightDelay;
    float FOVPrimary;
    float FOVSecondary;
    float stanceScale;
    float audioScale;
    float targetPersistence;
    float reactionTime;
    float collisionReactionScale;
    float stuntReactionTimeOut;
    float forgetfulness;
    float forgetfulnessTarget;
    float forgetfulnessSeek;
    float forgetfulnessMemory;
    bool isAffectedByLight;
    float minAlarmLevel;
    float bulletHitRadius;
    float minDistanceToSpotDeadBodies;
    float cloakMaxDistStill;
    float cloakMaxDistMoving;
    float cloakMaxDistCrouchedAndStill;
    float cloakMaxDistCrouchedAndMoving;

    struct SPerceptionScale // Id=800103D Size=8
    {
        float visual;
        float audio;
    };

    AgentPerceptionParameters::SPerceptionScale perceptionScale;

    void Serialize(TSerialize ser) { FSerialize(this,ser); }

#ifndef MOONCRASH
    static inline auto FSerialize = PreyFunction<void(AgentPerceptionParameters *const _this, TSerialize ser)>(0x7053D0);
#else

#endif
};

// Header: Exact
// CryEngine/crycommon/agentparams.h
struct AgentParameters // Id=800103B Size=240
{
	AgentPerceptionParameters m_PerceptionParams;
	int m_CombatClass;
	float m_fAccuracy;
	float m_fPassRadius;
	float m_fSeparationRadius;
	float m_fStrafingPitch;
	float m_fAttackRange;
	float m_fCommRange;
	float m_fAttackZoneHeight;
	float m_fProjectileLaunchDistScale;
	int m_weaponAccessories;
	float m_fMeleeRange;
	float m_fMeleeRangeShort;
	float m_fMeleeHitRange;
	float m_fMeleeAngleCosineThreshold;
	float m_fMeleeDamage;
	float m_fMeleeKnowckdownChance;
	float m_fMeleeImpulse;
	int m_nGroup;
	bool m_bAiIgnoreFgNode;
	bool m_bPerceivePlayer;
	bool m_bInvisible;
	bool m_bCloaked;
	float m_fCloakScale;
	float m_fCloakScaleTarget;
	float m_fLastCloakEventTime;
	float m_lookIdleTurnSpeed;
	float m_lookCombatTurnSpeed;
	float m_aimTurnSpeed;
	float m_fireTurnSpeed;
	float distanceToCover;
	float effectiveCoverHeight;
	float effectiveHighCoverHeight;
	float inCoverRadius;
	string m_sTerritoryName;
	string m_sWaveName;

	AgentParameters();
	void Serialize(TSerialize ser) { FSerialize(this,ser); }

#if 0
	void Reset();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(AgentParameters *const _this, TSerialize ser)>(0x7050E0);
#else

#endif
};


// CAIObject
// Header:  CryEngine/cryaisystem/AIObject.h
// Include: Prey/CryAISystem/AIObject.h
class CAIObject : public IAIObject
{ // Size=192 (0xC0)
public:
	bool m_bEnabled;
	uint16_t m_nObjectType;
	IAIObject::ESubType m_objectSubType;
	int m_groupId;
	float m_fRadius;
	unsigned m_entityID;
	CWeakRef<CAIObject> m_refThis;
	Vec3 m_vPosition;
	Vec3 m_vEntityDir;
	Vec3 m_vBodyDir;
	Vec3 m_vMoveDir;
	Vec3 m_vView;
	uint64_t m_lastNavNodeIndex;
	bool m_bUpdatedOnce;
	bool m_bTouched;
	Vec3 m_vLastPosition;
	Vec3 m_vFirePosition;
	Vec3 m_vFireDir;
	Vec3 m_vExpectedPhysicsPos;
	int m_expectedPhysicsPosFrameId;
	bool m_isThreateningForHostileFactions;
	bool m_observable;
	bool m_bIsInTrackview;
	bool m_bIsInExactPositioning;
	bool m_bIsInGravShaft;
	bool m_createdFromPool;
	bool m_serialize;
	string m_name;
	CWeakRef<CAIObject> m_refAssociation;

	CAIObject();
	virtual ~CAIObject();
	virtual void Reset(EObjectResetType type);
	virtual void Release();
	virtual bool IsUpdatedOnce() const;
	virtual bool IsEnabled() const;
	virtual void Event(uint16_t eType, SAIEVENT* pEvent);
	virtual void EntityEvent(const SEntityEvent& event);
	virtual unsigned GetAIObjectID() const;
	virtual void GetPhysicalSkipEntities(CryFixedArray<IPhysicalEntity *,32>& skipList) const;
	virtual void SetName(const char* pName);
	virtual const char* GetName() const;
	virtual uint16_t GetAIType() const;
	virtual IAIObject::ESubType GetSubType() const;
	virtual void SetType(uint16_t type);
	virtual void SetPos(const Vec3& pos, const Vec3& dirForw);
	virtual const Vec3& GetPos() const;
	virtual const Vec3 GetPosInNavigationMesh(const unsigned agentTypeID) const;
	virtual void SetRadius(float fRadius);
	virtual float GetRadius() const;
	virtual const Vec3& GetBodyDir() const;
	virtual void SetBodyDir(const Vec3& dir);
	virtual const Vec3& GetViewDir() const;
	virtual void SetViewDir(const Vec3& dir);
	virtual IAIObject::EFieldOfViewResult IsPointInFOV(const Vec3& pos, float distanceScale) const;
	virtual const Vec3& GetEntityDir() const;
	virtual void SetEntityDir(const Vec3& dir);
	virtual const Vec3& GetMoveDir() const;
	virtual void SetMoveDir(const Vec3& dir);
	virtual Vec3 GetVelocity() const;
	virtual uint64_t GetNavNodeIndex() const;
	virtual bool IsInTrackview() const;
	virtual void SetIsInTrackview(const bool _bInTrackview);
	virtual bool IsInExactPositioning() const;
	virtual void SetIsInExactPositioning(const bool _bIsInExactPositioning);
	virtual bool IsInGravShaft() const;
	virtual void SetIsInGravShaft(const bool _bIsInGravShaft);
	virtual void SetEntityID(unsigned ID);
	virtual unsigned GetEntityID() const;
	virtual IEntity* GetEntity() const;
	virtual void Serialize(TSerialize ser);
	virtual void PostSerialize();
	bool ShouldSerialize() const { return FShouldSerialize(this); }
	virtual void SetFirePos(const Vec3& pos);
	virtual const Vec3& GetFirePos() const;
	virtual IBlackBoard* GetBlackBoard();
	virtual bool IsHostile(const IAIObject* pOther, bool __unnamed1) const;
	virtual void SetThreateningForHostileFactions(const bool threatening);
	virtual bool IsThreateningForHostileFactions() const;
	virtual bool IsTargetable() const;
	virtual unsigned GetPerceivedEntityID() const;
	virtual void SetProxy(IAIActorProxy* proxy);
	virtual IAIActorProxy* GetProxy() const;
	virtual void RecordEvent(IAIRecordable::e_AIDbgEvent event, const IAIRecordable::RecorderEventData* pEventData);
	virtual void RecordSnapshot();
	virtual IAIDebugRecord* GetAIDebugRecord();
	virtual void Update(EObjectUpdate type);
	virtual void UpdateProxy(EObjectUpdate type);
	virtual void UpdateDisabled(EObjectUpdate type);
	virtual IPhysicalEntity* GetPhysics(bool bWantCharacterPhysics) const;
	virtual void SetFireDir(const Vec3& dir);
	virtual const Vec3& GetFireDir() const;
	virtual const Vec3& GetShootAtPos() const;
	virtual CWeakRef<CAIObject> GetAssociation() const;
	virtual void SetAssociation(CWeakRef<CAIObject> refAssociation);
	virtual void OnObjectRemoved(CAIObject* pObject);
	Vec3 GetPhysicsPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPhysicsPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	virtual void SetExpectedPhysicsPos(const Vec3& pos);
	void SetSubType(IAIObject::ESubType subType) { FSetSubType(this, subType); }
	virtual const CAIObject* CastToCAIObject() const;
	virtual CAIObject* CastToCAIObject();

#if 0
	void SetShouldSerialize(bool _arg0_);
	bool IsFromPool() const;
	const Vec3& GetLastPosition();
	const char* GetEventName(uint16_t _arg0_) const;
	uint16_t GetType() const;
	void SetSelfReference(CWeakRef<CAIObject> _arg0_);
	CWeakRef<CAIObject> GetSelfReference() const;
	bool HasSelfReference() const;
	void SetVisionID(const VisionID& _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FCAIObjectOv1 = PreyFunction<void(CAIObject* const _this)>(0x7048E0);
	static inline auto FBitNotCAIObject = PreyFunction<void(CAIObject* const _this)>(0x704990);
	static inline auto FReset = PreyFunction<void(CAIObject* const _this, EObjectResetType type)>(0x7050C0);
	static inline auto FRelease = PreyFunction<void(CAIObject* const _this)>(0x705090);
	static inline auto FIsUpdatedOnce = PreyFunction<bool(const CAIObject* const _this)>(0x705080);
	static inline auto FIsEnabled = PreyFunction<bool(const CAIObject* const _this)>(0x10DE2E0);
	static inline auto FEvent = PreyFunction<void(CAIObject* const _this, uint16_t eType, SAIEVENT* pEvent)>(0x704A50);
	static inline auto FEntityEvent = PreyFunction<void(CAIObject* const _this, const SEntityEvent& event)>(0xA13080);
	static inline auto FGetAIObjectID = PreyFunction<unsigned(const CAIObject* const _this)>(0xEB9170);
	static inline auto FGetPhysicalSkipEntities = PreyFunction<void(const CAIObject* const _this, CryFixedArray<IPhysicalEntity *,32>& skipList)>(0x704AD0);
	static inline auto FSetName = PreyFunction<void(CAIObject* const _this, const char* pName)>(0x706130);
	static inline auto FGetName = PreyFunction<const char* (const CAIObject* const _this)>(0x11A67A0);
	static inline auto FGetAIType = PreyFunction<uint16_t(const CAIObject* const _this)>(0x704A80);
	static inline auto FGetSubType = PreyFunction<IAIObject::ESubType(const CAIObject* const _this)>(0xD9C610);
	static inline auto FSetType = PreyFunction<void(CAIObject* const _this, uint16_t type)>(0x7062C0);
	static inline auto FSetPos = PreyFunction<void(CAIObject* const _this, const Vec3& pos, const Vec3& dirForw)>(0x706160);
	static inline auto FGetPos = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x704CA0);
	static inline auto FGetPosInNavigationMesh = PreyFunction<const Vec3*(const CAIObject* const _this, const Vec3* _return_value_, const unsigned agentTypeID)>(0x704CB0);
	static inline auto FSetRadius = PreyFunction<void(CAIObject* const _this, float fRadius)>(0x859AD0);
	static inline auto FGetRadius = PreyFunction<float(const CAIObject* const _this)>(0x855D80);
	static inline auto FGetBodyDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x12BDA90);
	static inline auto FSetBodyDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x706080);
	static inline auto FGetViewDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10BDA50);
	static inline auto FSetViewDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x7062D0);
	static inline auto FIsPointInFOV = PreyFunction<IAIObject::EFieldOfViewResult(const CAIObject* const _this, const Vec3& pos, float distanceScale)>(0x158AEF0);
	static inline auto FGetEntityDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x704AB0);
	static inline auto FSetEntityDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x706090);
	static inline auto FGetMoveDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10BD580);
	static inline auto FSetMoveDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x706120);
	static inline auto FGetVelocity = PreyFunction<Vec3*(const CAIObject* const _this, Vec3* _return_value_)>(0x704E80);
	static inline auto FGetNavNodeIndex = PreyFunction<uint64_t(const CAIObject* const _this)>(0x5E6280);
	static inline auto FIsInTrackview = PreyFunction<bool(const CAIObject* const _this)>(0x5E6C40);
	static inline auto FSetIsInTrackview = PreyFunction<void(CAIObject* const _this, const bool _bInTrackview)>(0x5E9780);
	static inline auto FIsInExactPositioning = PreyFunction<bool(const CAIObject* const _this)>(0x9F17B0);
	static inline auto FSetIsInExactPositioning = PreyFunction<void(CAIObject* const _this, const bool _bIsInExactPositioning)>(0x5E9760);
	static inline auto FIsInGravShaft = PreyFunction<bool(const CAIObject* const _this)>(0x6FDC40);
	static inline auto FSetIsInGravShaft = PreyFunction<void(CAIObject* const _this, const bool _bIsInGravShaft)>(0x5E9770);
	static inline auto FSetEntityID = PreyFunction<void(CAIObject* const _this, unsigned ID)>(0x7060A0);
	static inline auto FGetEntityID = PreyFunction<unsigned(const CAIObject* const _this)>(0x12380B0);
	static inline auto FGetEntity = PreyFunction<IEntity* (const CAIObject* const _this)>(0x704A90);
	static inline auto FSerialize = PreyFunction<void(CAIObject* const _this, TSerialize ser)>(0x705680);
	static inline auto FPostSerialize = PreyFunction<void(CAIObject* const _this)>(0xA13080);
	static inline auto FShouldSerialize = PreyFunction<bool(const CAIObject* const _this)>(0x7062E0);
	static inline auto FSetFirePos = PreyFunction<void(CAIObject* const _this, const Vec3& pos)>(0x706100);
	static inline auto FGetFirePos = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10BD540);
	static inline auto FGetBlackBoard = PreyFunction<IBlackBoard* (CAIObject* const _this)>(0x158AEF0);
	static inline auto FIsHostile = PreyFunction<bool(const CAIObject* const _this, const IAIObject* pOther, bool __unnamed1)>(0x704FB0);
	static inline auto FSetThreateningForHostileFactions = PreyFunction<void(CAIObject* const _this, const bool threatening)>(0x9FBC30);
	static inline auto FIsThreateningForHostileFactions = PreyFunction<bool(const CAIObject* const _this)>(0x350260);
	static inline auto FIsTargetable = PreyFunction<bool(const CAIObject* const _this)>(0x12E91B0);
	static inline auto FGetPerceivedEntityID = PreyFunction<unsigned(const CAIObject* const _this)>(0x704AC0);
	static inline auto FSetProxy = PreyFunction<void(CAIObject* const _this, IAIActorProxy* proxy)>(0xA13080);
	static inline auto FGetProxy = PreyFunction<IAIActorProxy* (const CAIObject* const _this)>(0x158AEF0);
	static inline auto FRecordEvent = PreyFunction<void(CAIObject* const _this, IAIRecordable::e_AIDbgEvent event, const IAIRecordable::RecorderEventData* pEventData)>(0xA13080);
	static inline auto FRecordSnapshot = PreyFunction<void(CAIObject* const _this)>(0xA13080);
	static inline auto FGetAIDebugRecord = PreyFunction<IAIDebugRecord* (CAIObject* const _this)>(0x158AEF0);
	static inline auto FUpdate = PreyFunction<void(CAIObject* const _this, EObjectUpdate type)>(0xA13080);
	static inline auto FUpdateProxy = PreyFunction<void(CAIObject* const _this, EObjectUpdate type)>(0xA13080);
	static inline auto FUpdateDisabled = PreyFunction<void(CAIObject* const _this, EObjectUpdate type)>(0xA13080);
	static inline auto FGetPhysics = PreyFunction<IPhysicalEntity* (const CAIObject* const _this, bool bWantCharacterPhysics)>(0x704BC0);
	static inline auto FSetFireDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x10BDE00);
	static inline auto FGetFireDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10BD810);
	static inline auto FGetShootAtPos = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10BDA70);
	static inline auto FGetAssociation = PreyFunction<CWeakRef<CAIObject>*(const CAIObject* const _this, CWeakRef<CAIObject>* _return_value_)>(0x5E5AC0);
	static inline auto FSetAssociation = PreyFunction<void(CAIObject* const _this, CWeakRef<CAIObject> refAssociation)>(0x706070);
	static inline auto FOnObjectRemoved = PreyFunction<void(CAIObject* const _this, CAIObject* pObject)>(0xA13080);
	static inline auto FGetPhysicsPos = PreyFunction<Vec3*(const CAIObject* const _this, Vec3* _return_value_)>(0x704BF0);
	static inline auto FSetExpectedPhysicsPos = PreyFunction<void(CAIObject* const _this, const Vec3& pos)>(0x7060B0);
	static inline auto FSetSubType = PreyFunction<void(CAIObject* const _this, IAIObject::ESubType subType)>(0x7062B0);
	static inline auto FCastToCAIObjectOv1 = PreyFunction<const CAIObject* (const CAIObject* const _this)>(0xC71190);
	static inline auto FCastToCAIObjectOv0 = PreyFunction<CAIObject* (CAIObject* const _this)>(0xC71190);
#else
	static inline auto FCAIObjectOv1 = PreyFunction<void(CAIObject* const _this)>(0x7205A0);
	static inline auto FBitNotCAIObject = PreyFunction<void(CAIObject* const _this)>(0x720650);
	static inline auto FReset = PreyFunction<void(CAIObject* const _this, EObjectResetType type)>(0x720DB0);
	static inline auto FRelease = PreyFunction<void(CAIObject* const _this)>(0x720D80);
	static inline auto FIsUpdatedOnce = PreyFunction<bool(const CAIObject* const _this)>(0x720D70);
	static inline auto FIsEnabled = PreyFunction<bool(const CAIObject* const _this)>(0x720C90);
	static inline auto FEvent = PreyFunction<void(CAIObject* const _this, uint16_t eType, SAIEVENT* pEvent)>(0x720710);
	static inline auto FEntityEvent = PreyFunction<void(CAIObject* const _this, const SEntityEvent& event)>(0x1333E90);
	static inline auto FGetAIObjectID = PreyFunction<unsigned(const CAIObject* const _this)>(0xA0CFE0);
	static inline auto FGetPhysicalSkipEntities = PreyFunction<void(const CAIObject* const _this, CryFixedArray<IPhysicalEntity *,32>& skipList)>(0x7207B0);
	static inline auto FSetName = PreyFunction<void(CAIObject* const _this, const char* pName)>(0x721E00);
	static inline auto FGetName = PreyFunction<const char* (const CAIObject* const _this)>(0x11C8520);
	static inline auto FGetAIType = PreyFunction<uint16_t(const CAIObject* const _this)>(0x720740);
	static inline auto FGetSubType = PreyFunction<IAIObject::ESubType(const CAIObject* const _this)>(0x11883D0);
	static inline auto FSetType = PreyFunction<void(CAIObject* const _this, uint16_t type)>(0x721F80);
	static inline auto FSetPos = PreyFunction<void(CAIObject* const _this, const Vec3& pos, const Vec3& dirForw)>(0x721E30);
	static inline auto FGetPos = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x720980);
	static inline auto FGetPosInNavigationMesh = PreyFunction<const Vec3*(const CAIObject* const _this, const Vec3* _return_value_, const unsigned agentTypeID)>(0x720990);
	static inline auto FSetRadius = PreyFunction<void(CAIObject* const _this, float fRadius)>(0x88A4E0);
	static inline auto FGetRadius = PreyFunction<float(const CAIObject* const _this)>(0x8716E0);
	static inline auto FGetBodyDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x1368F30);
	static inline auto FSetBodyDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x10ED520);
	static inline auto FGetViewDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10ED470);
	static inline auto FSetViewDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x10ED8C0);
	static inline auto FIsPointInFOV = PreyFunction<IAIObject::EFieldOfViewResult(const CAIObject* const _this, const Vec3& pos, float distanceScale)>(0x1CBB0B0);
	static inline auto FGetEntityDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x1368F40);
	static inline auto FSetEntityDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x721D70);
	static inline auto FGetMoveDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10ED250);
	static inline auto FSetMoveDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x721DF0);
	static inline auto FGetVelocity = PreyFunction<Vec3*(const CAIObject* const _this, Vec3* _return_value_)>(0x720B60);
	static inline auto FGetNavNodeIndex = PreyFunction<uint64_t(const CAIObject* const _this)>(0x720770);
	static inline auto FIsInTrackview = PreyFunction<bool(const CAIObject* const _this)>(0x600CC0);
	static inline auto FSetIsInTrackview = PreyFunction<void(CAIObject* const _this, const bool _bInTrackview)>(0x603760);
	static inline auto FIsInExactPositioning = PreyFunction<bool(const CAIObject* const _this)>(0xA0EC70);
	static inline auto FSetIsInExactPositioning = PreyFunction<void(CAIObject* const _this, const bool _bIsInExactPositioning)>(0xA0C640);
	static inline auto FIsInGravShaft = PreyFunction<bool(const CAIObject* const _this)>(0x600CB0);
	static inline auto FSetIsInGravShaft = PreyFunction<void(CAIObject* const _this, const bool _bIsInGravShaft)>(0x603750);
	static inline auto FSetEntityID = PreyFunction<void(CAIObject* const _this, unsigned ID)>(0x379640);
	static inline auto FGetEntityID = PreyFunction<unsigned(const CAIObject* const _this)>(0xD8FD10);
	static inline auto FGetEntity = PreyFunction<IEntity* (const CAIObject* const _this)>(0x720750);
	static inline auto FSerialize = PreyFunction<void(CAIObject* const _this, TSerialize ser)>(0x721370);
	static inline auto FPostSerialize = PreyFunction<void(CAIObject* const _this)>(0x1333E90);
	static inline auto FShouldSerialize = PreyFunction<bool(const CAIObject* const _this)>(0x721F90);
	static inline auto FSetFirePos = PreyFunction<void(CAIObject* const _this, const Vec3& pos)>(0x1028DB0);
	static inline auto FGetFirePos = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x13691E0);
	static inline auto FGetBlackBoard = PreyFunction<IBlackBoard* (CAIObject* const _this)>(0x1CBB0B0);
	static inline auto FIsHostile = PreyFunction<bool(const CAIObject* const _this, const IAIObject* pOther, bool __unnamed1)>(0x720CA0);
	static inline auto FSetThreateningForHostileFactions = PreyFunction<void(CAIObject* const _this, const bool threatening)>(0xA190B0);
	static inline auto FIsThreateningForHostileFactions = PreyFunction<bool(const CAIObject* const _this)>(0xA0ED40);
	static inline auto FIsTargetable = PreyFunction<bool(const CAIObject* const _this)>(0x127B6D0);
	static inline auto FGetPerceivedEntityID = PreyFunction<unsigned(const CAIObject* const _this)>(0x7207A0);
	static inline auto FSetProxy = PreyFunction<void(CAIObject* const _this, IAIActorProxy* proxy)>(0x1333E90);
	static inline auto FGetProxy = PreyFunction<IAIActorProxy* (const CAIObject* const _this)>(0x1CBB0B0);
	static inline auto FRecordEvent = PreyFunction<void(CAIObject* const _this, IAIRecordable::e_AIDbgEvent event, const IAIRecordable::RecorderEventData* pEventData)>(0x1333E90);
	static inline auto FRecordSnapshot = PreyFunction<void(CAIObject* const _this)>(0x1333E90);
	static inline auto FGetAIDebugRecord = PreyFunction<IAIDebugRecord* (CAIObject* const _this)>(0x1CBB0B0);
	static inline auto FUpdate = PreyFunction<void(CAIObject* const _this, EObjectUpdate type)>(0x1333E90);
	static inline auto FUpdateProxy = PreyFunction<void(CAIObject* const _this, EObjectUpdate type)>(0x1333E90);
	static inline auto FUpdateDisabled = PreyFunction<void(CAIObject* const _this, EObjectUpdate type)>(0x1333E90);
	static inline auto FGetPhysics = PreyFunction<IPhysicalEntity* (const CAIObject* const _this, bool bWantCharacterPhysics)>(0x7208A0);
	static inline auto FSetFireDir = PreyFunction<void(CAIObject* const _this, const Vec3& dir)>(0x721DD0);
	static inline auto FGetFireDir = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x10ED2A0);
	static inline auto FGetShootAtPos = PreyFunction<const Vec3& (const CAIObject* const _this)>(0x23E600);
	static inline auto FGetAssociation = PreyFunction<CWeakRef<CAIObject>*(const CAIObject* const _this, CWeakRef<CAIObject>* _return_value_)>(0x5FFB60);
	static inline auto FSetAssociation = PreyFunction<void(CAIObject* const _this, CWeakRef<CAIObject> refAssociation)>(0x721D60);
	static inline auto FOnObjectRemoved = PreyFunction<void(CAIObject* const _this, CAIObject* pObject)>(0x1333E90);
	static inline auto FGetPhysicsPos = PreyFunction<Vec3*(const CAIObject* const _this, Vec3* _return_value_)>(0x7208D0);
	static inline auto FSetExpectedPhysicsPos = PreyFunction<void(CAIObject* const _this, const Vec3& pos)>(0x721D80);
	static inline auto FSetSubType = PreyFunction<void(CAIObject* const _this, IAIObject::ESubType subType)>(0x141BB00);
	static inline auto FCastToCAIObjectOv1 = PreyFunction<const CAIObject* (const CAIObject* const _this)>(0x3DAC90);
	static inline auto FCastToCAIObjectOv0 = PreyFunction<CAIObject* (CAIObject* const _this)>(0x3DAC90);
#endif
};