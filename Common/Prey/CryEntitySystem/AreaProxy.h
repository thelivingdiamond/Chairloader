// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryEntitySystem/AreaProxy.h>
#include <Prey/CryEntitySystem/IEntityProxy.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/GameDll/ark/attention/ArkComplexAttentionObject.h>
#include <Prey/GameDll/ark/npc/ability/ArkNpcAbility.h>
#include <Prey/GameDll/ark/perception/ArkAttentiveSubject.h>
#include <Prey/GameDll/ark/perception/arkvisualperceiver.h>
#include <Chairloader/PreyFunction.h>

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

#ifndef MOONCRASH
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
#else
	static inline auto FResetTempState = PreyFunction<void()>(0x99DE90);
	static inline auto FCAreaProxyOv1 = PreyFunction<void(CAreaProxy* const _this)>(0x99CCD0);
	static inline auto FInitialize = PreyFunction<void(CAreaProxy* const _this, const IComponent::SComponentInitializer& init)>(0x99D260);
	static inline auto FProcessEvent = PreyFunction<void(CAreaProxy* const _this, SEntityEvent& event)>(0x99DAB0);
	static inline auto FGetType = PreyFunction<EEntityProxy(CAreaProxy* const _this)>(0x141A3D0);
	static inline auto FRelease = PreyFunction<void(CAreaProxy* const _this)>(0x3E3960);
	static inline auto FDone = PreyFunction<void(CAreaProxy* const _this)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CAreaProxy* const _this, SEntityUpdateContext& ctx)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CAreaProxy* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FReload = PreyFunction<void(CAreaProxy* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x99DE10);
	static inline auto FSerializeXML = PreyFunction<void(CAreaProxy* const _this, XmlNodeRef& entityNode, bool bLoading)>(0x99DEC0);
	static inline auto FSerialize = PreyFunction<void(CAreaProxy* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNeedSerialize = PreyFunction<bool(CAreaProxy* const _this)>(0x13B0900);
	static inline auto FGetSignature = PreyFunction<bool(CAreaProxy* const _this, TSerialize signature)>(0x99D200);
	static inline auto FSetFlags = PreyFunction<void(CAreaProxy* const _this, int nAreaProxyFlags)>(0x1508430);
	static inline auto FGetFlags = PreyFunction<int(CAreaProxy* const _this)>(0x19E84A0);
	static inline auto FGetAreaType = PreyFunction<EEntityAreaType(const CAreaProxy* const _this)>(0x99CFD0);
	static inline auto FSetPoints = PreyFunction<void(CAreaProxy* const _this, const Vec3* const vPoints, const bool* const pabSoundObstructionSegments, const int nPointsCount, const float fHeight)>(0x99F930);
	static inline auto FSetBox = PreyFunction<void(CAreaProxy* const _this, const Vec3& min, const Vec3& max, const bool* const pabSoundObstructionSides, const uint64_t nSideCount)>(0x99F650);
	static inline auto FSetSphere = PreyFunction<void(CAreaProxy* const _this, const Vec3& vCenter, float fRadius)>(0x99FBA0);
	static inline auto FBeginSettingSolid = PreyFunction<void(CAreaProxy* const _this, const Matrix34& worldTM)>(0x99CF20);
	static inline auto FAddConvexHullToSolid = PreyFunction<void(CAreaProxy* const _this, const Vec3* verticesOfConvexHull, bool bObstruction, int numberOfVertices)>(0x99CF10);
	static inline auto FEndSettingSolid = PreyFunction<void(CAreaProxy* const _this)>(0x99CFC0);
	static inline auto FGetPointsCount = PreyFunction<int(CAreaProxy* const _this)>(0x99D1B0);
	static inline auto FGetPoints = PreyFunction<const Vec3* (CAreaProxy* const _this)>(0x99D190);
	static inline auto FGetHeight = PreyFunction<float(CAreaProxy* const _this)>(0x99D030);
	static inline auto FGetBox = PreyFunction<void(CAreaProxy* const _this, Vec3& min, Vec3& max)>(0x99CFE0);
	static inline auto FGetSphere = PreyFunction<void(CAreaProxy* const _this, Vec3& vCenter, float& fRadius)>(0x99D230);
	static inline auto FSetGravityVolume = PreyFunction<void(CAreaProxy* const _this, const Vec3* pPoints, int nNumPoints, float fRadius, float fGravity, bool bDontDisableInvisible, float fFalloff, float fDamping)>(0x99F820);
	static inline auto FSetID = PreyFunction<void(CAreaProxy* const _this, const int id)>(0x99F920);
	static inline auto FGetID = PreyFunction<int(const CAreaProxy* const _this)>(0x99D040);
	static inline auto FSetGroup = PreyFunction<void(CAreaProxy* const _this, const int id)>(0x99F910);
	static inline auto FGetGroup = PreyFunction<int(const CAreaProxy* const _this)>(0x1B771A0);
	static inline auto FSetPriority = PreyFunction<void(CAreaProxy* const _this, const int nPriority)>(0x99FB70);
	static inline auto FGetPriority = PreyFunction<int(const CAreaProxy* const _this)>(0x99D1E0);
	static inline auto FSetSoundObstructionOnAreaFace = PreyFunction<void(CAreaProxy* const _this, const unsigned nFaceIndex, const bool bObstructs)>(0x99FB90);
	static inline auto FAddEntity = PreyFunction<void(CAreaProxy* const _this, unsigned id)>(0x1B76E70);
	static inline auto FClearEntities = PreyFunction<void(CAreaProxy* const _this)>(0x99CF90);
	static inline auto FSetProximity = PreyFunction<void(CAreaProxy* const _this, float prx)>(0x99FB80);
	static inline auto FGetProximity = PreyFunction<float(CAreaProxy* const _this)>(0x99D1F0);
	static inline auto FClosestPointOnHullDistSq = PreyFunction<float(CAreaProxy* const _this, const unsigned nEntityID, const Vec3& Point3d, Vec3& OnHull3d, bool bCacheResults)>(0x99CFA0);
	static inline auto FCalcPointNearDistSq = PreyFunction<float(CAreaProxy* const _this, const unsigned nEntityID, const Vec3& Point3d, Vec3& OnHull3d, bool bCacheResults)>(0x99CF50);
	static inline auto FCalcPointWithin = PreyFunction<bool(const CAreaProxy* const _this, const unsigned nEntityID, const Vec3& Point3d, const bool bIgnoreHeight, bool bCacheResults)>(0x99CF70);
	static inline auto FGetNumberOfEntitiesInArea = PreyFunction<uint64_t(const CAreaProxy* const _this)>(0x99D180);
	static inline auto FGetEntityInAreaByIdx = PreyFunction<unsigned(const CAreaProxy* const _this, uint64_t index)>(0x99D020);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAreaProxy* const _this, ICrySizer* pSizer)>(0x99D050);
	static inline auto FOnMove = PreyFunction<void(CAreaProxy* const _this)>(0x99D6C0);
	static inline auto FOnEnable = PreyFunction<void(CAreaProxy* const _this, bool bIsEnable, bool bIsCallScript)>(0x99D2F0);
	static inline auto FReadPolygonsForAreaSolid = PreyFunction<void(CAreaProxy* const _this, CCryFile& file, int numberOfPolygons, bool bObstruction)>(0x99DC60);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntityProxy.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryPhysics/physinterface.h>
