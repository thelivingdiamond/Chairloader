// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryString/CryName.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkHitDamageUI.h>
#include <Prey/GameDll/ark/ui/IHUDEventListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct AABB;
class ArkInputLegend;
class ArkLogEntry;
class ArkObjective;
class ArkObjectiveTask;
class CArkItem;
struct HitInfo;
struct ICVar;
struct IEntity;
struct ILoadGame;
struct ISaveGame;
struct IUIElement;
struct IUIEventSystem;
struct SActionEvent;
struct SActionMapEvent;
struct SHUDEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/arkuihud.h
class CArkUIHUD : public ArkUIMenuBase<CArkUIHUD>, public IUIGameEventSystem, public IHUDEventListener, public ISystemEventListener, public IUIControlSchemeListener, public IGameFrameworkListener, public IActionMapEventListener // Id=8017674 Size=936
{
public:
	enum EUIEvent
	{
		eUIE_SprintStaminaChanged = 0,
		eUIE_ObjectiveMenuHighlight = 1,
		eUIE_ScannerEquip = 2,
		eUIE_ScannerUnequip = 3,
		eUIE_ScannerShowTargetDetails = 4,
		eUIE_ScannerHideTargetDetails = 5,
		eUIE_ScannerLoseScanTarget = 6,
		eUIE_ScannerFindLostScanTarget = 7,
		eUIE_ScannerStartScanning = 8,
		eUIE_ScannerStopScanning = 9,
		eUIE_ScannerCompleteScanning = 10,
		eUIE_ScannerUpdateEnemyMeter = 11,
		eUIE_ScanningResearchCompleted = 12,
		eUIE_PsiMeterEnable = 13,
		eUIE_PsiMeterUpdate = 14,
		eUIE_PDAToggle = 15,
		eUIE_InitTrauma = 16,
		eUIE_ShowpieceMusicHack = 17,
	};

	enum class HitStrength
	{
		ineffective = 0,
		normal = 1,
		effective = 2,
	};

	enum class RelativePosition
	{
		center = 0,
		top = 1,
	};

	ArkHitDamageUI m_hitDamageUI;
	SUIEventSenderDispatcher<enum CArkUIHUD::EUIEvent> m_eventSender;
	IUIEventSystem *m_pUIFunctions;
	int m_nextTargetID;
	unsigned m_pickupTargetID;
	CCryName m_currentIteractReticle;
	CCryName m_currentWeaponReticle;
	std::set<int,std::less<int>> m_unavailableTargetIds;
	float m_feedbackTimeRemaining;
	float m_psiScannerRadius;
	std::map<unsigned int,int,std::less<unsigned int>> m_silhouettes;
	
	enum class StunGunEnemyRangeText
	{
		NotEquipped = 0,
		ShowText = 1,
		HideText = 2,
	};

	unsigned m_entityUnderReticle;
	float m_reticleDistSquared;
	bool m_bReticleOverTransparent;
	bool m_bReticleOverEnemy;
	CArkUIHUD::StunGunEnemyRangeText m_stungunEnemyRangeText;
	static int pl_pickupSilhouette;
	
	using ActiveLegend = std::pair<unsigned int,ArkInputLegend const *>;
	
	std::vector<std::pair<unsigned int,ArkInputLegend const *>> m_activeLegends;
	unsigned m_legendHandleGen;
	int64_t m_timedTask;
	ArkSimpleTimer m_errorTimer;
	wstring m_errorMsg;
	static Matrix44 s_cameraScreenProj;
	std::vector<ArkLogEntry> m_logQueue;
	
	class VisibleLogEntry : public ArkLogEntry // Id=80176D9 Size=64
	{
	public:
		string m_uniqueIdString;
		ArkTimeRemaining m_timer;
		
		VisibleLogEntry(ArkLogEntry const &_logEntry, float _duration);
		wstring BuildFinalString() const { return FBuildFinalString(this); }
		void Invalidate() { FInvalidate(this); }
		int GetUICategory() const { return FGetUICategory(this); }
		
#if 0
		bool IsValid() const;
#endif
		
		static inline auto FBuildFinalString = PreyFunction<wstring(CArkUIHUD::VisibleLogEntry const *const _this)>(0x1637150);
		static inline auto FInvalidate = PreyFunction<void(CArkUIHUD::VisibleLogEntry *const _this)>(0x1639310);
		static inline auto FGetUICategory = PreyFunction<int(CArkUIHUD::VisibleLogEntry const *const _this)>(0x1638440);
	};

	std::array<CArkUIHUD::VisibleLogEntry,4> m_visibleLog;
	
