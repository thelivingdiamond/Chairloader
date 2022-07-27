// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkPsiPowerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

class CArkItem;
class CCryName;
struct IUIElement;
struct SActionMapEvent;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkQuickSelectComponent.h
class ArkQuickSelectComponent : public IUIControlSchemeListener, public IArkInventoryListener, public IArkPsiPowerListener, public IActionMapEventListener // Id=8016F75 Size=408
{
public:
	enum class QuickSelectType
	{
		power = 0,
		weapon = 1,
		last = 2,
	};

	struct QuickSelectId // Id=8016FA3 Size=24
	{
		ArkQuickSelectComponent::QuickSelectType m_type;
		boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> m_id;
		
		void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
		void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this,_ser); }
		string GetIdString() const { return FGetIdString(this); }
		bool CanSelect() const { return FCanSelect(this); }
		
#if 0
		bool operator==(ArkQuickSelectComponent::QuickSelectId const &arg0) const;
		bool operator==(boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &arg0);
#endif
		
		static inline auto FSerialize = PreyFunction<void(ArkQuickSelectComponent::QuickSelectId *const _this, TSerialize _ser)>(0x130A480);
		static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkQuickSelectComponent::QuickSelectId *const _this, TSerialize _ser)>(0x130ACC0);
		static inline auto FGetIdString = PreyFunction<string(ArkQuickSelectComponent::QuickSelectId const *const _this)>(0x13088F0);
		static inline auto FCanSelect = PreyFunction<bool(ArkQuickSelectComponent::QuickSelectId const *const _this)>(0x1308300);
	};

	std::array<ArkQuickSelectComponent::QuickSelectId,4> m_controllerQuickSelects;
	std::array<ArkQuickSelectComponent::QuickSelectId,10> m_keyboardQuickSelects;
	bool m_bQuickSelectControllerOpen;
	bool m_bQuickSelectKeyboardOpen;
	ArkSimpleTimer m_quickSelectTimer;
	int m_heldQuickSelectIndex;
	ArkAutoResetTimer m_holdQuickSelectTimer;
	ArkAudioTrigger m_useFailedTrigger;
	ArkAudioTrigger m_assignTrigger;
	ArkAudioTrigger m_selectTrigger;
	ArkAudioTrigger m_errorTrigger;
	
	ArkQuickSelectComponent();
	void Release() { FRelease(this); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnItemAdded(unsigned _entityId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _entityId);
	virtual void OnItemCountChanged(unsigned _itemId);
	virtual void OnPowerAcquired(EArkPsiPowers _power);
	virtual void OnActionMapEvent(SActionMapEvent const &_event);
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this,_ser); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Reset() { FReset(this); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _fValue) { FProcessInput(this,_actionId,_activationMode,_fValue); }
	void OpenQuickSelect(bool _bTimed) { FOpenQuickSelect(this,_bTimed); }
	void CloseQuickSelect() { FCloseQuickSelect(this); }
	bool CanQuickSelect(CArkItem const &_item) const { return FCanQuickSelect(this,_item); }
	bool AssignQuickSelect(CArkItem const &_item, CCryName const &_actionId) { return FAssignQuickSelectOv1(this,_item,_actionId); }
	bool AssignQuickSelect(ArkQuickSelectComponent::QuickSelectType _type, boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id, CCryName const &_actionId) { return FAssignQuickSelectOv0(this,_type,_id,_actionId); }
	void ClearQuickSelect(CArkItem const &_item, IUIElement *_pUIElement) { FClearQuickSelect(this,_item,_pUIElement); }
	void UpdateAllSelectionsUI(IUIElement *_pUIElement) const { FUpdateAllSelectionsUI(this,_pUIElement); }
	string GetQuickSelectUIIndex(CArkItem const &_item) const { return FGetQuickSelectUIIndexOv1(this,_item); }
	string GetQuickSelectUIIndex(boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id) const { return FGetQuickSelectUIIndexOv0(this,_id); }
	void AddToQuickSelect(CArkItem const &_item) { FAddToQuickSelect(this,_item); }
	void RefreshFilterFeedback() { FRefreshFilterFeedback(this); }
	static int GetQuickSelectIndexFromActionId(CCryName const &_actionId) { return FGetQuickSelectIndexFromActionId(_actionId); }
	void OpenControllerQuickSelect(bool _bTimed) { FOpenControllerQuickSelect(this,_bTimed); }
	void OpenKeyboardQuickSelect(bool _bTimed) { FOpenKeyboardQuickSelect(this,_bTimed); }
	int GetControllerIndex(boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id) const { return FGetControllerIndex(this,_id); }
	int GetKeyboardIndex(boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id) const { return FGetKeyboardIndex(this,_id); }
	string GetKeyboardUIIndex(const int _index) const { return FGetKeyboardUIIndex(this,_index); }
	void ActivateSelection(ArkQuickSelectComponent::QuickSelectId const &_selection) { FActivateSelection(this,_selection); }
	void UpdateSelectionUI(IUIElement *_pUIElement, ArkQuickSelectComponent::QuickSelectId const &_selection, int _index) const { FUpdateSelectionUI(this,_pUIElement,_selection,_index); }
	void TryUpdateAmmoCount(CArkItem const &_item) { FTryUpdateAmmoCount(this,_item); }
	
