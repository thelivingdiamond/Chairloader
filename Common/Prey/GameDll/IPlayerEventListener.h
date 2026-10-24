// Header file automatically created from a PDB.
#pragma once

enum class EStance;
struct IActor;
struct IEntityClass;

// IPlayerEventListener
// Header:  _unknown/IPlayerEventListener.h
struct IPlayerEventListener
{ // Size=8 (0x8)
	enum ESpecialMove
	{
		eSM_Jump = 0,
		eSM_SpeedSprint = 1,
	};

	virtual ~IPlayerEventListener();
	virtual void OnEnterVehicle(IActor* pActor, const char* strVehicleClassName, const char* strSeatName, bool bThirdPerson);
	virtual void OnExitVehicle(IActor* pActor);
	virtual void OnToggleThirdPerson(IActor* pActor, bool bThirdPerson);
	virtual void OnItemDropped(IActor* pActor, unsigned itemId);
	virtual void OnItemPickedUp(IActor* pActor, unsigned itemId);
	virtual void OnItemUsed(IActor* pActor, unsigned itemId);
	virtual void OnStanceChanged(IActor* pActor, EStance stance);
	virtual void OnSpecialMove(IActor* pActor, IPlayerEventListener::ESpecialMove move);
	virtual void OnDeath(IActor* pActor, bool bIsGod);
	virtual void OnObjectGrabbed(IActor* pActor, bool bIsGrab, unsigned objectId, bool bIsNPC, bool bIsTwoHanded);
	virtual void OnHealthChanged(IActor* pActor, float newHealth);
	virtual void OnRevive(IActor* pActor, bool bIsGod);
	virtual void OnSpectatorModeChanged(IActor* pActor, uint8_t mode);
	virtual void OnSprintStaminaChanged(IActor* pActor, float newStamina);
	virtual void OnPickedUpPickableAmmo(IActor* pActor, IEntityClass* pAmmoType, int count);
	virtual void OnIsInWater(IActor* pActor, bool bIsInWater);
	virtual void OnHeadUnderwater(IActor* pActor, bool bHeadUnderwater);
	virtual void OnOxygenLevelChanged(IActor* pActor, float fNewOxygenLevel);

#ifndef MOONCRASH
	static inline auto FOnEnterVehicle = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, const char* strVehicleClassName, const char* strSeatName, bool bThirdPerson)>(0xA13080);
	static inline auto FOnExitVehicle = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor)>(0xA13080);
	static inline auto FOnToggleThirdPerson = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bThirdPerson)>(0xA13080);
	static inline auto FOnItemDropped = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0xA13080);
	static inline auto FOnItemPickedUp = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0xA13080);
	static inline auto FOnItemUsed = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0xA13080);
	static inline auto FOnStanceChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, EStance stance)>(0xA13080);
	static inline auto FOnSpecialMove = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, IPlayerEventListener::ESpecialMove move)>(0xA13080);
	static inline auto FOnDeath = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGod)>(0xA13080);
	static inline auto FOnObjectGrabbed = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGrab, unsigned objectId, bool bIsNPC, bool bIsTwoHanded)>(0xA13080);
	static inline auto FOnHealthChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float newHealth)>(0xA13080);
	static inline auto FOnRevive = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGod)>(0xA13080);
	static inline auto FOnSpectatorModeChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, uint8_t mode)>(0xA13080);
	static inline auto FOnSprintStaminaChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float newStamina)>(0xA13080);
	static inline auto FOnPickedUpPickableAmmo = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, IEntityClass* pAmmoType, int count)>(0xA13080);
	static inline auto FOnIsInWater = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsInWater)>(0xA13080);
	static inline auto FOnHeadUnderwater = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bHeadUnderwater)>(0xA13080);
	static inline auto FOnOxygenLevelChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float fNewOxygenLevel)>(0xA13080);
#else
	static inline auto FOnEnterVehicle = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, const char* strVehicleClassName, const char* strSeatName, bool bThirdPerson)>(0x1333E90);
	static inline auto FOnExitVehicle = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor)>(0x1333E90);
	static inline auto FOnToggleThirdPerson = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bThirdPerson)>(0x1333E90);
	static inline auto FOnItemDropped = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0x1333E90);
	static inline auto FOnItemPickedUp = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0x1333E90);
	static inline auto FOnItemUsed = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0x1333E90);
	static inline auto FOnStanceChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, EStance stance)>(0x1333E90);
	static inline auto FOnSpecialMove = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, IPlayerEventListener::ESpecialMove move)>(0x1333E90);
	static inline auto FOnDeath = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGod)>(0x1333E90);
	static inline auto FOnObjectGrabbed = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGrab, unsigned objectId, bool bIsNPC, bool bIsTwoHanded)>(0x1333E90);
	static inline auto FOnHealthChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float newHealth)>(0x1333E90);
	static inline auto FOnRevive = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGod)>(0x1333E90);
	static inline auto FOnSpectatorModeChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, uint8_t mode)>(0x1333E90);
	static inline auto FOnSprintStaminaChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float newStamina)>(0x1333E90);
	static inline auto FOnPickedUpPickableAmmo = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, IEntityClass* pAmmoType, int count)>(0x1333E90);
	static inline auto FOnIsInWater = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsInWater)>(0x1333E90);
	static inline auto FOnHeadUnderwater = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bHeadUnderwater)>(0x1333E90);
	static inline auto FOnOxygenLevelChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float fNewOxygenLevel)>(0x1333E90);
#endif
};

