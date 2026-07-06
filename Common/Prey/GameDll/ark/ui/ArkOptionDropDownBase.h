// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/ArkOptionLayout.h>
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/ArkOptionLayout.h>

class ArkOptionMenu;

// ArkOptionDropDownBase
// Header:  Prey/GameDll/ark/ui/ArkOptionDropDownBase.h
class ArkOptionDropDownBase : public ArkOptionWidgetBase
{ // Size=8 (0x8)
public:
	virtual std::vector<ArkOption>& GetDropDownOptions() = 0;
	virtual const std::vector<ArkOption>& GetDropDownOptions() const = 0;
	virtual int GetSelectedIndex(const char* const _cvarName) const = 0;
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	virtual bool RequiresConfirmation() const;
	virtual void RefreshOptions(const ArkOptionMenu& _optionMenu);
	virtual bool MustRefreshResolutions() const;

	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionDropDownBase* const _this)>(0x14B6CE0);
	static inline auto FRequiresConfirmation = PreyFunction<bool(const ArkOptionDropDownBase* const _this)>(0x1A302A0);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionDropDownBase* const _this, const ArkOptionMenu& _optionMenu)>(0x1333E90);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(const ArkOptionDropDownBase* const _this)>(0x13B0900);
};
#endif // !MOONCRASH
