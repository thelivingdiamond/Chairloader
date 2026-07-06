// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/hitdeathreactionsdefs.h>
#include <_unknown/Functor3.h>
#include <_unknown/Functor4wRet.h>

namespace ArkNpcCustomHitReaction
{
enum class Type;
} // namespace ArkNpcCustomHitReaction
class CCryActor;
struct HitInfo;
struct SReactionParams;
class SmartScriptTable;

// CCustomReactionFunctions
// Header:  Prey/GameDll/CustomReactionFunctions.h
class CCustomReactionFunctions
{ // Size=136 (0x88)
public:
	using ValidationFunctor = Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool>;
	using ValidationFncContainer = std::unordered_map<CryStringT<char>,Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool>,stl::hash_stricmp<CryStringT<char> >,stl::hash_stricmp<CryStringT<char> >,std::allocator<std::pair<CryStringT<char> const ,Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool> > > >;
	using ExecutionFunctor = Functor3<CCryActor &,SReactionParams const &,HitInfo const &>;
	using ExecutionFncContainer = std::unordered_map<CryStringT<char>,Functor3<CCryActor &,SReactionParams const &,HitInfo const &>,stl::hash_stricmp<CryStringT<char> >,stl::hash_stricmp<CryStringT<char> >,std::allocator<std::pair<CryStringT<char> const ,Functor3<CCryActor &,SReactionParams const &,HitInfo const &> > > >;

	std::unordered_map<CryStringT<char>,Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool>,stl::hash_stricmp<CryStringT<char> >,stl::hash_stricmp<CryStringT<char> >,std::allocator<std::pair<CryStringT<char> const ,Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool> > > > m_validationFunctors;
	std::unordered_map<CryStringT<char>,Functor3<CCryActor &,SReactionParams const &,HitInfo const &>,stl::hash_stricmp<CryStringT<char> >,stl::hash_stricmp<CryStringT<char> >,std::allocator<std::pair<CryStringT<char> const ,Functor3<CCryActor &,SReactionParams const &,HitInfo const &> > > > m_executionFunctors;
	uint16_t m_shotgunShellProjectile;

	CCustomReactionFunctions();
	void InitCustomReactionsData() { FInitCustomReactionsData(this); }
	bool CallCustomValidationFunction(bool& bResult, SmartScriptTable hitDeathReactionsTable, CCryActor& actor, const SReactionParams::SValidationParams& validationParams, const HitInfo& hitInfo, ArkNpcCustomHitReaction::Type _customType) const { return FCallCustomValidationFunction(this, bResult, hitDeathReactionsTable, actor, validationParams, hitInfo, _customType); }
	bool CallCustomExecutionFunction(SmartScriptTable hitDeathReactionsTable, const string& function, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo) const { return FCallCustomExecutionFunction(this, hitDeathReactionsTable, function, actor, reactionParams, hitInfo); }
	bool RegisterCustomValidationFunction(const string& sName, const Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool>& validationFunctor) { return FRegisterCustomValidationFunction(this, sName, validationFunctor); }
	bool RegisterCustomExecutionFunction(const string& sName, const Functor3<CCryActor &,SReactionParams const &,HitInfo const &>& executionFunctor) { return FRegisterCustomExecutionFunction(this, sName, executionFunctor); }
	void RegisterCustomFunctions() { FRegisterCustomFunctions(this); }
	void FallAndPlay_Reaction(CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo) { FFallAndPlay_Reaction(this, actor, reactionParams, hitInfo); }
	void DeathImpulse_Reaction(CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo) { FDeathImpulse_Reaction(this, actor, reactionParams, hitInfo); }
	void DeathImpulse_PowerMelee(CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo) { FDeathImpulse_PowerMelee(this, actor, reactionParams, hitInfo); }
	void MeleeDeath_Reaction(CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo) { FMeleeDeath_Reaction(this, actor, reactionParams, hitInfo); }
	void ReactionDoNothing(CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo) { FReactionDoNothing(this, actor, reactionParams, hitInfo); }

#if 0
	std::shared_ptr<CHitDeathReactions> GetActorHitDeathReactions(CCryActor& _arg0_) const;
#endif

	static inline auto FCCustomReactionFunctionsOv2 = PreyFunction<void(CCustomReactionFunctions* const _this)>(0x17D4270);
	static inline auto FInitCustomReactionsData = PreyFunction<void(CCustomReactionFunctions* const _this)>(0x17D4A40);
	static inline auto FCallCustomValidationFunction = PreyFunction<bool(const CCustomReactionFunctions* const _this, bool& bResult, SmartScriptTable hitDeathReactionsTable, CCryActor& actor, const SReactionParams::SValidationParams& validationParams, const HitInfo& hitInfo, ArkNpcCustomHitReaction::Type _customType)>(0x17D4540);
	static inline auto FCallCustomExecutionFunction = PreyFunction<bool(const CCustomReactionFunctions* const _this, SmartScriptTable hitDeathReactionsTable, const string& function, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo)>(0x17D4330);
	static inline auto FRegisterCustomValidationFunction = PreyFunction<bool(CCustomReactionFunctions* const _this, const string& sName, const Functor4wRet<CCryActor &,SReactionParams::SValidationParams const &,HitInfo const &,enum ArkNpcCustomHitReaction::Type,bool>& validationFunctor)>(0x17D5140);
	static inline auto FRegisterCustomExecutionFunction = PreyFunction<bool(CCustomReactionFunctions* const _this, const string& sName, const Functor3<CCryActor &,SReactionParams const &,HitInfo const &>& executionFunctor)>(0x17D4BA0);
	static inline auto FRegisterCustomFunctions = PreyFunction<void(CCustomReactionFunctions* const _this)>(0x17D4C20);
	static inline auto FFallAndPlay_Reaction = PreyFunction<void(CCustomReactionFunctions* const _this, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo)>(0x17D49D0);
	static inline auto FDeathImpulse_Reaction = PreyFunction<void(CCustomReactionFunctions* const _this, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo)>(0x17D4910);
	static inline auto FDeathImpulse_PowerMelee = PreyFunction<void(CCustomReactionFunctions* const _this, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo)>(0x17D48A0);
	static inline auto FMeleeDeath_Reaction = PreyFunction<void(CCustomReactionFunctions* const _this, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo)>(0x17D4A80);
	static inline auto FReactionDoNothing = PreyFunction<void(CCustomReactionFunctions* const _this, CCryActor& actor, const SReactionParams& reactionParams, const HitInfo& hitInfo)>(0x17D4B30);
};
#endif // MOONCRASH
