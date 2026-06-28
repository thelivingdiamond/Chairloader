// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/Item.h>
#include <Prey/GameDll/ark/CSchedulerActionPoolBase.h>
#include <Prey/GameDll/ark/ISchedulerAction.h>

class CItem;
class ICrySizer;
struct ITimer;

// CItemScheduler
// Header:  Prey/GameDll/ItemScheduler.h
class CItemScheduler
{ // Size=104 (0x68)
public:
	// CItemScheduler::SScheduledAction
	// Header:  Prey/GameDll/ItemScheduler.h
	struct SScheduledAction
	{ // Size=16 (0x10)
		ISchedulerAction* action;
		bool persist;

	#if 0
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CItemScheduler::STimerAction
	// Header:  Prey/GameDll/ItemScheduler.h
	struct STimerAction
	{ // Size=16 (0x10)
		ISchedulerAction* action;
		float time;
		bool persist;

	#if 0
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CItemScheduler::compare_timers
	// Header:  Prey/GameDll/ItemScheduler.h
	struct compare_timers
	{ // Size=1 (0x1)
	#if 0
		bool operator()(const CItemScheduler::STimerAction& _arg0_, const CItemScheduler::STimerAction& _arg1_) const;
	#endif
	};

	using TTimerActionVector = std::vector<CItemScheduler::STimerAction>;
	using TScheduledActionVector = std::vector<CItemScheduler::SScheduledAction>;

	bool m_locked;
	bool m_busy;
	ITimer* m_pTimer;
	CItem* m_pItem;
	std::vector<CItemScheduler::STimerAction> m_timers;
	std::vector<CItemScheduler::STimerAction> m_actives;
	std::vector<CItemScheduler::SScheduledAction> m_schedule;

	CItemScheduler(CItem* item);
	virtual ~CItemScheduler();
	void Reset(bool keepPersistent) { FReset(this, keepPersistent); }
	void Update(float frameTime) { FUpdate(this, frameTime); }
	void TimerAction(float fTimeSeconds, ISchedulerAction* action, bool persistent) { FTimerActionOv0(this, fTimeSeconds, action, persistent); }
	void GetMemoryStatistics(ICrySizer* s) const { FGetMemoryStatistics(this, s); }
	void SetBusy(bool busy) { FSetBusy(this, busy); }

#if 0
	void TimerAction(unsigned _arg0_, ISchedulerAction* _arg1_, bool _arg2_);
	void TimerAction(int _arg0_, ISchedulerAction* _arg1_, bool _arg2_);
	void ScheduleAction(ISchedulerAction* _arg0_, bool _arg1_);
	bool IsBusy() const;
	void Lock(bool _arg0_);
	bool IsLocked();
#endif

	static inline auto FCItemSchedulerOv1 = PreyFunction<void(CItemScheduler* const _this, CItem* item)>(0x188DBD0);
	static inline auto FBitNotCItemScheduler = PreyFunction<void(CItemScheduler* const _this)>(0x188DC20);
	static inline auto FReset = PreyFunction<void(CItemScheduler* const _this, bool keepPersistent)>(0x188DEF0);
	static inline auto FUpdate = PreyFunction<void(CItemScheduler* const _this, float frameTime)>(0x188E090);
	static inline auto FTimerActionOv0 = PreyFunction<void(CItemScheduler* const _this, float fTimeSeconds, ISchedulerAction* action, bool persistent)>(0x188E010);
	static inline auto FGetMemoryStatistics = PreyFunction<void(const CItemScheduler* const _this, ICrySizer* s)>(0x188DE50);
	static inline auto FSetBusy = PreyFunction<void(CItemScheduler* const _this, bool busy)>(0x188E000);
};

// CSchedulerActionPool<CItem::SelectAction>
// Header:  Prey/GameDll/ItemScheduler.h
class CSchedulerActionPool<CItem::SelectAction> : public CSchedulerActionPoolBase, public stl::PoolAllocator<17,stl::PSyncNone,0>
{ // Size=120 (0x78)
public:
	virtual void Reset();

	static inline auto FReset = PreyFunction<void(CSchedulerActionPool<CItem::SelectAction>* const _this)>(0x1878B20);
};

// CSchedulerAction<CItem::SelectAction>
// Header:  Prey/GameDll/ItemScheduler.h
class CSchedulerAction<CItem::SelectAction> : public ISchedulerAction
{ // Size=16 (0x10)
public:
	using Alloc = CSchedulerActionPool<CItem::SelectAction>;

	static inline auto m_alloc = PreyGlobal<CSchedulerActionPool<CItem::SelectAction>>(0x23F0570);
	CItem::SelectAction m_impl;

	virtual void execute(CItem* _this);
	virtual void destroy();
	virtual void GetMemoryStatistics(ICrySizer* s);
	virtual ~CSchedulerAction<CItem::SelectAction>();

#if 0
	static CSchedulerAction<CItem::SelectAction>* Create();
	static CSchedulerAction<CItem::SelectAction>* Create(const CItem::SelectAction& _arg0_);
	CSchedulerAction<CItem::SelectAction>();
	CSchedulerAction<CItem::SelectAction>(const CItem::SelectAction& _arg0_);
#endif

	static inline auto Fexecute = PreyFunction<void(CSchedulerAction<CItem::SelectAction>* const _this, CItem* _this)>(0x1881340);
	static inline auto Fdestroy = PreyFunction<void(CSchedulerAction<CItem::SelectAction>* const _this)>(0x18812B0);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CSchedulerAction<CItem::SelectAction>* const _this, ICrySizer* s)>(0x455F00);
};
#endif // !MOONCRASH
