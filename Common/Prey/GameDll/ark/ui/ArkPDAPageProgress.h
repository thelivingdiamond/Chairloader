// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <_unknown/ArkUIMenuBase.h>

enum class ArkPDAPage;

// CArkPDAPageProgress
// Header:  Prey/GameDll/ark/ui/ArkPDAPageProgress.h
class CArkPDAPageProgress : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageProgress>
{ // Size=40 (0x28)
public:
	virtual void Open();
	virtual bool HasNew() const;

#if 0
	CArkPDAPageProgress();
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FOpen = PreyFunction<void(CArkPDAPageProgress* const _this)>(0x1429520);
	static inline auto FHasNew = PreyFunction<bool(const CArkPDAPageProgress* const _this)>(0x14294F0);
};
#endif // MOONCRASH
