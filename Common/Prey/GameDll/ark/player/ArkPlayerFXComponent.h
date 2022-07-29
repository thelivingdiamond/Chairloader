// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/arkplayerfxcomponent.h>

class ArkClass;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerFXComponent.h
class ArkPlayerFXComponent // Id=801709F Size=160
{
public:
	class FXTimerData // Id=80170A0 Size=16
	{
	public:
		uint64_t m_fxId;
		ArkTimeRemaining m_timer;
		
#if 0
		bool operator==(const uint64_t arg0) const;
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkPlayerFXComponent::FXTimerData> m_loopingSFX;
	std::vector<ArkPlayerFXComponent::FXTimerData> m_loopingPostFX;
	std::vector<ArkPlayerFXComponent::FXTimerData> m_loopingVFX;
	std::vector<ArkPlayerFXComponent::FXTimerData> m_cooldowns;
	
	class ArkPlayerEffect : public ArkEntityEffect // Id=80170B5 Size=136
	{
	public:
	};

	std::unordered_map<unsigned __int64,ArkPlayerFXComponent::ArkPlayerEffect> m_activeVFX;
	
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnReceiveSignal(ArkSignalSystem::Package const &_package) { FOnReceiveSignal(this,_package); }
	void StopAllLoopingSFX() { FStopAllLoopingSFX(this); }
	void StopAllLoopingPostFX() { FStopAllLoopingPostFX(this); }
	void StopAllLoopingVFX() { FStopAllLoopingVFX(this); }
	void StopLoopingSFX(uint64_t _id, IEntity *_pEntity) { FStopLoopingSFX(this,_id,_pEntity); }
	void StopLoopingPostFX(uint64_t _id) { FStopLoopingPostFX(this,_id); }
	void StopLoopingVFX(uint64_t _id, bool _bKill) { FStopLoopingVFX(this,_id,_bKill); }
	
	static inline auto FReset = PreyFunction<void(ArkPlayerFXComponent *const _this)>(0x12FE800);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerFXComponent *const _this, const float _frameTime)>(0x12FEE60);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerFXComponent *const _this, TSerialize _ser)>(0x12FE830);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerFXComponent *const _this)>(0x12FE350);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerFXComponent *const _this, ArkSignalSystem::Package const &_package)>(0x12FD9A0);
	static inline auto FStopAllLoopingSFX = PreyFunction<void(ArkPlayerFXComponent *const _this)>(0x12FE970);
	static inline auto FStopAllLoopingPostFX = PreyFunction<void(ArkPlayerFXComponent *const _this)>(0x12FE8C0);
	static inline auto FStopAllLoopingVFX = PreyFunction<void(ArkPlayerFXComponent *const _this)>(0x12FEA60);
	static inline auto FStopLoopingSFX = PreyFunction<void(ArkPlayerFXComponent *const _this, uint64_t _id, IEntity *_pEntity)>(0x12FEC80);
	static inline auto FStopLoopingPostFX = PreyFunction<void(ArkPlayerFXComponent *const _this, uint64_t _id)>(0x12FEC00);
	static inline auto FStopLoopingVFX = PreyFunction<void(ArkPlayerFXComponent *const _this, uint64_t _id, bool _bKill)>(0x12FED10);
};

// Header: Exact
// Prey/GameDll/ark/player/arkplayerfxcomponent.h
class ArkSignalFXSignalEntry : public ArkReflectedObject // Id=801B70C Size=16
{
public:
	class ArkSignalProperty : public ArkProperty // Id=801B70D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFXSignalEntry::ArkSignalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFXSignalEntry::ArkSignalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkSignalFXSignalEntry::ArkSignalProperty s_ArkSignalProperty;
	uint64_t m_Signal;
	
	class ArkValueThresholdProperty : public ArkProperty // Id=801B70E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFXSignalEntry::ArkValueThresholdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFXSignalEntry::ArkValueThresholdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkSignalFXSignalEntry::ArkValueThresholdProperty s_ArkValueThresholdProperty;
	float m_ValueThreshold;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetSignal(uint64_t arg0);
	const uint64_t &GetSignal() const;
	void SetValueThreshold(float arg0);
	const float &GetValueThreshold() const;
	bool operator==(ArkSignalFXSignalEntry const &arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12FD580);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12FD740);
};

