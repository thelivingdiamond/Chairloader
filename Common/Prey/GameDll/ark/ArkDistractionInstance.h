// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	~ArkDistractionInstance();
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <_unknown/TNavigationID.h>

class ArkNpc;
class Distraction;
enum class DistractionFailedReason;
struct IEntity;

// ArkDistractionInstance
// Header:  Prey/GameDll/ark/ArkDistractionInstance.h
class ArkDistractionInstance
{ // Size=40 (0x28)
public:
	// ArkDistractionInstance::ObstacleCheckState
	// Header:  Prey/GameDll/ark/ArkDistractionInstance.h
	struct ObstacleCheckState
	{ // Size=16 (0x10)
		bool m_bClear;
		CTimeValue m_lastCheckTime;

	#if 0
		ObstacleCheckState();
	#endif
	};

	using ObstacleCheckCache = std::map<TNavigationID<1>, ArkDistractionInstance::ObstacleCheckState>;

	IEntity* m_pEntityOwner;
	DistractionState m_state;
	int m_distractionDataIndex;
	float m_cooldownCompleteTime;
	unsigned m_targetNpcEntityId;
	std::map<TNavigationID<1>, ArkDistractionInstance::ObstacleCheckState> m_navAgentObstacleChecks;

	ArkDistractionInstance();
	~ArkDistractionInstance();
	void Initialize(unsigned _entityId, int _distractionDataIndex) { FInitialize(this, _entityId, _distractionDataIndex); }
	void Destroy() { FDestroy(this); }
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Update(uint64_t _distractionInstanceIndex, float _gameTime, bool& _outSearched) { FUpdate(this, _distractionInstanceIndex, _gameTime, _outSearched); }
	IEntity& GetEntity() const { return FGetEntity(this); }
	const Distraction& GetDistractionData() const { return FGetDistractionData(this); }
	uint64_t GetDistractionDataId() const { return FGetDistractionDataId(this); }
	void DistractNpc(ArkNpc& _npc, uint64_t _distractionInstanceIndex) { FDistractNpc(this, _npc, _distractionInstanceIndex); }
	void OnNpcAcquire(unsigned _npcEntityId) { FOnNpcAcquire(this, _npcEntityId); }
	void OnNpcIgnored(unsigned _npcEntityId) { FOnNpcIgnored(this, _npcEntityId); }
	void OnNpcDistractionComplete(unsigned _npcEntityId, bool _bSuccessful) { FOnNpcDistractionComplete(this, _npcEntityId, _bSuccessful); }
	Vec3 GetWorldPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetWorldPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetWorldStandPos(const ArkNpc& _npc) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetWorldStandPos(this, reinterpret_cast<Vec3*>(_return_buf_), _npc); }
	Vec3 GetWorldLookAtPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetWorldLookAtPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetForwardDirection() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetForwardDirection(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	bool GetValidNavStandPosition(const ArkNpc& _npc, Vec3& _pos) const { return FGetValidNavStandPosition(this, _npc, _pos); }
	bool IsValidStandPosition(const Vec3& _pos) const { return FIsValidStandPosition(this, _pos); }
	bool IsActive() const { return FIsActive(this); }
	bool IsValidDistractionForNpc(const ArkNpc& _npc, bool _bIgnoreDistanceCheck, bool _bIgnoreDirectionCheck, bool _bIgnoreAreasCheck, int& _numAreasFound, std::array<SAreaManagerResult, 16>& _foundAreas) { return FIsValidDistractionForNpc(this, _npc, _bIgnoreDistanceCheck, _bIgnoreDirectionCheck, _bIgnoreAreasCheck, _numAreasFound, _foundAreas); }
	bool ShouldUseLookAt() const { return FShouldUseLookAt(this); }
	bool CanDistractRetreatingEntity(const IEntity& _entity) const { return FCanDistractRetreatingEntity(this, _entity); }
	void TryStartAreaCooldown() { FTryStartAreaCooldown(this); }
	void TryDistract(uint64_t _distractionInstanceIndex, bool& _outSearched) { FTryDistract(this, _distractionInstanceIndex, _outSearched); }
	bool IsClearOfObstacles(const ArkNpc& _npc, const Vec3& _standPos) { return FIsClearOfObstacles(this, _npc, _standPos); }

#if 0
	void DebugDraw(float _arg0_);
	int GetDistractionDataIndex() const;
	bool GetClosestNavStandPosition(const ArkNpc& _arg0_, Vec3& _arg1_) const;
	bool IsInRange(const Vec3& _arg0_) const;
	bool IsInAngle(const Vec3& _arg0_) const;
	float GetStandDistanceFromPos(const Vec3& _arg0_) const;
	float GetStandAngleFromPos(const Vec3& _arg0_) const;
	bool IsInUse() const;
	DistractionState GetState() const;
	const char* GetCurrentStateText() const;
	bool DoesOwnerHaveAnyOtherActiveDistractions() const;
	void OnCompleted(bool _arg0_);
	bool NpcHasTag(const ArkNpc& _arg0_) const;
	void SetFailedReason(DistractionFailedReason _arg0_);
#endif

	static inline auto FArkDistractionInstanceOv1 = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A0EC0);
	static inline auto FBitNotArkDistractionInstance = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A0F10);
	static inline auto FInitialize = PreyFunction<void(ArkDistractionInstance* const _this, unsigned _entityId, int _distractionDataIndex)>(0x11A2000);
	static inline auto FDestroy = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A0FD0);
	static inline auto FEnable = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A10C0);
	static inline auto FDisable = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A1030);
	static inline auto FReset = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A2DB0);
	static inline auto FSerialize = PreyFunction<void(ArkDistractionInstance* const _this, TSerialize _ser)>(0x11A2E50);
	static inline auto FUpdate = PreyFunction<void(ArkDistractionInstance* const _this, uint64_t _distractionInstanceIndex, float _gameTime, bool& _outSearched)>(0x11A3410);
	static inline auto FGetEntity = PreyFunction<IEntity& (const ArkDistractionInstance* const _this)>(0x1112EA0);
	static inline auto FGetDistractionData = PreyFunction<const Distraction& (const ArkDistractionInstance* const _this)>(0x11A11E0);
	static inline auto FGetDistractionDataId = PreyFunction<uint64_t(const ArkDistractionInstance* const _this)>(0x11A1300);
	static inline auto FDistractNpc = PreyFunction<void(ArkDistractionInstance* const _this, ArkNpc& _npc, uint64_t _distractionInstanceIndex)>(0x11A1060);
	static inline auto FOnNpcAcquire = PreyFunction<void(ArkDistractionInstance* const _this, unsigned _npcEntityId)>(0x11A2C00);
	static inline auto FOnNpcIgnored = PreyFunction<void(ArkDistractionInstance* const _this, unsigned _npcEntityId)>(0x11A2D40);
	static inline auto FOnNpcDistractionComplete = PreyFunction<void(ArkDistractionInstance* const _this, unsigned _npcEntityId, bool _bSuccessful)>(0x11A2C10);
	static inline auto FGetWorldPos = PreyFunction<Vec3*(const ArkDistractionInstance* const _this, Vec3* _return_value_)>(0x11A18E0);
	static inline auto FGetWorldStandPos = PreyFunction<Vec3*(const ArkDistractionInstance* const _this, Vec3* _return_value_, const ArkNpc& _npc)>(0x11A1B50);
	static inline auto FGetWorldLookAtPos = PreyFunction<Vec3*(const ArkDistractionInstance* const _this, Vec3* _return_value_)>(0x11A1670);
	static inline auto FGetForwardDirection = PreyFunction<Vec3*(const ArkDistractionInstance* const _this, Vec3* _return_value_)>(0x11A1360);
	static inline auto FGetValidNavStandPosition = PreyFunction<bool(const ArkDistractionInstance* const _this, const ArkNpc& _npc, Vec3& _pos)>(0x11A1500);
	static inline auto FIsValidStandPosition = PreyFunction<bool(const ArkDistractionInstance* const _this, const Vec3& _pos)>(0x11A29C0);
	static inline auto FIsActive = PreyFunction<bool(const ArkDistractionInstance* const _this)>(0x11A20D0);
	static inline auto FIsValidDistractionForNpc = PreyFunction<bool(ArkDistractionInstance* const _this, const ArkNpc& _npc, bool _bIgnoreDistanceCheck, bool _bIgnoreDirectionCheck, bool _bIgnoreAreasCheck, int& _numAreasFound, std::array<SAreaManagerResult, 16>& _foundAreas)>(0x11A2500);
	static inline auto FShouldUseLookAt = PreyFunction<bool(const ArkDistractionInstance* const _this)>(0x11A2FA0);
	static inline auto FCanDistractRetreatingEntity = PreyFunction<bool(const ArkDistractionInstance* const _this, const IEntity& _entity)>(0x11A0F30);
	static inline auto FTryStartAreaCooldown = PreyFunction<void(ArkDistractionInstance* const _this)>(0x11A3370);
	static inline auto FTryDistract = PreyFunction<void(ArkDistractionInstance* const _this, uint64_t _distractionInstanceIndex, bool& _outSearched)>(0x11A2FC0);
	static inline auto FIsClearOfObstacles = PreyFunction<bool(ArkDistractionInstance* const _this, const ArkNpc& _npc, const Vec3& _standPos)>(0x11A20E0);
};
#endif // !MOONCRASH
