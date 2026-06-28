// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IGameObject;
struct SEntityUpdateContext;

// ArkTyphonGateCap
// Header:  Prey/GameDll/ark/environment/ArkTyphonGateCap.h
class ArkTyphonGateCap : public ArkEnvironmentalObject, public IArkDisruptableListener
{ // Size=648 (0x288)
public:
	unsigned m_owningGate;
	EArkTyphonGateState m_state;
	ArkDisruptable m_disruptable;
	int m_activeAnimId;
	int m_inactiveAnimId;
	int m_offAnimId;
	int m_onAnimId;
	ArkEntityEffect m_activeVfx;
	ArkEntityEffect m_inactiveVfx;
	ArkAudioTrigger m_activeStartTrigger;
	ArkAudioTrigger m_activeStopTrigger;
	ArkAudioTrigger m_inactiveStartTrigger;
	ArkAudioTrigger m_inactiveStopTrigger;
	ArkAudioTrigger m_powerOffTrigger;
	string m_skinAttachmentName;
	Vec3 m_inactiveGlowColor;
	Vec3 m_activeGlowColor;
	Vec3 m_offGlowColor;
	float m_inactiveGlowAmount;
	float m_activeGlowAmount;
	float m_offGlowAmount;
	float m_vfxMaxScaleWidth;
	float m_vfxStrengthOverride;
	int m_glowSubMatIdA;
	int m_glowSubMatIdB;
	bool m_bUpdateGlow;

	ArkTyphonGateCap();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	void SetOwningGate(unsigned _gateId) { FSetOwningGate(this, _gateId); }
	void SetState(EArkTyphonGateState _state, bool _bPostSerialize) { FSetState(this, _state, _bPostSerialize); }
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual void RegisterForSignals(bool _bRegister);
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	void InitAnims() { FInitAnims(this); }
	bool PlayAnim(int _animId, int _animLayer, unsigned _flags) { return FPlayAnim(this, _animId, _animLayer, _flags); }

#if 0
	void UpdateGateDisruption();
	void StopAnims();
#endif

	static inline auto FArkTyphonGateCapOv2 = PreyFunction<void(ArkTyphonGateCap* const _this)>(0x11D70E0);
	static inline auto FPostInit = PreyFunction<void(ArkTyphonGateCap* const _this, IGameObject* _pGameObject)>(0x11D8AA0);
	static inline auto FFullSerialize = PreyFunction<void(ArkTyphonGateCap* const _this, TSerialize _ser)>(0x11D75C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTyphonGateCap* const _this)>(0x11D8BE0);
	static inline auto FUpdate = PreyFunction<void(ArkTyphonGateCap* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x11D8FC0);
	static inline auto FSetOwningGate = PreyFunction<void(ArkTyphonGateCap* const _this, unsigned _gateId)>(0x11D8C20);
	static inline auto FSetState = PreyFunction<void(ArkTyphonGateCap* const _this, EArkTyphonGateState _state, bool _bPostSerialize)>(0x11D8CD0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(IArkDisruptableListener* const _this, bool _bDisrupted, bool _bWasForced)>(0x11D8940);
	static inline auto FGetSparkLoc = PreyFunction<QuatT*(const IArkDisruptableListener* const _this, QuatT* _return_value_)>(0x87B3F0);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkTyphonGateCap* const _this, bool _bRegister)>(0x11D8C10);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkTyphonGateCap* const _this, const ArkSignalSystem::Package& _package)>(0x11D8980);
	static inline auto FOnReset = PreyFunction<void(ArkTyphonGateCap* const _this, bool _bEnteringGameMode)>(0x11D8990);
	static inline auto FLoadProperties = PreyFunction<void(ArkTyphonGateCap* const _this)>(0x11D7C40);
	static inline auto FInitAnims = PreyFunction<void(ArkTyphonGateCap* const _this)>(0x11D77A0);
	static inline auto FPlayAnim = PreyFunction<bool(ArkTyphonGateCap* const _this, int _animId, int _animLayer, unsigned _flags)>(0x11D89D0);
};
#endif // MOONCRASH
