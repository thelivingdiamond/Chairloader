// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/ArkGameObjectExtension.h>
#include <Prey/GameDll/ark/ArkOverlappingGooHandler.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/weapons/IArkOverlappingGooListener.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/arkanglerotationcomponent.h
class CArkAngleRotationComponent : public CArkGameObjectExtension<CArkAngleRotationComponent>, public IArkDisruptableListener, public IArkOverlappingGooListener // Id=8018FB8 Size=352
{
public:
	bool m_isActive;
	bool m_isPaused;
	bool m_useWorld;
	float m_lastTime;
	Vec3 m_speed;
	Quat m_worldRotation;
	Quat m_localRotation;
	uint64_t m_packageId;
	ArkOverlappingGooHandler m_gooHandler;
	ArkDisruptable m_disruptable;
	ArkDisruptableSignalReceiver m_disruptableSignalReceiver;
	
	CArkAngleRotationComponent();
	void SetActive(bool _isActive) { FSetActive(this,_isActive); }
	void SetRotation(Vec3 const &_degreesPerSecond, bool _useWorld) { FSetRotation(this,_degreesPerSecond,_useWorld); }
	virtual void Update(SEntityUpdateContext &_ctx, int __formal);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void PostInit(IGameObject *_gameObject);
	virtual bool ReloadExtension(IGameObject *_gameObject, SEntitySpawnParams const &__formal);
	virtual void PostReloadExtension(IGameObject *__formal, SEntitySpawnParams const &__formal);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual void OnGooStatusChanged(bool _bHasGoo);
	void SetGooParameters(const bool _bBreaksGoo, const bool _bReactivateWhenGooRemoved) { FSetGooParameters(this,_bBreaksGoo,_bReactivateWhenGooRemoved); }
	void Reset() { FReset(this); }
	
	static inline auto FSetActive = PreyFunction<void(CArkAngleRotationComponent *const _this, bool _isActive)>(0x114A2F0);
	static inline auto FSetRotation = PreyFunction<void(CArkAngleRotationComponent *const _this, Vec3 const &_degreesPerSecond, bool _useWorld)>(0x114A340);
	static inline auto FUpdate = PreyFunction<void(CArkAngleRotationComponent *const _this, SEntityUpdateContext &_ctx, int __formal)>(0x114A390);
	static inline auto FProcessEvent = PreyFunction<void(CArkAngleRotationComponent *const _this, SEntityEvent &_event)>(0x1149DC0);
	static inline auto FPostInit = PreyFunction<void(CArkAngleRotationComponent *const _this, IGameObject *_gameObject)>(0x1149D20);
	static inline auto FReloadExtension = PreyFunction<bool(CArkAngleRotationComponent *const _this, IGameObject *_gameObject, SEntitySpawnParams const &__formal)>(0x13CACC0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkAngleRotationComponent *const _this, IGameObject *__formal, SEntitySpawnParams const &__formal)>(0x1149DA0);
	static inline auto FRelease = PreyFunction<void(CArkAngleRotationComponent *const _this)>(0x1149E00);
	static inline auto FFullSerialize = PreyFunction<void(CArkAngleRotationComponent *const _this, TSerialize _ser)>(0x1149790);
	static inline auto FPostSerialize = PreyFunction<void(CArkAngleRotationComponent *const _this)>(0x1149DB0);
	static inline auto FHandleEvent = PreyFunction<void(CArkAngleRotationComponent *const _this, SGameObjectEvent const &_event)>(0x11499E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkAngleRotationComponent const *const _this, ICrySizer *_pS)>(0x11498F0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(CArkAngleRotationComponent *const _this, bool _bDisrupted, bool _bWasForced)>(0x1149CC0);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(CArkAngleRotationComponent const *const _this)>(0x1187DB0);
	static inline auto FOnGooStatusChanged = PreyFunction<void(CArkAngleRotationComponent *const _this, bool _bHasGoo)>(0x1149CF0);
	static inline auto FSetGooParameters = PreyFunction<void(CArkAngleRotationComponent *const _this, const bool _bBreaksGoo, const bool _bReactivateWhenGooRemoved)>(0x114A330);
	static inline auto FReset = PreyFunction<void(CArkAngleRotationComponent *const _this)>(0x1149EA0);
};

