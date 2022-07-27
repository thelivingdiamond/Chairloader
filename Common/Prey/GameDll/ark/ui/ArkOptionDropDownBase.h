// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/arkoptionlayout.h>

class ArkOptionMenu;

// Prey/GameDll/ark/ui/ArkOptionDropDownBase.h
class ArkOptionDropDownBase : public ArkOptionWidgetBase // Id=801B99D Size=8
{
public:
	virtual std::vector<ArkOption> &GetDropDownOptions() = 0;
	virtual std::vector<ArkOption> const &GetDropDownOptions() const = 0;
	virtual int GetSelectedIndex(const char *const arg0) const = 0;
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	virtual bool RequiresConfirmation() const;
	virtual void RefreshOptions(ArkOptionMenu const &_optionMenu);
	virtual bool MustRefreshResolutions() const;
	
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionDropDownBase const *const _this)>(0x1C4890);
	static inline auto FRequiresConfirmation = PreyFunction<bool(ArkOptionDropDownBase const *const _this)>(0x1B933B0);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionDropDownBase *const _this, ArkOptionMenu const &_optionMenu)>(0xA13080);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(ArkOptionDropDownBase const *const _this)>(0xDD23F0);
};

