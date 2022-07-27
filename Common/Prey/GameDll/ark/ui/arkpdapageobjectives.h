// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkObjective;
class CCryName;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapageobjectives.h
class CArkPDAPageObjectives : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageObjectives> // Id=801BA99 Size=64
{
public:
	int64_t m_highlightObjectiveId;
	int64_t m_locationTaskId;
	bool m_bShowingCompleted;
	
	CArkPDAPageObjectives();
	virtual ~CArkPDAPageObjectives();
	virtual bool ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue);
	void HighlightObjective(int64_t _objectiveId) const { FHighlightObjective(this,_objectiveId); }
	void OnHighlightObjective(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnHighlightObjective(this,_pSender,_event,_args); }
	void OnSetTrackedObjective(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetTrackedObjective(this,_pSender,_event,_args); }
	void OnGotoMap(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnGotoMap(this,_pSender,_event,_args); }
	void GotoTaskOnMap() const { FGotoTaskOnMap(this); }
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	void UpdateInputPrompt(const bool _bUpdateUI) const { FUpdateInputPrompt(this,_bUpdateUI); }
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	void UpdateShowMapButton() const { FUpdateShowMapButton(this); }
	
#if 0
	static ArkPDAPage GetPDAPage();
	static bool IsObjectiveVisible(ArkObjective const &arg0);
#endif
	
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageObjectives *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x162BA60);
	static inline auto FHighlightObjective = PreyFunction<void(CArkPDAPageObjectives const *const _this, int64_t _objectiveId)>(0x162AE90);
	static inline auto FOnHighlightObjective = PreyFunction<void(CArkPDAPageObjectives *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x162B090);
	static inline auto FOnSetTrackedObjective = PreyFunction<void(CArkPDAPageObjectives *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x162B790);
	static inline auto FOnGotoMap = PreyFunction<void(CArkPDAPageObjectives *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x162B080);
	static inline auto FGotoTaskOnMap = PreyFunction<void(CArkPDAPageObjectives const *const _this)>(0x162ADD0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageObjectives *const _this)>(0x162B9E0);
	static inline auto FClose = PreyFunction<void(CArkPDAPageObjectives *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageObjectives const *const _this)>(0x162BB40);
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkPDAPageObjectives const *const _this, const bool _bUpdateUI)>(0x162C0F0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageObjectives const *const _this)>(0x1B933B0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageObjectives *const _this)>(0x162BFE0);
	static inline auto FUpdateShowMapButton = PreyFunction<void(CArkPDAPageObjectives const *const _this)>(0x162C410);
};

