// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class CItem;
class ICrySizer;

// Header: Override
// Prey/GameDll/ark/ISchedulerAction.h
struct ISchedulerAction // Id=8013D63 Size=8
{
	virtual ~ISchedulerAction();
	virtual void execute(CItem *arg0) = 0;
	virtual void destroy() = 0;
	virtual void GetMemoryStatistics(ICrySizer *arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CItem;
class ICrySizer;

// ISchedulerAction
// Header:  Prey/GameDll/ark/ISchedulerAction.h
struct ISchedulerAction
{ // Size=8 (0x8)
	virtual ~ISchedulerAction();
	virtual void execute(CItem* _this) = 0;
	virtual void destroy() = 0;
	virtual void GetMemoryStatistics(ICrySizer* s) = 0;
};
#endif // !MOONCRASH
