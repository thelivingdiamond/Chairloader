// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ArkItem.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// ArkCondenserCell
// Header:  Prey/GameDll/ark/environment/ArkCondenserCell.h
class ArkCondenserCell
	: public CArkItem
	, public IArkRepairableListener
	, public ArkSignalSystem::Receiver
{ // Size=688 (0x2B0)
public:
	ArkRepairable m_repairable;
	unsigned m_condenser;
	ArkFireAndForgetEffect m_explosionVfx;
	const ArkSignalSystem::Data::SignalGroupData* m_pDamageSignalGroup;
	uint64_t m_explosionSignalPackage;
	string m_brokenModel;
	uint64_t m_cameraShakeId;
	float m_minRadius;
	float m_maxRadius;
	float m_explosionImpulse;
	ArkAudioTrigger m_triggerExplosion;

	ArkCondenserCell();
	virtual ~ArkCondenserCell();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Init(const unsigned& _entityId);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void Release();
	virtual wstring GetDisplayName(int _count) const;
	virtual const char* GetPickupModel() const;
	virtual void LoadCachedProperties();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	void RegisterForSignals(bool _bRegister) { FRegisterForSignals(this, _bRegister); }

#if 0
	bool IsBroken() const;
	void Break();
	ArkRepairable& GetRepairable();
	const ArkRepairable& GetRepairable() const;
	void SetCondenser(const unsigned _arg0_);
#endif

	static inline auto FArkCondenserCellOv1 = PreyFunction<void(ArkCondenserCell* const _this)>(0x11CD3A0);
	static inline auto FInitOv1 = PreyFunction<bool(ArkCondenserCell* const _this, IGameObject* _pGameObject)>(0x11CD790);
	static inline auto FInitOv0 = PreyFunction<void(ArkSignalSystem::Receiver* const _this, const unsigned& _entityId)>(0x11CD780);
	static inline auto FPostInit = PreyFunction<void(ArkCondenserCell* const _this, IGameObject* _pGameObject)>(0x11CE2E0);
	static inline auto FFullSerialize = PreyFunction<void(ArkCondenserCell* const _this, TSerialize _ser)>(0x11CD540);
	static inline auto FPostSerialize = PreyFunction<void(ArkCondenserCell* const _this)>(0x11CE330);
	static inline auto FUpdate = PreyFunction<void(ArkCondenserCell* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x11CE5D0);
	static inline auto FProcessEvent = PreyFunction<void(ArkCondenserCell* const _this, SEntityEvent& _event)>(0x11CE350);
	static inline auto FRelease = PreyFunction<void(ArkCondenserCell* const _this)>(0x11CE580);
	static inline auto FGetDisplayName = PreyFunction<wstring*(const ArkCondenserCell* const _this, wstring* _return_value_, int _count)>(0x11CD690);
	static inline auto FGetPickupModel = PreyFunction<const char* (const ArkCondenserCell* const _this)>(0x11CD760);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkCondenserCell* const _this)>(0x11CD810);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkSignalSystem::Receiver* const _this, const ArkSignalSystem::Package& _package)>(0x11CE000);
	static inline auto FOnBrokenChanged = PreyFunction<void(IArkRepairableListener* const _this, bool _bBroken, bool _bWasForced)>(0x11CDF70);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkCondenserCell* const _this, bool _bRegister)>(0x11CE490);
};
#endif // MOONCRASH
