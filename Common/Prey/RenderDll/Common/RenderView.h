// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Camera.h>
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryMath/Range.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryRenderer/IShader.h>
#include <Prey/RenderDll/Common/RenderItemDrawer.h>
#include <Prey/RenderDll/Common/Shadow_Renderer.h>
#include <Prey/RenderDll/Common/LockFreeAddVector.h>

class CCompiledRenderObject;
class CPermanentRenderObject;
class CREClientPoly;
class CREFogVolume;
class CRendElementBase;
class CRenderObject;
enum ERenderListID;
struct IClipVolume;
struct SDeferredDecal;
struct SGraphicsPipelinePassContext;
struct SRendItemSorter;
struct SRenderingPassInfo;
struct SShaderItem;
struct ShadowMapFrustum;
enum eDeferredLightType;

// SArkDeferredDecal
// Header:  _unknown/SArkDeferredDecal.h
struct SArkDeferredDecal
{ // Size=352 (0x160)
	SDeferredDecal source;
	STexState tsDiffuse;
	STexState tsDiffuse2;
	CTexture* pDiffuseTex;
	CTexture* pNormalsTex;
	CTexture* pSpecularTex;
	CTexture* pOpacityTex;
	CTexture* pDiffuse2Tex;
	CTexture* pNormals2Tex;
	CTexture* pSpecular2Tex;
	Matrix44 DiffuseTM;
	Vec4 DiffuseColor;
	Vec4 SpecularColor;
	float AlphaMultiplier;
	float Falloff;
	float DiffuseOpacity;
	float BlendFactor;
	float BlendFalloff;
	float BlendSpecular2;
	bool bHasNormalMap;
	bool bHasSpecMap;
	bool bHasOpacityMap;
	bool bHasBlend;
	bool bReady;
};

// SArkForwardDecal
// Header:  _unknown/SArkForwardDecal.h
struct SArkForwardDecal
{ // Size=336 (0x150)
	SDeferredDecal source;
	STexState tsEmittance;
	STexState tsEmittanceMask;
	CTexture* pEmittanceTex;
	CTexture* pEmittanceMaskTex;
	Matrix44 EmittanceTM;
	Matrix44 EmittanceMaskTM;
	Vec3 EmissiveColor;
	float EmittanceMapGamma;
	float Falloff;
	bool bHasEmiMaskMap;
	bool bReady;
};

// SArkClusteredDecal
// Header:  _unknown/SArkClusteredDecal.h
struct SArkClusteredDecal
{ // Size=192 (0xC0)
	SDeferredDecal source;
	CTexture* pDiffuseTex;
	CTexture* pNormalsTex;
	CTexture* pOpacityTex;
	CTexture* pEmittanceTex;
	Vec3 TexU;
	Vec3 TexV;
	Vec4 DiffuseColor;
	Vec3 EmissiveColor;
	float Falloff;
	float AlphaRef;
	bool bReady;
};

// SArkScreenBounds
// Header:  _unknown/SArkScreenBounds.h
struct SArkScreenBounds
{ // Size=4 (0x4)
	unsigned minx : 8;
	unsigned miny : 8;
	unsigned maxx : 8;
	unsigned maxy : 8;

#if 0
	SArkScreenBounds();
#endif
};

// CRenderView
// Header:  CryEngine/renderdll/common/RenderView.h
// Include: Prey/RenderDll/Common/RenderView.h
class CRenderView : public IRenderView
{ // Size=6784 (0x1A80)
public:
	enum eShadowFrustumRenderType
	{
		eShadowFrustumRenderType_SunCached = 0,
		eShadowFrustumRenderType_SunDynamic = 2,
		eShadowFrustumRenderType_LocalLight = 3,
		eShadowFrustumRenderType_Custom = 4,
		eShadowFrustumRenderType_Count = 5,
		eShadowFrustumRenderType_First = 0,
	};

	// CRenderView::SCompiledPair
	// Header:  CryEngine/renderdll/common/RenderView.h
	struct SCompiledPair
	{ // Size=16 (0x10)
		CRenderObject* pRenderObject;
		CCompiledRenderObject* pCompiledObject;
	};

	// CRenderView::SPermanentObjectRecord
	// Header:  CryEngine/renderdll/common/RenderView.h
	struct SPermanentObjectRecord
	{ // Size=24 (0x18)
		CPermanentRenderObject* pRenderObject;
		float distance;
		unsigned itemSorter;
		int shadowFrustumSide;
	};

