// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CBlendJobNode;
struct IBlendType;
struct IBlendedEffect;
class ICrySizer;

// CBlendGroup
// Header:  Prey/GameDll/blendnode.h
class CBlendGroup
{ // Size=40 (0x28)
public:
	using TJobVector = std::vector<CBlendJobNode*>;

	std::vector<CBlendJobNode*> m_jobs;
	int m_currentJob;
	unsigned m_nextFreeSlot;
	unsigned m_activeJobs;
	unsigned m_maxActiveJobs;

	~CBlendGroup();
	void Update(float frameTime) { FUpdate(this, frameTime); }
	bool HasJobs() { return FHasJobs(this); }

#if 0
	CBlendGroup();
	void AddJob(IBlendType* _arg0_, IBlendedEffect* _arg1_, float _arg2_);
	void Reset();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
	void AllocateMinJobs();
#endif

	static inline auto FBitNotCBlendGroup = PreyFunction<void(CBlendGroup* const _this)>(0x17A9BF0);
	static inline auto FUpdate = PreyFunction<void(CBlendGroup* const _this, float frameTime)>(0x17A9CE0);
	static inline auto FHasJobs = PreyFunction<bool(CBlendGroup* const _this)>(0x17A9C90);
};

// CBlendJobNode
// Header:  Prey/GameDll/blendnode.h
class CBlendJobNode
{ // Size=24 (0x18)
public:
	IBlendedEffect* m_myEffect;
	IBlendType* m_blendType;
	float m_speed;
	float m_progress;

	void Reset() { FReset(this); }

#if 0
	CBlendJobNode();
	~CBlendJobNode();
	void Init(IBlendType* _arg0_, IBlendedEffect* _arg1_, float _arg2_);
	void Update(float _arg0_);
	bool Done() const;
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FReset = PreyFunction<void(CBlendJobNode* const _this)>(0x17A9CA0);
};
#endif // MOONCRASH
