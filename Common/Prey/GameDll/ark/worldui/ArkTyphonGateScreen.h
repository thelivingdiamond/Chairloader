// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkKioskBase.h>

struct IEntity;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// ArkTyphonGateScreen
// Header:  Prey/GameDll/ark/worldui/ArkTyphonGateScreen.h
class ArkTyphonGateScreen : public ArkKioskBase
{ // Size=528 (0x210)
public:
	int m_nearbyTyphon;
	unsigned m_typhonGate;
	ArkSimpleTimer m_processingTimer;

	ArkTyphonGateScreen();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	void SetNearbyTyphon(int _nearbyTyphon) { FSetNearbyTyphon(this, _nearbyTyphon); }
	void SetTyphonGate(unsigned _typhonGate) { FSetTyphonGate(this, _typhonGate); }
	virtual void RefreshUI(bool _bReinit);
	virtual void HandleInteraction(IUIElement* _pUIInstance);
	virtual bool IsProcessing() const;
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);

#if 0
	void UpdateGateDisruption();
#endif

	static inline auto FArkTyphonGateScreenOv2 = PreyFunction<void(ArkTyphonGateScreen* const _this)>(0x14B6190);
	static inline auto FFullSerialize = PreyFunction<void(ArkTyphonGateScreen* const _this, TSerialize _ser)>(0x14B6270);
	static inline auto FPostSerialize = PreyFunction<void(ArkTyphonGateScreen* const _this)>(0x14B6590);
	static inline auto FUpdate = PreyFunction<void(ArkTyphonGateScreen* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14B67E0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkTyphonGateScreen* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14B6430);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x14B64D0);
	static inline auto FSetNearbyTyphon = PreyFunction<void(ArkTyphonGateScreen* const _this, int _nearbyTyphon)>(0x14B6790);
	static inline auto FSetTyphonGate = PreyFunction<void(ArkTyphonGateScreen* const _this, unsigned _typhonGate)>(0x14B67A0);
	static inline auto FRefreshUI = PreyFunction<void(ArkTyphonGateScreen* const _this, bool _bReinit)>(0x14B65D0);
	static inline auto FHandleInteraction = PreyFunction<void(ArkTyphonGateScreen* const _this, IUIElement* _pUIInstance)>(0x14B6410);
	static inline auto FIsProcessing = PreyFunction<bool(const ArkTyphonGateScreen* const _this)>(0x14B6420);
	static inline auto FOnDisruptedChanged = PreyFunction<void(IArkDisruptableListener* const _this, bool _bDisrupted, bool _bWasForced)>(0x14B6490);
};
#endif // MOONCRASH
