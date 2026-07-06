// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>

class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkClock.h
class ArkClock : public ArkEnvironmentalObject // Id=8019734 Size=96
{
public:
	int m_animId;
	int m_numMinutesOnClock;
	
	ArkClock();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual void OnReset(bool _bEnteringGameMode);
	void LoadAnim() { FLoadAnim(this); }
	virtual ~ArkClock();
	
	static inline auto FPostInit = PreyFunction<void(ArkClock *const _this, IGameObject *_pGameObject)>(0x11B9790);
	static inline auto FUpdate = PreyFunction<void(ArkClock *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x11B9860);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkClock const *const _this, ICrySizer *_pS)>(0xA39190);
	static inline auto FOnReset = PreyFunction<void(ArkClock *const _this, bool _bEnteringGameMode)>(0x11B9760);
	static inline auto FLoadAnim = PreyFunction<void(ArkClock *const _this)>(0x11B9620);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>

class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// ArkClock
// Header:  Prey/GameDll/ark/environment/ArkClock.h
class ArkClock : public ArkEnvironmentalObject
{ // Size=96 (0x60)
public:
	int m_animId;
	int m_numMinutesOnClock;

	ArkClock();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void OnReset(bool _bEnteringGameMode);
	void LoadAnim() { FLoadAnim(this); }

	static inline auto FArkClockOv2 = PreyFunction<void(ArkClock* const _this)>(0x123AFE0);
	static inline auto FPostInit = PreyFunction<void(ArkClock* const _this, IGameObject* _pGameObject)>(0x123B1F0);
	static inline auto FUpdate = PreyFunction<void(ArkClock* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x123B2C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkClock* const _this, ICrySizer* _pS)>(0xA55F00);
	static inline auto FOnReset = PreyFunction<void(ArkClock* const _this, bool _bEnteringGameMode)>(0x123B1C0);
	static inline auto FLoadAnim = PreyFunction<void(ArkClock* const _this)>(0x123B080);
};
#endif // !MOONCRASH