	// CRenderView::SShadows
	// Header:  CryEngine/renderdll/common/RenderView.h
	struct SShadows
	{ // Size=384 (0x180)
		ShadowMapFrustum* m_pShadowFrustumOwner;
		std::vector<SShadowFrustumToRender> m_renderFrustums;
		std::map<int, std::vector<SShadowFrustumToRender*>> m_frustumsByLight;
		std::array<std::vector<SShadowFrustumToRender*>, 5> m_frustumsByType;
		CThreadSafeRendererContainer<AABB> m_nearestCasterBoxes;

		void AddNearestCaster(CRenderObject* pObj) { FAddNearestCaster(this, pObj); }
		void CreateFrustumGroups() { FCreateFrustumGroups(this); }
		void PrepareNearestShadows() { FPrepareNearestShadows(this); }

#if 0
		void Clear();
#endif

		static inline auto FAddNearestCaster = PreyFunction<void(CRenderView::SShadows* const _this, CRenderObject * pObj)>(0xEB6A30);
		static inline auto FCreateFrustumGroups = PreyFunction<void(CRenderView::SShadows* const _this)>(0xEB8460);
		static inline auto FPrepareNearestShadows = PreyFunction<void(CRenderView::SShadows* const _this)>(0xEBB340);
	};

	using ItemsRange = TRange<int>;
	using ShadowFrustums = std::vector<SShadowFrustumToRender>;
	using ShadowFrustumsPtr = std::vector<SShadowFrustumToRender*>;
	using ModifiedObjects = lockfree_add_vector<CRenderObject*>;

	static constexpr const int MaxFogVolumeNum = 64;
	IRenderView::EUsageMode m_usageMode;
	IRenderView::EViewType m_viewType;
	string m_name;
	unsigned m_nSkipRenderingFlags;
	unsigned m_nShaderRenderingFlags;
	uint64_t m_frameId;
	CRenderView* m_pParentView;
	lockfree_add_vector<SRendItem> m_renderItems[25];
	volatile unsigned m_BatchFlags[25];
	std::vector<SRenderLight> m_lights[4];
	std::vector<SDeferredClipVolume> m_clipVolumes;
	std::vector<SFogVolumeInfo> m_fogVolumes[2];
	std::vector<CREClientPoly*> m_polygonsPool;
	int m_numUsedClientPolygons;
	std::vector<SArkDeferredDecal> m_deferredDecals;
	std::vector<SArkForwardDecal> m_forwardDecals;
	std::vector<SArkClusteredDecal> m_clusteredDecals;
	bool m_bLookingGlassEnabled;
	bool m_bLookingGlassMaskEnabled;
	bool m_bLookingGlassMaskShouldRender;
	bool m_bLookingGlassScene1Only;
	uint8_t m_nSceneMaskFilter;
	unsigned m_nBatchSceneMasks;
	SArkScreenBounds m_distortBounds;
	bool m_bTrackUncompiledItems;
	bool m_bAddingClientPolys;
	lockfree_add_vector<CPermanentRenderObject*> m_permanentRenderObjectsToCompile;
	lockfree_add_vector<CRenderView::SCompiledPair> m_temporaryCompiledObjects;
	std::vector<std::pair<CShaderResources*, CShader*>> m_shaderItemsToUpdate;
	lockfree_add_vector<CRenderView::SPermanentObjectRecord> m_permanentObjects;
	CCamera m_camera;
	CCamera m_previousCamera;
	CRenderCamera m_renderCamera;
	JobManager::SJobState m_jobstate_Sort;
	JobManager::SJobState m_jobstate_PostWrite;
	JobManager::SJobStateLambda m_jobstate_Write;
	JobManager::SJobStateLambda m_jobstate_ShadowGen;
	CryCriticalSectionNonRecursive m_lock_UsageMode;
	CryCriticalSectionNonRecursive m_lock_PostWrite;
	volatile int m_bPostWriteExecuted;
	CRenderView::SShadows m_shadows;
	CRenderItemDrawer m_RenderItemDrawer;

