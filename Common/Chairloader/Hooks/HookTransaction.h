#pragma once

//! A Detours transaction. All hooks are to be installed/removed inside such transaction.
class HookTransaction : NoCopy
{
public:
	HookTransaction();
	~HookTransaction();

	//! Commits the transaction. On error, throws std::runtime_error.
	void Commit();

	//! Commits the transaction. On error, crashes the program.
	void CommitOrDie();

	//! Aborts the transaction. No hooks will be installed.
	void Abort();

private:
	//! Only one transaction is allowed by Detours at a time.
	//! Used by FunctionHookBase add new errors to the list.
	//! @returns the current transaction.
	static HookTransaction* GetCurrent();

	//! Saves a Detours error. Only first value is saved because calls after it return the last error.
	//! Called by FunctionHookBase. 
	void SaveDetoursError(void* hook, long error);

	bool m_bInTransaction = false;		//!< The transaction hasn't been commited/aborted.
	void* m_pFirstErrorFunc = nullptr;	//!< Hook function pointer where the first error occured.
	long m_FirstErrorValue = 0;			//!< The first error.

	friend class FunctionHookBase;
};
