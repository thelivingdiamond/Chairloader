// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpc;
struct ArkNpcGameEffectInstance;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect
// Header:  Prey/GameDll/ark/npc/gameeffect/ArkNpcGameEffect.h
class ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	virtual ~ArkNpcGameEffect();
	const char* GetClassName() const { return FGetClassName(this); }
	std::unique_ptr<ArkNpcGameEffectInstance> MakeGameEffectInstance() const { alignas(std::unique_ptr<ArkNpcGameEffectInstance>) std::byte _return_buf_[sizeof(std::unique_ptr<ArkNpcGameEffectInstance>)]; return *FMakeGameEffectInstance(this, reinterpret_cast<std::unique_ptr<ArkNpcGameEffectInstance>*>(_return_buf_)); }
	void OnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const { FOnAttached(this, _npc, _gameEffectInstance); }
	void OnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const { FOnReattached(this, _npc, _gameEffectInstance); }
	void OnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const { FOnDetached(this, _npc, _gameEffectInstance); }
	void OnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const { FOnReceiveSignal(this, _npc, _gameEffectInstance, _package); }
	float ModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const { return FModifyDamage(this, _npc, _gameEffectInstance, _modifiedDamage, _hitInfo, _package); }
	void OnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const { FOnTakeDamage(this, _npc, _gameEffectInstance, _hitInfo, _package); }
	void OnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const { FOnDealtDamage(this, _npc, _gameEffectInstance, _damagedEntityId); }
	void OnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const { FOnDied(this, _npc, _gameEffectInstance); }
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void Serialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const { FSerialize(this, _npc, _gameEffectInstance, _serializer); }
	void PostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const { FPostSerialize(this, _npc, _gameEffectInstance); }
	virtual const char* DoGetClassName() const = 0;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const = 0;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const = 0;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const = 0;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const = 0;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const = 0;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const = 0;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const = 0;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const = 0;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const = 0;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const = 0;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const = 0;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const = 0;

#if 0
	static const char* ClassName();
	ArkNpcGameEffect();
	ArkNpcGameEffect(const ArkNpcGameEffect& _arg0_);
	ArkNpcGameEffect& operator=(const ArkNpcGameEffect& _arg0_);
#endif

	static inline auto FGetClassName = PreyFunction<const char* (const ArkNpcGameEffect* const _this)>(0x1855F90);
	static inline auto FMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffect* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x13384F0);
	static inline auto FOnAttached = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1338520);
	static inline auto FOnReattached = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1727910);
	static inline auto FOnDetached = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x5A35F0);
	static inline auto FOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1AEA770);
	static inline auto FModifyDamage = PreyFunction<float(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1338510);
	static inline auto FOnTakeDamage = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1338540);
	static inline auto FOnDealtDamage = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x18A63A0);
	static inline auto FOnDied = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1338530);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0xE94B70);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1338550);
	static inline auto FPostSerialize = PreyFunction<void(const ArkNpcGameEffect* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x16C6820);
};
#endif // MOONCRASH
