// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkgameobjectextension.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/signalsystem/ArkBreakableSignalReceiver.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/arkbreakable.h
class CArkBreakable : public CArkGameObjectExtension<CArkBreakable> // Id=8019358 Size=376
{
public:
	ArkBreakableSignalReceiver m_signalReceiver;
	ArkAudioTrigger m_onDestroySoundTrigger;
	ArkFireAndForgetEffect m_destroyEffect;
	ArkEntityEffect m_damageEffect;
	ArkSimpleTimer m_damageEffectTimer;
	_smart_ptr<IMaterial> m_pDefaultMaterial;
	float m_health;
	AABB m_defaultAABB;
	AABB m_brokenAABB;
	bool m_bRegenerateNavMesh;
	bool m_bHasRegeneratedNavMesh;
	bool m_bHideToggled;
	
	virtual ~CArkBreakable();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual void Release();
	void LoadParameters() { FLoadParameters(this); }
	void SetHealth(const float _health) { FSetHealth(this,_health); }
	bool IsGloo() const { return FIsGloo(this); }
	void LoadDefault() { FLoadDefault(this); }
	void LoadBroken() { FLoadBroken(this); }
	void RegenerateNavMesh() { FRegenerateNavMesh(this); }
	
#if 0
	float GetHealth() const;
	bool AffectsNavMesh() const;
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkBreakable *const _this, IGameObject *_pGameObject)>(0x141EB30);
	static inline auto FPostInit = PreyFunction<void(CArkBreakable *const _this, IGameObject *_pGameObject)>(0x141FC20);
	static inline auto FProcessEvent = PreyFunction<void(CArkBreakable *const _this, SEntityEvent &_event)>(0x141FC30);
	static inline auto FUpdate = PreyFunction<void(CArkBreakable *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1420390);
	static inline auto FFullSerialize = PreyFunction<void(CArkBreakable *const _this, TSerialize _ser)>(0x141E790);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkBreakable const *const _this, ICrySizer *_pS)>(0x1704D80);
	static inline auto FRelease = PreyFunction<void(CArkBreakable *const _this)>(0x141FF30);
	static inline auto FLoadParameters = PreyFunction<void(CArkBreakable *const _this)>(0x141F470);
	static inline auto FSetHealth = PreyFunction<void(CArkBreakable *const _this, const float _health)>(0x141FF80);
	static inline auto FIsGloo = PreyFunction<bool(CArkBreakable const *const _this)>(0x141EB70);
	static inline auto FLoadDefault = PreyFunction<void(CArkBreakable *const _this)>(0x141F170);
	static inline auto FLoadBroken = PreyFunction<void(CArkBreakable *const _this)>(0x141ED40);
	static inline auto FRegenerateNavMesh = PreyFunction<void(CArkBreakable *const _this)>(0x141FD20);
};

