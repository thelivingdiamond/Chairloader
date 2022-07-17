#pragma once
#include "IProxy.h"
#include "Prey/Cry3DEngine/I3DEngine.h"
#include "Prey/CryRenderer/IRenderer.h"

class IAttachment;
class IAttachmentManager
{
public:
	virtual ~IAttachmentManager() = 0;
	virtual unsigned int LoadAttachmentList(const char*) = 0;
	virtual unsigned int SaveAttachmentList(const char*) = 0;
	virtual IAttachment* CreateAttachment(const char*, unsigned int, const char*, bool) = 0;
	virtual int RemoveAttachmentByInterface(const IAttachment*, unsigned int) = 0;
	virtual int RemoveAttachmentByName(const char*, unsigned int) = 0;
	virtual int RemoveAttachmentByNameCRC(unsigned int, unsigned int) = 0;
	virtual IAttachment* GetInterfaceByName(const char*) = 0;
	virtual IAttachment* GetInterfaceByIndex(unsigned int) = 0;
	virtual IAttachment* GetInterfaceByNameCRC(unsigned int) = 0;
	virtual int GetAttachmentCount() = 0;
	virtual int GetIndexByName(const char*) = 0;
	virtual int GetIndexByNameCRC(unsigned int) = 0;
	virtual unsigned int ProjectAllAttachment() = 0;
	virtual void PhysicalizeAttachment(int, IPhysicalEntity*, int) = 0;
	virtual void DephysicalizeAttachment(int, IPhysicalEntity*) = 0;
	virtual ICharacterInstance* GetSkelInstance() = 0;
	virtual int GetProxyCount() = 0;
	virtual IProxy* CreateProxy(const char*, const char*) = 0;
	virtual IProxy* GetProxyInterfaceByIndex(unsigned int) = 0;
	virtual IProxy* GetProxyInterfaceByName(const char*) = 0;
	virtual IProxy* GetProxyInterfaceByCRC(unsigned int) = 0;
	virtual int GetProxyIndexByName(const char*) = 0;
	virtual int RemoveProxyByInterface(const IProxy*) = 0;
	virtual int RemoveProxyByName(const char*) = 0;
	virtual int RemoveProxyByNameCRC(unsigned int) = 0;
	virtual void DrawProxies(unsigned int) = 0;
	virtual unsigned int GetProcFunctionCount() = 0;
	virtual const char* GetProcFunctionName(unsigned int) = 0;


};

