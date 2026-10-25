// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/GameDll/ark/weapons/arkweaponactions.h>

class ArkNpc;
class ArkSafeScriptTable;
class ArkStatsComponent;
class CArkWeapon;

// Header: FromCpp
// Prey/GameDll/ark/weapons/ArkWrenchComponent.h
class ArkWrenchComponent // Id=801A7D6 Size=88
{
public:
	enum class hitResult
	{
		none = 0,
		hit = 1,
		hitEnemy = 2,
	};

	// Instantiations: T = ArkWeaponWrench, ArkWeaponDoubleWrench.
	// No addresses: they differ per instantiation.
	template <typename T>
	class Action : public ArkWeaponAttackAction // Id=801BC27 Size=136
	{
	public:
		virtual void Exit();
		virtual void OnActionEvent(const unsigned _eventCRC);

#if 0
		Action(unsigned _arg0_, int _arg1_);
		virtual ~Action();
#endif
	};

	// Instantiations: T = ArkWeaponWrench, ArkWeaponDoubleWrench.
	template <typename T>
	class GenericFatalityAction : public ArkWeaponAttackAction // Id=801CDB6 Size=144
	{
	public:
		unsigned m_target;

		GenericFatalityAction(unsigned _weaponId, int _fragmentId, const ArkNpc& _npc);
		virtual void OnActionEvent(const unsigned _eventCRC);

#if 0
		virtual ~GenericFatalityAction();
#endif
	};

	uint64_t m_packageId = -1;
	uint64_t m_criticalPackageId = -1;
	uint64_t m_chargedPackageId = -1;
	uint64_t m_chargedCriticalPackageId = -1;
	int m_hitType = 0;
	float m_hitOffset = 0;
	float m_maxForceMassScale = 0;
	float m_rayRange = 0;
	float m_speedRangeFactor = 0;
	float m_speedRangeMax = 0;
	float m_fatigueThisHit = 0;
	bool m_bChain = false;
	bool m_bInterrupt = false;
	bool m_bInChainWindow = false;
	bool m_bDodge = false;
	std::vector<uint64_t> m_sneakAttackMetaTags;

