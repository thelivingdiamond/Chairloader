// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/Ark/IArkRewardSystem.h>
#include <Prey/CryThreading/CryThread_win32.h>

class CryEvent;
struct IArkRewardSystemCallbackHandler;

// CArkRewardSystem
// Header:  CryEngine/CrySystem/Ark/ArkRewardSystem.h
class CArkRewardSystem : public IArkRewardSystem
{ // Size=144 (0x90)
public:
	struct ArkRewardTrackable
	{ // Size=16 (0x10)
		uint64_t associatedMetric;
		unsigned value;
		unsigned id;
	};

	struct ArkRewardTrackableCriteria
	{ // Size=16 (0x10)
		CArkRewardSystem::ArkRewardTrackable* trackable;
		unsigned value;
		bool bCriteriaMet;
	};

	struct ArkReward
	{ // Size=40 (0x28)
		unsigned unlockId;
		std::vector<CArkRewardSystem::ArkRewardTrackableCriteria> criteria;
		bool bCriteriaMet;
	};

	struct IArkRewardsJobInfo
	{ // Size=8 (0x8)
		enum class ArkRewardsJobInfoType : unsigned
		{
			Flush = 0,
			Unlock = 1,
		};

		virtual ~IArkRewardsJobInfo();
		virtual CArkRewardSystem::IArkRewardsJobInfo::ArkRewardsJobInfoType JobType() const = 0;
	};

	struct CArkRewardSystemFlushJobInfo : public CArkRewardSystem::IArkRewardsJobInfo
	{ // Size=16 (0x10)
		CryEvent& event;

		virtual CArkRewardSystem::IArkRewardsJobInfo::ArkRewardsJobInfoType JobType() const;

	#if 0
		CArkRewardSystemFlushJobInfo(CryEvent& _arg0_);
	#endif

		static inline auto FJobType = PreyFunction<CArkRewardSystem::IArkRewardsJobInfo::ArkRewardsJobInfoType(const CArkRewardSystem::CArkRewardSystemFlushJobInfo* const _this)>(0x158AEF0);
	};

	struct CArkRewardSystemUnlockJobInfo : public CArkRewardSystem::IArkRewardsJobInfo
	{ // Size=16 (0x10)
		unsigned userId;
		unsigned rewardId;

		virtual CArkRewardSystem::IArkRewardsJobInfo::ArkRewardsJobInfoType JobType() const;

	#if 0
		CArkRewardSystemUnlockJobInfo(const unsigned _arg0_, const unsigned _arg1_);
	#endif
	};

	class ArkRewardsThread : public CrySimpleThread<CryRunnable>
	{ // Size=312 (0x138)
	public:
		CArkRewardSystem* m_pRewardSystem;
		CryConditionVariable::LockType m_cvLock;
		CryConditionVariable m_cond;
		std::deque<CArkRewardSystem::IArkRewardsJobInfo *,std::allocator<CArkRewardSystem::IArkRewardsJobInfo *> > m_jobQueue;
		static constexpr const unsigned MAXIMUM_PENDING_REWARDS = 8;
		unsigned m_pendingRewards[8];
		unsigned m_pendingRewardsCount;
		bool m_bAlive;

		virtual void Run();
		virtual void Cancel();

	#if 0
		ArkRewardsThread(CArkRewardSystem* _arg0_);
		void PushUnlockRequest(unsigned _arg0_, unsigned _arg1_);
		void Flush();
	#endif

		static inline auto FRun = PreyFunction<void(CArkRewardSystem::ArkRewardsThread* const _this)>(0xD5CDB0);
		static inline auto FCancel = PreyFunction<void(CArkRewardSystem::ArkRewardsThread* const _this)>(0xD5C580);
	};

	static constexpr const uint64_t kNoAssociatedMetric = 0;
	CArkRewardSystem::ArkRewardsThread* m_pRewardsThread = nullptr;
	IArkRewardSystemCallbackHandler* m_pHandler = nullptr;
	std::vector<CArkRewardSystem::ArkRewardTrackable> m_trackables;
	std::unordered_map<uint64_t, CArkRewardSystem::ArkRewardTrackable*> m_trackablesByMetric;
	unsigned m_userId = -1;
	std::vector<CArkRewardSystem::ArkReward> m_rewards;

