// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/worldui/ArkKeycardReader.h>

struct ArkInteractionInfo;
struct IEntity;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkLevelTransitionDoor.h
class ArkLevelTransitionDoor : public ArkKeycardReader // Id=801BC8E Size=632
{
public:
	string m_inaccessibleText;
	bool m_bLevelTransitionGo;
	bool m_bLevelTransitionUpgrading;
	bool m_bPostEffectCleanupNeeded;
	string m_confirmLabelPrefix;
	string m_confirmQuery;
	uint64_t m_postProcessId;
	uint64_t m_locationId;
	bool m_bIsTrialGated;
	
	ArkLevelTransitionDoor();
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	void SetTextForInaccessible(string const &_inaccessibleText) { FSetTextForInaccessible(this,_inaccessibleText); }
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	virtual void LoadProperties();
	virtual void LoadInstanceProperties();
	virtual const char *GetInteractFunctionName() const;
	virtual const char *GetStateFunctionName() const;
	virtual void RefreshUI();
	void OnTransitionConfirmed() { FOnTransitionConfirmed(this); }
	void OnTransitionCancelled() { FOnTransitionCancelled(this); }
	void OnTrialUnlockPressed() { FOnTrialUnlockPressed(this); }
	string GetLocationName() const { return FGetLocationName(this); }
	
#if 0
	void CleanupPostEffect();
#endif
	
	static inline auto FFullSerialize = PreyFunction<void(ArkLevelTransitionDoor *const _this, TSerialize _ser)>(0x13A03A0);
	static inline auto FUpdate = PreyFunction<void(ArkLevelTransitionDoor *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x13A1840);
	static inline auto FOnButtonPress = PreyFunction<void(ArkLevelTransitionDoor *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A0AB0);
	static inline auto FSetTextForInaccessible = PreyFunction<void(ArkLevelTransitionDoor *const _this, string const &_inaccessibleText)>(0x13A1810);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkLevelTransitionDoor const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0xDD23F0);
	static inline auto FLoadProperties = PreyFunction<void(ArkLevelTransitionDoor *const _this)>(0x13A0780);
	static inline auto FLoadInstanceProperties = PreyFunction<void(ArkLevelTransitionDoor *const _this)>(0x13A0530);
	static inline auto FGetInteractFunctionName = PreyFunction<const char *(ArkLevelTransitionDoor const *const _this)>(0x13A04A0);
	static inline auto FGetStateFunctionName = PreyFunction<const char *(ArkLevelTransitionDoor const *const _this)>(0x13A0520);
	static inline auto FRefreshUI = PreyFunction<void(ArkLevelTransitionDoor *const _this)>(0x13A14E0);
	static inline auto FOnTransitionConfirmed = PreyFunction<void(ArkLevelTransitionDoor *const _this)>(0x13A1320);
	static inline auto FOnTransitionCancelled = PreyFunction<void(ArkLevelTransitionDoor *const _this)>(0x13A11F0);
	static inline auto FOnTrialUnlockPressed = PreyFunction<void(ArkLevelTransitionDoor *const _this)>(0x13A1440);
	static inline auto FGetLocationName = PreyFunction<string(ArkLevelTransitionDoor const *const _this)>(0x13A04B0);
};

