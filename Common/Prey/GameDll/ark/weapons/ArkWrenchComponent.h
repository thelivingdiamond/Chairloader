// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/weapons/arkweaponactions.h>
#include <Prey/GameDll/ark/weapons/arkwrenchcomponent.h>

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

	template <typename T>
	class Action : public ArkWeaponAttackAction // Id=801BC27 Size=136
	{
	public:
#if 0
		void Action(const unsigned arg0, const int arg1);
		virtual void Exit();
		virtual void OnActionEvent(const unsigned _eventCRC);
		virtual void ~Action();
#endif
	};

	template <typename T>
	class GenericFatalityAction : public ArkWeaponAttackAction // Id=801CDB6 Size=144
	{
	public:
		unsigned m_target;

#if 0
		void GenericFatalityAction(const unsigned arg0, const int arg1, ArkNpc& arg2);
		virtual void OnActionEvent(const unsigned _eventCRC);
		virtual void ~GenericFatalityAction();
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
	void InitializeStats(ArkSafeScriptTable const &_properties, ArkStatsComponent &_stats) { FInitializeStats(this,_properties,_stats); }
	void PreviewFatigue(bool _bCharged, float _maxChargeMultiplier) { FPreviewFatigue(this,_bCharged,_maxChargeMultiplier); }
	ArkWrenchComponent::hitResult OnHit(const float _dir, CArkWeapon &_weapon, const float _damageScale, const bool _bCharged) { return FOnHit(this,_dir,_weapon,_damageScale,_bCharged); }
	std::vector<ray_hit> GetHits(CArkWeapon const &_weapon, const float _angle) const { return FGetHits(this,_weapon,_angle); }
	void TryStartNpcDodge(CArkWeapon const &_weapon, const float _swipeDirection) { FTryStartNpcDodge(this,_weapon,_swipeDirection); }
	void KillNpc(ArkNpc &_npc, const unsigned _weaponId) const { FKillNpc(this,_npc,_weaponId); }
	static bool ShouldUseDoubleWrench() { return FShouldUseDoubleWrench(); }
	std::pair<ArkNpc *,bool> GetNpcToPerformFatalityOn(CArkWeapon &_weapon) const { return FGetNpcToPerformFatalityOn(this,_weapon); }
	
#if 0
	static void RegisterCVars();
	void GainFatigue(float arg0) const;
	void OnPlayAnim(const bool arg0);
	bool ConsumeInterrupt(CArkWeapon const &arg0);
	bool InChainWindow() const;
	void RequestChain();
	void EnterChainWindow();
	bool ConsumeChainRequest();
	uint64_t GetPackageId() const;
	uint64_t GetChargedPackageId() const;
#endif
	
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
};

