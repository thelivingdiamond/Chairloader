// Header file automatically created from a PDB.
#pragma once

namespace CryUnitTest
{
struct Test;
} // namespace CryUnitTest

namespace CryUnitTest
{

// CryUnitTest::UnitTestInfo
// Header:  _unknown/CryUnitTest__UnitTestInfo.h
struct UnitTestInfo
{ // Size=56 (0x38)
	const char* module;
	const char* suite;
	const char* name;
	const char* filename;
	int lineNumber;
	CryUnitTest::Test* pTestImpl;
	string sFilename;

#if 0
	UnitTestInfo();
#endif
};


} // namespace CryUnitTest

