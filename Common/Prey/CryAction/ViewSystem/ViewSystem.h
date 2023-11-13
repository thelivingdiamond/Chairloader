// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryAction/IViewSystem.h>
#include <Prey/CryMovie/IMovieSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class CView;
struct IAnimSequence;
class ICrySizer;
struct ILevel;
struct ILevelInfo;
struct ISystem;
struct IView;
struct IViewSystemListener;
struct SCameraParams;

// CViewSystem
// Header:  CryEngine/cryaction/viewsystem/ViewSystem.h
class CViewSystem
	: public IViewSystem
	, public IMovieUser
	, public ILevelSystemListener
{ // Size=168 (0xA8)
public:
	using TViewMap = std::map<unsigned int, CView*>;
	using TViewIdVector = std::vector<unsigned int>;

	ISystem* m_pSystem;
	std::map<unsigned int, CView*> m_views;
	std::vector<unsigned int> m_cutsceneViewIdVector;
	std::vector<IViewSystemListener*> m_listeners;
	unsigned m_activeViewId;
	unsigned m_nextViewIdToAssign;
	unsigned m_preSequenceViewId;
	unsigned m_cutsceneViewId;
	unsigned m_cutsceneCount;
	bool m_bActiveViewFromSequence;
	bool m_bOverridenCameraRotation;
	Quat m_overridenCameraRotation;
	float m_fCameraNoise;
	float m_fCameraNoiseFrequency;
	float m_fDefaultCameraNearZ;
	float m_fBlendInPosSpeed;
	float m_fBlendInRotSpeed;
	bool m_bPerformBlendOut;
	int m_nViewSystemDebug;
	bool m_useDeferredViewSystemUpdate;
	bool m_bControlsAudioListeners;
	bool m_bInvalidateAudioListeners;

	virtual IView* CreateView();
	virtual void RemoveView(IView* pView);
	virtual void RemoveView(unsigned viewId);
	virtual void SetActiveView(IView* pView);
	virtual void SetActiveView(unsigned viewId);
	virtual IView* GetView(unsigned viewId);
	virtual IView* GetActiveView();
	virtual unsigned GetViewId(IView* pView);
	virtual unsigned GetActiveViewId();
	virtual void Serialize(TSerialize ser);
	virtual void PostSerialize();
	virtual IView* GetViewByEntityId(unsigned id, bool forceCreate);
	virtual float GetDefaultZNear();
	virtual void SetBlendParams(float fBlendPosSpeed, float fBlendRotSpeed, bool performBlendOut);
	virtual void SetOverrideCameraRotation(bool bOverride, Quat rotation);
	virtual bool IsPlayingCutScene() const;
	virtual void UpdateSoundListeners();
	virtual bool UseDeferredViewSystemUpdate() const;
	virtual void SetControlAudioListeners(const bool bActive);
	virtual void SetActiveCamera(const SCameraParams& params);
	virtual void BeginCutScene(IAnimSequence* pSeq, unsigned long dwFlags, bool bResetFX);
	virtual void EndCutScene(IAnimSequence* pSeq, unsigned long dwFlags);
	virtual void SendGlobalEvent(const char* pszEvent);
	virtual void OnLevelNotFound(const char* levelName);
	virtual void OnLoadingStart(ILevelInfo* pLevel);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo* pLevel);
	virtual void OnLoadingComplete(ILevel* pLevel);
	virtual void OnLoadingError(ILevelInfo* pLevel, const char* error);
	virtual void OnLoadingProgress(ILevelInfo* pLevel, int progressAmount);
	virtual void OnUnloadComplete(ILevel* pLevel);
	CViewSystem(ISystem* pSystem);
	virtual ~CViewSystem();
	void Update(float frameTime) { FUpdate(this, frameTime); }
	virtual bool AddListener(IViewSystemListener* pListener);
	virtual bool RemoveListener(IViewSystemListener* pListener);
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }
	void ClearAllViews() { FClearAllViews(this); }
	void RemoveViewById(unsigned viewId) { FRemoveViewById(this, viewId); }
	void DebugDraw() { FDebugDraw(this); }

#if 0
	void Release();
	void ClearCutsceneViews();
