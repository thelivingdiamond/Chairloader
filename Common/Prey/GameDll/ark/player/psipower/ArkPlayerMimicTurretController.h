// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkInputLegend;
class ArkPsiMimicTurretProperties;
class ArkTurret;
class CCryName;
struct IEntity;

// ArkPlayerMimicTurretController
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretController.h
class ArkPlayerMimicTurretController
{ // Size=48 (0x30)
public:
	using Properties = ArkPsiMimicTurretProperties;

	ArkSimpleTimer m_attackTimer;
	Ang3 m_inputAngleVelocity;
	ArkTurret* m_pTurret;
	const ArkPsiMimicTurretProperties& m_properties;
	bool m_bFlipping;
	bool m_bAttacking;
	bool m_bAscending;
	bool m_bDescending;

	ArkPlayerMimicTurretController();
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	const ArkInputLegend& GetModalLegend() const { return FGetModalLegend(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	bool IsDeployed() const { return FIsDeployed(this); }
	Vec3 GetMuzzlePosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetMuzzlePosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetGimbalPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetGimbalPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	const Quat GetMuzzleRotation() const { alignas(const Quat) std::byte _return_buf_[sizeof(const Quat)]; return *FGetMuzzleRotation(this, reinterpret_cast<const Quat*>(_return_buf_)); }

#if 0
	void PostSerialize() const;
	bool IsAttacking() const;
	const ArkPsiMimicTurretProperties& GetProperties() const;
	const ArkSimpleTimer& GetAttackTimer() const;
#endif

	static inline auto FArkPlayerMimicTurretController = PreyFunction<void(ArkPlayerMimicTurretController* const _this)>(0x1324190);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicTurretController* const _this, IEntity& _mimicEntity)>(0x13242D0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicTurretController* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x1324410);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicTurretController* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13243B0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimicTurretController* const _this)>(0x1324210);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicTurretController* const _this, TSerialize _ser)>(0x13243F0);
	static inline auto FIsDeployed = PreyFunction<bool(const ArkPlayerMimicTurretController* const _this)>(0x13243A0);
	static inline auto FGetMuzzlePosition = PreyFunction<Vec3*(const ArkPlayerMimicTurretController* const _this, Vec3* _return_value_)>(0x1324240);
	static inline auto FGetGimbalPosition = PreyFunction<Vec3*(const ArkPlayerMimicTurretController* const _this, Vec3* _return_value_)>(0x13241F0);
	static inline auto FGetMuzzleRotation = PreyFunction<const Quat*(const ArkPlayerMimicTurretController* const _this, const Quat* _return_value_)>(0x1324260);
};