	CArkRewardSystem() = default;
	virtual ~CArkRewardSystem() {}
	virtual bool Init() { return FInit(this); }
	virtual void SetActiveUserId(unsigned _userId) { FSetActiveUserId(this, _userId); }
	virtual bool LoadRewardData(const string& _strRewardFile) { return FLoadRewardData(this, _strRewardFile); }
	virtual void SetInitialTrackableValue(unsigned _trackable, unsigned _value) { return FSetInitialTrackableValueOv1(this, _trackable, _value); }
	virtual void SetInitialTrackableValue(uint64_t _associatedMetric, unsigned _value) { return FSetInitialTrackableValueOv0(this, _associatedMetric, _value); }
	virtual unsigned IncrementTrackableValue(unsigned _trackable) { return FIncrementTrackableValueOv1(this, _trackable); }
	virtual unsigned IncrementTrackableValue(uint64_t _associatedMetric) { return FIncrementTrackableValueOv0(this, _associatedMetric); }
	virtual unsigned UpdateTrackableValueMax(uint64_t _associatedMetric, unsigned _value) { return FUpdateTrackableValueMax(this, _associatedMetric, _value); }
	virtual void UnlockReward(unsigned _reward) { FUnlockReward(this, _reward); }
	virtual void ResetTrackableData() { FResetTrackableData(this); }
	virtual void SetCallbackHandler(IArkRewardSystemCallbackHandler* _pHandler) { FSetCallbackHandler(this, _pHandler); }
	virtual void InternalTrackableUpdated(unsigned _trackableId, unsigned _oldVal, unsigned _newVal) { FInternalTrackableUpdated(this, _trackableId, _oldVal, _newVal); }
	virtual void InternalRewardUnlocked(unsigned _rewardId) { FInternalRewardUnlocked(this, _rewardId); }

#if 0
	CArkRewardSystem(const CArkRewardSystem& _arg0_);
	void TrackableChanged(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_);
	bool SuppressRewards() const;
#endif

	static inline auto FCArkRewardSystemOv1 = PreyFunction<void(CArkRewardSystem* const _this)>(0xD5C0F0);
	static inline auto FInit = PreyFunction<bool(CArkRewardSystem* const _this)>(0xD5C710);
	static inline auto FSetActiveUserId = PreyFunction<void(CArkRewardSystem* const _this, unsigned _userId)>(0xD5D0B0);
	static inline auto FLoadRewardData = PreyFunction<bool(CArkRewardSystem* const _this, const string& _strRewardFile)>(0xD5C8F0);
	static inline auto FSetInitialTrackableValueOv1 = PreyFunction<void(CArkRewardSystem* const _this, unsigned _trackable, unsigned _value)>(0xD5D130);
	static inline auto FSetInitialTrackableValueOv0 = PreyFunction<void(CArkRewardSystem* const _this, uint64_t _associatedMetric, unsigned _value)>(0xD5D140);
	static inline auto FIncrementTrackableValueOv1 = PreyFunction<unsigned(CArkRewardSystem* const _this, unsigned _trackable)>(0xD5C660);
	static inline auto FIncrementTrackableValueOv0 = PreyFunction<unsigned(CArkRewardSystem* const _this, uint64_t _associatedMetric)>(0xD5C6A0);
	static inline auto FUpdateTrackableValueMax = PreyFunction<unsigned(CArkRewardSystem* const _this, uint64_t _associatedMetric, unsigned _value)>(0xD5D190);
	static inline auto FUnlockReward = PreyFunction<void(CArkRewardSystem* const _this, unsigned _reward)>(0xD5D180);
	static inline auto FResetTrackableData = PreyFunction<void(CArkRewardSystem* const _this)>(0xD5CD50);
	static inline auto FSetCallbackHandler = PreyFunction<void(CArkRewardSystem* const _this, IArkRewardSystemCallbackHandler* _pHandler)>(0x9FBCE0);
	static inline auto FInternalTrackableUpdated = PreyFunction<void(CArkRewardSystem* const _this, unsigned _trackableId, unsigned _oldVal, unsigned _newVal)>(0xA13080);
	static inline auto FInternalRewardUnlocked = PreyFunction<void(CArkRewardSystem* const _this, unsigned _rewardId)>(0xA13080);
};

