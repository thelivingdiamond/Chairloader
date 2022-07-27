// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct IGameObject;
struct IGameVolumes;
class ITexture;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/arkmapvolume.h
class ArkBitVector : public std::vector<bool> // Id=80167C2 Size=32
{
public:
	static const uint8_t k_bitsPerChar;
	
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
	static inline auto FSerialize = PreyFunction<void(ArkBitVector *const _this, TSerialize _ser)>(0x144AA60);
};

// Header: FromCpp
// Prey/GameDll/ark/arkmapvolume.h
class CArkVolume // Id=80167C3 Size=32
{
public:
	std::vector<Vec3> m_points;
	float m_height;
	
	CArkVolume();
	void SetVolume(Matrix34 const &_worldTM, IGameVolumes::VolumeInfo const &_volumeInfo) { FSetVolume(this,_worldTM,_volumeInfo); }
	~CArkVolume() { FBitNotCArkVolume(this); }
	
#if 0
	bool IsPointInside(Vec3 const &arg0) const;
	std::vector<Vec3> const &GetPoints() const;
	float GetHeight() const;
#endif
	
	static inline auto FSetVolume = PreyFunction<void(CArkVolume *const _this, Matrix34 const &_worldTM, IGameVolumes::VolumeInfo const &_volumeInfo)>(0x144ADD0);
	static inline auto FBitNotCArkVolume = PreyFunction<void(CArkVolume *const _this)>(0x1F09C0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkmapvolume.h
class CArkMapVolume : public CGameObjectExtensionHelper<CArkMapVolume,IGameObjectExtension> // Id=80167BF Size=176
{
public:
	string m_mapIdentifier;
	CArkVolume m_volume;
	ArkBitVector m_visited;
	AABB m_bounds;
	ITexture *m_pTexture;
	int m_floorIndex;
	bool m_bShowIcons;
	
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
	bool IsPointInside(Vec3 const &_point) const { return FIsPointInside(this,_point); }
	void SetVisited(const unsigned _cellIndex) { FSetVisited(this,_cellIndex); }
	void ResizeVisitedArea(const unsigned _size) { FResizeVisitedArea(this,_size); }
	void LoadVolumeData() { FLoadVolumeData(this); }
	void ResetVisitedArea() { FResetVisitedArea(this); }
	virtual ~CArkMapVolume();
	
#if 0
	AABB const &GetBounds() const;
	ITexture *GetTexture() const;
	ArkBitVector &GetVisited();
	ArkBitVector const &GetVisited() const;
	int GetFloorIndex() const;
	bool GetShowIcons() const;
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkMapVolume *const _this, IGameObject *_pGameObject)>(0x144A380);
	static inline auto FPostInit = PreyFunction<void(CArkMapVolume *const _this, IGameObject *_pGameObject)>(0xA13080);
	static inline auto FInitClient = PreyFunction<void(CArkMapVolume *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkMapVolume *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkMapVolume *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkMapVolume *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkMapVolume *const _this, TSerialize _signature)>(0x1B933B0);
	static inline auto FRelease = PreyFunction<void(CArkMapVolume *const _this)>(0x144A970);
	static inline auto FFullSerialize = PreyFunction<void(CArkMapVolume *const _this, TSerialize _ser)>(0x144A310);
	static inline auto FNetSerialize = PreyFunction<bool(CArkMapVolume *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkMapVolume *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkMapVolume *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkMapVolume *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkMapVolume *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkMapVolume *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkMapVolume *const _this, SEntityEvent &_event)>(0x144A920);
	static inline auto FSetChannelId = PreyFunction<void(CArkMapVolume *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkMapVolume *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkMapVolume const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkMapVolume *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkMapVolume *const _this)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkMapVolume const *const _this, ICrySizer *_pCrySizer)>(0xA13080);
	static inline auto FIsPointInside = PreyFunction<bool(CArkMapVolume const *const _this, Vec3 const &_point)>(0x144A3B0);
	static inline auto FSetVisited = PreyFunction<void(CArkMapVolume *const _this, const unsigned _cellIndex)>(0x144ADA0);
	static inline auto FResizeVisitedArea = PreyFunction<void(CArkMapVolume *const _this, const unsigned _size)>(0x144AA50);
	static inline auto FLoadVolumeData = PreyFunction<void(CArkMapVolume *const _this)>(0x144A410);
	static inline auto FResetVisitedArea = PreyFunction<void(CArkMapVolume *const _this)>(0x144A9A0);
};

