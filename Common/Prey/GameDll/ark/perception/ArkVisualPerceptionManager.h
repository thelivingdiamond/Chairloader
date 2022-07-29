// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arklineofsightcheck.h>

struct AABB;
class ArkComplexVisualPerceivable;
class ArkSimpleVisualPerceivable;
class ArkVisualPerceiver;

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkVisualPerceptionManager.h
class ArkVisualPerceptionManager // Id=801621F Size=1800
{
public:
	enum class EBoundsEndpointType : unsigned
	{
		perceiver = 0,
		simplePerceivable = 1,
		complexPerceivable = 2,
	};

	enum class EBoundsEndpointExtent : unsigned
	{
		minimum = 0,
		maximum = 1,
	};

	enum class EBoundsEndpointDescription
	{
		perceiverMinimum = 0,
		perceiverMaximum = 1,
		simplePerceivableMinimum = 2,
		simplePerceivableMaximum = 3,
		complexPerceivableMinimum = 4,
		complexPerceivableMaximum = 5,
	};

	enum class EBoundsEndpointNeighborsDescription
	{
		perceiverMinimumPerceiverMinimum = 0,
		perceiverMinimumPerceiverMaximum = 1,
		perceiverMinimumSimplePerceivableMinimum = 2,
		perceiverMinimumSimplePerceivableMaximum = 3,
		perceiverMinimumComplexPerceivableMinimum = 4,
		perceiverMinimumComplexPerceivableMaximum = 5,
		perceiverMaximumPerceiverMinimum = 8,
		perceiverMaximumPerceiverMaximum = 9,
		perceiverMaximumSimplePerceivableMinimum = 10,
		perceiverMaximumSimplePerceivableMaximum = 11,
		perceiverMaximumComplexPerceivableMinimum = 12,
		perceiverMaximumComplexPerceivableMaximum = 13,
		simplePerceivableMinimumPerceiverMinimum = 16,
		simplePerceivableMinimumPerceiverMaximum = 17,
		simplePerceivableMinimumSimplePerceivableMinimum = 18,
		simplePerceivableMinimumSimplePerceivableMaximum = 19,
		simplePerceivableMinimumComplexPerceivableMinimum = 20,
		simplePerceivableMinimumComplexPerceivableMaximum = 21,
		simplePerceivableMaximumPerceiverMinimum = 24,
		simplePerceivableMaximumPerceiverMaximum = 25,
		simplePerceivableMaximumSimplePerceivableMinimum = 26,
		simplePerceivableMaximumSimplePerceivableMaximum = 27,
		simplePerceivableMaximumComplexPerceivableMinimum = 28,
		simplePerceivableMaximumComplexPerceivableMaximum = 29,
		complexPerceivableMinimumPerceiverMinimum = 32,
		complexPerceivableMinimumPerceiverMaximum = 33,
		complexPerceivableMinimumSimplePerceivableMinimum = 34,
		complexPerceivableMinimumSimplePerceivableMaximum = 35,
		complexPerceivableMinimumComplexPerceivableMinimum = 36,
		complexPerceivableMinimumComplexPerceivableMaximum = 37,
		complexPerceivableMaximumPerceiverMinimum = 40,
		complexPerceivableMaximumPerceiverMaximum = 41,
		complexPerceivableMaximumSimplePerceivableMinimum = 42,
		complexPerceivableMaximumSimplePerceivableMaximum = 43,
		complexPerceivableMaximumComplexPerceivableMinimum = 44,
		complexPerceivableMaximumComplexPerceivableMaximum = 45,
	};

	struct VisionConeDefinition // Id=8016225 Size=44
	{
		float m_forwardRadius;
		float m_meridianRadius;
		float m_horizontalSemiangle;
		float m_upSemiangle;
		float m_downSemiangle;
		float m_nearDistance;
		float m_nearMagnitude;
		float m_midDistance;
		float m_midMagnitude;
		float m_farDistance;
		float m_farMagnitude;
		
		void Load(XmlNodeRef const &_node) { FLoad(this,_node); }
		
		static inline auto FLoad = PreyFunction<void(ArkVisualPerceptionManager::VisionConeDefinition *const _this, XmlNodeRef const &_node)>(0x15335B0);
	};

