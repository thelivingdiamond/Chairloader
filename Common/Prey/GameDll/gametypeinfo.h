// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CryUnitTest__Test.h>

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

	static inline auto FGetRunTimeType = PreyFunction<const CGameTypeInfo* (const CBase* const _this)>(0x1862B50);
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

	static inline auto FGetRunTimeType = PreyFunction<const CGameTypeInfo* (const CType2* const _this)>(0x1862B60);
};

namespace CryGameTypeInfoTest
{

// CryGameTypeInfoTest::BadDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class BadDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::BadDownCast* const _this)>(0x18623F0);
};

// CryGameTypeInfoTest::BaseTypeNotCastableToSubType_BugFix
// Header:  Prey/GameDll/gametypeinfo.h
class BaseTypeNotCastableToSubType_BugFix : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::BaseTypeNotCastableToSubType_BugFix* const _this)>(0x18627D0);
};

// CryGameTypeInfoTest::ConstBadDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class ConstBadDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstBadDownCast* const _this)>(0x18625E0);
};

// CryGameTypeInfoTest::ConstGoodDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class ConstGoodDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstGoodDownCast* const _this)>(0x1862540);
};

// CryGameTypeInfoTest::ConstUpCast
// Header:  Prey/GameDll/gametypeinfo.h
class ConstUpCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::ConstUpCast* const _this)>(0x1862690);
};

// CryGameTypeInfoTest::FalseDownCastIsOf
// Header:  Prey/GameDll/gametypeinfo.h
class FalseDownCastIsOf : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::FalseDownCastIsOf* const _this)>(0x1862920);
};

// CryGameTypeInfoTest::GetName
// Header:  Prey/GameDll/gametypeinfo.h
class GetName : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::GetName* const _this)>(0x1862A70);
};

// CryGameTypeInfoTest::GoodDownCast
// Header:  Prey/GameDll/gametypeinfo.h
class GoodDownCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::GoodDownCast* const _this)>(0x1862350);
};

// CryGameTypeInfoTest::SameCast
// Header:  Prey/GameDll/gametypeinfo.h
class SameCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::SameCast* const _this)>(0x1862730);
};

// CryGameTypeInfoTest::TrueDownCastIsOf
// Header:  Prey/GameDll/gametypeinfo.h
class TrueDownCastIsOf : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::TrueDownCastIsOf* const _this)>(0x1862880);
};

// CryGameTypeInfoTest::TrueUpCastIsOf
// Header:  Prey/GameDll/gametypeinfo.h
class TrueUpCastIsOf : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::TrueUpCastIsOf* const _this)>(0x18629D0);
};

// CryGameTypeInfoTest::UpCast
// Header:  Prey/GameDll/gametypeinfo.h
class UpCast : public CryUnitTest::Test
{ // Size=88 (0x58)
public:
	virtual void Run();

	static inline auto FRun = PreyFunction<void(CryGameTypeInfoTest::UpCast* const _this)>(0x18624A0);
};


} // namespace CryGameTypeInfoTest
#endif // MOONCRASH
