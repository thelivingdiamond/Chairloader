// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkPsiPowerListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

class CArkItem;
class CCryName;
enum class EArkPsiPowers;
enum EControlScheme;
struct IUIElement;
struct SActionMapEvent;

// ArkQuickSelectComponent
// Header:  Prey/GameDll/ark/player/ArkQuickSelectComponent.h
class ArkQuickSelectComponent
	: public IUIControlSchemeListener
	, public IArkInventoryListener
	, public IArkPsiPowerListener
	, public IActionMapEventListener
{ // Size=408 (0x198)
public:
	enum class QuickSelectType
	{
		power = 0,
		weapon = 1,
		last = 2,
	};

	// ArkQuickSelectComponent::QuickSelectId
	// Header:  Prey/GameDll/ark/player/ArkQuickSelectComponent.h
	struct QuickSelectId
	{ // Size=24 (0x18)
		ArkQuickSelectComponent::QuickSelectType m_type;
		boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64> m_id;

		void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
		void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this, _ser); }
		string GetIdString() const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetIdString(this, reinterpret_cast<string*>(_return_buf_)); }
		bool CanSelect() const { return FCanSelect(this); }

	#if 0
		QuickSelectId();
		QuickSelectId(ArkQuickSelectComponent::QuickSelectType _arg0_, const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _arg1_);
		bool operator==(const ArkQuickSelectComponent::QuickSelectId& _arg0_) const;
		bool operator==(const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _arg0_);
	#endif

		static inline auto FSerialize = PreyFunction<void(ArkQuickSelectComponent::QuickSelectId* const _this, TSerialize _ser)>(0x130A480);
		static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkQuickSelectComponent::QuickSelectId* const _this, TSerialize _ser)>(0x130ACC0);
		static inline auto FGetIdString = PreyFunction<string*(const ArkQuickSelectComponent::QuickSelectId* const _this, string* _return_value_)>(0x13088F0);
		static inline auto FCanSelect = PreyFunction<bool(const ArkQuickSelectComponent::QuickSelectId* const _this)>(0x1308300);
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
	virtual ~ArkQuickSelectComponent();
	void Release() { FRelease(this); }
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual void OnItemAdded(unsigned _entityId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _entityId);
	virtual void OnItemCountChanged(unsigned _itemId);
	virtual void OnPowerAcquired(EArkPsiPowers _power);
	virtual void OnActionMapEvent(const SActionMapEvent& _event);
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this, _ser); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Reset() { FReset(this); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _fValue) { FProcessInput(this, _actionId, _activationMode, _fValue); }
	void OpenQuickSelect(bool _bTimed) { FOpenQuickSelect(this, _bTimed); }
	void CloseQuickSelect() { FCloseQuickSelect(this); }
	bool CanQuickSelect(const CArkItem& _item) const { return FCanQuickSelect(this, _item); }
	bool AssignQuickSelect(const CArkItem& _item, const CCryName& _actionId) { return FAssignQuickSelectOv1(this, _item, _actionId); }
	bool AssignQuickSelect(ArkQuickSelectComponent::QuickSelectType _type, const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id, const CCryName& _actionId) { return FAssignQuickSelectOv0(this, _type, _id, _actionId); }
	void ClearQuickSelect(const CArkItem& _item, IUIElement* _pUIElement) { FClearQuickSelect(this, _item, _pUIElement); }
	void UpdateAllSelectionsUI(IUIElement* _pUIElement) const { FUpdateAllSelectionsUI(this, _pUIElement); }
	string GetQuickSelectUIIndex(const CArkItem& _item) const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetQuickSelectUIIndexOv1(this, reinterpret_cast<string*>(_return_buf_), _item); }
	string GetQuickSelectUIIndex(const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id) const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetQuickSelectUIIndexOv0(this, reinterpret_cast<string*>(_return_buf_), _id); }
	void AddToQuickSelect(const CArkItem& _item) { FAddToQuickSelect(this, _item); }
	void RefreshFilterFeedback() { FRefreshFilterFeedback(this); }
	static int GetQuickSelectIndexFromActionId(const CCryName& _actionId) { return FGetQuickSelectIndexFromActionId(_actionId); }
	void OpenControllerQuickSelect(bool _bTimed) { FOpenControllerQuickSelect(this, _bTimed); }
	void OpenKeyboardQuickSelect(bool _bTimed) { FOpenKeyboardQuickSelect(this, _bTimed); }
	int GetControllerIndex(const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id) const { return FGetControllerIndex(this, _id); }
	int GetKeyboardIndex(const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id) const { return FGetKeyboardIndex(this, _id); }
	string GetKeyboardUIIndex(const int _index) const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetKeyboardUIIndex(this, reinterpret_cast<string*>(_return_buf_), _index); }
	void ActivateSelection(const ArkQuickSelectComponent::QuickSelectId& _selection) { FActivateSelection(this, _selection); }
	void UpdateSelectionUI(IUIElement* _pUIElement, const ArkQuickSelectComponent::QuickSelectId& _selection, int _index) const { FUpdateSelectionUI(this, _pUIElement, _selection, _index); }
	void TryUpdateAmmoCount(const CArkItem& _item) { FTryUpdateAmmoCount(this, _item); }

#if 0
	void SetQuickSelectTimeout(float _arg0_);
	bool IsQuickSelectOpen() const;
	static boost::variant<unsigned int,unsigned __int64> GetIdentifier(const CArkItem& _arg0_);
	static ArkQuickSelectComponent::QuickSelectType GetType(const CArkItem& _arg0_);
	ArkQuickSelectComponent::QuickSelectId GetQuickSelectAtIndex(int _arg0_) const;
	static bool IsKeyboard();
