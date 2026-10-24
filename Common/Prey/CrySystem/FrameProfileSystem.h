// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Chairloader/PreyFunction.h>

class CCustomProfilerSection;
class CFrameProfiler;
class CFrameProfilerSection;
enum class EProfiledSubsystem;
struct IFrameProfilePeakCallback;
struct ISystem;
struct SInputEvent;
struct SPeakRecord;

// IFrameProfileSystem
// Header:  _unknown/IFrameProfileSystem.h
struct IFrameProfileSystem
{ // Size=8 (0x8)
	enum class EDisplayQuantity
	{
		SELF_TIME = 0,
		TOTAL_TIME = 1,
		SELF_TIME_EXTENDED = 2,
		TOTAL_TIME_EXTENDED = 3,
		PEAK_TIME = 4,
		SUBSYSTEM_INFO = 5,
		COUNT_INFO = 6,
		STANDARD_DEVIATION = 7,
		ALLOCATED_MEMORY = 8,
		ALLOCATED_MEMORY_BYTES = 9,
		STALL_TIME = 10,
		PEAKS_ONLY = 11,
	};

	virtual ~IFrameProfileSystem() {}
	virtual void Reset() = 0;
	virtual void AddFrameProfiler(CFrameProfiler* pProfiler) = 0;
	virtual void RemoveFrameProfiler(CFrameProfiler* pProfiler) = 0;
	virtual void StartFrame() = 0;
	virtual void EndFrame() = 0;
	virtual void OnSliceAndSleep() = 0;
	virtual int GetProfilerCount() const = 0;
	virtual CFrameProfiler* GetProfiler(int index) const = 0;
	virtual int GetPeaksCount() const = 0;
	virtual const SPeakRecord* GetPeak(int index) const = 0;
	virtual const CFrameProfilerSection* GetCurrentProfilerSection() = 0;
	virtual float GetLostFrameTimeMS() const = 0;
	virtual void Enable(bool bCollect, bool bDisplay) = 0;
	virtual void SetSubsystemFilter(bool bFilterSubsystem, EProfiledSubsystem subsystem) = 0;
	virtual bool IsEnabled() const = 0;
	virtual bool IsVisible() const = 0;
	virtual bool IsProfiling() const = 0;
	virtual void SetDisplayQuantity(IFrameProfileSystem::EDisplayQuantity quantity) = 0;
	virtual void StartCustomSection(CCustomProfilerSection* pSection) = 0;
	virtual void EndCustomSection(CCustomProfilerSection* pSection) = 0;
	virtual void AddPeaksListener(IFrameProfilePeakCallback* pPeakCallback) = 0;
	virtual void RemovePeaksListener(IFrameProfilePeakCallback* pPeakCallback) = 0;
	virtual const char* GetFullName(CFrameProfiler* pProfiler) = 0;
	virtual const char* GetModuleName(CFrameProfiler* pProfiler) = 0;
};

