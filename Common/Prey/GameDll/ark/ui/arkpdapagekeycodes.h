// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagekeycodes.h
#ifdef MOONCRASH
enum class ArkPDAPage;
#endif
class CArkPDAPageKeyCodes : public IArkPDAPage // Id=801CBD2 Size=16
{
public:
	CArkPDAPageKeyCodes();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	virtual ~CArkPDAPageKeyCodes();
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
#ifndef MOONCRASH
	static inline auto FOpen = PreyFunction<void(CArkPDAPageKeyCodes *const _this)>(0x12941A0);
	static inline auto FClose = PreyFunction<void(CArkPDAPageKeyCodes *const _this)>(0x1622B10);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageKeyCodes const *const _this)>(0x1622B40);
#else
	static inline auto FCArkPDAPageKeyCodesOv2 = PreyFunction<void(CArkPDAPageKeyCodes* const _this)>(0x17444F0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageKeyCodes* const _this)>(0x1338520);
	static inline auto FClose = PreyFunction<void(CArkPDAPageKeyCodes* const _this)>(0x1744540);
	static inline auto FRefresh = PreyFunction<void(const CArkPDAPageKeyCodes* const _this)>(0x1744570);
#endif
};
