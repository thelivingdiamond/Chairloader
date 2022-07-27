// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkSignalManagerListener.h>

struct AABB;
class ICrySizer;
struct IGameObject;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkEnvironmentalHazard.h
class ArkEnvironmentalHazard : public ArkEnvironmentalObject, public IArkSignalManagerListener // Id=8019735 Size=168
{
public:
	std::vector<unsigned int> m_hazardTargets;
	std::vector<unsigned int> m_inertTargets;
	unsigned m_activator;
	uint64_t m_hazardPackage;
	unsigned m_avoidanceFieldId;
	
	virtual bool Init(IGameObject *_pGameObject);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnRegisteredSignalsChanged(unsigned _entityId, std::vector<unsigned __int64> const &_signals, bool _bAllSignals);
	virtual void OnReset(bool _bEnteringGameMode);
	void InitArea() { FInitArea(this); }
	virtual AABB GetLocalAreaBounds() const = 0;
	virtual bool ShouldUpdateWithTargets() const;
	virtual void AddTarget(unsigned _target);
	virtual void RemoveTarget(unsigned _target);
	void ClearTargets() { FClearTargets(this); }
	virtual bool IsPotentialTarget(unsigned _targetId, std::vector<unsigned __int64> const &_signals, bool _bAllSignals) const;
	virtual bool GetNpcAvoidanceInfo(Vec3 &_pos, float &_radius) const;
	void RemoveNpcAvoidanceField() { FRemoveNpcAvoidanceField(this); }
	void UpdateNpcAvoidanceField() { FUpdateNpcAvoidanceField(this); }
	virtual ~ArkEnvironmentalHazard();
	
#if 0
	void SetActivator(unsigned arg0);
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkEnvironmentalHazard *const _this, IGameObject *_pGameObject)>(0x11B9D60);
	static inline auto FProcessEvent = PreyFunction<void(ArkEnvironmentalHazard *const _this, SEntityEvent &_event)>(0x11BA420);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkEnvironmentalHazard const *const _this, ICrySizer *_s)>(0x11B9CE0);
	static inline auto FFullSerialize = PreyFunction<void(ArkEnvironmentalHazard *const _this, TSerialize _ser)>(0x11B9CB0);
	static inline auto FPostSerialize = PreyFunction<void(ArkEnvironmentalHazard *const _this)>(0x11BA410);
	static inline auto FOnRegisteredSignalsChanged = PreyFunction<void(ArkEnvironmentalHazard *const _this, unsigned _entityId, std::vector<unsigned __int64> const &_signals, bool _bAllSignals)>(0x11BA380);
	static inline auto FOnReset = PreyFunction<void(ArkEnvironmentalHazard *const _this, bool _bEnteringGameMode)>(0x11BA3E0);
	static inline auto FInitArea = PreyFunction<void(ArkEnvironmentalHazard *const _this)>(0x11B9E50);
	static inline auto FAddTarget = PreyFunction<void(ArkEnvironmentalHazard *const _this, unsigned _target)>(0x11B9A50);
	static inline auto FRemoveTarget = PreyFunction<void(ArkEnvironmentalHazard *const _this, unsigned _target)>(0x11BA500);
	static inline auto FClearTargets = PreyFunction<void(ArkEnvironmentalHazard *const _this)>(0x11B9BA0);
	static inline auto FIsPotentialTarget = PreyFunction<bool(ArkEnvironmentalHazard const *const _this, unsigned _targetId, std::vector<unsigned __int64> const &_signals, bool _bAllSignals)>(0x11BA2E0);
	static inline auto FGetNpcAvoidanceInfo = PreyFunction<bool(ArkEnvironmentalHazard const *const _this, Vec3 &_pos, float &_radius)>(0xDD23F0);
	static inline auto FRemoveNpcAvoidanceField = PreyFunction<void(ArkEnvironmentalHazard *const _this)>(0x11BA4B0);
	static inline auto FUpdateNpcAvoidanceField = PreyFunction<void(ArkEnvironmentalHazard *const _this)>(0x11BA5A0);
	static inline auto FBitNotArkEnvironmentalHazard = PreyFunction<void(ArkEnvironmentalHazard *const _this)>(0x127A3B0);
};

