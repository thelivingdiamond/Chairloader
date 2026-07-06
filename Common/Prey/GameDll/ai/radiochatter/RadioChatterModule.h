// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ai/gameaihelpers.h>

struct IEntity;

// RadioChatterModule
// Header:  Prey/GameDll/ai/radiochatter/RadioChatterModule.h
class RadioChatterModule : public AIModule<RadioChatterModule,RadioChatterInstance,12,1>
{ // Size=88 (0x58)
public:
	using SquaredDistanceToCamera = float;
	using EntityAndDistance = std::pair<IEntity*, float>;
	using ChatterCandidates = std::vector<std::pair<IEntity*, float>>;

	string m_chatterSoundName;
	CTimeValue m_nextChatterTime;
	float m_minimumSilenceDurationBetweenChatter;
	float m_maximumSilenceDurationBetweenChatter;
	bool m_enabled;

	virtual const char* GetName() const;
	virtual void Update(float updateTime);
	virtual void Reset(bool bUnload);
	virtual void Serialize(TSerialize ser);
	void SetDefaultSilenceDuration() { FSetDefaultSilenceDuration(this); }
	void SetDefaultSound() { FSetDefaultSound(this); }
	static bool CloserToCameraPred(const std::pair<IEntity*, float>& left, const std::pair<IEntity*, float>& right) { return FCloserToCameraPred(left, right); }
	void PlayChatterOnRandomNearbyAgent() { FPlayChatterOnRandomNearbyAgent(this); }
	void RefreshNextChatterTime() { FRefreshNextChatterTime(this); }

#if 0
	RadioChatterModule();
	void SetSilenceDuration(float _arg0_, float _arg1_);
	void SetSound(const char* _arg0_);
	void SetEnabled(bool _arg0_);
	void PlayChatterOnEntity(IEntity& _arg0_);
	void GatherCandidates(std::vector<std::pair<IEntity*, float>>& _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const RadioChatterModule* const _this)>(0x10C68B0);
	static inline auto FUpdate = PreyFunction<void(RadioChatterModule* const _this, float updateTime)>(0x10CBDE0);
	static inline auto FReset = PreyFunction<void(RadioChatterModule* const _this, bool bUnload)>(0x10CBCA0);
	static inline auto FSerialize = PreyFunction<void(RadioChatterModule* const _this, TSerialize ser)>(0x10CBD00);
	static inline auto FSetDefaultSilenceDuration = PreyFunction<void(RadioChatterModule* const _this)>(0x10CBDA0);
	static inline auto FSetDefaultSound = PreyFunction<void(RadioChatterModule* const _this)>(0x10CBDC0);
	static inline auto FCloserToCameraPred = PreyFunction<bool(const std::pair<IEntity*, float>& left, const std::pair<IEntity*, float>& right)>(0x10CB9F0);
	static inline auto FPlayChatterOnRandomNearbyAgent = PreyFunction<void(RadioChatterModule* const _this)>(0x10CBA00);
	static inline auto FRefreshNextChatterTime = PreyFunction<void(RadioChatterModule* const _this)>(0x10CBC20);
};
#endif // MOONCRASH
