// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>
#include <Prey/GameDll/ark/weapons/arkprojectilegoo.h>

class ArkSafeScriptTable;
struct IGameObject;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilegooball.h
class CArkProjectileGooBall : public CArkProjectile // Id=801BC03 Size=776
{
public:
	float m_initialStretch;
	int m_numBouncesAllowed;
	int m_viewDistanceRatio;
	float m_timeStretch;
	int m_numBounces;
	int m_modelNum;
	bool m_bAmmoIsPooled;
	bool m_bSpawnGoo;
	CArkProjectileGoo::ArkGooSpawnParameters m_spawnParameters;
	
	CArkProjectileGooBall();
	virtual ~CArkProjectileGooBall();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ReInitFromPool();
	virtual void LoadModel();
	virtual string GetModelFilename(ArkSafeScriptTable const &_propertiesTable);
	virtual void LoadCachedProperties();
	virtual void Physicalize(string const &_physicsType);
	
	static inline auto FPostInit = PreyFunction<void(CArkProjectileGooBall *const _this, IGameObject *_pGameObject)>(0x1381530);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGooBall *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1381670);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileGooBall *const _this, SGameObjectEvent const &_event)>(0x1380900);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileGooBall *const _this, TSerialize _ser)>(0x13806A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectileGooBall *const _this)>(0x13815C0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileGooBall *const _this)>(0x13815D0);
	static inline auto FLoadModel = PreyFunction<void(CArkProjectileGooBall *const _this)>(0x1381260);
	static inline auto FGetModelFilename = PreyFunction<string(CArkProjectileGooBall *const _this, ArkSafeScriptTable const &_propertiesTable)>(0x1380710);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileGooBall *const _this)>(0x1380F90);
	static inline auto FPhysicalize = PreyFunction<void(CArkProjectileGooBall *const _this, string const &_physicsType)>(0x13814A0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/weapons/ArkProjectile.h>
#include <Prey/GameDll/ark/weapons/ArkProjectileGoo.h>

class ArkSafeScriptTable;
struct IGameObject;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkProjectileGooBall
// Header:  Prey/GameDll/ark/weapons/ArkProjectileGooBall.h
class CArkProjectileGooBall : public CArkProjectile
{ // Size=800 (0x320)
public:
	float m_initialStretch;
	int m_numBouncesAllowed;
	int m_viewDistanceRatio;
	float m_timeStretch;
	ArkSimpleTimer m_noCollideTimer;
	int m_numBounces;
	int m_modelNum;
	unsigned m_grenadeId;
	bool m_bAmmoIsPooled;
	bool m_bCollideAI;
	bool m_bSpawnGoo;
	CArkProjectileGoo::ArkGooSpawnParameters m_spawnParameters;

	CArkProjectileGooBall();
	virtual ~CArkProjectileGooBall();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ReInitFromPool();
	virtual void LoadModel();
	virtual string GetModelFilename(const ArkSafeScriptTable& _propertiesTable);
	virtual void LoadCachedProperties();
	virtual void Physicalize(const string& _physicsType);
	virtual bool ShowHitDamageUI() const;

#if 0
	void SetGrenadeId(const unsigned _arg0_);
	unsigned GetGrenadeId() const;
	void SetNoCollideAI();
#endif

	static inline auto FCArkProjectileGooBallOv1 = PreyFunction<void(CArkProjectileGooBall* const _this)>(0x147DD80);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileGooBall* const _this, IGameObject* _pGameObject)>(0x147ED00);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGooBall* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x147EE60);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileGooBall* const _this, const SGameObjectEvent& _event)>(0x147E1F0);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileGooBall* const _this, TSerialize _ser)>(0x147DEC0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectileGooBall* const _this)>(0x147ED90);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileGooBall* const _this)>(0x147EDB0);
	static inline auto FLoadModel = PreyFunction<void(CArkProjectileGooBall* const _this)>(0x147EA10);
	static inline auto FGetModelFilename = PreyFunction<string*(CArkProjectileGooBall* const _this, string* _return_value_, const ArkSafeScriptTable& _propertiesTable)>(0x147E000);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileGooBall* const _this)>(0x147E6C0);
	static inline auto FPhysicalize = PreyFunction<void(CArkProjectileGooBall* const _this, const string& _physicsType)>(0x147EC50);
	static inline auto FShowHitDamageUI = PreyFunction<bool(const CArkProjectileGooBall* const _this)>(0x13B0900);
};
#endif // !MOONCRASH
