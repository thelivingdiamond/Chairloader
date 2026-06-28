// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
//#include <Prey/GameDll/ark/npc/ability/arknpcability.h>

struct ArkComplexRoomPerceptionInfo;
class ArkNpc;
class ArkNpcAbilityInstance;
class ArkNpcAbilityParams;

// Header: FromCpp
// Prey/GameDll/ark/npc/ability/arknpcability.h
class ArkRoomPerceiver // Id=8014315 Size=8
{
public:
	uint64_t GetRoomPerceptionModelId() const { return FGetRoomPerceptionModelId(this); }
	unsigned GetAreaContainerEntityId() const { return FGetAreaContainerEntityId(this); }
	unsigned FindCurrentRoomEntityId() const { return FFindCurrentRoomEntityId(this); }
	void UpdateRoomPerception(ArkComplexRoomPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexContinuePerceivingPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId) { FUpdateRoomPerception(this,_pFirstComplexStartPerceivingPerceptionInfo,_pLastComplexStartPerceivingPerceptionInfo,_pFirstComplexContinuePerceivingPerceptionInfo,_pLastComplexContinuePerceivingPerceptionInfo,_pFirstComplexStopPerceivingEntityId,_pLastComplexStopPerceivingEntityId); }
	virtual Vec3 DoGetRoomPosition() const = 0;
	virtual unsigned DoGetRoomPerceiverEntityId() const = 0;
	virtual uint64_t DoGetRoomPerceptionModelId() const = 0;
	virtual unsigned DoGetAreaContainerEntityId() const = 0;
	virtual unsigned DoFindCurrentRoomEntityId() const = 0;
	virtual void DoUpdateRoomPerception(ArkComplexRoomPerceptionInfo const *arg0, ArkComplexRoomPerceptionInfo const *arg1, ArkComplexRoomPerceptionInfo const *arg2, ArkComplexRoomPerceptionInfo const *arg3, const unsigned *arg4, const unsigned *arg5) = 0;
	
#if 0
	unsigned GetRoomPerceiverEntityId() const;
	Vec3 GetRoomPosition() const;
#endif
	
	static inline auto FGetRoomPerceptionModelId = PreyFunction<uint64_t(ArkRoomPerceiver const *const _this)>(0x15AAEA0);
	static inline auto FGetAreaContainerEntityId = PreyFunction<unsigned(ArkRoomPerceiver const *const _this)>(0x12941A0);
	static inline auto FFindCurrentRoomEntityId = PreyFunction<unsigned(ArkRoomPerceiver const *const _this)>(0x12B5B30);
	static inline auto FUpdateRoomPerception = PreyFunction<void(ArkRoomPerceiver *const _this, ArkComplexRoomPerceptionInfo const *_pFirstComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexStartPerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pFirstComplexContinuePerceivingPerceptionInfo, ArkComplexRoomPerceptionInfo const *_pLastComplexContinuePerceivingPerceptionInfo, const unsigned *_pFirstComplexStopPerceivingEntityId, const unsigned *_pLastComplexStopPerceivingEntityId)>(0x12B5B20);
};

// Header: FromCpp
// Prey/GameDll/ark/npc/ability/ArkNpcAbility.h
class ArkNpcAbility // Id=80157DB Size=8
{
public:
	virtual ~ArkNpcAbility();

#if 0
	std::unique_ptr<ArkNpcAbilityInstance> MakeAbilityInstance() const { return FMakeAbilityInstance(this); }
#endif
	void Initialize(ArkNpc &_npc, ArkNpcAbilityInstance &_abilityInstance) const { FInitialize(this,_npc,_abilityInstance); }
	void Finalize(ArkNpc &_npc, ArkNpcAbilityInstance &_abilityInstance) const { FFinalize(this,_npc,_abilityInstance); }
	bool CanBePerformed(ArkNpc const &_npc, uint64_t _contextId, ArkNpcAbilityParams const &_params, ArkNpcAbilityInstance const &_abilityInstance) const { return FCanBePerformed(this,_npc,_contextId,_params,_abilityInstance); }
	EArkNpcAbilityPerformanceResult Perform(ArkNpc &_npc, uint64_t _contextId, ArkNpcAbilityParams const &_params, ArkNpcAbilityInstance &_abilityInstance) const { return FPerform(this,_npc,_contextId,_params,_abilityInstance); }
	void Update(ArkNpc &_npc, float _elapsedTime, ArkNpcAbilityInstance &_abilityInstance) const { FUpdate(this,_npc,_elapsedTime,_abilityInstance); }
	void Interrupt(ArkNpc &_npc, ArkNpcAbilityInstance &_abilityInstance) const { FInterrupt(this,_npc,_abilityInstance); }
	ArkNpcAbility();
	virtual const char *DoGetClassName() const = 0;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const = 0;
	virtual void DoInitialize(ArkNpc &arg0, ArkNpcAbilityInstance &arg1) const = 0;
	virtual void DoFinalize(ArkNpc &arg0, ArkNpcAbilityInstance &arg1) const = 0;
	virtual bool DoCanBePerformed(ArkNpc const &arg0, uint64_t arg1, ArkNpcAbilityParams const &arg2, ArkNpcAbilityInstance const &arg3) const = 0;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc &arg0, uint64_t arg1, ArkNpcAbilityParams const &arg2, ArkNpcAbilityInstance &arg3) const = 0;
	virtual void DoUpdate(ArkNpc &arg0, float arg1, ArkNpcAbilityInstance &arg2) const = 0;
	virtual void DoInterrupt(ArkNpc &arg0, ArkNpcAbilityInstance &arg1) const = 0;
	
