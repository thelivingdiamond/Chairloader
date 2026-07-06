// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/IProceduralParams.h>

struct IAttachment;
struct IEntity;
struct SArkNpcConeAttackClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkNpcConeAttackProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arknpcconeattackclipevent.h
class CArkNpcConeAttackProceduralClipEvent : public TProceduralClip<SArkNpcConeAttackClipEventParams>
{ // Size=192 (0xC0)
public:
	using HitEntitiesDamageCooldown = std::unordered_map<unsigned int, float>;

	std::unordered_map<unsigned int, float> m_hitEntitiesCooldown;
	_smart_ptr<IAttachment> m_pDamageAttachment;
	Vec3 m_previousDamageAttachmentPosition;
	uint64_t m_damageSignalPackageId;
	float m_coneCosAngle;

	static unsigned GetStartCRC() { return FGetStartCRC(); }
	virtual void OnEnter(float blendTime, float duration, const SArkNpcConeAttackClipEventParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float _frameTime);
	void DamageHitEntities() { FDamageHitEntities(this); }
	void DealDamage(IEntity* _pHitEntity) { FDealDamage(this, _pHitEntity); }

#if 0
	CArkNpcConeAttackProceduralClipEvent();
	static unsigned GetStopCRC();
#endif

	static inline auto FGetStartCRC = PreyFunction<unsigned()>(0x12729D0);
	static inline auto FOnEnter = PreyFunction<void(CArkNpcConeAttackProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcConeAttackClipEventParams& params)>(0x1272B30);
	static inline auto FOnExit = PreyFunction<void(CArkNpcConeAttackProceduralClipEvent* const _this, float blendTime)>(0x1272D90);
	static inline auto FUpdate = PreyFunction<void(CArkNpcConeAttackProceduralClipEvent* const _this, float _frameTime)>(0x1272FB0);
	static inline auto FDamageHitEntities = PreyFunction<void(CArkNpcConeAttackProceduralClipEvent* const _this)>(0x1272080);
	static inline auto FDealDamage = PreyFunction<void(CArkNpcConeAttackProceduralClipEvent* const _this, IEntity* _pHitEntity)>(0x1272560);
};

// SArkNpcConeAttackClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arknpcconeattackclipevent.h
struct SArkNpcConeAttackClipEventParams : public IProceduralParams
{ // Size=48 (0x30)
	string m_attachmentName;
	float m_coneAngle;
	float m_coneLength;
	float m_coneOffset;
	float m_onPlayerHitImpulse;
	float m_onNpcHitImpulse;
	float m_onOtherHitImpulse;
	float m_damageCooldown;
	bool m_bHalfDamage;
	bool m_bSingleHitPerEntity;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcConeAttackClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(SArkNpcConeAttackClipEventParams* const _this, Serialization::IArchive& ar)>(0x1272E60);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcConeAttackClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
