// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryEntitySystem/AreaProxy.h>
#include <Prey/CryEntitySystem/IEntityProxy.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/GameDll/ark/attention/arkcomplexattentionobject.h>
#include <Prey/GameDll/ark/npc/ability/arknpcability.h>
#include <Prey/GameDll/ark/perception/ArkAttentiveSubject.h>
#include <Prey/GameDll/ark/perception/arkvisualperceiver.h>
#include <ChairLoader/PreyFunction.h>

struct ArkAttentionLevelChange;
struct ArkComplexAuralPerceptionInfo;
struct ArkComplexRoomPerceptionInfo;
struct ArkComplexVisualPerceptionInfo;
class ArkNpc;
struct ArkSimpleAuralPerceptionInfo;
class CArea;
class CCryFile;
class CEntity;
class IComponent;
class ICrySizer;
struct IEntity;
struct IPhysicalEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
class XmlNodeRef;

// Header: Exact
// CryEngine/cryentitysystem/areaproxy.h
struct CAreaProxy : public IEntityAreaProxy // Id=800CC9E Size=384
{
	static std::vector<Vec3> s_tmpWorldPoints;
	CEntity *m_pEntity;
	int m_nFlags;
	
	using tSoundObstruction = std::vector<bool>;
	using tSoundObstructionIterConst = std::_Vb_const_iterator<std::_Wrap_alloc<std::allocator<unsigned int> > >;
	
	CArea *m_pArea;
	std::vector<Vec3> m_localPoints;
	std::vector<bool> m_abObstructSound;
	Vec3 m_vCenter;
	float m_fRadius;
	float m_fGravity;
	float m_fFalloff;
	float m_fDamping;
	float m_bDontDisableInvisible;
	pe_params_area m_gravityParams;
	std::vector<Vec3> m_bezierPoints;
	std::vector<Vec3> m_bezierPointsTmp;
	SEntityPhysicalizeParams::AreaDefinition m_areaDefinition;
	bool m_bIsEnable;
	bool m_bIsEnableInternal;
	float m_lastFrameTime;
	
	static void ResetTempState() { FResetTempState(); }
	CAreaProxy();
	virtual ~CAreaProxy();
	virtual void Initialize(IComponent::SComponentInitializer const &init);
	virtual void ProcessEvent(SEntityEvent &event);
	virtual EEntityProxy GetType();
	virtual void Release();
	virtual void Done();
	virtual void Update(SEntityUpdateContext &ctx);
	virtual bool Init(IEntity *pEntity, SEntitySpawnParams &params);
	virtual void Reload(IEntity *pEntity, SEntitySpawnParams &params);
	virtual void SerializeXML(XmlNodeRef &entityNode, bool bLoading);
	virtual void Serialize(TSerialize ser);
	virtual bool NeedSerialize();
	virtual bool GetSignature(TSerialize signature);
	virtual void SetFlags(int nAreaProxyFlags);
	virtual int GetFlags();
	virtual EEntityAreaType GetAreaType() const;
	virtual void SetPoints(Vec3 const *const vPoints, const bool *const pabSoundObstructionSegments, const int nPointsCount, const float fHeight);
	virtual void SetBox(Vec3 const &min, Vec3 const &max, const bool *const pabSoundObstructionSides, const uint64_t nSideCount);
	virtual void SetSphere(Vec3 const &vCenter, float fRadius);
	virtual void BeginSettingSolid(Matrix34 const &worldTM);
	virtual void AddConvexHullToSolid(Vec3 const *verticesOfConvexHull, bool bObstruction, int numberOfVertices);
	virtual void EndSettingSolid();
	virtual int GetPointsCount();
	virtual Vec3 const *GetPoints();
	virtual float GetHeight();
	virtual void GetBox(Vec3 &min, Vec3 &max);
	virtual void GetSphere(Vec3 &vCenter, float &fRadius);
	virtual void SetGravityVolume(Vec3 const *pPoints, int nNumPoints, float fRadius, float fGravity, bool bDontDisableInvisible, float fFalloff, float fDamping);
	virtual void SetID(const int id);
	virtual int GetID() const;
	virtual void SetGroup(const int id);
	virtual int GetGroup() const;
	virtual void SetPriority(const int nPriority);
	virtual int GetPriority() const;
	virtual void SetSoundObstructionOnAreaFace(const unsigned nFaceIndex, const bool bObstructs);
	virtual void AddEntity(unsigned id);
	virtual void ClearEntities();
	virtual void SetProximity(float prx);
	virtual float GetProximity();
	virtual float ClosestPointOnHullDistSq(const unsigned nEntityID, Vec3 const &Point3d, Vec3 &OnHull3d, bool bCacheResults);
	virtual float CalcPointNearDistSq(const unsigned nEntityID, Vec3 const &Point3d, Vec3 &OnHull3d, bool bCacheResults);
	virtual bool CalcPointWithin(const unsigned nEntityID, Vec3 const &Point3d, const bool bIgnoreHeight, bool bCacheResults) const;
	virtual uint64_t GetNumberOfEntitiesInArea() const;
	virtual unsigned GetEntityInAreaByIdx(uint64_t index) const;
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	void OnMove() { FOnMove(this); }
	void OnEnable(bool bIsEnable, bool bIsCallScript) { FOnEnable(this,bIsEnable,bIsCallScript); }
	void ReadPolygonsForAreaSolid(CCryFile &file, int numberOfPolygons, bool bObstruction) { FReadPolygonsForAreaSolid(this,file,numberOfPolygons,bObstruction); }
	
#if 0
	CEntity *GetEntity() const;
	void Reset();
#endif
	
