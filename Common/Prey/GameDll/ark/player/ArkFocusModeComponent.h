// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkTimeScaler.h>
#include <Prey/GameDll/ark/player/ArkFocusModeEffectsManager.h>
#include <Prey/GameDll/ark/ui/ArkFocusModeUIComponent.h>

class CArkFlowNodeFocusModeEnabled;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkFocusModeComponent.h
class ArkFocusModeComponent // Id=801725D Size=928
{
public:
	ArkFocusModeUIComponent m_uiComponent;
	ArkFocusModeEffectsManager m_effectsManager;
	ArkTimeScaler m_gameTimeScaler;
	ArkTimeScaler m_playerTimeScaler;
	ArkAudioTrigger m_pauseGameTimerTrigger;
	ArkAudioTrigger m_resumeGameTimerTrigger;
	CArkFlowNodeFocusModeEnabled const *m_pFlowNodeEnabled;
	bool m_bEnabled;
	bool m_bJustSerialized;
	int m_noPowersStringIndex;
	int m_inputHandle;
	
	ArkFocusModeComponent();
	~ArkFocusModeComponent() { FBitNotArkFocusModeComponent(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Stop(const bool _bFromTargeting) { FStop(this,_bFromTargeting); }
	bool Start(const bool _bOpenMenu) { return FStart(this,_bOpenMenu); }
	bool IsTargeting() const { return FIsTargeting(this); }
	void RegisterEnabledFlowNode(CArkFlowNodeFocusModeEnabled const *_pFlowNode) { FRegisterEnabledFlowNode(this,_pFlowNode); }
	void ProcessInput(CCryName _actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }
	void EnableInputMode(const bool _bEnable) { FEnableInputMode(this,_bEnable); }
	
#if 0
	bool IsEnabled() const;
	ArkTimeScaler &GetGameTimeScaler();
	ArkTimeScaler &GetPlayerTimeScaler();
	ArkFocusModeEffectsManager &GetEffectsManager();
	void UnregisterEnabledFlowNode();
	ArkFocusModeUIComponent &GetFocusModeUIComponent();
#endif
	
	static inline auto FBitNotArkFocusModeComponent = PreyFunction<void(ArkFocusModeComponent *const _this)>(0x1220FB0);
	static inline auto FUpdate = PreyFunction<void(ArkFocusModeComponent *const _this, const float _frameTime)>(0x12219B0);
	static inline auto FStop = PreyFunction<void(ArkFocusModeComponent *const _this, const bool _bFromTargeting)>(0x1221840);
	static inline auto FStart = PreyFunction<bool(ArkFocusModeComponent *const _this, const bool _bOpenMenu)>(0x1221730);
	static inline auto FIsTargeting = PreyFunction<bool(ArkFocusModeComponent const *const _this)>(0x1221100);
	static inline auto FRegisterEnabledFlowNode = PreyFunction<void(ArkFocusModeComponent *const _this, CArkFlowNodeFocusModeEnabled const *_pFlowNode)>(0x12215F0);
	static inline auto FProcessInput = PreyFunction<void(ArkFocusModeComponent *const _this, CCryName _actionId, const int _activationMode, const float _value)>(0x12211D0);
	static inline auto FSerialize = PreyFunction<void(ArkFocusModeComponent *const _this, TSerialize _ser)>(0x1221680);
	static inline auto FPostSerialize = PreyFunction<void(ArkFocusModeComponent *const _this)>(0x1221120);
	static inline auto FReset = PreyFunction<void(ArkFocusModeComponent *const _this)>(0x1221600);
	static inline auto FEnableInputMode = PreyFunction<void(ArkFocusModeComponent *const _this, const bool _bEnable)>(0x1221010);
};

