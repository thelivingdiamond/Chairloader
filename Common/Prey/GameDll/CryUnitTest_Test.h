// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/CryUnitTest_AutoTestInfo.h>
#include <Prey/GameDll/CryUnitTest_UnitTestInfo.h>

namespace CryUnitTest
{

// CryUnitTest::Test
// Header:  _unknown/CryUnitTest__Test.h
struct Test
{ // Size=88 (0x58)
	CryUnitTest::UnitTestInfo m_unitTestInfo;
	CryUnitTest::AutoTestInfo m_autoTestInfo;
	CryUnitTest::Test* m_pNext;
#ifndef MOONCRASH
	static inline auto m_pFirst = PreyGlobal<CryUnitTest::Test*>(0x240CD80);
	static inline auto m_pLast = PreyGlobal<CryUnitTest::Test*>(0x240CD90);
#else
	static inline auto m_pFirst = PreyGlobal<CryUnitTest::Test*>(0x257C1D0);
	static inline auto m_pLast = PreyGlobal<CryUnitTest::Test*>(0x257C1D8);
#endif

	virtual ~Test();
	virtual void Run() = 0;
	virtual void Init();
	virtual void Done();

#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(CryUnitTest::Test* const _this)>(0xA13080);
	static inline auto FDone = PreyFunction<void(CryUnitTest::Test* const _this)>(0xA13080);
#else
	static inline auto FInit = PreyFunction<void(CryUnitTest::Test* const _this)>(0x1333E90);
	static inline auto FDone = PreyFunction<void(CryUnitTest::Test* const _this)>(0x1333E90);
#endif
};


} // namespace CryUnitTest

