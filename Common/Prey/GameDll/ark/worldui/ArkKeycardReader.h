// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkKeyWorldUI.h>

class ICrySizer;
struct IGameObject;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/worldui/ArkKeycardReader.h
class ArkKeycardReader : public ArkKeyWorldUI // Id=801BC8D Size=576
{
public:
	enum class EArkKeyCardUIState
	{
		LockedDefault = 0,
		LockedNoCard = 1,
		LockedFail = 2,
		LockedMatch = 3,
		UnlockedDefault = 4,
		UnlockedNoCard = 5,
		UnlockedFail = 6,
		UnlockedMatch = 7,
		Processing = 8,
		Inaccessible = 9,
	};

	EArkKeycardReaderState m_pendingState;
	ArkKeycardReader::EArkKeyCardUIState m_uiState;
	ArkSimpleTimer m_processingTimer;
	bool m_bInaccessible;
	uint64_t m_keycard;
	bool m_bStartsInaccessible;
	
	ArkKeycardReader();
	virtual ~ArkKeycardReader();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	virtual void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	void SetInaccessible(bool _bInaccessible) { FSetInaccessible(this,_bInaccessible); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual bool SetLocked(bool _bLocked, bool _bForce);
	const char *GetKeycardLabel() const { return FGetKeycardLabel(this); }
	virtual bool IsProcessing() const;
	virtual void LoadProperties();
	virtual void LoadInstanceProperties();
	virtual const char *GetInteractFunctionName() const;
	virtual const char *GetStateFunctionName() const;
	void UpdateUIState() { FUpdateUIState(this); }
	virtual void RefreshUI();
	virtual bool UseLockedMaterial() const;
	
#if 0
	void SetState(EArkKeycardReaderState arg0);
	bool PlayerHasKeycard() const;
	void SetUIState(ArkKeycardReader::EArkKeyCardUIState arg0);
#endif
	
	static inline auto FBitNotArkKeycardReader = PreyFunction<void(ArkKeycardReader *const _this)>(0x1399990);
	static inline auto FPostInit = PreyFunction<void(ArkKeycardReader *const _this, IGameObject *_pGameObject)>(0x139A320);
	static inline auto FFullSerialize = PreyFunction<void(ArkKeycardReader *const _this, TSerialize _ser)>(0x1399A90);
	static inline auto FPostSerialize = PreyFunction<void(ArkKeycardReader *const _this)>(0x139A360);
	static inline auto FUpdate = PreyFunction<void(ArkKeycardReader *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x139A7C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkKeycardReader const *const _this, ICrySizer *_s)>(0x1399D60);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkKeycardReader *const _this, unsigned _targetId)>(0x139A280);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkKeycardReader *const _this, unsigned _targetId)>(0x139A2C0);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkKeycardReader *const _this, IUIElement *_pUIInstance)>(0x139A300);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkKeycardReader const *const _this)>(0x1B1DEA0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkKeycardReader *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139A0F0);
	static inline auto FSetInaccessible = PreyFunction<void(ArkKeycardReader *const _this, bool _bInaccessible)>(0x139A760);
	static inline auto FOnReset = PreyFunction<void(ArkKeycardReader *const _this, bool _bEnteringGameMode)>(0x139A240);
	static inline auto FSetLocked = PreyFunction<bool(ArkKeycardReader *const _this, bool _bLocked, bool _bForce)>(0x139A790);
	static inline auto FGetKeycardLabel = PreyFunction<const char *(ArkKeycardReader const *const _this)>(0x1399BF0);
	static inline auto FIsProcessing = PreyFunction<bool(ArkKeycardReader const *const _this)>(0x1399D90);
	static inline auto FLoadProperties = PreyFunction<void(ArkKeycardReader *const _this)>(0x1399F30);
	static inline auto FLoadInstanceProperties = PreyFunction<void(ArkKeycardReader *const _this)>(0x1399DA0);
	static inline auto FGetInteractFunctionName = PreyFunction<const char *(ArkKeycardReader const *const _this)>(0x1399BE0);
	static inline auto FGetStateFunctionName = PreyFunction<const char *(ArkKeycardReader const *const _this)>(0x1399D80);
	static inline auto FUpdateUIState = PreyFunction<void(ArkKeycardReader *const _this)>(0x139A8B0);
	static inline auto FRefreshUI = PreyFunction<void(ArkKeycardReader *const _this)>(0x139A390);
	static inline auto FUseLockedMaterial = PreyFunction<bool(ArkKeycardReader const *const _this)>(0x139A960);
};