	static uint64_t GetWrenchArchetypeId() { return FGetWrenchArchetypeId(); }
	static uint64_t GetDoubleWrenchArchetypeId() { return FGetDoubleWrenchArchetypeId(); }
	void LoadCachedProperties(ArkSafeScriptTable const &_properties) { FLoadCachedProperties(this,_properties); }
#ifndef MOONCRASH
	void InitializeStats(ArkSafeScriptTable const &_properties, ArkStatsComponent &_stats) { FInitializeStats(this,_properties,_stats); }
	void PreviewFatigue(bool _bCharged, float _maxChargeMultiplier) { FPreviewFatigue(this,_bCharged,_maxChargeMultiplier); }
#else
	void InitializeStats(const ArkSafeScriptTable& _properties, ArkStatsComponent& _stats, const bool _bIsSword) { FInitializeStats(this, _properties, _stats, _bIsSword); }
	void PreviewFatigue(CArkWeapon& _weapon, bool _bCharged, float _maxChargeMultiplier) { FPreviewFatigue(this, _weapon, _bCharged, _maxChargeMultiplier); }
#endif
	ArkWrenchComponent::hitResult OnHit(const float _dir, CArkWeapon &_weapon, const float _damageScale, const bool _bCharged) { return FOnHit(this,_dir,_weapon,_damageScale,_bCharged); }
#ifndef MOONCRASH
	std::vector<ray_hit> GetHits(CArkWeapon const &_weapon, const float _angle) const { return FGetHits(this,_weapon,_angle); }
	void TryStartNpcDodge(CArkWeapon const &_weapon, const float _swipeDirection) { FTryStartNpcDodge(this,_weapon,_swipeDirection); }
#else
	std::vector<ray_hit> GetHits(const CArkWeapon& _weapon, const float _angle) const { alignas(std::vector<ray_hit>) std::byte _return_buf_[sizeof(std::vector<ray_hit>)]; return *FGetHits(this, reinterpret_cast<std::vector<ray_hit>*>(_return_buf_), _weapon, _angle); }
#endif
	void KillNpc(ArkNpc &_npc, const unsigned _weaponId) const { FKillNpc(this,_npc,_weaponId); }
#ifdef MOONCRASH
	bool ConsumeInterrupt(const CArkWeapon& _weapon) { return FConsumeInterrupt(this, _weapon); }
#endif
	static bool ShouldUseDoubleWrench() { return FShouldUseDoubleWrench(); }
#ifndef MOONCRASH
	std::pair<ArkNpc *,bool> GetNpcToPerformFatalityOn(CArkWeapon &_weapon) const { return FGetNpcToPerformFatalityOn(this,_weapon); }
#else
	std::pair<ArkNpc*, bool> GetNpcToPerformFatalityOn(CArkWeapon& _weapon) const { alignas(std::pair<ArkNpc*, bool>) std::byte _return_buf_[sizeof(std::pair<ArkNpc*, bool>)]; return *FGetNpcToPerformFatalityOn(this, reinterpret_cast<std::pair<ArkNpc*, bool>*>(_return_buf_), _weapon); }
#endif

#if 0
	ArkWrenchComponent();
	static void RegisterCVars();
	void GainFatigue(float arg0) const;
	void OnPlayAnim(const bool arg0);
#ifndef MOONCRASH
	bool ConsumeInterrupt(CArkWeapon const &arg0);
#else
	void TryStartNpcDodge(const CArkWeapon& _arg0_, const float _arg1_);
#endif
	bool InChainWindow() const;
	void RequestChain();
	void EnterChainWindow();
	bool ConsumeChainRequest();
	uint64_t GetPackageId() const;
	uint64_t GetChargedPackageId() const;
#endif

#ifndef MOONCRASH
	static inline auto FGetWrenchArchetypeId = PreyFunction<uint64_t()>(0x1391890);
	static inline auto FGetDoubleWrenchArchetypeId = PreyFunction<uint64_t()>(0x1390540);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkWrenchComponent *const _this, ArkSafeScriptTable const &_properties)>(0x1391F30);
	static inline auto FInitializeStats = PreyFunction<void(ArkWrenchComponent *const _this, ArkSafeScriptTable const &_properties, ArkStatsComponent &_stats)>(0x1391910);
	static inline auto FPreviewFatigue = PreyFunction<void(ArkWrenchComponent *const _this, bool _bCharged, float _maxChargeMultiplier)>(0x1392F90);
	static inline auto FOnHit = PreyFunction<ArkWrenchComponent::hitResult(ArkWrenchComponent *const _this, const float _dir, CArkWeapon &_weapon, const float _damageScale, const bool _bCharged)>(0x13926D0);
	static inline auto FGetHits = PreyFunction<std::vector<ray_hit>(ArkWrenchComponent const *const _this, CArkWeapon const &_weapon, const float _angle)>(0x13905C0);
	static inline auto FTryStartNpcDodge = PreyFunction<void(ArkWrenchComponent *const _this, CArkWeapon const &_weapon, const float _swipeDirection)>(0x1393400);
	static inline auto FKillNpc = PreyFunction<void(ArkWrenchComponent const *const _this, ArkNpc &_npc, const unsigned _weaponId)>(0x1391D80);
	static inline auto FShouldUseDoubleWrench = PreyFunction<bool()>(0x1393040);
	static inline auto FGetNpcToPerformFatalityOn = PreyFunction<std::pair<ArkNpc *,bool>(ArkWrenchComponent const *const _this, CArkWeapon &_weapon)>(0x13913D0);
#else
	static inline auto FGetWrenchArchetypeId = PreyFunction<uint64_t()>(0x149B690);
	static inline auto FGetDoubleWrenchArchetypeId = PreyFunction<uint64_t()>(0x149A170);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkWrenchComponent* const _this, const ArkSafeScriptTable& _properties)>(0x149BEF0);
	static inline auto FInitializeStats = PreyFunction<void(ArkWrenchComponent* const _this, const ArkSafeScriptTable& _properties, ArkStatsComponent& _stats, const bool _bIsSword)>(0x149B710);
	static inline auto FPreviewFatigue = PreyFunction<void(ArkWrenchComponent* const _this, CArkWeapon& _weapon, bool _bCharged, float _maxChargeMultiplier)>(0x149D730);
	static inline auto FOnHit = PreyFunction<ArkWrenchComponent::hitResult(ArkWrenchComponent* const _this, const float _dir, CArkWeapon& _weapon, const float _damageScale, const bool _bCharged)>(0x149CE30);
	static inline auto FGetHits = PreyFunction<std::vector<ray_hit>*(const ArkWrenchComponent* const _this, std::vector<ray_hit>* _return_value_, const CArkWeapon& _weapon, const float _angle)>(0x149A1F0);
	static inline auto FKillNpc = PreyFunction<void(const ArkWrenchComponent* const _this, ArkNpc& _npc, const unsigned _weaponId)>(0x149BD40);
	static inline auto FConsumeInterrupt = PreyFunction<bool(ArkWrenchComponent* const _this, const CArkWeapon& _weapon)>(0x149A0B0);
	static inline auto FShouldUseDoubleWrench = PreyFunction<bool()>(0x149D7D0);
	static inline auto FGetNpcToPerformFatalityOn = PreyFunction<std::pair<ArkNpc*, bool>*(const ArkWrenchComponent* const _this, std::pair<ArkNpc*, bool>* _return_value_, CArkWeapon& _weapon)>(0x149B1D0);
#endif
};
