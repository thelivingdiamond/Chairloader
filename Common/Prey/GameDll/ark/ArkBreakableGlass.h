// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/ArkBreakableGlass.h
class ArkBreakableGlass : public CGameObjectExtensionHelper<ArkBreakableGlass,IGameObjectExtension> // Id=8018FC7 Size=64
{
public:
	virtual void Release();
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual ~ArkBreakableGlass();
	
#if 0
	void SetPortalsOcclusion(const float arg0) const;
#endif
	
	static inline auto FRelease = PreyFunction<void(ArkBreakableGlass *const _this)>(0xA97D40);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkBreakableGlass const *const _this, ICrySizer *_pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(ArkBreakableGlass *const _this, IGameObject *_pGameObject)>(0x114C2C0);
	static inline auto FPostInit = PreyFunction<void(ArkBreakableGlass *const _this, IGameObject *_pGameObject)>(0x170BA10);
	static inline auto FInitClient = PreyFunction<void(ArkBreakableGlass *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkBreakableGlass *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkBreakableGlass *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkBreakableGlass *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkBreakableGlass *const _this, TSerialize _signature)>(0x1B933B0);
	static inline auto FFullSerialize = PreyFunction<void(ArkBreakableGlass *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(ArkBreakableGlass *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkBreakableGlass *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkBreakableGlass *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkBreakableGlass *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkBreakableGlass *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkBreakableGlass *const _this, SGameObjectEvent const &_event)>(0x114C1F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkBreakableGlass *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(ArkBreakableGlass *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkBreakableGlass *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(ArkBreakableGlass const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(ArkBreakableGlass *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkBreakableGlass *const _this)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/CGameObjectExtensionHelper.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkBreakableGlass
// Header:  Prey/GameDll/ark/ArkBreakableGlass.h
class ArkBreakableGlass : public CGameObjectExtensionHelper<ArkBreakableGlass, IGameObjectExtension>
{ // Size=64 (0x40)
public:
	virtual void Release();
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();

#if 0
	void SetPortalsOcclusion(const float _arg0_) const;
#endif

	static inline auto FRelease = PreyFunction<void(ArkBreakableGlass* const _this)>(0x3E3960);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkBreakableGlass* const _this, ICrySizer* _pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(ArkBreakableGlass* const _this, IGameObject* _pGameObject)>(0x11933E0);
	static inline auto FPostInit = PreyFunction<void(ArkBreakableGlass* const _this, IGameObject* _pGameObject)>(0x1832310);
	static inline auto FInitClient = PreyFunction<void(ArkBreakableGlass* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(ArkBreakableGlass* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkBreakableGlass* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkBreakableGlass* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkBreakableGlass* const _this, TSerialize _signature)>(0x1A302A0);
	static inline auto FFullSerialize = PreyFunction<void(ArkBreakableGlass* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(ArkBreakableGlass* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkBreakableGlass* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkBreakableGlass* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkBreakableGlass* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkBreakableGlass* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkBreakableGlass* const _this, const SGameObjectEvent& _event)>(0x1193310);
	static inline auto FProcessEvent = PreyFunction<void(ArkBreakableGlass* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(ArkBreakableGlass* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkBreakableGlass* const _this, bool _bAuth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const ArkBreakableGlass* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(ArkBreakableGlass* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkBreakableGlass* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
