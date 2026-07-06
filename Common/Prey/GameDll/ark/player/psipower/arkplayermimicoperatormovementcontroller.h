// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkPlayerMimicEngineeringOperatorController;
class ArkPlayerMimicMilitaryOperatorController;
class ArkPlayerMimicScienceOperatorController;
class CCryName;
struct IAnimatedCharacter;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h
template <typename T>
class ArkPlayerMimicOperatorMovementController // Id=801B685 Size=40
{
public:
	Vec3 m_velocity;
	float m_speed;
	T const &m_controller;
	IAnimatedCharacter *m_pAnimatedCharacter;
	bool m_bAscending;
	bool m_bDescending;
	bool m_bSprinting;
	
#if 0
	void ArkPlayerMimicOperatorMovementController(T const &_controller);
	void Initialize(IEntity &_mimicEntity);
	void Update(const float _frameTime, IEntity const &_mimicEntity);
	void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	void Serialize(TSerialize _ser);
	bool IsSprinting() const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkPlayerMimicEngineeringOperatorController;
class ArkPlayerMimicMilitaryOperatorController;
class ArkPlayerMimicScienceOperatorController;
class CCryName;
struct IAnimatedCharacter;
struct IEntity;

// ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h
class ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>
{ // Size=40 (0x28)
public:
	Vec3 m_velocity;
	float m_speed;
	const ArkPlayerMimicEngineeringOperatorController& m_controller;
	IAnimatedCharacter* m_pAnimatedCharacter;
	bool m_bAscending;
	bool m_bDescending;
	bool m_bSprinting;

	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>(const ArkPlayerMimicEngineeringOperatorController& _controller);
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	bool IsSprinting() const { return FIsSprinting(this); }

	static inline auto FArkPlayerMimicOperatorMovementControllerLessArkPlayerMimicEngineeringOperatorControllerGreaterOv2 = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>* const _this, const ArkPlayerMimicEngineeringOperatorController& _controller)>(0x13ED340);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>* const _this, IEntity& _mimicEntity)>(0x13ED360);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x13ED6A0);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13ED5E0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>* const _this, TSerialize _ser)>(0x13ED650);
	static inline auto FIsSprinting = PreyFunction<bool(const ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13ED5D0);
};

// ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h
class ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>
{ // Size=40 (0x28)
public:
	Vec3 m_velocity;
	float m_speed;
	const ArkPlayerMimicMilitaryOperatorController& m_controller;
	IAnimatedCharacter* m_pAnimatedCharacter;
	bool m_bAscending;
	bool m_bDescending;
	bool m_bSprinting;

	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>(const ArkPlayerMimicMilitaryOperatorController& _controller);
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	bool IsSprinting() const { return FIsSprinting(this); }

	static inline auto FArkPlayerMimicOperatorMovementControllerLessArkPlayerMimicMilitaryOperatorControllerGreaterOv2 = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>* const _this, const ArkPlayerMimicMilitaryOperatorController& _controller)>(0x13ED340);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>* const _this, IEntity& _mimicEntity)>(0x13ED430);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x13EDCA0);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13ED5E0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>* const _this, TSerialize _ser)>(0x13ED650);
	static inline auto FIsSprinting = PreyFunction<bool(const ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13ED5D0);
};

// ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h
class ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>
{ // Size=40 (0x28)
public:
	Vec3 m_velocity;
	float m_speed;
	const ArkPlayerMimicScienceOperatorController& m_controller;
	IAnimatedCharacter* m_pAnimatedCharacter;
	bool m_bAscending;
	bool m_bDescending;
	bool m_bSprinting;

	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>(const ArkPlayerMimicScienceOperatorController& _controller);
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	bool IsSprinting() const { return FIsSprinting(this); }

	static inline auto FArkPlayerMimicOperatorMovementControllerLessArkPlayerMimicScienceOperatorControllerGreaterOv2 = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>* const _this, const ArkPlayerMimicScienceOperatorController& _controller)>(0x13ED340);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>* const _this, IEntity& _mimicEntity)>(0x13ED500);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x13EE2A0);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13ED5E0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>* const _this, TSerialize _ser)>(0x13ED650);
	static inline auto FIsSprinting = PreyFunction<bool(const ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>* const _this)>(0x13ED5D0);
};
#endif // !MOONCRASH
