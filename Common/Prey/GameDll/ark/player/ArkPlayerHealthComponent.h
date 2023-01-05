// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
struct IParticleEffect;
class XmlNodeRef;

// ArkPlayerHealthFeedback
// Header:  Prey/GameDll/ark/player/ArkPlayerHealthComponent.h
class ArkPlayerHealthFeedback
{ // Size=72 (0x48)
public:
	float m_lowHealth;
	float m_nearDeath;
	float m_prevHealth;
	int m_vfxSlot;
	bool m_bTookDamageThisTick;
	IParticleEffect* m_pLowHealthParticle;
	IParticleEffect* m_pNearDeathParticle;
	uint64_t m_lowHealthPostEffect;
	uint64_t m_nearDeathPostEffect;
	ArkAudioTrigger m_triggerNearDeathStart;
	ArkAudioTrigger m_triggerNearDeathStop;
	ArkAudioTrigger m_triggerNearDeathStinger;
	ArkAudioRtpc m_rtpcNearDeathIntensity;

	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void UpdateFeedback(float _currentHealth, float _frameTime) { FUpdateFeedback(this, _currentHealth, _frameTime); }

#if 0
	ArkPlayerHealthFeedback();
	float GetNearDeathThreshold() const;
	void SetTookDamage();
#endif

	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerHealthFeedback* const _this, const XmlNodeRef& _node)>(0x155EA00);
	static inline auto FUpdateFeedback = PreyFunction<void(ArkPlayerHealthFeedback* const _this, float _currentHealth, float _frameTime)>(0x155F7E0);
};

// ArkPlayerHealthComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerHealthComponent.h
class ArkPlayerHealthComponent : private IArkStatsListener
{ // Size=160 (0xA0)
public:
	ArkAudioTrigger m_damageAudio;
	ArkAudioTrigger m_deathAudio;
	ArkAudioTrigger m_lastChanceAudio;
	ArkAudioTrigger m_regenStartAudio;
	ArkAudioTrigger m_regenStopAudio;
	string m_deathCharacter;
	float m_damageSinceRegen;
	float m_elapsedSinceDamaged;
	ArkSimpleTimer m_lastChanceTimeout;
	ArkSimpleTimer m_timeRemainingBeforeDeathMenu;
	ArkPlayerHealthFeedback m_feedback;
	bool m_bDeathMenuOpened;
	bool m_bRegening;
	Vec3 m_bWeaponPosition;
	unsigned m_killer;

	ArkPlayerHealthComponent();
	virtual ~ArkPlayerHealthComponent();
	void Reset() { FReset(this); }
	int GetGodMode() const { return FGetGodMode(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	bool IsDead() const { return FIsDead(this); }
	float GetHealth() const { return FGetHealth(this); }
	float GetMaxHealth() const { return FGetMaxHealth(this); }
	float GetUnreducedMaxHealth() const { return FGetUnreducedMaxHealth(this); }
	void SetHealth(const float _health, const bool _bDamagedByRecyclerGrenade) { FSetHealth(this, _health, _bDamagedByRecyclerGrenade); }
	void IncreaseHealth(const float _increase) { FIncreaseHealth(this, _increase); }
	void ForceKill() { FForceKill(this); }
	void SetKiller(const unsigned _killer) { FSetKiller(this, _killer); }
	unsigned GetKiller() const { return FGetKiller(this); }
	void SetWeaponPosition(const Vec3& _bRecyclerGrenadeDeathPosition) { FSetWeaponPosition(this, _bRecyclerGrenadeDeathPosition); }
	Vec3 GetWeaponPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetWeaponPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void UpdateHUD(bool _bAnimate, float _previewValue) const { FUpdateHUD(this, _bAnimate, _previewValue); }
	static int FormatForDisplay(const float _fAmount) { return FFormatForDisplay(_fAmount); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void DoDeath(bool _bByRecyclerGrenade) { FDoDeath(this, _bByRecyclerGrenade); }

#if 0
	float GetMaxRegen() const;
	float GetMaxHealthReduction() const;
	float GetRegenRate() const;
	float GetRegenCooldown() const;
	void SetTimeRemainingBeforeDeathMenu(const float _arg0_);
	float GetStat(const CCryName& _arg0_) const;
	float GetLowHealthRegenRate() const;
	float GetLowHealthRegenCooldown() const;
	float GetLowHealthRegenThreshold() const;
	bool ShouldRegenerateHealth() const;
	bool ShouldRegenerateLowHealth() const;
#endif

	static inline auto FArkPlayerHealthComponentOv1 = PreyFunction<void(ArkPlayerHealthComponent* const _this)>(0x155E290);
	static inline auto FReset = PreyFunction<void(ArkPlayerHealthComponent* const _this)>(0x155EE60);
	static inline auto FGetGodMode = PreyFunction<int(const ArkPlayerHealthComponent* const _this)>(0x155E620);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerHealthComponent* const _this, const float _frameTime)>(0x155F4A0);
	static inline auto FIsDead = PreyFunction<bool(const ArkPlayerHealthComponent* const _this)>(0x155E7F0);
	static inline auto FGetHealth = PreyFunction<float(const ArkPlayerHealthComponent* const _this)>(0x155E660);
	static inline auto FGetMaxHealth = PreyFunction<float(const ArkPlayerHealthComponent* const _this)>(0x155E680);
	static inline auto FGetUnreducedMaxHealth = PreyFunction<float(const ArkPlayerHealthComponent* const _this)>(0x155E750);
	static inline auto FSetHealth = PreyFunction<void(ArkPlayerHealthComponent* const _this, const float _health, const bool _bDamagedByRecyclerGrenade)>(0x155EFE0);
	static inline auto FIncreaseHealth = PreyFunction<void(ArkPlayerHealthComponent* const _this, const float _increase)>(0x155E790);
	static inline auto FForceKill = PreyFunction<void(ArkPlayerHealthComponent* const _this)>(0x155E530);
	static inline auto FSetKiller = PreyFunction<void(ArkPlayerHealthComponent* const _this, const unsigned _killer)>(0x155F490);
	static inline auto FGetKiller = PreyFunction<unsigned(const ArkPlayerHealthComponent* const _this)>(0xF43E0);
	static inline auto FSetWeaponPosition = PreyFunction<void(ArkPlayerHealthComponent* const _this, const Vec3& _bRecyclerGrenadeDeathPosition)>(0x10BDE00);
	static inline auto FGetWeaponPosition = PreyFunction<Vec3*(const ArkPlayerHealthComponent* const _this, Vec3* _return_value_)>(0x155E770);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerHealthComponent* const _this, TSerialize _ser)>(0x155EF00);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerHealthComponent* const _this)>(0x155ED80);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerHealthComponent* const _this, const XmlNodeRef& _node)>(0x155E810);
	static inline auto FUpdateHUD = PreyFunction<void(const ArkPlayerHealthComponent* const _this, bool _bAnimate, float _previewValue)>(0x155FC40);
	static inline auto FFormatForDisplay = PreyFunction<int(const float _fAmount)>(0x155E600);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerHealthComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x155EC70);
	static inline auto FDoDeath = PreyFunction<void(ArkPlayerHealthComponent* const _this, bool _bByRecyclerGrenade)>(0x155E420);
};

