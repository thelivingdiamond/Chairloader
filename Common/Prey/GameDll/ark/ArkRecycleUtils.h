// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkInterval.h>

class ArkFabricationPlanIngredients;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IEntity;
struct IEntityClass;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/ArkRecycleUtils.h
class ArkRecycleUtils // Id=8017636 Size=1
{
public:
	static IEntityClass *k_pIngredientClass;
	
	static IEntityClass *GetIngredientEntityClass() { return FGetIngredientEntityClass(); }
	static uint64_t GetRecycleFinishSignalId() { return FGetRecycleFinishSignalId(); }
	static void ImpulseRecycledIngredient(IPhysicalEntity *const _pPhysics, const float _impulse, Vec3 const &_direction, const float _angle) { FImpulseRecycledIngredient(_pPhysics,_impulse,_direction,_angle); }
	static bool HandleRecycleSignal(ArkSignalSystem::Package const &_package) { return FHandleRecycleSignal(_package); }
	static bool HandleRecycleSignalForEntity(IEntity *const _pRecycleEntity, ArkSignalSystem::Package const &_package, const float _impuseAmount) { return FHandleRecycleSignalForEntity(_pRecycleEntity,_package,_impuseAmount); }
	static bool GetRecycleData(IEntity const &_rEntity, ArkFabricationPlanIngredients &_recycleData) { return FGetRecycleData(_rEntity,_recycleData); }
	static bool CalculateRecycleData(ArkFabricationPlanIngredients &_recycleData, IEntity const &_rEntity, ArkInterval<float> _percentRange) { return FCalculateRecycleData(_recycleData,_rEntity,_percentRange); }
	static void CreateRecycledIngredient(EArkCraftingIngredientType _type, const int _numScraps, Vec3 const &_position, Quat const &_rotation, Vec3 const &_impulseDirection, const float _impulseAmount, const float _impulseRandomAngle) { FCreateRecycledIngredient(_type,_numScraps,_position,_rotation,_impulseDirection,_impulseAmount,_impulseRandomAngle); }
	
	static inline auto FGetIngredientEntityClass = PreyFunction<IEntityClass *()>(0x11ACDC0);
	static inline auto FGetRecycleFinishSignalId = PreyFunction<uint64_t()>(0x11AD000);
	static inline auto FImpulseRecycledIngredient = PreyFunction<void(IPhysicalEntity *const _pPhysics, const float _impulse, Vec3 const &_direction, const float _angle)>(0x11AD580);
	static inline auto FHandleRecycleSignal = PreyFunction<bool(ArkSignalSystem::Package const &_package)>(0x11AD010);
	static inline auto FHandleRecycleSignalForEntity = PreyFunction<bool(IEntity *const _pRecycleEntity, ArkSignalSystem::Package const &_package, const float _impuseAmount)>(0x11AD370);
	static inline auto FGetRecycleData = PreyFunction<bool(IEntity const &_rEntity, ArkFabricationPlanIngredients &_recycleData)>(0x11ACE00);
	static inline auto FCalculateRecycleData = PreyFunction<bool(ArkFabricationPlanIngredients &_recycleData, IEntity const &_rEntity, ArkInterval<float> _percentRange)>(0x11AC0B0);
	static inline auto FCreateRecycledIngredient = PreyFunction<void(EArkCraftingIngredientType _type, const int _numScraps, Vec3 const &_position, Quat const &_rotation, Vec3 const &_impulseDirection, const float _impulseAmount, const float _impulseRandomAngle)>(0x11AC320);
};

