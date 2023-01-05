// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorRotationController.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h>
#include <Prey/GameDll/ark/ArkOperatorLaserHelper.h>

class ArkPsiMimicMilitaryOperatorProperties;
class CCryName;
struct IEntity;

// ArkPlayerMimicMilitaryOperatorController
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorController.h
class ArkPlayerMimicMilitaryOperatorController : public ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>
{ // Size=1016 (0x3F8)
public:
	using Properties = ArkPsiMimicMilitaryOperatorProperties;
	using MovementController = ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>;
	using RotationController = ArkPlayerMimicMilitaryOperatorRotationController;

	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController> m_movementController;
	ArkPlayerMimicMilitaryOperatorRotationController m_rotationController;
	ArkOperatorLaserHelper m_laserHelper;
	const ArkPsiMimicMilitaryOperatorProperties& m_properties;

	ArkPlayerMimicMilitaryOperatorController();
	void Initialize_Derived(IEntity& _mimicEntity) { FInitialize_Derived(this, _mimicEntity); }
	void Update_Derived(const float _frameTime, IEntity& _mimicEntity) { FUpdate_Derived(this, _frameTime, _mimicEntity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	bool IsAttacking() const { return FIsAttacking(this); }
	float GetMovementSpeed() const { return FGetMovementSpeed(this); }
	Vec3 GetLaserMuzzlePosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetLaserMuzzlePosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Quat GetLaserMuzzleRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetLaserMuzzleRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	Vec3 GetLaserTargetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetLaserTargetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

#if 0
	void PostSerialize() const;
	const Quat& GetTargetEntityRotation() const;
	const ArkPsiMimicMilitaryOperatorProperties& GetProperties() const;
#endif

	static inline auto FArkPlayerMimicMilitaryOperatorController = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController* const _this)>(0x1310C90);
	static inline auto FInitialize_Derived = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController* const _this, IEntity& _mimicEntity)>(0x1311000);
	static inline auto FUpdate_Derived = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x1311150);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController* const _this, const CCryName& _actionId, const bool _bPressed)>(0x1311080);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController* const _this, TSerialize _ser)>(0x1311100);
	static inline auto FIsAttacking = PreyFunction<bool(const ArkPlayerMimicMilitaryOperatorController* const _this)>(0x1311060);
	static inline auto FGetMovementSpeed = PreyFunction<float(const ArkPlayerMimicMilitaryOperatorController* const _this)>(0x1310FC0);
	static inline auto FGetLaserMuzzlePosition = PreyFunction<Vec3*(const ArkPlayerMimicMilitaryOperatorController* const _this, Vec3* _return_value_)>(0x1310DE0);
	static inline auto FGetLaserMuzzleRotation = PreyFunction<Quat*(const ArkPlayerMimicMilitaryOperatorController* const _this, Quat* _return_value_)>(0x1310E30);
	static inline auto FGetLaserTargetPosition = PreyFunction<Vec3*(const ArkPlayerMimicMilitaryOperatorController* const _this, Vec3* _return_value_)>(0x1310E80);
};

