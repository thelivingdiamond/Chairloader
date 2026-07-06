// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkProjectile.h>

struct IGameObject;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkProjectileSwordSwipe
// Header:  Prey/GameDll/ark/weapons/ArkProjectileSwordSwipe.h
class CArkProjectileSwordSwipe : public CArkProjectile
{ // Size=720 (0x2D0)
public:
	float m_minEffectStrength;
	float m_rateEffectStrength;
	float m_currentEffectStrength;
	std::vector<unsigned int> m_uniqueEnemiesDamaged;
	float m_damageMultiplier;
	int m_numEnemiesDamagedForAchievement;

	CArkProjectileSwordSwipe();
	virtual ~CArkProjectileSwordSwipe();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ReInitFromPool();
	virtual void SetOwnerIdAndWeaponClassName(const unsigned _ownerId, const uint64_t _ownerWeaponId, const string& _weaponName);
	virtual void LoadCachedProperties();
	virtual void Physicalize(const string& _physicsType);

#if 0
	void SetDamageMultiplier(const float _arg0_);
	float GetDamageMultiplier() const;
#endif

	static inline auto FCArkProjectileSwordSwipeOv1 = PreyFunction<void(CArkProjectileSwordSwipe* const _this)>(0x148BDB0);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileSwordSwipe* const _this, IGameObject* _pGameObject)>(0x148C6B0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileSwordSwipe* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x148C800);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileSwordSwipe* const _this, const SGameObjectEvent& _event)>(0x148C000);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileSwordSwipe* const _this, TSerialize _ser)>(0x148BE50);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectileSwordSwipe* const _this)>(0x148C6E0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileSwordSwipe* const _this)>(0x148C710);
	static inline auto FSetOwnerIdAndWeaponClassName = PreyFunction<void(CArkProjectileSwordSwipe* const _this, const unsigned _ownerId, const uint64_t _ownerWeaponId, const string& _weaponName)>(0x148C760);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileSwordSwipe* const _this)>(0x148C380);
	static inline auto FPhysicalize = PreyFunction<void(CArkProjectileSwordSwipe* const _this, const string& _physicsType)>(0x148C530);
};
#endif // MOONCRASH
