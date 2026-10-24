// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMovie/IMovieSystem.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/CryMovie/ITrackEventListener.h>
#include <Prey/CryMath/Range.h>
#include <Prey/CryCore/Containers/VectorSet.h>

enum EAnimNodeType;
struct IAnimNode;
struct IAnimSequenceOwner;
struct IAnimStringTable;
class IArkConversation;
class IArkSpeaker;
class ICrySizer;
struct IEntity;
struct IMovieSystem;
struct ITrackEventListener;
struct SAnimContext;
class XmlNodeRef;

// CAnimSequence
// Header:  CryEngine/crymovie/AnimSequence.h
// Include: Prey/CryMovie/AnimSequence.h
class CAnimSequence : public IAnimSequence, public IArkConversationListener
{ // Size=248 (0xF8)
public:
	using AnimNodes = std::vector<_smart_ptr<IAnimNode>>;
	using TTrackEventListeners = std::list<ITrackEventListener *,std::allocator<ITrackEventListener *> >;

	std::vector<_smart_ptr<IAnimNode>> m_nodes;
	std::vector<_smart_ptr<IAnimNode>> m_nodesNeedToRender;
	unsigned m_id;
	string m_name;
	string m_fullNameHolder;
	TRange<float> m_timeRange;
	std::vector<string> m_events;
	_smart_ptr<IAnimStringTable> m_pEventStrings;
	std::list<ITrackEventListener *,std::allocator<ITrackEventListener *> > m_listeners;
	int m_flags;
	bool m_precached;
	bool m_bResetting;
	bool m_bIsStopping;
	IAnimSequence* m_pParentSequence;
	IMovieSystem* m_pMovieSystem;
	bool m_bPaused;
	bool m_bActive;
	unsigned m_lastGenId;
	IAnimSequenceOwner* m_pOwner;
	IAnimNode* m_pActiveDirector;
	float m_time;
	float m_fixedTimeStep;
	VectorSet<IEntity *,std::less<IEntity *>,std::allocator<IEntity *> > m_precachedEntitiesSet;
	uint64_t m_conversationId;
	IArkConversation* m_pCurrentConversation;