#include <_unknown/IComponent.h>
#include <_unknown/SEntityPhysicalizeParams.h>

class CArea;
class CCryFile;
class CEntity;
enum EEntityAreaType;
enum EEntityProxy;
class ICrySizer;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
class XmlNodeRef;

// CAreaProxy
// Header:  CryEngine/cryentitysystem/AreaProxy.h
// Include: Prey/CryEntitySystem/AreaProxy.h
struct CAreaProxy : public IEntityAreaProxy
{ // Size=384 (0x180)
	using tSoundObstruction = std::vector<bool>;
	using tSoundObstructionIterConst = std::_Vb_const_iterator<std::_Wrap_alloc<std::allocator<unsigned int> > >;

	static inline auto s_tmpWorldPoints = PreyGlobal<std::vector<Vec3>>(0x28D5898);
	CEntity* m_pEntity;
	int m_nFlags;
	CArea* m_pArea;
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
	virtual void Initialize(const IComponent::SComponentInitializer& init);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual EEntityProxy GetType();
	virtual void Release();
	virtual void Done();
	virtual void Update(SEntityUpdateContext& ctx);
	virtual bool Init(IEntity* pEntity, SEntitySpawnParams& params);
	virtual void Reload(IEntity* pEntity, SEntitySpawnParams& params);
	virtual void SerializeXML(XmlNodeRef& entityNode, bool bLoading);
	virtual void Serialize(TSerialize ser);
	virtual bool NeedSerialize();
	virtual bool GetSignature(TSerialize signature);
	virtual void SetFlags(int nAreaProxyFlags);
	virtual int GetFlags();
	virtual EEntityAreaType GetAreaType() const;
	virtual void SetPoints(const Vec3* const vPoints, const bool* const pabSoundObstructionSegments, const int nPointsCount, const float fHeight);
	virtual void SetBox(const Vec3& min, const Vec3& max, const bool* const pabSoundObstructionSides, const uint64_t nSideCount);
	virtual void SetSphere(const Vec3& vCenter, float fRadius);
	virtual void BeginSettingSolid(const Matrix34& worldTM);
	virtual void AddConvexHullToSolid(const Vec3* verticesOfConvexHull, bool bObstruction, int numberOfVertices);
	virtual void EndSettingSolid();
	virtual int GetPointsCount();
	virtual const Vec3* GetPoints();
	virtual float GetHeight();
	virtual void GetBox(Vec3& min, Vec3& max);
	virtual void GetSphere(Vec3& vCenter, float& fRadius);
	virtual void SetGravityVolume(const Vec3* pPoints, int nNumPoints, float fRadius, float fGravity, bool bDontDisableInvisible, float fFalloff, float fDamping);
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
	virtual float ClosestPointOnHullDistSq(const unsigned nEntityID, const Vec3& Point3d, Vec3& OnHull3d, bool bCacheResults);
	virtual float CalcPointNearDistSq(const unsigned nEntityID, const Vec3& Point3d, Vec3& OnHull3d, bool bCacheResults);
	virtual bool CalcPointWithin(const unsigned nEntityID, const Vec3& Point3d, const bool bIgnoreHeight, bool bCacheResults) const;
	virtual uint64_t GetNumberOfEntitiesInArea() const;
	virtual unsigned GetEntityInAreaByIdx(uint64_t index) const;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	void OnMove() { FOnMove(this); }
	void OnEnable(bool bIsEnable, bool bIsCallScript) { FOnEnable(this, bIsEnable, bIsCallScript); }
	void ReadPolygonsForAreaSolid(CCryFile& file, int numberOfPolygons, bool bObstruction) { FReadPolygonsForAreaSolid(this, file, numberOfPolygons, bObstruction); }

#if 0
	CEntity* GetEntity() const;
	void Reset();
#endif

