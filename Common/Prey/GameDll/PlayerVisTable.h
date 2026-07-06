// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/SDeferredLinetestBuffer.h>
#include <_unknown/SVisTableEntry.h>
#include <_unknown/SVisTablePriority.h>

struct RayCastResult;
struct SDeferredLinetestReceiver;

// CPlayerVisTable
// Header:  Prey/GameDll/PlayerVisTable.h
class CPlayerVisTable
{ // Size=1776 (0x6F0)
public:
	// CPlayerVisTable::SVisibilityParams
	// Header:  Prey/GameDll/PlayerVisTable.h
	struct SVisibilityParams
	{ // Size=12 (0xC)
		unsigned targetEntityId;
		float heightOffset;
		uint8_t queryParams;

	#if 0
		SVisibilityParams(unsigned _arg0_);
	#endif
	};

	// CPlayerVisTable::SIgnoreEntity
	// Header:  Prey/GameDll/PlayerVisTable.h
	struct SIgnoreEntity
	{ // Size=8 (0x8)
		unsigned id;
		unsigned refCount;

	#if 0
		SIgnoreEntity();
		void Clear();
	#endif
	};

	static constexpr const int kMinUnusedFramesBeforeEntryRemoved = 20;
	static constexpr const int kMaxVisTableEntries = 128;
	static constexpr const int kDefaultAcceptableLatency = 10;
	static constexpr const int kNumVisTableBuffers = 2;
	static constexpr const uint8_t kMaxNumIgnoreEntities = 8;
	SDeferredLinetestBuffer m_linetestBuffers[2];
	SVisTableEntry m_visTableEntries[128];
	SVisTablePriority m_visTablePriorities[5];
	CPlayerVisTable::SIgnoreEntity m_globalIgnoreEntities[8];
	int16_t m_numUsedVisTableEntries;
	int16_t m_numLinetestsThisFrame;
	uint8_t m_currentNumIgnoreEntities;
	uint8_t m_currentBufferTarget;
	uint8_t m_currentBufferProcessing;

	CPlayerVisTable();
	~CPlayerVisTable();
	void Update(float dt) { FUpdate(this, dt); }
	void Reset() { FReset(this); }
	void DoVisibilityCheck(const Vec3& localPlayerPosn, SVisTableEntry& visInfo, int16_t visIndex) { FDoVisibilityCheck(this, localPlayerPosn, visInfo, visIndex); }
	void ClearRemovedEntities() { FClearRemovedEntities(this); }

#if 0
	bool CanLocalPlayerSee(const CPlayerVisTable::SVisibilityParams& _arg0_);
	bool CanLocalPlayerSee(const CPlayerVisTable::SVisibilityParams& _arg0_, uint8_t _arg1_);
	SVisTableEntry& GetNthVisTableEntry(int _arg0_);
	void AddGlobalIgnoreEntity(const unsigned _arg0_, const char* _arg1_);
	void RemoveGlobalIgnoreEntity(const unsigned _arg0_);
	void ClearGlobalIgnoreEntities();
	SDeferredLinetestBuffer& GetDeferredLinetestBuffer(int _arg0_);
	void GetLocalPlayerPosn(Vec3& _arg0_);
	int16_t GetEntityIndexFromID(unsigned _arg0_);
	int AddVisTableEntriesToPriorityList();
	void UpdatePendingDeferredLinetest(const int16_t _arg0_, const int16_t _arg1_);
	void RemovePendingDeferredLinetest(const int16_t _arg0_);
	SDeferredLinetestReceiver* GetDeferredLinetestReceiverFromVisTableIndex(const int16_t _arg0_, const int16_t _arg1_);
	SDeferredLinetestReceiver* GetAvailableDeferredLinetestReceiver(SDeferredLinetestBuffer& _arg0_);
	int GetCurrentLinetestBufferTargetIndex();
	void RemoveNthEntity(const int16_t _arg0_);
#endif

	static inline auto FCPlayerVisTable = PreyFunction<void(CPlayerVisTable* const _this)>(0x18EC6D0);
	static inline auto FBitNotCPlayerVisTable = PreyFunction<void(CPlayerVisTable* const _this)>(0x18EC7B0);
	static inline auto FUpdate = PreyFunction<void(CPlayerVisTable* const _this, float dt)>(0x18ED1D0);
	static inline auto FReset = PreyFunction<void(CPlayerVisTable* const _this)>(0x18ED0F0);
	static inline auto FDoVisibilityCheck = PreyFunction<void(CPlayerVisTable* const _this, const Vec3& localPlayerPosn, SVisTableEntry& visInfo, int16_t visIndex)>(0x18EC9C0);
	static inline auto FClearRemovedEntities = PreyFunction<void(CPlayerVisTable* const _this)>(0x18EC810);
};

// SDeferredLinetestReceiver
// Header:  Prey/GameDll/PlayerVisTable.h
struct SDeferredLinetestReceiver
{ // Size=8 (0x8)
	unsigned queuedRayID;
	int16_t visTableIndex;
	int8_t visBufferIndex;

	~SDeferredLinetestReceiver();
	void OnDataReceived(const unsigned& rayID, const RayCastResult& result) { FOnDataReceived(this, rayID, result); }
	void CancelPendingRay() { FCancelPendingRay(this); }

#if 0
	SDeferredLinetestReceiver();
	void SetFree();
	bool IsFree();
	void SetInvalid();
	bool IsValid();
#endif

	static inline auto FBitNotSDeferredLinetestReceiver = PreyFunction<void(SDeferredLinetestReceiver* const _this)>(0x18EC800);
	static inline auto FOnDataReceived = PreyFunction<void(SDeferredLinetestReceiver* const _this, const unsigned& rayID, const RayCastResult& result)>(0x18ECEA0);
	static inline auto FCancelPendingRay = PreyFunction<void(SDeferredLinetestReceiver* const _this)>(0x18BC640);
};
#endif // MOONCRASH
