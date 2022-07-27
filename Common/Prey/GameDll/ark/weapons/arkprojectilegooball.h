// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMemory/StlDbgAlloc.h>
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

