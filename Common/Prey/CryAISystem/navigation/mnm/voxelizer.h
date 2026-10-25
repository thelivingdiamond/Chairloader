// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/navigation/mnm/DynamicSpanGrid.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryCore/stridedptr.h>

struct IGeometry;
struct IPhysicalEntity;

namespace MNM
{

// MNM::Voxelizer
// Header:  CryEngine/cryaisystem/navigation/mnm/Voxelizer.h
class Voxelizer
{ // Size=152 (0x98)
public:
	AABB m_volumeAABB;
	Vec3 m_voxelSize;
	Vec3 m_voxelConv;
	Vec3i m_voxelSpaceSize;
	MNM::DynamicSpanGrid m_spanGrid;

	Voxelizer();
	void Reset() { FReset(this); }
	void Start(const AABB& volume, const Vec3& voxelSize) { FStart(this, volume, voxelSize); }
	void RasterizeTriangle(const Vec3 v0, const Vec3 v1, const Vec3 v2, MNM::DynamicSpanGrid* _targetGrid) { FRasterizeTriangle(this, v0, v1, v2, _targetGrid); }

#if 0
	const MNM::DynamicSpanGrid& GetSpanGrid() const;
	void Evaluate2DEdge(Vec2& _arg0_, float& _arg1_, bool _arg2_, const Vec2 _arg3_, const Vec2 _arg4_, const Vec2 _arg5_);
#endif

#ifndef MOONCRASH
	static inline auto FVoxelizerOv2 = PreyFunction<void(MNM::Voxelizer* const _this)>(0x65F650);
	static inline auto FReset = PreyFunction<void(MNM::Voxelizer* const _this)>(0x662670);
	static inline auto FStart = PreyFunction<void(MNM::Voxelizer* const _this, const AABB& volume, const Vec3& voxelSize)>(0x6630E0);
	static inline auto FRasterizeTriangle = PreyFunction<void(MNM::Voxelizer* const _this, const Vec3 v0, const Vec3 v1, const Vec3 v2, MNM::DynamicSpanGrid* _targetGrid)>(0x661890);
#else
	static inline auto FVoxelizerOv2 = PreyFunction<void(MNM::Voxelizer* const _this)>(0x67B050);
	static inline auto FReset = PreyFunction<void(MNM::Voxelizer* const _this)>(0x67E0B0);
	static inline auto FStart = PreyFunction<void(MNM::Voxelizer* const _this, const AABB& volume, const Vec3& voxelSize)>(0x67EB30);
	static inline auto FRasterizeTriangle = PreyFunction<void(MNM::Voxelizer* const _this, const Vec3 v0, const Vec3 v1, const Vec3 v2, MNM::DynamicSpanGrid* _targetGrid)>(0x67D2D0);
#endif
};

// MNM::WorldVoxelizer
// Header:  CryEngine/cryaisystem/navigation/mnm/Voxelizer.h
class WorldVoxelizer : public MNM::Voxelizer
{ // Size=33120 (0x8160)
public:
	IPhysicalEntity* m_jobsEntities[4096];
	IPhysicalEntity* * m_jobsEntityList;
	int m_entityCount;
	uint64_t m_badTerrainCount;
	unsigned m_badTerrainIndex[16];
	int m_finalTriCount;
	int m_callbackContext;
	MNM::DynamicSpanGrid m_jobsSpanGrid[1];
	int m_triCount[2];
	volatile int m_NumRunningJobs;
	volatile int m_NextEntitytoProcess;

