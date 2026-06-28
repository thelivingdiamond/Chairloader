// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <_unknown/TMannequinAutoInit.h>

class CTagDefinition;
struct SAnimationContext;
struct SControllerDef;

// CArkAnimActionAIBlink
// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
class CArkAnimActionAIBlink : public TAction<SAnimationContext>
{ // Size=136 (0x88)
public:
	using TBase = TAction<SAnimationContext>;

	static inline auto s_kRandIntervalMin = PreyGlobal<const float>(0x1F41684);
	static inline auto s_kRandIntervalMax = PreyGlobal<const float>(0x1F41688);
	float m_timer;
	bool m_bBlinking;
	bool m_bEnabled;
	bool m_bIsDead;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CArkAnimActionAIBlink();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float _timePassed);
	virtual IAction::EStatus UpdatePending(float _timePassed);
	virtual void OnSequenceFinished(int layer, unsigned scopeId);
	static bool IsSupported(const SAnimationContext& _context) { return FIsSupported(_context); }
	static int FindFragmentId(const SAnimationContext& context) { return FFindFragmentId(context); }
	void UpdateBlink(float _timePassed) { FUpdateBlink(this, _timePassed); }

#if 0
	void Enable(bool _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CArkAnimActionAIBlink* const _this)>(0x126D170);
	static inline auto FDoDelete = PreyFunction<void(CArkAnimActionAIBlink* const _this)>(0x3E3960);
	static inline auto FCArkAnimActionAIBlink = PreyFunction<void(CArkAnimActionAIBlink* const _this)>(0x126CDB0);
	static inline auto FOnInitialise = PreyFunction<void(CArkAnimActionAIBlink* const _this)>(0x126D350);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CArkAnimActionAIBlink* const _this, float _timePassed)>(0x126D3A0);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CArkAnimActionAIBlink* const _this, float _timePassed)>(0x126D570);
	static inline auto FOnSequenceFinished = PreyFunction<void(CArkAnimActionAIBlink* const _this, int layer, unsigned scopeId)>(0x126D350);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& _context)>(0x126D290);
	static inline auto FFindFragmentId = PreyFunction<int(const SAnimationContext& context)>(0x126CF10);
	static inline auto FUpdateBlink = PreyFunction<void(CArkAnimActionAIBlink* const _this, float _timePassed)>(0x126D3D0);
};

// CArkAnimActionAIEyeSaccade
// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
class CArkAnimActionAIEyeSaccade : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	using TBase = TAction<SAnimationContext>;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CArkAnimActionAIEyeSaccade();
	static bool IsSupported(const SAnimationContext& _context) { return FIsSupported(_context); }
	virtual void OnInitialise();
	static int FindFragmentId(const SAnimationContext& context) { return FFindFragmentId(context); }

	static inline auto FGetName = PreyFunction<const char* (const CArkAnimActionAIEyeSaccade* const _this)>(0x126D180);
	static inline auto FDoDelete = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x3E3960);
	static inline auto FCArkAnimActionAIEyeSaccade = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x126CE70);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& _context)>(0x126D2B0);
	static inline auto FOnInitialise = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x126D2D0);
	static inline auto FFindFragmentId = PreyFunction<int(const SAnimationContext& context)>(0x126D040);
};

// SMannequinAiBlinkUserParams
// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
struct SMannequinAiBlinkUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiBlinkUserParams::FragmentIDs
	// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> LookBlink;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiBlinkUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiBlinkUserParams* const _this, const SControllerDef& controllerDef)>(0x126D190);
};

// SMannequinAiEyeSaccadeUserParams
// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
struct SMannequinAiEyeSaccadeUserParams : public IMannequinUserParams
{ // Size=16 (0x10)
	// SMannequinAiEyeSaccadeUserParams::FragmentIDs
	// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
	struct FragmentIDs
	{ // Size=4 (0x4)
		TMannequinAutoInit<int,-1> LookSaccade;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAiEyeSaccadeUserParams::FragmentIDs fragmentIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAiEyeSaccadeUserParams* const _this, const SControllerDef& controllerDef)>(0x126D210);
};
#endif // MOONCRASH
