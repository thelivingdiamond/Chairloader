// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/ArkInterval.h>

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>

class ArkFabricationPlanIngredients;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
enum class EArkCraftingIngredientType;
struct IEntity;
struct IEntityClass;
struct IPhysicalEntity;

// ArkRecycleUtils
// Header:  Prey/GameDll/ark/ArkRecycleUtils.h
class ArkRecycleUtils
{ // Size=1 (0x1)
public:
	static inline auto k_pIngredientClass = PreyGlobal<IEntityClass*>(0x2D3FC60);

	static IEntityClass* GetIngredientEntityClass() { return FGetIngredientEntityClass(); }
	static uint64_t GetRecycleFinishSignalId() { return FGetRecycleFinishSignalId(); }
	static void ImpulseRecycledIngredient(IPhysicalEntity* const _pPhysics, const float _impulse, const Vec3& _direction, const float _angle) { FImpulseRecycledIngredient(_pPhysics, _impulse, _direction, _angle); }
	static bool HandleRecycleSignal(const ArkSignalSystem::Package& _package) { return FHandleRecycleSignal(_package); }
	static bool HandleRecycleSignalForEntity(IEntity* const _pRecycleEntity, const ArkSignalSystem::Package& _package, const float _impuseAmount) { return FHandleRecycleSignalForEntity(_pRecycleEntity, _package, _impuseAmount); }
	static bool GetRecycleData(const IEntity& _rEntity, ArkFabricationPlanIngredients& _recycleData) { return FGetRecycleData(_rEntity, _recycleData); }
	static bool CalculateRecycleData(ArkFabricationPlanIngredients& _recycleData, const IEntity& _rEntity, const ArkInterval<float> _percentRange) { return FCalculateRecycleData(_recycleData, _rEntity, _percentRange); }
	static IEntity* CreateRecycledIngredient(const EArkCraftingIngredientType _type, const int _numScraps) { return FCreateRecycledIngredientOv1(_type, _numScraps); }
	static void CreateRecycledIngredient(const EArkCraftingIngredientType _type, const int _numScraps, const Vec3& _position, const Quat& _rotation, const Vec3& _impulseDirection, const float _impulseAmount, const float _impulseRandomAngle) { FCreateRecycledIngredientOv0(_type, _numScraps, _position, _rotation, _impulseDirection, _impulseAmount, _impulseRandomAngle); }

	static inline auto FGetIngredientEntityClass = PreyFunction<IEntityClass* ()>(0x122A420);
	static inline auto FGetRecycleFinishSignalId = PreyFunction<uint64_t()>(0x122A600);
	static inline auto FImpulseRecycledIngredient = PreyFunction<void(IPhysicalEntity* const _pPhysics, const float _impulse, const Vec3& _direction, const float _angle)>(0x122ABD0);
	static inline auto FHandleRecycleSignal = PreyFunction<bool(const ArkSignalSystem::Package& _package)>(0x122A610);
	static inline auto FHandleRecycleSignalForEntity = PreyFunction<bool(IEntity* const _pRecycleEntity, const ArkSignalSystem::Package& _package, const float _impuseAmount)>(0x122A970);
	static inline auto FGetRecycleData = PreyFunction<bool(const IEntity& _rEntity, ArkFabricationPlanIngredients& _recycleData)>(0x122A460);
	static inline auto FCalculateRecycleData = PreyFunction<bool(ArkFabricationPlanIngredients& _recycleData, const IEntity& _rEntity, const ArkInterval<float> _percentRange)>(0x1229EF0);
	static inline auto FCreateRecycledIngredientOv1 = PreyFunction<IEntity* (const EArkCraftingIngredientType _type, const int _numScraps)>(0x122A160);
	static inline auto FCreateRecycledIngredientOv0 = PreyFunction<void(const EArkCraftingIngredientType _type, const int _numScraps, const Vec3& _position, const Quat& _rotation, const Vec3& _impulseDirection, const float _impulseAmount, const float _impulseRandomAngle)>(0x122A2C0);
};
#endif // !MOONCRASH