#endif

	static inline auto FCreateView = PreyFunction<IView* (CViewSystem* const _this)>(0x3DB3E0);
	static inline auto FRemoveViewOv1 = PreyFunction<void(CViewSystem* const _this, IView* pView)>(0x3DBFE0);
	static inline auto FRemoveViewOv0 = PreyFunction<void(CViewSystem* const _this, unsigned viewId)>(0x3DBFD0);
	static inline auto FSetActiveViewOv1 = PreyFunction<void(CViewSystem* const _this, IView* pView)>(0x3DC590);
	static inline auto FSetActiveViewOv0 = PreyFunction<void(CViewSystem* const _this, unsigned viewId)>(0x3DC530);
	static inline auto FGetView = PreyFunction<IView* (CViewSystem* const _this, unsigned viewId)>(0x3DBBB0);
	static inline auto FGetActiveView = PreyFunction<IView* (CViewSystem* const _this)>(0x3DBA80);
	static inline auto FGetViewId = PreyFunction<unsigned(CViewSystem* const _this, IView* pView)>(0x3DBD40);
	static inline auto FGetActiveViewId = PreyFunction<unsigned(CViewSystem* const _this)>(0x3DBA90);
	static inline auto FSerialize = PreyFunction<void(CViewSystem* const _this, TSerialize ser)>(0x3DC080);
	static inline auto FPostSerialize = PreyFunction<void(CViewSystem* const _this)>(0x3DBF00);
	static inline auto FGetViewByEntityId = PreyFunction<IView* (CViewSystem* const _this, unsigned id, bool forceCreate)>(0x3DBC00);
	static inline auto FGetDefaultZNear = PreyFunction<float(CViewSystem* const _this)>(0x22F4D0);
	static inline auto FSetBlendParams = PreyFunction<void(CViewSystem* const _this, float fBlendPosSpeed, float fBlendRotSpeed, bool performBlendOut)>(0x3DC610);
	static inline auto FSetOverrideCameraRotation = PreyFunction<void(CViewSystem* const _this, bool bOverride, Quat rotation)>(0x3DC650);
	static inline auto FIsPlayingCutScene = PreyFunction<bool(const CViewSystem* const _this)>(0x3DBDC0);
	static inline auto FUpdateSoundListeners = PreyFunction<void(CViewSystem* const _this)>(0x3DD020);
	static inline auto FUseDeferredViewSystemUpdate = PreyFunction<bool(const CViewSystem* const _this)>(0x1426BA0);
	static inline auto FSetControlAudioListeners = PreyFunction<void(CViewSystem* const _this, const bool bActive)>(0x3DC630);
	static inline auto FSetActiveCamera = PreyFunction<void(IMovieUser* const _this, const SCameraParams& params)>(0x3DC120);
	static inline auto FBeginCutScene = PreyFunction<void(IMovieUser* const _this, IAnimSequence* pSeq, unsigned long dwFlags, bool bResetFX)>(0x3DB230);
	static inline auto FEndCutScene = PreyFunction<void(IMovieUser* const _this, IAnimSequence* pSeq, unsigned long dwFlags)>(0x3DB8A0);
	static inline auto FSendGlobalEvent = PreyFunction<void(IMovieUser* const _this, const char* pszEvent)>(0xA13080);
	static inline auto FOnLevelNotFound = PreyFunction<void(ILevelSystemListener* const _this, const char* levelName)>(0xA13080);
	static inline auto FOnLoadingStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0x3DBE70);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0xA13080);
	static inline auto FOnLoadingComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0xA13080);
	static inline auto FOnLoadingError = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, const char* error)>(0xA13080);
	static inline auto FOnLoadingProgress = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, int progressAmount)>(0xA13080);
	static inline auto FOnUnloadComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0x3DBEB0);
	static inline auto FCViewSystemOv1 = PreyFunction<void(CViewSystem* const _this, ISystem* pSystem)>(0x3DAD00);
	static inline auto FUpdate = PreyFunction<void(CViewSystem* const _this, float frameTime)>(0x3DC680);
	static inline auto FAddListener = PreyFunction<bool(CViewSystem* const _this, IViewSystemListener* pListener)>(0x3DB1E0);
	static inline auto FRemoveListener = PreyFunction<bool(CViewSystem* const _this, IViewSystemListener* pListener)>(0x3DBF80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CViewSystem* const _this, ICrySizer* s)>(0x3DBAB0);
	static inline auto FClearAllViews = PreyFunction<void(CViewSystem* const _this)>(0x3DB2F0);
	static inline auto FRemoveViewById = PreyFunction<void(CViewSystem* const _this, unsigned viewId)>(0x3DC000);
	static inline auto FDebugDraw = PreyFunction<void(CViewSystem* const _this)>(0x3DB480);
};

