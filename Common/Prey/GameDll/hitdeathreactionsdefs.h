// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <_unknown/STagState.h>
#include <_unknown/VectorSet.h>

class IActionController;
class IAnimationDatabase;
struct IAnimationSet;
class ICrySizer;

// SReactionParams
// Header:  Prey/GameDll/hitdeathreactionsdefs.h
struct SReactionParams
{ // Size=216 (0xD8)
	enum class Flags
	{
		OrientateToHitDir = 1,
		CollisionCheckIntersectionWithGround = 2,
		SleepRagdoll = 4,
		OrientateToMovementDir = 8,
		NoRagdollOnEnd = 16,
		ReactionFinishesNotAiming = 32,
		ReactionsForbidden = 64,
		TriggerRagdollAfterSerializing = 128,
	};

	// SReactionParams::SReactionAnim
	// Header:  Prey/GameDll/hitdeathreactionsdefs.h
	struct SReactionAnim
	{ // Size=56 (0x38)
		int iLayer;
		unsigned animFlags;
		float fOverrideTransTimeToAG;
		std::vector<unsigned int> animCRCs;
		bool bAdditive;
		bool bNoAnimCamera;
		int16_t m_iNextAnimIndex;
		unsigned m_nextAnimCRC;
		unsigned m_requestedAnimCRC;
		unsigned m_iTimerHandle;

		SReactionAnim();
		~SReactionAnim();
		int GetNextReactionAnimIndex() const { return FGetNextReactionAnimIndex(this); }
		void RequestNextAnim(const IAnimationSet* pAnimSet) const { FRequestNextAnim(this, pAnimSet); }
		void ReleaseRequestedAnims() { FReleaseRequestedAnims(this); }
		void UpdateRequestedAnimStatus() const { FUpdateRequestedAnimStatus(this); }
		void OnTimer(void* pUserData, unsigned handler) const { FOnTimer(this, pUserData, handler); }

	#if 0
		void Reset();
		int GetNextReactionAnimId(const IAnimationSet* _arg0_) const;
		void OnAnimLoaded() const;
	#endif

		static inline auto FSReactionAnimOv1 = PreyFunction<void(SReactionParams::SReactionAnim* const _this)>(0x18690A0);
		static inline auto FBitNotSReactionAnim = PreyFunction<void(SReactionParams::SReactionAnim* const _this)>(0x18692D0);
		static inline auto FGetNextReactionAnimIndex = PreyFunction<int(const SReactionParams::SReactionAnim* const _this)>(0x1869730);
		static inline auto FRequestNextAnim = PreyFunction<void(const SReactionParams::SReactionAnim* const _this, const IAnimationSet* pAnimSet)>(0x186A020);
		static inline auto FReleaseRequestedAnims = PreyFunction<void(SReactionParams::SReactionAnim* const _this)>(0x1869DD0);
		static inline auto FUpdateRequestedAnimStatus = PreyFunction<void(const SReactionParams::SReactionAnim* const _this)>(0x186A6F0);
		static inline auto FOnTimer = PreyFunction<void(const SReactionParams::SReactionAnim* const _this, void* pUserData, unsigned handler)>(0x1869970);
	};

	// SReactionParams::SAnimGraphReaction
	// Header:  Prey/GameDll/hitdeathreactionsdefs.h
	struct SAnimGraphReaction
	{ // Size=32 (0x20)
		// SReactionParams::SAnimGraphReaction::SVariationData
		// Header:  Prey/GameDll/hitdeathreactionsdefs.h
		struct SVariationData
		{ // Size=16 (0x10)
			string sName;
			string sValue;

		#if 0
			SVariationData();
			SVariationData(const char* _arg0_, const char* _arg1_);
			void GetMemoryUsage(ICrySizer* _arg0_) const;
		#endif
		};

		using VariationsContainer = std::vector<SReactionParams::SAnimGraphReaction::SVariationData>;

		string sAGInputValue;
		std::vector<SReactionParams::SAnimGraphReaction::SVariationData> variations;

	#if 0
		void Reset();
	#endif
	};

	// SReactionParams::SMannequinData
	// Header:  Prey/GameDll/hitdeathreactionsdefs.h
	struct SMannequinData
	{ // Size=72 (0x48)
		enum EActionType
		{
			EActionType_Fragment = 0,
			EActionType_Coop = 1,
			EActionType_FragTagCopyingFragment = 2,
			EActionType_DoNothing = 3,
			EActionType_MultiStageAction = 4,
			EActionType_Last = 4,
			EActionType_Invalid = 5,
		};

		STagState<12> tagState;
		unsigned m_iNextOptionIndex;
		SReactionParams::SMannequinData::EActionType actionType;
		float m_multiStageDuration;
		unsigned m_numOptions;
		unsigned m_animIndexMP;
		unsigned m_iTimerHandle;
		std::shared_ptr<CFragmentCache> m_pRequestedFragment;
		std::shared_ptr<CFragmentCache> m_pCurrentFragment;

		void Initialize(const IActionController* piActionController) { FInitialize(this, piActionController); }
		void AddDB(const IActionController* piActionController, const IAnimationDatabase* piAnimationDB) const { FAddDB(this, piActionController, piAnimationDB); }
		void RequestNextAnim(const IActionController* piActionController) const { FRequestNextAnim(this, piActionController); }
		void ReleaseRequestedAnims() { FReleaseRequestedAnims(this); }
		void Reset() { FReset(this); }
		void UpdateRequestedAnimStatus() const { FUpdateRequestedAnimStatus(this); }
		void OnTimer(void* pUserData, unsigned handler) const { FOnTimer(this, pUserData, handler); }

