// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkgameobjectextension.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/ArkRepairableObject.h
class ArkRepairableObject : public CArkGameObjectExtension<ArkRepairableObject>, public IArkRepairableListener // Id=801A8E0 Size=368
{
public:
	ArkRepairable m_repairable;
	ArkRandomizedAutoResetTimer m_timerVFX;
	bool m_bUpdating;
	string m_model;
	string m_modelBroken;
	string m_displayName;
	ArkAudioTrigger m_triggerBreak;
	ArkAudioTrigger m_triggerBrokenLoop;
	ArkAudioTrigger m_triggerRepaired;
	ArkFireAndForgetEffect m_brokenVfx;
	float m_VFXScale;
	Vec3 m_VFXOffset;
	
	ArkRepairableObject();
	virtual ~ArkRepairableObject();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	void LoadProperties() { FLoadProperties(this); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	void PlayVFX() { FPlayVFX(this); }
	
#if 0
	void OnReset(bool arg0);
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkRepairableObject *const _this, IGameObject *_pGameObject)>(0x1257600);
	static inline auto FPostInit = PreyFunction<void(ArkRepairableObject *const _this, IGameObject *_pGameObject)>(0x1258390);
	static inline auto FRelease = PreyFunction<void(ArkRepairableObject *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkRepairableObject *const _this, TSerialize _ser)>(0x1257510);
	static inline auto FPostSerialize = PreyFunction<void(ArkRepairableObject *const _this)>(0x12583C0);
	static inline auto FUpdate = PreyFunction<void(ArkRepairableObject *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1258490);
	static inline auto FProcessEvent = PreyFunction<void(ArkRepairableObject *const _this, SEntityEvent &_event)>(0x12583D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkRepairableObject const *const _this, ICrySizer *_s)>(0x12575D0);
	static inline auto FLoadProperties = PreyFunction<void(ArkRepairableObject *const _this)>(0x1257640);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkRepairableObject *const _this, bool _bBroken, bool _bWasForced)>(0x1257F50);
	static inline auto FPlayVFX = PreyFunction<void(ArkRepairableObject *const _this)>(0x1258110);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <_unknown/CArkGameObjectExtension.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// ArkRepairableObject
// Header:  Prey/GameDll/ark/ArkRepairableObject.h
class ArkRepairableObject : public CArkGameObjectExtension<ArkRepairableObject>, public IArkRepairableListener
{ // Size=368 (0x170)
public:
	ArkRepairable m_repairable;
	ArkRandomizedAutoResetTimer m_timerVFX;
	bool m_bUpdating;
	string m_model;
	string m_modelBroken;
	string m_displayName;
	ArkAudioTrigger m_triggerBreak;
	ArkAudioTrigger m_triggerBrokenLoop;
	ArkAudioTrigger m_triggerRepaired;
	ArkFireAndForgetEffect m_brokenVfx;
	float m_VFXScale;
	Vec3 m_VFXOffset;

	ArkRepairableObject();
	virtual ~ArkRepairableObject();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	void LoadProperties() { FLoadProperties(this); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	void PlayVFX() { FPlayVFX(this); }

#if 0
	void OnReset(bool _arg0_);
#endif

	static inline auto FArkRepairableObjectOv1 = PreyFunction<void(ArkRepairableObject* const _this)>(0x12FB460);
	static inline auto FInit = PreyFunction<bool(ArkRepairableObject* const _this, IGameObject* _pGameObject)>(0x12FB770);
	static inline auto FPostInit = PreyFunction<void(ArkRepairableObject* const _this, IGameObject* _pGameObject)>(0x12FC500);
	static inline auto FRelease = PreyFunction<void(ArkRepairableObject* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkRepairableObject* const _this, TSerialize _ser)>(0x12FB680);
	static inline auto FPostSerialize = PreyFunction<void(ArkRepairableObject* const _this)>(0x12FC530);
	static inline auto FUpdate = PreyFunction<void(ArkRepairableObject* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x12FC600);
	static inline auto FProcessEvent = PreyFunction<void(ArkRepairableObject* const _this, SEntityEvent& _event)>(0x12FC540);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkRepairableObject* const _this, ICrySizer* _s)>(0x12FB740);
	static inline auto FLoadProperties = PreyFunction<void(ArkRepairableObject* const _this)>(0x12FB7B0);
	static inline auto FOnBrokenChanged = PreyFunction<void(IArkRepairableListener* const _this, bool _bBroken, bool _bWasForced)>(0x12FC0C0);
	static inline auto FPlayVFX = PreyFunction<void(ArkRepairableObject* const _this)>(0x12FC280);
};
#endif // !MOONCRASH