	struct VisionConeProperties // Id=8016226 Size=100
	{
		float m_minRadius;
		float m_maxRadius;
		float m_forwardRadiusSquared;
		float m_meridianRadiusSquared;
		float m_minRadiusSquared;
		float m_maxRadiusSquared;
		float m_radiiProductSquared;
		float m_minimumContainedUpUnitVectorForwardComponent;
		float m_maximumExcludedUpUnitVectorForwardComponent;
		float m_unitConeUpSemiaxisRatio;
		float m_oneHalfCos2HorizontalSemianglePlusCos2UpSemiangle;
		float m_oneHalfCos2HorizontalSemiangleMinusCos2UpSemiangle;
		float m_minimumContainedDownUnitVectorForwardComponent;
		float m_maximumExcludedDownUnitVectorForwardComponent;
		float m_unitConeDownSemiaxisRatio;
		float m_oneHalfCos2HorizontalSemianglePlusCos2DownSemiangle;
		float m_oneHalfCos2HorizontalSemiangleMinusCos2DownSemiangle;
		float m_nearDistance;
		float m_nearMagnitude;
		float m_midDistance;
		float m_midMagnitude;
		float m_oneOverMidMinusNear;
		float m_farDistance;
		float m_farMagnitude;
		float m_oneOverFarMinusMid;
	};

	struct VisionConeAabb // Id=8016227 Size=12
	{
		float m_horizontalExtent;
		float m_depthExtent;
		float m_verticalExtent;
		
#if 0
		ArkVisualPerceptionManager::VisionConeAabb &operator+=(ArkVisualPerceptionManager::VisionConeAabb const &arg0);
		void Clear();
#endif
	};

	struct BoundsEndpoint // Id=8016228 Size=8
	{
		ArkVisualPerceptionManager::EBoundsEndpointType m_type : 2;
		ArkVisualPerceptionManager::EBoundsEndpointExtent m_extent : 1;
		unsigned m_index : 29;
		float m_value;
	};

	struct PerceiverPerceivableIndexPair // Id=8016229 Size=16
	{
		uint64_t m_perceiverIndex;
		uint64_t m_perceivableIndex;
		
#if 0
		bool operator==(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0) const;
		bool operator<(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0) const;
#endif
	};

	struct RemovedPerceivable // Id=801622A Size=16
	{
		uint64_t m_perceiverIndex;
		unsigned m_perceivableEntityId;
	};

	struct PerceiverPerceivableIndexPairHash // Id=801622B Size=1
	{
#if 0
		uint64_t operator()(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0) const;
#endif
	};

	static constexpr const uint64_t k_maxSimpleRayCastCount = 1;
	static constexpr const uint64_t k_maxComplexAnyRayCastCount = 2;
	static constexpr const uint64_t k_maxComplexAcuteRayCastCount = 1;
	static constexpr const uint64_t k_maxComplexAllRayCastCount = 2;
	static constexpr const uint64_t k_maxComplexRayCastCount = 5;
	
	struct SimplePerceivableWorldPoints // Id=801622C Size=12
	{
		using AnyPointArray = std::array<Vec3,1>;
		
		std::array<Vec3,1> m_any;
		
#if 0
		void Clear();
#endif
	};

	struct ComplexPerceivableWorldPoints // Id=8016232 Size=60
	{
		using AnyPointArray = std::array<Vec3,2>;
		using AcutePointArray = std::array<Vec3,1>;
		using AllPointArray = std::array<Vec3,2>;
		
		std::array<Vec3,2> m_any;
		std::array<Vec3,1> m_acute;
		std::array<Vec3,2> m_all;
		
		void Clear() { FClear(this); }
		
		static inline auto FClear = PreyFunction<void(ArkVisualPerceptionManager::ComplexPerceivableWorldPoints *const _this)>(0x1532CD0);
	};

	class SimpleLineOfSightCheckImpl // Id=8016238 Size=1
	{
	public:
#if 0
		static bool ShouldRayCast(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3);
		static Vec3 GetRayCastTarget(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2);
		static IPhysicalEntity **GetPerceivableIgnoredPhysicalEntities(ArkVisualPerceptionManager const &arg0, uint64_t arg1, IPhysicalEntity **arg2, IPhysicalEntity **arg3);
#endif
	};

