// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkAudioEnvironment.h>
#include <Prey/GameDll/ark/iface/IArkRoomVolume.h>

struct IArea;
class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/arkroomvolume.h
class CArkRoomVolume : public CGameObjectExtensionHelper<CArkRoomVolume,IGameObjectExtension>, public IArkRoomVolume, public IAreaManagerEventListener // Id=801C077 Size=128
{
public:
	ArkAudioTrigger m_ambientTrigger;
	ArkAudioRtpc m_ambientRtpc;
	ArkAudioEnvironment m_environment;
	std::vector<Vec3> m_points;
	float m_height;
	
	CArkRoomVolume();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
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
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void GetMemoryUsage(ICrySizer *_pCrySizer) const;
	virtual bool IsPointInside(Vec3 const &_point) const;
	virtual void SetPoints(std::vector<Vec3> const &_points, float _height, bool _resetPoints);
	virtual void SetExportable(bool _bExported);
	virtual const char *GetName() const;
	virtual void OnAreaManagerEvent(EEntityEvent _event, unsigned _triggerEntityID, IArea *_pArea);
	void SetupAmbientSound() { FSetupAmbientSound(this); }
	
	static inline auto FInit = PreyFunction<bool(CArkRoomVolume *const _this, IGameObject *_pGameObject)>(0x1471910);
	static inline auto FPostInit = PreyFunction<void(CArkRoomVolume *const _this, IGameObject *_pGameObject)>(0xA13080);
	static inline auto FInitClient = PreyFunction<void(CArkRoomVolume *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkRoomVolume *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkRoomVolume *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkRoomVolume *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkRoomVolume *const _this, TSerialize _signature)>(0x1B933B0);
	static inline auto FRelease = PreyFunction<void(CArkRoomVolume *const _this)>(0x1471CC0);
	static inline auto FFullSerialize = PreyFunction<void(CArkRoomVolume *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CArkRoomVolume *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkRoomVolume *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkRoomVolume *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkRoomVolume *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkRoomVolume *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x14722E0);
	static inline auto FHandleEvent = PreyFunction<void(CArkRoomVolume *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkRoomVolume *const _this, SEntityEvent &_event)>(0x1471B90);
	static inline auto FSetChannelId = PreyFunction<void(CArkRoomVolume *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkRoomVolume *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkRoomVolume const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkRoomVolume *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkRoomVolume *const _this)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkRoomVolume const *const _this, ICrySizer *_pCrySizer)>(0xA13080);
	static inline auto FIsPointInside = PreyFunction<bool(CArkRoomVolume const *const _this, Vec3 const &_point)>(0x1471A20);
	static inline auto FSetPoints = PreyFunction<void(CArkRoomVolume *const _this, std::vector<Vec3> const &_points, float _height, bool _resetPoints)>(0x1471DA0);
	static inline auto FSetExportable = PreyFunction<void(CArkRoomVolume *const _this, bool _bExported)>(0x1471D60);
	static inline auto FGetName = PreyFunction<const char *(CArkRoomVolume const *const _this)>(0x14718F0);
	static inline auto FOnAreaManagerEvent = PreyFunction<void(CArkRoomVolume *const _this, EEntityEvent _event, unsigned _triggerEntityID, IArea *_pArea)>(0x1471A80);
	static inline auto FSetupAmbientSound = PreyFunction<void(CArkRoomVolume *const _this)>(0x1471EC0);
};

