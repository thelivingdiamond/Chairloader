// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagestatus.h
class CArkPDAPageStatus : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageStatus> // Id=801CBF9 Size=40
{
public:
	virtual void Open();
	virtual ~CArkPDAPageStatus();
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageStatus *const _this)>(0x162C960);
};

