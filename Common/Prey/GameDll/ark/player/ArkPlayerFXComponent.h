// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>

class ArkClass;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class IArkValueBase;
struct IEntity;

// ArkPlayerFXComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
class ArkPlayerFXComponent
{ // Size=160 (0xA0)
public:
	// ArkPlayerFXComponent::FXTimerData
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class FXTimerData
	{ // Size=16 (0x10)
	public:
		uint64_t m_fxId;
		ArkTimeRemaining m_timer;

	#if 0
		FXTimerData();
		FXTimerData(uint64_t _arg0_, float _arg1_);
		bool operator==(const uint64_t _arg0_) const;
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// ArkPlayerFXComponent::ArkPlayerEffect
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkPlayerEffect : public ArkEntityEffect
	{ // Size=136 (0x88)
	public:
	#if 0
		ArkPlayerEffect();
	#endif
	};

	std::vector<ArkPlayerFXComponent::FXTimerData> m_loopingSFX;
	std::vector<ArkPlayerFXComponent::FXTimerData> m_loopingPostFX;
	std::vector<ArkPlayerFXComponent::FXTimerData> m_loopingVFX;
	std::vector<ArkPlayerFXComponent::FXTimerData> m_cooldowns;
	std::unordered_map<uint64_t, ArkPlayerFXComponent::ArkPlayerEffect> m_activeVFX;

	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnReceiveSignal(const ArkSignalSystem::Package& _package) { FOnReceiveSignal(this, _package); }
	void StopAllLoopingSFX() { FStopAllLoopingSFX(this); }
	void StopAllLoopingPostFX() { FStopAllLoopingPostFX(this); }
	void StopAllLoopingVFX() { FStopAllLoopingVFX(this); }
	void StopLoopingSFX(uint64_t _id, IEntity* _pEntity) { FStopLoopingSFX(this, _id, _pEntity); }
	void StopLoopingPostFX(uint64_t _id) { FStopLoopingPostFX(this, _id); }
	void StopLoopingVFX(uint64_t _id, bool _bKill) { FStopLoopingVFX(this, _id, _bKill); }

	static inline auto FReset = PreyFunction<void(ArkPlayerFXComponent* const _this)>(0x12FE800);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerFXComponent* const _this, const float _frameTime)>(0x12FEE60);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerFXComponent* const _this, TSerialize _ser)>(0x12FE830);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerFXComponent* const _this)>(0x12FE350);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerFXComponent* const _this, const ArkSignalSystem::Package& _package)>(0x12FD9A0);
	static inline auto FStopAllLoopingSFX = PreyFunction<void(ArkPlayerFXComponent* const _this)>(0x12FE970);
	static inline auto FStopAllLoopingPostFX = PreyFunction<void(ArkPlayerFXComponent* const _this)>(0x12FE8C0);
	static inline auto FStopAllLoopingVFX = PreyFunction<void(ArkPlayerFXComponent* const _this)>(0x12FEA60);
	static inline auto FStopLoopingSFX = PreyFunction<void(ArkPlayerFXComponent* const _this, uint64_t _id, IEntity* _pEntity)>(0x12FEC80);
	static inline auto FStopLoopingPostFX = PreyFunction<void(ArkPlayerFXComponent* const _this, uint64_t _id)>(0x12FEC00);
	static inline auto FStopLoopingVFX = PreyFunction<void(ArkPlayerFXComponent* const _this, uint64_t _id, bool _bKill)>(0x12FED10);
};

// ArkSignalFXSignalEntry
// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
class ArkSignalFXSignalEntry : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkSignalFXSignalEntry::ArkSignalProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkSignalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFXSignalEntry::ArkSignalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFXSignalEntry::ArkSignalProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkSignalFXSignalEntry::ArkValueThresholdProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkValueThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkValueThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFXSignalEntry::ArkValueThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFXSignalEntry::ArkValueThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static inline auto s_ArkSignalProperty = PreyGlobal<ArkSignalFXSignalEntry::ArkSignalProperty>(0x2BDA200);
	uint64_t m_Signal;
	static inline auto s_ArkValueThresholdProperty = PreyGlobal<ArkSignalFXSignalEntry::ArkValueThresholdProperty>(0x2BDA220);
	float m_ValueThreshold;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkSignalFXSignalEntry();
	ArkSignalFXSignalEntry(const uint64_t _arg0_, const float _arg1_);
	void SetSignal(uint64_t _arg0_);
	const uint64_t& GetSignal() const;
	void SetValueThreshold(float _arg0_);
	const float& GetValueThreshold() const;
	bool operator==(const ArkSignalFXSignalEntry& _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12FD580);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12FD740);
};