	CAnimSequence(IMovieSystem* pMovieSystem, unsigned id);
	virtual void Release();
	virtual void SetName(const char* name);
	virtual const char* GetName() const;
	virtual unsigned GetId() const;
	virtual float GetFixedTimeStep() const;
	virtual void SetFixedTimeStep(float dt);
	virtual void SetOwner(IAnimSequenceOwner* pOwner);
	virtual IAnimSequenceOwner* GetOwner() const;
	virtual void SetActiveDirector(IAnimNode* pDirectorNode);
	virtual IAnimNode* GetActiveDirector() const;
	virtual void SetFlags(int flags);
	virtual int GetFlags() const;
	virtual int GetCutSceneFlags(const bool localFlags) const;
	virtual void SetParentSequence(IAnimSequence* pParentSequence);
	virtual const IAnimSequence* GetParentSequence() const;
	virtual bool IsAncestorOf(const IAnimSequence* pSequence) const;
	virtual void SetTimeRange(TRange<float> timeRange);
	virtual TRange<float> GetTimeRange();
	virtual void AdjustKeysToTimeRange(const TRange<float>& timeRange);
	virtual int GetNodeCount() const;
	virtual IAnimNode* GetNode(int index) const;
	virtual IAnimNode* FindNodeByName(const char* sNodeName, const IAnimNode* pParentDirector);
	IAnimNode* FindNodeById(int nNodeId) { return FFindNodeById(this, nNodeId); }
	virtual void ReorderNode(IAnimNode* pNode, IAnimNode* pPivotNode, bool bNext);
	virtual void Reset(bool bSeekToStart);
	virtual void ResetHard();
	virtual void Pause();
	virtual void Resume();
	virtual bool IsPaused() const;
	virtual void OnStart();
	virtual void OnStop(bool _bAbort);
	virtual bool AddNode(IAnimNode* pAnimNode);
	virtual IAnimNode* CreateNode(EAnimNodeType nodeType);
	virtual IAnimNode* CreateNode(XmlNodeRef node);
	virtual void RemoveNode(IAnimNode* node);
	virtual void RemoveAll();
	virtual void Activate();
	virtual bool IsActivated() const;
	virtual void Deactivate();
	virtual void SetIsStopping(bool _bStopping);
	virtual bool IsStopping() const;
	virtual void PrecacheData(float startTime);
	void PrecacheStatic(const float startTime) { FPrecacheStatic(this, startTime); }
	void PrecacheDynamic(float time) { FPrecacheDynamic(this, time); }
	void PrecacheEntity(IEntity* pEntity) { FPrecacheEntity(this, pEntity); }
	virtual void StillUpdate();
	virtual void Animate(const SAnimContext& ec);
	virtual void Render();
	virtual void Serialize(XmlNodeRef& xmlNode, bool bLoading, bool bLoadEmptyTracks, unsigned overrideId, bool bResetLightAnimSet);
	virtual void CopyNodes(XmlNodeRef& xmlNode, IAnimNode* * pSelectedNodes, unsigned count);
	virtual void PasteNodes(const XmlNodeRef& xmlNode, IAnimNode* pParent);
	virtual bool AddTrackEvent(const char* szEvent);
	virtual bool RemoveTrackEvent(const char* szEvent);
	virtual bool RenameTrackEvent(const char* szEvent, const char* szNewEvent);
	virtual bool MoveUpTrackEvent(const char* szEvent);
	virtual bool MoveDownTrackEvent(const char* szEvent);
	virtual void ClearTrackEvents();
	virtual int GetTrackEventsCount() const;
	virtual const char* GetTrackEvent(int iIndex) const;
	virtual IAnimStringTable* GetTrackEventStringTable();
	virtual void TriggerTrackEvent(const char* event, const char* param);
	virtual void AddTrackEventListener(ITrackEventListener* pListener);
	virtual void RemoveTrackEventListener(ITrackEventListener* pListener);
	virtual uint64_t GetArkConversation() const;
	virtual void SetArkConversation(const uint64_t _conversationId);
	virtual IArkConversation* CreateOrAddToCurrentConversation(IArkSpeaker* _pSpeaker);
	virtual void EndConversation(bool _bComplete);
	virtual const IArkConversation* GetCurrentConversation();
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void MoveAbsolutePositions(const Vec3& offset);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	void CopyNodeChildren(XmlNodeRef& xmlNode, IAnimNode* pAnimNode) { FCopyNodeChildren(this, xmlNode, pAnimNode); }
	void NotifyTrackEvent(ITrackEventListener::ETrackEventReason reason, const char* event, const char* param) { FNotifyTrackEvent(this, reason, event, param); }
	IAnimNode* CreateNodeInternal(EAnimNodeType nodeType, unsigned nNodeId) { return FCreateNodeInternal(this, nodeType, nNodeId); }

#if 0
	IMovieSystem* GetMovieSystem() const;
	float GetTime() const;
	void ComputeTimeRange();
	bool AddNodeNeedToRender(IAnimNode* _arg0_);
	void RemoveNodeNeedToRender(IAnimNode* _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FCAnimSequenceOv2 = PreyFunction<void(CAnimSequence* const _this, IMovieSystem* pMovieSystem, unsigned id)>(0x9DE2E0);
	static inline auto FRelease = PreyFunction<void(CAnimSequence* const _this)>(0x49DB00);
	static inline auto FSetName = PreyFunction<void(CAnimSequence* const _this, const char* name)>(0x9E1630);
	static inline auto FGetName = PreyFunction<const char* (const CAnimSequence* const _this)>(0x9DFAA0);
	static inline auto FGetId = PreyFunction<unsigned(const CAnimSequence* const _this)>(0xA38760);
	static inline auto FGetFixedTimeStep = PreyFunction<float(const CAnimSequence* const _this)>(0x9DF8B0);
	static inline auto FSetFixedTimeStep = PreyFunction<void(CAnimSequence* const _this, float dt)>(0x1804780);
	static inline auto FSetOwner = PreyFunction<void(CAnimSequence* const _this, IAnimSequenceOwner* pOwner)>(0x9E1750);
	static inline auto FGetOwner = PreyFunction<IAnimSequenceOwner* (const CAnimSequence* const _this)>(0x155AD10);
	static inline auto FSetActiveDirector = PreyFunction<void(CAnimSequence* const _this, IAnimNode* pDirectorNode)>(0x9E15D0);
	static inline auto FGetActiveDirector = PreyFunction<IAnimNode* (const CAnimSequence* const _this)>(0x12C8A0);
	static inline auto FSetFlags = PreyFunction<void(CAnimSequence* const _this, int flags)>(0x155F490);
	static inline auto FGetFlags = PreyFunction<int(const CAnimSequence* const _this)>(0xF43E0);
	static inline auto FGetCutSceneFlags = PreyFunction<int(const CAnimSequence* const _this, const bool localFlags)>(0x9DF860);
	static inline auto FSetParentSequence = PreyFunction<void(CAnimSequence* const _this, IAnimSequence* pParentSequence)>(0x9E1760);
	static inline auto FGetParentSequence = PreyFunction<const IAnimSequence* (const CAnimSequence* const _this)>(0x9DFAE0);
	static inline auto FIsAncestorOf = PreyFunction<bool(const CAnimSequence* const _this, const IAnimSequence* pSequence)>(0x9DFB70);
	static inline auto FSetTimeRange = PreyFunction<void(CAnimSequence* const _this, TRange<float> timeRange)>(0x9E1770);
	static inline auto FGetTimeRange = PreyFunction<TRange<float>*(CAnimSequence* const _this, TRange<float>* _return_value_)>(0x9DFAF0);
	static inline auto FAdjustKeysToTimeRange = PreyFunction<void(CAnimSequence* const _this, const TRange<float>& timeRange)>(0x9DEB60);
	static inline auto FGetNodeCount = PreyFunction<int(const CAnimSequence* const _this)>(0x1143FF0);
	static inline auto FGetNode = PreyFunction<IAnimNode* (const CAnimSequence* const _this, int index)>(0x9DFAB0);
	static inline auto FFindNodeByName = PreyFunction<IAnimNode* (CAnimSequence* const _this, const char* sNodeName, const IAnimNode* pParentDirector)>(0x9DF7D0);
	static inline auto FFindNodeById = PreyFunction<IAnimNode* (CAnimSequence* const _this, int nNodeId)>(0x9DF7A0);
	static inline auto FReorderNode = PreyFunction<void(CAnimSequence* const _this, IAnimNode* pNode, IAnimNode* pPivotNode, bool bNext)>(0x9E0C20);
	static inline auto FReset = PreyFunction<void(CAnimSequence* const _this, bool bSeekToStart)>(0x9E0D90);
	static inline auto FResetHard = PreyFunction<void(CAnimSequence* const _this)>(0x9E0EA0);
	static inline auto FPause = PreyFunction<void(CAnimSequence* const _this)>(0x9E0350);
	static inline auto FResume = PreyFunction<void(CAnimSequence* const _this)>(0x9E0F70);
	static inline auto FIsPaused = PreyFunction<bool(const CAnimSequence* const _this)>(0x9DFD20);
	static inline auto FOnStart = PreyFunction<void(CAnimSequence* const _this)>(0x9E0010);
	static inline auto FOnStop = PreyFunction<void(CAnimSequence* const _this, bool _bAbort)>(0x9E0060);
	static inline auto FAddNode = PreyFunction<bool(CAnimSequence* const _this, IAnimNode* pAnimNode)>(0x9DE800);
	static inline auto FCreateNodeOv1 = PreyFunction<IAnimNode* (CAnimSequence* const _this, EAnimNodeType nodeType)>(0x9DF120);
	static inline auto FCreateNodeOv0 = PreyFunction<IAnimNode* (CAnimSequence* const _this, XmlNodeRef node)>(0x9DEFE0);
	static inline auto FRemoveNode = PreyFunction<void(CAnimSequence* const _this, IAnimNode* node)>(0x9E0780);
	static inline auto FRemoveAll = PreyFunction<void(CAnimSequence* const _this)>(0x9E0710);
	static inline auto FActivate = PreyFunction<void(CAnimSequence* const _this)>(0x9DE7B0);
	static inline auto FIsActivated = PreyFunction<bool(const CAnimSequence* const _this)>(0x9DFB60);
	static inline auto FDeactivate = PreyFunction<void(CAnimSequence* const _this)>(0x9DF5F0);
	static inline auto FSetIsStopping = PreyFunction<void(CAnimSequence* const _this, bool _bStopping)>(0x9E1620);
	static inline auto FIsStopping = PreyFunction<bool(const CAnimSequence* const _this)>(0x9DFD30);
	static inline auto FPrecacheData = PreyFunction<void(CAnimSequence* const _this, float startTime)>(0x9E0540);
	static inline auto FPrecacheStatic = PreyFunction<void(CAnimSequence* const _this, const float startTime)>(0x9E0540);
	static inline auto FPrecacheDynamic = PreyFunction<void(CAnimSequence* const _this, float time)>(0x9E03B0);
	static inline auto FPrecacheEntity = PreyFunction<void(CAnimSequence* const _this, IEntity* pEntity)>(0x9E0400);
	static inline auto FStillUpdate = PreyFunction<void(CAnimSequence* const _this)>(0x9E17E0);
	static inline auto FAnimate = PreyFunction<void(CAnimSequence* const _this, const SAnimContext& ec)>(0x9DECA0);
	static inline auto FRender = PreyFunction<void(CAnimSequence* const _this)>(0x9E0BD0);
	static inline auto FSerialize = PreyFunction<void(CAnimSequence* const _this, XmlNodeRef& xmlNode, bool bLoading, bool bLoadEmptyTracks, unsigned overrideId, bool bResetLightAnimSet)>(0x9E0FD0);
	static inline auto FCopyNodes = PreyFunction<void(CAnimSequence* const _this, XmlNodeRef& xmlNode, IAnimNode* * pSelectedNodes, unsigned count)>(0x9DEF10);
	static inline auto FPasteNodes = PreyFunction<void(CAnimSequence* const _this, const XmlNodeRef& xmlNode, IAnimNode* pParent)>(0x9E00B0);
	static inline auto FAddTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9DE990);
	static inline auto FRemoveTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9E0950);
	static inline auto FRenameTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent, const char* szNewEvent)>(0x9E0AE0);
	static inline auto FMoveUpTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9DFEA0);
	static inline auto FMoveDownTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9DFDB0);
	static inline auto FClearTrackEvents = PreyFunction<void(CAnimSequence* const _this)>(0x9DED80);
	static inline auto FGetTrackEventsCount = PreyFunction<int(const CAnimSequence* const _this)>(0x9DFB50);
	static inline auto FGetTrackEvent = PreyFunction<const char* (const CAnimSequence* const _this, int iIndex)>(0x9DFB00);
	static inline auto FGetTrackEventStringTable = PreyFunction<IAnimStringTable* (CAnimSequence* const _this)>(0x16A1030);
	static inline auto FTriggerTrackEvent = PreyFunction<void(CAnimSequence* const _this, const char* event, const char* param)>(0x9E1830);
	static inline auto FAddTrackEventListener = PreyFunction<void(CAnimSequence* const _this, ITrackEventListener* pListener)>(0x9DEAC0);
	static inline auto FRemoveTrackEventListener = PreyFunction<void(CAnimSequence* const _this, ITrackEventListener* pListener)>(0x9E0A90);
	static inline auto FGetArkConversation = PreyFunction<uint64_t(const CAnimSequence* const _this)>(0x155ADA0);
	static inline auto FSetArkConversation = PreyFunction<void(CAnimSequence* const _this, const uint64_t _conversationId)>(0x9E1610);
	static inline auto FCreateOrAddToCurrentConversation = PreyFunction<IArkConversation* (CAnimSequence* const _this, IArkSpeaker* _pSpeaker)>(0x9DF520);
	static inline auto FEndConversation = PreyFunction<void(CAnimSequence* const _this, bool _bComplete)>(0x9DF750);
	static inline auto FGetCurrentConversation = PreyFunction<const IArkConversation* (CAnimSequence* const _this)>(0x833BD0);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x9E0000);
	static inline auto FMoveAbsolutePositions = PreyFunction<void(CAnimSequence* const _this, const Vec3& offset)>(0x9DFD40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAnimSequence* const _this, ICrySizer* pSizer)>(0x9DF990);
	static inline auto FCopyNodeChildren = PreyFunction<void(CAnimSequence* const _this, XmlNodeRef& xmlNode, IAnimNode* pAnimNode)>(0x9DEDF0);
	static inline auto FNotifyTrackEvent = PreyFunction<void(CAnimSequence* const _this, ITrackEventListener::ETrackEventReason reason, const char* event, const char* param)>(0x9DFF80);
	static inline auto FCreateNodeInternal = PreyFunction<IAnimNode* (CAnimSequence* const _this, EAnimNodeType nodeType, unsigned nNodeId)>(0x9DF130);
