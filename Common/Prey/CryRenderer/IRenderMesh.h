// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/CryArray.h>
#include <Prey/Cry3DEngine/CryPodArray.h>
#include <Prey/CryMath/Cry_Geo.h>               // EGeomForm
#include <Prey/CryRenderer/VertexFormats.h>     // EVertexFormat
#include <utility>

class CMesh;
struct CRenderChunk;
class CRenderObject;
class ICrySizer;
struct IIndexedMesh;
struct IMaterial;
struct IShader;
struct PosNorm;
struct SGeometryDebugDrawInfo;
struct SMeshBoneMapping_uint16;
struct SMeshBoneMapping_uint8;
struct SPipNormal;
struct SPipTangents;
struct SRendParams;
struct SRenderingPassInfo;
struct SSkinningData;

// IRenderMesh
// Header:  _unknown/IRenderMesh.h
// Include: Prey/CryRenderer/IRenderMesh.h
// Defined here rather than in IRenderer.h (which includes this header) so IRenderMesh.h stays
// self-contained and light enough for the base PCH (ArkStubs.h).
enum PublicRenderPrimitiveType
{
	prtTriangleList = 0x0,
	prtTriangleStrip = 0x1,
	prtLineList = 0x2,
	prtLineStrip = 0x3,
};

// From CryEngine CryRenderer/IRenderMesh.h
enum ERenderMeshType
{
	eRMT_Immmutable = 0,
	eRMT_Static = 1,
	eRMT_StaticShared = 2,
	eRMT_Dynamic = 3,
	eRMT_Transient = 4,
};

struct IRenderMesh
{ // Size=8 (0x8)
	enum class EMemoryUsageArgument
	{
		MEM_USAGE_COMBINED = 0,
		MEM_USAGE_ONLY_SYSTEM = 1,
		MEM_USAGE_ONLY_VIDEO = 2,
		MEM_USAGE_ONLY_STREAMS = 3,
	};

	// IRenderMesh::SInitParamerers
	// Header:  _unknown/IRenderMesh.h
	struct SInitParamerers
	{ // Size=72 (0x48)
		EVertexFormat eVertexFormat;
		ERenderMeshType eType;
		void* pVertBuffer;
		int nVertexCount;
		SPipTangents* pTangents;
		SPipNormal* pNormals;
		uint16_t* pIndices;
		int nIndexCount;
		PublicRenderPrimitiveType nPrimetiveType;
		int nRenderChunkCount;
		int nClientTextureBindID;
		bool bOnlyVideoBuffer;
		bool bPrecache;
		bool bLockForThreadAccess;

	#if 0
		SInitParamerers();
	#endif
	};

	// IRenderMesh::ThreadAccessLock
	// Header:  _unknown/IRenderMesh.h
	struct ThreadAccessLock
	{ // Size=8 (0x8)
		IRenderMesh* m_pRM;

	#if 0
		ThreadAccessLock(IRenderMesh* _arg0_);
		ThreadAccessLock(const IRenderMesh::ThreadAccessLock& _arg0_);
		~ThreadAccessLock();
		IRenderMesh::ThreadAccessLock& operator=(const IRenderMesh::ThreadAccessLock& _arg0_);
	#endif
	};

