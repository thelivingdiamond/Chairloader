// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapageemails.h
class CArkPDAPageEmails : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageEmails> // Id=801CC3F Size=40
{
public:
	CArkPDAPageEmails();
	virtual ~CArkPDAPageEmails();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	void OnShowEmail(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowEmail(this,_pSender,_event,_args); }
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageEmails *const _this)>(0x1642520);
	static inline auto FClose = PreyFunction<void(CArkPDAPageEmails *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageEmails const *const _this)>(0x1642580);
	static inline auto FOnShowEmail = PreyFunction<void(CArkPDAPageEmails *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1642290);
};

