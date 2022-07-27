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
// Prey/GameDll/ark/ArkApexVolume.h
class ArkApexVolume : public CGameObjectExtensionHelper<ArkApexVolume,IGameObjectExtension> // Id=8018FBC Size=64
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
	virtual void SetAuthority(bool _auth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	void CreateArea() const { FCreateArea(this); }
	
	static inline auto FRelease = PreyFunction<void(ArkApexVolume *const _this)>(0xA97D40);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkApexVolume const *const _this, ICrySizer *_pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(ArkApexVolume *const _this, IGameObject *_pGameObject)>(0x1704E80);
	static inline auto FPostInit = PreyFunction<void(ArkApexVolume *const _this, IGameObject *_pGameObject)>(0xA13080);
	static inline auto FInitClient = PreyFunction<void(ArkApexVolume *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkApexVolume *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkApexVolume *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0x360660);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkApexVolume *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkApexVolume *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FFullSerialize = PreyFunction<void(ArkApexVolume *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(ArkApexVolume *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkApexVolume *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkApexVolume *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkApexVolume *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkApexVolume *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkApexVolume *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkApexVolume *const _this, SEntityEvent &_event)>(0x114B3A0);
	static inline auto FSetChannelId = PreyFunction<void(ArkApexVolume *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkApexVolume *const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(ArkApexVolume const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(ArkApexVolume *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkApexVolume *const _this)>(0xA13080);
	static inline auto FCreateArea = PreyFunction<void(ArkApexVolume const *const _this)>(0x114B1B0);
};

