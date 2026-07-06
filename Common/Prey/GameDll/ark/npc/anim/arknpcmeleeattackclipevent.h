// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/IProceduralParams.h>

struct IAttachment;
struct IEntity;
struct SArkNpcMeleeAttackClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkNpcMeleeAttackProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arknpcmeleeattackclipevent.h
class CArkNpcMeleeAttackProceduralClipEvent : public TProceduralClip<SArkNpcMeleeAttackClipEventParams>
{ // Size=176 (0xB0)
public:
	using HitEntitiesDamageCooldown = std::unordered_map<unsigned int, float>;

	std::unordered_map<unsigned int, float> m_hitEntitiesCooldown;
	_smart_ptr<IAttachment> m_pDamageAttachment;
	Vec3 m_previousDamageAttachmentPosition;
	uint64_t m_damageSignalPackageId;

	static unsigned GetStartCRC() { return FGetStartCRC(); }
	virtual void OnEnter(float blendTime, float duration, const SArkNpcMeleeAttackClipEventParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float _frameTime);
	void DamageHitEntities() { FDamageHitEntities(this); }
	void DealDamage(IEntity* _pHitEntity) { FDealDamage(this, _pHitEntity); }

#if 0
	CArkNpcMeleeAttackProceduralClipEvent();
	static unsigned GetStopCRC();
#endif

	static inline auto FGetStartCRC = PreyFunction<unsigned()>(0x12774F0);
	static inline auto FOnEnter = PreyFunction<void(CArkNpcMeleeAttackProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcMeleeAttackClipEventParams& params)>(0x1277640);
	static inline auto FOnExit = PreyFunction<void(CArkNpcMeleeAttackProceduralClipEvent* const _this, float blendTime)>(0x1277890);
	static inline auto FUpdate = PreyFunction<void(CArkNpcMeleeAttackProceduralClipEvent* const _this, float _frameTime)>(0x1277A70);
	static inline auto FDamageHitEntities = PreyFunction<void(CArkNpcMeleeAttackProceduralClipEvent* const _this)>(0x1276E80);
	static inline auto FDealDamage = PreyFunction<void(CArkNpcMeleeAttackProceduralClipEvent* const _this, IEntity* _pHitEntity)>(0x12770B0);
};

// SArkNpcMeleeAttackClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arknpcmeleeattackclipevent.h
struct SArkNpcMeleeAttackClipEventParams : public IProceduralParams
{ // Size=40 (0x28)
	string m_attachmentName;
	float m_hitCheckRadius;
	float m_onPlayerHitImpulse;
	float m_onNpcHitImpulse;
	float m_onOtherHitImpulse;
	float m_damageCooldown;
	bool m_bHalfDamage;
	bool m_bSingleHitPerEntity;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcMeleeAttackClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(SArkNpcMeleeAttackClipEventParams* const _this, Serialization::IArchive& ar)>(0x1277960);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcMeleeAttackClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
