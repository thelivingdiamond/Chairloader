// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/cryaisystem/navigation/mnm/CompactSpanGrid.h>
#include <CryEngine/cryaisystem/navigation/mnm/profiler.h>
#include <CryEngine/cryaisystem/navigation/mnm/voxelizer.h>
#include <CryEngine/crycommon/ark/arkaudioutil.h>
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryAction/ICryMannequinTagDefs.h>
#include <Prey/CryCore/FixedPoint.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryMath/SimpleHashLookUp.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryNetwork/Protocol/ExponentialKeyExchange.h>
#include <Prey/CrySystem/ILog.h>
#include <Prey/CrySystem/Log.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ai/hazardmodule/hazardraycast.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerRobotLightExtension.h>
#include <Prey/GameDll/ark/npc/anim/arknpcanimactions.h>
#include <Prey/GameDll/ark/npc/arkpatrolmanager.h>
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
#include <_unknown/Color_tpl_float_.h>
#include <_unknown/CryLockT_2_.h>
#include <_unknown/CryMT__queue_CLog__SLogMsg,std__allocator_CLog__SLogMsg_ _.h>
#include <_unknown/IArkPatrolManager.h>

class Agent;
struct AkModulatorParams;
class ArkNpc;
class ArkNpcBlackboardEntryKey_LostVisibilityTime;
class ArkNpcBlackboardEntryKey_VisibilityTime;
struct ArkPatrol;
struct ArkPatrolPoint;
class ArkPsiPowerCyberkinesisProperties;
class ArkPsiPowerHypnosisProperties;
class ArkPsiPowerTargetingComponent;
class ArkWorldUIOwner;
class CArkLight;
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
class IArkAbilityListener;
class IArkBreakableListener;
class IArkCharacterStatusListener;
class IArkCombatFocusListener;
class IArkEmailListener;
class IArkEtherDuplicateListener;
class IArkFabricationPlanListener;
class IArkGravShaftListener;
class IArkGroundColliderListener;
class IArkHUDListener;
class IArkInventoryListener;
class IArkMetaTagListener;
class IArkObjectiveStateListener;
class IArkPDAListener;
class IArkPauseMenuListener;
class IArkPlayerCarryListener;
class IArkPlayerCombatListener;
class IArkPlayerHealthListener;
class IArkPlayerInteractionListener;
class IArkPlayerPsiListener;
class IArkPlayerStatusListener;
class IArkPsiPowerCreatePhantomListener;
class IArkPsiPowerListener;
class IArkPsiPowerTargetingListener;
class IArkSignalManagerListener;
class IArkStatsListener;
class IArkUtilityListener;
struct IAttachment;
struct ICVar;
struct IConsole;
struct IConsoleCmdArgs;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct ILightSource;
struct ILogCallback;
struct IParticleEffect;
struct IParticleEmitter;
struct ISystem;
struct IUIElement;
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

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkSimpleTimer : public ArkTimeRemaining // Id=80134C2 Size=8
{
public:
	float m_duration;
	
	ArkSimpleTimer();
	ArkSimpleTimer(float _duration, bool _bResetTimer);
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetDuration(float _duration, bool _bResetTimer) { FSetDuration(this,_duration,_bResetTimer); }
	float GetDuration() const { return FGetDuration(this); }
	void ResetTimer() { FResetTimer(this); }
	bool IsTimerReset() const { return FIsTimerReset(this); }
	float GetTimeElapsed() const { return FGetTimeElapsed(this); }
	void SetTimeElapsed(float _elapsed) { FSetTimeElapsed(this,_elapsed); }
	float GetTimeElapsedRatio() const { return FGetTimeElapsedRatio(this); }
	
	static inline auto FUpdate = PreyFunction<bool(ArkSimpleTimer *const _this, float _frameTime)>(0x1258970);
	static inline auto FSerialize = PreyFunction<void(ArkSimpleTimer *const _this, TSerialize _ser)>(0x1258730);
	static inline auto FSetDuration = PreyFunction<void(ArkSimpleTimer *const _this, float _duration, bool _bResetTimer)>(0x1258850);
	static inline auto FGetDuration = PreyFunction<float(ArkSimpleTimer const *const _this)>(0x10BDAA0);
	static inline auto FResetTimer = PreyFunction<void(ArkSimpleTimer *const _this)>(0x1258690);
	static inline auto FIsTimerReset = PreyFunction<bool(ArkSimpleTimer const *const _this)>(0x1258610);
	static inline auto FGetTimeElapsed = PreyFunction<float(ArkSimpleTimer const *const _this)>(0x12585A0);
	static inline auto FSetTimeElapsed = PreyFunction<void(ArkSimpleTimer *const _this, float _elapsed)>(0x1258870);
	static inline auto FGetTimeElapsedRatio = PreyFunction<float(ArkSimpleTimer const *const _this)>(0x12585C0);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkTimeRemaining // Id=80134C3 Size=4
{
public:
	float m_timeRemaining;
	
	ArkTimeRemaining();
	ArkTimeRemaining(float _duration);
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetDuration(float _duration) { FSetDuration(this,_duration); }
	void SetElapsed() { FSetElapsed(this); }
	bool HasElapsed() const { return FHasElapsed(this); }
	bool IsValid() const { return FIsValid(this); }
	void Invalidate() { FInvalidate(this); }
	float GetTimeRemaining() const { return FGetTimeRemaining(this); }
	ArkTimeRemaining &operator*=(float _scalar) { return FoperatorMultEq(this,_scalar); }
	
	static inline auto FUpdate = PreyFunction<bool(ArkTimeRemaining *const _this, float _frameTime)>(0x12589B0);
	static inline auto FSerialize = PreyFunction<void(ArkTimeRemaining *const _this, TSerialize _ser)>(0x12587A0);
	static inline auto FSetDuration = PreyFunction<void(ArkTimeRemaining *const _this, float _duration)>(0x10BE310);
	static inline auto FSetElapsed = PreyFunction<void(ArkTimeRemaining *const _this)>(0x1B216D0);
	static inline auto FHasElapsed = PreyFunction<bool(ArkTimeRemaining const *const _this)>(0x12585F0);
	static inline auto FIsValid = PreyFunction<bool(ArkTimeRemaining const *const _this)>(0x1258620);
	static inline auto FInvalidate = PreyFunction<void(ArkTimeRemaining *const _this)>(0x1258600);
	static inline auto FGetTimeRemaining = PreyFunction<float(ArkTimeRemaining const *const _this)>(0x10BDAB0);
	static inline auto FoperatorMultEq = PreyFunction<ArkTimeRemaining &(ArkTimeRemaining *const _this, float _scalar)>(0x1258590);
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
struct ArkRobotLight // Id=80141D6 Size=96
{
	enum class LightMode
	{
		friendly = 0,
		hostile = 1,
		hacked = 2,
	};

	IEntity *m_pEntity;
	unsigned m_arkLightEntityId;
	ArkRobotLight::LightMode m_lightMode;
	ArkDialogPlayerRobotLightExtension m_dialogExtension;
	ArkSimpleTimer m_lightFlickerDurationTimer;
	ArkSimpleTimer m_lightFlickerToggleTimer;
	float m_flickerToggleMaxTime;
	float m_onBrightness;
	bool m_bActive;
	bool m_bGlowHidden;
	bool m_bEntityHidden;
	bool m_bIsOn;
	bool m_bScriptEnabled;
	bool m_bIsFlickering;
	bool m_bFlickeringForceOff;
	bool m_bRemoved;
	
	ArkRobotLight();
	void Initialize(IEntity &_entity) { FInitialize(this,_entity); }
	void OnStartGame() { FOnStartGame(this); }
	void Deinitialize() { FDeinitialize(this); }
	void RemoveLight() { FRemoveLight(this); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Activate(bool _bActivate) { FActivate(this,_bActivate); }
	void HideGlow(bool _bHideGlow) { FHideGlow(this,_bHideGlow); }
	void HideEntity(bool _bHideEntity) { FHideEntity(this,_bHideEntity); }
	void ScriptEnable(bool _bEnable) { FScriptEnable(this,_bEnable); }
	void StartFlicker(float _flickerDuration) { FStartFlicker(this,_flickerDuration); }
	void StopFlicker() { FStopFlicker(this); }
	void SetHacked() { FSetHacked(this); }
	void UpdateOnBrightness(const float _brightness) { FUpdateOnBrightness(this,_brightness); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void TryChangeLightArchetype() { FTryChangeLightArchetype(this); }
	void TurnOn() { FTurnOn(this); }
	void TurnOff() { FTurnOff(this); }
	void TryChangeLightState() { FTryChangeLightState(this); }
	bool SpawnLight() { return FSpawnLight(this); }
	IAttachment *GetLightAttachment() const { return FGetLightAttachment(this); }
	CArkLight *GetArkLight() const { return FGetArkLight(this); }
	IEntityArchetype *GetDesiredLightArchetype() const { return FGetDesiredLightArchetype(this); }
	
#if 0
	bool IsFlickering() const;
	bool IsActive() const;
	bool IsGlowHidden() const;
	bool IsEntityHidden() const;
	ArkDialogPlayerRobotLightExtension &GetDialogExtension();
	void SetBrightness(float arg0);
	bool ShouldTurnOn() const;
	bool ShouldTurnOff() const;
	void ForceRefresh();
	Color_tpl<float> const &GetLightColor(bool arg0) const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkRobotLight *const _this, IEntity &_entity)>(0x10BE320);
	static inline auto FOnStartGame = PreyFunction<void(ArkRobotLight *const _this)>(0x13462B0);
	static inline auto FDeinitialize = PreyFunction<void(ArkRobotLight *const _this)>(0x1345FA0);
	static inline auto FRemoveLight = PreyFunction<void(ArkRobotLight *const _this)>(0x1345FA0);
	static inline auto FReset = PreyFunction<void(ArkRobotLight *const _this)>(0x13463D0);
	static inline auto FUpdate = PreyFunction<void(ArkRobotLight *const _this, float _frameTime)>(0x1346C30);
	static inline auto FActivate = PreyFunction<void(ArkRobotLight *const _this, bool _bActivate)>(0x1345F90);
	static inline auto FHideGlow = PreyFunction<void(ArkRobotLight *const _this, bool _bHideGlow)>(0x13462A0);
	static inline auto FHideEntity = PreyFunction<void(ArkRobotLight *const _this, bool _bHideEntity)>(0x1346250);
	static inline auto FScriptEnable = PreyFunction<void(ArkRobotLight *const _this, bool _bEnable)>(0x1346610);
	static inline auto FStartFlicker = PreyFunction<void(ArkRobotLight *const _this, float _flickerDuration)>(0x1346A20);
	static inline auto FStopFlicker = PreyFunction<void(ArkRobotLight *const _this)>(0x1346A50);
	static inline auto FSetHacked = PreyFunction<void(ArkRobotLight *const _this)>(0x1346810);
	static inline auto FUpdateOnBrightness = PreyFunction<void(ArkRobotLight *const _this, const float _brightness)>(0x1346D30);
	static inline auto FSerialize = PreyFunction<void(ArkRobotLight *const _this, TSerialize _ser)>(0x1346620);
	static inline auto FPostSerialize = PreyFunction<void(ArkRobotLight *const _this)>(0x1346320);
	static inline auto FTryChangeLightArchetype = PreyFunction<void(ArkRobotLight *const _this)>(0x1346A60);
	static inline auto FTurnOn = PreyFunction<void(ArkRobotLight *const _this)>(0x1346BB0);
	static inline auto FTurnOff = PreyFunction<void(ArkRobotLight *const _this)>(0x1346B30);
	static inline auto FTryChangeLightState = PreyFunction<void(ArkRobotLight *const _this)>(0x1346AC0);
	static inline auto FSpawnLight = PreyFunction<bool(ArkRobotLight *const _this)>(0x1346830);
	static inline auto FGetLightAttachment = PreyFunction<IAttachment *(ArkRobotLight const *const _this)>(0x1346140);
	static inline auto FGetArkLight = PreyFunction<CArkLight *(ArkRobotLight const *const _this)>(0x1346000);
	static inline auto FGetDesiredLightArchetype = PreyFunction<IEntityArchetype *(ArkRobotLight const *const _this)>(0x13460D0);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkListenerManager // Id=80154C5 Size=1032
{
public:
	std::vector<IArkAbilityListener *> m_AbilityListeners;
	std::vector<IArkCharacterStatusListener *> m_CharacterStatusListeners;
	std::vector<IArkCombatFocusListener *> m_CombatFocusListeners;
	std::vector<IArkEmailListener *> m_EmailListeners;
	std::vector<IArkEtherDuplicateListener *> m_EtherDuplicateListeners;
	std::vector<IArkGravShaftListener *> m_GravShaftListeners;
	std::vector<IArkFabricationPlanListener *> m_FabricationPlanListeners;
	std::vector<IArkHUDListener *> m_HUDListeners;
	std::vector<IArkMetaTagListener *> m_MetaTagListeners;
	std::vector<IArkObjectiveStateListener *> m_ObjectiveStateListeners;
	std::vector<IArkPauseMenuListener *> m_PauseMenuListeners;
	std::vector<IArkPDAListener *> m_PDAListeners;
	std::vector<IArkPlayerCarryListener *> m_PlayerCarryListeners;
	std::vector<IArkPlayerCombatListener *> m_PlayerCombatListeners;
	std::vector<IArkPlayerHealthListener *> m_PlayerHealthListeners;
	std::vector<IArkPlayerPsiListener *> m_PlayerPsiListeners;
	std::vector<IArkPlayerStatusListener *> m_PlayerStatusListeners;
	std::vector<IArkPsiPowerListener *> m_PsiPowerListeners;
	std::vector<IArkPsiPowerCreatePhantomListener *> m_PsiPowerCreatePhantomListeners;
	std::vector<IArkUtilityListener *> m_UtilityListeners;
	std::vector<IArkBreakableListener *> m_BreakableListeners;
	std::unordered_map<unsigned int,std::vector<IArkGroundColliderListener *>> m_GroundColliderListeners;
	std::vector<IArkGroundColliderListener *> m_emptyGroundCollider;
	std::unordered_map<unsigned int,std::vector<IArkInventoryListener *>> m_InventoryListeners;
	std::vector<IArkInventoryListener *> m_emptyInventory;
	std::unordered_map<unsigned int,std::vector<IArkPlayerInteractionListener *>> m_PlayerInteractionListeners;
	std::vector<IArkPlayerInteractionListener *> m_emptyPlayerInteraction;
	std::unordered_map<unsigned int,std::vector<IArkPsiPowerTargetingListener *>> m_PsiPowerTargetingListeners;
	std::vector<IArkPsiPowerTargetingListener *> m_emptyPsiPowerTargeting;
	std::unordered_map<unsigned int,std::vector<IArkSignalManagerListener *>> m_SignalManagerListeners;
	std::vector<IArkSignalManagerListener *> m_emptySignalManager;
	std::unordered_map<unsigned int,std::unordered_map<CCryName,std::vector<IArkStatsListener *>>,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::unordered_map<CCryName,std::vector<IArkStatsListener *>>>>> m_StatsListeners;
	std::vector<IArkStatsListener *> m_emptyStats;
	
	void RegisterAbilityListener(IArkAbilityListener *_pListener) { FRegisterAbilityListener(this,_pListener); }
	void UnregisterAbilityListener(IArkAbilityListener *_pListener) { FUnregisterAbilityListener(this,_pListener); }
	std::vector<IArkAbilityListener *> const &GetAbilityListeners() const { return FGetAbilityListeners(this); }
	void RegisterCharacterStatusListener(IArkCharacterStatusListener *_pListener) { FRegisterCharacterStatusListener(this,_pListener); }
	void UnregisterCharacterStatusListener(IArkCharacterStatusListener *_pListener) { FUnregisterCharacterStatusListener(this,_pListener); }
	std::vector<IArkCharacterStatusListener *> const &GetCharacterStatusListeners() const { return FGetCharacterStatusListeners(this); }
	void RegisterCombatFocusListener(IArkCombatFocusListener *_pListener) { FRegisterCombatFocusListener(this,_pListener); }
	void UnregisterCombatFocusListener(IArkCombatFocusListener *_pListener) { FUnregisterCombatFocusListener(this,_pListener); }
	std::vector<IArkCombatFocusListener *> const &GetCombatFocusListeners() const { return FGetCombatFocusListeners(this); }
	void RegisterEmailListener(IArkEmailListener *_pListener) { FRegisterEmailListener(this,_pListener); }
	void UnregisterEmailListener(IArkEmailListener *_pListener) { FUnregisterEmailListener(this,_pListener); }
	std::vector<IArkEmailListener *> const &GetEmailListeners() const { return FGetEmailListeners(this); }
	void RegisterEtherDuplicateListener(IArkEtherDuplicateListener *_pListener) { FRegisterEtherDuplicateListener(this,_pListener); }
	void UnregisterEtherDuplicateListener(IArkEtherDuplicateListener *_pListener) { FUnregisterEtherDuplicateListener(this,_pListener); }
	std::vector<IArkEtherDuplicateListener *> const &GetEtherDuplicateListeners() const { return FGetEtherDuplicateListeners(this); }
	void RegisterGravShaftListener(IArkGravShaftListener *_pListener) { FRegisterGravShaftListener(this,_pListener); }
	void UnregisterGravShaftListener(IArkGravShaftListener *_pListener) { FUnregisterGravShaftListener(this,_pListener); }
	std::vector<IArkGravShaftListener *> const &GetGravShaftListeners() const { return FGetGravShaftListeners(this); }
	void RegisterFabricationPlanListener(IArkFabricationPlanListener *_pListener) { FRegisterFabricationPlanListener(this,_pListener); }
	void UnregisterFabricationPlanListener(IArkFabricationPlanListener *_pListener) { FUnregisterFabricationPlanListener(this,_pListener); }
	std::vector<IArkFabricationPlanListener *> const &GetFabricationPlanListeners() const { return FGetFabricationPlanListeners(this); }
	void RegisterHUDListener(IArkHUDListener *_pListener) { FRegisterHUDListener(this,_pListener); }
	void UnregisterHUDListener(IArkHUDListener *_pListener) { FUnregisterHUDListener(this,_pListener); }
	std::vector<IArkHUDListener *> const &GetHUDListeners() const { return FGetHUDListeners(this); }
	void RegisterMetaTagListener(IArkMetaTagListener *_pListener) { FRegisterMetaTagListener(this,_pListener); }
	void UnregisterMetaTagListener(IArkMetaTagListener *_pListener) { FUnregisterMetaTagListener(this,_pListener); }
	std::vector<IArkMetaTagListener *> const &GetMetaTagListeners() const { return FGetMetaTagListeners(this); }
	void RegisterObjectiveStateListener(IArkObjectiveStateListener *_pListener) { FRegisterObjectiveStateListener(this,_pListener); }
	void UnregisterObjectiveStateListener(IArkObjectiveStateListener *_pListener) { FUnregisterObjectiveStateListener(this,_pListener); }
	std::vector<IArkObjectiveStateListener *> const &GetObjectiveStateListeners() const { return FGetObjectiveStateListeners(this); }
	void RegisterPauseMenuListener(IArkPauseMenuListener *_pListener) { FRegisterPauseMenuListener(this,_pListener); }
	void UnregisterPauseMenuListener(IArkPauseMenuListener *_pListener) { FUnregisterPauseMenuListener(this,_pListener); }
	std::vector<IArkPauseMenuListener *> const &GetPauseMenuListeners() const { return FGetPauseMenuListeners(this); }
	void RegisterPDAListener(IArkPDAListener *_pListener) { FRegisterPDAListener(this,_pListener); }
	void UnregisterPDAListener(IArkPDAListener *_pListener) { FUnregisterPDAListener(this,_pListener); }
	std::vector<IArkPDAListener *> const &GetPDAListeners() const { return FGetPDAListeners(this); }
	void RegisterPlayerCarryListener(IArkPlayerCarryListener *_pListener) { FRegisterPlayerCarryListener(this,_pListener); }
	void UnregisterPlayerCarryListener(IArkPlayerCarryListener *_pListener) { FUnregisterPlayerCarryListener(this,_pListener); }
	std::vector<IArkPlayerCarryListener *> const &GetPlayerCarryListeners() const { return FGetPlayerCarryListeners(this); }
	void RegisterPlayerCombatListener(IArkPlayerCombatListener *_pListener) { FRegisterPlayerCombatListener(this,_pListener); }
	void UnregisterPlayerCombatListener(IArkPlayerCombatListener *_pListener) { FUnregisterPlayerCombatListener(this,_pListener); }
	std::vector<IArkPlayerCombatListener *> const &GetPlayerCombatListeners() const { return FGetPlayerCombatListeners(this); }
	void RegisterPlayerHealthListener(IArkPlayerHealthListener *_pListener) { FRegisterPlayerHealthListener(this,_pListener); }
	void UnregisterPlayerHealthListener(IArkPlayerHealthListener *_pListener) { FUnregisterPlayerHealthListener(this,_pListener); }
	std::vector<IArkPlayerHealthListener *> const &GetPlayerHealthListeners() const { return FGetPlayerHealthListeners(this); }
	void RegisterPlayerPsiListener(IArkPlayerPsiListener *_pListener) { FRegisterPlayerPsiListener(this,_pListener); }
	void UnregisterPlayerPsiListener(IArkPlayerPsiListener *_pListener) { FUnregisterPlayerPsiListener(this,_pListener); }
	std::vector<IArkPlayerPsiListener *> const &GetPlayerPsiListeners() const { return FGetPlayerPsiListeners(this); }
	void RegisterPlayerStatusListener(IArkPlayerStatusListener *_pListener) { FRegisterPlayerStatusListener(this,_pListener); }
	void UnregisterPlayerStatusListener(IArkPlayerStatusListener *_pListener) { FUnregisterPlayerStatusListener(this,_pListener); }
	std::vector<IArkPlayerStatusListener *> const &GetPlayerStatusListeners() const { return FGetPlayerStatusListeners(this); }
	void RegisterPsiPowerListener(IArkPsiPowerListener *_pListener) { FRegisterPsiPowerListener(this,_pListener); }
	void UnregisterPsiPowerListener(IArkPsiPowerListener *_pListener) { FUnregisterPsiPowerListener(this,_pListener); }
	std::vector<IArkPsiPowerListener *> const &GetPsiPowerListeners() const { return FGetPsiPowerListeners(this); }
	void RegisterPsiPowerCreatePhantomListener(IArkPsiPowerCreatePhantomListener *_pListener) { FRegisterPsiPowerCreatePhantomListener(this,_pListener); }
	void UnregisterPsiPowerCreatePhantomListener(IArkPsiPowerCreatePhantomListener *_pListener) { FUnregisterPsiPowerCreatePhantomListener(this,_pListener); }
	std::vector<IArkPsiPowerCreatePhantomListener *> const &GetPsiPowerCreatePhantomListeners() const { return FGetPsiPowerCreatePhantomListeners(this); }
	void RegisterUtilityListener(IArkUtilityListener *_pListener) { FRegisterUtilityListener(this,_pListener); }
	void UnregisterUtilityListener(IArkUtilityListener *_pListener) { FUnregisterUtilityListener(this,_pListener); }
	std::vector<IArkUtilityListener *> const &GetUtilityListeners() const { return FGetUtilityListeners(this); }
	void RegisterBreakableListener(IArkBreakableListener *_pListener) { FRegisterBreakableListener(this,_pListener); }
	void UnregisterBreakableListener(IArkBreakableListener *_pListener) { FUnregisterBreakableListener(this,_pListener); }
	std::vector<IArkBreakableListener *> const &GetBreakableListeners() const { return FGetBreakableListeners(this); }
	void RegisterGroundColliderListener(unsigned _entity, IArkGroundColliderListener *_pListener) { FRegisterGroundColliderListener(this,_entity,_pListener); }
	void UnregisterGroundColliderListener(unsigned _entity, IArkGroundColliderListener *_pListener) { FUnregisterGroundColliderListener(this,_entity,_pListener); }
	std::vector<IArkGroundColliderListener *> const &GetGroundColliderListeners(unsigned _entity) const { return FGetGroundColliderListenersOv1(this,_entity); }
	void RegisterInventoryListener(unsigned _entity, IArkInventoryListener *_pListener) { FRegisterInventoryListener(this,_entity,_pListener); }
	void UnregisterInventoryListener(unsigned _entity, IArkInventoryListener *_pListener) { FUnregisterInventoryListener(this,_entity,_pListener); }
	std::vector<IArkInventoryListener *> const &GetInventoryListeners(unsigned _entity) const { return FGetInventoryListenersOv1(this,_entity); }
	void RegisterPlayerInteractionListener(unsigned _entity, IArkPlayerInteractionListener *_pListener) { FRegisterPlayerInteractionListener(this,_entity,_pListener); }
	void UnregisterPlayerInteractionListener(unsigned _entity, IArkPlayerInteractionListener *_pListener) { FUnregisterPlayerInteractionListener(this,_entity,_pListener); }
	std::vector<IArkPlayerInteractionListener *> const &GetPlayerInteractionListeners(unsigned _entity) const { return FGetPlayerInteractionListenersOv1(this,_entity); }
	void RegisterPsiPowerTargetingListener(unsigned _entity, IArkPsiPowerTargetingListener *_pListener) { FRegisterPsiPowerTargetingListener(this,_entity,_pListener); }
	void UnregisterPsiPowerTargetingListener(unsigned _entity, IArkPsiPowerTargetingListener *_pListener) { FUnregisterPsiPowerTargetingListener(this,_entity,_pListener); }
	std::vector<IArkPsiPowerTargetingListener *> const &GetPsiPowerTargetingListeners(unsigned _entity) const { return FGetPsiPowerTargetingListenersOv1(this,_entity); }
	void RegisterSignalManagerListener(unsigned _entity, IArkSignalManagerListener *_pListener) { FRegisterSignalManagerListener(this,_entity,_pListener); }
	void UnregisterSignalManagerListener(unsigned _entity, IArkSignalManagerListener *_pListener) { FUnregisterSignalManagerListener(this,_entity,_pListener); }
	std::vector<IArkSignalManagerListener *> const &GetSignalManagerListeners(unsigned _entity) const { return FGetSignalManagerListenersOv1(this,_entity); }
	void RegisterStatsListener(const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener) { FRegisterStatsListener(this,_entity,_cryName,_pListener); }
	void UnregisterStatsListener(const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener) { FUnregisterStatsListener(this,_entity,_cryName,_pListener); }
	std::vector<IArkStatsListener *> const &GetStatsListeners(const unsigned _entity, CCryName const &_cryName) const { return FGetStatsListeners(this,_entity,_cryName); }
	
#if 0
	std::unordered_map<unsigned int,std::vector<IArkGroundColliderListener *>> const &GetGroundColliderListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkInventoryListener *>> const &GetInventoryListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkPlayerInteractionListener *>> const &GetPlayerInteractionListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkPsiPowerTargetingListener *>> const &GetPsiPowerTargetingListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkSignalManagerListener *>> const &GetSignalManagerListeners() const;
#endif
	
	static inline auto FRegisterAbilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkAbilityListener *_pListener)>(0x1193F40);
	static inline auto FUnregisterAbilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkAbilityListener *_pListener)>(0x1195080);
	static inline auto FGetAbilityListeners = PreyFunction<std::vector<IArkAbilityListener *> const &(ArkListenerManager const *const _this)>(0xC71190);
	static inline auto FRegisterCharacterStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCharacterStatusListener *_pListener)>(0x1193FD0);
	static inline auto FUnregisterCharacterStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCharacterStatusListener *_pListener)>(0x1195110);
	static inline auto FGetCharacterStatusListeners = PreyFunction<std::vector<IArkCharacterStatusListener *> const &(ArkListenerManager const *const _this)>(0x12BDA70);
	static inline auto FRegisterCombatFocusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCombatFocusListener *_pListener)>(0x1194020);
	static inline auto FUnregisterCombatFocusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCombatFocusListener *_pListener)>(0x1195150);
	static inline auto FGetCombatFocusListeners = PreyFunction<std::vector<IArkCombatFocusListener *> const &(ArkListenerManager const *const _this)>(0x12BDA00);
	static inline auto FRegisterEmailListener = PreyFunction<void(ArkListenerManager *const _this, IArkEmailListener *_pListener)>(0x1194070);
	static inline auto FUnregisterEmailListener = PreyFunction<void(ArkListenerManager *const _this, IArkEmailListener *_pListener)>(0x1195190);
	static inline auto FGetEmailListeners = PreyFunction<std::vector<IArkEmailListener *> const &(ArkListenerManager const *const _this)>(0x222910);
	static inline auto FRegisterEtherDuplicateListener = PreyFunction<void(ArkListenerManager *const _this, IArkEtherDuplicateListener *_pListener)>(0x11940C0);
	static inline auto FUnregisterEtherDuplicateListener = PreyFunction<void(ArkListenerManager *const _this, IArkEtherDuplicateListener *_pListener)>(0x11951D0);
	static inline auto FGetEtherDuplicateListeners = PreyFunction<std::vector<IArkEtherDuplicateListener *> const &(ArkListenerManager const *const _this)>(0x10BD9E0);
	static inline auto FRegisterGravShaftListener = PreyFunction<void(ArkListenerManager *const _this, IArkGravShaftListener *_pListener)>(0x1194160);
	static inline auto FUnregisterGravShaftListener = PreyFunction<void(ArkListenerManager *const _this, IArkGravShaftListener *_pListener)>(0x1195260);
	static inline auto FGetGravShaftListeners = PreyFunction<std::vector<IArkGravShaftListener *> const &(ArkListenerManager const *const _this)>(0x10BD7D0);
	static inline auto FRegisterFabricationPlanListener = PreyFunction<void(ArkListenerManager *const _this, IArkFabricationPlanListener *_pListener)>(0x1194110);
	static inline auto FUnregisterFabricationPlanListener = PreyFunction<void(ArkListenerManager *const _this, IArkFabricationPlanListener *_pListener)>(0x1195210);
	static inline auto FGetFabricationPlanListeners = PreyFunction<std::vector<IArkFabricationPlanListener *> const &(ArkListenerManager const *const _this)>(0x10BD460);
	static inline auto FRegisterHUDListener = PreyFunction<void(ArkListenerManager *const _this, IArkHUDListener *_pListener)>(0x1194350);
	static inline auto FUnregisterHUDListener = PreyFunction<void(ArkListenerManager *const _this, IArkHUDListener *_pListener)>(0x11953E0);
	static inline auto FGetHUDListeners = PreyFunction<std::vector<IArkHUDListener *> const &(ArkListenerManager const *const _this)>(0x10BD340);
	static inline auto FRegisterMetaTagListener = PreyFunction<void(ArkListenerManager *const _this, IArkMetaTagListener *_pListener)>(0x1194540);
	static inline auto FUnregisterMetaTagListener = PreyFunction<void(ArkListenerManager *const _this, IArkMetaTagListener *_pListener)>(0x1195560);
	static inline auto FGetMetaTagListeners = PreyFunction<std::vector<IArkMetaTagListener *> const &(ArkListenerManager const *const _this)>(0x10BD8F0);
	static inline auto FRegisterObjectiveStateListener = PreyFunction<void(ArkListenerManager *const _this, IArkObjectiveStateListener *_pListener)>(0x1194590);
	static inline auto FUnregisterObjectiveStateListener = PreyFunction<void(ArkListenerManager *const _this, IArkObjectiveStateListener *_pListener)>(0x11955B0);
	static inline auto FGetObjectiveStateListeners = PreyFunction<std::vector<IArkObjectiveStateListener *> const &(ArkListenerManager const *const _this)>(0x10BD4D0);
	static inline auto FRegisterPauseMenuListener = PreyFunction<void(ArkListenerManager *const _this, IArkPauseMenuListener *_pListener)>(0x1194630);
	static inline auto FUnregisterPauseMenuListener = PreyFunction<void(ArkListenerManager *const _this, IArkPauseMenuListener *_pListener)>(0x1195650);
	static inline auto FGetPauseMenuListeners = PreyFunction<std::vector<IArkPauseMenuListener *> const &(ArkListenerManager const *const _this)>(0x10BD930);
	static inline auto FRegisterPDAListener = PreyFunction<void(ArkListenerManager *const _this, IArkPDAListener *_pListener)>(0x11945E0);
	static inline auto FUnregisterPDAListener = PreyFunction<void(ArkListenerManager *const _this, IArkPDAListener *_pListener)>(0x1195600);
	static inline auto FGetPDAListeners = PreyFunction<std::vector<IArkPDAListener *> const &(ArkListenerManager const *const _this)>(0x10BD840);
	static inline auto FRegisterPlayerCarryListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCarryListener *_pListener)>(0x1194680);
	static inline auto FUnregisterPlayerCarryListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCarryListener *_pListener)>(0x11956A0);
	static inline auto FGetPlayerCarryListeners = PreyFunction<std::vector<IArkPlayerCarryListener *> const &(ArkListenerManager const *const _this)>(0x1193B60);
	static inline auto FRegisterPlayerCombatListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCombatListener *_pListener)>(0x11946D0);
	static inline auto FUnregisterPlayerCombatListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCombatListener *_pListener)>(0x11956F0);
	static inline auto FGetPlayerCombatListeners = PreyFunction<std::vector<IArkPlayerCombatListener *> const &(ArkListenerManager const *const _this)>(0x10BD4A0);
	static inline auto FRegisterPlayerHealthListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerHealthListener *_pListener)>(0x1194720);
	static inline auto FUnregisterPlayerHealthListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerHealthListener *_pListener)>(0x1195740);
	static inline auto FGetPlayerHealthListeners = PreyFunction<std::vector<IArkPlayerHealthListener *> const &(ArkListenerManager const *const _this)>(0x10BD370);
	static inline auto FRegisterPlayerPsiListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerPsiListener *_pListener)>(0x1194910);
	static inline auto FUnregisterPlayerPsiListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerPsiListener *_pListener)>(0x11958C0);
	static inline auto FGetPlayerPsiListeners = PreyFunction<std::vector<IArkPlayerPsiListener *> const &(ArkListenerManager const *const _this)>(0x10BD890);
	static inline auto FRegisterPlayerStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerStatusListener *_pListener)>(0x1194960);
	static inline auto FUnregisterPlayerStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerStatusListener *_pListener)>(0x1195910);
	static inline auto FGetPlayerStatusListeners = PreyFunction<std::vector<IArkPlayerStatusListener *> const &(ArkListenerManager const *const _this)>(0x10BD8D0);
	static inline auto FRegisterPsiPowerListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerListener *_pListener)>(0x1194A00);
	static inline auto FUnregisterPsiPowerListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerListener *_pListener)>(0x11959B0);
	static inline auto FGetPsiPowerListeners = PreyFunction<std::vector<IArkPsiPowerListener *> const &(ArkListenerManager const *const _this)>(0x1193C40);
	static inline auto FRegisterPsiPowerCreatePhantomListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerCreatePhantomListener *_pListener)>(0x11949B0);
	static inline auto FUnregisterPsiPowerCreatePhantomListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerCreatePhantomListener *_pListener)>(0x1195960);
	static inline auto FGetPsiPowerCreatePhantomListeners = PreyFunction<std::vector<IArkPsiPowerCreatePhantomListener *> const &(ArkListenerManager const *const _this)>(0x10BD4C0);
	static inline auto FRegisterUtilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkUtilityListener *_pListener)>(0x1195030);
	static inline auto FUnregisterUtilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkUtilityListener *_pListener)>(0x1195E10);
	static inline auto FGetUtilityListeners = PreyFunction<std::vector<IArkUtilityListener *> const &(ArkListenerManager const *const _this)>(0x1193F30);
	static inline auto FRegisterBreakableListener = PreyFunction<void(ArkListenerManager *const _this, IArkBreakableListener *_pListener)>(0x1193F80);
	static inline auto FUnregisterBreakableListener = PreyFunction<void(ArkListenerManager *const _this, IArkBreakableListener *_pListener)>(0x11950C0);
	static inline auto FGetBreakableListeners = PreyFunction<std::vector<IArkBreakableListener *> const &(ArkListenerManager const *const _this)>(0x11939B0);
	static inline auto FRegisterGroundColliderListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkGroundColliderListener *_pListener)>(0x11941B0);
	static inline auto FUnregisterGroundColliderListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkGroundColliderListener *_pListener)>(0x11952B0);
	static inline auto FGetGroundColliderListenersOv1 = PreyFunction<std::vector<IArkGroundColliderListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x11939C0);
	static inline auto FRegisterInventoryListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkInventoryListener *_pListener)>(0x11943A0);
	static inline auto FUnregisterInventoryListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkInventoryListener *_pListener)>(0x1195430);
	static inline auto FGetInventoryListenersOv1 = PreyFunction<std::vector<IArkInventoryListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193A90);
	static inline auto FRegisterPlayerInteractionListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPlayerInteractionListener *_pListener)>(0x1194770);
	static inline auto FUnregisterPlayerInteractionListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPlayerInteractionListener *_pListener)>(0x1195790);
	static inline auto FGetPlayerInteractionListenersOv1 = PreyFunction<std::vector<IArkPlayerInteractionListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193B70);
	static inline auto FRegisterPsiPowerTargetingListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPsiPowerTargetingListener *_pListener)>(0x1194A50);
	static inline auto FUnregisterPsiPowerTargetingListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPsiPowerTargetingListener *_pListener)>(0x1195A00);
	static inline auto FGetPsiPowerTargetingListenersOv1 = PreyFunction<std::vector<IArkPsiPowerTargetingListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193C50);
	static inline auto FRegisterSignalManagerListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkSignalManagerListener *_pListener)>(0x1194BF0);
	static inline auto FUnregisterSignalManagerListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkSignalManagerListener *_pListener)>(0x1195B30);
	static inline auto FGetSignalManagerListenersOv1 = PreyFunction<std::vector<IArkSignalManagerListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193D20);
	static inline auto FRegisterStatsListener = PreyFunction<void(ArkListenerManager *const _this, const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener)>(0x1194D90);
	static inline auto FUnregisterStatsListener = PreyFunction<void(ArkListenerManager *const _this, const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener)>(0x1195C60);
	static inline auto FGetStatsListeners = PreyFunction<std::vector<IArkStatsListener *> const &(ArkListenerManager const *const _this, const unsigned _entity, CCryName const &_cryName)>(0x1193DF0);
};

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

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkPatrolManager : public IArkPatrolManager // Id=8015D4B Size=184
{
public:
	std::vector<ArkPatrol> m_patrols;
	std::vector<ArkPatrolPoint> m_points;
	std::unordered_map<string,unsigned int,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,unsigned int>>> m_nameToIndexMap;
	std::unordered_map<unsigned __int64,unsigned int> m_idToIndexMap;
	
	ArkPatrolManager();
	~ArkPatrolManager() { FBitNotArkPatrolManager(this); }
	virtual unsigned GetPatrolIndex(const char *const _pName) const;
	virtual unsigned GetPatrolIndex(const uint64_t &_id) const;
	virtual string const &GetPatrolName(unsigned _patrolIndex) const;
	virtual uint64_t GetPatrolId(unsigned _patrolIndex) const;
	ArkPatrolState CreateInitialPatrolStateFromClosestPatrolTo(Vec3 const &_point) { return FCreateInitialPatrolStateFromClosestPatrolTo(this,_point); }
	ArkPatrolState CreateInitialPatrolStateFromClosestForwardPointOnPatrolTo(unsigned _patrolIndex, Vec3 const &_point) { return FCreateInitialPatrolStateFromClosestForwardPointOnPatrolTo(this,_patrolIndex,_point); }
	ArkPatrolState CreateInitialPatrolStateFromPatrolAndPoint(unsigned _patrolIndex, int _pointIndex) { return FCreateInitialPatrolStateFromPatrolAndPoint(this,_patrolIndex,_pointIndex); }
	bool UpdatePatrolState(ArkPatrolState &_patrolState) const { return FUpdatePatrolState(this,_patrolState); }
	bool ReachedDestination(ArkPatrolState const &_patrolState, Vec3 const &_pos, float _epsilon) const { return FReachedDestination(this,_patrolState,_pos,_epsilon); }
	Vec3 GetCurrentPointDestination(ArkPatrolState const &_patrolState, unsigned _forEntityId) const { return FGetCurrentPointDestination(this,_patrolState,_forEntityId); }
	float GetCurrentPointGuardTime(ArkPatrolState const &_patrolState) const { return FGetCurrentPointGuardTime(this,_patrolState); }
	float GetCurrentPointIdleChance(ArkPatrolState const &_patrolState) const { return FGetCurrentPointIdleChance(this,_patrolState); }
	int GetCurrentPointLocalIndex(ArkPatrolState const &_patrolState) const { return FGetCurrentPointLocalIndex(this,_patrolState); }
	bool GetZeroGDesiredPitchRoll(ArkPatrolState const &_patrolState, float &_pitch, float &_roll) const { return FGetZeroGDesiredPitchRoll(this,_patrolState,_pitch,_roll); }
	void RelinquishPatrol(ArkPatrolState &_patrolState) const { FRelinquishPatrol(this,_patrolState); }
	void SetPatrolEnabled(unsigned _patrolIndex, bool _bEnabled) { FSetPatrolEnabled(this,_patrolIndex,_bEnabled); }
	void Update(float _framTime) { FUpdate(this,_framTime); }
	virtual void LoadFromFile(const char *_pLevelName);
	virtual std::unordered_map<string,unsigned int,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,unsigned int>>> const &GetNameMap() const;
	virtual std::unordered_map<unsigned __int64,unsigned int> const &GetIdMap() const;
	int GetNextPointIndex(ArkPatrolState const &_patrolState) const { return FGetNextPointIndex(this,_patrolState); }
	int GetClosestPointIndexOnPatrolTo(ArkPatrol const &_patrol, Vec3 const &_toPoint) const { return FGetClosestPointIndexOnPatrolTo(this,_patrol,_toPoint); }
	
#if 0
	ArkPatrolState CreateInitialPatrolStateFromClosestPointOnPatrolTo(unsigned arg0, Vec3 const &arg1);
	bool GetNextPointGuardTime(ArkPatrolState const &arg0, float &arg1) const;
	bool IsPatrolEnabled(unsigned arg0) const;
	bool IsValidPatrolIndex(unsigned arg0) const;
	void Clear();
	void DebugDraw();
	bool IsValidPointIndex(int arg0) const;
	ArkPatrol *GetPatrol(unsigned arg0);
	ArkPatrol const *GetPatrol(unsigned arg0) const;
	ArkPatrolPoint const *GetPatrolPoint(int arg0) const;
#endif
	
	static inline auto FBitNotArkPatrolManager = PreyFunction<void(ArkPatrolManager *const _this)>(0x151E2C0);
	static inline auto FGetPatrolIndexOv1 = PreyFunction<unsigned(ArkPatrolManager const *const _this, const char *const _pName)>(0x151F090);
	static inline auto FGetPatrolIndexOv0 = PreyFunction<unsigned(ArkPatrolManager const *const _this, const uint64_t &_id)>(0x151EFA0);
	static inline auto FGetPatrolName = PreyFunction<string const &(ArkPatrolManager const *const _this, unsigned _patrolIndex)>(0x151F230);
	static inline auto FGetPatrolId = PreyFunction<uint64_t(ArkPatrolManager const *const _this, unsigned _patrolIndex)>(0x151EF40);
	static inline auto FCreateInitialPatrolStateFromClosestPatrolTo = PreyFunction<ArkPatrolState(ArkPatrolManager *const _this, Vec3 const &_point)>(0x151E770);
	static inline auto FCreateInitialPatrolStateFromClosestForwardPointOnPatrolTo = PreyFunction<ArkPatrolState(ArkPatrolManager *const _this, unsigned _patrolIndex, Vec3 const &_point)>(0x151E370);
	static inline auto FCreateInitialPatrolStateFromPatrolAndPoint = PreyFunction<ArkPatrolState(ArkPatrolManager *const _this, unsigned _patrolIndex, int _pointIndex)>(0x151E8A0);
	static inline auto FUpdatePatrolState = PreyFunction<bool(ArkPatrolManager const *const _this, ArkPatrolState &_patrolState)>(0x1520140);
	static inline auto FReachedDestination = PreyFunction<bool(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState, Vec3 const &_pos, float _epsilon)>(0x151FEE0);
	static inline auto FGetCurrentPointDestination = PreyFunction<Vec3(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState, unsigned _forEntityId)>(0x151EB60);
	static inline auto FGetCurrentPointGuardTime = PreyFunction<float(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState)>(0x151ED00);
	static inline auto FGetCurrentPointIdleChance = PreyFunction<float(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState)>(0x151ED60);
	static inline auto FGetCurrentPointLocalIndex = PreyFunction<int(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState)>(0x151EDC0);
	static inline auto FGetZeroGDesiredPitchRoll = PreyFunction<bool(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState, float &_pitch, float &_roll)>(0x151F370);
	static inline auto FRelinquishPatrol = PreyFunction<void(ArkPatrolManager const *const _this, ArkPatrolState &_patrolState)>(0x151FFB0);
	static inline auto FSetPatrolEnabled = PreyFunction<void(ArkPatrolManager *const _this, unsigned _patrolIndex, bool _bEnabled)>(0x15200F0);
	static inline auto FUpdate = PreyFunction<void(ArkPatrolManager *const _this, float _framTime)>(0xA13080);
	static inline auto FLoadFromFile = PreyFunction<void(ArkPatrolManager *const _this, const char *_pLevelName)>(0x151F450);
	static inline auto FGetNameMap = PreyFunction<std::unordered_map<string,unsigned int,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,unsigned int>>> const &(ArkPatrolManager const *const _this)>(0x10BDA20);
	static inline auto FGetIdMap = PreyFunction<std::unordered_map<unsigned __int64,unsigned int> const &(ArkPatrolManager const *const _this)>(0x10BD7D0);
	static inline auto FGetNextPointIndex = PreyFunction<int(ArkPatrolManager const *const _this, ArkPatrolState const &_patrolState)>(0x151EE60);
	static inline auto FGetClosestPointIndexOnPatrolTo = PreyFunction<int(ArkPatrolManager const *const _this, ArkPatrol const &_patrol, Vec3 const &_toPoint)>(0x151E930);
};

