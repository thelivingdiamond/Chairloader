// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalHazard.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/environment/ArkAreaHazard.h
class ArkAreaHazard : public ArkEnvironmentalHazard // Id=801A9B5 Size=352
{
public:
	ArkAutoResetTimer m_timer;
	ArkEntityEffect m_hazardVfx;
	bool m_bHazardActive;
	float m_areaHazardRadius;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamagingSignalGroup;
	string m_intactMaterial;
	string m_hazardMaterial;
	bool m_bHazardStartsActive;
	
	ArkAreaHazard();
	virtual ~ArkAreaHazard();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void RegisterForSignals(bool _bRegister);
	void StartHazard() { FStartHazard(this); }
	void ClearHazard() { FClearHazard(this); }
	void PulseHazard() { FPulseHazard(this); }
	virtual AABB GetLocalAreaBounds() const;
	virtual bool ShouldUpdateWithTargets() const;
	
	static inline auto FPostInit = PreyFunction<void(ArkAreaHazard *const _this, IGameObject *_pGameObject)>(0x127AD70);
	static inline auto FFullSerialize = PreyFunction<void(ArkAreaHazard *const _this, TSerialize _ser)>(0x127A570);
	static inline auto FPostSerialize = PreyFunction<void(ArkAreaHazard *const _this)>(0x127ADA0);
	static inline auto FUpdate = PreyFunction<void(ArkAreaHazard *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x127B330);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkAreaHazard const *const _this, ICrySizer *_s)>(0x127A680);
	static inline auto FOnReset = PreyFunction<void(ArkAreaHazard *const _this, bool _bEnteringGameMode)>(0x127AD30);
	static inline auto FLoadProperties = PreyFunction<void(ArkAreaHazard *const _this)>(0x127A6C0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkAreaHazard *const _this, ArkSignalSystem::Package const &_package)>(0x127AC50);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkAreaHazard *const _this, bool _bRegister)>(0x127B160);
	static inline auto FStartHazard = PreyFunction<void(ArkAreaHazard *const _this)>(0x127B260);
	static inline auto FClearHazard = PreyFunction<void(ArkAreaHazard *const _this)>(0x127A4B0);
	static inline auto FPulseHazard = PreyFunction<void(ArkAreaHazard *const _this)>(0x127ADE0);
	static inline auto FGetLocalAreaBounds = PreyFunction<AABB(ArkAreaHazard const *const _this)>(0x127A630);
	static inline auto FShouldUpdateWithTargets = PreyFunction<bool(ArkAreaHazard const *const _this)>(0x127B240);
};