	virtual void SetFrameId(uint64_t frameId);
	virtual uint64_t GetFrameId() const;
	virtual void SetSkipRenderingFlags(unsigned nFlags);
	virtual unsigned GetSkipRenderingFlags() const;
	virtual void SetShaderRenderingFlags(unsigned nFlags);
	virtual unsigned GetShaderRenderingFlags() const;
	virtual void SetCamera(const CCamera& cam);
	virtual void SetPreviousFrameCamera(const CCamera& _camera);
	virtual void SwitchUsageMode(IRenderView::EUsageMode mode);
	virtual JobManager::SJobState* GetWriteMutex();
	virtual void AddPermanentObject(CRenderObject* pObject, float _fDistance, const SRenderingPassInfo& passInfo);
	CRenderView(const char* name, IRenderView::EViewType type, CRenderView* pParentView, ShadowMapFrustum* pShadowFrustumOwner);
	virtual ~CRenderView();
	lockfree_add_vector<SRendItem>& GetRenderItems(int nRenderList) { return FGetRenderItems(this, nRenderList); }
	unsigned GetBatchFlags(int nRenderList) const { return FGetBatchFlags(this, nRenderList); }
	void AddRenderItem(CRendElementBase* pElem, CRenderObject* pObj, const SShaderItem& shaderItem, unsigned nList, unsigned nBatchFlags, float _fDistance, SRendItemSorter sorter, bool bShadowPass, bool bForceOpaqueForward) { FAddRenderItem(this, pElem, pObj, shaderItem, nList, nBatchFlags, _fDistance, sorter, bShadowPass, bForceOpaqueForward); }
	void AddPermanentObjectInline(CPermanentRenderObject* pObject, float _fDistance, SRendItemSorter sorter, int shadowFrustumSide) { FAddPermanentObjectInline(this, pObject, _fDistance, sorter, shadowFrustumSide); }
	int FindRenderListSplit(ERenderListID list, unsigned objFlag) { return FFindRenderListSplit(this, list, objFlag); }
	void PrepareForWriting() { FPrepareForWriting(this); }
	void AddShadowFrustumToRender(const SShadowFrustumToRender& frustum) { FAddShadowFrustumToRender(this, frustum); }
	std::vector<SShadowFrustumToRender*>& GetShadowFrustumsForLight(int lightId) { return FGetShadowFrustumsForLight(this, lightId); }
	std::vector<SShadowFrustumToRender*>& GetShadowFrustumsByType(CRenderView::eShadowFrustumRenderType type) { return FGetShadowFrustumsByType(this, type); }
	void PostWriteShadowViews() { FPostWriteShadowViews(this); }
	void PrepareShadowViews() { FPrepareShadowViews(this); }
	virtual void AddDynamicLight(SRenderLight& light);
	virtual int GetDynamicLightsCount() const;
	virtual SRenderLight& GetDynamicLight(int nLightId);
	virtual void AddLight(eDeferredLightType lightType, SRenderLight& light);
	virtual int GetLightsCount(eDeferredLightType lightType) const;
	virtual SRenderLight& GetLight(eDeferredLightType lightType, int nLightId);
	std::vector<SRenderLight>& GetLightsArray(eDeferredLightType lightType) { return FGetLightsArray(this, lightType); }
	SRenderLight* AddLightAtIndex(eDeferredLightType lightType, const SRenderLight& light, int index) { return FAddLightAtIndex(this, lightType, light, index); }
	virtual uint8_t AddClipVolume(const IClipVolume* pClipVolume);
	virtual void SetClipVolumeBlendInfo(const IClipVolume* pClipVolume, int blendInfoCount, IClipVolume** blendVolumes, Plane_tpl<float>* blendPlanes);
	virtual void AddFogVolume(const CREFogVolume* pFogVolume);
	const std::vector<SFogVolumeInfo>& GetFogVolumes(IFogVolumeRenderNode::eFogVolumeType volumeType) const { return FGetFogVolumes(this, volumeType); }
	bool HaveAnyFogVolumes() const { return FHaveAnyFogVolumes(this); }
	CREClientPoly* AddClientPoly() { return FAddClientPoly(this); }
	bool AddDeferredDecal(const SDeferredDecal& _source) { return FAddDeferredDecal(this, _source); }
	virtual void ArkAddClusteredDecal(SDeferredDecal& _source);
	virtual void EnableLookingGlass(bool _bEnable);
	SArkScreenBounds GetDistortBounds() const { alignas(SArkScreenBounds) std::byte _return_buf_[sizeof(SArkScreenBounds)]; return *FGetDistortBounds(this, reinterpret_cast<SArkScreenBounds*>(_return_buf_)); }
	void Clear() { FClear(this); }
	void Job_PostWrite() { FJob_PostWrite(this); }
	void Job_SortRenderItemsInList(ERenderListID list) { FJob_SortRenderItemsInList(this, list); }
	void CollectLookingGlassInformation() { FCollectLookingGlassInformation(this); }
	void ExpandPermanentRenderObjects() { FExpandPermanentRenderObjects(this); }
	void CompileModifiedRenderObjects() { FCompileModifiedRenderObjects(this); }
	void UpdateModifiedShaderItems() { FUpdateModifiedShaderItems(this); }
	void AddRenderItemsFromClientPolys() { FAddRenderItemsFromClientPolys(this); }
	bool CheckAndScheduleForUpdate(const SShaderItem& shaderItem) { return FCheckAndScheduleForUpdate(this, shaderItem); }
	ColorF TraceFogVolumes(const Vec3& _worldPos) { alignas(ColorF) std::byte _return_buf_[sizeof(ColorF)]; return *FTraceFogVolumes(this, reinterpret_cast<ColorF*>(_return_buf_), _worldPos); }
	void PrepareDeferredDecals() { FPrepareDeferredDecals(this); }
	void PrepareForwardDecals() { FPrepareForwardDecals(this); }
	void PrepareClusteredDecals() { FPrepareClusteredDecals(this); }
	void DrawCompiledRenderItems(const SGraphicsPipelinePassContext& passContext) const { FDrawCompiledRenderItems(this, passContext); }

#if 0
	IRenderView::EViewType GetType() const;
	void SetParentView(CRenderView* _arg0_);
	CRenderView* GetParentView() const;
	const CCamera& GetCamera() const;
	const CCamera& GetPreviousCamera() const;
	const CRenderCamera& GetRenderCamera() const;
	TRange<int> GetItemsRange(ERenderListID _arg0_);
	void PrepareForRendering();
	bool IsRecursive() const;
	bool IsShadowGenView() const;
	IRenderView::EUsageMode GetUsageMode() const;
	CRenderView* GetShadowsView(ShadowMapFrustum* _arg0_);
	TRange<int> GetShadowItemsRange(ShadowMapFrustum* _arg0_, int _arg1_);
	lockfree_add_vector<SRendItem>& GetShadowItems(ShadowMapFrustum* _arg0_, int _arg1_);
	std::vector<SShadowFrustumToRender>& GetFrustumsToRender();
	void SetShadowFrustumOwner(ShadowMapFrustum* _arg0_);
	const std::vector<SDeferredClipVolume>& GetClipVolumes() const;
	int GetClientPolyCount() const;
	CREClientPoly* GetClientPoly(int _arg0_) const;
	const std::vector<SArkDeferredDecal>& GetDeferredDecals() const;
	const std::vector<SArkForwardDecal>& GetForwardDecals() const;
	const std::vector<SArkClusteredDecal>& ArkGetClusteredDecals() const;
	bool IsLookingGlassMaskEnabled() const;
	bool ShouldLookingGlassMaskRender() const;
	bool IsLookingGlassScene1Only() const;
	uint8_t GetSceneMaskFilter() const;
	void ExtractTemporaryShaderItems();
	void ClearTemporaryCompiledObjects();
	void PrepareNearestShadows();
	CCompiledRenderObject* AllocCompiledObject(CRenderObject* _arg0_, CRendElementBase* _arg1_, const SShaderItem& _arg2_);
	CCompiledRenderObject* AllocCompiledObjectTemporary(CRenderObject* _arg0_, CRendElementBase* _arg1_, const SShaderItem& _arg2_);
	void ComputeListDirtyBounds(ERenderListID _arg0_, SArkScreenBounds& _arg1_);
	void UpdateFogAndClipVolumeStencil(CRenderObject* _arg0_, uint8_t _arg1_);
	CRenderItemDrawer& GetDrawer();
	const CRenderItemDrawer& GetDrawer() const;
#endif

