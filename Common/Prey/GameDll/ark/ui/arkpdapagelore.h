// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <_unknown/ArkUIMenuBase.h>

enum class ArkPDAPage;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// CArkPDAPageLore
// Header:  Prey/GameDll/ark/ui/ArkPDAPageLore.h
class CArkPDAPageLore : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageLore>
{ // Size=40 (0x28)
public:
	CArkPDAPageLore();
	virtual ~CArkPDAPageLore();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	virtual bool HasNew() const;
	void OnShowLore(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnShowLore(this, _pSender, _event, _args); }

#if 0
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FCArkPDAPageLoreOv1 = PreyFunction<void(CArkPDAPageLore* const _this)>(0x1456780);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageLore* const _this)>(0x1456E80);
	static inline auto FClose = PreyFunction<void(CArkPDAPageLore* const _this)>(0x174AC00);
	static inline auto FRefresh = PreyFunction<void(const CArkPDAPageLore* const _this)>(0x1456EE0);
	static inline auto FHasNew = PreyFunction<bool(const CArkPDAPageLore* const _this)>(0x1456A70);
	static inline auto FOnShowLore = PreyFunction<void(CArkPDAPageLore* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1456AB0);
};
#endif // !MOONCRASH
