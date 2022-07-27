// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/INavigationSystem.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ai/ArkOffMeshLinkHelper.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class SmartScriptTable;

// Header: FromCpp
// Prey/GameDll/ark/arknavislandjumplink.h
class CArkNavIslandJumpLink : public CGameObjectExtensionHelper<CArkNavIslandJumpLink,IGameObjectExtension> // Id=801BF59 Size=208
{
public:
	using LinkPosition = std::tuple<Vec3,Vec3>;
	using Links = std::vector<std::tuple<Vec3,Vec3>>;
	
	enum class LinkError
	{
		None = 0,
		Invalid = 1,
		NoMesh = 2,
		NoIsland = 3,
		NoLinksFound = 4,
	};

	std::vector<std::tuple<Vec3,Vec3>> m_links;
	ArkOffMeshLinkHelper m_navLinksForward;
	ArkOffMeshLinkHelper m_navLinksReverse;
	CArkNavIslandJumpLink::LinkError m_linkStatus;
	Vec3 m_lastLinkPos;
	float m_updateEditorPosTimer;
	bool m_bRebuildLinks;
	
	CArkNavIslandJumpLink();
	virtual bool Init(IGameObject *_pGameObject);
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
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	void OnNavMeshChange() { FOnNavMeshChange(this); }
	void ClearLinks() { FClearLinks(this); }
	void RebuildLinks() { FRebuildLinks(this); }
	CArkNavIslandJumpLink::LinkError CalculateLinkPositions(TNavigationID<1> _navAgentID, std::vector<std::tuple<Vec3,Vec3>> &_links) const { return FCalculateLinkPositions(this,_navAgentID,_links); }
	int CheckLinkRow(TNavigationID<1> _navAgentID, Vec3 const &_start, Vec3 const &_fwdDir, float _fwdDist, Vec3 const &_linkDir, float _linkDist, unsigned _islandId, std::vector<std::tuple<Vec3,Vec3>> &_links, CArkNavIslandJumpLink::LinkError &_error) const { return FCheckLinkRow(this,_navAgentID,_start,_fwdDir,_fwdDist,_linkDir,_linkDist,_islandId,_links,_error); }
	int CheckLink(TNavigationID<1> _navAgentID, Vec3 const &_start, Vec3 const &_dir, float _dist, unsigned _islandId, std::vector<std::tuple<Vec3,Vec3>> &_links, CArkNavIslandJumpLink::LinkError &_error) const { return FCheckLink(this,_navAgentID,_start,_dir,_dist,_islandId,_links,_error); }
	int ValidateLink(TNavigationID<1> _navAgentID, Vec3 const &_startPos, Vec3 const &_dir, unsigned _islandStart, Vec3 const &_endPos, std::vector<std::tuple<Vec3,Vec3>> &_links, CArkNavIslandJumpLink::LinkError &_error) const { return FValidateLink(this,_navAgentID,_startPos,_dir,_islandStart,_endPos,_links,_error); }
	virtual ~CArkNavIslandJumpLink();
	
#if 0
	Vec3 GetTriggerSize() const;
	SmartScriptTable GetPropertiesTable() const;
	bool FindSurfacePos(Vec3 const &arg0, Vec3 &arg1) const;
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkNavIslandJumpLink *const _this, IGameObject *_pGameObject)>(0x1417E90);
	static inline auto FInitClient = PreyFunction<void(CArkNavIslandJumpLink *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(CArkNavIslandJumpLink *const _this, IGameObject *_pGameObject)>(0x13D6020);
	static inline auto FPostInitClient = PreyFunction<void(CArkNavIslandJumpLink *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNavIslandJumpLink *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNavIslandJumpLink *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNavIslandJumpLink *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkNavIslandJumpLink *const _this)>(0x1418840);
	static inline auto FFullSerialize = PreyFunction<void(CArkNavIslandJumpLink *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNavIslandJumpLink *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkNavIslandJumpLink *const _this)>(0x1417FB0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNavIslandJumpLink *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkNavIslandJumpLink *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkNavIslandJumpLink *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1418890);
	static inline auto FPostUpdate = PreyFunction<void(CArkNavIslandJumpLink *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNavIslandJumpLink *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkNavIslandJumpLink *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkNavIslandJumpLink *const _this, SEntityEvent &_event)>(0x1417FF0);
	static inline auto FSetChannelId = PreyFunction<void(CArkNavIslandJumpLink *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkNavIslandJumpLink *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkNavIslandJumpLink const *const _this, ICrySizer *_pS)>(0x34EBF0);
	static inline auto FOnNavMeshChange = PreyFunction<void(CArkNavIslandJumpLink *const _this)>(0x1417F80);
	static inline auto FClearLinks = PreyFunction<void(CArkNavIslandJumpLink *const _this)>(0x1417E00);
	static inline auto FRebuildLinks = PreyFunction<void(CArkNavIslandJumpLink *const _this)>(0x1418120);
	static inline auto FCalculateLinkPositions = PreyFunction<CArkNavIslandJumpLink::LinkError(CArkNavIslandJumpLink const *const _this, TNavigationID<1> _navAgentID, std::vector<std::tuple<Vec3,Vec3>> &_links)>(0x1416B30);
	static inline auto FCheckLinkRow = PreyFunction<int(CArkNavIslandJumpLink const *const _this, TNavigationID<1> _navAgentID, Vec3 const &_start, Vec3 const &_fwdDir, float _fwdDist, Vec3 const &_linkDir, float _linkDist, unsigned _islandId, std::vector<std::tuple<Vec3,Vec3>> &_links, CArkNavIslandJumpLink::LinkError &_error)>(0x1417B90);
	static inline auto FCheckLink = PreyFunction<int(CArkNavIslandJumpLink const *const _this, TNavigationID<1> _navAgentID, Vec3 const &_start, Vec3 const &_dir, float _dist, unsigned _islandId, std::vector<std::tuple<Vec3,Vec3>> &_links, CArkNavIslandJumpLink::LinkError &_error)>(0x1417990);
	static inline auto FValidateLink = PreyFunction<int(CArkNavIslandJumpLink const *const _this, TNavigationID<1> _navAgentID, Vec3 const &_startPos, Vec3 const &_dir, unsigned _islandStart, Vec3 const &_endPos, std::vector<std::tuple<Vec3,Vec3>> &_links, CArkNavIslandJumpLink::LinkError &_error)>(0x1418930);
};