	CArkUIHUD();
	virtual ~CArkUIHUD();
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float _delta);
	void SetPaused(bool _bPaused) { FSetPaused(this,_bPaused); }
	void PostSerialize() { FPostSerialize(this); }
	static Matrix44 GetScreenProjectionMatrix() { return FGetScreenProjectionMatrix(); }
	int AddTarget(wstring const &_rText, Vec2 _pos, const bool _bActive) { return FAddTarget(this,_rText,_pos,_bActive); }
	void UpdateTarget(const int _Id, Vec2 _pos, const bool _bActive) { FUpdateTarget(this,_Id,_pos,_bActive); }
	void RemoveTarget(const int _Id) { FRemoveTarget(this,_Id); }
	SUIEventSenderDispatcher<enum CArkUIHUD::EUIEvent> &GetEventSender() { return FGetEventSender(this); }
	static Vec2 GetScreenPixelPos(Vec2 const &_screenPos) { return FGetScreenPixelPosOv2(_screenPos); }
	static boost::tuples::tuple<Vec2_tpl<float>,bool,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type> GetScreenPixelPos(Vec3 const &_worldPos, bool _bClampSafeZone) { return FGetScreenPixelPosOv0(_worldPos,_bClampSafeZone); }
	static Vec2 GetEntityScreenPos(IEntity const &_entity) { return FGetEntityScreenPos(_entity); }
	static boost::tuples::tuple<Vec2_tpl<float>,bool,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type> GetScreenPos(Vec3 const &_worldPos, bool _bClampSafeZone) { return FGetScreenPos(_worldPos,_bClampSafeZone); }
	void ClearFeedback() { FClearFeedback(this); }
	void DisplayFeedback(string const &_feedback, float _duration) { FDisplayFeedbackOv1(this,_feedback,_duration); }
	void ShowErrorMessage(string const &_errorMessage, float _duration, bool _bBlinking) { FShowErrorMessageOv1(this,_errorMessage,_duration,_bBlinking); }
	void ShowErrorMessage(wstring const &_errorMessage, float _duration, bool _bBlinking) { FShowErrorMessageOv0(this,_errorMessage,_duration,_bBlinking); }
	unsigned PushInputLegend(ArkInputLegend const &_inputLegend) { return FPushInputLegend(this,_inputLegend); }
	void RemoveInputLegend(unsigned _legendHandle) { FRemoveInputLegend(this,_legendHandle); }
	void RefreshInputLegends() const { FRefreshInputLegends(this); }
	static void PlayReticleHit(unsigned _targetId, CArkUIHUD::HitStrength _strength) { FPlayReticleHit(_targetId,_strength); }
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	static IUIElement *GetMarkerUIElement() { return FGetMarkerUIElement(); }
	static IUIElement *GetHUDUIElement() { return FGetHUDUIElement(); }
	virtual void OnHUDEvent(SHUDEvent const &_event);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnSetVisible(IUIElement *_pSender, bool _bVisible);
	virtual void OnActionMapEvent(SActionMapEvent const &_event);
	void ActivateTaskTimer(int64_t _taskId, string const &_label) { FActivateTaskTimer(this,_taskId,_label); }
	void DeactivateTaskTimer(int64_t _taskId) { FDeactivateTaskTimer(this,_taskId); }
	void SetHUDSilhouette(unsigned _entityId, EArkSilhouetteType _type) { FSetHUDSilhouette(this,_entityId,_type); }
	void ClearHUDSilhouette(unsigned _entityId, EArkSilhouetteType _type) { FClearHUDSilhouette(this,_entityId,_type); }
	bool IsVisible(const unsigned &_handle) const { return FIsVisible(this,_handle); }
	void AddLogEntry(ArkLogEntry const &_logEntry) { FAddLogEntry(this,_logEntry); }
	static void OnItemPickup(CArkItem const &_item, int _count) { FOnItemPickup(_item,_count); }
	static void OnChipsetEffect(const char *_notif) { FOnChipsetEffect(_notif); }
	void OnEnemyHit(HitInfo const &_hitInfo) { FOnEnemyHit(this,_hitInfo); }
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame *pSaveGame);
	virtual void OnLoadGame(ILoadGame *pLoadGame);
	virtual void OnLevelEnd(const char *nextLevel);
	virtual void OnActionEvent(SActionEvent const &event);
	virtual void OnPreRender();
	void UpdateHUDSilhouette(unsigned _entityId) const { FUpdateHUDSilhouette(this,_entityId); }
	static void OnPickupSilhouetteChanged(ICVar *_pArgs) { FOnPickupSilhouetteChanged(_pArgs); }
	void UpdateLogEntry(float _frameTime) { FUpdateLogEntry(this,_frameTime); }
	void CollapseVisibleLog_r(int _endingIndex) { FCollapseVisibleLog_r(this,_endingIndex); }
	static void UpdateInputLegend(ArkInputLegend const &_inputLegend) { FUpdateInputLegend(_inputLegend); }
	void OnShowObjectiveNotification(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowObjectiveNotification(this,_pSender,_event,_args); }
	void OnStaminaPreviewAnimationFinished(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnStaminaPreviewAnimationFinished(this,_pSender,_event,_args); }
	void OnUpdatePsiScannerRadius(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnUpdatePsiScannerRadius(this,_pSender,_event,_args); }
	