// CFrameProfileSystem
// Header:  _unknown/CFrameProfileSystem.h
// Prey ships the frame profiler compiled out: an 8-byte class whose virtuals are stubs.
struct CFrameProfileSystem : public IFrameProfileSystem
{ // Size=8 (0x8)
	virtual void Reset();
	virtual void AddFrameProfiler(CFrameProfiler* pProfiler);
	virtual void RemoveFrameProfiler(CFrameProfiler* pProfiler);
	virtual void StartFrame();
	virtual void EndFrame();
	virtual void OnSliceAndSleep();
	virtual int GetPeaksCount() const;
	virtual const SPeakRecord* GetPeak(int index) const;
	virtual int GetProfilerCount() const;
	virtual float GetLostFrameTimeMS() const;
	virtual CFrameProfiler* GetProfiler(int index) const;
	virtual void Enable(bool bCollect, bool bDisplay);
	virtual void SetSubsystemFilter(bool bFilterSubsystem, EProfiledSubsystem subsystem);
	virtual void SetSubsystemFilter(const char* sFilterName);
	virtual void SetSubsystemFilterThread(const char* sFilterThreadName);
	virtual bool IsEnabled() const;
	virtual bool IsProfiling() const;
	virtual void SetDisplayQuantity(IFrameProfileSystem::EDisplayQuantity quantity);
	virtual void StartCustomSection(CCustomProfilerSection* pSection);
	virtual void EndCustomSection(CCustomProfilerSection* pSection);
	virtual void StartSampling(int __unnamed1);
	virtual void AddPeaksListener(IFrameProfilePeakCallback* pPeakCallback);
	virtual void RemovePeaksListener(IFrameProfilePeakCallback* pPeakCallback);
	virtual const char* GetFullName(CFrameProfiler* pProfiler);
	virtual const int GetModuleCount() const;
	virtual void SetPeakDisplayDuration(float duration);
	virtual void SetAdditionalSubsystems(bool bEnabled);
	virtual const float GetOverBudgetRatio(int modulenumber) const;
	virtual bool IsVisible() const;
	virtual const CFrameProfilerSection* GetCurrentProfilerSection();
	virtual const char* GetModuleName(CFrameProfiler* pProfiler);
	virtual bool OnInputEvent(const SInputEvent& event);

#if 0
	void Init(ISystem* _arg0_, int _arg1_);
	void Done();
	void Render();
	void SetHistogramScale(float _arg0_);
	void SetDrawGraph(bool _arg0_);
	void SetNetworkProfiler(bool _arg0_);
	void SetPeakTolerance(float _arg0_);
	void SetSmoothingTime(float _arg0_);
	void SetPageFaultsGraph(bool _arg0_);
	void SetThreadSupport(int _arg0_);
	void EnableMemoryProfile(bool _arg0_);
	const char* GetModuleName(int _arg0_) const;
	void UpdateInputSystemStatus();
#endif

#ifndef MOONCRASH
	static inline auto FReset = PreyFunction<void(CFrameProfileSystem* const _this)>(0xA13080);
	static inline auto FAddFrameProfiler = PreyFunction<void(CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0xA13080);
	static inline auto FRemoveFrameProfiler = PreyFunction<void(CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0xA13080);
	static inline auto FStartFrame = PreyFunction<void(CFrameProfileSystem* const _this)>(0xA13080);
	static inline auto FEndFrame = PreyFunction<void(CFrameProfileSystem* const _this)>(0xA13080);
	static inline auto FOnSliceAndSleep = PreyFunction<void(CFrameProfileSystem* const _this)>(0xA13080);
	static inline auto FGetPeaksCount = PreyFunction<int(const CFrameProfileSystem* const _this)>(0x158AEF0);
	static inline auto FGetPeak = PreyFunction<const SPeakRecord* (const CFrameProfileSystem* const _this, int index)>(0x158AEF0);
	static inline auto FGetProfilerCount = PreyFunction<int(const CFrameProfileSystem* const _this)>(0x158AEF0);
	static inline auto FGetLostFrameTimeMS = PreyFunction<float(const CFrameProfileSystem* const _this)>(0xB5F050);
	static inline auto FGetProfiler = PreyFunction<CFrameProfiler* (const CFrameProfileSystem* const _this, int index)>(0x158AEF0);
	static inline auto FEnable = PreyFunction<void(CFrameProfileSystem* const _this, bool bCollect, bool bDisplay)>(0xA13080);
	static inline auto FSetSubsystemFilterOv1 = PreyFunction<void(CFrameProfileSystem* const _this, bool bFilterSubsystem, EProfiledSubsystem subsystem)>(0xA13080); // Ov0 (const char*) is the same folded `ret` stub
	static inline auto FSetSubsystemFilterThread = PreyFunction<void(CFrameProfileSystem* const _this, const char* sFilterThreadName)>(0xA13080);
	static inline auto FIsEnabled = PreyFunction<bool(const CFrameProfileSystem* const _this)>(0xDD23F0);
	static inline auto FIsProfiling = PreyFunction<bool(const CFrameProfileSystem* const _this)>(0xDD23F0);
	static inline auto FSetDisplayQuantity = PreyFunction<void(CFrameProfileSystem* const _this, IFrameProfileSystem::EDisplayQuantity quantity)>(0xA13080);
	static inline auto FStartCustomSection = PreyFunction<void(CFrameProfileSystem* const _this, CCustomProfilerSection* pSection)>(0xA13080);
	static inline auto FEndCustomSection = PreyFunction<void(CFrameProfileSystem* const _this, CCustomProfilerSection* pSection)>(0xA13080);
	static inline auto FStartSampling = PreyFunction<void(CFrameProfileSystem* const _this, int __unnamed1)>(0xA13080);
	static inline auto FAddPeaksListener = PreyFunction<void(CFrameProfileSystem* const _this, IFrameProfilePeakCallback* pPeakCallback)>(0xA13080);
	static inline auto FRemovePeaksListener = PreyFunction<void(CFrameProfileSystem* const _this, IFrameProfilePeakCallback* pPeakCallback)>(0xA13080);
	static inline auto FGetFullName = PreyFunction<const char* (CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0x158AEF0);
	static inline auto FGetModuleCount = PreyFunction<const int(const CFrameProfileSystem* const _this)>(0x158AEF0);
	static inline auto FSetPeakDisplayDuration = PreyFunction<void(CFrameProfileSystem* const _this, float duration)>(0xA13080);
	static inline auto FSetAdditionalSubsystems = PreyFunction<void(CFrameProfileSystem* const _this, bool bEnabled)>(0xA13080);
	static inline auto FGetOverBudgetRatio = PreyFunction<const float(const CFrameProfileSystem* const _this, int modulenumber)>(0xB5F050);
	static inline auto FIsVisible = PreyFunction<bool(const CFrameProfileSystem* const _this)>(0x1B933B0);
	static inline auto FGetCurrentProfilerSection = PreyFunction<const CFrameProfilerSection* (CFrameProfileSystem* const _this)>(0x158AEF0);
	static inline auto FGetModuleNameOv1 = PreyFunction<const char* (CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0x158AEF0);
	static inline auto FOnInputEvent = PreyFunction<bool(CFrameProfileSystem* const _this, const SInputEvent& event)>(0xDD23F0);
#else // MOONCRASH
	static inline auto FReset = PreyFunction<void(CFrameProfileSystem* const _this)>(0x1333E90);
	static inline auto FAddFrameProfiler = PreyFunction<void(CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0x1333E90);
	static inline auto FRemoveFrameProfiler = PreyFunction<void(CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0x1333E90);
	static inline auto FStartFrame = PreyFunction<void(CFrameProfileSystem* const _this)>(0x1333E90);
	static inline auto FEndFrame = PreyFunction<void(CFrameProfileSystem* const _this)>(0x1333E90);
	static inline auto FOnSliceAndSleep = PreyFunction<void(CFrameProfileSystem* const _this)>(0x1333E90);
	static inline auto FGetPeaksCount = PreyFunction<int(const CFrameProfileSystem* const _this)>(0x1CBB0B0);
	static inline auto FGetPeak = PreyFunction<const SPeakRecord* (const CFrameProfileSystem* const _this, int index)>(0x1CBB0B0);
	static inline auto FGetProfilerCount = PreyFunction<int(const CFrameProfileSystem* const _this)>(0x1CBB0B0);
	static inline auto FGetLostFrameTimeMS = PreyFunction<float(const CFrameProfileSystem* const _this)>(0x714650);
	static inline auto FGetProfiler = PreyFunction<CFrameProfiler* (const CFrameProfileSystem* const _this, int index)>(0x1CBB0B0);
	static inline auto FEnable = PreyFunction<void(CFrameProfileSystem* const _this, bool bCollect, bool bDisplay)>(0x1333E90);
	static inline auto FSetSubsystemFilterOv1 = PreyFunction<void(CFrameProfileSystem* const _this, bool bFilterSubsystem, EProfiledSubsystem subsystem)>(0x1333E90); // Ov0 (const char*) is the same folded `ret` stub
	static inline auto FSetSubsystemFilterThread = PreyFunction<void(CFrameProfileSystem* const _this, const char* sFilterThreadName)>(0x1333E90);
	static inline auto FIsEnabled = PreyFunction<bool(const CFrameProfileSystem* const _this)>(0x13B0900);
	static inline auto FIsProfiling = PreyFunction<bool(const CFrameProfileSystem* const _this)>(0x13B0900);
	static inline auto FSetDisplayQuantity = PreyFunction<void(CFrameProfileSystem* const _this, IFrameProfileSystem::EDisplayQuantity quantity)>(0x1333E90);
	static inline auto FStartCustomSection = PreyFunction<void(CFrameProfileSystem* const _this, CCustomProfilerSection* pSection)>(0x1333E90);
	static inline auto FEndCustomSection = PreyFunction<void(CFrameProfileSystem* const _this, CCustomProfilerSection* pSection)>(0x1333E90);
	static inline auto FStartSampling = PreyFunction<void(CFrameProfileSystem* const _this, int __unnamed1)>(0x1333E90);
	static inline auto FAddPeaksListener = PreyFunction<void(CFrameProfileSystem* const _this, IFrameProfilePeakCallback* pPeakCallback)>(0x1333E90);
	static inline auto FRemovePeaksListener = PreyFunction<void(CFrameProfileSystem* const _this, IFrameProfilePeakCallback* pPeakCallback)>(0x1333E90);
	static inline auto FGetFullName = PreyFunction<const char* (CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0x1CBB0B0);
	static inline auto FGetModuleCount = PreyFunction<const int(const CFrameProfileSystem* const _this)>(0x1CBB0B0);
	static inline auto FSetPeakDisplayDuration = PreyFunction<void(CFrameProfileSystem* const _this, float duration)>(0x1333E90);
	static inline auto FSetAdditionalSubsystems = PreyFunction<void(CFrameProfileSystem* const _this, bool bEnabled)>(0x1333E90);
	static inline auto FGetOverBudgetRatio = PreyFunction<const float(const CFrameProfileSystem* const _this, int modulenumber)>(0x714650);
	static inline auto FIsVisible = PreyFunction<bool(const CFrameProfileSystem* const _this)>(0x1A302A0);
	static inline auto FGetCurrentProfilerSection = PreyFunction<const CFrameProfilerSection* (CFrameProfileSystem* const _this)>(0x1CBB0B0);
	static inline auto FGetModuleNameOv1 = PreyFunction<const char* (CFrameProfileSystem* const _this, CFrameProfiler* pProfiler)>(0x1CBB0B0);
	static inline auto FOnInputEvent = PreyFunction<bool(CFrameProfileSystem* const _this, const SInputEvent& event)>(0x13B0900);
#endif // !MOONCRASH
};

#ifndef MOONCRASH
// CProfilingSystem (base game only)
// Header:  _unknown/CProfilingSystem.h
struct CProfilingSystem : public IProfilingSystem
{ // Size=8 (0x8)
	virtual void VTuneResume();
	virtual void VTunePause();

	static inline auto FVTuneResume = PreyFunction<void(CProfilingSystem* const _this)>(0xDC9FA0);
	static inline auto FVTunePause = PreyFunction<void(CProfilingSystem* const _this)>(0xDC9F70);
};

static_assert(sizeof(CProfilingSystem) == 8);
#endif // !MOONCRASH

static_assert(sizeof(CFrameProfileSystem) == 8);
