// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagemetadata.h
class CArkPDAPageMetadata : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageMetadata> // Id=801BB94 Size=40
{
public:
	CArkPDAPageMetadata();
	virtual ~CArkPDAPageMetadata();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAPageMetadata *const _this)>(0x13760D0);
	static inline auto FClose = PreyFunction<void(CArkPDAPageMetadata *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageMetadata const *const _this)>(0x1376130);
};

