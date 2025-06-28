// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalHazard.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IParticleEffect;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/environment/ArkLeakable.h
class ArkLeakable : public ArkEnvironmentalHazard // Id=801B818 Size=376
{
public:
	class LeakInfo // Id=801B819 Size=44
	{
	public:
		Vec3 m_pos;
		Vec3 m_dir;
		int m_vfxSlot;
		unsigned m_linkedEntity;
		unsigned m_causeId;
		float m_length;
		float m_timeSinceCreation;
		
		void ConvertToLocal(IEntity *_pEntity) { FConvertToLocal(this,_pEntity); }
		std::pair<Vec3,Vec3> GetGlobal(IEntity *_pEntity) const { return FGetGlobal(this,_pEntity); }
		std::pair<Triangle_tpl<float>,Triangle_tpl<float> > GetTriangles(Vec3 const &_globalPos, Vec3 const &_globalDir, float _angle) const { return FGetTriangles(this,_globalPos,_globalDir,_angle); }
		
#if 0
		void Serialize(TSerialize arg0);
#endif
		
		static inline auto FConvertToLocal = PreyFunction<void(ArkLeakable::LeakInfo *const _this, IEntity *_pEntity)>(0x13C4220);
		static inline auto FGetGlobal = PreyFunction<std::pair<Vec3,Vec3>(ArkLeakable::LeakInfo const *const _this, IEntity *_pEntity)>(0x13C4CE0);
		static inline auto FGetTriangles = PreyFunction<std::pair<Triangle_tpl<float>,Triangle_tpl<float> >(ArkLeakable::LeakInfo const *const _this, Vec3 const &_globalPos, Vec3 const &_globalDir, float _angle)>(0x13C5360);
	};

	using LeakArray = std::vector<ArkLeakable::LeakInfo>;
	using LeakIter = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > >;
	
	bool m_bValveOpen;
	std::vector<ArkLeakable::LeakInfo> m_leaks;
	std::vector<ArkEntityEffect> m_vfx;
	ArkAutoResetTimer m_hazardTimer;
	ArkSimpleTimer m_hostileAdjustmentTimer;
	unsigned m_leakToUpdate;
	bool m_bLeakAudioOn;
	bool m_bRecycleLeaks;
	bool m_bForceEffectVAClip;
	float m_leakAngle;
	float m_minLeakLength;
	float m_maxLeakLength;
	float m_vfxMinLeakLength;
	float m_vfxMaxLeakLength;
	int m_maxLeaks;
	float m_chanceOfLeak;
	float m_minDistanceBetweenLeaksSq;
	float m_hazardInterval;
	float m_leakDuration;
	float m_recycleDuration;
	float m_selfImpulseScale;
	float m_allowedAngle;
	float m_allowedAngleOffset;
	float m_maxHostileAdjustment;
	uint64_t m_gooSignal;
	std::vector<string> m_targetBlackList;
	ArkSignalSystem::Data::SignalGroupData const *m_pPiercingSignalGroup;
	IParticleEffect *m_pLeakParticle;
	ArkAudioTrigger m_triggerLeakStart;
	ArkAudioTrigger m_triggerLeakStop;
	bool m_bValveStartsOpen;
	
	ArkLeakable();
	virtual ~ArkLeakable();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	bool TestGlooLOS(Vec3 const &_glooPos, IEntity const *_pGlooEntity) const { return FTestGlooLOS(this,_glooPos,_pGlooEntity); }
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	void SetValveState(bool _bOpen, bool _bImmediate) { FSetValveState(this,_bOpen,_bImmediate); }
	bool AddLeak(ArkLeakable::LeakInfo &_leak) { return FAddLeak(this,_leak); }
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > > RepairLeak(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > > _iter) { return FRepairLeak(this,_iter); }
	virtual bool CanLeak() const;
	virtual void LeakingStarted(ArkLeakable::LeakInfo const &_leak);
	virtual void LeakingStopped();
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual AABB GetLocalAreaBounds() const;
	virtual bool ShouldUpdateWithTargets() const;
	virtual void RegisterForSignals(bool _bRegister);
	virtual bool GetNpcAvoidanceInfo(Vec3 &_pos, float &_radius) const;
	bool ShouldIgnoreSignal(uint64_t _signalId) const { return FShouldIgnoreSignal(this,_signalId); }
	virtual void HandleScriptEvent(const char *_pEvent, SEntityEvent &_event);
	bool AdjustLeakTowardsHostiles(ArkLeakable::LeakInfo &_leak) const { return FAdjustLeakTowardsHostiles(this,_leak); }
	void CreateLinkedLeak(unsigned _entityId) { FCreateLinkedLeak(this,_entityId); }
	std::vector<IEntity *> GetEntitiesInAngle(float _angle, ArkLeakable::LeakInfo const &_leak) const { return FGetEntitiesInAngle(this,_angle,_leak); }
	unsigned GetNumLeaks_Recursive(std::vector<unsigned int> &_visited) const { return FGetNumLeaks_Recursive(this,_visited); }
	bool PickBestReplacementLeak_Recursive(ArkLeakable *&_pLeakable, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > > &_iter, std::vector<unsigned int> &_visited, Vec3 _leakPos) { return FPickBestReplacementLeak_Recursive(this,_pLeakable,_iter,_visited,_leakPos); }
	void SetupVfx() { FSetupVfx(this); }
	void ClearVfx() { FClearVfx(this); }
	int GetAvailableVfxSlot() { return FGetAvailableVfxSlot(this); }
	void StartVFX(ArkLeakable::LeakInfo &_leak, int _slot) { FStartVFX(this,_leak,_slot); }
	virtual bool IsPotentialTarget(unsigned _targetId, std::vector<unsigned __int64> const &_signals, bool _bAllSignals) const;
	
#if 0
	float GetLeakDuration() const;
	float GetHazardInterval() const;
	bool IsLeaking() const;
	void RepairAllLeaks();
	void AdjustLeakWithinAllowedAngle(ArkLeakable::LeakInfo &arg0) const;
	void UpdateAudio();
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > > GetLinkedLeak(unsigned arg0);
	void StopVFX(ArkLeakable::LeakInfo &arg0, bool arg1);
#endif
	
