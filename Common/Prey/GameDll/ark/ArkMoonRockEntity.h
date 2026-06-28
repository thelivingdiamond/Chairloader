// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkMoonRockEntity
// Header:  Prey/GameDll/ark/ArkMoonRockEntity.h
class CArkMoonRockEntity : public CGameObjectExtensionHelper<CArkMoonRockEntity, IGameObjectExtension>
{ // Size=352 (0x160)
public:
	bool m_bRecentlyThrown;
	ArkEntityEffect m_spawnEffect;
	ArkEntityEffect m_throwLevitatedEffect;
	ArkAudioTrigger m_spawnTrigger;

	CArkMoonRockEntity();
	virtual ~CArkMoonRockEntity();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	void Spawn() { FSpawn(this); }
	void OnThrowLevitated() { FOnThrowLevitated(this); }
	void OnThrowDropped() { FOnThrowDropped(this); }
	void OnThrown() { FOnThrown(this); }
	void OnThrowCollision() { FOnThrowCollision(this); }
	void SetCarryBlocked(bool _bCarryBlocked) { FSetCarryBlocked(this, _bCarryBlocked); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }

#if 0
	void DisableCollisionListening();
	void EnableCollisionListening();
	void SetCollidable(bool _arg0_);
	bool IsBeingCarried() const;
	void ScaleRock();
#endif

	static inline auto FCArkMoonRockEntityOv1 = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B7CA0);
	static inline auto FInit = PreyFunction<bool(CArkMoonRockEntity* const _this, IGameObject* _pGameObject)>(0x11B7E90);
	static inline auto FUpdate = PreyFunction<void(CArkMoonRockEntity* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkMoonRockEntity* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkMoonRockEntity* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CArkMoonRockEntity* const _this, IGameObject* _pGameObject)>(0x11B8650);
	static inline auto FPostInitClient = PreyFunction<void(CArkMoonRockEntity* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkMoonRockEntity* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkMoonRockEntity* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkMoonRockEntity* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B8690);
	static inline auto FFullSerialize = PreyFunction<void(CArkMoonRockEntity* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkMoonRockEntity* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B8670);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkMoonRockEntity* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkMoonRockEntity* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FPostUpdate = PreyFunction<void(CArkMoonRockEntity* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkMoonRockEntity* const _this, const SGameObjectEvent& _event)>(0x11B7E80);
	static inline auto FSetChannelId = PreyFunction<void(CArkMoonRockEntity* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkMoonRockEntity* const _this, bool _bAuth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkMoonRockEntity* const _this, ICrySizer* _pS)>(0x11B7E50);
	static inline auto FSpawn = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B8790);
	static inline auto FOnThrowLevitated = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B8530);
	static inline auto FOnThrowDropped = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B84A0);
	static inline auto FOnThrown = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B85C0);
	static inline auto FOnThrowCollision = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B81F0);
	static inline auto FSetCarryBlocked = PreyFunction<void(CArkMoonRockEntity* const _this, bool _bCarryBlocked)>(0x11B86D0);
	static inline auto FLoadScriptVariables = PreyFunction<void(CArkMoonRockEntity* const _this)>(0x11B7ED0);
};
#endif // MOONCRASH