	class ?$LineOfSightCheckImpl@VSimpleLineOfSightCheckImpl@ArkVisualPerceptionManager@@ : private ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl // Id=8016239 Size=16
	{
	public:
		using RayCasterType = RayCastQueue<41>;
		
		ArkVisualPerceptionManager::PerceiverPerceivableIndexPair m_perceiverPerceivableIndexPair;
		
#if 0
		void LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0);
		RayCastQueue<41> &GetRayCaster() const;
		bool GetRayCastRequest(uint64_t arg0, RayCastRequest &arg1) const;
		void OnSucceeded();
		void OnFailed();
#endif
	};

	using SimpleLineOfSightCheck = ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>;
	
	class ComplexLineOfSightCheckImplBase // Id=8016244 Size=1
	{
	public:
#if 0
		static IPhysicalEntity **GetPerceivableIgnoredPhysicalEntities(ArkVisualPerceptionManager const &arg0, uint64_t arg1, IPhysicalEntity **arg2, IPhysicalEntity **arg3);
#endif
	};

	class ComplexAnyLineOfSightCheckImpl : protected ArkVisualPerceptionManager::ComplexLineOfSightCheckImplBase // Id=8016245 Size=1
	{
	public:
#if 0
		static bool ShouldRayCast(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3);
		static Vec3 GetRayCastTarget(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2);
#endif
	};

	class ?$LineOfSightCheckImpl@VComplexAnyLineOfSightCheckImpl@ArkVisualPerceptionManager@@ : private ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl // Id=8016246 Size=16
	{
	public:
		using RayCasterType = RayCastQueue<41>;
		
		ArkVisualPerceptionManager::PerceiverPerceivableIndexPair m_perceiverPerceivableIndexPair;
		
#if 0
		void LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0);
		RayCastQueue<41> &GetRayCaster() const;
		bool GetRayCastRequest(uint64_t arg0, RayCastRequest &arg1) const;
		void OnSucceeded();
		void OnFailed();
#endif
	};

	using ComplexAnyLineOfSightCheck = ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>;
	
	class ComplexAcuteLineOfSightCheckImpl : protected ArkVisualPerceptionManager::ComplexLineOfSightCheckImplBase // Id=8016251 Size=1
	{
	public:
#if 0
		static bool ShouldRayCast(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3);
		static Vec3 GetRayCastTarget(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2);
#endif
	};

	class ?$LineOfSightCheckImpl@VComplexAcuteLineOfSightCheckImpl@ArkVisualPerceptionManager@@ : private ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl // Id=8016252 Size=16
	{
	public:
		using RayCasterType = RayCastQueue<41>;
		
		ArkVisualPerceptionManager::PerceiverPerceivableIndexPair m_perceiverPerceivableIndexPair;
		
#if 0
		void LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0);
		RayCastQueue<41> &GetRayCaster() const;
		bool GetRayCastRequest(uint64_t arg0, RayCastRequest &arg1) const;
		void OnSucceeded();
		void OnFailed();
#endif
	};

	using ComplexAcuteLineOfSightCheck = ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>;
	
	class ComplexAllLineOfSightCheckImpl : protected ArkVisualPerceptionManager::ComplexLineOfSightCheckImplBase // Id=801625D Size=1
	{
	public:
#if 0
		static bool ShouldRayCast(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3);
		static Vec3 GetRayCastTarget(ArkVisualPerceptionManager const &arg0, uint64_t arg1, uint64_t arg2);
#endif
	};

	class ?$LineOfSightCheckImpl@VComplexAllLineOfSightCheckImpl@ArkVisualPerceptionManager@@ : private ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl // Id=801625E Size=16
	{
	public:
		using RayCasterType = RayCastQueue<41>;
		
		ArkVisualPerceptionManager::PerceiverPerceivableIndexPair m_perceiverPerceivableIndexPair;
		
#if 0
		void LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const &arg0);
		RayCastQueue<41> &GetRayCaster() const;
		bool GetRayCastRequest(uint64_t arg0, RayCastRequest &arg1) const;
		void OnSucceeded();
		void OnFailed();