// Header: Exact
// Prey/ArkCommon/reflect/arkreflectionaccessors.h
class ArkWorldUIManager : public IUIElementEventListener // Id=80163BF Size=256
{
public:
	using TPoolEntry = std::pair<IUIElement *,ArkWorldUIOwner *>;
	using TInstancePool = std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>>;
	
	std::unordered_map<unsigned int,ArkWorldUIOwner *> m_worldUIEntities;
	std::unordered_map<string,std::vector<ArkWorldUIOwner *>,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,std::vector<ArkWorldUIOwner *>>>> m_worldUIElements;
	std::unordered_map<string,std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>>,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>>>>> m_instancePools;
	std::vector<ArkMaterialParamOverride> m_interferenceOverrides;
	std::vector<ArkMaterialParamOverride> m_transcribeDisruption;
	unsigned m_highPriorityWorldUI;
	static int ui_debugKioskInteraction;
	static std::array<int,7> s_uiAutoExamine;
	
	ArkWorldUIManager();
	virtual ~ArkWorldUIManager();
	void Init() { FInit(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	bool IsWorldUI(unsigned _entityId) const { return FIsWorldUI(this,_entityId); }
	ArkWorldUIOwner *GetWorldUIOwner(unsigned _entityId) { return FGetWorldUIOwner(this,_entityId); }
	unsigned GetWorldUIFromOwner(unsigned _ownerId) const { return FGetWorldUIFromOwner(this,_ownerId); }
	void RegisterWorldUIOwner(unsigned _entityId, ArkWorldUIOwner *_pOwner) { FRegisterWorldUIOwner(this,_entityId,_pOwner); }
	void UnregisterWorldUIOwner(unsigned _entityId, ArkWorldUIOwner *_pOwner) { FUnregisterWorldUIOwner(this,_entityId,_pOwner); }
	void SetHighPriorityWorldUI(unsigned _entityId) { FSetHighPriorityWorldUI(this,_entityId); }
	void RegisterWorldUIElement(const char *_uiElement, ArkWorldUIOwner &_owner) { FRegisterWorldUIElement(this,_uiElement,_owner); }
	void UnregisterWorldUIElement(const char *_uiElement, ArkWorldUIOwner &_owner) { FUnregisterWorldUIElement(this,_uiElement,_owner); }
	bool HasUIElementPool(const char *_uiElement) { return FHasUIElementPool(this,_uiElement); }
	virtual void OnInstanceDestroyed(IUIElement *pSender, IUIElement *pDeletedInstance);
	std::vector<ArkMaterialParamOverride> const &GetInterferenceMaterialOverrides() const { return FGetInterferenceMaterialOverrides(this); }
	std::vector<ArkMaterialParamOverride> const &GetTranscribeMaterialOverrides() const { return FGetTranscribeMaterialOverrides(this); }
	static bool ShouldAutoExamineType(EArkInteractiveScreenType _type) { return FShouldAutoExamineType(_type); }
	void InitializePools() { FInitializePools(this); }
	void LoadInterferenceOverrides() { FLoadInterferenceOverrides(this); }
	
#if 0
	void GrantInstanceFromPool(std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>> &arg0, ArkWorldUIOwner &arg1);
	void ReturnInstanceToPool(std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>> &arg0, ArkWorldUIOwner &arg1);
#endif
	
	static inline auto FBitNotArkWorldUIManager = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AE300);
	static inline auto FInit = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AE940);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AEFA0);
	static inline auto FReset = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AF2E0);
	static inline auto FUpdate = PreyFunction<void(ArkWorldUIManager *const _this, const float _frameTime)>(0x13AF5D0);
	static inline auto FIsWorldUI = PreyFunction<bool(ArkWorldUIManager const *const _this, unsigned _entityId)>(0x145A1E0);
	static inline auto FGetWorldUIOwner = PreyFunction<ArkWorldUIOwner *(ArkWorldUIManager *const _this, unsigned _entityId)>(0x13AE7B0);
	static inline auto FGetWorldUIFromOwner = PreyFunction<unsigned(ArkWorldUIManager const *const _this, unsigned _ownerId)>(0x13AE750);
	static inline auto FRegisterWorldUIOwner = PreyFunction<void(ArkWorldUIManager *const _this, unsigned _entityId, ArkWorldUIOwner *_pOwner)>(0x13AF160);
	static inline auto FUnregisterWorldUIOwner = PreyFunction<void(ArkWorldUIManager *const _this, unsigned _entityId, ArkWorldUIOwner *_pOwner)>(0x13AF510);
	static inline auto FSetHighPriorityWorldUI = PreyFunction<void(ArkWorldUIManager *const _this, unsigned _entityId)>(0x13AF300);
	static inline auto FRegisterWorldUIElement = PreyFunction<void(ArkWorldUIManager *const _this, const char *_uiElement, ArkWorldUIOwner &_owner)>(0x13AEFB0);
	static inline auto FUnregisterWorldUIElement = PreyFunction<void(ArkWorldUIManager *const _this, const char *_uiElement, ArkWorldUIOwner &_owner)>(0x13AF330);
	static inline auto FHasUIElementPool = PreyFunction<bool(ArkWorldUIManager *const _this, const char *_uiElement)>(0x13AE870);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(ArkWorldUIManager *const _this, IUIElement *pSender, IUIElement *pDeletedInstance)>(0x13AEE60);
	static inline auto FGetInterferenceMaterialOverrides = PreyFunction<std::vector<ArkMaterialParamOverride> const &(ArkWorldUIManager const *const _this)>(0x10BD480);
	static inline auto FGetTranscribeMaterialOverrides = PreyFunction<std::vector<ArkMaterialParamOverride> const &(ArkWorldUIManager const *const _this)>(0x13AE740);
	static inline auto FShouldAutoExamineType = PreyFunction<bool(EArkInteractiveScreenType _type)>(0x13AF310);
	static inline auto FInitializePools = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AE950);
	static inline auto FLoadInterferenceOverrides = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AECC0);
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