	#if 0
		int GetNextReactionAnimIndex() const;
		int GetCurrentReactionAnimIndex() const;
		bool IsCurrentFragmentLoaded() const;
		bool IsValid() const;
		SMannequinData();
		void OnAnimLoaded() const;
	#endif

		static inline auto FInitialize = PreyFunction<void(SReactionParams::SMannequinData* const _this, const IActionController* piActionController)>(0x1869750);
		static inline auto FAddDB = PreyFunction<void(const SReactionParams::SMannequinData* const _this, const IActionController* piActionController, const IAnimationDatabase* piAnimationDB)>(0x1869360);
		static inline auto FRequestNextAnim = PreyFunction<void(const SReactionParams::SMannequinData* const _this, const IActionController* piActionController)>(0x1869E50);
		static inline auto FReleaseRequestedAnims = PreyFunction<void(SReactionParams::SMannequinData* const _this)>(0x1869D00);
		static inline auto FReset = PreyFunction<void(SReactionParams::SMannequinData* const _this)>(0x186A250);
		static inline auto FUpdateRequestedAnimStatus = PreyFunction<void(const SReactionParams::SMannequinData* const _this)>(0x186A5E0);
		static inline auto FOnTimer = PreyFunction<void(const SReactionParams::SMannequinData* const _this, void* pUserData, unsigned handler)>(0x18698C0);
	};

	// SReactionParams::SValidationParams
	// Header:  Prey/GameDll/hitdeathreactionsdefs.h
	struct SValidationParams
	{ // Size=280 (0x118)
		VectorSet<std::pair<unsigned __int64,float>,std::less<std::pair<unsigned __int64,float> >,std::allocator<std::pair<unsigned __int64,float> > > allowedSignals;
		float fMinHitAngle;
		float fMaxHitAngle;
		SmartScriptTable validationParamsScriptTable;
		string sCustomValidationFunc;
		float fMinimumSpeedAllowed;
		float fMaximumSpeedAllowed;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedPartIds;
		ECardinalDirection shotOrigin;
		ECardinalDirection movementDir;
		float fProbability;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedStances;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedHitTypes;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedProjectiles;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedWeapons;
		float fMinimumDamageAllowed;
		float fMaximumDamageAllowed;
		VectorSet<float,std::less<float>,std::allocator<float> > healthThresholds;
		unsigned destructibleEvent;
		float fMinimumDistance;
		float fMaximumDistance;
		bool bAllowOnlyWhenUsingMountedItems;
		EAirState airState;
		bool bCustomValidationOnly;
		EReactionHitType m_hitType;
		float fThrowHitCheckDistance;
		float fThrowHitCheckSphereR;
		float fThrowHitSweepHeight;
		float fThrowHitLedgeCheckDist;
		float fThrowHitWallGlassCheckHeight;
		bool bCustomOnlyWhenValid;

		SValidationParams();
		void Reset() { FReset(this); }
		void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }

		static inline auto FSValidationParamsOv2 = PreyFunction<void(SReactionParams::SValidationParams* const _this)>(0x18691B0);
		static inline auto FReset = PreyFunction<void(SReactionParams::SValidationParams* const _this)>(0x186A4A0);
		static inline auto FGetMemoryUsage = PreyFunction<void(const SReactionParams::SValidationParams* const _this, ICrySizer* s)>(0x1869580);
	};

	using AnimCRCContainer = std::vector<unsigned int>;
	using SReactionAnimPtr = std::shared_ptr<SReactionParams::SReactionAnim>;
	using SReactionAnimConstPtr = std::shared_ptr<const SReactionParams::SReactionAnim>;
	using SReactionAnimWeakPtr = std::weak_ptr<SReactionParams::SReactionAnim>;
	using SReactionAnimConstWeakPtr = std::weak_ptr<SReactionParams::SReactionAnim const >;
	using IdContainer = VectorSet<int,std::less<int>,std::allocator<int> >;
	using ThresholdsContainer = VectorSet<float,std::less<float>,std::allocator<float> >;
	using SignalIdMinValuePair = std::pair<uint64_t, float>;
	using SignalIdContainer = VectorSet<std::pair<unsigned __int64,float>,std::less<std::pair<unsigned __int64,float> >,std::allocator<std::pair<unsigned __int64,float> > >;
	using ValidationParamsList = std::vector<SReactionParams::SValidationParams>;

	SmartScriptTable reactionScriptTable;
	std::vector<SReactionParams::SValidationParams> validationParams;
	string sCustomExecutionFunc;
	string sCustomExecutionEndFunc;
	string sCustomAISignal;
	SReactionParams::SAnimGraphReaction agReaction;
	std::shared_ptr<SReactionParams::SReactionAnim> reactionAnim;
	SReactionParams::SMannequinData mannequinData;
	float orientationSnapAngle;
	Vec3 endVelocity;
	bool bPauseAI;
	uint8_t flags;
	uint8_t reactionOnCollision;
	float minTimeInRagdoll;
	float maxTimeInRagdoll;
	float fThrowHitImpulseScale;
	float fThrowHitRailVertOffset;
	bool bRotateTowardsShooter;
	bool bRotateAwayFromShooter;

	SReactionParams();
	void Reset() { FReset(this); }
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }

	static inline auto FSReactionParamsOv2 = PreyFunction<void(SReactionParams* const _this)>(0x18690E0);
	static inline auto FReset = PreyFunction<void(SReactionParams* const _this)>(0x186A2F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const SReactionParams* const _this, ICrySizer* s)>(0x1869380);
};
#endif // MOONCRASH
