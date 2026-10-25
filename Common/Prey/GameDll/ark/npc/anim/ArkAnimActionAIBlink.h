// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>

class CTagDefinition;
struct SAnimationContext;
struct SControllerDef;

// CArkAnimActionAIBlink
// Header:  Prey/GameDll/ark/npc/anim/ArkAnimActionAIBlink.h
class CArkAnimActionAIBlink : public TAction<SAnimationContext>
{ // Size=136 (0x88)
public:
	using TBase = TAction<SAnimationContext>;

#ifndef MOONCRASH
	static inline auto s_kRandIntervalMin = PreyGlobal<const float>(0x1DFDFB4);
	static inline auto s_kRandIntervalMax = PreyGlobal<const float>(0x1DFDFB8);
#else
	static inline auto s_kRandIntervalMin = PreyGlobal<const float>(0x1F41684);
	static inline auto s_kRandIntervalMax = PreyGlobal<const float>(0x1F41688);
#endif
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

#ifndef MOONCRASH
	static inline auto FGetName = PreyFunction<const char* (const CArkAnimActionAIBlink* const _this)>(0x11E14A0);
	static inline auto FDoDelete = PreyFunction<void(CArkAnimActionAIBlink* const _this)>(0xA97D40);
	static inline auto FCArkAnimActionAIBlink = PreyFunction<void(CArkAnimActionAIBlink* const _this)>(0x11E1090);
	static inline auto FOnInitialise = PreyFunction<void(CArkAnimActionAIBlink* const _this)>(0x11E1680);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CArkAnimActionAIBlink* const _this, float _timePassed)>(0x11E16D0);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CArkAnimActionAIBlink* const _this, float _timePassed)>(0x11E18A0);
	static inline auto FOnSequenceFinished = PreyFunction<void(CArkAnimActionAIBlink* const _this, int layer, unsigned scopeId)>(0x11E1680);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& _context)>(0x11E15C0);
	static inline auto FFindFragmentId = PreyFunction<int(const SAnimationContext& context)>(0x11E1240);
	static inline auto FUpdateBlink = PreyFunction<void(CArkAnimActionAIBlink* const _this, float _timePassed)>(0x11E1700);
#else
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
#endif
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

#ifndef MOONCRASH
	static inline auto FGetName = PreyFunction<const char* (const CArkAnimActionAIEyeSaccade* const _this)>(0x11E14B0);
	static inline auto FDoDelete = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0xA97D40);
	static inline auto FCArkAnimActionAIEyeSaccade = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x11E1150);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& _context)>(0x11E15E0);
	static inline auto FOnInitialise = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x11E1600);
	static inline auto FFindFragmentId = PreyFunction<int(const SAnimationContext& context)>(0x11E1370);
#else
	static inline auto FGetName = PreyFunction<const char* (const CArkAnimActionAIEyeSaccade* const _this)>(0x126D180);
	static inline auto FDoDelete = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x3E3960);
	static inline auto FCArkAnimActionAIEyeSaccade = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x126CE70);
	static inline auto FIsSupported = PreyFunction<bool(const SAnimationContext& _context)>(0x126D2B0);
	static inline auto FOnInitialise = PreyFunction<void(CArkAnimActionAIEyeSaccade* const _this)>(0x126D2D0);
	static inline auto FFindFragmentId = PreyFunction<int(const SAnimationContext& context)>(0x126D040);
#endif
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

#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(SMannequinAiBlinkUserParams* const _this, const SControllerDef& controllerDef)>(0x11E14C0);
#else
	static inline auto FInit = PreyFunction<void(SMannequinAiBlinkUserParams* const _this, const SControllerDef& controllerDef)>(0x126D190);
#endif
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

#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(SMannequinAiEyeSaccadeUserParams* const _this, const SControllerDef& controllerDef)>(0x11E1540);
#else
	static inline auto FInit = PreyFunction<void(SMannequinAiEyeSaccadeUserParams* const _this, const SControllerDef& controllerDef)>(0x126D210);
#endif
};

