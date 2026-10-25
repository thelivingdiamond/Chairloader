// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

class CCryName;
struct IActionFilter;
struct SActionMapEvent;

// Header: FromCpp
// Prey/GameDll/ark/ArkExclusiveActionFilter.h
#ifdef MOONCRASH
#include <Prey/CryString/CryName.h>
enum EControlScheme;
#endif
class ArkExclusiveActionFilter : public IUIControlSchemeListener, public IActionMapEventListener // Id=80147D1 Size=88
{
public:
	bool m_bIgnoreActionMapState;
	string m_filterName;
	string m_actionMap;
	std::vector<CCryName> m_filteredActionIds;
	std::vector<CCryName> m_allowedActionIds;
	
#ifndef MOONCRASH
	ArkExclusiveActionFilter() { FArkExclusiveActionFilter(this); }
#endif
	virtual ~ArkExclusiveActionFilter() { FBitNotArkExclusiveActionFilter(this); }
	void CreateActionFilter(const char *_pName) { FCreateActionFilter(this,_pName); }
	void Enable(bool _bEnable) { FEnable(this,_bEnable); }
	bool Enabled() const { return FEnabled(this); }
	void SetActionMap(string const &_actionMap) { FSetActionMap(this,_actionMap); }
	void Filter(CCryName const &_action) { FFilter(this,_action); }
	void Allow(CCryName const &_action) { FAllow(this,_action); }
	void BuildFilterList(IActionFilter *_pFilter) { FBuildFilterList(this,_pFilter); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme) { return FOnControlSchemeChanged(this, _controlScheme); }
	virtual void OnActionMapEvent(SActionMapEvent const &_event) { FOnActionMapEvent(this, _event); }
	
#if 0
	string const &GetActionMap() const;
	void SetIgnoreActionMapState(bool arg0);
	IActionFilter *GetActionFilter()
#endif

#ifndef MOONCRASH
	static inline auto FArkExclusiveActionFilter = PreyFunction<void(ArkExclusiveActionFilter *const _this)>(0x115ED10);
	static inline auto FBitNotArkExclusiveActionFilter = PreyFunction<void(ArkExclusiveActionFilter *const _this)>(0x115ED60);
	static inline auto FCreateActionFilter = PreyFunction<void(ArkExclusiveActionFilter *const _this, const char *_pName)>(0x115F440);
	static inline auto FEnable = PreyFunction<void(ArkExclusiveActionFilter *const _this, bool _bEnable)>(0x115F4B0);
	static inline auto FEnabled = PreyFunction<bool(ArkExclusiveActionFilter const *const _this)>(0x115F5B0);
	static inline auto FSetActionMap = PreyFunction<void(ArkExclusiveActionFilter *const _this, string const &_actionMap)>(0x115F710);
	static inline auto FFilter = PreyFunction<void(ArkExclusiveActionFilter *const _this, CCryName const &_action)>(0x115F610);
	static inline auto FAllow = PreyFunction<void(ArkExclusiveActionFilter *const _this, CCryName const &_action)>(0x115EFC0);
	static inline auto FBuildFilterList = PreyFunction<void(ArkExclusiveActionFilter *const _this, IActionFilter *_pFilter)>(0x115EFD0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkExclusiveActionFilter *const _this, EControlScheme _controlScheme)>(0x115F6B0);
	static inline auto FOnActionMapEvent = PreyFunction<void(ArkExclusiveActionFilter *const _this, SActionMapEvent const &_event)>(0x115F640);
#else
	static inline auto FArkExclusiveActionFilterOv1 = PreyFunction<void(ArkExclusiveActionFilter* const _this)>(0x11AC440);
	static inline auto FBitNotArkExclusiveActionFilter = PreyFunction<void(ArkExclusiveActionFilter* const _this)>(0x11AC490);
	static inline auto FCreateActionFilter = PreyFunction<void(ArkExclusiveActionFilter* const _this, const char* _pName)>(0x11ACB70);
	static inline auto FEnable = PreyFunction<void(ArkExclusiveActionFilter* const _this, bool _bEnable)>(0x11ACBE0);
	static inline auto FEnabled = PreyFunction<bool(const ArkExclusiveActionFilter* const _this)>(0x11ACCE0);
	static inline auto FSetActionMap = PreyFunction<void(ArkExclusiveActionFilter* const _this, const string& _actionMap)>(0x11ACE40);
	static inline auto FFilter = PreyFunction<void(ArkExclusiveActionFilter* const _this, const CCryName& _action)>(0x11ACD40);
	static inline auto FAllow = PreyFunction<void(ArkExclusiveActionFilter* const _this, const CCryName& _action)>(0x11AC6F0);
	static inline auto FBuildFilterList = PreyFunction<void(ArkExclusiveActionFilter* const _this, IActionFilter* _pFilter)>(0x11AC700);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkExclusiveActionFilter* const _this, const EControlScheme _controlScheme)>(0x11ACDE0);
	static inline auto FOnActionMapEvent = PreyFunction<void(IActionMapEventListener* const _this, const SActionMapEvent& _event)>(0x11ACD70);
#endif
};
