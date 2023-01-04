// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorCamera.h>

class ArkPlayerMimicMilitaryOperatorController;
class CCryName;
struct IEntity;

// ArkPlayerMimicMilitaryOperatorCamera
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorCamera.h
class ArkPlayerMimicMilitaryOperatorCamera : public ArkPlayerMimicOperatorCamera
{ // Size=104 (0x68)
public:
	using Controller = ArkPlayerMimicMilitaryOperatorController;

	Quat m_rotation;
	Quat m_mimicWorldRotation;
	Quat m_reticleRotationDelta;
	Vec3 m_position;
	Ang3 m_inputAngles;
	ArkSimpleTimer m_lerpTimer;
	const ArkPlayerMimicMilitaryOperatorController* m_pController;
	float m_attackPositionXDir;
	bool m_bWasAttacking;
	bool m_bZeroG;
	bool m_bInGravShaft;

	ArkPlayerMimicMilitaryOperatorCamera();
	void Initialize(const ArkPlayerMimicMilitaryOperatorController& _controller) { FInitialize(this, _controller); }
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	Quat GetRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	void SetInGravShaft(const bool _bInGravShaft) { FSetInGravShaft(this, _bInGravShaft); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	Vec3 GetPosition() const;
	void SetPosition(const Vec3& _arg0_);
	void SetRotation(const Quat& _arg0_);
	void ProcessInput(const CCryName& _arg0_, const bool _arg1_) const;
#endif

	static inline auto FArkPlayerMimicMilitaryOperatorCameraOv2 = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera* const _this)>(0x130F380);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera* const _this, const ArkPlayerMimicMilitaryOperatorController& _controller)>(0x130F540);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x130F6F0);
	static inline auto FGetRotation = PreyFunction<Quat*(const ArkPlayerMimicMilitaryOperatorCamera* const _this, Quat* _return_value_)>(0x130F400);
	static inline auto FSetInGravShaft = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera* const _this, const bool _bInGravShaft)>(0x130F6B0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera* const _this, TSerialize _ser)>(0x130F5E0);
};