	virtual ~IRenderMesh() {}
	virtual void AddRef() = 0;
	virtual int Release() = 0;
	virtual bool CanRender() = 0;
	virtual const char* GetTypeName() = 0;
	virtual const char* GetSourceName() const = 0;
	virtual int GetIndicesCount() = 0;
	virtual int GetVerticesCount() = 0;
	virtual EVertexFormat GetVertexFormat() = 0;
	virtual ERenderMeshType GetMeshType() = 0;
	virtual float GetGeometricMeanFaceArea() const = 0;
	virtual void SetSkinned(bool bSkinned) = 0;
	virtual unsigned GetSkinningWeightCount() const = 0;
	virtual uint64_t SetMesh(CMesh& mesh, int nSecColorsSetOffset, unsigned flags, const Vec3* pPosOffset, bool requiresLock) = 0;
	virtual void CopyTo(IRenderMesh* _pDst, int nAppendVtx, bool bDynamic, bool fullCopy) = 0;
	virtual void SetSkinningDataVegetation(SMeshBoneMapping_uint8* pBoneMapping) = 0;
	virtual void SetSkinningDataCharacter(CMesh& mesh, SMeshBoneMapping_uint16* pBoneMapping, SMeshBoneMapping_uint16* pExtraBoneMapping) = 0;
	virtual IIndexedMesh* GetIndexedMesh(IIndexedMesh* pIdxMesh) = 0;
	virtual int GetRenderChunksCount(IMaterial* pMaterial, int& nRenderTrisCount) = 0;
	virtual IRenderMesh* GenerateMorphWeights() = 0;
	virtual IRenderMesh* GetMorphBuddy() = 0;
	virtual void SetMorphBuddy(IRenderMesh* pMorph) = 0;
	virtual bool UpdateVertices(const void* pVertBuffer, int nVertCount, int nOffset, int nStream, unsigned copyFlags, bool requiresLock) = 0;
	virtual bool UpdateIndices(const uint16_t* pNewInds, int nInds, int nOffsInd, unsigned copyFlags, bool requiresLock) = 0;
	virtual void SetCustomTexID(int nCustomTID) = 0;
	virtual void SetChunk(int nIndex, CRenderChunk& inChunk) = 0;
	virtual void SetChunk(IMaterial* pNewMat, int nFirstVertId, int nVertCount, int nFirstIndexId, int nIndexCount, float texelAreaDensity, int nIndex) = 0;
	virtual void SetRenderChunks(CRenderChunk* pInputChunksArray, int nCount, bool bSubObjectChunks) = 0;
	virtual void GenerateQTangents() = 0;
	virtual void CreateChunksSkinned() = 0;
	virtual void NextDrawSkinned() = 0;
	virtual IRenderMesh* GetVertexContainer() = 0;
	virtual void SetVertexContainer(IRenderMesh* pBuf) = 0;
	virtual DynArray<CRenderChunk,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetChunks() = 0;
	virtual DynArray<CRenderChunk,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetChunksSkinned() = 0;
	virtual DynArray<CRenderChunk,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetChunksSubObjects() = 0;
	virtual void SetBBox(const Vec3& vBoxMin, const Vec3& vBoxMax) = 0;
	virtual void GetBBox(Vec3& vBoxMin, Vec3& vBoxMax) = 0;
	virtual void UpdateBBoxFromMesh() = 0;
	virtual unsigned* GetPhysVertexMap() = 0;
	virtual bool IsEmpty() = 0;
	virtual uint8_t* GetPosPtrNoCache(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetPosPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetColorPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetNormPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetUVPtrNoCache(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetUVPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetTangentPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetQTangentPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual uint8_t* GetHWSkinPtr(int& nStride, unsigned nFlags, int nOffset, bool remapped) = 0;
	virtual uint8_t* GetVelocityPtr(int& nStride, unsigned nFlags, int nOffset) = 0;
	virtual void UnlockStream(int nStream) = 0;
	virtual void UnlockIndexStream() = 0;
	virtual uint16_t* GetIndexPtr(unsigned nFlags, int nOffset) = 0;
	virtual const PodArray<std::pair<int,int>,0>* GetTrisForPosition(const Vec3& vPos, IMaterial* pMaterial) = 0;
	virtual float GetExtent(EGeomForm eForm) = 0;
	virtual void GetRandomPos(PosNorm& ran, EGeomForm eForm, const SSkinningData* pSkinning) = 0;
	virtual void Render(const SRendParams& rParams, CRenderObject* pObj, IMaterial* pMaterial, const SRenderingPassInfo& passInfo, bool bSkinned) = 0;
	virtual void Render(CRenderObject* pObj, const SRenderingPassInfo& passInfo) = 0;
	virtual void AddRenderElements(IMaterial* pIMatInfo, CRenderObject* pObj, const SRenderingPassInfo& passInfo, int nList, int nAW) = 0;
	virtual void AddRE(IMaterial* pMaterial, CRenderObject* obj, IShader* ef, const SRenderingPassInfo& passInfo, int nList, int nAW) = 0;
	virtual void SetREUserData(float* pfCustomData, float fFogScale, float fAlpha) = 0;
	virtual void DebugDraw(const SGeometryDebugDrawInfo& info, unsigned nVisibleChunksMask, float fExtrdueScale) = 0;
	virtual uint64_t GetMemoryUsage(ICrySizer* pSizer, IRenderMesh::EMemoryUsageArgument nType) const = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	virtual int GetAllocatedBytes(bool bVideoMem) const = 0;
	virtual float GetAverageTrisNumPerChunk(IMaterial* pMat) = 0;
	virtual int GetTextureMemoryUsage(const IMaterial* pMaterial, ICrySizer* pSizer, bool bStreamedIn) const = 0;
	virtual void KeepSysMesh(bool keep) = 0;
	virtual void UnKeepSysMesh() = 0;
	virtual void SetMeshLod(int nLod) = 0;
	virtual void LockForThreadAccess() = 0;
	virtual void UnLockForThreadAccess() = 0;
	virtual volatile int* SetAsyncUpdateState() = 0;
	virtual void CreateRemappedBoneIndicesPair(const DynArray<unsigned short,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& arrRemapTable, const unsigned pairGuid) = 0;
	virtual void ReleaseRemappedBoneIndicesPair(const unsigned pairGuid) = 0;
};

static_assert(sizeof(IRenderMesh) == 8);
static_assert(sizeof(IRenderMesh::SInitParamerers) == 72);