	static inline auto FSetFrameId = PreyFunction<void(CRenderView* const _this, uint64_t frameId)>(0xEBBDB0);
	static inline auto FGetFrameId = PreyFunction<uint64_t(const CRenderView* const _this)>(0xD87510);
	static inline auto FSetSkipRenderingFlags = PreyFunction<void(CRenderView* const _this, unsigned nFlags)>(0x7060A0);
	static inline auto FGetSkipRenderingFlags = PreyFunction<unsigned(const CRenderView* const _this)>(0x12380B0);
	static inline auto FSetShaderRenderingFlags = PreyFunction<void(CRenderView* const _this, unsigned nFlags)>(0x11E4270);
	static inline auto FGetShaderRenderingFlags = PreyFunction<unsigned(const CRenderView* const _this)>(0xEB9170);
	static inline auto FSetCamera = PreyFunction<void(CRenderView* const _this, const CCamera & cam)>(0xEBB960);
	static inline auto FSetPreviousFrameCamera = PreyFunction<void(CRenderView* const _this, const CCamera & _camera)>(0xEBBDC0);
	static inline auto FSwitchUsageMode = PreyFunction<void(CRenderView* const _this, IRenderView::EUsageMode mode)>(0xEBBDD0);
	static inline auto FGetWriteMutex = PreyFunction<JobManager::SJobState * (CRenderView* const _this)>(0xEB9E30);
	static inline auto FAddPermanentObject = PreyFunction<void(CRenderView* const _this, CRenderObject * pObject, float _fDistance, const SRenderingPassInfo & passInfo)>(0xEB6C20);
	static inline auto FCRenderView = PreyFunction<void(CRenderView* const _this, const char* name, IRenderView::EViewType type, CRenderView * pParentView, ShadowMapFrustum * pShadowFrustumOwner)>(0xEB2DF0);
	static inline auto FBitNotCRenderView = PreyFunction<void(CRenderView* const _this)>(0xEB4EC0);
	static inline auto FGetRenderItems = PreyFunction<lockfree_add_vector<SRendItem>&(CRenderView* const _this, int nRenderList)>(0xEB9100);
	static inline auto FGetBatchFlags = PreyFunction<unsigned(const CRenderView* const _this, int nRenderList)>(0xEB8FF0);
	static inline auto FAddRenderItem = PreyFunction<void(CRenderView* const _this, CRendElementBase * pElem, CRenderObject * pObj, const SShaderItem & shaderItem, unsigned nList, unsigned nBatchFlags, float _fDistance, SRendItemSorter sorter, bool bShadowPass, bool bForceOpaqueForward)>(0xEB6EA0);
	static inline auto FAddPermanentObjectInline = PreyFunction<void(CRenderView* const _this, CPermanentRenderObject * pObject, float _fDistance, SRendItemSorter sorter, int shadowFrustumSide)>(0xEB6C40);
	static inline auto FFindRenderListSplit = PreyFunction<int(CRenderView* const _this, ERenderListID list, unsigned objFlag)>(0xEB8F40);
	static inline auto FPrepareForWriting = PreyFunction<void(CRenderView* const _this)>(0xA13080);
	static inline auto FAddShadowFrustumToRender = PreyFunction<void(CRenderView* const _this, const SShadowFrustumToRender & frustum)>(0xEB76C0);
	static inline auto FGetShadowFrustumsForLight = PreyFunction<std::vector<SShadowFrustumToRender*>&(CRenderView* const _this, int lightId)>(0xEB91A0);
	static inline auto FGetShadowFrustumsByType = PreyFunction<std::vector<SShadowFrustumToRender*>&(CRenderView* const _this, CRenderView::eShadowFrustumRenderType type)>(0xEB9180);
	static inline auto FPostWriteShadowViews = PreyFunction<void(CRenderView* const _this)>(0xA13080);
	static inline auto FPrepareShadowViews = PreyFunction<void(CRenderView* const _this)>(0xEBB8F0);
	static inline auto FAddDynamicLight = PreyFunction<void(CRenderView* const _this, SRenderLight & light)>(0xEB6510);
	static inline auto FGetDynamicLightsCount = PreyFunction<int(const CRenderView* const _this)>(0xEB9030);
	static inline auto FGetDynamicLight = PreyFunction<SRenderLight & (CRenderView* const _this, int nLightId)>(0xEB9010);
	static inline auto FAddLight = PreyFunction<void(CRenderView* const _this, eDeferredLightType lightType, SRenderLight & light)>(0xEB6810);
	static inline auto FGetLightsCount = PreyFunction<int(const CRenderView* const _this, eDeferredLightType lightType)>(0xEB90C0);
	static inline auto FGetLight = PreyFunction<SRenderLight & (CRenderView* const _this, eDeferredLightType lightType, int nLightId)>(0xEB9080);
	static inline auto FGetLightsArray = PreyFunction<std::vector<SRenderLight>&(CRenderView* const _this, eDeferredLightType lightType)>(0xEB90A0);
	static inline auto FAddLightAtIndex = PreyFunction<SRenderLight * (CRenderView* const _this, eDeferredLightType lightType, const SRenderLight & light, int index)>(0xEB68B0);
	static inline auto FAddClipVolume = PreyFunction<uint8_t(CRenderView* const _this, const IClipVolume * pClipVolume)>(0xEB6070);
	static inline auto FSetClipVolumeBlendInfo = PreyFunction<void(CRenderView* const _this, const IClipVolume * pClipVolume, int blendInfoCount, IClipVolume * *blendVolumes, Plane_tpl<float>*blendPlanes)>(0xEBBCB0);
	static inline auto FAddFogVolume = PreyFunction<void(CRenderView* const _this, const CREFogVolume * pFogVolume)>(0xEB65A0);
	static inline auto FGetFogVolumes = PreyFunction<const std::vector<SFogVolumeInfo>&(const CRenderView* const _this, IFogVolumeRenderNode::eFogVolumeType volumeType)>(0xEB9060);
	static inline auto FHaveAnyFogVolumes = PreyFunction<bool(const CRenderView* const _this)>(0xEB9E40);
	static inline auto FAddClientPoly = PreyFunction<CREClientPoly * (CRenderView* const _this)>(0xEB5F90);
	static inline auto FAddDeferredDecal = PreyFunction<bool(CRenderView* const _this, const SDeferredDecal & _source)>(0xEB6150);
	static inline auto FArkAddClusteredDecal = PreyFunction<void(CRenderView* const _this, SDeferredDecal & _source)>(0xEB7990);
	static inline auto FEnableLookingGlass = PreyFunction<void(CRenderView* const _this, bool _bEnable)>(0xEB85E0);
	static inline auto FGetDistortBounds = PreyFunction<SArkScreenBounds * (const CRenderView* const _this, SArkScreenBounds * _return_value_)>(0xEB9000);
	static inline auto FClear = PreyFunction<void(CRenderView* const _this)>(0xEB7B10);
	static inline auto FJob_PostWrite = PreyFunction<void(CRenderView* const _this)>(0xEB9EA0);
	static inline auto FJob_SortRenderItemsInList = PreyFunction<void(CRenderView* const _this, ERenderListID list)>(0xEBA0C0);
	static inline auto FCollectLookingGlassInformation = PreyFunction<void(CRenderView* const _this)>(0xEB7FB0);
	static inline auto FExpandPermanentRenderObjects = PreyFunction<void(CRenderView* const _this)>(0xEB85F0);
	static inline auto FCompileModifiedRenderObjects = PreyFunction<void(CRenderView* const _this)>(0xEB81B0);
	static inline auto FUpdateModifiedShaderItems = PreyFunction<void(CRenderView* const _this)>(0xEBC3B0);
	static inline auto FAddRenderItemsFromClientPolys = PreyFunction<void(CRenderView* const _this)>(0xEB7450);
	static inline auto FCheckAndScheduleForUpdate = PreyFunction<bool(CRenderView* const _this, const SShaderItem & shaderItem)>(0xEB7A70);
	static inline auto FTraceFogVolumes = PreyFunction<ColorF * (CRenderView* const _this, ColorF * _return_value_, const Vec3 & _worldPos)>(0xEBC0D0);
	static inline auto FPrepareDeferredDecals = PreyFunction<void(CRenderView* const _this)>(0xEBA9D0);
	static inline auto FPrepareForwardDecals = PreyFunction<void(CRenderView* const _this)>(0xEBAF30);
	static inline auto FPrepareClusteredDecals = PreyFunction<void(CRenderView* const _this)>(0xEBA6B0);
	static inline auto FDrawCompiledRenderItems = PreyFunction<void(const CRenderView* const _this, const SGraphicsPipelinePassContext & passContext)>(0xEB85D0);
};
