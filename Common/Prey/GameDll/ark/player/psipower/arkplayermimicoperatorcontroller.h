// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkNpc;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h
template <typename T>
class ArkPlayerMimicOperatorController // Id=801B687 Size=64
{
public:
	using Properties = ArkPsiMimicOperatorProperties;
	
	ArkSimpleTimer m_ragdollTimer;
	ArkInputLegend m_modalInputLegend;
	ArkNpc *m_pNpc;
	ArkPsiMimicOperatorProperties const &m_properties;
	bool m_bZeroG;
	
#if 0
	void ArkPlayerMimicOperatorController();
	void ResetModalLegend();
	void Initialize(IEntity &_mimicEntity);
	void Update(const float _frameTime, IEntity &_mimicEntity);
	ArkNpc &GetNpc() const;
	bool IsZeroG() const;
	bool IsRagdolled() const;
	Vec3 GetMimicPosition() const;
	Quat GetMimicRotation() const;
	float GetTurnSpeedScale() const;
	ArkInputLegend const &GetModalLegend() const;
	void Initialize_Derived(IEntity &arg0) const;
	void Update_Derived(const float arg0, IEntity &arg1) const;
	void ResetModalLegend_Derived(ArkInputLegend &arg0) const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkNpc;
class ArkPsiMimicOperatorProperties;
struct IEntity;

// ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h
class ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>
{ // Size=64 (0x40)
public:
	using Properties = ArkPsiMimicOperatorProperties;

	ArkSimpleTimer m_ragdollTimer;
	ArkInputLegend m_modalInputLegend;
	ArkNpc* m_pNpc;
	const ArkPsiMimicOperatorProperties& m_properties;
	bool m_bZeroG;

	ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>();
	void ResetModalLegend() { FResetModalLegend(this); }
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	ArkNpc& GetNpc() const { return FGetNpc(this); }
	bool IsZeroG() const { return FIsZeroG(this); }
	bool IsRagdolled() const { return FIsRagdolled(this); }
	Vec3 GetMimicPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetMimicPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Quat GetMimicRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetMimicRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	float GetTurnSpeedScale() const { return FGetTurnSpeedScale(this); }
	const ArkInputLegend& GetModalLegend() const { return FGetModalLegend(this); }

#if 0
	void Initialize_Derived(IEntity& _arg0_) const;
	void Update_Derived(const float _arg0_, IEntity& _arg1_) const;
	void ResetModalLegend_Derived(ArkInputLegend& _arg0_) const;
#endif

	static inline auto FArkPlayerMimicOperatorControllerLessArkPlayerMimicEngineeringOperatorControllerGreaterOv2 = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13A2FF0);
	static inline auto FResetModalLegend = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13A3390);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this, IEntity& _mimicEntity)>(0x13A31E0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x13A3410);
	static inline auto FGetNpc = PreyFunction<ArkNpc& (const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x7E3C90);
	static inline auto FIsZeroG = PreyFunction<bool(const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13A3380);
	static inline auto FIsRagdolled = PreyFunction<bool(const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13A3360);
	static inline auto FGetMimicPosition = PreyFunction<Vec3*(const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this, Vec3* _return_value_)>(0x13A3050);
	static inline auto FGetMimicRotation = PreyFunction<Quat*(const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this, Quat* _return_value_)>(0x13A30A0);
	static inline auto FGetTurnSpeedScale = PreyFunction<float(const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13A30E0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x133BA60);
};

// ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h
class ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>
{ // Size=64 (0x40)
public:
	using Properties = ArkPsiMimicOperatorProperties;

	ArkSimpleTimer m_ragdollTimer;
	ArkInputLegend m_modalInputLegend;
	ArkNpc* m_pNpc;
	const ArkPsiMimicOperatorProperties& m_properties;
	bool m_bZeroG;

	ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>();
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	ArkNpc& GetNpc() const { return FGetNpc(this); }
	bool IsZeroG() const { return FIsZeroG(this); }
	bool IsRagdolled() const { return FIsRagdolled(this); }
	Vec3 GetMimicPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetMimicPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Quat GetMimicRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetMimicRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	float GetTurnSpeedScale() const { return FGetTurnSpeedScale(this); }
	const ArkInputLegend& GetModalLegend() const { return FGetModalLegend(this); }

#if 0
	void ResetModalLegend();
	void Initialize_Derived(IEntity& _arg0_) const;
	void Update_Derived(const float _arg0_, IEntity& _arg1_) const;
	void ResetModalLegend_Derived(ArkInputLegend& _arg0_) const;
#endif

	static inline auto FArkPlayerMimicOperatorControllerLessArkPlayerMimicMilitaryOperatorControllerGreaterOv2 = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13A2FF0);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this, IEntity& _mimicEntity)>(0x13A3260);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x13A3510);
	static inline auto FGetNpc = PreyFunction<ArkNpc& (const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x7E3C90);
	static inline auto FIsZeroG = PreyFunction<bool(const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13A3380);
	static inline auto FIsRagdolled = PreyFunction<bool(const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13A3360);
	static inline auto FGetMimicPosition = PreyFunction<Vec3*(const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this, Vec3* _return_value_)>(0x13A3050);
	static inline auto FGetMimicRotation = PreyFunction<Quat*(const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this, Quat* _return_value_)>(0x13A30A0);
	static inline auto FGetTurnSpeedScale = PreyFunction<float(const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13A30E0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x133BA60);
};

// ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h
class ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>
{ // Size=64 (0x40)
public:
	using Properties = ArkPsiMimicOperatorProperties;

	ArkSimpleTimer m_ragdollTimer;
	ArkInputLegend m_modalInputLegend;
	ArkNpc* m_pNpc;
	const ArkPsiMimicOperatorProperties& m_properties;
	bool m_bZeroG;

	ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>();
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	ArkNpc& GetNpc() const { return FGetNpc(this); }
	bool IsZeroG() const { return FIsZeroG(this); }
	bool IsRagdolled() const { return FIsRagdolled(this); }
	Vec3 GetMimicPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetMimicPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Quat GetMimicRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetMimicRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	float GetTurnSpeedScale() const { return FGetTurnSpeedScale(this); }
	const ArkInputLegend& GetModalLegend() const { return FGetModalLegend(this); }

#if 0
	void ResetModalLegend();
	void Initialize_Derived(IEntity& _arg0_) const;
	void Update_Derived(const float _arg0_, IEntity& _arg1_) const;
	void ResetModalLegend_Derived(ArkInputLegend& _arg0_) const;
#endif

	static inline auto FArkPlayerMimicOperatorControllerLessArkPlayerMimicScienceOperatorControllerGreaterOv2 = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x13A2FF0);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this, IEntity& _mimicEntity)>(0x13A32E0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x13A3600);
	static inline auto FGetNpc = PreyFunction<ArkNpc& (const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x7E3C90);
	static inline auto FIsZeroG = PreyFunction<bool(const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x13A3380);
	static inline auto FIsRagdolled = PreyFunction<bool(const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x13A3360);
	static inline auto FGetMimicPosition = PreyFunction<Vec3*(const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this, Vec3* _return_value_)>(0x13A3050);
	static inline auto FGetMimicRotation = PreyFunction<Quat*(const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this, Quat* _return_value_)>(0x13A30A0);
	static inline auto FGetTurnSpeedScale = PreyFunction<float(const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x13A30E0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x133BA60);
};
#endif // !MOONCRASH