	static inline auto FResetTempState = PreyFunction<void()>(0x99DE90);
	static inline auto FCAreaProxyOv1 = PreyFunction<void(CAreaProxy* const _this)>(0x99CCD0);
	static inline auto FInitialize = PreyFunction<void(CAreaProxy* const _this, const IComponent::SComponentInitializer& init)>(0x99D260);
	static inline auto FProcessEvent = PreyFunction<void(CAreaProxy* const _this, SEntityEvent& event)>(0x99DAB0);
	static inline auto FGetType = PreyFunction<EEntityProxy(CAreaProxy* const _this)>(0x141A3D0);
	static inline auto FRelease = PreyFunction<void(CAreaProxy* const _this)>(0x3E3960);
	static inline auto FDone = PreyFunction<void(CAreaProxy* const _this)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CAreaProxy* const _this, SEntityUpdateContext& ctx)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CAreaProxy* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FReload = PreyFunction<void(CAreaProxy* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x99DE10);
	static inline auto FSerializeXML = PreyFunction<void(CAreaProxy* const _this, XmlNodeRef& entityNode, bool bLoading)>(0x99DEC0);
	static inline auto FSerialize = PreyFunction<void(CAreaProxy* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNeedSerialize = PreyFunction<bool(CAreaProxy* const _this)>(0x13B0900);
	static inline auto FGetSignature = PreyFunction<bool(CAreaProxy* const _this, TSerialize signature)>(0x99D200);
	static inline auto FSetFlags = PreyFunction<void(CAreaProxy* const _this, int nAreaProxyFlags)>(0x1508430);
	static inline auto FGetFlags = PreyFunction<int(CAreaProxy* const _this)>(0x19E84A0);
	static inline auto FGetAreaType = PreyFunction<EEntityAreaType(const CAreaProxy* const _this)>(0x99CFD0);
	static inline auto FSetPoints = PreyFunction<void(CAreaProxy* const _this, const Vec3* const vPoints, const bool* const pabSoundObstructionSegments, const int nPointsCount, const float fHeight)>(0x99F930);
	static inline auto FSetBox = PreyFunction<void(CAreaProxy* const _this, const Vec3& min, const Vec3& max, const bool* const pabSoundObstructionSides, const uint64_t nSideCount)>(0x99F650);
	static inline auto FSetSphere = PreyFunction<void(CAreaProxy* const _this, const Vec3& vCenter, float fRadius)>(0x99FBA0);
	static inline auto FBeginSettingSolid = PreyFunction<void(CAreaProxy* const _this, const Matrix34& worldTM)>(0x99CF20);
	static inline auto FAddConvexHullToSolid = PreyFunction<void(CAreaProxy* const _this, const Vec3* verticesOfConvexHull, bool bObstruction, int numberOfVertices)>(0x99CF10);
	static inline auto FEndSettingSolid = PreyFunction<void(CAreaProxy* const _this)>(0x99CFC0);
	static inline auto FGetPointsCount = PreyFunction<int(CAreaProxy* const _this)>(0x99D1B0);
	static inline auto FGetPoints = PreyFunction<const Vec3* (CAreaProxy* const _this)>(0x99D190);
	static inline auto FGetHeight = PreyFunction<float(CAreaProxy* const _this)>(0x99D030);
	static inline auto FGetBox = PreyFunction<void(CAreaProxy* const _this, Vec3& min, Vec3& max)>(0x99CFE0);
	static inline auto FGetSphere = PreyFunction<void(CAreaProxy* const _this, Vec3& vCenter, float& fRadius)>(0x99D230);
	static inline auto FSetGravityVolume = PreyFunction<void(CAreaProxy* const _this, const Vec3* pPoints, int nNumPoints, float fRadius, float fGravity, bool bDontDisableInvisible, float fFalloff, float fDamping)>(0x99F820);
	static inline auto FSetID = PreyFunction<void(CAreaProxy* const _this, const int id)>(0x99F920);
	static inline auto FGetID = PreyFunction<int(const CAreaProxy* const _this)>(0x99D040);
	static inline auto FSetGroup = PreyFunction<void(CAreaProxy* const _this, const int id)>(0x99F910);
	static inline auto FGetGroup = PreyFunction<int(const CAreaProxy* const _this)>(0x1B771A0);
	static inline auto FSetPriority = PreyFunction<void(CAreaProxy* const _this, const int nPriority)>(0x99FB70);
	static inline auto FGetPriority = PreyFunction<int(const CAreaProxy* const _this)>(0x99D1E0);
	static inline auto FSetSoundObstructionOnAreaFace = PreyFunction<void(CAreaProxy* const _this, const unsigned nFaceIndex, const bool bObstructs)>(0x99FB90);
	static inline auto FAddEntity = PreyFunction<void(CAreaProxy* const _this, unsigned id)>(0x1B76E70);
	static inline auto FClearEntities = PreyFunction<void(CAreaProxy* const _this)>(0x99CF90);
	static inline auto FSetProximity = PreyFunction<void(CAreaProxy* const _this, float prx)>(0x99FB80);
	static inline auto FGetProximity = PreyFunction<float(CAreaProxy* const _this)>(0x99D1F0);
	static inline auto FClosestPointOnHullDistSq = PreyFunction<float(CAreaProxy* const _this, const unsigned nEntityID, const Vec3& Point3d, Vec3& OnHull3d, bool bCacheResults)>(0x99CFA0);
	static inline auto FCalcPointNearDistSq = PreyFunction<float(CAreaProxy* const _this, const unsigned nEntityID, const Vec3& Point3d, Vec3& OnHull3d, bool bCacheResults)>(0x99CF50);
	static inline auto FCalcPointWithin = PreyFunction<bool(const CAreaProxy* const _this, const unsigned nEntityID, const Vec3& Point3d, const bool bIgnoreHeight, bool bCacheResults)>(0x99CF70);
	static inline auto FGetNumberOfEntitiesInArea = PreyFunction<uint64_t(const CAreaProxy* const _this)>(0x99D180);
	static inline auto FGetEntityInAreaByIdx = PreyFunction<unsigned(const CAreaProxy* const _this, uint64_t index)>(0x99D020);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAreaProxy* const _this, ICrySizer* pSizer)>(0x99D050);
	static inline auto FOnMove = PreyFunction<void(CAreaProxy* const _this)>(0x99D6C0);
	static inline auto FOnEnable = PreyFunction<void(CAreaProxy* const _this, bool bIsEnable, bool bIsCallScript)>(0x99D2F0);
	static inline auto FReadPolygonsForAreaSolid = PreyFunction<void(CAreaProxy* const _this, CCryFile& file, int numberOfPolygons, bool bObstruction)>(0x99DC60);
};
#endif // !MOONCRASH
