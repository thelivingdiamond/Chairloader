// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkDialogAudioTrigger.h>
#include <Prey/CryCore/functor.h>
#include <Prey/GameDll/ark/dialog/IArkDialogAudioTriggerOwner.h>
#include <Prey/GameDll/ark/ui/ArkNoteUI.h>

class ArkCardTutorial;
struct IUIElement;

// Header: Exact
// Prey/GameDll/ark/ui/ArkTutorialCardUI.h
class ArkTutorialCardUI : public ArkNoteUI, public IArkDialogAudioTriggerOwner // Id=8019130 Size=808
{
public:
	using TutorialCallback = Functor0;
	
	bool m_bResetClosed;
	Functor0 m_cardCallback;
	ArkDialogAudioTrigger m_dialogTrigger;
	
	virtual ~ArkTutorialCardUI();
	virtual const char *GetTypeName() const;
	virtual void Init();
	void Open(ArkCardTutorial const *_pTutorialCard, wstring const &_body) { FOpen(this,_pTutorialCard,_body); }
	void SetCallback(Functor0 _callback) { FSetCallback(this,_callback); }
	void Refresh(wstring const &_body) { FRefresh(this,_body); }
	virtual void Close(bool _bImmediate);
	virtual IUIElement *GetUIElement() const;
	virtual void OnTriggerLoaded(ArkDialogAudioTrigger const *_pTrigger, bool _bSuccess);
	virtual void OnTriggerCutoff(ArkDialogAudioTrigger const *_pTrigger);
	virtual void OnTriggerFinished(ArkDialogAudioTrigger const *_pTrigger);
	virtual void CleanupClose();
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkTutorialCardUI const *const _this)>(0x16337A0);
	static inline auto FInit = PreyFunction<void(ArkTutorialCardUI *const _this)>(0x16337D0);
	static inline auto FOpen = PreyFunction<void(ArkTutorialCardUI *const _this, ArkCardTutorial const *_pTutorialCard, wstring const &_body)>(0x1633840);
	static inline auto FSetCallback = PreyFunction<void(ArkTutorialCardUI *const _this, Functor0 _callback)>(0x1633BB0);
	static inline auto FRefresh = PreyFunction<void(ArkTutorialCardUI *const _this, wstring const &_body)>(0x1633A10);
	static inline auto FClose = PreyFunction<void(ArkTutorialCardUI *const _this, bool _bImmediate)>(0x1633600);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(ArkTutorialCardUI const *const _this)>(0x16337B0);
	static inline auto FOnTriggerLoaded = PreyFunction<void(ArkTutorialCardUI *const _this, ArkDialogAudioTrigger const *_pTrigger, bool _bSuccess)>(0x1633800);
	static inline auto FOnTriggerCutoff = PreyFunction<void(ArkTutorialCardUI *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0xA13080);
	static inline auto FOnTriggerFinished = PreyFunction<void(ArkTutorialCardUI *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0xA13080);
	static inline auto FCleanupClose = PreyFunction<void(ArkTutorialCardUI *const _this)>(0x1633540);
};