#if 0
	static const char *ClassName();
	const char *GetClassName() const;
#endif

	static inline auto FMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>(ArkNpcAbility const *const _this)>(0x1294170);
	static inline auto FInitialize = PreyFunction<void(ArkNpcAbility const *const _this, ArkNpc &_npc, ArkNpcAbilityInstance &_abilityInstance)>(0x12941A0);
	static inline auto FFinalize = PreyFunction<void(ArkNpcAbility const *const _this, ArkNpc &_npc, ArkNpcAbilityInstance &_abilityInstance)>(0x12B5B30);
	static inline auto FCanBePerformed = PreyFunction<bool(ArkNpcAbility const *const _this, ArkNpc const &_npc, uint64_t _contextId, ArkNpcAbilityParams const &_params, ArkNpcAbilityInstance const &_abilityInstance)>(0x12B5B20);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(ArkNpcAbility const *const _this, ArkNpc &_npc, uint64_t _contextId, ArkNpcAbilityParams const &_params, ArkNpcAbilityInstance &_abilityInstance)>(0x1143E80);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAbility const *const _this, ArkNpc &_npc, float _elapsedTime, ArkNpcAbilityInstance &_abilityInstance)>(0x12E91B0);
	static inline auto FInterrupt = PreyFunction<void(ArkNpcAbility const *const _this, ArkNpc &_npc, ArkNpcAbilityInstance &_abilityInstance)>(0x12B5B40);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpc;
class ArkNpcAbilityInstance;
class ArkNpcAbilityParams;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbility
// Header:  Prey/GameDll/ark/npc/ability/ArkNpcAbility.h
class ArkNpcAbility
{ // Size=8 (0x8)
public:
	virtual ~ArkNpcAbility();
	std::unique_ptr<ArkNpcAbilityInstance> MakeAbilityInstance() const { alignas(std::unique_ptr<ArkNpcAbilityInstance>) std::byte _return_buf_[sizeof(std::unique_ptr<ArkNpcAbilityInstance>)]; return *FMakeAbilityInstance(this, reinterpret_cast<std::unique_ptr<ArkNpcAbilityInstance>*>(_return_buf_)); }
	void Initialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const { FInitialize(this, _npc, _abilityInstance); }
	void Finalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const { FFinalize(this, _npc, _abilityInstance); }
	bool CanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const { return FCanBePerformed(this, _npc, _contextId, _params, _abilityInstance); }
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void Interrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const { FInterrupt(this, _npc, _abilityInstance); }
	ArkNpcAbility();
	virtual const char* DoGetClassName() const = 0;
	virtual std::unique_ptr<ArkNpcAbilityInstance> DoMakeAbilityInstance() const = 0;
	virtual void DoInitialize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const = 0;
	virtual void DoFinalize(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const = 0;
	virtual bool DoCanBePerformed(const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance) const = 0;
	virtual EArkNpcAbilityPerformanceResult DoPerform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance) const = 0;
	virtual void DoUpdate(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance) const = 0;
	virtual void DoInterrupt(ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance) const = 0;

#if 0
	static const char* ClassName();
	const char* GetClassName() const;
	ArkNpcAbility(const ArkNpcAbility& _arg0_);
	ArkNpcAbility& operator=(const ArkNpcAbility& _arg0_);
#endif

	static inline auto FMakeAbilityInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityInstance>*(const ArkNpcAbility* const _this, std::unique_ptr<ArkNpcAbilityInstance>* _return_value_)>(0x13384F0);
	static inline auto FInitialize = PreyFunction<void(const ArkNpcAbility* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1338520);
	static inline auto FFinalize = PreyFunction<void(const ArkNpcAbility* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x1727910);
	static inline auto FCanBePerformed = PreyFunction<bool(const ArkNpcAbility* const _this, const ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, const ArkNpcAbilityInstance& _abilityInstance)>(0x135F1E0);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance& _abilityInstance)>(0x118AC40);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance& _abilityInstance)>(0x127B6D0);
	static inline auto FInterrupt = PreyFunction<void(const ArkNpcAbility* const _this, ArkNpc& _npc, ArkNpcAbilityInstance& _abilityInstance)>(0x135F1F0);
	static inline auto FArkNpcAbilityOv1 = PreyFunction<void(ArkNpcAbility* const _this)>(0x135F1D0);
};
#endif // !MOONCRASH
