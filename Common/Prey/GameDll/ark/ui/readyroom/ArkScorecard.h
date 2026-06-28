// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/IArkReadyRoomMetaUI.h>

class ArkReadyRoomManager;
class CCryName;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkScorecard
// Header:  Prey/GameDll/ark/ui/readyroom/ArkScorecard.h
class ArkScorecard : public ArkUIMenuBase<ArkScorecard>, public IArkReadyRoomMetaUI
{ // Size=88 (0x58)
public:
	// ArkScorecard::ScorecardEntry
	// Header:  Prey/GameDll/ark/ui/readyroom/ArkScorecard.h
	class ScorecardEntry
	{ // Size=24 (0x18)
	public:
		string m_label;
		float m_snapshotTotal;
		float m_currentTotal;
		float m_cryptoEarned;

	#if 0
		ScorecardEntry(string _arg0_, float _arg1_, float _arg2_, float _arg3_);
	#endif
	};

	std::vector<ArkScorecard::ScorecardEntry> m_scorecardEntries;
	bool m_bAvailable;
	bool m_bPopup;
	bool m_bAnimating;
	bool m_bIgnoreInput;
	float m_totalCryptoEarned;
	float m_currentRunningTotal;
	ArkReadyRoomManager& m_readyRoomManager;
	float m_highlightTimer;
	bool m_bNeedHighlight;

	ArkScorecard(ArkReadyRoomManager& _readyRoomManager);
	virtual ~ArkScorecard();
	virtual void Open();
	virtual void Close();
	virtual void Reset();
	virtual bool ProcessInput(CCryName _action, int _activationMode, float _value);
	void Update(float _fDelta) { FUpdate(this, _fDelta); }
	void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(this, _pSender, _event, _args); }
	void OnAnimationComplete(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnAnimationComplete(this, _pSender, _event, _args); }
	void OnLineAnimated(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnLineAnimated(this, _pSender, _event, _args); }

#if 0
	void SetIsPopup(bool _arg0_);
	bool IsPopup() const;
	void SetIgnoreInput(bool _arg0_);
#endif

	static inline auto FArkScorecardOv1 = PreyFunction<void(ArkScorecard* const _this, ArkReadyRoomManager& _readyRoomManager)>(0x1478E30);
	static inline auto FOpen = PreyFunction<void(IArkReadyRoomMetaUI* const _this)>(0x1479320);
	static inline auto FClose = PreyFunction<void(IArkReadyRoomMetaUI* const _this)>(0x1479170);
	static inline auto FReset = PreyFunction<void(IArkReadyRoomMetaUI* const _this)>(0x147A0B0);
	static inline auto FProcessInput = PreyFunction<bool(IArkReadyRoomMetaUI* const _this, CCryName _action, int _activationMode, float _value)>(0x147A000);
	static inline auto FUpdate = PreyFunction<void(ArkScorecard* const _this, float _fDelta)>(0x147A280);
	static inline auto FOnButtonPress = PreyFunction<void(ArkScorecard* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1479230);
	static inline auto FOnAnimationComplete = PreyFunction<void(ArkScorecard* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14791D0);
	static inline auto FOnLineAnimated = PreyFunction<void(ArkScorecard* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1479240);
};
#endif // MOONCRASH
