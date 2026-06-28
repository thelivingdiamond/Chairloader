// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/CGameObjectExtensionHelper.h>
#include <_unknown/IArkRoomPortal.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkRoomPortal
// Header:  Prey/GameDll/ark/ArkRoomPortal.h
class CArkRoomPortal : public CGameObjectExtensionHelper<CArkRoomPortal, IGameObjectExtension>, public IArkRoomPortal
{ // Size=128 (0x80)
public:
	float m_occlusion;
	float m_hazardOcclusion;
	std::array<Vec3, 4> m_corners;

	CArkRoomPortal();
	virtual ~CArkRoomPortal();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* __unnamed1);
	virtual void InitClient(int _channelId);
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
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void GetMemoryUsage(ICrySizer* _pCrySizer) const;
	virtual void SetOcclusion(float _occlusion);
	virtual float GetOcclusion() const;
	virtual void SetHazardOcclusion(float _occlusion);
	virtual float GetHazardOcclusion() const;
	virtual const std::array<Vec3, 4>& GetCorners() const;
	virtual void SetCorners(const std::array<Vec3, 4>& _corners);
	virtual bool IsValid() const;
	virtual void SetExportable(bool _bExportable);
	virtual const char* GetName() const;

	static inline auto FCArkRoomPortalOv1 = PreyFunction<void(CArkRoomPortal* const _this)>(0x15885D0);
	static inline auto FInit = PreyFunction<bool(CArkRoomPortal* const _this, IGameObject* _pGameObject)>(0x15887C0);
	static inline auto FPostInit = PreyFunction<void(CArkRoomPortal* const _this, IGameObject* __unnamed1)>(0x15889D0);
	static inline auto FInitClient = PreyFunction<void(CArkRoomPortal* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkRoomPortal* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkRoomPortal* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkRoomPortal* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkRoomPortal* const _this, TSerialize _signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(CArkRoomPortal* const _this)>(0x1588B50);
	static inline auto FFullSerialize = PreyFunction<void(CArkRoomPortal* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkRoomPortal* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkRoomPortal* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkRoomPortal* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkRoomPortal* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkRoomPortal* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkRoomPortal* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkRoomPortal* const _this, SEntityEvent& _event)>(0x1588A70);
	static inline auto FSetChannelId = PreyFunction<void(CArkRoomPortal* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkRoomPortal* const _this, bool _bAuth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkRoomPortal* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkRoomPortal* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkRoomPortal* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkRoomPortal* const _this, ICrySizer* _pCrySizer)>(0x1333E90);
	static inline auto FSetOcclusion = PreyFunction<void(IArkRoomPortal* const _this, float _occlusion)>(0x1588E10);
	static inline auto FGetOcclusion = PreyFunction<float(const IArkRoomPortal* const _this)>(0x15887B0);
	static inline auto FSetHazardOcclusion = PreyFunction<void(IArkRoomPortal* const _this, float _occlusion)>(0x1588DC0);
	static inline auto FGetHazardOcclusion = PreyFunction<float(const IArkRoomPortal* const _this)>(0x138B7A0);
	static inline auto FGetCorners = PreyFunction<const std::array<Vec3, 4>& (const IArkRoomPortal* const _this)>(0x10ED260);
	static inline auto FSetCorners = PreyFunction<void(IArkRoomPortal* const _this, const std::array<Vec3, 4>& _corners)>(0x1588BF0);
	static inline auto FIsValid = PreyFunction<bool(const IArkRoomPortal* const _this)>(0x15889A0);
	static inline auto FSetExportable = PreyFunction<void(IArkRoomPortal* const _this, bool _bExportable)>(0x1588D80);
	static inline auto FGetName = PreyFunction<const char* (const IArkRoomPortal* const _this)>(0x1588790);
};
#endif // MOONCRASH
