// Split out of PlayerVisTable.h: SDeferredLinetestBuffer embeds it by value and is included before CPlayerVisTable.
#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>

struct RayCastResult;

// SDeferredLinetestReceiver
// Header:  Prey/GameDll/PlayerVisTable.h
struct SDeferredLinetestReceiver
{ // Size=8 (0x8)
	unsigned queuedRayID;
	int16_t visTableIndex;
	int8_t visBufferIndex;

	~SDeferredLinetestReceiver();
	void OnDataReceived(const unsigned& rayID, const RayCastResult& result) { FOnDataReceived(this, rayID, result); }
	void CancelPendingRay() { FCancelPendingRay(this); }

#if 0
	SDeferredLinetestReceiver();
	void SetFree();
	bool IsFree();
	void SetInvalid();
	bool IsValid();
#endif

#ifndef MOONCRASH
	static inline auto FBitNotSDeferredLinetestReceiver = PreyFunction<void(SDeferredLinetestReceiver* const _this)>(0x17C54C0);
	static inline auto FOnDataReceived = PreyFunction<void(SDeferredLinetestReceiver* const _this, const unsigned& rayID, const RayCastResult& result)>(0x17C5B60);
	static inline auto FCancelPendingRay = PreyFunction<void(SDeferredLinetestReceiver* const _this)>(0x1795D00);
#else
	static inline auto FBitNotSDeferredLinetestReceiver = PreyFunction<void(SDeferredLinetestReceiver* const _this)>(0x18EC800);
	static inline auto FOnDataReceived = PreyFunction<void(SDeferredLinetestReceiver* const _this, const unsigned& rayID, const RayCastResult& result)>(0x18ECEA0);
	static inline auto FCancelPendingRay = PreyFunction<void(SDeferredLinetestReceiver* const _this)>(0x18BC640);
#endif
};