#endif
	};

	using ComplexAllLineOfSightCheck = ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>;
	
	struct ComplexLineOfSightChecks // Id=8016269 Size=1832
	{
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2> m_any;
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1> m_acute;
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2> m_all;
		
		void Begin() { FBegin(this); }
		void Reset() { FReset(this); }
		
#if 0
		void Cancel();
		EArkLineOfSightCheckStatus GetStatus() const;
#endif
		
		static inline auto FBegin = PreyFunction<void(ArkVisualPerceptionManager::ComplexLineOfSightChecks *const _this)>(0x15323F0);
		static inline auto FReset = PreyFunction<void(ArkVisualPerceptionManager::ComplexLineOfSightChecks *const _this)>(0x15368B0);
	};

	static constexpr const uint64_t k_maxVisionConeCount = 2;
	
	using BoundsEndpointVector = std::vector<ArkVisualPerceptionManager::BoundsEndpoint>;
	using ComplexLineOfSightChecksMap = std::unordered_map<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair,ArkVisualPerceptionManager::ComplexLineOfSightChecks,ArkVisualPerceptionManager::PerceiverPerceivableIndexPairHash,std::equal_to<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair>,std::allocator<std::pair<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const ,ArkVisualPerceptionManager::ComplexLineOfSightChecks> > >;
	using ComplexPerceivableWorldPointsVector = std::vector<ArkVisualPerceptionManager::ComplexPerceivableWorldPoints>;
	using ComplexVisualPerceivableVector = std::vector<ArkComplexVisualPerceivable const *>;
	using ComplexVisualPerceptionInfoVector = std::vector<ArkComplexVisualPerceptionInfo>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int,unsigned __int64>;
	using EntityIdVector = std::vector<unsigned int>;
	using FlagVector = std::vector<bool>;
	using FloatVector = std::vector<float>;
	using IndexVector = std::vector<unsigned __int64>;
	using Matrix34Vector = std::vector<Matrix34>;
	using PerceiverPerceivableIndexPairVector = std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair>;
	using RemovedPerceivableVector = std::vector<ArkVisualPerceptionManager::RemovedPerceivable>;
	using SimpleLineOfSightCheckMap = std::unordered_map<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair,ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>,ArkVisualPerceptionManager::PerceiverPerceivableIndexPairHash,std::equal_to<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair>,std::allocator<std::pair<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const ,ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1> > > >;
	using SimplePerceivableWorldPointsVector = std::vector<ArkVisualPerceptionManager::SimplePerceivableWorldPoints>;
	using SimpleVisualPerceivableVector = std::vector<ArkSimpleVisualPerceivable const *>;
	using SizeIntervalVector = std::vector<ArkInterval<unsigned __int64>>;
	using UniqueIdToIndexMap = std::unordered_map<unsigned __int64,unsigned __int64>;
	using Vec3Vector = std::vector<Vec3>;
	using VisionConeAabbVector = std::vector<ArkVisualPerceptionManager::VisionConeAabb>;
	using VisionConeDefinitionVector = std::vector<ArkVisualPerceptionManager::VisionConeDefinition>;
	using VisionConeIndexVector = std::vector<std::array<unsigned __int64,2>>;
	using VisionConePropertiesVector = std::vector<ArkVisualPerceptionManager::VisionConeProperties>;
	using VisualPerceiverVector = std::vector<ArkVisualPerceiver *>;
	
	std::unordered_map<unsigned int,unsigned __int64> m_perceiverIndexMap;
	std::unordered_map<unsigned int,unsigned __int64> m_simplePerceivableIndexMap;
	std::unordered_map<unsigned int,unsigned __int64> m_complexPerceivableIndexMap;
	std::unordered_map<unsigned __int64,unsigned __int64> m_visionConeIdMap;
	std::vector<ArkVisualPerceptionManager::VisionConeDefinition> m_visionConeDefinitions;
	std::vector<ArkVisualPerceptionManager::VisionConeProperties> m_visionConeProperties;
	std::vector<ArkVisualPerceptionManager::VisionConeAabb> m_visionConeLocalAabbs;
	std::vector<unsigned __int64> m_freePerceiverIndexes;
	std::vector<ArkVisualPerceiver *> m_perceivers;
	std::vector<std::array<unsigned __int64,2>> m_perceiverVisionConeIndexes;
	std::vector<ArkVisualPerceptionManager::VisionConeAabb> m_perceiverVisionLocalAabbs;
	std::vector<Matrix34> m_perceiverVisionConeLocalToWorldMatrixes;
	std::vector<Matrix34> m_perceiverVisionConeWorldToLocalMatrixes;
	std::vector<ArkInterval<unsigned __int64>> m_perceiverXAxisBoundsEndpointIndexes;
	std::vector<ArkInterval<unsigned __int64>> m_perceiverYAxisBoundsEndpointIndexes;
	std::vector<ArkInterval<unsigned __int64>> m_perceiverZAxisBoundsEndpointIndexes;
	std::vector<Vec3> m_perceiverEyePositions;
	std::vector<unsigned __int64> m_freeSimplePerceivableIndexes;
	std::vector<ArkSimpleVisualPerceivable const *> m_simplePerceivables;
	std::vector<unsigned int> m_simplePerceivableEntityIds;
	std::vector<ArkVisualPerceptionManager::SimplePerceivableWorldPoints> m_simplePerceivableWorldPoints;
	std::vector<ArkInterval<unsigned __int64>> m_simplePerceivableXAxisBoundsEndpointIndexes;
	std::vector<ArkInterval<unsigned __int64>> m_simplePerceivableYAxisBoundsEndpointIndexes;
	std::vector<ArkInterval<unsigned __int64>> m_simplePerceivableZAxisBoundsEndpointIndexes;
	std::vector<unsigned __int64> m_freeComplexPerceivableIndexes;
	std::vector<ArkComplexVisualPerceivable const *> m_complexPerceivables;
	std::vector<unsigned int> m_complexPerceivableEntityIds;
	std::vector<ArkVisualPerceptionManager::ComplexPerceivableWorldPoints> m_complexPerceivableWorldPoints;
	std::vector<float> m_complexPerceivableVisibilityScalars;
	std::vector<ArkInterval<unsigned __int64>> m_complexPerceivableXAxisBoundsEndpointIndexes;
	std::vector<ArkInterval<unsigned __int64>> m_complexPerceivableYAxisBoundsEndpointIndexes;
	std::vector<ArkInterval<unsigned __int64>> m_complexPerceivableZAxisBoundsEndpointIndexes;
	std::vector<ArkVisualPerceptionManager::BoundsEndpoint> m_xAxisBoundsEndpoints;
	std::vector<ArkVisualPerceptionManager::BoundsEndpoint> m_yAxisBoundsEndpoints;
	std::vector<ArkVisualPerceptionManager::BoundsEndpoint> m_zAxisBoundsEndpoints;
	std::vector<bool> m_simpleSweepAndPruneXAxisFlags;
	std::vector<bool> m_simpleSweepAndPruneYAxisFlags;
	std::vector<bool> m_simpleSweepAndPruneZAxisFlags;
	std::vector<bool> m_complexSweepAndPruneXAxisFlags;
	std::vector<bool> m_complexSweepAndPruneYAxisFlags;
	std::vector<bool> m_complexSweepAndPruneZAxisFlags;
	std::vector<bool> m_simplePerceivableWorldPointFlags;
	std::vector<bool> m_complexPerceivableWorldPointFlags;
	std::vector<float> m_complexVisionConeMagnitudes;
	std::vector<bool> m_complexAcuteVisionFlags;
	std::vector<bool> m_complexXRayVisionFlags;
	std::unordered_map<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair,ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>,ArkVisualPerceptionManager::PerceiverPerceivableIndexPairHash,std::equal_to<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair>,std::allocator<std::pair<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const ,ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1> > > > m_simpleLineOfSightChecks;
	std::unordered_map<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair,ArkVisualPerceptionManager::ComplexLineOfSightChecks,ArkVisualPerceptionManager::PerceiverPerceivableIndexPairHash,std::equal_to<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair>,std::allocator<std::pair<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair const ,ArkVisualPerceptionManager::ComplexLineOfSightChecks> > > m_complexLineOfSightChecks;
	std::vector<bool> m_simplePerceptionFlags;
	std::vector<bool> m_complexPerceptionFlags;
	std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> m_simpleStartPerceivingIndexPairs;
	std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> m_simpleContinuePerceivingIndexPairs;
	std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> m_simpleStopPerceivingIndexPairs;
	std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> m_complexStartPerceivingIndexPairs;
	std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> m_complexContinuePerceivingIndexPairs;
	std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> m_complexStopPerceivingIndexPairs;
	std::vector<ArkVisualPerceptionManager::RemovedPerceivable> m_removedSimplePerceivables;
	std::vector<ArkVisualPerceptionManager::RemovedPerceivable> m_removedComplexPerceivables;
	std::vector<unsigned int> m_simpleNotificationBuffer;
	std::vector<ArkComplexVisualPerceptionInfo> m_complexStartContinueNotificationBuffer;
	std::vector<unsigned int> m_complexStopNotificationBuffer;
	
	ArkVisualPerceptionManager();
	~ArkVisualPerceptionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void RegisterPerceiver(unsigned _perceiverEntityId, ArkVisualPerceiver &_perceiver) { FRegisterPerceiver(this,_perceiverEntityId,_perceiver); }
	bool IsPerceiverRegistered(unsigned _perceiverEntityId) const { return FIsPerceiverRegistered(this,_perceiverEntityId); }
	void UnregisterPerceiver(unsigned _perceiverEntityId) { FUnregisterPerceiver(this,_perceiverEntityId); }
	void RegisterSimplePerceivable(unsigned _simplePerceivableEntityId, ArkSimpleVisualPerceivable const &_perceivable) { FRegisterSimplePerceivable(this,_simplePerceivableEntityId,_perceivable); }
	bool IsSimplePerceivableRegistered(unsigned _simplePerceivableEntityId) const { return FIsSimplePerceivableRegistered(this,_simplePerceivableEntityId); }
	void UnregisterSimplePerceivable(unsigned _simplePerceivableEntityId) { FUnregisterSimplePerceivable(this,_simplePerceivableEntityId); }
	void RegisterComplexPerceivable(unsigned _complexPerceivableEntityId, ArkComplexVisualPerceivable const &_perceivable) { FRegisterComplexPerceivable(this,_complexPerceivableEntityId,_perceivable); }
	bool IsComplexPerceivableRegistered(unsigned _complexPerceivableEntityId) const { return FIsComplexPerceivableRegistered(this,_complexPerceivableEntityId); }
	void UnregisterComplexPerceivable(unsigned _complexPerceivableEntityId) { FUnregisterComplexPerceivable(this,_complexPerceivableEntityId); }
	bool PerceiverCanSeeSimplePerceivable(unsigned _perceiverEntityId, unsigned _simplePerceivableEntityId) const { return FPerceiverCanSeeSimplePerceivable(this,_perceiverEntityId,_simplePerceivableEntityId); }
	bool PerceiverCanSeeComplexPerceivable(unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId) const { return FPerceiverCanSeeComplexPerceivable(this,_perceiverEntityId,_complexPerceivableEntityId); }
	void SetAcuteVision(unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId, bool _bEnabled) { FSetAcuteVision(this,_perceiverEntityId,_complexPerceivableEntityId,_bEnabled); }
	void SetXRayVision(unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId, bool _bEnabled) { FSetXRayVision(this,_perceiverEntityId,_complexPerceivableEntityId,_bEnabled); }
	bool HasXRayVision(unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId) const { return FHasXRayVisionOv1(this,_perceiverEntityId,_complexPerceivableEntityId); }
	void Update(float _elapsedTime) { FUpdate(this,_elapsedTime); }
	bool GetVisionConeSemiangles(uint64_t _visionConeId, float &_outHorizontalSemiangle, float &_outUpSemiangle, float &_outDownSemiangle) const { return FGetVisionConeSemiangles(this,_visionConeId,_outHorizontalSemiangle,_outUpSemiangle,_outDownSemiangle); }
	void LoadVisionCones() { FLoadVisionCones(this); }
	void AssignVisionCones(uint64_t _perceiverIndex, ArkVisualPerceiver const &_perceiver) { FAssignVisionCones(this,_perceiverIndex,_perceiver); }
	void AddBoundsEndpoints(uint64_t _index, ArkVisualPerceptionManager::EBoundsEndpointType _type, std::vector<ArkInterval<unsigned __int64>> &_xAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_yAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_zAxisBoundsEndpointIndexes) { FAddBoundsEndpoints(this,_index,_type,_xAxisBoundsEndpointIndexes,_yAxisBoundsEndpointIndexes,_zAxisBoundsEndpointIndexes); }
	void RemoveBoundsEndpoints(uint64_t _index, std::vector<ArkInterval<unsigned __int64>> &_xAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_yAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_zAxisBoundsEndpointIndexes) { FRemoveBoundsEndpoints(this,_index,_xAxisBoundsEndpointIndexes,_yAxisBoundsEndpointIndexes,_zAxisBoundsEndpointIndexes); }
	void AcquireAllPerceivableInfo() { FAcquireAllPerceivableInfo(this); }
	void CollectCandidates() { FCollectCandidates(this); }
	void VerifyCandidates() { FVerifyCandidates(this); }
	void UpdatePerceptionFlags(uint64_t _perceivableCount, std::vector<bool> &_perceptionFlags, std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> &_startPerceivingIndexPairs, std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> &_stopPerceivingIndexPairs) { FUpdatePerceptionFlagsOv0(this,_perceivableCount,_perceptionFlags,_startPerceivingIndexPairs,_stopPerceivingIndexPairs); }
	void NotifyPerceivers() { FNotifyPerceivers(this); }
	void AcquirePerceiverVisionTransforms(uint64_t _perceiverIndex, ArkVisualPerceiver const &_perceiver) { FAcquirePerceiverVisionTransforms(this,_perceiverIndex,_perceiver); }
	void CalculatePerceiverBoundsEndpoints(uint64_t _perceiverIndex) { FCalculatePerceiverBoundsEndpoints(this,_perceiverIndex); }
	float CalcVisionConeMagnitude(uint64_t _perceiverIndex, Vec3 const &_worldPosition) const { return FCalcVisionConeMagnitudeOv1(this,_perceiverIndex,_worldPosition); }
	static float CalculatePlayerMagnitude(float _distance, ArkVisualPerceptionManager::VisionConeProperties const &_visionConeProperties) { return FCalculatePlayerMagnitude(_distance,_visionConeProperties); }
	
