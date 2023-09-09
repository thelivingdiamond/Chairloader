// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
//#include <Prey/CryAction/ICryMannequin.h>
//#include <Prey/CryAction/ICryMannequinUserParams.h>

class ArkNpc;
struct SAnimationContext;
struct SControllerDef;
class IAction;

// Header: FromCpp
// Prey/GameDll/ark/npc/arknpclookaroundcontrol.h
class CArkNpcLookAroundControl // Id=80141D5 Size=16
{
public:
	enum class EBehavior
	{
		Patrol = 0,
		Wander = 1,
		Max = 2,
	};

	bool m_bSuspended;
	bool m_bStateChange;
	bool m_bEnabled[2];
	float m_idleTime;
	_smart_ptr<IAction> m_pLookAroundAction;
	
	CArkNpcLookAroundControl();
	void Enable(CArkNpcLookAroundControl::EBehavior _behavior, bool _bEnable) { FEnable(this,_behavior,_bEnable); }
	void Suspend(ArkNpc *_pNpc, bool _bSuspend) { FSuspend(this,_pNpc,_bSuspend); }
	void Update(ArkNpc *_pNpc, float _dt) { FUpdate(this,_pNpc,_dt); }
	void ShutDown(ArkNpc *_pNpc) { FShutDown(this,_pNpc); }
	void SetIdleTime(float _idleTime) { FSetIdleTime(this,_idleTime); }
	float GetIdleTime() const { return FGetIdleTime(this); }
	
#if 0
	bool IsEnabled() const;
#endif
	
	static inline auto FEnable = PreyFunction<void(CArkNpcLookAroundControl *const _this, CArkNpcLookAroundControl::EBehavior _behavior, bool _bEnable)>(0x128F580);
	static inline auto FSuspend = PreyFunction<void(CArkNpcLookAroundControl *const _this, ArkNpc *_pNpc, bool _bSuspend)>(0x128F7D0);
	static inline auto FUpdate = PreyFunction<void(CArkNpcLookAroundControl *const _this, ArkNpc *_pNpc, float _dt)>(0x128F870);
	static inline auto FShutDown = PreyFunction<void(CArkNpcLookAroundControl *const _this, ArkNpc *_pNpc)>(0x128F780);
	static inline auto FSetIdleTime = PreyFunction<void(CArkNpcLookAroundControl *const _this, float _idleTime)>(0x128F760);
	static inline auto FGetIdleTime = PreyFunction<float(CArkNpcLookAroundControl const *const _this)>(0x128F5F0);
};
#if 0
// Header: FromCpp
// Prey/GameDll/ark/npc/arknpclookaroundcontrol.h
class CArkAnimActionLookAround : public TAction<SAnimationContext> // Id=801AA8D Size=128
{
public:
	using TBase = TAction<SAnimationContext>;
	
	virtual const char *GetName() const;
	virtual void DoDelete();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float timePassed);
	virtual ~CArkAnimActionLookAround();
	
#if 0
	static bool IsSupported(SAnimationContext const &arg0);
	static int FindFragmentId(SAnimationContext const &arg0);
#endif
	
	static inline auto FGetName = PreyFunction<const char *(CArkAnimActionLookAround const *const _this)>(0x128F620);
	static inline auto FDoDelete = PreyFunction<void(CArkAnimActionLookAround *const _this)>(0xA97D40);
	static inline auto FOnInitialise = PreyFunction<void(CArkAnimActionLookAround *const _this)>(0x128F6B0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CArkAnimActionLookAround *const _this, float timePassed)>(0x128F7F0);
};

// Header: FromCpp
// Prey/GameDll/ark/npc/arknpclookaroundcontrol.h
struct SMannequinNpcLookAroundParams : public IMannequinUserParams // Id=801AA8E Size=16
{
	struct FragmentIDs // Id=801AA8F Size=4
	{
		TMannequinAutoInit<int,-1> LookAround;
		
#if 0
		void Init(CTagDefinition const &arg0);
#endif
	};

	SMannequinNpcLookAroundParams::FragmentIDs fragmentIDs;
	
	virtual void Init(SControllerDef const &controllerDef);
	virtual ~SMannequinNpcLookAroundParams();
	
	static inline auto FInit = PreyFunction<void(SMannequinNpcLookAroundParams *const _this, SControllerDef const &controllerDef)>(0x128F630);
};

#endif