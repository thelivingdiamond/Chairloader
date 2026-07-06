// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkSafeScriptTable;
class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/arkglassbreaker.h
class CArkGlassBreaker : public CGameObjectExtensionHelper<CArkGlassBreaker,IGameObjectExtension> // Id=8019350 Size=72
{
public:
	unsigned m_ownerId;
	
	CArkGlassBreaker();
	virtual ~CArkGlassBreaker();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
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
	virtual void SetAuthority(bool _auth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	void StartGlassBreaking(unsigned _ownerId, float _radius) { FStartGlassBreaking(this,_ownerId,_radius); }
	void Physicalize(float _radius) { FPhysicalize(this,_radius); }
	
#if 0
	ArkSafeScriptTable GetPropertiesTable() const;
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkGlassBreaker const *const _this, ICrySizer *_s)>(0x345AA0);
	static inline auto FInit = PreyFunction<bool(CArkGlassBreaker *const _this, IGameObject *_pGameObject)>(0x13CACC0);
	static inline auto FPostInit = PreyFunction<void(CArkGlassBreaker *const _this, IGameObject *_pGameObject)>(0xA13080);
	static inline auto FInitClient = PreyFunction<void(CArkGlassBreaker *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkGlassBreaker *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkGlassBreaker *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkGlassBreaker *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkGlassBreaker *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkGlassBreaker *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(CArkGlassBreaker *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CArkGlassBreaker *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkGlassBreaker *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkGlassBreaker *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkGlassBreaker *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkGlassBreaker *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkGlassBreaker *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkGlassBreaker *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(CArkGlassBreaker *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkGlassBreaker *const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkGlassBreaker const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkGlassBreaker *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkGlassBreaker *const _this)>(0xA13080);
	static inline auto FStartGlassBreaking = PreyFunction<void(CArkGlassBreaker *const _this, unsigned _ownerId, float _radius)>(0x117BD70);
	static inline auto FPhysicalize = PreyFunction<void(CArkGlassBreaker *const _this, float _radius)>(0x117BB60);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/CGameObjectExtensionHelper.h>

class ArkSafeScriptTable;
enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkGlassBreaker
// Header:  Prey/GameDll/ark/ArkGlassBreaker.h
class CArkGlassBreaker : public CGameObjectExtensionHelper<CArkGlassBreaker, IGameObjectExtension>
{ // Size=72 (0x48)
public:
	unsigned m_ownerId;

	CArkGlassBreaker();
	virtual ~CArkGlassBreaker();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	void StartGlassBreaking(unsigned _ownerId, float _radius) { FStartGlassBreaking(this, _ownerId, _radius); }
	void Physicalize(float _radius) { FPhysicalize(this, _radius); }

#if 0
	ArkSafeScriptTable GetPropertiesTable() const;
#endif

	static inline auto FCArkGlassBreakerOv1 = PreyFunction<void(CArkGlassBreaker* const _this)>(0x11F6E20);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkGlassBreaker* const _this, ICrySizer* _s)>(0x35A360);
	static inline auto FInit = PreyFunction<bool(CArkGlassBreaker* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FPostInit = PreyFunction<void(CArkGlassBreaker* const _this, IGameObject* _pGameObject)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkGlassBreaker* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkGlassBreaker* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkGlassBreaker* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkGlassBreaker* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkGlassBreaker* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkGlassBreaker* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkGlassBreaker* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkGlassBreaker* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(CArkGlassBreaker* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkGlassBreaker* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkGlassBreaker* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkGlassBreaker* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkGlassBreaker* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkGlassBreaker* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CArkGlassBreaker* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkGlassBreaker* const _this, bool _auth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkGlassBreaker* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkGlassBreaker* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkGlassBreaker* const _this)>(0x1333E90);
	static inline auto FStartGlassBreaking = PreyFunction<void(CArkGlassBreaker* const _this, unsigned _ownerId, float _radius)>(0x11F70C0);
	static inline auto FPhysicalize = PreyFunction<void(CArkGlassBreaker* const _this, float _radius)>(0x11F6EB0);
};
#endif // !MOONCRASH