#else
	static inline auto FCAnimSequenceOv2 = PreyFunction<void(CAnimSequence* const _this, IMovieSystem* pMovieSystem, unsigned id)>(0x9FB6C0);
	static inline auto FRelease = PreyFunction<void(CAnimSequence* const _this)>(0xA56ED0);
	static inline auto FSetName = PreyFunction<void(CAnimSequence* const _this, const char* name)>(0x9FEA40);
	static inline auto FGetName = PreyFunction<const char* (const CAnimSequence* const _this)>(0x20D640);
	static inline auto FGetId = PreyFunction<unsigned(const CAnimSequence* const _this)>(0xA1F860);
	static inline auto FGetFixedTimeStep = PreyFunction<float(const CAnimSequence* const _this)>(0x9FCCB0);
	static inline auto FSetFixedTimeStep = PreyFunction<void(CAnimSequence* const _this, float dt)>(0x9FEA10);
	static inline auto FSetOwner = PreyFunction<void(CAnimSequence* const _this, IAnimSequenceOwner* pOwner)>(0x9FEB60);
	static inline auto FGetOwner = PreyFunction<IAnimSequenceOwner* (const CAnimSequence* const _this)>(0x9FCEC0);
	static inline auto FSetActiveDirector = PreyFunction<void(CAnimSequence* const _this, IAnimNode* pDirectorNode)>(0x9FE9C0);
	static inline auto FGetActiveDirector = PreyFunction<IAnimNode* (const CAnimSequence* const _this)>(0x9FCC40);
	static inline auto FSetFlags = PreyFunction<void(CAnimSequence* const _this, int flags)>(0x9FEA20);
	static inline auto FGetFlags = PreyFunction<int(const CAnimSequence* const _this)>(0x1684410);
	static inline auto FGetCutSceneFlags = PreyFunction<int(const CAnimSequence* const _this, const bool localFlags)>(0x9FCC60);
	static inline auto FSetParentSequence = PreyFunction<void(CAnimSequence* const _this, IAnimSequence* pParentSequence)>(0x9FEB70);
	static inline auto FGetParentSequence = PreyFunction<const IAnimSequence* (const CAnimSequence* const _this)>(0x16804D0);
	static inline auto FIsAncestorOf = PreyFunction<bool(const CAnimSequence* const _this, const IAnimSequence* pSequence)>(0x9FCF70);
	static inline auto FSetTimeRange = PreyFunction<void(CAnimSequence* const _this, TRange<float> timeRange)>(0x9FEB80);
	static inline auto FGetTimeRange = PreyFunction<TRange<float>*(CAnimSequence* const _this, TRange<float>* _return_value_)>(0x9FCEF0);
	static inline auto FAdjustKeysToTimeRange = PreyFunction<void(CAnimSequence* const _this, const TRange<float>& timeRange)>(0x9FBF40);
	static inline auto FGetNodeCount = PreyFunction<int(const CAnimSequence* const _this)>(0x9FCEB0);
	static inline auto FGetNode = PreyFunction<IAnimNode* (const CAnimSequence* const _this, int index)>(0x9FCEA0);
	static inline auto FFindNodeByName = PreyFunction<IAnimNode* (CAnimSequence* const _this, const char* sNodeName, const IAnimNode* pParentDirector)>(0x9FCBB0);
	static inline auto FFindNodeById = PreyFunction<IAnimNode* (CAnimSequence* const _this, int nNodeId)>(0x9FCB80);
	static inline auto FReorderNode = PreyFunction<void(CAnimSequence* const _this, IAnimNode* pNode, IAnimNode* pPivotNode, bool bNext)>(0x9FE010);
	static inline auto FReset = PreyFunction<void(CAnimSequence* const _this, bool bSeekToStart)>(0x9FE180);
	static inline auto FResetHard = PreyFunction<void(CAnimSequence* const _this)>(0x9FE290);
	static inline auto FPause = PreyFunction<void(CAnimSequence* const _this)>(0x9FD740);
	static inline auto FResume = PreyFunction<void(CAnimSequence* const _this)>(0x9FE360);
	static inline auto FIsPaused = PreyFunction<bool(const CAnimSequence* const _this)>(0x13EFC30);
	static inline auto FOnStart = PreyFunction<void(CAnimSequence* const _this)>(0x9FD400);
	static inline auto FOnStop = PreyFunction<void(CAnimSequence* const _this, bool _bAbort)>(0x9FD450);
	static inline auto FAddNode = PreyFunction<bool(CAnimSequence* const _this, IAnimNode* pAnimNode)>(0x9FBBE0);
	static inline auto FCreateNodeOv1 = PreyFunction<IAnimNode* (CAnimSequence* const _this, EAnimNodeType nodeType)>(0x9FC500);
	static inline auto FCreateNodeOv0 = PreyFunction<IAnimNode* (CAnimSequence* const _this, XmlNodeRef node)>(0x9FC3C0);
	static inline auto FRemoveNode = PreyFunction<void(CAnimSequence* const _this, IAnimNode* node)>(0x9FDB70);
	static inline auto FRemoveAll = PreyFunction<void(CAnimSequence* const _this)>(0x9FDB00);
	static inline auto FActivate = PreyFunction<void(CAnimSequence* const _this)>(0x9FBB90);
	static inline auto FIsActivated = PreyFunction<bool(const CAnimSequence* const _this)>(0x9FCF60);
	static inline auto FDeactivate = PreyFunction<void(CAnimSequence* const _this)>(0x9FC9D0);
	static inline auto FSetIsStopping = PreyFunction<void(CAnimSequence* const _this, bool _bStopping)>(0x9FEA30);
	static inline auto FIsStopping = PreyFunction<bool(const CAnimSequence* const _this)>(0x9FD120);
	static inline auto FPrecacheData = PreyFunction<void(CAnimSequence* const _this, float startTime)>(0x9FD7A0);
	static inline auto FPrecacheStatic = PreyFunction<void(CAnimSequence* const _this, const float startTime)>(0x9FD7A0);
	static inline auto FPrecacheDynamic = PreyFunction<void(CAnimSequence* const _this, float time)>(0x9FD960);
	static inline auto FPrecacheEntity = PreyFunction<void(CAnimSequence* const _this, IEntity* pEntity)>(0x9FD9B0);
	static inline auto FStillUpdate = PreyFunction<void(CAnimSequence* const _this)>(0x9FEBF0);
	static inline auto FAnimate = PreyFunction<void(CAnimSequence* const _this, const SAnimContext& ec)>(0x9FC080);
	static inline auto FRender = PreyFunction<void(CAnimSequence* const _this)>(0x9FDFC0);
	static inline auto FSerialize = PreyFunction<void(CAnimSequence* const _this, XmlNodeRef& xmlNode, bool bLoading, bool bLoadEmptyTracks, unsigned overrideId, bool bResetLightAnimSet)>(0x9FE3C0);
	static inline auto FCopyNodes = PreyFunction<void(CAnimSequence* const _this, XmlNodeRef& xmlNode, IAnimNode* * pSelectedNodes, unsigned count)>(0x9FC2F0);
	static inline auto FPasteNodes = PreyFunction<void(CAnimSequence* const _this, const XmlNodeRef& xmlNode, IAnimNode* pParent)>(0x9FD4A0);
	static inline auto FAddTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9FBD70);
	static inline auto FRemoveTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9FDD40);
	static inline auto FRenameTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent, const char* szNewEvent)>(0x9FDED0);
	static inline auto FMoveUpTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9FD290);
	static inline auto FMoveDownTrackEvent = PreyFunction<bool(CAnimSequence* const _this, const char* szEvent)>(0x9FD1A0);
	static inline auto FClearTrackEvents = PreyFunction<void(CAnimSequence* const _this)>(0x9FC160);
	static inline auto FGetTrackEventsCount = PreyFunction<int(const CAnimSequence* const _this)>(0x9FCF50);
	static inline auto FGetTrackEvent = PreyFunction<const char* (const CAnimSequence* const _this, int iIndex)>(0x9FCF00);
	static inline auto FGetTrackEventStringTable = PreyFunction<IAnimStringTable* (CAnimSequence* const _this)>(0x510580);
	static inline auto FTriggerTrackEvent = PreyFunction<void(CAnimSequence* const _this, const char* event, const char* param)>(0x9FEC40);
	static inline auto FAddTrackEventListener = PreyFunction<void(CAnimSequence* const _this, ITrackEventListener* pListener)>(0x9FBEA0);
	static inline auto FRemoveTrackEventListener = PreyFunction<void(CAnimSequence* const _this, ITrackEventListener* pListener)>(0x9FDE80);
	static inline auto FGetArkConversation = PreyFunction<uint64_t(const CAnimSequence* const _this)>(0x9FCC50);
	static inline auto FSetArkConversation = PreyFunction<void(CAnimSequence* const _this, const uint64_t _conversationId)>(0x9FEA00);
	static inline auto FCreateOrAddToCurrentConversation = PreyFunction<IArkConversation* (CAnimSequence* const _this, IArkSpeaker* _pSpeaker)>(0x9FC900);
	static inline auto FEndConversation = PreyFunction<void(CAnimSequence* const _this, bool _bComplete)>(0x9FCB30);
	static inline auto FGetCurrentConversation = PreyFunction<const IArkConversation* (CAnimSequence* const _this)>(0x5D9010);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x9FD3F0);
	static inline auto FMoveAbsolutePositions = PreyFunction<void(CAnimSequence* const _this, const Vec3& offset)>(0x9FD130);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAnimSequence* const _this, ICrySizer* pSizer)>(0x9FCD90);
	static inline auto FCopyNodeChildren = PreyFunction<void(CAnimSequence* const _this, XmlNodeRef& xmlNode, IAnimNode* pAnimNode)>(0x9FC1D0);
	static inline auto FNotifyTrackEvent = PreyFunction<void(CAnimSequence* const _this, ITrackEventListener::ETrackEventReason reason, const char* event, const char* param)>(0x9FD370);
	static inline auto FCreateNodeInternal = PreyFunction<IAnimNode* (CAnimSequence* const _this, EAnimNodeType nodeType, unsigned nNodeId)>(0x9FC510);
#endif
};

