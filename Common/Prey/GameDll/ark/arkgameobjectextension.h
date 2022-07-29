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
// Prey/GameDll/ark/arkgameobjectextension.h
template <typename T>
class CArkGameObjectExtension : public CGameObjectExtensionHelper<T, IGameObjectExtension> // Id=8015E89 Size=64
{
public:
	using BaseType = CGameObjectExtensionHelper<T, IGameObjectExtension>;
	
#if 0
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual bool Init(IGameObject *arg0);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
#endif
};

