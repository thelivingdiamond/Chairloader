// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <_unknown/ArkUIMenuBase.h>

enum class ArkPDAPage;
class CCryName;

// CArkPDAPageStatus
// Header:  Prey/GameDll/ark/ui/ArkPDAPageStatus.h
class CArkPDAPageStatus : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageStatus>
{ // Size=40 (0x28)
public:
	virtual void Open();
	virtual bool ProcessInput(const CCryName& _rActionId, const int _activationMode, const float _fValue);
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	void OnAbortSimulation() { FOnAbortSimulation(this); }
	void OnAbortSimulationConfirm() { FOnAbortSimulationConfirm(this); }

#if 0
	CArkPDAPageStatus();
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FOpen = PreyFunction<void(CArkPDAPageStatus* const _this)>(0x174EE00);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageStatus* const _this, const CCryName& _rActionId, const int _activationMode, const float _fValue)>(0x174F240);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const CArkPDAPageStatus* const _this)>(0x1A302A0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageStatus* const _this)>(0x174F270);
	static inline auto FOnAbortSimulation = PreyFunction<void(CArkPDAPageStatus* const _this)>(0x174ECA0);
	static inline auto FOnAbortSimulationConfirm = PreyFunction<void(CArkPDAPageStatus* const _this)>(0x174EDC0);
};
#endif // !MOONCRASH
