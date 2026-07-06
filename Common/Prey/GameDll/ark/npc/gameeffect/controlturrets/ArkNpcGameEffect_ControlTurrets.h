// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_ControlTurrets;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ArkTurretController;
struct HitInfo;
struct IEntity;

// ArkNpcGameEffect_ControlTurrets
// Header:  Prey/GameDll/ark/npc/gameeffect/controlturrets/ArkNpcGameEffect_ControlTurrets.h
class ArkNpcGameEffect_ControlTurrets : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>
{ // Size=72 (0x48)
public:
	unsigned m_maxControllableTurrets;
	float m_turretDesiredDistanceFromNpc;
	float m_desiredTurretHeight;
	float m_turretCheckRadius;
	float m_turretRotationSpeed;
	float m_timeBetweenTurretScans;
	float m_formationChangeRotationSpeed;
	float m_turretTraceAdjustmentRadius;
	uint64_t m_requiredTurretTag;
	uint64_t m_defaultTurretFaction;
	uint64_t m_conditionalOwnerFaction;
	uint64_t m_conditionalTurretFaction;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_ControlTurrets();
	void Serialize(ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, TSerialize _ser) const { FSerialize(this, _npc, _gameEffectInstance, _ser); }
	int GetNumControlledTurrets(ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { return FGetNumControlledTurrets(this, _gameEffectInstance); }
	std::vector<unsigned int> GetControlledTurretIds(ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGetControlledTurretIds(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _gameEffectInstance); }
	void GenerateTurretControllers(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { FGenerateTurretControllers(this, _npc, _gameEffectInstance); }
	void GrabSurroundingTurrets(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { FGrabSurroundingTurrets(this, _npc, _gameEffectInstance); }
	bool CanStartControllingTurret(const IEntity& _entity, const ArkNpc& _npc, const ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { return FCanStartControllingTurret(this, _entity, _npc, _gameEffectInstance); }
	bool ControlTurretAtNearestControlPoint(const unsigned _turretId, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { return FControlTurretAtNearestControlPoint(this, _turretId, _npc, _gameEffectInstance); }
	void UpdateControlledTurrets(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime) const { FUpdateControlledTurrets(this, _npc, _gameEffectInstance, _elapsedTime); }
	void UpdateFormationPositions(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime) const { FUpdateFormationPositions(this, _npc, _gameEffectInstance, _elapsedTime); }
	void UpdateNormalControlPositions(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime) const { FUpdateNormalControlPositions(this, _npc, _gameEffectInstance, _elapsedTime); }
	void UpdateAttackControlPositions(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime) const { FUpdateAttackControlPositions(this, _npc, _gameEffectInstance, _elapsedTime); }
	void MoveControlPositionsToDesiredLocations(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime) const { FMoveControlPositionsToDesiredLocations(this, _npc, _gameEffectInstance, _elapsedTime); }
	void AssignTurretControllerPositions(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { FAssignTurretControllerPositions(this, _npc, _gameEffectInstance); }
	void OnFormationChange(const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance) const { FOnFormationChange(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, float _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void ReleaseControlOnAllTurretsNew(const ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	bool IsControllingMaxNumberOfTurrets(ArkNpcGameEffectInstance_ControlTurrets& _arg0_) const;
	void FindSurroundingControllableTurrets(const ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, std::vector<unsigned int>& _arg2_) const;
	int GetClosestUnusedTurretControlPointTo(const Vec3& _arg0_, const ArkNpc& _arg1_, ArkNpcGameEffectInstance_ControlTurrets& _arg2_) const;
	void BeginTurretControl(const unsigned _arg0_, ArkTurretController& _arg1_, const ArkNpc& _arg2_, ArkNpcGameEffectInstance_ControlTurrets& _arg3_) const;
	void UpdateControlPositions(const ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, float _arg2_) const;
	void UpdateDebugControlPositions(const ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, float _arg2_) const;
	void UnpinControlPositions(ArkNpcGameEffectInstance_ControlTurrets& _arg0_) const;
	void UnassignTurretControllerPositions(ArkNpcGameEffectInstance_ControlTurrets& _arg0_) const;
	void TryRefreshFormationAssignments(const ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, float _arg2_) const;
	bool AllActiveControllersHolding(ArkNpcGameEffectInstance_ControlTurrets& _arg0_) const;
	void ReleaseControlOnAllTurrets(const ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void AdvanceAllowedTraceIndex(ArkNpcGameEffectInstance_ControlTurrets& _arg0_) const;
	uint64_t GetExpectedTurretFaction(const ArkNpc& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x134F880);
	static inline auto FArkNpcGameEffect_ControlTurrets = PreyFunction<void(ArkNpcGameEffect_ControlTurrets* const _this)>(0x134EAE0);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, TSerialize _ser)>(0x13513B0);
	static inline auto FGetNumControlledTurrets = PreyFunction<int(const ArkNpcGameEffect_ControlTurrets* const _this, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x1350140);
	static inline auto FGetControlledTurretIds = PreyFunction<std::vector<unsigned int>*(const ArkNpcGameEffect_ControlTurrets* const _this, std::vector<unsigned int>* _return_value_, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x134FFA0);
	static inline auto FGenerateTurretControllers = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x134FCD0);
	static inline auto FGrabSurroundingTurrets = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x13502C0);
	static inline auto FCanStartControllingTurret = PreyFunction<bool(const ArkNpcGameEffect_ControlTurrets* const _this, const IEntity& _entity, const ArkNpc& _npc, const ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x134F400);
	static inline auto FControlTurretAtNearestControlPoint = PreyFunction<bool(const ArkNpcGameEffect_ControlTurrets* const _this, const unsigned _turretId, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x134F6A0);
	static inline auto FUpdateControlledTurrets = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime)>(0x1351D40);
	static inline auto FUpdateFormationPositions = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime)>(0x1351FF0);
	static inline auto FUpdateNormalControlPositions = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime)>(0x13521B0);
	static inline auto FUpdateAttackControlPositions = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime)>(0x13516E0);
	static inline auto FMoveControlPositionsToDesiredLocations = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance, float _elapsedTime)>(0x1350680);
	static inline auto FAssignTurretControllerPositions = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x134EE00);
	static inline auto FOnFormationChange = PreyFunction<void(const ArkNpcGameEffect_ControlTurrets* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_ControlTurrets& _gameEffectInstance)>(0x13512D0);
};
#endif // MOONCRASH
