// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/cryaisystem/navigation/mnm/CompactSpanGrid.h>
#include <CryEngine/cryaisystem/navigation/mnm/profiler.h>
#include <CryEngine/cryaisystem/navigation/mnm/voxelizer.h>
#include <Prey/Ark/arkaudioutil.h>
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequinTagDefs.h>
#include <Prey/CryCore/FixedPoint.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryMath/SimpleHashLookUp.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryNetwork/Protocol/ExponentialKeyExchange.h>
#include <Prey/CrySystem/ILog.h>
#include <Prey/CrySystem/IMiniLog.h>
#include <Prey/CrySystem/Log.h>
#include <Prey/GameDll/ai/hazardmodule/hazardraycast.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/anim/arknpcanimactions.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/weapons/arklaser.h>
#include <_unknown/AkEnvelopeParams.h>
#include <_unknown/ArkAiTreeStimulusTemplate_ArkAiTreeGuardBeginStimulus_.h>
#include <_unknown/ArkNpcBlackboardEntryTemplate_GetUpdate_ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardEntryKey_LostVisibilityTime,ArkNpcBlackboardEntry_LostVisibilityTime,float,float_.h>
#include <_unknown/ArkNpcBlackboardEntryTemplate_GetUpdate_ArkNpcBlackboardKey_VisibilityTime,ArkNpcBlackboardEntryKey_VisibilityTime,ArkNpcBlackboardEntry_VisibilityTime,float,float_.h>
#include <_unknown/ArkPsiPowerFactionTraits_10_.h>
#include <_unknown/ArkPsiPowerFactionTraits_11_.h>
#include <_unknown/CFXNodeDescription__CControlParamBase.h>
#include <_unknown/CryLockT_2_.h>
#include <_unknown/CryMT__queue_CLog__SLogMsg,std__allocator_CLog__SLogMsg_ _.h>

class Agent;
struct AkModulatorParams;
class ArkNpc;
class ArkNpcBlackboardEntryKey_LostVisibilityTime;
class ArkNpcBlackboardEntryKey_VisibilityTime;
class ArkPsiPowerCyberkinesisProperties;
class ArkPsiPowerHypnosisProperties;
class ArkPsiPowerTargetingComponent;
class CCryName;
namespace EntityEffects
{
struct SEffectAttachParams;
struct SEffectInfo;
struct SLightAttachParams;
} // namespace EntityEffects
struct EventPhysCollision;
namespace HazardSystem
{
class HazardCollisionResult;
class HazardProjectileID;
} // namespace HazardSystem
struct ICVar;
struct IConsole;
struct IConsoleCmdArgs;
class ICrySizer;
struct IEntity;
struct ILightSource;
struct ILogCallback;
struct IParticleEffect;
struct IParticleEmitter;
struct ISystem;
namespace MNM
{
struct Tile;
} // namespace MNM
struct RayCastResult;

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CExponentialKeyExchange // Id=8000A4B Size=192
{
public:
	static constexpr const uint64_t KEY_SIZE = 32;
	static constexpr const uint64_t KEY_SIZE_IN_BITS = 256;
	
	struct KEY_TYPE // Id=8000A4C Size=32
	{
		uint8_t key[32];
	};

	CExponentialKeyExchange::KEY_TYPE m_x;
	CExponentialKeyExchange::KEY_TYPE m_g;
	CExponentialKeyExchange::KEY_TYPE m_p;
	CExponentialKeyExchange::KEY_TYPE m_A;
	CExponentialKeyExchange::KEY_TYPE m_B;
	CExponentialKeyExchange::KEY_TYPE m_k;
	
	CExponentialKeyExchange();
	~CExponentialKeyExchange() { FBitNotCExponentialKeyExchange(this); }
	void Generate(CExponentialKeyExchange::KEY_TYPE &gg, CExponentialKeyExchange::KEY_TYPE &pp, CExponentialKeyExchange::KEY_TYPE &AA) { FGenerateOv1(this,gg,pp,AA); }
	void Generate(CExponentialKeyExchange::KEY_TYPE &BB, CExponentialKeyExchange::KEY_TYPE const &gg, CExponentialKeyExchange::KEY_TYPE const &pp, CExponentialKeyExchange::KEY_TYPE const &AA) { FGenerateOv0(this,BB,gg,pp,AA); }
	void Calculate(CExponentialKeyExchange::KEY_TYPE const &BB) { FCalculate(this,BB); }
	CExponentialKeyExchange::KEY_TYPE const &GetKey() const { return FGetKey(this); }
	static int RandFunc(uint8_t *bytes, uint64_t nbytes, const uint8_t *seed, uint64_t slen) { return FRandFunc(bytes,nbytes,seed,slen); }
	
#if 0
	static void Test(IConsoleCmdArgs *arg0);
#endif
	
	static inline auto FBitNotCExponentialKeyExchange = PreyFunction<void(CExponentialKeyExchange *const _this)>(0xA13080);
	static inline auto FGenerateOv1 = PreyFunction<void(CExponentialKeyExchange *const _this, CExponentialKeyExchange::KEY_TYPE &gg, CExponentialKeyExchange::KEY_TYPE &pp, CExponentialKeyExchange::KEY_TYPE &AA)>(0xB04EE0);
	static inline auto FGenerateOv0 = PreyFunction<void(CExponentialKeyExchange *const _this, CExponentialKeyExchange::KEY_TYPE &BB, CExponentialKeyExchange::KEY_TYPE const &gg, CExponentialKeyExchange::KEY_TYPE const &pp, CExponentialKeyExchange::KEY_TYPE const &AA)>(0xB052F0);
	static inline auto FCalculate = PreyFunction<void(CExponentialKeyExchange *const _this, CExponentialKeyExchange::KEY_TYPE const &BB)>(0xB04D70);
	static inline auto FGetKey = PreyFunction<CExponentialKeyExchange::KEY_TYPE const &(CExponentialKeyExchange const *const _this)>(0x10BD350);
	static inline auto FRandFunc = PreyFunction<int(uint8_t *bytes, uint64_t nbytes, const uint8_t *seed, uint64_t slen)>(0xB05600);
};

