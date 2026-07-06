// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpc;
class ArkNpcAbilityContextInstanceStorage;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;
class ArkNpcAbilityPrereqModifier;

// ArkNpcAbilityPrereq
// Header:  Prey/GameDll/ark/npc/ability/prereq/ArkNpcAbilityPrereq.h
class ArkNpcAbilityPrereq
{ // Size=24 (0x18)
public:
	const ArkNpcAbilityPrereqModifier* const * m_ppFirstModifier;
	const ArkNpcAbilityPrereqModifier* const * m_ppLastModifier;

	const char* GetClassName() const { return FGetClassName(this); }
	virtual ~ArkNpcAbilityPrereq();
	bool IsGlobal() const { return FIsGlobal(this); }
	void SetModifiers(const ArkNpcAbilityPrereqModifier* const * _ppFirstModifier, const ArkNpcAbilityPrereqModifier* const * _ppLastModifier) { FSetModifiers(this, _ppFirstModifier, _ppLastModifier); }
	bool SortsBefore(const ArkNpcAbilityPrereq& _other) const { return FSortsBefore(this, _other); }
	std::unique_ptr<ArkNpcAbilityPrereqInstance> MakePrereqInstance() const { alignas(std::unique_ptr<ArkNpcAbilityPrereqInstance>) std::byte _return_buf_[sizeof(std::unique_ptr<ArkNpcAbilityPrereqInstance>)]; return *FMakePrereqInstance(this, reinterpret_cast<std::unique_ptr<ArkNpcAbilityPrereqInstance>*>(_return_buf_)); }
	ArkNpcAbilityPrereqInstance& GetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const { return FGetPrereqInstance(this, _storage); }
	void Initialize(ArkNpcAbilityPrereqInstance& _prereqInstance) const { FInitializeOv1(this, _prereqInstance); }
	void Initialize(const ArkNpc& _npc, ArkNpcAbilityPrereqInstance& _prereqInstance) const { FInitializeOv0(this, _npc, _prereqInstance); }
	void Finalize(ArkNpcAbilityPrereqInstance& _prereqInstance) const { FFinalizeOv1(this, _prereqInstance); }
	void Finalize(const ArkNpc& _npc, ArkNpcAbilityPrereqInstance& _prereqInstance) const { FFinalizeOv0(this, _npc, _prereqInstance); }
	void Update(float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const { FUpdateOv1(this, _elapsedTime, _prereqInstance); }
	void Update(const ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const { FUpdateOv0(this, _npc, _elapsedTime, _prereqInstance); }
	bool Evaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const { return FEvaluate(this, _npc, _params, _prereqInstance); }
	void OnContextStarted(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const { FOnContextStarted(this, _contextId, _prereqInstance); }
	void Serialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const { FSerialize(this, _serializer, _prereqInstance); }
	ArkNpcAbilityPrereq();
	void RequireReevaluation(ArkNpcAbilityPrereqInstance& _prereqInstance) const { FRequireReevaluation(this, _prereqInstance); }
	float ApplyModifiers(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const { return FApplyModifiersOv1(this, _npc, _params, _value); }
	unsigned ApplyModifiers(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, unsigned _value) const { return FApplyModifiersOv0(this, _npc, _params, _value); }
	virtual const char* DoGetClassName() const = 0;
	virtual bool DoIsGlobal() const = 0;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereq& _other) const = 0;
	virtual std::unique_ptr<ArkNpcAbilityPrereqInstance> DoMakePrereqInstance() const = 0;
	virtual ArkNpcAbilityPrereqInstance& DoGetPrereqInstance(ArkNpcAbilityContextInstanceStorage& _storage) const = 0;
	virtual void DoInitialize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const = 0;
	virtual void DoFinalize(const ArkNpc* _pNpc, ArkNpcAbilityPrereqInstance& _prereqInstance) const = 0;
	virtual void DoUpdate(const ArkNpc* _pNpc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance) const = 0;
	virtual bool DoEvaluate(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance) const = 0;
	virtual void DoOnPerformedContext(uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance) const = 0;
	virtual void DoSerialize(TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance) const = 0;

#if 0
	ArkNpcAbilityPrereq(const ArkNpcAbilityPrereq& _arg0_);
	ArkNpcAbilityPrereq& operator=(const ArkNpcAbilityPrereq& _arg0_);
	bool ModifiersSortBefore(const ArkNpcAbilityPrereq& _arg0_) const;
#endif

	static inline auto FGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereq* const _this)>(0x1855F90);
	static inline auto FIsGlobal = PreyFunction<bool(const ArkNpcAbilityPrereq* const _this)>(0x6CBC30);
	static inline auto FSetModifiers = PreyFunction<void(ArkNpcAbilityPrereq* const _this, const ArkNpcAbilityPrereqModifier* const * _ppFirstModifier, const ArkNpcAbilityPrereqModifier* const * _ppLastModifier)>(0x5670A0);
	static inline auto FSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereq* const _this, const ArkNpcAbilityPrereq& _other)>(0x139CE80);
	static inline auto FMakePrereqInstance = PreyFunction<std::unique_ptr<ArkNpcAbilityPrereqInstance>*(const ArkNpcAbilityPrereq* const _this, std::unique_ptr<ArkNpcAbilityPrereqInstance>* _return_value_)>(0xD77270);
	static inline auto FGetPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityPrereq* const _this, ArkNpcAbilityContextInstanceStorage& _storage)>(0x5A35F0);
	static inline auto FInitializeOv1 = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CE00);
	static inline auto FInitializeOv0 = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, const ArkNpc& _npc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1AEA770);
	static inline auto FFinalizeOv1 = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CDF0);
	static inline auto FFinalizeOv0 = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, const ArkNpc& _npc, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x127B6D0);
	static inline auto FUpdateOv1 = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CFC0);
	static inline auto FUpdateOv0 = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, const ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CFB0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNpcAbilityPrereq* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CDA0);
	static inline auto FOnContextStarted = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, uint64_t _contextId, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x1338530);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, TSerialize _serializer, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CE20);
	static inline auto FArkNpcAbilityPrereqOv1 = PreyFunction<void(ArkNpcAbilityPrereq* const _this)>(0x139CC60);
	static inline auto FRequireReevaluation = PreyFunction<void(const ArkNpcAbilityPrereq* const _this, ArkNpcAbilityPrereqInstance& _prereqInstance)>(0x139CE10);
	static inline auto FApplyModifiersOv1 = PreyFunction<float(const ArkNpcAbilityPrereq* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x139CD20);
	static inline auto FApplyModifiersOv0 = PreyFunction<unsigned(const ArkNpcAbilityPrereq* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, unsigned _value)>(0x139CC80);
};
#endif // MOONCRASH