	uint64_t ProcessGeometry(unsigned hashValueSeed, unsigned hashTest, unsigned* hashValue, Functor2wRet<IPhysicalEntity &,unsigned int &,bool> pEntityCallback) { return FProcessGeometry(this, hashValueSeed, hashTest, hashValue, pEntityCallback); }
	void SpawnProcessGeometryJobs(unsigned _hashValueSeed, unsigned _hashTest, unsigned* _hashValue, Functor2wRet<IPhysicalEntity &,unsigned int &,bool> _pEntityCallback, int _callbackContext) { FSpawnProcessGeometryJobs(this, _hashValueSeed, _hashTest, _hashValue, _pEntityCallback, _callbackContext); }
	void DoProcessGeometryJob(int _channel) { FDoProcessGeometryJob(this, _channel); }
	int GetFinalTriangleCount() { return FGetFinalTriangleCount(this); }
	void CalculateWaterDepth() { FCalculateWaterDepth(this); }
	MNM::DynamicSpanGrid& GetGridForChannel(int _jobChannel) { return FGetGridForChannel(this, _jobChannel); }
	void VoxelizeGeometry(const strided_pointer<Vec3_tpl<float> >& vertices, const int* indices, uint64_t triCount, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid) { FVoxelizeGeometryOv2(this, vertices, indices, triCount, worldTM, _targetGrid); }
	void VoxelizeGeometry(const Vec3* vertices, const unsigned* indices, uint64_t triCount, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid) { FVoxelizeGeometryOv1(this, vertices, indices, triCount, worldTM, _targetGrid); }
#ifndef MOONCRASH
	uint64_t VoxelizeGeometry(IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid) { return FVoxelizeGeometryOv0(this, geometry, worldTM, _targetGrid); }
#else
	uint64_t VoxelizeGeometry(IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid, unsigned _flags) { return FVoxelizeGeometryOv0(this, geometry, worldTM, _targetGrid, _flags); }
#endif
	AABB ComputeTerrainAABB(IGeometry* geometry) { alignas(AABB) std::byte _return_buf_[sizeof(AABB)]; return *FComputeTerrainAABB(this, reinterpret_cast<AABB*>(_return_buf_), geometry); }
	uint64_t VoxelizeTerrain(IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid) { return FVoxelizeTerrain(this, geometry, worldTM, _targetGrid); }

#if 0
	void FinishProcessGeometryJob();
	void VoxelizeGeometry(const Vec3* _arg0_, uint64_t _arg1_, const Matrix34& _arg2_, MNM::DynamicSpanGrid* _arg3_);
#endif

#ifndef MOONCRASH
	static inline auto FProcessGeometry = PreyFunction<uint64_t(MNM::WorldVoxelizer* const _this, unsigned hashValueSeed, unsigned hashTest, unsigned* hashValue, Functor2wRet<IPhysicalEntity &,unsigned int &,bool> pEntityCallback)>(0x660E10);
	static inline auto FSpawnProcessGeometryJobs = PreyFunction<void(MNM::WorldVoxelizer* const _this, unsigned _hashValueSeed, unsigned _hashTest, unsigned* _hashValue, Functor2wRet<IPhysicalEntity &,unsigned int &,bool> _pEntityCallback, int _callbackContext)>(0x662680);
	static inline auto FDoProcessGeometryJob = PreyFunction<void(MNM::WorldVoxelizer* const _this, int _channel)>(0x6608A0);
	static inline auto FGetFinalTriangleCount = PreyFunction<int(MNM::WorldVoxelizer* const _this)>(0x660DC0);
	static inline auto FCalculateWaterDepth = PreyFunction<void(MNM::WorldVoxelizer* const _this)>(0x65F6F0);
	static inline auto FGetGridForChannel = PreyFunction<MNM::DynamicSpanGrid& (MNM::WorldVoxelizer* const _this, int _jobChannel)>(0x660DD0);
	static inline auto FVoxelizeGeometryOv2 = PreyFunction<void(MNM::WorldVoxelizer* const _this, const strided_pointer<Vec3_tpl<float> >& vertices, const int* indices, uint64_t triCount, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x663220);
	static inline auto FVoxelizeGeometryOv1 = PreyFunction<void(MNM::WorldVoxelizer* const _this, const Vec3* vertices, const unsigned* indices, uint64_t triCount, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x6637E0);
	static inline auto FVoxelizeGeometryOv0 = PreyFunction<uint64_t(MNM::WorldVoxelizer* const _this, IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x663D60);
	static inline auto FComputeTerrainAABB = PreyFunction<AABB*(MNM::WorldVoxelizer* const _this, AABB* _return_value_, IGeometry* geometry)>(0x65FF10);
	static inline auto FVoxelizeTerrain = PreyFunction<uint64_t(MNM::WorldVoxelizer* const _this, IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x665830);
#else
	static inline auto FProcessGeometry = PreyFunction<uint64_t(MNM::WorldVoxelizer* const _this, unsigned hashValueSeed, unsigned hashTest, unsigned* hashValue, Functor2wRet<IPhysicalEntity &,unsigned int &,bool> pEntityCallback)>(0x67C820);
	static inline auto FSpawnProcessGeometryJobs = PreyFunction<void(MNM::WorldVoxelizer* const _this, unsigned _hashValueSeed, unsigned _hashTest, unsigned* _hashValue, Functor2wRet<IPhysicalEntity &,unsigned int &,bool> _pEntityCallback, int _callbackContext)>(0x67E0C0);
	static inline auto FDoProcessGeometryJob = PreyFunction<void(MNM::WorldVoxelizer* const _this, int _channel)>(0x67C2B0);
	static inline auto FGetFinalTriangleCount = PreyFunction<int(MNM::WorldVoxelizer* const _this)>(0x67C7D0);
	static inline auto FCalculateWaterDepth = PreyFunction<void(MNM::WorldVoxelizer* const _this)>(0x67B0F0);
	static inline auto FGetGridForChannel = PreyFunction<MNM::DynamicSpanGrid& (MNM::WorldVoxelizer* const _this, int _jobChannel)>(0x67C7E0);
	static inline auto FVoxelizeGeometryOv2 = PreyFunction<void(MNM::WorldVoxelizer* const _this, const strided_pointer<Vec3_tpl<float> >& vertices, const int* indices, uint64_t triCount, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x67EC70);
	static inline auto FVoxelizeGeometryOv1 = PreyFunction<void(MNM::WorldVoxelizer* const _this, const Vec3* vertices, const unsigned* indices, uint64_t triCount, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x67F230);
	static inline auto FVoxelizeGeometryOv0 = PreyFunction<uint64_t(MNM::WorldVoxelizer* const _this, IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid, unsigned _flags)>(0x67F7B0);
	static inline auto FComputeTerrainAABB = PreyFunction<AABB*(MNM::WorldVoxelizer* const _this, AABB* _return_value_, IGeometry* geometry)>(0x67B920);
	static inline auto FVoxelizeTerrain = PreyFunction<uint64_t(MNM::WorldVoxelizer* const _this, IGeometry* geometry, const Matrix34& worldTM, MNM::DynamicSpanGrid* _targetGrid)>(0x681410);
#endif
};


} // namespace MNM

