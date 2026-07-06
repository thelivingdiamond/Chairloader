// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <_unknown/TMannequinAutoInit.h>

class CPlayer;
class CTagDefinition;
class IAnimationDatabase;
struct SAnimationContext;
struct SControllerDef;
struct SFragTagState;

// CAnimActionAIStance
// Header:  Prey/GameDll/AnimActionAIStance.h
class CAnimActionAIStance : public TAction<SAnimationContext>
{ // Size=144 (0x90)
public:
	using TBase = TAction<SAnimationContext>;

	CPlayer* const m_pPlayer;
	const EStance m_targetStance;
	bool m_isPlayerAnimationStanceSet;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CAnimActionAIStance(int priority, CPlayer* pPlayer, const EStance targetStance);
	virtual void Enter();
	virtual void Exit();
	virtual IAction::EStatus Update(float elapsedSeconds);
	virtual IAction::EStatus UpdatePending(float timePassed);
	virtual void OnInitialise();
	unsigned FindStanceActionScopeMask(const SAnimationContext& context) const { return FFindStanceActionScopeMask(this, context); }
	bool FragmentExistsInDatabase(const SAnimationContext& context, const IAnimationDatabase& database) const { return FFragmentExistsInDatabase(this, context, database); }
	bool FindFragmentInfo(const SAnimationContext& context, int& fragmentIdOut, SFragTagState& fragTagStateOut) const { return FFindFragmentInfo(this, context, fragmentIdOut, fragTagStateOut); }

#if 0
	EStance GetTargetStance() const;
	bool IsPlayerAnimationStanceSet() const;
	void SetMovementParameters();
	void RestoreMovementParameters();
	void SetPlayerAnimationStanceOnce();
	EStance GetPlayerAnimationStance() const;
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionAIStance* const _this)>(0x10D38B0);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionAIStance* const _this)>(0x3E3960);
	static inline auto FCAnimActionAIStance = PreyFunction<void(CAnimActionAIStance* const _this, int priority, CPlayer* pPlayer, const EStance targetStance)>(0x10D3310);
	static inline auto FEnter = PreyFunction<void(CAnimActionAIStance* const _this)>(0x10D3410);
	static inline auto FExit = PreyFunction<void(CAnimActionAIStance* const _this)>(0x10D3480);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionAIStance* const _this, float elapsedSeconds)>(0x10D3F50);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CAnimActionAIStance* const _this, float timePassed)>(0x10D3FF0);
	static inline auto FOnInitialise = PreyFunction<void(CAnimActionAIStance* const _this)>(0x10D3EC0);
	static inline auto FFindStanceActionScopeMask = PreyFunction<unsigned(const CAnimActionAIStance* const _this, const SAnimationContext& context)>(0x10D3730);
	static inline auto FFragmentExistsInDatabase = PreyFunction<bool(const CAnimActionAIStance* const _this, const SAnimationContext& context, const IAnimationDatabase& database)>(0x10D37F0);
	static inline auto FFindFragmentInfo = PreyFunction<bool(const CAnimActionAIStance* const _this, const SAnimationContext& context, int& fragmentIdOut, SFragTagState& fragTagStateOut)>(0x10D3530);
};

// SMannequinAiStanceUserParams
// Header:  Prey/GameDll/AnimActionAIStance.h
struct SMannequinAiStanceUserParams : public IMannequinUserParams
{ // Size=88 (0x58)
	// SMannequinAiStanceUserParams::ScopeIDs
	// Header:  Prey/GameDll/AnimActionAIStance.h
	struct ScopeIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> FullBody3P;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	// SMannequinAiStanceUserParams::Fragments
	// Header:  Prey/GameDll/AnimActionAIStance.h
	struct Fragments
	{ // Size=72 (0x48)
		// SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance
		// Header:  Prey/GameDll/AnimActionAIStance.h
		struct SCODE_AI_ChangeStance
		{ // Size=72 (0x48)
			// SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance::FragmentTagIDs
			// Header:  Prey/GameDll/AnimActionAIStance.h
			struct FragmentTagIDs
			{ // Size=60 (0x3C)
				TMannequinAutoInit<int,-1> ToCoverHigh;
				TMannequinAutoInit<int,-1> ToCoverLow;
				TMannequinAutoInit<int,-1> ToRelaxed;
				TMannequinAutoInit<int,-1> ToAlerted;
				TMannequinAutoInit<int,-1> ToStand;
				TMannequinAutoInit<int,-1> ToSwim;
				TMannequinAutoInit<int,-1> ToCrouch;
				TMannequinAutoInit<int,-1> ToHover;
				TMannequinAutoInit<int,-1> ToCorrupted;
				TMannequinAutoInit<int,-1> ToInvestigateAnomaly;
				TMannequinAutoInit<int,-1> ToInvestigateDanger;
				TMannequinAutoInit<int,-1> ToInvestigateVision;
				TMannequinAutoInit<int,-1> ToHunt;
				TMannequinAutoInit<int,-1> ToGunUp;
				TMannequinAutoInit<int,-1> ToCharge;

				void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

				static inline auto FInit = PreyFunction<void(SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance::FragmentTagIDs* const _this, const CTagDefinition& tagDefs)>(0x10D38C0);
			};

			TMannequinAutoInit<int,-1> fragmentID;
			SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance::FragmentTagIDs fragmentTagIDs;
			const CTagDefinition* pTagDefinition;

		#if 0
			SCODE_AI_ChangeStance();
			void Init(const SControllerDef& _arg0_);
		#endif
		};

		SMannequinAiStanceUserParams::Fragments::SCODE_AI_ChangeStance CODE_AI_ChangeStance;

	#if 0
		void Init(const SControllerDef& _arg0_);
	#endif
	};

	SMannequinAiStanceUserParams::ScopeIDs scopeIDs;
	SMannequinAiStanceUserParams::Fragments fragments;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiStanceUserParams* const _this, const SControllerDef& controllerDef)>(0x10D3D10);
};
#endif // MOONCRASH