	static inline auto FResetTempState = PreyFunction<void()>(0x981270);
	static inline auto FInitialize = PreyFunction<void(CAreaProxy *const _this, IComponent::SComponentInitializer const &init)>(0x980640);
	static inline auto FProcessEvent = PreyFunction<void(CAreaProxy *const _this, SEntityEvent &event)>(0x980E90);
	static inline auto FGetType = PreyFunction<EEntityProxy(CAreaProxy *const _this)>(0x133DF50);
	static inline auto FRelease = PreyFunction<void(CAreaProxy *const _this)>(0xA97D40);
	static inline auto FDone = PreyFunction<void(CAreaProxy *const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CAreaProxy *const _this, SEntityUpdateContext &ctx)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(CAreaProxy *const _this, IEntity *pEntity, SEntitySpawnParams &params)>(0x1B933B0);
	static inline auto FReload = PreyFunction<void(CAreaProxy *const _this, IEntity *pEntity, SEntitySpawnParams &params)>(0x9811F0);
	static inline auto FSerializeXML = PreyFunction<void(CAreaProxy *const _this, XmlNodeRef &entityNode, bool bLoading)>(0x9812A0);
	static inline auto FSerialize = PreyFunction<void(CAreaProxy *const _this, TSerialize ser)>(0xA13080);
	static inline auto FNeedSerialize = PreyFunction<bool(CAreaProxy *const _this)>(0xDD23F0);
	static inline auto FGetSignature = PreyFunction<bool(CAreaProxy *const _this, TSerialize signature)>(0x9805E0);
	static inline auto FSetFlags = PreyFunction<void(CAreaProxy *const _this, int nAreaProxyFlags)>(0x982C00);
	static inline auto FGetFlags = PreyFunction<int(CAreaProxy *const _this)>(0x18C0750);
	static inline auto FGetAreaType = PreyFunction<EEntityAreaType(CAreaProxy const *const _this)>(0x9803B0);
	static inline auto FSetPoints = PreyFunction<void(CAreaProxy *const _this, Vec3 const *const vPoints, const bool *const pabSoundObstructionSegments, const int nPointsCount, const float fHeight)>(0x982D20);
	static inline auto FSetBox = PreyFunction<void(CAreaProxy *const _this, Vec3 const &min, Vec3 const &max, const bool *const pabSoundObstructionSides, const uint64_t nSideCount)>(0x982A30);
	static inline auto FSetSphere = PreyFunction<void(CAreaProxy *const _this, Vec3 const &vCenter, float fRadius)>(0x982F90);
	static inline auto FBeginSettingSolid = PreyFunction<void(CAreaProxy *const _this, Matrix34 const &worldTM)>(0x980300);
	static inline auto FAddConvexHullToSolid = PreyFunction<void(CAreaProxy *const _this, Vec3 const *verticesOfConvexHull, bool bObstruction, int numberOfVertices)>(0x9802F0);
	static inline auto FEndSettingSolid = PreyFunction<void(CAreaProxy *const _this)>(0x9803A0);
	static inline auto FGetPointsCount = PreyFunction<int(CAreaProxy *const _this)>(0x980590);
	static inline auto FGetPoints = PreyFunction<Vec3 const *(CAreaProxy *const _this)>(0x980570);
	static inline auto FGetHeight = PreyFunction<float(CAreaProxy *const _this)>(0x980410);
	static inline auto FGetBox = PreyFunction<void(CAreaProxy *const _this, Vec3 &min, Vec3 &max)>(0x9803C0);
	static inline auto FGetSphere = PreyFunction<void(CAreaProxy *const _this, Vec3 &vCenter, float &fRadius)>(0x980610);
	static inline auto FSetGravityVolume = PreyFunction<void(CAreaProxy *const _this, Vec3 const *pPoints, int nNumPoints, float fRadius, float fGravity, bool bDontDisableInvisible, float fFalloff, float fDamping)>(0x982C10);
	static inline auto FSetID = PreyFunction<void(CAreaProxy *const _this, const int id)>(0x982D10);
	static inline auto FGetID = PreyFunction<int(CAreaProxy const *const _this)>(0x980420);
	static inline auto FSetGroup = PreyFunction<void(CAreaProxy *const _this, const int id)>(0x982D00);
	static inline auto FGetGroup = PreyFunction<int(CAreaProxy const *const _this)>(0x1A4F660);
	static inline auto FSetPriority = PreyFunction<void(CAreaProxy *const _this, const int nPriority)>(0x982F60);
	static inline auto FGetPriority = PreyFunction<int(CAreaProxy const *const _this)>(0x9805C0);
	static inline auto FSetSoundObstructionOnAreaFace = PreyFunction<void(CAreaProxy *const _this, const unsigned nFaceIndex, const bool bObstructs)>(0x982F80);
	static inline auto FAddEntity = PreyFunction<void(CAreaProxy *const _this, unsigned id)>(0x1A4F330);
	static inline auto FClearEntities = PreyFunction<void(CAreaProxy *const _this)>(0x980370);
	static inline auto FSetProximity = PreyFunction<void(CAreaProxy *const _this, float prx)>(0x982F70);
	static inline auto FGetProximity = PreyFunction<float(CAreaProxy *const _this)>(0x9805D0);
	static inline auto FClosestPointOnHullDistSq = PreyFunction<float(CAreaProxy *const _this, const unsigned nEntityID, Vec3 const &Point3d, Vec3 &OnHull3d, bool bCacheResults)>(0x980380);
	static inline auto FCalcPointNearDistSq = PreyFunction<float(CAreaProxy *const _this, const unsigned nEntityID, Vec3 const &Point3d, Vec3 &OnHull3d, bool bCacheResults)>(0x980330);
	static inline auto FCalcPointWithin = PreyFunction<bool(CAreaProxy const *const _this, const unsigned nEntityID, Vec3 const &Point3d, const bool bIgnoreHeight, bool bCacheResults)>(0x980350);
	static inline auto FGetNumberOfEntitiesInArea = PreyFunction<uint64_t(CAreaProxy const *const _this)>(0x980560);
	static inline auto FGetEntityInAreaByIdx = PreyFunction<unsigned(CAreaProxy const *const _this, uint64_t index)>(0x980400);
	static inline auto FGetMemoryUsage = PreyFunction<void(CAreaProxy const *const _this, ICrySizer *pSizer)>(0x980430);
	static inline auto FOnMove = PreyFunction<void(CAreaProxy *const _this)>(0x980AA0);
	static inline auto FOnEnable = PreyFunction<void(CAreaProxy *const _this, bool bIsEnable, bool bIsCallScript)>(0x9806D0);
	static inline auto FReadPolygonsForAreaSolid = PreyFunction<void(CAreaProxy *const _this, CCryFile &file, int numberOfPolygons, bool bObstruction)>(0x981040);
};

