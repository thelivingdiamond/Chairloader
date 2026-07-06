// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleFsm.h>

class ArkNpc;

// ArkNpcLifecycle
// Header:  Prey/GameDll/ark/npc/ArkNpcLifecycle.h
class ArkNpcLifecycle
{ // Size=728 (0x2D8)
public:
	ArkNpc* m_pNpc;
	ArkNpcLifecycleFsm m_fsm;

	ArkNpcLifecycle(ArkNpc& _npc);
	bool InitializeAlert() { return FInitializeAlert(this); }
	bool InitializeBroken() { return FInitializeBroken(this); }
	bool InitializeDead() { return FInitializeDead(this); }
	bool InitializeDormant(const Vec3& _position, const Quat& _rotation) { return FInitializeDormant(this, _position, _rotation); }
	bool Finalize() { return FFinalize(this); }
	bool BecomeAlert() { return FBecomeAlert(this); }
	bool BecomeBroken() { return FBecomeBroken(this); }
	bool BecomeDead() { return FBecomeDead(this); }
	bool BecomeUnconscious() { return FBecomeUnconscious(this); }
	bool IsAlert() const { return FIsAlert(this); }
	bool IsBroken() const { return FIsBroken(this); }
	bool IsConscious() const { return FIsConscious(this); }
	bool IsDead() const { return FIsDead(this); }
	bool IsDormant() const { return FIsDormant(this); }
	bool IsUnconscious() const { return FIsUnconscious(this); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }

#if 0
	bool InitializeUnconscious();
	bool BecomeDormant(const Vec3& _arg0_, const Quat& _arg1_);
#endif

	static inline auto FArkNpcLifecycle = PreyFunction<void(ArkNpcLifecycle* const _this, ArkNpc& _npc)>(0x128F4F0);
	static inline auto FInitializeAlert = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F8E0);
	static inline auto FInitializeBroken = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F960);
	static inline auto FInitializeDead = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F9E0);
	static inline auto FInitializeDormant = PreyFunction<bool(ArkNpcLifecycle* const _this, const Vec3& _position, const Quat& _rotation)>(0x128FA60);
	static inline auto FFinalize = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F850);
	static inline auto FBecomeAlert = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F520);
	static inline auto FBecomeBroken = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F5F0);
	static inline auto FBecomeDead = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F6C0);
	static inline auto FBecomeUnconscious = PreyFunction<bool(ArkNpcLifecycle* const _this)>(0x128F780);
	static inline auto FIsAlert = PreyFunction<bool(const ArkNpcLifecycle* const _this)>(0x128FB10);
	static inline auto FIsBroken = PreyFunction<bool(const ArkNpcLifecycle* const _this)>(0x128FB50);
	static inline auto FIsConscious = PreyFunction<bool(const ArkNpcLifecycle* const _this)>(0x128FB90);
	static inline auto FIsDead = PreyFunction<bool(const ArkNpcLifecycle* const _this)>(0x128FBD0);
	static inline auto FIsDormant = PreyFunction<bool(const ArkNpcLifecycle* const _this)>(0x128FBE0);
	static inline auto FIsUnconscious = PreyFunction<bool(const ArkNpcLifecycle* const _this)>(0x128FC20);
	static inline auto FUpdate = PreyFunction<void(ArkNpcLifecycle* const _this, float _elapsedTime)>(0x128FDC0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcLifecycle* const _this, TSerialize _serializer)>(0x128FC70);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcLifecycle* const _this, ArkNpc& _npc)>(0x128FC60);
};
#endif // MOONCRASH
