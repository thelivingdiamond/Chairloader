// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <_unknown/ArkUIMenuBase_CArkPDAPageNotes_.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagenotes.h
class CArkPDAPageNotes : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageNotes> // Id=801C431 Size=40
{
public:
	CArkPDAPageNotes();
	virtual ~CArkPDAPageNotes();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	void OnShowNote(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowNote(this,_pSender,_event,_args); }
	
#if 0
	void SelectNote(uint64_t arg0);
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageNotes *const _this)>(0x1629340);
	static inline auto FClose = PreyFunction<void(CArkPDAPageNotes *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageNotes const *const _this)>(0x16293A0);
	static inline auto FOnShowNote = PreyFunction<void(CArkPDAPageNotes *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1628FF0);
};

