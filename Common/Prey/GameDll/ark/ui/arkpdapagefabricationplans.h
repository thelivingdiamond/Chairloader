// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagefabricationplans.h
class CArkPDAFabricationPlans : public IArkPDAPage, public ArkUIMenuBase<CArkPDAFabricationPlans> // Id=801CC1C Size=48
{
public:
	uint64_t m_selectedPlanId;
	
	CArkPDAFabricationPlans();
	virtual ~CArkPDAFabricationPlans();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	void OnShowPlan(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowPlan(this,_pSender,_event,_args); }
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FOpen = PreyFunction<void(CArkPDAFabricationPlans *const _this)>(0x161B120);
	static inline auto FClose = PreyFunction<void(CArkPDAFabricationPlans *const _this)>(0x1628FA0);
	static inline auto FRefresh = PreyFunction<void(CArkPDAFabricationPlans const *const _this)>(0x161B180);
	static inline auto FOnShowPlan = PreyFunction<void(CArkPDAFabricationPlans *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x161AD60);
};

