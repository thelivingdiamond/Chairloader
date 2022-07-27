// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkObjectiveTask;
class CCryName;
struct ICVar;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagelevelmap.h
class CArkPDAPageLevelMap : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageLevelMap> // Id=801CBD6 Size=136
{
public:
	enum class EArkFogUpdateState
	{
		invalid = 0,
		calculate = 1,
		send = 2,
		icons = 3,
	};

	Vec2 m_panDelta;
	float m_zoom;
	float m_zoomDelta;
	int m_CurrentMapIndex;
	unsigned m_fogFloorIdx;
	unsigned m_nLastTileSent;
	std::vector<unsigned char> m_fogFloors;
	CArkPDAPageLevelMap::EArkFogUpdateState m_fogState;
	std::vector<unsigned char> m_fogData;
	ICVar *m_pFlashMapFog;
	
	CArkPDAPageLevelMap();
	virtual ~CArkPDAPageLevelMap();
	void Reload() { FReload(this); }
	virtual void Open();
	virtual void Update(float _frameTime);
	virtual void Close();
	virtual bool ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue);
	void ShowTaskMarker(ArkObjectiveTask const &_task) { FShowTaskMarker(this,_task); }
	void OnOpenPDA() { FOnOpenPDA(this); }
	virtual void OnClosePDA();
	void OnShowLevel(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowLevel(this,_pSender,_event,_args); }
	void ShowIcons() { FShowIcons(this); }
	void UpdateFog() { FUpdateFog(this); }
	virtual void SetupInputPrompts();
	virtual bool ManagesInputPrompts() const;
	void UpdateInputPrompt(const bool _bUpdateUI) const { FUpdateInputPrompt(this,_bUpdateUI); }
	
#if 0
	static ArkPDAPage GetPDAPage();
	void ClearIcons();
	bool IsFogLoaded(const uint8_t arg0);
	void PrioritizeFogUpdateQueue(const uint8_t arg0, const uint8_t arg1);
	static float GetUIRotation(Vec3 const &arg0);
#endif
	
	static inline auto FReload = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1625B20);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x16253D0);
	static inline auto FUpdate = PreyFunction<void(CArkPDAPageLevelMap *const _this, float _frameTime)>(0x1627870);
	static inline auto FClose = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1624E50);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageLevelMap *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x1625880);
	static inline auto FShowTaskMarker = PreyFunction<void(CArkPDAPageLevelMap *const _this, ArkObjectiveTask const &_task)>(0x16276A0);
	static inline auto FOnOpenPDA = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1624EE0);
	static inline auto FOnClosePDA = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1624EA0);
	static inline auto FOnShowLevel = PreyFunction<void(CArkPDAPageLevelMap *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1625290);
	static inline auto FShowIcons = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1626290);
	static inline auto FUpdateFog = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1627990);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageLevelMap *const _this)>(0x1626180);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageLevelMap const *const _this)>(0x1B933B0);
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkPDAPageLevelMap const *const _this, const bool _bUpdateUI)>(0x1627F10);
};

