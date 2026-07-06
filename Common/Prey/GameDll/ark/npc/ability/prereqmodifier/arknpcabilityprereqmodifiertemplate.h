// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereqmodifier/ArkNpcAbilityPrereqModifier.h>
#include <_unknown/ArkNpcAbilityPrereqModification_Add.h>
#include <_unknown/ArkNpcAbilityPrereqModifierCondition_Equal.h>
#include <_unknown/ArkNpcAbilityPrereqModifierCondition_Greater.h>
#include <_unknown/ArkNpcAbilityPrereqModifierCondition_Less.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual;
class ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual;
class ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater;
class ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess;
class ArkNpcAbilityPrereqModifier_AddIfLowG;

// ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h
class ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
	: public ArkNpcAbilityPrereqModifier
	, public ArkNpcAbilityPrereqModifierCondition_Equal
	, public ArkNpcAbilityPrereqModification_Add
{ // Size=16 (0x10)
public:
	virtual ~ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>();
	virtual const char* DoGetClassName() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereqModifier& _other) const;
	virtual float DoModify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const;

#if 0
	ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>();
	bool SortsBefore(const ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual& _arg0_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this)>(0x13802E0);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpcAbilityPrereqModifier& _other)>(0x1380420);
	static inline auto FDoModify = PreyFunction<float(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x1380330);
};

// ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h
class ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
	: public ArkNpcAbilityPrereqModifier
	, public ArkNpcAbilityPrereqModifierCondition_Equal
	, public ArkNpcAbilityPrereqModification_Add
{ // Size=16 (0x10)
public:
	virtual ~ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>();
	virtual const char* DoGetClassName() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereqModifier& _other) const;
	virtual float DoModify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const;

#if 0
	ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>();
	bool SortsBefore(const ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual& _arg0_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this)>(0x13802F0);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpcAbilityPrereqModifier& _other)>(0x1380420);
	static inline auto FDoModify = PreyFunction<float(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x1380360);
};

// ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h
class ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>
	: public ArkNpcAbilityPrereqModifier
	, public ArkNpcAbilityPrereqModifierCondition_Greater
	, public ArkNpcAbilityPrereqModification_Add
{ // Size=16 (0x10)
public:
	virtual ~ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>();
	virtual const char* DoGetClassName() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereqModifier& _other) const;
	virtual float DoModify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const;

#if 0
	ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>();
	bool SortsBefore(const ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater& _arg0_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>* const _this)>(0x1380300);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpcAbilityPrereqModifier& _other)>(0x1380420);
	static inline auto FDoModify = PreyFunction<float(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x1380390);
};

// ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h
class ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>
	: public ArkNpcAbilityPrereqModifier
	, public ArkNpcAbilityPrereqModifierCondition_Less
	, public ArkNpcAbilityPrereqModification_Add
{ // Size=16 (0x10)
public:
	virtual ~ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>();
	virtual const char* DoGetClassName() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereqModifier& _other) const;
	virtual float DoModify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const;

#if 0
	ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>();
	bool SortsBefore(const ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess& _arg0_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>* const _this)>(0x1380310);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpcAbilityPrereqModifier& _other)>(0x1380420);
	static inline auto FDoModify = PreyFunction<float(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x13803C0);
};

// ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
// Header:  Prey/GameDll/ark/npc/ability/prereqmodifier/arknpcabilityprereqmodifiertemplate.h
class ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>
	: public ArkNpcAbilityPrereqModifier
	, public ArkNpcAbilityPrereqModifierCondition_Equal
	, public ArkNpcAbilityPrereqModification_Add
{ // Size=16 (0x10)
public:
	virtual ~ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>();
	virtual const char* DoGetClassName() const;
	virtual bool DoSortsBefore(const ArkNpcAbilityPrereqModifier& _other) const;
	virtual float DoModify(const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value) const;

#if 0
	ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>();
	bool SortsBefore(const ArkNpcAbilityPrereqModifier_AddIfLowG& _arg0_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this)>(0x1380320);
	static inline auto FDoSortsBefore = PreyFunction<bool(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpcAbilityPrereqModifier& _other)>(0x1380420);
	static inline auto FDoModify = PreyFunction<float(const ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>* const _this, const ArkNpc& _npc, const ArkNpcAbilityParams& _params, float _value)>(0x13803F0);
};
#endif // MOONCRASH
