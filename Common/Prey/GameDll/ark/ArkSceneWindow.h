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

// Header: FromCpp
// Prey/GameDll/ark/ArkSceneWindow.h
class ArkSceneWindow : public CGameObjectExtensionHelper<ArkSceneWindow,IGameObjectExtension> // Id=8019544 Size=64
{
public:
	ArkSceneWindow();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
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
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	
	static inline auto FInit = PreyFunction<bool(ArkSceneWindow *const _this, IGameObject *_pGameObject)>(0x13CACC0);
	static inline auto FPostInit = PreyFunction<void(ArkSceneWindow *const _this, IGameObject *_pGameObject)>(0xA13080);
	static inline auto FInitClient = PreyFunction<void(ArkSceneWindow *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkSceneWindow *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkSceneWindow *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkSceneWindow *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkSceneWindow *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(ArkSceneWindow *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkSceneWindow *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(ArkSceneWindow *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkSceneWindow *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkSceneWindow *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkSceneWindow *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkSceneWindow *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkSceneWindow *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkSceneWindow *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(ArkSceneWindow *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkSceneWindow *const _this, bool _bAuth)>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(ArkSceneWindow *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkSceneWindow *const _this)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkSceneWindow const *const _this, ICrySizer *_pS)>(0x1187D80);
};