#if 0
	void SetQuickSelectTimeout(float arg0);
	bool IsQuickSelectOpen() const;
	static boost::variant<unsigned int,unsigned __int64> GetIdentifier(CArkItem const &arg0);
	static ArkQuickSelectComponent::QuickSelectType GetType(CArkItem const &arg0);
	ArkQuickSelectComponent::QuickSelectId GetQuickSelectAtIndex(int arg0) const;
	static bool IsKeyboard();
#endif
	
	static inline auto FRelease = PreyFunction<void(ArkQuickSelectComponent *const _this)>(0x130A300);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkQuickSelectComponent *const _this, EControlScheme _controlScheme)>(0x1309190);
	static inline auto FOnItemAdded = PreyFunction<void(ArkQuickSelectComponent *const _this, unsigned _entityId, unsigned _originalId)>(0x13091A0);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkQuickSelectComponent *const _this, unsigned _entityId)>(0x1309300);
	static inline auto FOnItemCountChanged = PreyFunction<void(ArkQuickSelectComponent *const _this, unsigned _itemId)>(0x13091D0);
	static inline auto FOnPowerAcquired = PreyFunction<void(ArkQuickSelectComponent *const _this, EArkPsiPowers _power)>(0x1309370);
	static inline auto FOnActionMapEvent = PreyFunction<void(ArkQuickSelectComponent *const _this, SActionMapEvent const &_event)>(0x1309180);
	static inline auto FSerialize = PreyFunction<void(ArkQuickSelectComponent *const _this, TSerialize _ser)>(0x130A430);
	static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkQuickSelectComponent *const _this, TSerialize _ser)>(0x130A780);
	static inline auto FUpdate = PreyFunction<void(ArkQuickSelectComponent *const _this, float _frameTime)>(0x130B160);
	static inline auto FReset = PreyFunction<void(ArkQuickSelectComponent *const _this)>(0x130A350);
	static inline auto FProcessInput = PreyFunction<void(ArkQuickSelectComponent *const _this, CCryName const &_actionId, const int _activationMode, const float _fValue)>(0x1309D30);
	static inline auto FOpenQuickSelect = PreyFunction<void(ArkQuickSelectComponent *const _this, bool _bTimed)>(0x1309D00);
	static inline auto FCloseQuickSelect = PreyFunction<void(ArkQuickSelectComponent *const _this)>(0x13086A0);
	static inline auto FCanQuickSelect = PreyFunction<bool(ArkQuickSelectComponent const *const _this, CArkItem const &_item)>(0x13082C0);
	static inline auto FAssignQuickSelectOv1 = PreyFunction<bool(ArkQuickSelectComponent *const _this, CArkItem const &_item, CCryName const &_actionId)>(0x1307EE0);
	static inline auto FAssignQuickSelectOv0 = PreyFunction<bool(ArkQuickSelectComponent *const _this, ArkQuickSelectComponent::QuickSelectType _type, boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id, CCryName const &_actionId)>(0x1308080);
	static inline auto FClearQuickSelect = PreyFunction<void(ArkQuickSelectComponent *const _this, CArkItem const &_item, IUIElement *_pUIElement)>(0x1308360);
	static inline auto FUpdateAllSelectionsUI = PreyFunction<void(ArkQuickSelectComponent const *const _this, IUIElement *_pUIElement)>(0x130B6C0);
	static inline auto FGetQuickSelectUIIndexOv1 = PreyFunction<string(ArkQuickSelectComponent const *const _this, CArkItem const &_item)>(0x1309040);
	static inline auto FGetQuickSelectUIIndexOv0 = PreyFunction<string(ArkQuickSelectComponent const *const _this, boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id)>(0x1308ED0);
	static inline auto FAddToQuickSelect = PreyFunction<void(ArkQuickSelectComponent *const _this, CArkItem const &_item)>(0x1307C20);
	static inline auto FRefreshFilterFeedback = PreyFunction<void(ArkQuickSelectComponent *const _this)>(0x130A0E0);
	static inline auto FGetQuickSelectIndexFromActionId = PreyFunction<int(CCryName const &_actionId)>(0x1308DC0);
	static inline auto FOpenControllerQuickSelect = PreyFunction<void(ArkQuickSelectComponent *const _this, bool _bTimed)>(0x1309550);
	static inline auto FOpenKeyboardQuickSelect = PreyFunction<void(ArkQuickSelectComponent *const _this, bool _bTimed)>(0x1309640);
	static inline auto FGetControllerIndex = PreyFunction<int(ArkQuickSelectComponent const *const _this, boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id)>(0x1308720);
	static inline auto FGetKeyboardIndex = PreyFunction<int(ArkQuickSelectComponent const *const _this, boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> const &_id)>(0x1308A10);
	static inline auto FGetKeyboardUIIndex = PreyFunction<string(ArkQuickSelectComponent const *const _this, const int _index)>(0x1308BE0);
	static inline auto FActivateSelection = PreyFunction<void(ArkQuickSelectComponent *const _this, ArkQuickSelectComponent::QuickSelectId const &_selection)>(0x1307B30);
	static inline auto FUpdateSelectionUI = PreyFunction<void(ArkQuickSelectComponent const *const _this, IUIElement *_pUIElement, ArkQuickSelectComponent::QuickSelectId const &_selection, int _index)>(0x130B7A0);
	static inline auto FTryUpdateAmmoCount = PreyFunction<void(ArkQuickSelectComponent *const _this, CArkItem const &_item)>(0x130B020);
};

