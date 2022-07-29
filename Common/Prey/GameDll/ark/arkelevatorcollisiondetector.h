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
// Prey/GameDll/ark/arkelevatorcollisiondetector.h
class CArkElevatorCollisionDetector : public CGameObjectExtensionHelper<CArkElevatorCollisionDetector,IGameObjectExtension> // Id=8018FFF Size=104
{
public:
	unsigned m_elevatorId;
	unsigned m_floorAreaId;
	uint64_t m_packageId;
	std::vector<unsigned int> m_floorAreaEntities;
	
	CArkElevatorCollisionDetector();
	virtual ~CArkElevatorCollisionDetector();
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
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
	void SetupLinkedEntities() { FSetupLinkedEntities(this); }
	void OnReset() { FOnReset(this); }
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkElevatorCollisionDetector const *const _this, ICrySizer *_pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(CArkElevatorCollisionDetector *const _this, IGameObject *_pGameObject)>(0x1158890);
	static inline auto FPostInit = PreyFunction<void(CArkElevatorCollisionDetector *const _this, IGameObject *_pGameObject)>(0x1158AC0);
	static inline auto FInitClient = PreyFunction<void(CArkElevatorCollisionDetector *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkElevatorCollisionDetector *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkElevatorCollisionDetector *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkElevatorCollisionDetector *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkElevatorCollisionDetector *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkElevatorCollisionDetector *const _this)>(0x1158C10);
	static inline auto FFullSerialize = PreyFunction<void(CArkElevatorCollisionDetector *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CArkElevatorCollisionDetector *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkElevatorCollisionDetector *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkElevatorCollisionDetector *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkElevatorCollisionDetector *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkElevatorCollisionDetector *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkElevatorCollisionDetector *const _this, SGameObjectEvent const &_event)>(0x1158560);
	static inline auto FProcessEvent = PreyFunction<void(CArkElevatorCollisionDetector *const _this, SEntityEvent &_event)>(0x1158B20);
	static inline auto FSetChannelId = PreyFunction<void(CArkElevatorCollisionDetector *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkElevatorCollisionDetector *const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkElevatorCollisionDetector const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkElevatorCollisionDetector *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkElevatorCollisionDetector *const _this)>(0xA13080);
	static inline auto FSetupLinkedEntities = PreyFunction<void(CArkElevatorCollisionDetector *const _this)>(0x1158C30);
	static inline auto FOnReset = PreyFunction<void(CArkElevatorCollisionDetector *const _this)>(0x11588C0);
};

