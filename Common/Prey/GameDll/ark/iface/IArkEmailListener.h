// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkEmailListener.h
class IArkEmailListener // Id=80154EF Size=8
{
public:
	virtual void OnEmailSentChanged(const uint64_t arg0);
	virtual void OnEmailRead(const uint64_t arg0);
	virtual void OnDownloadHiddenChanged(const uint64_t _id);
	
	static inline auto FOnDownloadHiddenChanged = PreyFunction<void(IArkEmailListener *const _this, const uint64_t _id)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkEmailListener
// Header:  Prey/GameDll/ark/iface/IArkEmailListener.h
class IArkEmailListener
{ // Size=8 (0x8)
public:
	virtual void OnEmailSentChanged(const uint64_t _arg0_);
	virtual void OnEmailRead(const uint64_t _arg0_);
	virtual void OnDownloadHiddenChanged(const uint64_t _id);

	static inline auto FOnDownloadHiddenChanged = PreyFunction<void(IArkEmailListener* const _this, const uint64_t _id)>(0x1333E90);
};
#endif // !MOONCRASH
