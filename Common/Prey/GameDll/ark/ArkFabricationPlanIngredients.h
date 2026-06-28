// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkFabricationPlan;

// Header: FromCpp
// Prey/GameDll/ark/ArkFabricationPlanIngredients.h
class ArkFabricationPlanIngredients // Id=8016E4F Size=20
{
public:
	std::array<unsigned int,4> m_amounts;
	int m_totalAmount;
	
	ArkFabricationPlanIngredients();
	ArkFabricationPlanIngredients(ArkFabricationPlan const &_plan);
	void Clear() { FClear(this); }
	bool Empty() const { return FEmpty(this); }
	bool operator==(ArkFabricationPlanIngredients const &_rhs) const { return FoperatorEqEq(this,_rhs); }
	ArkFabricationPlanIngredients &operator+=(ArkFabricationPlanIngredients const &_rhs) { return FoperatorPlusEq(this,_rhs); }
	ArkFabricationPlanIngredients &operator-=(ArkFabricationPlanIngredients const &_rhs) { return FoperatorMinusEq(this,_rhs); }
	bool CanAfford(ArkFabricationPlanIngredients const &_required) const { return FCanAfford(this,_required); }
	unsigned GetAmount(EArkCraftingIngredientType _type) const { return FGetAmount(this,_type); }
	void AdjustAmount(EArkCraftingIngredientType _type, int _amount) { FAdjustAmount(this,_type,_amount); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	ArkFabricationPlanIngredients &operator*=(const int arg0);
	unsigned GetTotalAmount() const;
#endif
	
	static inline auto FClear = PreyFunction<void(ArkFabricationPlanIngredients *const _this)>(0x115F930);
	static inline auto FEmpty = PreyFunction<bool(ArkFabricationPlanIngredients const *const _this)>(0x115F940);
	static inline auto FoperatorEqEq = PreyFunction<bool(ArkFabricationPlanIngredients const *const _this, ArkFabricationPlanIngredients const &_rhs)>(0x115F820);
	static inline auto FoperatorPlusEq = PreyFunction<ArkFabricationPlanIngredients &(ArkFabricationPlanIngredients *const _this, ArkFabricationPlanIngredients const &_rhs)>(0x115F860);
	static inline auto FoperatorMinusEq = PreyFunction<ArkFabricationPlanIngredients &(ArkFabricationPlanIngredients *const _this, ArkFabricationPlanIngredients const &_rhs)>(0x115F8A0);
	static inline auto FCanAfford = PreyFunction<bool(ArkFabricationPlanIngredients const *const _this, ArkFabricationPlanIngredients const &_required)>(0x115F8F0);
	static inline auto FGetAmount = PreyFunction<unsigned(ArkFabricationPlanIngredients const *const _this, EArkCraftingIngredientType _type)>(0x115F950);
	static inline auto FAdjustAmount = PreyFunction<void(ArkFabricationPlanIngredients *const _this, EArkCraftingIngredientType _type, int _amount)>(0x115F8E0);
	static inline auto FSerialize = PreyFunction<void(ArkFabricationPlanIngredients *const _this, TSerialize _ser)>(0x115F960);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkFabricationPlan;
enum class EArkCraftingIngredientType;

// ArkFabricationPlanIngredients
// Header:  Prey/GameDll/ark/ArkFabricationPlanIngredients.h
class ArkFabricationPlanIngredients
{ // Size=20 (0x14)
public:
	std::array<unsigned int, 4> m_amounts;
	int m_totalAmount;

	ArkFabricationPlanIngredients();
	ArkFabricationPlanIngredients(const ArkFabricationPlan& _plan);
	void Clear() { FClear(this); }
	bool Empty() const { return FEmpty(this); }
	bool operator==(const ArkFabricationPlanIngredients& _rhs) const { return FoperatorEqEq(this, _rhs); }
	ArkFabricationPlanIngredients& operator+=(const ArkFabricationPlanIngredients& _rhs) { return FoperatorPlusEq(this, _rhs); }
	ArkFabricationPlanIngredients& operator-=(const ArkFabricationPlanIngredients& _rhs) { return FoperatorMinusEq(this, _rhs); }
	bool CanAfford(const ArkFabricationPlanIngredients& _required) const { return FCanAfford(this, _required); }
	unsigned GetAmount(EArkCraftingIngredientType _type) const { return FGetAmount(this, _type); }
	void AdjustAmount(EArkCraftingIngredientType _type, int _amount) { FAdjustAmount(this, _type, _amount); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	ArkFabricationPlanIngredients(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, unsigned _arg3_);
	ArkFabricationPlanIngredients& operator*=(const int _arg0_);
	unsigned GetTotalAmount() const;
#endif

	static inline auto FArkFabricationPlanIngredientsOv2 = PreyFunction<void(ArkFabricationPlanIngredients* const _this)>(0x11ACF50);
	static inline auto FArkFabricationPlanIngredientsOv1 = PreyFunction<void(ArkFabricationPlanIngredients* const _this, const ArkFabricationPlan& _plan)>(0x11ACED0);
	static inline auto FClear = PreyFunction<void(ArkFabricationPlanIngredients* const _this)>(0x1C4EE70);
	static inline auto FEmpty = PreyFunction<bool(const ArkFabricationPlanIngredients* const _this)>(0x11AD070);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkFabricationPlanIngredients* const _this, const ArkFabricationPlanIngredients& _rhs)>(0x11ACF60);
	static inline auto FoperatorPlusEq = PreyFunction<ArkFabricationPlanIngredients& (ArkFabricationPlanIngredients* const _this, const ArkFabricationPlanIngredients& _rhs)>(0x11ACFA0);
	static inline auto FoperatorMinusEq = PreyFunction<ArkFabricationPlanIngredients& (ArkFabricationPlanIngredients* const _this, const ArkFabricationPlanIngredients& _rhs)>(0x11ACFE0);
	static inline auto FCanAfford = PreyFunction<bool(const ArkFabricationPlanIngredients* const _this, const ArkFabricationPlanIngredients& _required)>(0x11AD030);
	static inline auto FGetAmount = PreyFunction<unsigned(const ArkFabricationPlanIngredients* const _this, EArkCraftingIngredientType _type)>(0x11AD080);
	static inline auto FAdjustAmount = PreyFunction<void(ArkFabricationPlanIngredients* const _this, EArkCraftingIngredientType _type, int _amount)>(0x11AD020);
	static inline auto FSerialize = PreyFunction<void(ArkFabricationPlanIngredients* const _this, TSerialize _ser)>(0x11AD090);
};
#endif // !MOONCRASH
