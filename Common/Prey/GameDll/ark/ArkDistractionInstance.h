// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpc;
class Distraction;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/ArkDistractionInstance.h
class ArkDistractionInstance // Id=801518F Size=40
{
public:
	IEntity *m_pEntityOwner;
	DistractionState m_state;
	int m_distractionDataIndex;
	float m_cooldownCompleteTime;
	unsigned m_targetNpcEntityId;
	
	struct ObstacleCheckState // Id=8015195 Size=16
	{
		bool m_bClear;
		CTimeValue m_lastCheckTime;
	};

	using ObstacleCheckCache = std::map<TNavigationID<1>,ArkDistractionInstance::ObstacleCheckState,std::less<TNavigationID<1> >,std::allocator<std::pair<TNavigationID<1> const ,ArkDistractionInstance::ObstacleCheckState> > >;
	
	std::map<TNavigationID<1>,ArkDistractionInstance::ObstacleCheckState,std::less<TNavigationID<1> >,std::allocator<std::pair<TNavigationID<1> const ,ArkDistractionInstance::ObstacleCheckState> > > m_navAgentObstacleChecks;
	
	ArkDistractionInstance();
	~ArkDistractionInstance() { FBitNotArkDistractionInstance(this); }
	void Initialize(unsigned _entityId, int _distractionDataIndex) { FInitialize(this,_entityId,_distractionDataIndex); }
	void Destroy() { FDestroy(this); }
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Update(uint64_t _distractionInstanceIndex, float _gameTime, bool &_outSearched) { FUpdate(this,_distractionInstanceIndex,_gameTime,_outSearched); }
	IEntity &GetEntity() const { return FGetEntity(this); }
	Distraction const &GetDistractionData() const { return FGetDistractionData(this); }
	uint64_t GetDistractionDataId() const { return FGetDistractionDataId(this); }
	void DistractNpc(ArkNpc &_npc, uint64_t _distractionInstanceIndex) { FDistractNpc(this,_npc,_distractionInstanceIndex); }
	void OnNpcAcquire(unsigned _npcEntityId) { FOnNpcAcquire(this,_npcEntityId); }
	void OnNpcIgnored(unsigned _npcEntityId) { FOnNpcIgnored(this,_npcEntityId); }
	void OnNpcDistractionComplete(unsigned _npcEntityId, bool _bSuccessful) { FOnNpcDistractionComplete(this,_npcEntityId,_bSuccessful); }
	Vec3 GetWorldPos() const { return FGetWorldPos(this); }
	Vec3 GetWorldStandPos(ArkNpc const &_npc) const { return FGetWorldStandPos(this,_npc); }
	Vec3 GetWorldLookAtPos() const { return FGetWorldLookAtPos(this); }
	Vec3 GetForwardDirection() const { return FGetForwardDirection(this); }
	bool GetValidNavStandPosition(ArkNpc const &_npc, Vec3 &_pos) const { return FGetValidNavStandPosition(this,_npc,_pos); }
	bool IsValidStandPosition(Vec3 const &_pos) const { return FIsValidStandPosition(this,_pos); }
	bool IsActive() const { return FIsActive(this); }
	bool IsValidDistractionForNpc(ArkNpc const &_npc, bool _bIgnoreDistanceCheck, bool _bIgnoreDirectionCheck, bool _bIgnoreAreasCheck, int &_numAreasFound, std::array<SAreaManagerResult,16> &_foundAreas) { return FIsValidDistractionForNpc(this,_npc,_bIgnoreDistanceCheck,_bIgnoreDirectionCheck,_bIgnoreAreasCheck,_numAreasFound,_foundAreas); }
	bool ShouldUseLookAt() const { return FShouldUseLookAt(this); }
	bool CanDistractRetreatingEntity(IEntity const &_entity) const { return FCanDistractRetreatingEntity(this,_entity); }
	void TryStartAreaCooldown() { FTryStartAreaCooldown(this); }
	void TryDistract(uint64_t _distractionInstanceIndex, bool &_outSearched) { FTryDistract(this,_distractionInstanceIndex,_outSearched); }
	bool IsClearOfObstacles(ArkNpc const &_npc, Vec3 const &_standPos) { return FIsClearOfObstacles(this,_npc,_standPos); }
	
#if 0
	void DebugDraw(float arg0);
	int GetDistractionDataIndex() const;
	bool GetClosestNavStandPosition(ArkNpc const &arg0, Vec3 &arg1) const;
	bool IsInRange(Vec3 const &arg0) const;
	bool IsInAngle(Vec3 const &arg0) const;
	float GetStandDistanceFromPos(Vec3 const &arg0) const;
	float GetStandAngleFromPos(Vec3 const &arg0) const;
	bool IsInUse() const;
	DistractionState GetState() const;
	const char *GetCurrentStateText() const;
	bool DoesOwnerHaveAnyOtherActiveDistractions() const;
	void OnCompleted(bool arg0);
	bool NpcHasTag(ArkNpc const &arg0) const;
	void SetFailedReason(DistractionFailedReason arg0);
#endif
	
