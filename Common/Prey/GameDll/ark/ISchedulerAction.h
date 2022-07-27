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

