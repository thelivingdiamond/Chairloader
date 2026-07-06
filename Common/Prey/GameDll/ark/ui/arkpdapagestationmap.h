// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

enum class ArkPDAPage;
class CCryName;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// CArkPDAPageStationMap
// Header:  Prey/GameDll/ark/ui/ArkPDAPageStationMap.h
class CArkPDAPageStationMap : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageStationMap>
{ // Size=64 (0x40)
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
	virtual bool ProcessInput(const CCryName& _rActionId, const int _activationMode, const float _fValue);
	void SetCurrentLocation(uint64_t _locationId) const { FSetCurrentLocation(this, _locationId); }
	void SetZoom(const float _zoomAmount) { FSetZoom(this, _zoomAmount); }
	void OnPressMapObjective() { FOnPressMapObjective(this); }
	void OnSelectLevel(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSelectLevel(this, _pSender, _event, _args); }
	virtual void SetupInputPrompts();
	void UpdateInputPrompt() const { FUpdateInputPrompt(this); }
	virtual bool ManagesInputPrompts() const;

#if 0
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FCArkPDAPageStationMapOv1 = PreyFunction<void(CArkPDAPageStationMap* const _this)>(0x142B9F0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageStationMap* const _this)>(0x142C610);
	static inline auto FUpdate = PreyFunction<void(CArkPDAPageStationMap* const _this, float _frameTime)>(0x142D250);
	static inline auto FClose = PreyFunction<void(CArkPDAPageStationMap* const _this)>(0x174AC00);
	static inline auto FOnClosePDA = PreyFunction<void(CArkPDAPageStationMap* const _this)>(0x9A07D0);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageStationMap* const _this, const CCryName& _rActionId, const int _activationMode, const float _fValue)>(0x142CC10);
	static inline auto FSetCurrentLocation = PreyFunction<void(const CArkPDAPageStationMap* const _this, uint64_t _locationId)>(0x142CD60);
	static inline auto FSetZoom = PreyFunction<void(CArkPDAPageStationMap* const _this, const float _zoomAmount)>(0x142CF20);
	static inline auto FOnPressMapObjective = PreyFunction<void(CArkPDAPageStationMap* const _this)>(0x142BD50);
	static inline auto FOnSelectLevel = PreyFunction<void(CArkPDAPageStationMap* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x142BDA0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageStationMap* const _this)>(0x142D0D0);
	static inline auto FUpdateInputPrompt = PreyFunction<void(const CArkPDAPageStationMap* const _this)>(0x142D2C0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const CArkPDAPageStationMap* const _this)>(0x1A302A0);
};
#endif // !MOONCRASH