#if 0
	void ResetVisionCones(unsigned arg0, ArkVisualPerceiver const &arg1);
	void ClearAcuteVision(unsigned arg0);
	bool HasAcuteVision(unsigned arg0, unsigned arg1) const;
	bool HasAcuteVision(uint64_t arg0, uint64_t arg1) const;
	void ClearXRayVision(unsigned arg0);
	bool HasXRayVision(uint64_t arg0, uint64_t arg1) const;
	void SortFreeIndexes();
	static ArkVisualPerceptionManager::EBoundsEndpointDescription MakeBoundsEndpointDescription(ArkVisualPerceptionManager::BoundsEndpoint const &arg0);
	static ArkVisualPerceptionManager::EBoundsEndpointNeighborsDescription MakeBoundsEndpointNeighborsDescription(ArkVisualPerceptionManager::BoundsEndpoint const &arg0, ArkVisualPerceptionManager::BoundsEndpoint const &arg1);
	void AcquireAllPerceiverInfo();
	void CalculateAllPerceiverBoundsEndpoints();
	void SweepAndPrune();
	void TestCandidates();
	void UpdatePerceptionFlags();
	void SetPerceivableBoundsEndpoints(uint64_t arg0, AABB const &arg1, std::vector<ArkInterval<unsigned __int64>> const &arg2, std::vector<ArkInterval<unsigned __int64>> const &arg3, std::vector<ArkInterval<unsigned __int64>> const &arg4);
	float CalcVisionConeMagnitude(ArkVisualPerceptionManager::VisionConeProperties const &arg0, Vec3 const &arg1, float arg2) const;
