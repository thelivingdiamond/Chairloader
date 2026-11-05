// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/CryUnitTest_Test.h>

class CGameTypeInfo;

// CBase
// Header:  Prey/GameDll/gametypeinfo.h
class CBase
{ // Size=8 (0x8)
public:
	virtual ~CBase();
	virtual const CGameTypeInfo* GetRunTimeType() const;

#if 0
	static const CGameTypeInfo* GetStaticType();
#endif

#ifndef MOONCRASH
	static inline auto FGetRunTimeType = PreyFunction<const CGameTypeInfo* (const CBase* const _this)>(0x173BF70);
#else
	static inline auto FGetRunTimeType = PreyFunction<const CGameTypeInfo* (const CBase* const _this)>(0x1862B50);
#endif
};

// CType2
// Header:  Prey/GameDll/gametypeinfo.h
class CType2 : public CBase
{ // Size=8 (0x8)
public:
	virtual const CGameTypeInfo* GetRunTimeType() const;

#if 0
	static const CGameTypeInfo* GetStaticType();
#endif

#ifndef MOONCRASH
	static inline auto FGetRunTimeType = PreyFunction<const CGameTypeInfo* (const CType2* const _this)>(0x173BF80);
#else
	static inline auto FGetRunTimeType = PreyFunction<const CGameTypeInfo* (const CType2* const _this)>(0x1862B60);
#endif
};

namespace CryGameTypeInfoTest
{

// CryGameTypeInfoTest::BadDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class BadDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::BadDownCast* const _this)>(0x173BB60);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::BadDownCast* const _this)>(0x18623F0);
#endif
};

// CryGameTypeInfoTest::BaseTypeNotCastableToSubType_BugFix
// Header:  Prey/GameDll/gametypeinfo.h
class BaseTypeNotCastableToSubType_BugFix : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::BaseTypeNotCastableToSubType_BugFix* const _this)>(0x173B770);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::BaseTypeNotCastableToSubType_BugFix* const _this)>(0x18627D0);
#endif
};

// CryGameTypeInfoTest::ConstBadDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class ConstBadDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstBadDownCast* const _this)>(0x173BD50);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstBadDownCast* const _this)>(0x18625E0);
#endif
};

// CryGameTypeInfoTest::ConstGoodDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class ConstGoodDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstGoodDownCast* const _this)>(0x173BCB0);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstGoodDownCast* const _this)>(0x1862540);
#endif
};

// CryGameTypeInfoTest::ConstUpCast
// Header:  Prey/GameDll/gametypeinfo.h
class ConstUpCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstUpCast* const _this)>(0x173BE00);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstUpCast* const _this)>(0x1862690);
#endif
};

// CryGameTypeInfoTest::FalseDownCastIsOf
// Header:  Prey/GameDll/gametypeinfo.h
class FalseDownCastIsOf : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::FalseDownCastIsOf* const _this)>(0x173B8C0);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::FalseDownCastIsOf* const _this)>(0x1862920);
#endif
};

// CryGameTypeInfoTest::GetName
// Header:  Prey/GameDll/gametypeinfo.h
class GetName : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::GetName* const _this)>(0x173BA10);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::GetName* const _this)>(0x1862A70);
#endif
};

// CryGameTypeInfoTest::GoodDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class GoodDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::GoodDownCast* const _this)>(0x173BAC0);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::GoodDownCast* const _this)>(0x1862350);
#endif
};

// CryGameTypeInfoTest::SameCast
// Header:  Prey/GameDll/gametypeinfo.h
class SameCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::SameCast* const _this)>(0x173BEA0);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::SameCast* const _this)>(0x1862730);
#endif
};

// CryGameTypeInfoTest::TrueDownCastIsOf
// Header:  Prey/GameDll/gametypeinfo.h
class TrueDownCastIsOf : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::TrueDownCastIsOf* const _this)>(0x173B820);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::TrueDownCastIsOf* const _this)>(0x1862880);
#endif
};

// CryGameTypeInfoTest::TrueUpCastIsOf
// Header:  Prey/GameDll/gametypeinfo.h
class TrueUpCastIsOf : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::TrueUpCastIsOf* const _this)>(0x173B970);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::TrueUpCastIsOf* const _this)>(0x18629D0);
#endif
};

// CryGameTypeInfoTest::UpCast
// Header:  Prey/GameDll/gametypeinfo.h
class UpCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

#ifndef MOONCRASH
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::UpCast* const _this)>(0x173BC10);
#else
	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::UpCast* const _this)>(0x18624A0);
#endif
};


} // namespace CryGameTypeInfoTest