#endif

	static inline auto FArkQuickSelectComponentOv1 = PreyFunction<void(ArkQuickSelectComponent* const _this)>(0x13074E0);
	static inline auto FRelease = PreyFunction<void(ArkQuickSelectComponent* const _this)>(0x130A300);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkQuickSelectComponent* const _this, const EControlScheme _controlScheme)>(0x1309190);
	static inline auto FOnItemAdded = PreyFunction<void(IArkInventoryListener* const _this, unsigned _entityId, unsigned _originalId)>(0x13091A0);
	static inline auto FOnItemRemoved = PreyFunction<void(IArkInventoryListener* const _this, unsigned _entityId)>(0x1309300);
	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId)>(0x13091D0);
	static inline auto FOnPowerAcquired = PreyFunction<void(IArkPsiPowerListener* const _this, EArkPsiPowers _power)>(0x1309370);
	static inline auto FOnActionMapEvent = PreyFunction<void(IActionMapEventListener* const _this, const SActionMapEvent& _event)>(0x1309180);
	static inline auto FSerialize = PreyFunction<void(ArkQuickSelectComponent* const _this, TSerialize _ser)>(0x130A430);
	static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkQuickSelectComponent* const _this, TSerialize _ser)>(0x130A780);
	static inline auto FUpdate = PreyFunction<void(ArkQuickSelectComponent* const _this, float _frameTime)>(0x130B160);
	static inline auto FReset = PreyFunction<void(ArkQuickSelectComponent* const _this)>(0x130A350);
	static inline auto FProcessInput = PreyFunction<void(ArkQuickSelectComponent* const _this, const CCryName& _actionId, const int _activationMode, const float _fValue)>(0x1309D30);
	static inline auto FOpenQuickSelect = PreyFunction<void(ArkQuickSelectComponent* const _this, bool _bTimed)>(0x1309D00);
	static inline auto FCloseQuickSelect = PreyFunction<void(ArkQuickSelectComponent* const _this)>(0x13086A0);
	static inline auto FCanQuickSelect = PreyFunction<bool(const ArkQuickSelectComponent* const _this, const CArkItem& _item)>(0x13082C0);
	static inline auto FAssignQuickSelectOv1 = PreyFunction<bool(ArkQuickSelectComponent* const _this, const CArkItem& _item, const CCryName& _actionId)>(0x1307EE0);
	static inline auto FAssignQuickSelectOv0 = PreyFunction<bool(ArkQuickSelectComponent* const _this, ArkQuickSelectComponent::QuickSelectType _type, const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id, const CCryName& _actionId)>(0x1308080);
	static inline auto FClearQuickSelect = PreyFunction<void(ArkQuickSelectComponent* const _this, const CArkItem& _item, IUIElement* _pUIElement)>(0x1308360);
	static inline auto FUpdateAllSelectionsUI = PreyFunction<void(const ArkQuickSelectComponent* const _this, IUIElement* _pUIElement)>(0x130B6C0);
	static inline auto FGetQuickSelectUIIndexOv1 = PreyFunction<string*(const ArkQuickSelectComponent* const _this, string* _return_value_, const CArkItem& _item)>(0x1309040);
	static inline auto FGetQuickSelectUIIndexOv0 = PreyFunction<string*(const ArkQuickSelectComponent* const _this, string* _return_value_, const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id)>(0x1308ED0);
	static inline auto FAddToQuickSelect = PreyFunction<void(ArkQuickSelectComponent* const _this, const CArkItem& _item)>(0x1307C20);
	static inline auto FRefreshFilterFeedback = PreyFunction<void(ArkQuickSelectComponent* const _this)>(0x130A0E0);
	static inline auto FGetQuickSelectIndexFromActionId = PreyFunction<int(const CCryName& _actionId)>(0x1308DC0);
	static inline auto FOpenControllerQuickSelect = PreyFunction<void(ArkQuickSelectComponent* const _this, bool _bTimed)>(0x1309550);
	static inline auto FOpenKeyboardQuickSelect = PreyFunction<void(ArkQuickSelectComponent* const _this, bool _bTimed)>(0x1309640);
	static inline auto FGetControllerIndex = PreyFunction<int(const ArkQuickSelectComponent* const _this, const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id)>(0x1308720);
	static inline auto FGetKeyboardIndex = PreyFunction<int(const ArkQuickSelectComponent* const _this, const boost::variant<unsigned int,enum EArkPsiPowers,unsigned __int64>& _id)>(0x1308A10);
	static inline auto FGetKeyboardUIIndex = PreyFunction<string*(const ArkQuickSelectComponent* const _this, string* _return_value_, const int _index)>(0x1308BE0);
	static inline auto FActivateSelection = PreyFunction<void(ArkQuickSelectComponent* const _this, const ArkQuickSelectComponent::QuickSelectId& _selection)>(0x1307B30);
	static inline auto FUpdateSelectionUI = PreyFunction<void(const ArkQuickSelectComponent* const _this, IUIElement* _pUIElement, const ArkQuickSelectComponent::QuickSelectId& _selection, int _index)>(0x130B7A0);
	static inline auto FTryUpdateAmmoCount = PreyFunction<void(ArkQuickSelectComponent* const _this, const CArkItem& _item)>(0x130B020);
};