#endif
	
	static inline auto FBitNotArkVisualPerceptionManager = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x152F120);
	static inline auto FInitialize = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x1533440);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x1534BF0);
	static inline auto FReset = PreyFunction<void(ArkVisualPerceptionManager *const _this, bool _bEnteringGameMode)>(0x1536810);
	static inline auto FRegisterPerceiver = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _perceiverEntityId, ArkVisualPerceiver &_perceiver)>(0x1536490);
	static inline auto FIsPerceiverRegistered = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, unsigned _perceiverEntityId)>(0x1533450);
	static inline auto FUnregisterPerceiver = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _perceiverEntityId)>(0x1536E70);
	static inline auto FRegisterSimplePerceivable = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _simplePerceivableEntityId, ArkSimpleVisualPerceivable const &_perceivable)>(0x1536590);
	static inline auto FIsSimplePerceivableRegistered = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, unsigned _simplePerceivableEntityId)>(0x1533500);
	static inline auto FUnregisterSimplePerceivable = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _simplePerceivableEntityId)>(0x1537330);
	static inline auto FRegisterComplexPerceivable = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _complexPerceivableEntityId, ArkComplexVisualPerceivable const &_perceivable)>(0x15362B0);
	static inline auto FIsComplexPerceivableRegistered = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, unsigned _complexPerceivableEntityId)>(0x13E7D10);
	static inline auto FUnregisterComplexPerceivable = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _complexPerceivableEntityId)>(0x1536D20);
	static inline auto FPerceiverCanSeeSimplePerceivable = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, unsigned _perceiverEntityId, unsigned _simplePerceivableEntityId)>(0x1535E90);
	static inline auto FPerceiverCanSeeComplexPerceivable = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId)>(0x1535CD0);
	static inline auto FSetAcuteVision = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId, bool _bEnabled)>(0x1536A60);
	static inline auto FSetXRayVision = PreyFunction<void(ArkVisualPerceptionManager *const _this, unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId, bool _bEnabled)>(0x1536C80);
	static inline auto FHasXRayVisionOv1 = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, unsigned _perceiverEntityId, unsigned _complexPerceivableEntityId)>(0x1533280);
	static inline auto FUpdate = PreyFunction<void(ArkVisualPerceptionManager *const _this, float _elapsedTime)>(0x1537460);
	static inline auto FGetVisionConeSemiangles = PreyFunction<bool(ArkVisualPerceptionManager const *const _this, uint64_t _visionConeId, float &_outHorizontalSemiangle, float &_outUpSemiangle, float &_outDownSemiangle)>(0x1533130);
	static inline auto FLoadVisionCones = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x1533920);
	static inline auto FAssignVisionCones = PreyFunction<void(ArkVisualPerceptionManager *const _this, uint64_t _perceiverIndex, ArkVisualPerceiver const &_perceiver)>(0x15320B0);
	static inline auto FAddBoundsEndpoints = PreyFunction<void(ArkVisualPerceptionManager *const _this, uint64_t _index, ArkVisualPerceptionManager::EBoundsEndpointType _type, std::vector<ArkInterval<unsigned __int64>> &_xAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_yAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_zAxisBoundsEndpointIndexes)>(0x1531EF0);
	static inline auto FRemoveBoundsEndpoints = PreyFunction<void(ArkVisualPerceptionManager *const _this, uint64_t _index, std::vector<ArkInterval<unsigned __int64>> &_xAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_yAxisBoundsEndpointIndexes, std::vector<ArkInterval<unsigned __int64>> &_zAxisBoundsEndpointIndexes)>(0x1536750);
	static inline auto FAcquireAllPerceivableInfo = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x15316D0);
	static inline auto FCollectCandidates = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x1532D40);
	static inline auto FVerifyCandidates = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x15378C0);
	static inline auto FUpdatePerceptionFlagsOv0 = PreyFunction<void(ArkVisualPerceptionManager *const _this, uint64_t _perceivableCount, std::vector<bool> &_perceptionFlags, std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> &_startPerceivingIndexPairs, std::vector<ArkVisualPerceptionManager::PerceiverPerceivableIndexPair> &_stopPerceivingIndexPairs)>(0x1537820);
	static inline auto FNotifyPerceivers = PreyFunction<void(ArkVisualPerceptionManager *const _this)>(0x1534420);
	static inline auto FAcquirePerceiverVisionTransforms = PreyFunction<void(ArkVisualPerceptionManager *const _this, uint64_t _perceiverIndex, ArkVisualPerceiver const &_perceiver)>(0x15319B0);
	static inline auto FCalculatePerceiverBoundsEndpoints = PreyFunction<void(ArkVisualPerceptionManager *const _this, uint64_t _perceiverIndex)>(0x1532980);
	static inline auto FCalcVisionConeMagnitudeOv1 = PreyFunction<float(ArkVisualPerceptionManager const *const _this, uint64_t _perceiverIndex, Vec3 const &_worldPosition)>(0x1532660);
	static inline auto FCalculatePlayerMagnitude = PreyFunction<float(float _distance, ArkVisualPerceptionManager::VisionConeProperties const &_visionConeProperties)>(0x1532B80);
};

