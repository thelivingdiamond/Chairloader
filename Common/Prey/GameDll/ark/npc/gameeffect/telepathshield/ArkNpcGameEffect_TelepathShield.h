// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_TelepathShield;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;
struct IEntity;

// ArkNpcGameEffect_TelepathShield
// Header:  Prey/GameDll/ark/npc/gameeffect/telepathshield/ArkNpcGameEffect_TelepathShield.h
class ArkNpcGameEffect_TelepathShield : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>
{ // Size=64 (0x40)
public:
	string m_shieldAttachmentPoint;
	string m_shieldSurfaceMaterial;
	uint64_t m_dissolveOnSignalGroupId;
	uint64_t m_signalModifierId;
	uint64_t m_fearPackageId;
	float m_burstFearRadius;
	float m_dissolveDuration;
	float m_shieldRadius;
	float m_shieldHeight;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_TelepathShield();
	void StartDissolve(ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance) const { FStartDissolve(this, _npc, _gameEffectInstance); }
	void StopDissolve(ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance) const { FStopDissolve(this, _npc, _gameEffectInstance); }
	void CreateShieldEntity(ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance) const { FCreateShieldEntity(this, _npc, _gameEffectInstance); }
	void AttachShieldEntity(ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance) const { FAttachShieldEntity(this, _npc, _gameEffectInstance); }
	void DestroyShieldEntity(ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance) const { FDestroyShieldEntity(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, float _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, TSerialize _arg2_) const;
	void FearEntity(ArkNpc& _arg0_, IEntity& _arg1_) const;
	void FearBurst(ArkNpc& _arg0_) const;
	bool IsDissolved(ArkNpcGameEffectInstance_TelepathShield& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B3270);
	static inline auto FArkNpcGameEffect_TelepathShield = PreyFunction<void(ArkNpcGameEffect_TelepathShield* const _this)>(0x12B2AF0);
	static inline auto FStartDissolve = PreyFunction<void(const ArkNpcGameEffect_TelepathShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance)>(0x12B3A30);
	static inline auto FStopDissolve = PreyFunction<void(const ArkNpcGameEffect_TelepathShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance)>(0x12B3AB0);
	static inline auto FCreateShieldEntity = PreyFunction<void(const ArkNpcGameEffect_TelepathShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance)>(0x12B2E90);
	static inline auto FAttachShieldEntity = PreyFunction<void(const ArkNpcGameEffect_TelepathShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance)>(0x12B2C30);
	static inline auto FDestroyShieldEntity = PreyFunction<void(const ArkNpcGameEffect_TelepathShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_TelepathShield& _gameEffectInstance)>(0x12B3200);
};
#endif // MOONCRASH
