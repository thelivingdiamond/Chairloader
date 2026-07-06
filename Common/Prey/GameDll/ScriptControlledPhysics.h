// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>

enum EEntityAspects;
struct EventPhysPostStep;
class ICrySizer;
struct IFunctionHandler;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CScriptControlledPhysics
// Header:  Prey/GameDll/ScriptControlledPhysics.h
class CScriptControlledPhysics : public CGameObjectExtensionHelper<CScriptControlledPhysics, IGameObjectExtension>, private CScriptableBase
{ // Size=256 (0x100)
public:
	bool m_bExactPosition;
	bool m_bTarget;
	bool m_moving;
	Vec3 m_moveTarget;
	Vec3 m_lastVelocity;
	Vec3 m_direction;
	float m_speed;
	float m_maxSpeed;
	float m_acceleration;
	float m_stopTime;
	bool m_bCrushing;
	bool m_rotating;
	Quat m_rotationTarget;
	float m_rotationSpeed;
	float m_rotationMaxSpeed;
	float m_rotationAcceleration;
	float m_rotationStopTime;
	bool m_bWasMovedThisFrame;

	CScriptControlledPhysics();
	virtual ~CScriptControlledPhysics();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual bool Init(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int slot);
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void ProcessEvent(SEntityEvent& __unnamed1);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	int Reset(IFunctionHandler* pH) { return FReset(this, pH); }
	int GetSpeed(IFunctionHandler* pH) { return FGetSpeed(this, pH); }
	int GetAcceleration(IFunctionHandler* pH) { return FGetAcceleration(this, pH); }
	int GetAngularSpeed(IFunctionHandler* pH) { return FGetAngularSpeed(this, pH); }
	int GetAngularAcceleration(IFunctionHandler* pH) { return FGetAngularAcceleration(this, pH); }
	int Stop(IFunctionHandler* pH, float stopTime) { return FStop(this, pH, stopTime); }
	int Move(IFunctionHandler* pH, Vec3 velocity, float acceleration) { return FMove(this, pH, velocity, acceleration); }
	int MoveTo(IFunctionHandler* pH, Vec3 point, float initialSpeed, float speed, float acceleration, float stopTime, bool bExactPosition) { return FMoveTo(this, pH, point, initialSpeed, speed, acceleration, stopTime, bExactPosition); }
	int RotateTo(IFunctionHandler* pH, Vec3 dir, float roll, float initialSpeed, float speed, float acceleration, float stopTime) { return FRotateTo(this, pH, dir, roll, initialSpeed, speed, acceleration, stopTime); }
	int RotateToAngles(IFunctionHandler* pH, Vec3 angles, float initialSpeed, float speed, float acceleration, float stopTime) { return FRotateToAngles(this, pH, angles, initialSpeed, speed, acceleration, stopTime); }
	int HasArrived(IFunctionHandler* pH) { return FHasArrived(this, pH); }
	void OnPostStep(EventPhysPostStep* pPostStep) { FOnPostStep(this, pPostStep); }
	bool SetCrushing(const bool _bCrushing) { return FSetCrushing(this, _bCrushing); }
	void RegisterMethods() { FRegisterMethods(this); }

#if 0
	bool IsMoving() const;
	void RegisterGlobals();
#endif

	static inline auto FCScriptControlledPhysicsOv1 = PreyFunction<void(CScriptControlledPhysics* const _this)>(0x1918470);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptControlledPhysics* const _this, ICrySizer* pSizer)>(0x1918B40);
	static inline auto FInit = PreyFunction<bool(CScriptControlledPhysics* const _this, IGameObject* pGameObject)>(0x1918C20);
	static inline auto FInitClient = PreyFunction<void(CScriptControlledPhysics* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CScriptControlledPhysics* const _this, IGameObject* pGameObject)>(0x1919900);
	static inline auto FPostInitClient = PreyFunction<void(CScriptControlledPhysics* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CScriptControlledPhysics* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1919F40);
	static inline auto FPostReloadExtension = PreyFunction<void(CScriptControlledPhysics* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CScriptControlledPhysics* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(CScriptControlledPhysics* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CScriptControlledPhysics* const _this, TSerialize ser)>(0x19188F0);
	static inline auto FNetSerialize = PreyFunction<bool(CScriptControlledPhysics* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CScriptControlledPhysics* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CScriptControlledPhysics* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CScriptControlledPhysics* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CScriptControlledPhysics* const _this, SEntityUpdateContext& ctx, int slot)>(0x191A8F0);
	static inline auto FHandleEvent = PreyFunction<void(CScriptControlledPhysics* const _this, const SGameObjectEvent& event)>(0x1918B90);
	static inline auto FProcessEvent = PreyFunction<void(CScriptControlledPhysics* const _this, SEntityEvent& __unnamed1)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CScriptControlledPhysics* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CScriptControlledPhysics* const _this, bool auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CScriptControlledPhysics* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CScriptControlledPhysics* const _this)>(0x1333E90);
	static inline auto FReset = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH)>(0x1919FE0);
	static inline auto FGetSpeed = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH)>(0x1918B70);
	static inline auto FGetAcceleration = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH)>(0x1918AE0);
	static inline auto FGetAngularSpeed = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH)>(0x1918B20);
	static inline auto FGetAngularAcceleration = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH)>(0x1918B00);
	static inline auto FStop = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH, float stopTime)>(0x191A6A0);
	static inline auto FMove = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH, Vec3 velocity, float acceleration)>(0x1918DE0);
	static inline auto FMoveTo = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH, Vec3 point, float initialSpeed, float speed, float acceleration, float stopTime, bool bExactPosition)>(0x1918FF0);
	static inline auto FRotateTo = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH, Vec3 dir, float roll, float initialSpeed, float speed, float acceleration, float stopTime)>(0x191A060);
	static inline auto FRotateToAngles = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH, Vec3 angles, float initialSpeed, float speed, float acceleration, float stopTime)>(0x191A310);
	static inline auto FHasArrived = PreyFunction<int(CScriptControlledPhysics* const _this, IFunctionHandler* pH)>(0x1918BA0);
	static inline auto FOnPostStep = PreyFunction<void(CScriptControlledPhysics* const _this, EventPhysPostStep* pPostStep)>(0x19190C0);
	static inline auto FSetCrushing = PreyFunction<bool(CScriptControlledPhysics* const _this, const bool _bCrushing)>(0x191A520);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptControlledPhysics* const _this)>(0x19199E0);
};
#endif // MOONCRASH
