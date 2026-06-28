// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

enum class ArkPDAPage;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// CArkPDAFabricationPlans
// Header:  Prey/GameDll/ark/ui/arkpdapagefabricationplans.h
class CArkPDAFabricationPlans : public IArkPDAPage, public ArkUIMenuBase<CArkPDAFabricationPlans>
{ // Size=48 (0x30)
public:
	uint64_t m_selectedPlanId;

	CArkPDAFabricationPlans();
	virtual ~CArkPDAFabricationPlans();
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	void OnShowPlan(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnShowPlan(this, _pSender, _event, _args); }

#if 0
	static ArkPDAPage GetPDAPage();
#endif

	static inline auto FCArkPDAFabricationPlansOv1 = PreyFunction<void(CArkPDAFabricationPlans* const _this)>(0x173C0A0);
	static inline auto FOpen = PreyFunction<void(CArkPDAFabricationPlans* const _this)>(0x173C870);
	static inline auto FClose = PreyFunction<void(CArkPDAFabricationPlans* const _this)>(0x174AC00);
	static inline auto FRefresh = PreyFunction<void(const CArkPDAFabricationPlans* const _this)>(0x173C8D0);
	static inline auto FOnShowPlan = PreyFunction<void(CArkPDAFabricationPlans* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173C590);
};
#endif // !MOONCRASH
