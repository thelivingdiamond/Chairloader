// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagelore.h
class CArkPDAPageLore : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageLore> // Id=801BB4D Size=40
{
public:
	CArkPDAPageLore();
	virtual ~CArkPDAPageLore();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	virtual bool HasNew() const;
	void OnShowLore(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowLore(this,_pSender,_event,_args); }
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageLore *const _this)>(0x1373D10);
	static inline auto FClose = PreyFunction<void(CArkPDAPageLore *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageLore const *const _this)>(0x1373D70);
	static inline auto FHasNew = PreyFunction<bool(CArkPDAPageLore const *const _this)>(0x1373910);
	static inline auto FOnShowLore = PreyFunction<void(CArkPDAPageLore *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1373950);
};