namespace MNM
{

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class TileGenerator // Id=800A299 Size=34816
{
public:
	enum
	{
		MaxTileSizeX = 18,
		MaxTileSizeY = 18,
		MaxTileSizeZ = 18,
	};

	struct Params // Id=800A29A Size=136
	{
		enum class Flags
		{
			NoBorder = 1,
			NoErosion = 2,
			NoHashTest = 4,
			BuildBVTree = 8,
			DebugInfo = 128,
		};

		Vec3 origin;
		Vec3 voxelSize;
		float climbableInclineGradient;
		float climbableStepRatio;
		uint16_t flags;
		uint16_t minWalkableArea;
		uint16_t exclusionCount;
		uint8_t blurAmount;
		uint8_t sizeX;
		uint8_t sizeY;
		uint8_t sizeZ;
		
		struct AgentSettings // Id=800A29B Size=48
		{
			unsigned radius : 8;
			unsigned height : 8;
			unsigned climbableHeight : 8;
			unsigned maxWaterDepth : 8;
			Functor2wRet<IPhysicalEntity &,unsigned int &,bool> callback;
			uint16_t downwardSearch;
			bool bTestHeight;
		};

		MNM::TileGenerator::Params::AgentSettings agent;
		MNM::BoundingVolume const *boundary;
		MNM::BoundingVolume const *exclusions;
		unsigned hashValue;
		TNavigationID<0> meshId;
		uint64_t tileName;
		bool bBackground;
	};

	enum class ProfilerTimers
	{
		Voxelization = 0,
		Filter = 1,
		DistanceTransform = 2,
		Blur = 3,
		ContourExtraction = 4,
		Simplification = 5,
		Triangulation = 6,
		BVTreeConstruction = 7,
	};

	enum class ProfilerMemoryUsers
	{
		DynamicSpanGridMemory = 0,
		CompactSpanGridMemory = 1,
		SegmentationMemory = 2,
		RegionMemory = 3,
		PolygonMemory = 4,
		TriangulationMemory = 5,
		VertexMemory = 6,
		TriangleMemory = 7,
		BVTreeConstructionMemory = 8,
		BVTreeMemory = 9,
	};

	enum class ProfilerStats
	{
		VoxelizationTriCount = 0,
		RegionCount = 1,
		PolygonCount = 2,
		TriangleCount = 3,
		VertexCount = 4,
		BVTreeNodeCount = 5,
	};

	enum class DrawMode
	{
		DrawNone = 0,
		DrawRawVoxels = 1,
		DrawFlaggedVoxels = 2,
		DrawDistanceTransform = 3,
		DrawSegmentation = 4,
		DrawContourVertices = 5,
		DrawNumberedContourVertices = 6,
		DrawTracers = 7,
		DrawSimplifiedContours = 8,
		DrawTriangulation = 9,
		DrawBVTree = 10,
		LastDrawMode = 11,
	};

	using ProfilerType = MNM::Profiler<enum MNM::TileGenerator::ProfilerMemoryUsers,enum MNM::TileGenerator::ProfilerTimers,enum MNM::TileGenerator::ProfilerStats>;
	
	enum class SpanFlags
	{
		NotWalkable = 1,
		TileBoundary = 2,
	};

	enum class Labels
	{
		FirstInvalidLabel = 4095,
		NoLabel = 4095,
		ExternalContour = 4096,
		InternalContour = 8192,
		BorderLabelH = 16384,
		BorderLabelV = 32768,
	};

	enum class Paint
	{
		NoPaint = 0,
		BadPaint = 1,
		OkPaintStart = 2,
	};

	using SpanExtraInfo = std::vector<unsigned short>;
	
	struct ContourVertex // Id=800A29F Size=8
	{
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint16_t flags;
		
		enum class Flags
		{
			TileBoundary = 1,
			TileBoundaryV = 2,
			Unremovable = 4,
			TileSideA = 16,
			TileSideB = 32,
			TileSideC = 64,
			TileSideD = 128,
			TileSides = 240,
		};

#if 0
		bool operator<(MNM::TileGenerator::ContourVertex const &arg0) const;
		bool operator==(MNM::TileGenerator::ContourVertex const &arg0) const;
#endif
	};

	using Contour = std::vector<MNM::TileGenerator::ContourVertex>;
	using Contours = std::vector<std::vector<MNM::TileGenerator::ContourVertex>>;
	
	struct PolygonVertex // Id=800A2C0 Size=8
	{
		enum class Flags
		{
			Reflex = 1,
			Ear = 2,
		};

		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint16_t flags;
		
#if 0
		bool operator<(MNM::TileGenerator::ContourVertex const &arg0) const;
		bool operator==(MNM::TileGenerator::ContourVertex const &arg0) const;
#endif
	};

	using PolygonContour = std::vector<MNM::TileGenerator::PolygonVertex>;
	
	struct Hole // Id=800A2D7 Size=40
	{
		std::vector<MNM::TileGenerator::PolygonVertex> verts;
		Vec2i center;
		int rad;
	};

	using PolygonHoles = std::vector<MNM::TileGenerator::Hole>;
	using VoxelContour = std::vector<MNM::TileGenerator::PolygonVertex>;
	
	struct Polygon // Id=800A2EA Size=48
	{
		std::vector<MNM::TileGenerator::PolygonVertex> contour;
		std::vector<MNM::TileGenerator::Hole> holes;
	};

	struct Region // Id=800A2EB Size=64
	{
		enum class Flags
		{
			TileBoundary = 1,
			TileBoundaryV = 2,
		};

		std::vector<MNM::TileGenerator::ContourVertex> contour;
		std::vector<std::vector<MNM::TileGenerator::ContourVertex>> holes;
		uint64_t spanCount;
		uint64_t flags;
		
#if 0
		void swap(MNM::TileGenerator::Region &arg0);
#endif
	};

	struct NeighbourInfoRequirements // Id=800A2EC Size=4
	{
		uint16_t paint;
		uint16_t notPaint;
	};

	struct NeighbourInfo // Id=800A2ED Size=32
	{
		Vec2i pos;
		uint64_t top;
		uint64_t index;
		uint16_t label;
		uint16_t paint;
		bool isValid;
		
#if 0
		bool Check(MNM::TileGenerator::NeighbourInfoRequirements const &arg0) const;
#endif
	};

	enum class TracerDir
	{
		N = 0,
		E = 1,
		S = 2,
		W = 3,
		TOTAL_DIR = 4,
	};

	struct Tracer // Id=800A2EE Size=40
	{
		Vec3i pos;
		int dir;
		uint64_t indexIn;
		uint64_t indexOut;
		bool bPinchPoint;
		
#if 0
		bool operator==(MNM::TileGenerator::Tracer const &arg0) const;
		bool operator!=(MNM::TileGenerator::Tracer const &arg0) const;
		void SetPos(MNM::TileGenerator::NeighbourInfo const &arg0);
		void TurnRight();
		void TurnLeft();
		Vec2i GetDir() const;
		Vec3i GetFront() const;
		Vec3i GetLeft() const;
		Vec3i GetFrontLeft() const;
#endif
	};

	struct TracerPath // Id=800A2EF Size=32
	{
		using Tracers = std::vector<MNM::TileGenerator::Tracer>;
		
		std::vector<MNM::TileGenerator::Tracer> steps;
		int turns;
	};

	using VertexIndexLookUp = simple_hash_lookup<unsigned int,unsigned short,default_integer_hash<4>,unsigned __int64>;
	
	struct SurroundingSpanInfo // Id=800A305 Size=24
	{
		uint64_t flags;
		uint64_t index;
		uint16_t label;
	};

	enum class NeighbourClassification
	{
		UW = 0,
		NB = 1,
		WB = 2,
	};

	MNM::TileGenerator::Params m_params;
	MNM::Profiler<enum MNM::TileGenerator::ProfilerMemoryUsers,enum MNM::TileGenerator::ProfilerTimers,enum MNM::TileGenerator::ProfilerStats> m_profiler;
	uint64_t m_top;
	
	using Triangles = std::vector<MNM::Tile::Triangle>;
	
	std::vector<MNM::Tile::Triangle> m_triangles;
	
	using Vertices = std::vector<MNM::FixedVec3<unsigned short,5>>;
	
	std::vector<MNM::FixedVec3<unsigned short,5>> m_vertices;
	
	using BVTree = std::vector<MNM::Tile::BVNode>;
	
	std::vector<MNM::Tile::BVNode> m_bvtree;
	MNM::CompactSpanGrid m_spanGrid;
	std::vector<unsigned short> m_distances;
	std::vector<unsigned short> m_labels;
	std::vector<unsigned short> m_paint;
	
	using Regions = std::vector<MNM::TileGenerator::Region>;
	
	std::vector<MNM::TileGenerator::Region> m_regions;
	
	using Polygons = std::vector<MNM::TileGenerator::Polygon>;
	
	std::vector<MNM::TileGenerator::Polygon> m_polygons;
	
	using TracerPaths = std::vector<MNM::TileGenerator::TracerPath>;
	
	std::vector<MNM::TileGenerator::TracerPath> m_tracerPaths;
	MNM::CompactSpanGrid m_spanGridFlagged;
	bool m_bFullyContained;
	unsigned m_hashSeed;
	AABB m_AABB;
	MNM::WorldVoxelizer m_voxelizer;
	
	bool Generate(MNM::TileGenerator::Params const &params, MNM::Tile &tile, unsigned *tileHash) { return FGenerate(this,params,tile,tileHash); }
	bool GenerateJobStep1Startup(MNM::TileGenerator::Params const &_params) { return FGenerateJobStep1Startup(this,_params); }
	void GenerateJobStep2Voxelize(MNM::Tile &_tile, unsigned *_tileHash, int _callbackContext) { FGenerateJobStep2Voxelize(this,_tile,_tileHash,_callbackContext); }
	bool GenerateJobStep3VoxelizeFinish(MNM::Tile &_tile) { return FGenerateJobStep3VoxelizeFinish(this,_tile); }
	bool GenerateJobStep4Finish(MNM::Tile &_tile) { return FGenerateJobStep4Finish(this,_tile); }
	void Draw(MNM::TileGenerator::DrawMode mode) const { FDraw(this,mode); }
	MNM::Profiler<enum MNM::TileGenerator::ProfilerMemoryUsers,enum MNM::TileGenerator::ProfilerTimers,enum MNM::TileGenerator::ProfilerStats> const &GetProfiler() const { return FGetProfiler(this); }
	void Clear() { FClear(this); }
	uint64_t VoxelizeVolume(AABB const &volume, unsigned hashValueSeed, unsigned *hashValue) { return FVoxelizeVolume(this,volume,hashValueSeed,hashValue); }
	void FilterWalkable(AABB const &aabb, bool fullyContained) { FFilterWalkable(this,aabb,fullyContained); }
	void ComputeDistanceTransform() { FComputeDistanceTransform(this); }
	void PaintBorder(uint16_t *data, uint64_t borderH, uint64_t borderV) { FPaintBorder(this,data,borderH,borderV); }
	void TraceContour(MNM::TileGenerator::TracerPath &path, MNM::TileGenerator::Tracer const &start, uint64_t erosion, uint64_t climbableVoxelCount, MNM::TileGenerator::NeighbourInfoRequirements const &contourReq) { FTraceContour(this,path,start,erosion,climbableVoxelCount,contourReq); }
	int LabelTracerPath(MNM::TileGenerator::TracerPath const &path, uint64_t climbableVoxelCount, MNM::TileGenerator::Region &region, std::vector<MNM::TileGenerator::ContourVertex> &contour, const uint16_t internalLabel, const uint16_t internalLabelFlags, const uint16_t externalLabel) { return FLabelTracerPath(this,path,climbableVoxelCount,region,contour,internalLabel,internalLabelFlags,externalLabel); }
	uint64_t ExtractContours() { return FExtractContours(this); }
	void CalcPaintValues() { FCalcPaintValues(this); }
	void FilterBadRegions(uint64_t minSpanCount) { FFilterBadRegions(this,minSpanCount); }
	bool SimplifyContour(std::vector<MNM::TileGenerator::ContourVertex> const &contour, fixed_t<int,16> const &tolerance2DSq, fixed_t<int,16> const &tolerance3DSq, std::vector<MNM::TileGenerator::PolygonVertex> &poly) { return FSimplifyContour(this,contour,tolerance2DSq,tolerance3DSq,poly); }
	void SimplifyContours() { FSimplifyContours(this); }
	void MergeHole(std::vector<MNM::TileGenerator::PolygonVertex> &contour, const uint64_t contourVertex, std::vector<MNM::TileGenerator::PolygonVertex> const &hole, const uint64_t holeVertex, const int distSqr) const { FMergeHole(this,contour,contourVertex,hole,holeVertex,distSqr); }
	uint64_t Triangulate(MNM::TileGenerator::Params const &params, std::vector<MNM::TileGenerator::PolygonVertex> &contour, const uint64_t agentHeight, const uint64_t borderH, const uint64_t borderV, simple_hash_lookup<unsigned int,unsigned short,default_integer_hash<4>,unsigned __int64> &lookUp) { return FTriangulateOv1(this,params,contour,agentHeight,borderH,borderV,lookUp); }
	uint64_t Triangulate(MNM::TileGenerator::Params const &params) { return FTriangulateOv0(this,params); }
	void BuildBVTree() { FBuildBVTree(this); }
	bool GatherSurroundingInfo(Vec2i const &vertex, Vec2i const &direction, const uint16_t top, const uint16_t climbableVoxelCount, uint64_t &height, MNM::TileGenerator::SurroundingSpanInfo &left, MNM::TileGenerator::SurroundingSpanInfo &front, MNM::TileGenerator::SurroundingSpanInfo &frontLeft) const { return FGatherSurroundingInfo(this,vertex,direction,top,climbableVoxelCount,height,left,front,frontLeft); }
	void DetermineContourVertex(Vec2i const &vertex, Vec2i const &direction, uint16_t top, uint16_t climbableVoxelCount, MNM::TileGenerator::ContourVertex &contourVertex) const { FDetermineContourVertex(this,vertex,direction,top,climbableVoxelCount,contourVertex); }
	uint64_t InsertUniqueVertex(simple_hash_lookup<unsigned int,unsigned short,default_integer_hash<4>,unsigned __int64> &lookUp, uint64_t x, uint64_t y, uint64_t z) { return FInsertUniqueVertex(this,lookUp,x,y,z); }
	
#if 0
	uint64_t BorderSizeH() const;
	uint64_t BorderSizeV() const;
	bool IsBorderCell(uint64_t arg0, uint64_t arg1) const;
	bool IsBoundaryCell_Static(uint64_t arg0, uint64_t arg1, const uint64_t arg2, const uint64_t arg3, const uint64_t arg4) const;
	bool IsBoundaryCell(uint64_t arg0, uint64_t arg1) const;
	bool IsBoundaryVertex(uint64_t arg0, uint64_t arg1) const;
	bool IsCornerVertex(uint64_t arg0, uint64_t arg1) const;
	bool IsBoundaryVertexV(uint64_t arg0) const;
	void BlurDistanceTransform();
	uint16_t GetPaintVal(uint64_t arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);
	void AssessNeighbour(MNM::TileGenerator::NeighbourInfo &arg0, uint64_t arg1, uint64_t arg2);
	void TidyUpContourEnd(std::vector<MNM::TileGenerator::ContourVertex> &arg0);
	void CacheTracerPath(MNM::TileGenerator::TracerPath const &arg0);
	MNM::TileGenerator::NeighbourClassification ClassifyNeighbour(MNM::TileGenerator::SurroundingSpanInfo const &arg0, uint64_t arg1, uint64_t arg2) const;
	bool ContourVertexRemovable(MNM::TileGenerator::ContourVertex const &arg0) const;
	void AddContourVertex(MNM::TileGenerator::ContourVertex const &arg0, MNM::TileGenerator::Region &arg1, std::vector<MNM::TileGenerator::ContourVertex> &arg2) const;
#endif
	
	static inline auto FGenerate = PreyFunction<bool(MNM::TileGenerator *const _this, MNM::TileGenerator::Params const &params, MNM::Tile &tile, unsigned *tileHash)>(0x6533C0);
	static inline auto FGenerateJobStep1Startup = PreyFunction<bool(MNM::TileGenerator *const _this, MNM::TileGenerator::Params const &_params)>(0x654310);
	static inline auto FGenerateJobStep2Voxelize = PreyFunction<void(MNM::TileGenerator *const _this, MNM::Tile &_tile, unsigned *_tileHash, int _callbackContext)>(0x6550E0);
	static inline auto FGenerateJobStep3VoxelizeFinish = PreyFunction<bool(MNM::TileGenerator *const _this, MNM::Tile &_tile)>(0x6551A0);
	static inline auto FGenerateJobStep4Finish = PreyFunction<bool(MNM::TileGenerator *const _this, MNM::Tile &_tile)>(0x655300);
	static inline auto FDraw = PreyFunction<void(MNM::TileGenerator const *const _this, MNM::TileGenerator::DrawMode mode)>(0x65BCE0);
	static inline auto FGetProfiler = PreyFunction<MNM::Profiler<enum MNM::TileGenerator::ProfilerMemoryUsers,enum MNM::TileGenerator::ProfilerTimers,enum MNM::TileGenerator::ProfilerStats> const &(MNM::TileGenerator const *const _this)>(0x10BD7F0);
	static inline auto FClear = PreyFunction<void(MNM::TileGenerator *const _this)>(0x650510);
	static inline auto FVoxelizeVolume = PreyFunction<uint64_t(MNM::TileGenerator *const _this, AABB const &volume, unsigned hashValueSeed, unsigned *hashValue)>(0x659950);
	static inline auto FFilterWalkable = PreyFunction<void(MNM::TileGenerator *const _this, AABB const &aabb, bool fullyContained)>(0x652160);
	static inline auto FComputeDistanceTransform = PreyFunction<void(MNM::TileGenerator *const _this)>(0x650670);
	static inline auto FPaintBorder = PreyFunction<void(MNM::TileGenerator *const _this, uint16_t *data, uint64_t borderH, uint64_t borderV)>(0x655DC0);
	static inline auto FTraceContour = PreyFunction<void(MNM::TileGenerator *const _this, MNM::TileGenerator::TracerPath &path, MNM::TileGenerator::Tracer const &start, uint64_t erosion, uint64_t climbableVoxelCount, MNM::TileGenerator::NeighbourInfoRequirements const &contourReq)>(0x657D30);
	static inline auto FLabelTracerPath = PreyFunction<int(MNM::TileGenerator *const _this, MNM::TileGenerator::TracerPath const &path, uint64_t climbableVoxelCount, MNM::TileGenerator::Region &region, std::vector<MNM::TileGenerator::ContourVertex> &contour, const uint16_t internalLabel, const uint16_t internalLabelFlags, const uint16_t externalLabel)>(0x6557B0);
	static inline auto FExtractContours = PreyFunction<uint64_t(MNM::TileGenerator *const _this)>(0x651510);
	static inline auto FCalcPaintValues = PreyFunction<void(MNM::TileGenerator *const _this)>(0x650200);
	static inline auto FFilterBadRegions = PreyFunction<void(MNM::TileGenerator *const _this, uint64_t minSpanCount)>(0x652000);
	static inline auto FSimplifyContour = PreyFunction<bool(MNM::TileGenerator *const _this, std::vector<MNM::TileGenerator::ContourVertex> const &contour, fixed_t<int,16> const &tolerance2DSq, fixed_t<int,16> const &tolerance3DSq, std::vector<MNM::TileGenerator::PolygonVertex> &poly)>(0x6561C0);
	static inline auto FSimplifyContours = PreyFunction<void(MNM::TileGenerator *const _this)>(0x656940);
	static inline auto FMergeHole = PreyFunction<void(MNM::TileGenerator const *const _this, std::vector<MNM::TileGenerator::PolygonVertex> &contour, const uint64_t contourVertex, std::vector<MNM::TileGenerator::PolygonVertex> const &hole, const uint64_t holeVertex, const int distSqr)>(0x655BF0);
	static inline auto FTriangulateOv1 = PreyFunction<uint64_t(MNM::TileGenerator *const _this, MNM::TileGenerator::Params const &params, std::vector<MNM::TileGenerator::PolygonVertex> &contour, const uint64_t agentHeight, const uint64_t borderH, const uint64_t borderV, simple_hash_lookup<unsigned int,unsigned short,default_integer_hash<4>,unsigned __int64> &lookUp)>(0x6590C0);
	static inline auto FTriangulateOv0 = PreyFunction<uint64_t(MNM::TileGenerator *const _this, MNM::TileGenerator::Params const &params)>(0x6581C0);
	static inline auto FBuildBVTree = PreyFunction<void(MNM::TileGenerator *const _this)>(0x64FAA0);
	static inline auto FGatherSurroundingInfo = PreyFunction<bool(MNM::TileGenerator const *const _this, Vec2i const &vertex, Vec2i const &direction, const uint16_t top, const uint16_t climbableVoxelCount, uint64_t &height, MNM::TileGenerator::SurroundingSpanInfo &left, MNM::TileGenerator::SurroundingSpanInfo &front, MNM::TileGenerator::SurroundingSpanInfo &frontLeft)>(0x653190);
	static inline auto FDetermineContourVertex = PreyFunction<void(MNM::TileGenerator const *const _this, Vec2i const &vertex, Vec2i const &direction, uint16_t top, uint16_t climbableVoxelCount, MNM::TileGenerator::ContourVertex &contourVertex)>(0x650CF0);
	static inline auto FInsertUniqueVertex = PreyFunction<uint64_t(MNM::TileGenerator *const _this, simple_hash_lookup<unsigned int,unsigned short,default_integer_hash<4>,unsigned __int64> &lookUp, uint64_t x, uint64_t y, uint64_t z)>(0x655530);
};

} // namespace MNM

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CFXNodeDescription::TControlParam<bool> : public CFXNodeDescription::CControlParamBase // Id=800D7A7 Size=32
{
public:
	bool m_defaultValue;
	
#if 0
	virtual void SetDefault(float val);
	virtual void SetDefault(bool val);
	virtual void SetDefault(Vec4 val);
	virtual void GetDefault(float &val) const;
	virtual void GetDefault(bool &val) const;
	virtual void GetDefault(Vec4 &val) const;
	virtual ~TControlParam<bool>();
	void TControlParam<bool>();
	void TControlParam<bool>(CFXNodeDescription::TControlParam<bool> const &arg0);
#endif
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CLog : public ILog // Id=8010019 Size=66744
{
public:
	using Callbacks = std::list<ILogCallback *,std::allocator<ILogCallback *> >;
	using LogStringType = CryFixedStringT<2048>;
	
	ISystem *m_pSystem;
	float m_fLastLoadingUpdateTime;
	char m_szFilename[256];
	char m_sBackupFilename[256];
	_iobuf *m_pLogFile;
	CryStackStringT<char,32> m_LogMode;
	_iobuf *m_pErrFile;
	int m_nErrCount;
	ICVar *m_pLogIncludeTime;
	IConsole *m_pConsole;
	CryLockT<2> m_logCriticalSection;
	
	struct SLogHistoryItem // Id=801002D Size=4120
	{
		char str[4096];
		const char *formatPtr;
		IMiniLog::ELogType type;
		float time;
		int count;
	};

	CLog::SLogHistoryItem m_history[16];
	int m_iLastHistoryItem;
	ICVar *m_pLogVerbosity;
	ICVar *m_pLogWriteToFile;
	ICVar *m_pLogWriteToFileVerbosity;
	ICVar *m_pLogVerbosityOverridesWriteToFile;
	ICVar *m_pLogSpamDelay;
	ICVar *m_pLogSpamThreshold;
	ICVar *m_pLogModule;
	std::list<ILogCallback *,std::allocator<ILogCallback *> > m_callbacks;
	unsigned long m_nMainThreadId;
	
	struct SLogMsg // Id=801002E Size=515
	{
		char msg[512];
		bool bError;
		bool bAdd;
		bool bConsole;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	CryMT::queue<CLog::SLogMsg,std::allocator<CLog::SLogMsg> > m_threadSafeMsgQueue;
	
	CLog(ISystem *pSystem);
	virtual void Release();
	virtual bool SetFileName(const char *filename);
	virtual const char *GetFileName();
	virtual const char *GetBackupFileName();
	virtual void LogComment(const char *szFormat, ... arg1);
	virtual void Log(const char *szFormat, ... arg1);
	virtual void LogAlways(const char *szFormat, ... arg1);
	virtual void LogWarning(const char *szFormat, ... ArgList);
	virtual void LogError(const char *szFormat, ... ArgList);
	virtual void LogPlus(const char *szFormat, ... szTemp);
	virtual void LogToFile(const char *szFormat, ... szTemp);
	virtual void LogToFilePlus(const char *szFormat, ... szTemp);
	virtual void LogToConsole(const char *szFormat, ... szBuffer);
	virtual void LogToConsolePlus(const char *szFormat, ... szTemp);
	virtual void UpdateLoadingScreen(const char *szFormat, ... arg1);
	virtual void SetVerbosity(int verbosity);
	virtual int GetVerbosityLevel();
	virtual void RegisterConsoleVariables();
	virtual void UnregisterConsoleVariables();
	virtual void AddCallback(ILogCallback *pCallback);
	virtual void RemoveCallback(ILogCallback *pCallback);
	virtual void LogV(IMiniLog::ELogType type, int flags, const char *szFormat, char *args);
	virtual void LogV(IMiniLog::ELogType type, const char *szFormat, char *args);
	virtual void Update();
	virtual const char *GetModuleFilter();
	virtual void FlushAndClose();
	void LogStringToFile(const char *szString, bool bAdd, bool bError) { FLogStringToFile(this,szString,bAdd,bError); }
	void LogStringToConsole(const char *szString, bool bAdd) { FLogStringToConsole(this,szString,bAdd); }
	void CloseLogFile(bool forceClose) { FCloseLogFile(this,forceClose); }
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	void CreateBackupFile() const { FCreateBackupFile(this); }
	
#if 0
	_iobuf *OpenLogFile(const char *arg0, const char *arg1);
	void FormatMessageA(const char *arg0, ... arg1);
	const char *CheckAgainstVerbosity(const char *arg0, bool &arg1, bool &arg2, const uint8_t arg3);
#endif
	
	static inline auto FRelease = PreyFunction<void(CLog *const _this)>(0x5A2F30);
	static inline auto FSetFileName = PreyFunction<bool(CLog *const _this, const char *filename)>(0xDB2220);
	static inline auto FGetFileName = PreyFunction<const char *(CLog *const _this)>(0x12BDAA0);
	static inline auto FGetBackupFileName = PreyFunction<const char *(CLog *const _this)>(0x10BD3B0);
	static inline auto FLogComment = PreyFunction<void(CLog *const _this, const char *szFormat, ... arg1)>(0xDAEDE0);
	static inline auto FLog = PreyFunction<void(CLog *const _this, const char *szFormat, ... arg1)>(0xDAED80);
	static inline auto FLogAlways = PreyFunction<void(CLog *const _this, const char *szFormat, ... arg1)>(0xDAEDB0);
	static inline auto FLogWarning = PreyFunction<void(CLog *const _this, const char *szFormat, ... ArgList)>(0xDB1E30);
	static inline auto FLogError = PreyFunction<void(CLog *const _this, const char *szFormat, ... ArgList)>(0xDAEE10);
	static inline auto FLogPlus = PreyFunction<void(CLog *const _this, const char *szFormat, ... szTemp)>(0xDAEED0);
	static inline auto FLogToFile = PreyFunction<void(CLog *const _this, const char *szFormat, ... szTemp)>(0xDB11C0);
	static inline auto FLogToFilePlus = PreyFunction<void(CLog *const _this, const char *szFormat, ... szTemp)>(0xDB12B0);
	static inline auto FLogToConsole = PreyFunction<void(CLog *const _this, const char *szFormat, ... szBuffer)>(0xDB0FE0);
	static inline auto FLogToConsolePlus = PreyFunction<void(CLog *const _this, const char *szFormat, ... szTemp)>(0xDB10D0);
	static inline auto FUpdateLoadingScreen = PreyFunction<void(CLog *const _this, const char *szFormat, ... arg1)>(0xDB26D0);
	static inline auto FSetVerbosity = PreyFunction<void(CLog *const _this, int verbosity)>(0xDB2360);
	static inline auto FGetVerbosityLevel = PreyFunction<int(CLog *const _this)>(0xDAED60);
	static inline auto FRegisterConsoleVariables = PreyFunction<void(CLog *const _this)>(0xDB1EF0);
	static inline auto FUnregisterConsoleVariables = PreyFunction<void(CLog *const _this)>(0xDB2380);
	static inline auto FAddCallback = PreyFunction<void(CLog *const _this, ILogCallback *pCallback)>(0xDADD10);
	static inline auto FRemoveCallback = PreyFunction<void(CLog *const _this, ILogCallback *pCallback)>(0xDB2160);
	static inline auto FLogVOv1 = PreyFunction<void(CLog *const _this, IMiniLog::ELogType type, int flags, const char *szFormat, char *args)>(0xDB13A0);
	static inline auto FLogVOv0 = PreyFunction<void(CLog *const _this, IMiniLog::ELogType type, const char *szFormat, char *args)>(0xDB1E10);
	static inline auto FUpdate = PreyFunction<void(CLog *const _this)>(0xDB23C0);
	static inline auto FGetModuleFilter = PreyFunction<const char *(CLog *const _this)>(0xDAED40);
	static inline auto FFlushAndClose = PreyFunction<void(CLog *const _this)>(0xA13080);
	static inline auto FLogStringToFile = PreyFunction<void(CLog *const _this, const char *szString, bool bAdd, bool bError)>(0xDAF4A0);
	static inline auto FLogStringToConsole = PreyFunction<void(CLog *const _this, const char *szString, bool bAdd)>(0xDAF020);
	static inline auto FCloseLogFile = PreyFunction<void(CLog *const _this, bool forceClose)>(0xDADDB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CLog const *const _this, ICrySizer *pSizer)>(0xDAEC10);
	static inline auto FCreateBackupFile = PreyFunction<void(CLog const *const _this)>(0xDADDE0);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkUnanimous // Id=801348B Size=16
{
public:
	uint64_t m_trueCount;
	uint64_t m_falseCount;
	
	ArkUnanimous();
	ArkUnanimous(uint64_t _trueCount);
	bool PushTrue() { return FPushTrue(this); }
	bool PopTrue() { return FPopTrue(this); }
	bool PushFalse() { return FPushFalse(this); }
	bool PopFalse() { return FPopFalse(this); }
	bool IsUnanimous() const { return FIsUnanimous(this); }
	void SetTrueCount(uint64_t _trueCount) { FSetTrueCount(this,_trueCount); }
	void SetFalseCount(uint64_t _falseCount) { FSetFalseCount(this,_falseCount); }
	uint64_t GetTrueCount() const { return FGetTrueCount(this); }
	uint64_t GetFalseCount() const { return FGetFalseCount(this); }
	
#if 0
	int *operator int ArkSafeBool<class ArkUnanimous>::*() const;
#endif
	
	static inline auto FPushTrue = PreyFunction<bool(ArkUnanimous *const _this)>(0x1056F20);
	static inline auto FPopTrue = PreyFunction<bool(ArkUnanimous *const _this)>(0x1056EE0);
	static inline auto FPushFalse = PreyFunction<bool(ArkUnanimous *const _this)>(0x1056F00);
	static inline auto FPopFalse = PreyFunction<bool(ArkUnanimous *const _this)>(0x1056EC0);
	static inline auto FIsUnanimous = PreyFunction<bool(ArkUnanimous const *const _this)>(0x1056EA0);
	static inline auto FSetTrueCount = PreyFunction<void(ArkUnanimous *const _this, uint64_t _trueCount)>(0x10BE320);
	static inline auto FSetFalseCount = PreyFunction<void(ArkUnanimous *const _this, uint64_t _falseCount)>(0x414F30);
	static inline auto FGetTrueCount = PreyFunction<uint64_t(ArkUnanimous const *const _this)>(0x12E5E70);
	static inline auto FGetFalseCount = PreyFunction<uint64_t(ArkUnanimous const *const _this)>(0x12AAC70);
};

namespace EntityEffects
{

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CEffectsController // Id=8013ED2 Size=40
{
public:
	using TAttachedEffects = std::vector<EntityEffects::SEffectInfo>;
	
	IEntity *m_pOwnerEntity;
	std::vector<EntityEffects::SEffectInfo> m_attachedEffects;
	unsigned m_effectGeneratorId;
	
	CEffectsController();
	void InitWithEntity(IEntity *pEntity) { FInitWithEntity(this,pEntity); }
	void FreeAllEffects() { FFreeAllEffects(this); }
	unsigned AttachParticleEffect(IParticleEffect *pParticleEffect, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv3(this,pParticleEffect,attachParams); }
	unsigned AttachParticleEffect(const char *effectName, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv2(this,effectName,attachParams); }
	unsigned AttachParticleEffect(IParticleEffect *pParticleEffect, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv1(this,pParticleEffect,targetSlot,helperName,attachParams); }
	unsigned AttachParticleEffect(const char *effectName, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv0(this,effectName,targetSlot,helperName,attachParams); }
	void DetachEffect(const unsigned effectId) { FDetachEffect(this,effectId); }
	IParticleEmitter *GetEffectEmitter(const unsigned effectId) const { return FGetEffectEmitter(this,effectId); }
	int FindSafeSlot(int firstSafeSlot) { return FFindSafeSlot(this,firstSafeSlot); }
	
#if 0
	unsigned AttachLight(const int arg0, const char *arg1, EntityEffects::SLightAttachParams const &arg2);
	EntityEffects::SEffectInfo const &GetEffectInfoAt(const unsigned arg0) const;
	unsigned GetEffectCount() const;
	ILightSource *GetLightSource(const unsigned arg0) const;
	void SetEffectWorldTM(const unsigned arg0, Matrix34 const &arg1);
	void UpdateEntitySlotEffectLocationsFromHelpers();
	void GetMemoryStatistics(ICrySizer *arg0) const;
#endif
	
	static inline auto FInitWithEntity = PreyFunction<void(EntityEffects::CEffectsController *const _this, IEntity *pEntity)>(0x10BE320);
	static inline auto FFreeAllEffects = PreyFunction<void(EntityEffects::CEffectsController *const _this)>(0x16BCC80);
	static inline auto FAttachParticleEffectOv3 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, IParticleEffect *pParticleEffect, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC120);
	static inline auto FAttachParticleEffectOv2 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, const char *effectName, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC9B0);
	static inline auto FAttachParticleEffectOv1 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, IParticleEffect *pParticleEffect, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC3E0);
	static inline auto FAttachParticleEffectOv0 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, const char *effectName, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC9F0);
	static inline auto FDetachEffect = PreyFunction<void(EntityEffects::CEffectsController *const _this, const unsigned effectId)>(0x16BCA40);
	static inline auto FGetEffectEmitter = PreyFunction<IParticleEmitter *(EntityEffects::CEffectsController const *const _this, const unsigned effectId)>(0x16BCD20);
	static inline auto FFindSafeSlot = PreyFunction<int(EntityEffects::CEffectsController *const _this, int firstSafeSlot)>(0x16BCBD0);
};

} // namespace EntityEffects

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkNpcBlackboardEntry_LostVisibilityTime : public ArkNpcBlackboardEntryTemplate_GetUpdate<ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardEntryKey_LostVisibilityTime,ArkNpcBlackboardEntry_LostVisibilityTime,float,float> // Id=80159E3 Size=4
{
public:
	float m_time;
	
	ArkNpcBlackboardEntry_LostVisibilityTime();
	float Get() const { return FGet(this); }
	void Update(ArkNpcBlackboardEntryKey_LostVisibilityTime const &_entryKey, float _elapsedTime) { FUpdate(this,_entryKey,_elapsedTime); }
	
	static inline auto FGet = PreyFunction<float(ArkNpcBlackboardEntry_LostVisibilityTime const *const _this)>(0x10BDAB0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_LostVisibilityTime *const _this, ArkNpcBlackboardEntryKey_LostVisibilityTime const &_entryKey, float _elapsedTime)>(0x12104A0);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkNpcBlackboardEntry_VisibilityTime : public ArkNpcBlackboardEntryTemplate_GetUpdate<ArkNpcBlackboardKey_VisibilityTime,ArkNpcBlackboardEntryKey_VisibilityTime,ArkNpcBlackboardEntry_VisibilityTime,float,float> // Id=80159EF Size=4
{
public:
	float m_time;
	
	ArkNpcBlackboardEntry_VisibilityTime();
	float Get() const { return FGet(this); }
	void Update(ArkNpcBlackboardEntryKey_VisibilityTime const &_entryKey, float _elapsedTime) { FUpdate(this,_entryKey,_elapsedTime); }
	
	static inline auto FGet = PreyFunction<float(ArkNpcBlackboardEntry_VisibilityTime const *const _this)>(0x10BDAB0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_VisibilityTime *const _this, ArkNpcBlackboardEntryKey_VisibilityTime const &_entryKey, float _elapsedTime)>(0x1210530);
};

namespace HazardSystem
{

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class HazardDataProjectile : public HazardSystem::HazardDataRayCast // Id=8016DE7 Size=104
{
public:
	using BaseClass = HazardSystem::HazardDataRayCast;
	
	Vec3 m_AreaStartPos;
	Vec3 m_MoveNormal;
	float m_Radius;
	float m_MaxScanDistance;
	float m_MaxPosDeviationDistance;
	float m_MaxCosAngleDeviation;
	float m_AreaLength;
	unsigned m_IgnoredWeaponEntityID;
	
	HazardDataProjectile();
	HazardDataProjectile(HazardSystem::HazardDataProjectile const &source);
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	virtual Vec3 const &GetNormal() const;
	virtual bool IsAgentAwareOfDanger(Agent const &agent, Vec3 const &avoidPos) const;
	virtual void CheckCollision(Agent &agent, HazardSystem::HazardCollisionResult *result) const;
	virtual float GetMaxRayCastDistance() const;
	virtual void ProcessRayCastResult(Vec3 const &rayStartPos, Vec3 const &rayNormal, RayCastResult const &result);
	
#if 0
	bool IsHazardAreaDefined() const;
	HazardSystem::HazardProjectileID GetTypeInstanceID() const;
	bool IsApproximationAcceptable(Vec3 const &arg0, Vec3 const &arg1) const;
#endif
	
	static inline auto FSerialize = PreyFunction<void(HazardSystem::HazardDataProjectile *const _this, TSerialize ser)>(0x109B520);
	static inline auto FGetNormal = PreyFunction<Vec3 const &(HazardSystem::HazardDataProjectile const *const _this)>(0x10BD7E0);
	static inline auto FIsAgentAwareOfDanger = PreyFunction<bool(HazardSystem::HazardDataProjectile const *const _this, Agent const &agent, Vec3 const &avoidPos)>(0x109B4A0);
	static inline auto FCheckCollision = PreyFunction<void(HazardSystem::HazardDataProjectile const *const _this, Agent &agent, HazardSystem::HazardCollisionResult *result)>(0x109B310);
	static inline auto FGetMaxRayCastDistance = PreyFunction<float(HazardSystem::HazardDataProjectile const *const _this)>(0x109B490);
	static inline auto FProcessRayCastResult = PreyFunction<void(HazardSystem::HazardDataProjectile *const _this, Vec3 const &rayStartPos, Vec3 const &rayNormal, RayCastResult const &result)>(0x109B4E0);
};

} // namespace HazardSystem

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkAiTreeGuardBeginStimulus : public ArkAiTreeStimulusTemplate<ArkAiTreeGuardBeginStimulus> // Id=8017E42 Size=40
{
public:
	Vec3 m_position;
	Ang3 m_rotation;
	
	static const char *ClassName() { return FClassName(); }
	ArkAiTreeGuardBeginStimulus();
	ArkAiTreeGuardBeginStimulus(Vec3 const &_position, Ang3 const &_rotation);
	Vec3 const &GetPosition() const { return FGetPosition(this); }
	Ang3 const &GetRotation() const { return FGetRotation(this); }
	virtual void Serialize(TSerialize _serializer);
	
	static inline auto FClassName = PreyFunction<const char *()>(0x1141680);
	static inline auto FGetPosition = PreyFunction<Vec3 const &(ArkAiTreeGuardBeginStimulus const *const _this)>(0x1296490);
	static inline auto FGetRotation = PreyFunction<Ang3 const &(ArkAiTreeGuardBeginStimulus const *const _this)>(0x12BDA40);
	static inline auto FSerialize = PreyFunction<void(ArkAiTreeGuardBeginStimulus *const _this, TSerialize _serializer)>(0x1141690);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkPasswordProtected // Id=80193FF Size=16
{
public:
	uint64_t m_characterId;
	string m_proxyPassword;
	
	ArkPasswordProtected();
	static bool IsTouristMode() { return FIsTouristMode(); }
	bool IsHackOnly() const { return FIsHackOnly(this); }
	bool PlayerHasPassword() const { return FPlayerHasPassword(this); }
	void ResetProxyPassword() { FResetProxyPassword(this); }
	void SetCharacterId(const uint64_t _characterId) { FSetCharacterId(this,_characterId); }
	std::pair<string,string> GetCharacterInfo() const { return FGetCharacterInfo(this); }
	
#if 0
	string const &GetProxyPassword() const;
#endif
	
	static inline auto FIsTouristMode = PreyFunction<bool()>(0x13A2980);
	static inline auto FIsHackOnly = PreyFunction<bool(ArkPasswordProtected const *const _this)>(0x13A2960);
	static inline auto FPlayerHasPassword = PreyFunction<bool(ArkPasswordProtected const *const _this)>(0x13A2AA0);
	static inline auto FResetProxyPassword = PreyFunction<void(ArkPasswordProtected *const _this)>(0x13A2C00);
	static inline auto FSetCharacterId = PreyFunction<void(ArkPasswordProtected *const _this, const uint64_t _characterId)>(0x10BE320);
	static inline auto FGetCharacterInfo = PreyFunction<std::pair<string,string>(ArkPasswordProtected const *const _this)>(0x13A2740);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkOperatorLaserHelper // Id=80197FE Size=608
{
public:
	enum class Stage
	{
		Off = 0,
		Charging = 1,
		On = 2,
	};

	CArkLaserBeam m_laserBeam;
	CArkLaserBeam::ArkLaserParams params;
	string m_laserMatEffectName;
	Vec3 m_laserTarget;
	Vec3 m_beamCollisionPoint;
	uint64_t m_laserAttackPackageId;
	float m_laserDamagePerSecond;
	int m_laserHitTypeId;
	static constexpr const int k_beamEndVfxCount = 4;
	std::array<ArkLooseEffect,4> m_beamEndVfx;
	int m_currentBeamEndEffectIndex;
	float m_beamEndJumpDistSq;
	ArkSimpleTimer m_materialEffectCooldown;
	float m_chargeTimer;
	float m_maxLaserLength;
	ArkOperatorLaserHelper::Stage m_stage;
	
	ArkOperatorLaserHelper();
	~ArkOperatorLaserHelper() { FBitNotArkOperatorLaserHelper(this); }
	void InitializeLaserHelper(ArkNpc &_npc, float _laserDamagePerSecond) { FInitializeLaserHelper(this,_npc,_laserDamagePerSecond); }
	void StartChargingLaser(ArkNpc &_npc, float _chargeDuration) { FStartChargingLaser(this,_npc,_chargeDuration); }
	void TurnOffLaser(ArkNpc &_npc) { FTurnOffLaser(this,_npc); }
	void UpdateLaser(ArkNpc &_npc, float _elapsedTime) { FUpdateLaser(this,_npc,_elapsedTime); }
	QuatT GetLaserAttachmentTM(ArkNpc const &_npc) const { return FGetLaserAttachmentTM(this,_npc); }
	Vec3 const &GetBeamCollisionPoint() const { return FGetBeamCollisionPoint(this); }
	void DoMilitaryOperatorLaserDamage(ArkNpc &_npc, const float _frameTime, EventPhysCollision const &_collision) { FDoMilitaryOperatorLaserDamage(this,_npc,_frameTime,_collision); }
	
#if 0
	bool IsLaserOn() const;
	bool IsLaserCharging() const;
	void TurnOnLaser(ArkNpc &arg0);
	void SetLaserTarget(Vec3 const &arg0);
	void SetLaserDirection(ArkNpc const &arg0, Vec3 const &arg1);
	void UpdateBeamEndParticleEffect(ArkNpc &arg0, bool arg1, Vec3 const &arg2, Vec3 const &arg3);
	void UpdateBeamEndMaterialEffect(ArkNpc &arg0, EventPhysCollision const &arg1);
#endif
	
	static inline auto FBitNotArkOperatorLaserHelper = PreyFunction<void(ArkOperatorLaserHelper *const _this)>(0x1280DE0);
	static inline auto FInitializeLaserHelper = PreyFunction<void(ArkOperatorLaserHelper *const _this, ArkNpc &_npc, float _laserDamagePerSecond)>(0x1281510);
	static inline auto FStartChargingLaser = PreyFunction<void(ArkOperatorLaserHelper *const _this, ArkNpc &_npc, float _chargeDuration)>(0x1281630);
	static inline auto FTurnOffLaser = PreyFunction<void(ArkOperatorLaserHelper *const _this, ArkNpc &_npc)>(0x1281690);
	static inline auto FUpdateLaser = PreyFunction<void(ArkOperatorLaserHelper *const _this, ArkNpc &_npc, float _elapsedTime)>(0x1281700);
	static inline auto FGetLaserAttachmentTM = PreyFunction<QuatT(ArkOperatorLaserHelper const *const _this, ArkNpc const &_npc)>(0x1281250);
	static inline auto FGetBeamCollisionPoint = PreyFunction<Vec3 const &(ArkOperatorLaserHelper const *const _this)>(0x10BD5B0);
	static inline auto FDoMilitaryOperatorLaserDamage = PreyFunction<void(ArkOperatorLaserHelper *const _this, ArkNpc &_npc, const float _frameTime, EventPhysCollision const &_collision)>(0x1280F70);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkNpcAnimActionRagdollAndStandUp : public ArkNpcAnimAction // Id=8019975 Size=200
{
public:
	_smart_ptr<ArkNpcAnimActionStandUp> m_pDelayedStandUpAction;
	float m_stoppingTime;
	bool m_bStopping;
	
	virtual const char *GetName() const;
	virtual void DoDelete();
	ArkNpcAnimActionRagdollAndStandUp(ArkNpc &_npc, int priority, const int &fragID, STagState<12> const &sleepTagState, _smart_ptr<ArkNpcAnimActionStandUp> const &_pStandupAnimAction, bool bIndefinite);
	virtual void Enter();
	virtual IAction::EStatus Update(float _timePassed);
	virtual void Exit();
	virtual void Fail(EActionFailure _actionFailure);
	void Stop() { FStop(this); }
	_smart_ptr<ArkNpcAnimActionStandUp> const &GetStandUpAnimAction() const { return FGetStandUpAnimAction(this); }
	void StartStandup() { FStartStandup(this); }
	
#if 0
	void ForceFinish();
	bool IsStopping() const;
#endif
	
	static inline auto FGetName = PreyFunction<const char *(ArkNpcAnimActionRagdollAndStandUp const *const _this)>(0x11E27B0);
	static inline auto FDoDelete = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp *const _this)>(0xA97D40);
	static inline auto FEnter = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp *const _this)>(0x11E1FD0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkNpcAnimActionRagdollAndStandUp *const _this, float _timePassed)>(0x11E2A20);
	static inline auto FExit = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp *const _this)>(0x11E23B0);
	static inline auto FFail = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp *const _this, EActionFailure _actionFailure)>(0x11E24F0);
	static inline auto FStop = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp *const _this)>(0x11E2A00);
	static inline auto FGetStandUpAnimAction = PreyFunction<_smart_ptr<ArkNpcAnimActionStandUp> const &(ArkNpcAnimActionRagdollAndStandUp const *const _this)>(0x10BD800);
	static inline auto FStartStandup = PreyFunction<void(ArkNpcAnimActionRagdollAndStandUp *const _this)>(0x11E28C0);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CArkPsiPowerFaction<11> : public CArkPsiPower<CyberkinesisPowerProperties> // Id=801C8A6 Size=696
{
public:
	using PowerTraits = ArkPsiPowerFactionTraits<11>;
	using PowerProperties = CyberkinesisPowerProperties;
	using BaseType = CArkPsiPower<CyberkinesisPowerProperties>;
	
	ArkPsiPowerCyberkinesisProperties const *m_pProperties;
	ArkAudioTrigger m_onExecuteSoundTrigger;
	ArkPsiPowerIndividualTargetingComponent m_targetingComponent;
	
#if 0
	virtual void Cancel();
	virtual void UpdateTargeting(const float _frameTime);
	virtual bool StartTargeting();
	virtual void RefreshTargets();
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	virtual EArkPsiPowerError GetExecutionError() const;
	bool FilterTarget(IEntity const &_entity) const;
#endif
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CArkPsiPowerFaction<10> : public CArkPsiPower<HypnosisPowerProperties> // Id=801C8A7 Size=696
{
public:
	using PowerTraits = ArkPsiPowerFactionTraits<10>;
	using PowerProperties = HypnosisPowerProperties;
	using BaseType = CArkPsiPower<HypnosisPowerProperties>;
	
	ArkPsiPowerHypnosisProperties const *m_pProperties;
	ArkAudioTrigger m_onExecuteSoundTrigger;
	ArkPsiPowerIndividualTargetingComponent m_targetingComponent;
	
#if 0
	virtual void Cancel();
	virtual void UpdateTargeting(const float _frameTime);
	virtual bool StartTargeting();
	virtual void RefreshTargets();
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	virtual EArkPsiPowerError GetExecutionError() const;
	bool FilterTarget(IEntity const &_entity) const;
#endif
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class CAkEnvelopeCtx : public CAkModulatorCtx // Id=801F0CE Size=176
{
public:
	AkEnvelopeParams m_params;
	
	virtual bool SetParam(AkRTPC_ParameterID in_paramID, float in_fValue);
	virtual void CalcBufferNeeded();
	virtual void InitializeOutput();
	virtual AkModulatorParams *GetParamsPtr();
	
#if 0
	void FillParams(AkEnvelopeParams *arg0);
#endif
	
	static inline auto FSetParam = PreyFunction<bool(CAkEnvelopeCtx *const _this, AkRTPC_ParameterID in_paramID, float in_fValue)>(0x1A3D840);
	static inline auto FCalcBufferNeeded = PreyFunction<void(CAkEnvelopeCtx *const _this)>(0x1A3CB00);
	static inline auto FInitializeOutput = PreyFunction<void(CAkEnvelopeCtx *const _this)>(0x1A3CB90);
	static inline auto FGetParamsPtr = PreyFunction<AkModulatorParams *(CAkEnvelopeCtx *const _this)>(0x10BD540);
};

