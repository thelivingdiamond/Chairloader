// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/item.h>
#include <Prey/GameDll/ark/CSchedulerActionPoolBase.h>
#include <Prey/GameDll/ark/ISchedulerAction.h>

class ICrySizer;
struct ITimer;

// Header: FromCpp
// Prey/GameDll/itemscheduler.h
class CItemScheduler // Id=8013D61 Size=104
{
public:
	struct SScheduledAction // Id=8013D62 Size=16
	{
		ISchedulerAction *action;
		bool persist;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	struct STimerAction // Id=8013D64 Size=16
	{
		ISchedulerAction *action;
		float time;
		bool persist;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	using TTimerActionVector = std::vector<CItemScheduler::STimerAction>;
	using TScheduledActionVector = std::vector<CItemScheduler::SScheduledAction>;
	
	struct compare_timers // Id=8013D8D Size=1
	{
#if 0
		bool operator()(CItemScheduler::STimerAction const &arg0, CItemScheduler::STimerAction const &arg1) const;
#endif
	};

	bool m_locked;
	bool m_busy;
	ITimer *m_pTimer;
	CItem *m_pItem;
	std::vector<CItemScheduler::STimerAction> m_timers;
	std::vector<CItemScheduler::STimerAction> m_actives;
	std::vector<CItemScheduler::SScheduledAction> m_schedule;
	
	void CItemScheduler(CItem *item);
	virtual void ~CItemScheduler();
	void Reset(bool keepPersistent) { FReset(this,keepPersistent); }
	void Update(float frameTime) { FUpdate(this,frameTime); }
	void TimerAction(float fTimeSeconds, ISchedulerAction *action, bool persistent) { FTimerActionOv0(this,fTimeSeconds,action,persistent); }
	void GetMemoryStatistics(ICrySizer *s) const { FGetMemoryStatistics(this,s); }
	void SetBusy(bool busy) { FSetBusy(this,busy); }
	
#if 0
	void TimerAction(unsigned arg0, ISchedulerAction *arg1, bool arg2);
	void TimerAction(int arg0, ISchedulerAction *arg1, bool arg2);
	void ScheduleAction(ISchedulerAction *arg0, bool arg1);
	bool IsBusy() const;
	void Lock(bool arg0);
	bool IsLocked();
#endif
	
	static inline auto FBitNotCItemScheduler = PreyFunction<void(CItemScheduler *const _this)>(0x1766E70);
	static inline auto FReset = PreyFunction<void(CItemScheduler *const _this, bool keepPersistent)>(0x1767140);
	static inline auto FUpdate = PreyFunction<void(CItemScheduler *const _this, float frameTime)>(0x17672E0);
	static inline auto FTimerActionOv0 = PreyFunction<void(CItemScheduler *const _this, float fTimeSeconds, ISchedulerAction *action, bool persistent)>(0x1767260);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CItemScheduler const *const _this, ICrySizer *s)>(0x17670A0);
	static inline auto FSetBusy = PreyFunction<void(CItemScheduler *const _this, bool busy)>(0x1767250);
};

// Header: Exact
// Prey/GameDll/itemscheduler.h
template <typename T>
class CSchedulerActionPool : public CSchedulerActionPoolBase, public stl::PoolAllocator<17, stl::PSyncNone, 0> // Id=801D359 Size=120
{
public:
#if 0
	virtual void Reset();
#endif
};

// Header: Exact
// Prey/GameDll/itemscheduler.h
template <typename T>
class CSchedulerAction : public ISchedulerAction // Id=801D358 Size=16
{
public:
	using Alloc = CSchedulerActionPool<T>;
	
	static Alloc m_alloc;
	T m_impl;
	
#if 0
	static CSchedulerAction *Create();
	static CSchedulerAction *Create(CItem::SelectAction const &arg0);
	virtual void execute(CItem *_this);
	virtual void destroy();
	virtual void GetMemoryStatistics(ICrySizer *s);
#endif
};