// ArkSignalFX
// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
class ArkSignalFX : public ArkReflectedObject
{ // Size=104 (0x68)
public:
	// ArkSignalFX::ArkIDProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkSignalFX::ArkNameProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkSignalFX::ArkSignalsProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkSignalsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSignalsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkSignalsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkSignalsProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD30);
		static inline auto FIsArray = PreyFunction<bool(const ArkSignalFX::ArkSignalsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkSignalFX::ArkSignalsProperty* const _this, ArkReflectedObject* _pObject)>(0x12FBD50);
	};

	// ArkSignalFX::ArkPostEffectProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkPostEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkPostEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkPostEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkSignalFX::ArkPostEffectLoopDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkPostEffectLoopDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostEffectLoopDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkPostEffectLoopDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkPostEffectLoopDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkSignalFX::ArkParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkSignalFX::ArkParticleLoopDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkParticleLoopDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkParticleLoopDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkParticleLoopDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A650);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkParticleLoopDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	// ArkSignalFX::ArkAudioTriggerStartProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkAudioTriggerStartProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAudioTriggerStartProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkAudioTriggerStartProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkAudioTriggerStartProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
	};

	// ArkSignalFX::ArkAudioTriggerStopProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkAudioTriggerStopProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAudioTriggerStopProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkAudioTriggerStopProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkAudioTriggerStopProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkSignalFX::ArkLoopDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkLoopDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoopDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkLoopDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBDF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkLoopDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10860E0);
	};

	// ArkSignalFX::ArkCooldownProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkCooldownProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkCooldownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328A80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkCooldownProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328A90);
	};

	// ArkSignalFX::ArkForceFeedbackProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkForceFeedbackProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkForceFeedbackProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFX::ArkForceFeedbackProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFX::ArkForceFeedbackProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkSignalFX::ArkIDProperty>(0x2BDA240);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkSignalFX::ArkNameProperty>(0x2BDA260);
	string m_Name;
	static inline auto s_ArkSignalsProperty = PreyGlobal<ArkSignalFX::ArkSignalsProperty>(0x2BDA280);
	std::vector<ArkSignalFXSignalEntry> m_Signals;
	static inline auto s_ArkPostEffectProperty = PreyGlobal<ArkSignalFX::ArkPostEffectProperty>(0x2BDA2A0);
	uint64_t m_PostEffect;
	static inline auto s_ArkPostEffectLoopDurationProperty = PreyGlobal<ArkSignalFX::ArkPostEffectLoopDurationProperty>(0x2BDA2C0);
	float m_PostEffectLoopDuration;
	static inline auto s_ArkParticleEffectProperty = PreyGlobal<ArkSignalFX::ArkParticleEffectProperty>(0x2BDA2E0);
	string m_ParticleEffect;
	static inline auto s_ArkParticleLoopDurationProperty = PreyGlobal<ArkSignalFX::ArkParticleLoopDurationProperty>(0x2BDA300);
	float m_ParticleLoopDuration;
	static inline auto s_ArkAudioTriggerStartProperty = PreyGlobal<ArkSignalFX::ArkAudioTriggerStartProperty>(0x2BDA320);
	string m_AudioTriggerStart;
	static inline auto s_ArkAudioTriggerStopProperty = PreyGlobal<ArkSignalFX::ArkAudioTriggerStopProperty>(0x2BDA340);
	string m_AudioTriggerStop;
	static inline auto s_ArkLoopDurationProperty = PreyGlobal<ArkSignalFX::ArkLoopDurationProperty>(0x2BDA360);
	float m_LoopDuration;
	static inline auto s_ArkCooldownProperty = PreyGlobal<ArkSignalFX::ArkCooldownProperty>(0x2BDA380);
	float m_Cooldown;
	static inline auto s_ArkForceFeedbackProperty = PreyGlobal<ArkSignalFX::ArkForceFeedbackProperty>(0x2BDA3A0);
	string m_ForceFeedback;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<ArkSignalFXSignalEntry>& GetSignals();
	const std::vector<ArkSignalFXSignalEntry>& GetSignals() const;
	void SetPostEffect(uint64_t _arg0_);
	const uint64_t& GetPostEffect() const;
	void SetPostEffectLoopDuration(float _arg0_);
	const float& GetPostEffectLoopDuration() const;
	void SetParticleEffect(string _arg0_);
	const string& GetParticleEffect() const;
	void SetParticleLoopDuration(float _arg0_);
	const float& GetParticleLoopDuration() const;
	void SetAudioTriggerStart(string _arg0_);
	const string& GetAudioTriggerStart() const;
	void SetAudioTriggerStop(string _arg0_);
	const string& GetAudioTriggerStop() const;
	void SetLoopDuration(float _arg0_);
	const float& GetLoopDuration() const;
	void SetCooldown(float _arg0_);
	const float& GetCooldown() const;
	void SetForceFeedback(string _arg0_);
	const string& GetForceFeedback() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12FD4C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12FD5B0);
};

// ArkSignalFXLibrary
// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
class ArkSignalFXLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkSignalFXLibrary::ArkFXProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerFXComponent.h
	class ArkFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalFXLibrary::ArkFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBE60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalFXLibrary::ArkFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBEB0);
		static inline auto FIsArray = PreyFunction<bool(const ArkSignalFXLibrary::ArkFXProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkSignalFXLibrary::ArkFXProperty* const _this, ArkReflectedObject* _pObject)>(0x12FBEF0);
	};

	static inline auto s_ArkFXProperty = PreyGlobal<ArkSignalFXLibrary::ArkFXProperty>(0x2BDA3C0);
	std::vector<ArkSignalFX> m_FX;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkSignalFX>& GetFX();
	const std::vector<ArkSignalFX>& GetFX() const;
	const ArkSignalFX* FindSignalFX(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12FD520);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12FD650);
	static inline auto FInit = PreyFunction<bool(ArkSignalFXLibrary* const _this)>(0x12FD7E0);
};

