// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
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
	virtual ~ArkLevelTransitionDoor();
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/worldui/ArkKeycardReader.h>

struct ArkInteractionInfo;
struct IEntity;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// ArkLevelTransitionDoor
// Header:  Prey/GameDll/ark/worldui/ArkLevelTransitionDoor.h
class ArkLevelTransitionDoor : public ArkKeycardReader
{ // Size=664 (0x298)
public:
	string m_inaccessibleText;
	bool m_bLevelTransitionGo;
	bool m_bLevelTransitionUpgrading;
	bool m_bPostEffectCleanupNeeded;
	bool m_bLevelLoadEnabled;
	bool m_bImageLeft;
	string m_confirmLabelPrefix;
	string m_confirmQuery;
	uint64_t m_postProcessId;
	uint64_t m_locationId;
	bool m_bIsTrialGated;

	ArkLevelTransitionDoor();
	virtual ~ArkLevelTransitionDoor();
	virtual void FullSerialize(TSerialize _ser);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void SetTextForInaccessible(const string& _inaccessibleText) { FSetTextForInaccessible(this, _inaccessibleText); }
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	virtual void LoadProperties();
	virtual void LoadInstanceProperties();
	virtual const char* GetInteractFunctionName() const;
	virtual const char* GetStateFunctionName() const;
	virtual void RefreshUI();
	virtual void OnReset(bool _bEnteringGameMode);
	void OnTransitionConfirmed() { FOnTransitionConfirmed(this); }
	void OnTransitionCancelled() { FOnTransitionCancelled(this); }
	void OnTrialUnlockPressed() { FOnTrialUnlockPressed(this); }
	void CleanupPostEffect() { FCleanupPostEffect(this); }
	string GetLocationName() const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetLocationName(this, reinterpret_cast<string*>(_return_buf_)); }

#if 0
	void SetLevelLoadEnabled(const bool _arg0_);
	void SetImageDirection(bool _arg0_);
#endif

	static inline auto FArkLevelTransitionDoorOv1 = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14AA690);
	static inline auto FFullSerialize = PreyFunction<void(ArkLevelTransitionDoor* const _this, TSerialize _ser)>(0x14AA980);
	static inline auto FProcessEvent = PreyFunction<void(ArkLevelTransitionDoor* const _this, SEntityEvent& _event)>(0x14ABB80);
	static inline auto FUpdate = PreyFunction<void(ArkLevelTransitionDoor* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14ABF60);
	static inline auto FOnButtonPress = PreyFunction<void(ArkLevelTransitionDoor* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14AB140);
	static inline auto FSetTextForInaccessible = PreyFunction<void(ArkLevelTransitionDoor* const _this, const string& _inaccessibleText)>(0x14ABF30);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x13B0900);
	static inline auto FLoadProperties = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14AAE00);
	static inline auto FLoadInstanceProperties = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14AAB40);
	static inline auto FGetInteractFunctionName = PreyFunction<const char* (const ArkLevelTransitionDoor* const _this)>(0x14AAAB0);
	static inline auto FGetStateFunctionName = PreyFunction<const char* (const ArkLevelTransitionDoor* const _this)>(0x14AAB30);
	static inline auto FRefreshUI = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14ABBF0);
	static inline auto FOnReset = PreyFunction<void(ArkLevelTransitionDoor* const _this, bool _bEnteringGameMode)>(0x14AB890);
	static inline auto FOnTransitionConfirmed = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14AB9F0);
	static inline auto FOnTransitionCancelled = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14AB8B0);
	static inline auto FOnTrialUnlockPressed = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14ABB10);
	static inline auto FCleanupPostEffect = PreyFunction<void(ArkLevelTransitionDoor* const _this)>(0x14AA940);
	static inline auto FGetLocationName = PreyFunction<string*(const ArkLevelTransitionDoor* const _this, string* _return_value_)>(0x14AAAC0);
};
#endif // !MOONCRASH
