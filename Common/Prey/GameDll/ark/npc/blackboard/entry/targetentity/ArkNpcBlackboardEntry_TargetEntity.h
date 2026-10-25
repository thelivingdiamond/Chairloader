// Header file automatically created from a PDB.
// (Dumped under _unknown/; placed next to the other blackboard entries.)
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardEntryTemplates.h>

struct IEntity;
class ArkNpcBlackboardKey_TargetEntity;
class ArkNpcBlackboardEntryKey_TargetEntity;

// ArkNpcBlackboardEntry_TargetEntity
// Header:  Prey/GameDll/ark/npc/blackboard/entry/targetentity/ArkNpcBlackboardEntry_TargetEntity.h
class ArkNpcBlackboardEntry_TargetEntity : public ArkNpcBlackboardEntryTemplate_SetGet<ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardEntryKey_TargetEntity,ArkNpcBlackboardEntry_TargetEntity,IEntity*,IEntity*>
{ // Size=4 (0x4)
public:
	unsigned m_targetEntityId;

	ArkNpcBlackboardEntry_TargetEntity();
	void Set(unsigned _targetEntityId) { FSetOv2(this, _targetEntityId); }
	IEntity* Get() const { return FGet(this); }

#if 0
	void Set(const IEntity& _arg0_);
	void Set(const IEntity* _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FArkNpcBlackboardEntry_TargetEntityOv2 = PreyFunction<void(ArkNpcBlackboardEntry_TargetEntity* const _this)>(0x1524620);
	static inline auto FSetOv2 = PreyFunction<void(ArkNpcBlackboardEntry_TargetEntity* const _this, unsigned _targetEntityId)>(0x1210520);
	static inline auto FGet = PreyFunction<IEntity* (const ArkNpcBlackboardEntry_TargetEntity* const _this)>(0x1210510);
#else
	static inline auto FArkNpcBlackboardEntry_TargetEntityOv2 = PreyFunction<void(ArkNpcBlackboardEntry_TargetEntity* const _this)>(0x1643FB0);
	static inline auto FSetOv2 = PreyFunction<void(ArkNpcBlackboardEntry_TargetEntity* const _this, unsigned _targetEntityId)>(0x129F6F0);
	static inline auto FGet = PreyFunction<IEntity* (const ArkNpcBlackboardEntry_TargetEntity* const _this)>(0x129F6E0);
#endif
};
