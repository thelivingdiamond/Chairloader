// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagestationmap.h
class CArkPDAPageStationMap : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageStationMap> // Id=801BA76 Size=64
{
public:
	uint64_t m_locationId;
	uint64_t m_objectiveId;
	float m_zoomAmount;
	float m_zoomDelta;
	
	CArkPDAPageStationMap();
	virtual ~CArkPDAPageStationMap();
	virtual void Open();
	virtual void Update(float _frameTime);
	virtual void Close();
	virtual void OnClosePDA();
	virtual bool ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue);
	void SetCurrentLocation(uint64_t _locationId) const { FSetCurrentLocation(this,_locationId); }
	void SetZoom(const float _zoomAmount) { FSetZoom(this,_zoomAmount); }
	void OnSelectLevel(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSelectLevel(this,_pSender,_event,_args); }
	virtual void SetupInputPrompts();
	void UpdateInputPrompt() const { FUpdateInputPrompt(this); }
	virtual bool ManagesInputPrompts() const;
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageStationMap *const _this)>(0x134DBE0);
	static inline auto FUpdate = PreyFunction<void(CArkPDAPageStationMap *const _this, float _frameTime)>(0x134E840);
	static inline auto FClose = PreyFunction<void(CArkPDAPageStationMap *const _this)>(0x1628FA0);
	static inline auto FOnClosePDA = PreyFunction<void(CArkPDAPageStationMap *const _this)>(0x134D360);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageStationMap *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x134E250);
	static inline auto FSetCurrentLocation = PreyFunction<void(CArkPDAPageStationMap const *const _this, uint64_t _locationId)>(0x134E3D0);
	static inline auto FSetZoom = PreyFunction<void(CArkPDAPageStationMap *const _this, const float _zoomAmount)>(0x134E590);
	static inline auto FOnSelectLevel = PreyFunction<void(CArkPDAPageStationMap *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x134D370);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageStationMap *const _this)>(0x134E740);
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkPDAPageStationMap const *const _this)>(0x134E8B0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageStationMap const *const _this)>(0x1B933B0);
};