	static inline auto FBitNotArkDistractionInstance = PreyFunction<void(ArkDistractionInstance *const _this)>(0x1154E40);
	static inline auto FInitialize = PreyFunction<void(ArkDistractionInstance *const _this, unsigned _entityId, int _distractionDataIndex)>(0x1155F30);
	static inline auto FDestroy = PreyFunction<void(ArkDistractionInstance *const _this)>(0x1154F00);
	static inline auto FEnable = PreyFunction<void(ArkDistractionInstance *const _this)>(0x1154FF0);
	static inline auto FDisable = PreyFunction<void(ArkDistractionInstance *const _this)>(0x1154F60);
	static inline auto FReset = PreyFunction<void(ArkDistractionInstance *const _this)>(0x1156CD0);
	static inline auto FSerialize = PreyFunction<void(ArkDistractionInstance *const _this, TSerialize _ser)>(0x1156D70);
	static inline auto FUpdate = PreyFunction<void(ArkDistractionInstance *const _this, uint64_t _distractionInstanceIndex, float _gameTime, bool &_outSearched)>(0x1157330);
	static inline auto FGetEntity = PreyFunction<IEntity &(ArkDistractionInstance const *const _this)>(0x12E5E70);
	static inline auto FGetDistractionData = PreyFunction<Distraction const &(ArkDistractionInstance const *const _this)>(0x1155110);
	static inline auto FGetDistractionDataId = PreyFunction<uint64_t(ArkDistractionInstance const *const _this)>(0x1155230);
	static inline auto FDistractNpc = PreyFunction<void(ArkDistractionInstance *const _this, ArkNpc &_npc, uint64_t _distractionInstanceIndex)>(0x1154F90);
	static inline auto FOnNpcAcquire = PreyFunction<void(ArkDistractionInstance *const _this, unsigned _npcEntityId)>(0x1156B20);
	static inline auto FOnNpcIgnored = PreyFunction<void(ArkDistractionInstance *const _this, unsigned _npcEntityId)>(0x1156C60);
	static inline auto FOnNpcDistractionComplete = PreyFunction<void(ArkDistractionInstance *const _this, unsigned _npcEntityId, bool _bSuccessful)>(0x1156B30);
	static inline auto FGetWorldPos = PreyFunction<Vec3(ArkDistractionInstance const *const _this)>(0x1155810);
	static inline auto FGetWorldStandPos = PreyFunction<Vec3(ArkDistractionInstance const *const _this, ArkNpc const &_npc)>(0x1155A80);
	static inline auto FGetWorldLookAtPos = PreyFunction<Vec3(ArkDistractionInstance const *const _this)>(0x11555A0);
	static inline auto FGetForwardDirection = PreyFunction<Vec3(ArkDistractionInstance const *const _this)>(0x1155290);
	static inline auto FGetValidNavStandPosition = PreyFunction<bool(ArkDistractionInstance const *const _this, ArkNpc const &_npc, Vec3 &_pos)>(0x1155430);
	static inline auto FIsValidStandPosition = PreyFunction<bool(ArkDistractionInstance const *const _this, Vec3 const &_pos)>(0x11568E0);
	static inline auto FIsActive = PreyFunction<bool(ArkDistractionInstance const *const _this)>(0x1156000);
	static inline auto FIsValidDistractionForNpc = PreyFunction<bool(ArkDistractionInstance *const _this, ArkNpc const &_npc, bool _bIgnoreDistanceCheck, bool _bIgnoreDirectionCheck, bool _bIgnoreAreasCheck, int &_numAreasFound, std::array<SAreaManagerResult,16> &_foundAreas)>(0x1156420);
	static inline auto FShouldUseLookAt = PreyFunction<bool(ArkDistractionInstance const *const _this)>(0x1156EC0);
	static inline auto FCanDistractRetreatingEntity = PreyFunction<bool(ArkDistractionInstance const *const _this, IEntity const &_entity)>(0x1154E60);
	static inline auto FTryStartAreaCooldown = PreyFunction<void(ArkDistractionInstance *const _this)>(0x1157290);
	static inline auto FTryDistract = PreyFunction<void(ArkDistractionInstance *const _this, uint64_t _distractionInstanceIndex, bool &_outSearched)>(0x1156EE0);
	static inline auto FIsClearOfObstacles = PreyFunction<bool(ArkDistractionInstance *const _this, ArkNpc const &_npc, Vec3 const &_standPos)>(0x1156010);
};

