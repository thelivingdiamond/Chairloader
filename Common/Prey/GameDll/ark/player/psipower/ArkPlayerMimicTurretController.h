// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h>

class ArkInputLegend;
class ArkTurret;
class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretController.h
class ArkPlayerMimicTurretController // Id=801B845 Size=48
{
public:
	using Properties = ArkPsiMimicTurretProperties;
	
	ArkSimpleTimer m_attackTimer;
	Ang3 m_inputAngleVelocity;
	ArkTurret *m_pTurret;
	ArkPsiMimicTurretProperties const &m_properties;
	bool m_bFlipping;
	bool m_bAttacking;
	bool m_bAscending;
	bool m_bDescending;
	
	ArkPlayerMimicTurretController();
	void Initialize(IEntity &_mimicEntity) { FInitialize(this,_mimicEntity); }
	void Update(const float _frameTime, IEntity &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	void ProcessInput(CCryName const &_actionId, const bool _bPressed) { FProcessInput(this,_actionId,_bPressed); }
	ArkInputLegend const &GetModalLegend() const { return FGetModalLegend(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	bool IsDeployed() const { return FIsDeployed(this); }
	Vec3 GetMuzzlePosition() const { return FGetMuzzlePosition(this); }
	Vec3 GetGimbalPosition() const { return FGetGimbalPosition(this); }
	Quat GetMuzzleRotation() const { return FGetMuzzleRotation(this); }
	
#if 0
	void PostSerialize() const;
	bool IsAttacking() const;
	ArkPsiMimicTurretProperties const &GetProperties() const;
	ArkSimpleTimer const &GetAttackTimer() const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicTurretController *const _this, IEntity &_mimicEntity)>(0x13242D0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicTurretController *const _this, const float _frameTime, IEntity &_mimicEntity)>(0x1324410);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicTurretController *const _this, CCryName const &_actionId, const bool _bPressed)>(0x13243B0);
	static inline auto FGetModalLegend = PreyFunction<ArkInputLegend const &(ArkPlayerMimicTurretController const *const _this)>(0x1324210);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicTurretController *const _this, TSerialize _ser)>(0x13243F0);
	static inline auto FIsDeployed = PreyFunction<bool(ArkPlayerMimicTurretController const *const _this)>(0x13243A0);
	static inline auto FGetMuzzlePosition = PreyFunction<Vec3(ArkPlayerMimicTurretController const *const _this)>(0x1324240);
	static inline auto FGetGimbalPosition = PreyFunction<Vec3(ArkPlayerMimicTurretController const *const _this)>(0x13241F0);
	static inline auto FGetMuzzleRotation = PreyFunction<Quat(ArkPlayerMimicTurretController const *const _this)>(0x1324260);
};