class ISkin
{
public:
	virtual ~ISkin() = 0;
	virtual void PrecacheMesh(bool, int, int) = 0;
	virtual IRenderMesh* GetIRenderMesh(unsigned int) = 0;
	virtual const char* GetModelFilePath() = 0;
	virtual IMaterial* GetIMaterial(unsigned int) = 0;
	virtual unsigned int GetNumLODs() = 0;


};
class IVertexAnimation
{
public:
	virtual ~IVertexAnimation() = 0;
	virtual void SetFrameWeightByName(const ISkin*, const char*, float) = 0;
	virtual void ClearAllFramesWeight() = 0;


};
class IAttachmentSkin
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ISkin* GetISkin() = 0;
	virtual IVertexAnimation* GetIVertexAnimation() = 0;
	virtual float GetExtent(EGeomForm) = 0;
	virtual void GetRandomPos(PosNorm*, EGeomForm) = 0;
	virtual void GetMemoryUsage(ICrySizer*) = 0;
	virtual void ComputeGeometricMean(SMeshLodInfo*) = 0;
	virtual virtual ~IAttachmentSkin() = 0;


};
class IAttachmentObject
{
public:
	enum EType
	{
		eAttachment_Unknown = 0,
		eAttachment_StatObj = 1,
		eAttachment_Skeleton = 2,
		eAttachment_SkinMesh = 3,
		eAttachment_Entity = 4,
		eAttachment_Light = 5,
		eAttachment_Effect = 6,
		eAttachment_MultiEffect = 7
	};
	virtual ~IAttachmentObject() = 0;
	virtual IAttachmentObject::EType GetAttachmentType() = 0;
	virtual void ProcessAttachment(IAttachment*) = 0;
	virtual void RenderAttachment(SRendParams*, const SRenderingPassInfo*) = 0;
	virtual bool PhysicalizeAttachment(IAttachmentManager*, int, int, IPhysicalEntity*, const Vec3_tpl<float>*) = 0;
	virtual bool UpdatePhysicalizedAttachment(IAttachmentManager*, int, IPhysicalEntity*, const QuatT_tpl<float>*) = 0;
	virtual AABB* GetAABB(AABB* result) = 0;
	virtual float GetRadiusSqr() = 0;
	virtual IStatObj* GetIStatObj() = 0;
	virtual ICharacterInstance* GetICharacterInstance() = 0;
	virtual IAttachmentSkin* GetIAttachmentSkin() = 0;
	virtual const char* GetObjectFilePath() = 0;
	virtual IMaterial* GetBaseMaterial(unsigned int) = 0;
	virtual void SetReplacementMaterial(IMaterial*, unsigned int) = 0;
	virtual IMaterial* GetReplacementMaterial(unsigned int) = 0;
	virtual void OnRemoveAttachment(IAttachmentManager*, int) = 0;
	virtual void Release() = 0;


};
class SimulationParams
{
	enum ClampType
	{
		DISABLED = 0,
		PENDULUM_CONE = 1,
		PENDULUM_HINGE_PLANE = 2,
		PENDULUM_HALF_CONE = 3,
		SPRING_ELLIPSOID = 4
	};
	SimulationParams::ClampType m_nClampType;
	bool m_useDebug;
	bool m_useSimulation;
	bool m_useRedirect;
	unsigned __int8 m_nSimFPS;
	float m_fMaxDeg;
	float m_fHRotation;
	float m_fScaleZP;
	float m_fScaleZN;
	float m_fMass;
	float m_fGravity;
	float m_fDamping;
	float m_fStiffness;
	Vec3_tpl<float> m_vPivotOffset;
	Vec3_tpl<float> m_vSimulationAxis;
	Vec3_tpl<float> m_vStiffnessTarget;
	Vec2_tpl<float> m_vCapsule;
	unsigned int m_crcProcFunction;
	unsigned __int8 m_nProjectionType;
	DynArray<unsigned int, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_arrProxyCRC32;
	DynArray<CryStringT<char>, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_arrProxyName;
};
class IAttachment
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual const char* GetName() = 0;
	virtual unsigned int GetNameCRC() = 0;
	virtual unsigned int ReName(const char*, unsigned int) = 0;
	virtual unsigned int GetType() = 0;
	virtual unsigned int SetJointName(const char*) = 0;
	virtual void SetFlags(unsigned int) = 0;
	virtual unsigned int GetFlags() = 0;
	virtual void SetAttAbsoluteDefault(const QuatT_tpl<float>*) = 0;
	virtual const QuatT_tpl<float>* GetAttAbsoluteDefault() = 0;
	virtual void SetAttRelativeDefault(const QuatT_tpl<float>*) = 0;
	virtual const QuatT_tpl<float>* GetAttRelativeDefault() = 0;
	virtual const QuatT_tpl<float>* GetAttModelRelative() = 0;
	virtual const QuatTS_tpl<float>* GetAttWorldAbsolute(const QuatTS_tpl<float>* result) = 0;
	virtual void UpdateAttModelRelative() = 0;
	virtual unsigned int ProjectAttachment() = 0;
	virtual void HideAttachment(unsigned int) = 0;
	virtual unsigned int IsAttachmentHidden() = 0;
	virtual void HideInRecursion(unsigned int) = 0;
	virtual unsigned int IsAttachmentHiddenInRecursion() = 0;
	virtual void HideInShadow(unsigned int) = 0;
	virtual unsigned int IsAttachmentHiddenInShadow() = 0;
	virtual void AlignJointAttachment() = 0;
	virtual unsigned int GetJointID() = 0;
	virtual IAttachmentObject* GetIAttachmentObject() = 0;
	virtual IAttachmentSkin* GetIAttachmentSkin() = 0;
	virtual unsigned int AddBinding(IAttachmentObject*, ISkin*, unsigned int) = 0;
	virtual void ClearBinding(unsigned int) = 0;
	virtual unsigned int SwapBinding(IAttachment*) = 0;
	virtual SimulationParams* GetSimulationParams(SimulationParams* result) = 0;
	virtual void SetSimulationParams(const SimulationParams*) = 0;
	virtual unsigned __int64 SizeOfThis() = 0;
	virtual void Serialize(CSerializeWrapper<ISerialize>) = 0;
	virtual void GetMemoryUsage(ICrySizer*) = 0;
	virtual virtual ~IAttachment() = 0;


};