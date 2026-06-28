// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ai/ArkOffMeshLinkHelper.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkNavLowGJumpLink
// Header:  Prey/GameDll/ark/ArkNavLowGJumpLink.h
class CArkNavLowGJumpLink : public CGameObjectExtensionHelper<CArkNavLowGJumpLink, IGameObjectExtension>
{ // Size=256 (0x100)
public:
	using LinkPosition = std::tuple<Vec3_tpl<float>,Vec3_tpl<float> >;
	using Links = std::vector<std::tuple<Vec3_tpl<float>, Vec3_tpl<float>>>;

	std::vector<std::tuple<Vec3_tpl<float>, Vec3_tpl<float>>> m_links;
	ArkOffMeshLinkHelper m_navLinksForward;
	ArkOffMeshLinkHelper m_navLinksReverse;
	ENavLinkError m_linkStatus;
	Vec3 m_linkDir;
	Matrix34 m_lastLinkTM;
	float m_updateEditorPosTimer;
	bool m_bRebuildLinks;

	CArkNavLowGJumpLink();
	virtual bool Init(IGameObject* _pGameObject);
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
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	void OnNavMeshChange() { FOnNavMeshChange(this); }
	void ClearLinks() { FClearLinks(this); }
	void RebuildLinks() { FRebuildLinks(this); }

#if 0
	void InitProperties();
#endif

	static inline auto FCArkNavLowGJumpLinkOv2 = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x121E6D0);
	static inline auto FInit = PreyFunction<bool(CArkNavLowGJumpLink* const _this, IGameObject* _pGameObject)>(0x152DF50);
	static inline auto FInitClient = PreyFunction<void(CArkNavLowGJumpLink* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CArkNavLowGJumpLink* const _this, IGameObject* _pGameObject)>(0x152E070);
	static inline auto FPostInitClient = PreyFunction<void(CArkNavLowGJumpLink* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNavLowGJumpLink* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNavLowGJumpLink* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNavLowGJumpLink* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x121F260);
	static inline auto FFullSerialize = PreyFunction<void(CArkNavLowGJumpLink* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNavLowGJumpLink* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x121E950);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNavLowGJumpLink* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkNavLowGJumpLink* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkNavLowGJumpLink* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x121F2B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkNavLowGJumpLink* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkNavLowGJumpLink* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkNavLowGJumpLink* const _this, SEntityEvent& _event)>(0x121E990);
	static inline auto FSetChannelId = PreyFunction<void(CArkNavLowGJumpLink* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkNavLowGJumpLink* const _this, bool _bAuth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkNavLowGJumpLink* const _this, ICrySizer* _pS)>(0x1918B40);
	static inline auto FOnNavMeshChange = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x121E920);
	static inline auto FClearLinks = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x121E890);
	static inline auto FRebuildLinks = PreyFunction<void(CArkNavLowGJumpLink* const _this)>(0x121EBC0);
};
#endif // MOONCRASH
