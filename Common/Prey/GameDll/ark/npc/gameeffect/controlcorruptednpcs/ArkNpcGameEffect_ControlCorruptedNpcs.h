// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_ControlCorruptedNpcs;
struct IEntity;

// ArkNpcGameEffect_ControlCorruptedNpcs
// Header:  Prey/GameDll/ark/npc/gameeffect/controlcorruptednpcs/ArkNpcGameEffect_ControlCorruptedNpcs.h
class ArkNpcGameEffect_ControlCorruptedNpcs : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>
{ // Size=24 (0x18)
public:
	float m_minRadiusToLeader;
	float m_maxRadiusToLeader;
	float m_refreshPositionCooldown;
	float m_refreshPositionsOnLeaderMoveDistance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_ControlCorruptedNpcs();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance, const float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void OnNumberOfControlledNpcsChanged(ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance) const { FOnNumberOfControlledNpcsChanged(this, _npc, _gameEffectInstance); }
	void CalculateAllRelativeStandPositions(ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance) const { FCalculateAllRelativeStandPositions(this, _gameEffectInstance); }
	void CalculateRelativeStandPosition(int _positionIndex, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance) const { FCalculateRelativeStandPosition(this, _positionIndex, _gameEffectInstance); }
	void UpdateStandPositionsOfControlledNpcs(ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance) const { FUpdateStandPositionsOfControlledNpcs(this, _npc, _gameEffectInstance); }
	void AssignControlledNpcsToStandPositions(ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance) const { FAssignControlledNpcsToStandPositions(this, _npc, _gameEffectInstance); }
	int GetNumberOfControlledNpcsThatCanFollow(ArkNpc& _npc) const { return FGetNumberOfControlledNpcsThatCanFollow(this, _npc); }
	Vec3 GetWorldStandPosition(ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance, int _positionIndex) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetWorldStandPosition(this, reinterpret_cast<Vec3*>(_return_buf_), _npc, _gameEffectInstance, _positionIndex); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	void UpdateAttention(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	bool GroupHasTopAttentionTarget(ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg0_) const;
	void PushGroupAttentionTarget(ArkNpc& _arg0_, unsigned _arg1_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg2_) const;
	void PopGroupAttentionTarget(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	Vec3 GetPositionOnNavigationMesh(IEntity& _arg0_, const Vec3& _arg1_) const;
	bool IsValidStandPosition(IEntity& _arg0_, const Vec3& _arg1_, const Vec3& _arg2_) const;
	int GetNumberOfFollowingNpcs(ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg0_) const;
	bool CanControlledNpcFollow(unsigned _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12A9B20);
	static inline auto FArkNpcGameEffect_ControlCorruptedNpcs = PreyFunction<void(ArkNpcGameEffect_ControlCorruptedNpcs* const _this)>(0x12A9480);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance, const float _elapsedTime)>(0x12A9ED0);
	static inline auto FOnNumberOfControlledNpcsChanged = PreyFunction<void(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance)>(0x12A9E00);
	static inline auto FCalculateAllRelativeStandPositions = PreyFunction<void(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance)>(0x12A9890);
	static inline auto FCalculateRelativeStandPosition = PreyFunction<void(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, int _positionIndex, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance)>(0x12A9990);
	static inline auto FUpdateStandPositionsOfControlledNpcs = PreyFunction<void(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance)>(0x12AA210);
	static inline auto FAssignControlledNpcsToStandPositions = PreyFunction<void(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance)>(0x12A9580);
	static inline auto FGetNumberOfControlledNpcsThatCanFollow = PreyFunction<int(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, ArkNpc& _npc)>(0x12A9C70);
	static inline auto FGetWorldStandPosition = PreyFunction<Vec3*(const ArkNpcGameEffect_ControlCorruptedNpcs* const _this, Vec3* _return_value_, ArkNpc& _npc, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _gameEffectInstance, int _positionIndex)>(0x12A9CE0);
};
#endif // MOONCRASH
