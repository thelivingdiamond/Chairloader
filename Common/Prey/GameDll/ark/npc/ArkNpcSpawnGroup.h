// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkNpcSpawnGroup
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnGroup.h
class CArkNpcSpawnGroup : public CGameObjectExtensionHelper<CArkNpcSpawnGroup, IGameObjectExtension>
{ // Size=64 (0x40)
public:
	CArkNpcSpawnGroup();
	virtual ~CArkNpcSpawnGroup();
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _rParams);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _rParams);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _rCtx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	void SetManagedByEncounter(const string& profile_name, const string& encounter_name) { FSetManagedByEncounter(this, profile_name, encounter_name); }
	int RequestSpawnAtLinkedSpawners() { return FRequestSpawnAtLinkedSpawners(this); }

#if 0
	void ProcessResetEvent(SEntityEvent& _arg0_);
	void ProcessScriptEvent(SEntityEvent& _arg0_);
	void ProcessSpawnScriptEvent(SEntityEvent& _arg0_);
	void ProcessStartGameEvent(SEntityEvent& _arg0_);
#endif

	static inline auto FCArkNpcSpawnGroupOv1 = PreyFunction<void(CArkNpcSpawnGroup* const _this)>(0x1485BB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkNpcSpawnGroup* const _this, ICrySizer* _pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CArkNpcSpawnGroup* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FPostInit = PreyFunction<void(CArkNpcSpawnGroup* const _this, IGameObject* _pGameObject)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkNpcSpawnGroup* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkNpcSpawnGroup* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNpcSpawnGroup* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNpcSpawnGroup* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNpcSpawnGroup* const _this, TSerialize _signature)>(0x1485D70);
	static inline auto FRelease = PreyFunction<void(CArkNpcSpawnGroup* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkNpcSpawnGroup* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNpcSpawnGroup* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkNpcSpawnGroup* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNpcSpawnGroup* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkNpcSpawnGroup* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkNpcSpawnGroup* const _this, SEntityUpdateContext& _rCtx, int _updateSlot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkNpcSpawnGroup* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkNpcSpawnGroup* const _this, SEntityEvent& _event)>(0x1485DB0);
	static inline auto FSetChannelId = PreyFunction<void(CArkNpcSpawnGroup* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkNpcSpawnGroup* const _this, bool _auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CArkNpcSpawnGroup* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNpcSpawnGroup* const _this)>(0x1333E90);
	static inline auto FSetManagedByEncounter = PreyFunction<void(CArkNpcSpawnGroup* const _this, const string& profile_name, const string& encounter_name)>(0x1485FD0);
	static inline auto FRequestSpawnAtLinkedSpawners = PreyFunction<int(CArkNpcSpawnGroup* const _this)>(0x1485EC0);
};
#endif // MOONCRASH
