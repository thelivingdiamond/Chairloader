// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagemainmenu.h
class CArkPDAPageMainMenu : public IArkPDAPage // Id=801CBD3 Size=16
{
public:
	virtual void Open();
	virtual void SetupInputPrompts();
	virtual bool ManagesInputPrompts() const;
	virtual ~CArkPDAPageMainMenu();
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageMainMenu *const _this)>(0x16285D0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageMainMenu *const _this)>(0x1628720);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageMainMenu const *const _this)>(0x1B933B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>

enum class ArkPDAPage;

// CArkPDAPageMainMenu
// Header:  Prey/GameDll/ark/ui/ArkPDAPageMainMenu.h
class CArkPDAPageMainMenu : public IArkPDAPage
{ // Size=16 (0x10)
public:
	virtual void Open();
	virtual void SetupInputPrompts();
	virtual bool ManagesInputPrompts() const;

#if 0
	CArkPDAPageMainMenu();
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FOpen = PreyFunction<void(CArkPDAPageMainMenu* const _this)>(0x174A190);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageMainMenu* const _this)>(0x174A2E0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const CArkPDAPageMainMenu* const _this)>(0x1A302A0);
};
#endif // !MOONCRASH
