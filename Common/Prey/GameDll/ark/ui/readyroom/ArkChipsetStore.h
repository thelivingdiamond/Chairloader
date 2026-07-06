// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/IArkReadyRoomUI.h>

class ArkReadyRoomManager;
class CCryName;
enum class EArkReadyRoomPage;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkChipsetStore
// Header:  Prey/GameDll/ark/ui/readyroom/ArkChipsetStore.h
class ArkChipsetStore : public ArkUIMenuBase<ArkChipsetStore>, public IArkReadyRoomUI
{ // Size=72 (0x48)
public:
	// ArkChipsetStore::ChipsetEntry
	// Header:  Prey/GameDll/ark/ui/readyroom/ArkChipsetStore.h
	class ChipsetEntry
	{ // Size=48 (0x30)
	public:
		uint64_t m_archetype;
		wstring m_name;
		string m_icon;
		string m_description;
		IArkItem::EArkQualityTier m_qualityTier;
		float m_cryptoCost;
		bool m_bInCart;
		bool m_bNew;

	#if 0
		ChipsetEntry(uint64_t _arg0_, bool _arg1_);
		bool operator==(const uint64_t _arg0_) const;
		bool operator<(const ArkChipsetStore::ChipsetEntry& _arg0_) const;
	#endif
	};

	std::vector<ArkChipsetStore::ChipsetEntry> m_chipsets;
	int m_currentChipset;
	bool m_bFocusOnStore;
	ArkReadyRoomManager& m_readyRoomManager;

	ArkChipsetStore(ArkReadyRoomManager& _readyRoomManager);
	virtual ~ArkChipsetStore();
	virtual unsigned SetupInputPrompts(unsigned _startingIndex);
	virtual bool IsAvailable() const;
	virtual void Open();
	virtual bool ProcessInput(CCryName _action, int _activationMode, float _value);
	virtual void Close(bool _bImmediate, bool _bExitReadyRoom);
	virtual void Reset();
	virtual void OnLaunch();
	virtual const char* GetLabel() const;
	virtual void OnControlSchemeChanged() const;
	std::pair<float, unsigned int> GetCartCostAndCount() const { alignas(std::pair<float, unsigned int>) std::byte _return_buf_[sizeof(std::pair<float, unsigned int>)]; return *FGetCartCostAndCount(this, reinterpret_cast<std::pair<float, unsigned int>*>(_return_buf_)); }
	void ResetCart() { FResetCart(this); }
	void OnChipsetSelected(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnChipsetSelected(this, _pSender, _event, _args); }
	void OnChipsetHighlighted(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnChipsetHighlighted(this, _pSender, _event, _args); }
	void OnChipsetFocus(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnChipsetFocus(this, _pSender, _event, _args); }
	void SelectChipset(int _chipsetIndex) { FSelectChipset(this, _chipsetIndex); }
	void SelectCurrentChipset() { FSelectCurrentChipset(this); }
	void Refresh() { FRefresh(this); }
	void ConfirmReset() { FConfirmReset(this); }
	void UpdateChipsetDetails(const ArkChipsetStore::ChipsetEntry& _entry) const { FUpdateChipsetDetails(this, _entry); }

#if 0
	static EArkReadyRoomPage GetID();
	std::vector<uint64_t> GetStartingChipsets() const;
#endif

	static inline auto FArkChipsetStoreOv1 = PreyFunction<void(ArkChipsetStore* const _this, ArkReadyRoomManager& _readyRoomManager)>(0x1466560);
	static inline auto FSetupInputPrompts = PreyFunction<unsigned(IArkReadyRoomUI* const _this, unsigned _startingIndex)>(0x1468400);
	static inline auto FIsAvailable = PreyFunction<bool(const IArkReadyRoomUI* const _this)>(0x1466F10);
	static inline auto FOpen = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1467200);
	static inline auto FProcessInput = PreyFunction<bool(IArkReadyRoomUI* const _this, CCryName _action, int _activationMode, float _value)>(0x14672E0);
	static inline auto FClose = PreyFunction<void(IArkReadyRoomUI* const _this, bool _bImmediate, bool _bExitReadyRoom)>(0x1466940);
	static inline auto FReset = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1468080);
	static inline auto FOnLaunch = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x14670E0);
	static inline auto FGetLabel = PreyFunction<const char* (const IArkReadyRoomUI* const _this)>(0x1466F00);
	static inline auto FOnControlSchemeChanged = PreyFunction<void(const IArkReadyRoomUI* const _this)>(0x1467090);
	static inline auto FGetCartCostAndCount = PreyFunction<std::pair<float, unsigned int>*(const ArkChipsetStore* const _this, std::pair<float, unsigned int>* _return_value_)>(0x1466AC0);
	static inline auto FResetCart = PreyFunction<void(ArkChipsetStore* const _this)>(0x1468180);
	static inline auto FOnChipsetSelected = PreyFunction<void(ArkChipsetStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1467010);
	static inline auto FOnChipsetHighlighted = PreyFunction<void(ArkChipsetStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1466FA0);
	static inline auto FOnChipsetFocus = PreyFunction<void(ArkChipsetStore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1466F20);
	static inline auto FSelectChipset = PreyFunction<void(ArkChipsetStore* const _this, int _chipsetIndex)>(0x1468280);
	static inline auto FSelectCurrentChipset = PreyFunction<void(ArkChipsetStore* const _this)>(0x14683F0);
	static inline auto FRefresh = PreyFunction<void(ArkChipsetStore* const _this)>(0x1467420);
	static inline auto FConfirmReset = PreyFunction<void(ArkChipsetStore* const _this)>(0x14669A0);
	static inline auto FUpdateChipsetDetails = PreyFunction<void(const ArkChipsetStore* const _this, const ArkChipsetStore::ChipsetEntry& _entry)>(0x1468700);
};
#endif // MOONCRASH