	static inline auto FBitNotArkLeakable = PreyFunction<void(ArkLeakable *const _this)>(0x13C3570);
	static inline auto FPostInit = PreyFunction<void(ArkLeakable *const _this, IGameObject *_pGameObject)>(0x13C7E60);
	static inline auto FFullSerialize = PreyFunction<void(ArkLeakable *const _this, TSerialize _ser)>(0x13C45A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkLeakable *const _this)>(0x13C7F50);
	static inline auto FUpdate = PreyFunction<void(ArkLeakable *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0x13C8A50);
	static inline auto FProcessEvent = PreyFunction<void(ArkLeakable *const _this, SEntityEvent &_event)>(0x13C7FC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkLeakable const *const _this, ICrySizer *_s)>(0x13C4ED0);
	static inline auto FTestGlooLOS = PreyFunction<bool(ArkLeakable const *const _this, Vec3 const &_glooPos, IEntity const *_pGlooEntity)>(0x13C8840);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkLeakable *const _this, ArkSignalSystem::Package const &_package)>(0x13C7360);
	static inline auto FSetValveState = PreyFunction<void(ArkLeakable *const _this, bool _bOpen, bool _bImmediate)>(0x13C8370);
	static inline auto FAddLeak = PreyFunction<bool(ArkLeakable *const _this, ArkLeakable::LeakInfo &_leak)>(0x13C3650);
	static inline auto FRepairLeak = PreyFunction<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > >(ArkLeakable *const _this, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > > _iter)>(0x13C81A0);
	static inline auto FCanLeak = PreyFunction<bool(ArkLeakable const *const _this)>(0x1B933B0);
	static inline auto FLeakingStarted = PreyFunction<void(ArkLeakable *const _this, ArkLeakable::LeakInfo const &_leak)>(0x13C5790);
	static inline auto FLeakingStopped = PreyFunction<void(ArkLeakable *const _this)>(0x13C5830);
	static inline auto FLoadProperties = PreyFunction<void(ArkLeakable *const _this)>(0x13C58A0);
	static inline auto FOnReset = PreyFunction<void(ArkLeakable *const _this, bool _bEnteringGameMode)>(0x13C7BA0);
	static inline auto FGetLocalAreaBounds = PreyFunction<AABB(ArkLeakable const *const _this)>(0x13C4E30);
	static inline auto FShouldUpdateWithTargets = PreyFunction<bool(ArkLeakable const *const _this)>(0x13BF050);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkLeakable *const _this, bool _bRegister)>(0x13C80A0);
	static inline auto FGetNpcAvoidanceInfo = PreyFunction<bool(ArkLeakable const *const _this, Vec3 &_pos, float &_radius)>(0x13C4F80);
	static inline auto FShouldIgnoreSignal = PreyFunction<bool(ArkLeakable const *const _this, uint64_t _signalId)>(0x13C85F0);
	static inline auto FHandleScriptEvent = PreyFunction<void(ArkLeakable *const _this, const char *_pEvent, SEntityEvent &_event)>(0x13C56A0);
	static inline auto FAdjustLeakTowardsHostiles = PreyFunction<bool(ArkLeakable const *const _this, ArkLeakable::LeakInfo &_leak)>(0x13C3940);
	static inline auto FCreateLinkedLeak = PreyFunction<void(ArkLeakable *const _this, unsigned _entityId)>(0x13C44A0);
	static inline auto FGetEntitiesInAngle = PreyFunction<std::vector<IEntity *>(ArkLeakable const *const _this, float _angle, ArkLeakable::LeakInfo const &_leak)>(0x13C47F0);
	static inline auto FGetNumLeaks_Recursive = PreyFunction<unsigned(ArkLeakable const *const _this, std::vector<unsigned int> &_visited)>(0x13C5290);
	static inline auto FPickBestReplacementLeak_Recursive = PreyFunction<bool(ArkLeakable *const _this, ArkLeakable *&_pLeakable, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkLeakable::LeakInfo> > > &_iter, std::vector<unsigned int> &_visited, Vec3 _leakPos)>(0x13C7C90);
	static inline auto FSetupVfx = PreyFunction<void(ArkLeakable *const _this)>(0x13C8560);
	static inline auto FClearVfx = PreyFunction<void(ArkLeakable *const _this)>(0x13C4050);
	static inline auto FGetAvailableVfxSlot = PreyFunction<int(ArkLeakable *const _this)>(0x13C47A0);
	static inline auto FStartVFX = PreyFunction<void(ArkLeakable *const _this, ArkLeakable::LeakInfo &_leak, int _slot)>(0x13C8660);
	static inline auto FIsPotentialTarget = PreyFunction<bool(ArkLeakable const *const _this, unsigned _targetId, std::vector<unsigned __int64> const &_signals, bool _bAllSignals)>(0x13C5700);
};

