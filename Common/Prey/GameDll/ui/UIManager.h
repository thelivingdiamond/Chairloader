// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  File name:   UIManager.h
//  Version:     v1.00
//  Created:     08/8/2011 by Paul Reindell.
//  Description: 
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////
#ifndef __UIManager_H__
#define __UIManager_H__

#include <array>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryAction/FlashUI/FlashUI.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include "IUIGameEventSystem.h"
#include "UITypes.h"

class CProfileOptions;
struct IUIEventSystem;

class CUIManager
	: public ISystemEventListener
	, public IGameFrameworkListener
	, public IInputEventListener
{
public:
	EntityId m_soundListener;
	bool m_bRegistered;

	CProfileOptions* m_pOptions;
	EControlScheme m_curControlScheme;
	EControlScheme m_actualControlScheme;
	std::array<int, 4> m_lastDeviceIndices;
	TUIControlSchemeListeners m_controlSchemeListeners;

	typedef std::map<string, TUIEventSystemPtr> TUIEventSystems;
	TUIEventSystems m_EventSystems;

	enum EUIEvent
	{
		eUIE_OnControlSchemeChanged = 0,
	};

	SUIEventSenderDispatcher<enum CUIManager::EUIEvent> m_eventSender;
	IUIEventSystem* m_pUIFunctions;

	CUIManager();
	virtual ~CUIManager();
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	void PostSerialize() { FPostSerialize(this); }
	virtual bool OnInputEvent(SInputEvent const& event);
	virtual int GetPriority() const;
	IUIGameEventSystem* GetUIEventSystem(const char* type) const { return FGetUIEventSystem(this, type); }
	void ProcessViewParams(SViewParams const& viewParams) { FProcessViewParams(this, viewParams); }
	void ActivateState(const char* state) { FActivateState(this, state); }
	void ActivateDefaultState() { FActivateDefaultState(this); }
	bool IsInMenu() { return FIsInMenu(this); }
	void InitGameType(bool multiplayer, bool fromInit) { FInitGameType(this, multiplayer, fromInit); }
	bool RegisterControlSchemeListener(IUIControlSchemeListener* pListener) { return FRegisterControlSchemeListener(this, pListener); }
	bool UnregisterControlSchemeListener(IUIControlSchemeListener* pListener) { return FUnregisterControlSchemeListener(this, pListener); }
	void SetCurControlScheme(EControlScheme controlScheme) { FSetCurControlScheme(this, controlScheme); }
	void RefreshControlScheme() { FRefreshControlScheme(this); }
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* nextLevel);
	virtual void OnActionEvent(SActionEvent const& event);
	virtual void OnPreRender();
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }

#if 0
	CProfileOptions* GetOptions() const;
	void ActivateStateImmediate(const char* arg0);
	void ActivateDefaultStateImmediate();
	bool IsLoading();
	bool IsPreGameDone();
	void ForceCompletePreGame();
	void ClearControlSchemeListeners();
	void SetDefaultControlScheme();
	EControlScheme GetCurControlScheme() const;
	EControlScheme GetFunctionalControlScheme() const;
	int GetDeviceIndexForDevice(EInputDeviceType arg0) const;
	static bool IsController(EControlScheme arg0);
	void InitSound();
	void ShutdownSound();
#endif

	static inline auto FInit = PreyFunction<void(CUIManager* const _this)>(0x17FEBC0);
	static inline auto FShutdown = PreyFunction<void(CUIManager* const _this)>(0x17FF7A0);
	static inline auto FPostSerialize = PreyFunction<void(CUIManager* const _this)>(0xA13080);
	static inline auto FOnInputEvent = PreyFunction<bool(CUIManager* const _this, SInputEvent const& event)>(0x17FF250);
	static inline auto FGetPriority = PreyFunction<int(CUIManager const* const _this)>(0x1B1DEA0);
	static inline auto FGetUIEventSystem = PreyFunction<IUIGameEventSystem* (CUIManager const* const _this, const char* type)>(0x17FEA80);
	static inline auto FProcessViewParams = PreyFunction<void(CUIManager* const _this, SViewParams const& viewParams)>(0x17FF3D0);
	static inline auto FActivateState = PreyFunction<void(CUIManager* const _this, const char* state)>(0xA13080);
	static inline auto FActivateDefaultState = PreyFunction<void(CUIManager* const _this)>(0xA13080);
	static inline auto FIsInMenu = PreyFunction<bool(CUIManager* const _this)>(0xDD23F0);
	static inline auto FInitGameType = PreyFunction<void(CUIManager* const _this, bool multiplayer, bool fromInit)>(0xA13080);
	static inline auto FRegisterControlSchemeListener = PreyFunction<bool(CUIManager* const _this, IUIControlSchemeListener* pListener)>(0x17FF540);
	static inline auto FUnregisterControlSchemeListener = PreyFunction<bool(CUIManager* const _this, IUIControlSchemeListener* pListener)>(0x17FF8E0);
	static inline auto FSetCurControlScheme = PreyFunction<void(CUIManager* const _this, EControlScheme controlScheme)>(0x17FF590);
	static inline auto FRefreshControlScheme = PreyFunction<void(CUIManager* const _this)>(0x17FF470);
	static inline auto FOnSystemEvent = PreyFunction<void(CUIManager* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xA13080);
	static inline auto FOnPostUpdate = PreyFunction<void(CUIManager* const _this, float fDeltaTime)>(0x17FF330);
	static inline auto FOnSaveGame = PreyFunction<void(CUIManager* const _this, ISaveGame* pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(CUIManager* const _this, ILoadGame* pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(CUIManager* const _this, const char* nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(CUIManager* const _this, SActionEvent const& event)>(0xA13080);
	static inline auto FOnPreRender = PreyFunction<void(CUIManager* const _this)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CUIManager const* const _this, ICrySizer* pSizer)>(0x17FEA30);
};

static_assert(sizeof(CUIManager) == 152);

namespace UIEvents
{
	template <class T>
	T* Get()
	{
		if(g_pGame->GetUI())
			return static_cast<T*>(g_pGame->GetUI()->GetUIEventSystem(T::GetTypeNameS()));
		return NULL;
	}
}

#if FRONTEND_ENABLE_EXTRA_DEBUG
#define FE_LOG( ... )                                    \
{                                                        \
	string temp;                                            \
	temp.Format(__VA_ARGS__);                               \
	CryLogAlways( "[UI] %s", temp.c_str() );                \
}
#else
#define FE_LOG(...)
#endif


#endif