// Header: Exact
// CryEngine/cryentitysystem/areaproxy.h
class ArkNpcAttentiveSubject : public ArkAttentiveSubject, public ArkAuralPerceiver, public ArkVisualPerceiver, public ArkRoomPerceiver // Id=801430B Size=56
{
public:
	ArkNpc *m_pNpc;
	float m_complexHearingGain;
	float m_complexVisionGain;
	EArkNpcVisionDirection m_visionDirection;
	
	ArkNpcAttentiveSubject(ArkNpc &_npc);
	void EnableAttentiveSubject() { FEnableAttentiveSubject(this); }
	void DisableAttentiveSubject() { FDisableAttentiveSubject(this); }
	bool IsAttentiveSubjectEnabled() const { return FIsAttentiveSubjectEnabled(this); }
	void EnableAuralPerceiver() { FEnableAuralPerceiver(this); }
	void DisableAuralPerceiver() { FDisableAuralPerceiver(this); }
	bool IsAuralPerceiverEnabled() const { return FIsAuralPerceiverEnabled(this); }
	void EnableVisualPerceiver() { FEnableVisualPerceiver(this); }
	void DisableVisualPerceiver() { FDisableVisualPerceiver(this); }
	bool IsVisualPerceiverEnabled() const { return FIsVisualPerceiverEnabled(this); }
	void EnableRoomPerceiver() { FEnableRoomPerceiver(this); }
	void DisableRoomPerceiver() { FDisableRoomPerceiver(this); }
	bool IsRoomPerceiverEnabled() const { return FIsRoomPerceiverEnabled(this); }
	void SetComplexHearingGain(float _gain) { FSetComplexHearingGain(this,_gain); }
	float GetComplexHearingGain() const { return FGetComplexHearingGain(this); }
	void SetComplexVisionGain(float _gain) { FSetComplexVisionGain(this,_gain); }
	float GetComplexVisionGain() const { return FGetComplexVisionGain(this); }
	void SetVisionDirection(EArkNpcVisionDirection _visionDirection) { FSetVisionDirection(this,_visionDirection); }
	virtual unsigned DoGetEntityId() const;
	virtual uint64_t DoGetAttentionModelId() const;
	virtual void DoGetAttentiveSubjectInfo(bool &_bUpdateAttentionLevels, Vec3 &_position) const;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange);
	virtual void DoOnAttentionProxiesUpdated(const unsigned *_pFirstEntityId, const unsigned *_pLastEntityId);
	virtual Vec3 DoGetHearingPosition() const;
	virtual void DoUpdateAuralPerception(ArkSimpleAuralPerceptionInfo const *_pFirstSimpleAuralPerceptionInfo, ArkSimpleAuralPerceptionInfo const *_pLastSimpleAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pFirstComplexAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pLastComplexAuralPerceptionInfo);
	virtual uint64_t *DoGetVisionConeIds(uint64_t *_pFirstVisionConeId, uint64_t *_pLastVisionConeId) const;
	virtual ArkVisualPerceiverVisionParams DoGetVisionParams() const;
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const;
	virtual void DoUpdateVisualPerception(const unsigned *_pFirstSimpleStartPerceivingEntityId, const unsigned *_pFirstSimpleContinuePerceivingEntityId, const unsigned *_pFirstSimpleStopPerceivingEntityId, const unsigned *_pLastSimpleStopPerceivingEntityId, ArkComplexVisualPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pLastComplexPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId);
	virtual uint64_t DoGetRoomPerceptionModelId() const;
	virtual Vec3 DoGetRoomPosition() const;
	virtual unsigned DoGetRoomPerceiverEntityId() const;
	virtual unsigned DoFindCurrentRoomEntityId() const;
	virtual unsigned DoGetAreaContainerEntityId() const;
	virtual void DoUpdateRoomPerception(ArkComplexRoomPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexPContinuePerceivingPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId);
	
	static inline auto FEnableAttentiveSubject = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F5670);
	static inline auto FDisableAttentiveSubject = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F3700);
	static inline auto FIsAttentiveSubjectEnabled = PreyFunction<bool(ArkNpcAttentiveSubject const *const _this)>(0x13F5840);
	static inline auto FEnableAuralPerceiver = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F56E0);
	static inline auto FDisableAuralPerceiver = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F3720);
	static inline auto FIsAuralPerceiverEnabled = PreyFunction<bool(ArkNpcAttentiveSubject const *const _this)>(0x13F5860);
	static inline auto FEnableVisualPerceiver = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F5760);
	static inline auto FDisableVisualPerceiver = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F37F0);
	static inline auto FIsVisualPerceiverEnabled = PreyFunction<bool(ArkNpcAttentiveSubject const *const _this)>(0x13F58A0);
	static inline auto FEnableRoomPerceiver = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F5710);
	static inline auto FDisableRoomPerceiver = PreyFunction<void(ArkNpcAttentiveSubject *const _this)>(0x13F3780);
	static inline auto FIsRoomPerceiverEnabled = PreyFunction<bool(ArkNpcAttentiveSubject const *const _this)>(0x13F5880);
	static inline auto FSetComplexHearingGain = PreyFunction<void(ArkNpcAttentiveSubject *const _this, float _gain)>(0x13F58C0);
	static inline auto FGetComplexHearingGain = PreyFunction<float(ArkNpcAttentiveSubject const *const _this)>(0xEBF520);
	static inline auto FSetComplexVisionGain = PreyFunction<void(ArkNpcAttentiveSubject *const _this, float _gain)>(0x13F5920);
	static inline auto FGetComplexVisionGain = PreyFunction<float(ArkNpcAttentiveSubject const *const _this)>(0x13F5830);
	static inline auto FSetVisionDirection = PreyFunction<void(ArkNpcAttentiveSubject *const _this, EArkNpcVisionDirection _visionDirection)>(0x982C00);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkNpcAttentiveSubject const *const _this)>(0x13F3A90);
	static inline auto FDoGetAttentionModelId = PreyFunction<uint64_t(ArkNpcAttentiveSubject const *const _this)>(0x13F3890);
	static inline auto FDoGetAttentiveSubjectInfo = PreyFunction<void(ArkNpcAttentiveSubject const *const _this, bool &_bUpdateAttentionLevels, Vec3 &_position)>(0x13F3A30);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkNpcAttentiveSubject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x13F49C0);
	static inline auto FDoOnAttentionProxiesUpdated = PreyFunction<void(ArkNpcAttentiveSubject *const _this, const unsigned *_pFirstEntityId, const unsigned *_pLastEntityId)>(0x13F4AC0);
	static inline auto FDoGetHearingPosition = PreyFunction<Vec3(ArkNpcAttentiveSubject const *const _this)>(0x13F3AB0);
	static inline auto FDoUpdateAuralPerception = PreyFunction<void(ArkNpcAttentiveSubject *const _this, ArkSimpleAuralPerceptionInfo const *_pFirstSimpleAuralPerceptionInfo, ArkSimpleAuralPerceptionInfo const *_pLastSimpleAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pFirstComplexAuralPerceptionInfo, ArkComplexAuralPerceptionInfo const *_pLastComplexAuralPerceptionInfo)>(0x13F4B30);
	static inline auto FDoGetVisionConeIds = PreyFunction<uint64_t *(ArkNpcAttentiveSubject const *const _this, uint64_t *_pFirstVisionConeId, uint64_t *_pLastVisionConeId)>(0x13F3CC0);
	static inline auto FDoGetVisionParams = PreyFunction<ArkVisualPerceiverVisionParams(ArkNpcAttentiveSubject const *const _this)>(0x13F3E80);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkNpcAttentiveSubject const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x13F2B50);
	static inline auto FDoUpdateVisualPerception = PreyFunction<void(ArkNpcAttentiveSubject *const _this, const unsigned *_pFirstSimpleStartPerceivingEntityId, const unsigned *_pFirstSimpleContinuePerceivingEntityId, const unsigned *_pFirstSimpleStopPerceivingEntityId, const unsigned *_pLastSimpleStopPerceivingEntityId, ArkComplexVisualPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexVisualPerceptionInfo const *_pLastComplexPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId)>(0x13F5390);
	static inline auto FDoGetRoomPerceptionModelId = PreyFunction<uint64_t(ArkNpcAttentiveSubject const *const _this)>(0x13F3AF0);
	static inline auto FDoGetRoomPosition = PreyFunction<Vec3(ArkNpcAttentiveSubject const *const _this)>(0x13F3C90);
	static inline auto FDoGetRoomPerceiverEntityId = PreyFunction<unsigned(ArkNpcAttentiveSubject const *const _this)>(0x13F3AE0);
	static inline auto FDoFindCurrentRoomEntityId = PreyFunction<unsigned(ArkNpcAttentiveSubject const *const _this)>(0x13F3850);
	static inline auto FDoGetAreaContainerEntityId = PreyFunction<unsigned(ArkNpcAttentiveSubject const *const _this)>(0x13F3870);
	static inline auto FDoUpdateRoomPerception = PreyFunction<void(ArkNpcAttentiveSubject *const _this, ArkComplexRoomPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexPContinuePerceivingPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId)>(0x13F5170);
};

