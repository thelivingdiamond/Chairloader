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