#if 0
	static const char *GetTypeNameS();
	static TRect_tpl<float> GetScreenPixelPos(AABB const &arg0);
	static Vec3 GetWorldPos(Vec2 const &arg0);
	void DisplayFeedback(wstring const &arg0, float arg1);
	static void AddObjectiveNotification(ArkObjective const &arg0, EArkTaskMarkerStyle arg1);
	static void AddObjectiveTaskNotification(ArkObjective const &arg0, ArkObjectiveTask const &arg1, EArkTaskMarkerStyle arg2);
	static boost::optional<Vec2> GetEntityScreenPosInHUD(IEntity const &arg0, CArkUIHUD::RelativePosition arg1);
	unsigned GetEntityUnderReticle() const;
	float GetDistanceSquaredOfRaycast() const;
	bool IsReticleOverTransparent() const;
	float GetPsiScannerRadius() const;
	void ClearPickupTarget();
#endif
	
	static inline auto FBitNotCArkUIHUD = PreyFunction<void(CArkUIHUD *const _this)>(0x1635810);
	static inline auto FGetTypeName = PreyFunction<const char *(CArkUIHUD const *const _this)>(0x1638430);
	static inline auto FInitEventSystem = PreyFunction<void(CArkUIHUD *const _this)>(0x16384A0);
	static inline auto FUnloadEventSystem = PreyFunction<void(CArkUIHUD *const _this)>(0x163BFD0);
	static inline auto FOnUpdate = PreyFunction<void(CArkUIHUD *const _this, float _delta)>(0x163A450);
	static inline auto FSetPaused = PreyFunction<void(CArkUIHUD *const _this, bool _bPaused)>(0x163BB50);
	static inline auto FPostSerialize = PreyFunction<void(CArkUIHUD *const _this)>(0x163B380);
	static inline auto FGetScreenProjectionMatrix = PreyFunction<Matrix44()>(0x1638400);
	static inline auto FAddTarget = PreyFunction<int(CArkUIHUD *const _this, wstring const &_rText, Vec2 _pos, const bool _bActive)>(0x1637070);
	static inline auto FUpdateTarget = PreyFunction<void(CArkUIHUD *const _this, const int _Id, Vec2 _pos, const bool _bActive)>(0x163CAD0);
	static inline auto FRemoveTarget = PreyFunction<void(CArkUIHUD *const _this, const int _Id)>(0x163B970);
	static inline auto FGetEventSender = PreyFunction<SUIEventSenderDispatcher<enum CArkUIHUD::EUIEvent> &(CArkUIHUD *const _this)>(0x1637E70);
	static inline auto FGetScreenPixelPosOv2 = PreyFunction<Vec2(Vec2 const &_screenPos)>(0x1637EC0);
	static inline auto FGetScreenPixelPosOv0 = PreyFunction<boost::tuples::tuple<Vec2_tpl<float>,bool,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type>(Vec3 const &_worldPos, bool _bClampSafeZone)>(0x1637FC0);
	static inline auto FGetEntityScreenPos = PreyFunction<Vec2(IEntity const &_entity)>(0x1637E30);
	static inline auto FGetScreenPos = PreyFunction<boost::tuples::tuple<Vec2_tpl<float>,bool,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type,boost::tuples::null_type>(Vec3 const &_worldPos, bool _bClampSafeZone)>(0x16380F0);
	static inline auto FClearFeedback = PreyFunction<void(CArkUIHUD *const _this)>(0x1637630);
	static inline auto FDisplayFeedbackOv1 = PreyFunction<void(CArkUIHUD *const _this, string const &_feedback, float _duration)>(0x1637C80);
	static inline auto FShowErrorMessageOv1 = PreyFunction<void(CArkUIHUD *const _this, string const &_errorMessage, float _duration, bool _bBlinking)>(0x163BCE0);
	static inline auto FShowErrorMessageOv0 = PreyFunction<void(CArkUIHUD *const _this, wstring const &_errorMessage, float _duration, bool _bBlinking)>(0x163BD80);
	static inline auto FPushInputLegend = PreyFunction<unsigned(CArkUIHUD *const _this, ArkInputLegend const &_inputLegend)>(0x163B7B0);
	static inline auto FRemoveInputLegend = PreyFunction<void(CArkUIHUD *const _this, unsigned _legendHandle)>(0x163B820);
	static inline auto FRefreshInputLegends = PreyFunction<void(CArkUIHUD const *const _this)>(0x163B800);
	static inline auto FPlayReticleHit = PreyFunction<void(unsigned _targetId, CArkUIHUD::HitStrength _strength)>(0x163B280);
	static inline auto FOnSystemEvent = PreyFunction<void(CArkUIHUD *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x163A010);
	static inline auto FGetMarkerUIElement = PreyFunction<IUIElement *()>(0x1637EA0);
	static inline auto FGetHUDUIElement = PreyFunction<IUIElement *()>(0x1637E80);
	static inline auto FOnHUDEvent = PreyFunction<void(CArkUIHUD *const _this, SHUDEvent const &_event)>(0x1639780);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(CArkUIHUD *const _this, EControlScheme _controlScheme)>(0x1639710);
	static inline auto FOnSetVisible = PreyFunction<void(CArkUIHUD *const _this, IUIElement *_pSender, bool _bVisible)>(0x1639EA0);
	static inline auto FOnActionMapEvent = PreyFunction<void(CArkUIHUD *const _this, SActionMapEvent const &_event)>(0x1639440);
	static inline auto FActivateTaskTimer = PreyFunction<void(CArkUIHUD *const _this, int64_t _taskId, string const &_label)>(0x1636500);
	static inline auto FDeactivateTaskTimer = PreyFunction<void(CArkUIHUD *const _this, int64_t _taskId)>(0x1637C20);
	static inline auto FSetHUDSilhouette = PreyFunction<void(CArkUIHUD *const _this, unsigned _entityId, EArkSilhouetteType _type)>(0x163BA90);
	static inline auto FClearHUDSilhouette = PreyFunction<void(CArkUIHUD *const _this, unsigned _entityId, EArkSilhouetteType _type)>(0x1637640);
	static inline auto FIsVisible = PreyFunction<bool(CArkUIHUD const *const _this, const unsigned &_handle)>(0x1639420);
	static inline auto FAddLogEntry = PreyFunction<void(CArkUIHUD *const _this, ArkLogEntry const &_logEntry)>(0x16367A0);
	static inline auto FOnItemPickup = PreyFunction<void(CArkItem const &_item, int _count)>(0x1639810);
	static inline auto FOnChipsetEffect = PreyFunction<void(const char *_notif)>(0x1639460);
	static inline auto FOnEnemyHit = PreyFunction<void(CArkUIHUD *const _this, HitInfo const &_hitInfo)>(0x1639770);
	static inline auto FOnPostUpdate = PreyFunction<void(CArkUIHUD *const _this, float fDeltaTime)>(0xA13080);
	static inline auto FOnSaveGame = PreyFunction<void(CArkUIHUD *const _this, ISaveGame *pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(CArkUIHUD *const _this, ILoadGame *pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(CArkUIHUD *const _this, const char *nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(CArkUIHUD *const _this, SActionEvent const &event)>(0xA13080);
	static inline auto FOnPreRender = PreyFunction<void(CArkUIHUD *const _this)>(0x1639B40);
	static inline auto FUpdateHUDSilhouette = PreyFunction<void(CArkUIHUD const *const _this, unsigned _entityId)>(0x163C040);
	static inline auto FOnPickupSilhouetteChanged = PreyFunction<void(ICVar *_pArgs)>(0x1639AE0);
	static inline auto FUpdateLogEntry = PreyFunction<void(CArkUIHUD *const _this, float _frameTime)>(0x163C4C0);
	static inline auto FCollapseVisibleLog_r = PreyFunction<void(CArkUIHUD *const _this, int _endingIndex)>(0x16376D0);
	static inline auto FUpdateInputLegend = PreyFunction<void(ArkInputLegend const &_inputLegend)>(0x163C0D0);
	static inline auto FOnShowObjectiveNotification = PreyFunction<void(CArkUIHUD *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1639EF0);
	static inline auto FOnStaminaPreviewAnimationFinished = PreyFunction<void(CArkUIHUD *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1639FE0);
	static inline auto FOnUpdatePsiScannerRadius = PreyFunction<void(CArkUIHUD *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163B1F0);
};