// Header: Exact
// Prey/GameDll/ark/player/arkplayerfxcomponent.h
class ArkSignalFX : public ArkReflectedObject // Id=801B70F Size=104
{
public:
	class ArkIDProperty : public ArkProperty // Id=801B710 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkSignalFX::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=801B711 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkSignalFX::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkSignalsProperty : public ArkProperty // Id=801B712 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkSignalsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkSignalsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD30);
		static inline auto FIsArray = PreyFunction<bool(ArkSignalFX::ArkSignalsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkSignalFX::ArkSignalsProperty const *const _this, ArkReflectedObject *_pObject)>(0x12FBD50);
	};

	static ArkSignalFX::ArkSignalsProperty s_ArkSignalsProperty;
	std::vector<ArkSignalFXSignalEntry> m_Signals;
	
	class ArkPostEffectProperty : public ArkProperty // Id=801B720 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkPostEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkPostEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkSignalFX::ArkPostEffectProperty s_ArkPostEffectProperty;
	uint64_t m_PostEffect;
	
	class ArkPostEffectLoopDurationProperty : public ArkProperty // Id=801B721 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkPostEffectLoopDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkPostEffectLoopDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkSignalFX::ArkPostEffectLoopDurationProperty s_ArkPostEffectLoopDurationProperty;
	float m_PostEffectLoopDuration;
	
	class ArkParticleEffectProperty : public ArkProperty // Id=801B722 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkSignalFX::ArkParticleEffectProperty s_ArkParticleEffectProperty;
	string m_ParticleEffect;
	
	class ArkParticleLoopDurationProperty : public ArkProperty // Id=801B723 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkParticleLoopDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A650);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkParticleLoopDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkSignalFX::ArkParticleLoopDurationProperty s_ArkParticleLoopDurationProperty;
	float m_ParticleLoopDuration;
	
	class ArkAudioTriggerStartProperty : public ArkProperty // Id=801B724 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkAudioTriggerStartProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkAudioTriggerStartProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkSignalFX::ArkAudioTriggerStartProperty s_ArkAudioTriggerStartProperty;
	string m_AudioTriggerStart;
	
	class ArkAudioTriggerStopProperty : public ArkProperty // Id=801B725 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkAudioTriggerStopProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkAudioTriggerStopProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkSignalFX::ArkAudioTriggerStopProperty s_ArkAudioTriggerStopProperty;
	string m_AudioTriggerStop;
	
	class ArkLoopDurationProperty : public ArkProperty // Id=801B726 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkLoopDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBDF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkLoopDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkSignalFX::ArkLoopDurationProperty s_ArkLoopDurationProperty;
	float m_LoopDuration;
	
	class ArkCooldownProperty : public ArkProperty // Id=801B727 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328A80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328A90);
	};

	static ArkSignalFX::ArkCooldownProperty s_ArkCooldownProperty;
	float m_Cooldown;
	
	class ArkForceFeedbackProperty : public ArkProperty // Id=801B728 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFX::ArkForceFeedbackProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFX::ArkForceFeedbackProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkSignalFX::ArkForceFeedbackProperty s_ArkForceFeedbackProperty;
	string m_ForceFeedback;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	std::vector<ArkSignalFXSignalEntry> &GetSignals();
	std::vector<ArkSignalFXSignalEntry> const &GetSignals() const;
	void SetPostEffect(uint64_t arg0);
	const uint64_t &GetPostEffect() const;
	void SetPostEffectLoopDuration(float arg0);
	const float &GetPostEffectLoopDuration() const;
	void SetParticleEffect(string arg0);
	string const &GetParticleEffect() const;
	void SetParticleLoopDuration(float arg0);
	const float &GetParticleLoopDuration() const;
	void SetAudioTriggerStart(string arg0);
	string const &GetAudioTriggerStart() const;
	void SetAudioTriggerStop(string arg0);
	string const &GetAudioTriggerStop() const;
	void SetLoopDuration(float arg0);
	const float &GetLoopDuration() const;
	void SetCooldown(float arg0);
	const float &GetCooldown() const;
	void SetForceFeedback(string arg0);
	string const &GetForceFeedback() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12FD4C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12FD5B0);
};

// Header: Exact
// Prey/GameDll/ark/player/arkplayerfxcomponent.h
class ArkSignalFXLibrary : public ArkReflectedLibrary // Id=801B737 Size=32
{
public:
	class ArkFXProperty : public ArkProperty // Id=801B738 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalFXLibrary::ArkFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBE60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalFXLibrary::ArkFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBEB0);
		static inline auto FIsArray = PreyFunction<bool(ArkSignalFXLibrary::ArkFXProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkSignalFXLibrary::ArkFXProperty const *const _this, ArkReflectedObject *_pObject)>(0x12FBEF0);
	};

	static ArkSignalFXLibrary::ArkFXProperty s_ArkFXProperty;
	std::vector<ArkSignalFX> m_FX;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkSignalFXLibrary();
	
#if 0
	std::vector<ArkSignalFX> &GetFX();
	std::vector<ArkSignalFX> const &GetFX() const;
	ArkSignalFX const *FindSignalFX(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12FD520);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12FD650);
	static inline auto FInit = PreyFunction<bool(ArkSignalFXLibrary *const _this)>(0x12FD7E0);
};

