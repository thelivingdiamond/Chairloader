// Header file automatically created from a PDB.
#pragma once

struct CryUserID;
enum ECryLobbyError;
enum ECryLobbyLeaderboardType;
struct SCryStatsLeaderBoardReadResult;
struct SCryStatsLeaderBoardWrite;

enum ECryLobbyUserDataType
{
	eCLUDT_Int64 = 0,
	eCLUDT_Int32 = 1,
	eCLUDT_Int16 = 2,
	eCLUDT_Int8 = 3,
	eCLUDT_Float64 = 4,
	eCLUDT_Float32 = 5,
	eCLUDT_Int64NoEndianSwap = 6,
};

// SCryLobbyUserData
// Header:  _unknown/SCryLobbyUserData.h
struct SCryLobbyUserData
{ // Size=16 (0x10)
	unsigned m_id;
	ECryLobbyUserDataType m_type;
	union
	{
		int64_t m_int64;
		double m_f64;
		int m_int32;
		float m_f32;
		int16_t m_int16;
		int8_t m_int8;
	};
};

static_assert(sizeof(SCryLobbyUserData) == 16);

// ICryStats
// Header:  _unknown/ICryStats.h
// Include: Prey/CryLobby/ICryStats.h
struct ICryStats
{ // Size=8 (0x8)
	virtual ~ICryStats();
	virtual ECryLobbyError StatsRegisterLeaderBoards(SCryStatsLeaderBoardWrite* _arg0_, unsigned _arg1_, unsigned* _arg2_, void (*_arg3_)(unsigned, ECryLobbyError, void*), void* _arg4_) = 0;
	virtual ECryLobbyError StatsWriteLeaderBoards(unsigned _arg0_, unsigned _arg1_, SCryStatsLeaderBoardWrite* _arg2_, unsigned _arg3_, unsigned* _arg4_, void (*_arg5_)(unsigned, ECryLobbyError, void*), void* _arg6_) = 0;
	virtual ECryLobbyError StatsWriteLeaderBoards(unsigned _arg0_, CryUserID* _arg1_, SCryStatsLeaderBoardWrite* * _arg2_, unsigned* _arg3_, unsigned _arg4_, unsigned* _arg5_, void (*_arg6_)(unsigned, ECryLobbyError, void*), void* _arg7_) = 0;
	virtual ECryLobbyError StatsReadLeaderBoardByRankForRange(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, unsigned* _arg3_, void (*_arg4_)(unsigned, ECryLobbyError, SCryStatsLeaderBoardReadResult*, void*), void* _arg5_) = 0;
	virtual ECryLobbyError StatsReadLeaderBoardByRankForUser(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, unsigned* _arg3_, void (*_arg4_)(unsigned, ECryLobbyError, SCryStatsLeaderBoardReadResult*, void*), void* _arg5_) = 0;
	virtual ECryLobbyError StatsReadLeaderBoardByUserID(unsigned _arg0_, CryUserID* _arg1_, unsigned _arg2_, unsigned* _arg3_, void (*_arg4_)(unsigned, ECryLobbyError, SCryStatsLeaderBoardReadResult*, void*), void* _arg5_) = 0;
	virtual ECryLobbyError StatsRegisterUserData(SCryLobbyUserData* _arg0_, unsigned _arg1_, unsigned* _arg2_, void (*_arg3_)(unsigned, ECryLobbyError, void*), void* _arg4_) = 0;
	virtual ECryLobbyError StatsWriteUserData(unsigned _arg0_, SCryLobbyUserData* _arg1_, unsigned _arg2_, unsigned* _arg3_, void (*_arg4_)(unsigned, ECryLobbyError, void*), void* _arg5_) = 0;
	virtual ECryLobbyError StatsWriteUserData(CryUserID* _arg0_, SCryLobbyUserData* * _arg1_, unsigned* _arg2_, unsigned _arg3_, unsigned* _arg4_, void (*_arg5_)(unsigned, ECryLobbyError, void*), void* _arg6_) = 0;
	virtual ECryLobbyError StatsReadUserData(unsigned _arg0_, unsigned* _arg1_, void (*_arg2_)(unsigned, ECryLobbyError, SCryLobbyUserData*, unsigned, void*), void* _arg3_) = 0;
	virtual ECryLobbyError StatsReadUserData(unsigned _arg0_, CryUserID _arg1_, unsigned* _arg2_, void (*_arg3_)(unsigned, ECryLobbyError, SCryLobbyUserData*, unsigned, void*), void* _arg4_) = 0;
	virtual void CancelTask(unsigned _arg0_) = 0;
	virtual void SetLeaderboardType(ECryLobbyLeaderboardType _arg0_) = 0;
	virtual void RegisterLeaderboardNameIdPair(string _arg0_, unsigned _arg1_) = 0;
	virtual ECryLobbyLeaderboardType GetLeaderboardType() = 0;
};

