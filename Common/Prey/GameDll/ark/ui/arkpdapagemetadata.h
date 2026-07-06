// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <_unknown/ArkUIMenuBase.h>

enum class ArkPDAPage;
class CCryName;

// CArkPDAPageMetadata
// Header:  Prey/GameDll/ark/ui/ArkPDAPageMetadata.h
class CArkPDAPageMetadata : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageMetadata>
{ // Size=48 (0x30)
public:
	bool m_bShowingLifetime;

	CArkPDAPageMetadata();
	virtual ~CArkPDAPageMetadata();
	virtual bool ProcessInput(const CCryName& _rActionId, const int _activationMode, const float _fValue);
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	void OnPressUse() { FOnPressUse(this); }
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;

#if 0
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FCArkPDAPageMetadataOv1 = PreyFunction<void(CArkPDAPageMetadata* const _this)>(0x1458C50);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageMetadata* const _this, const CCryName& _rActionId, const int _activationMode, const float _fValue)>(0x14590B0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const CArkPDAPageMetadata* const _this)>(0x1A302A0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageMetadata* const _this)>(0x1459520);
	static inline auto FOnPressUse = PreyFunction<void(CArkPDAPageMetadata* const _this)>(0x1458EC0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageMetadata* const _this)>(0x1459050);
	static inline auto FClose = PreyFunction<void(CArkPDAPageMetadata* const _this)>(0x174AC00);
	static inline auto FRefresh = PreyFunction<void(const CArkPDAPageMetadata* const _this)>(0x14590E0);
};
#endif // !MOONCRASH
