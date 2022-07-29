// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

class ArkClass;
class CCryName;
class XmlNodeRef;

// Header: Exact
// Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
class ArkPlayerScopeComponent : public ArkReflectedObject // Id=8017213 Size=128
{
public:
	class ArkPostProcessIdProperty : public ArkProperty // Id=8017214 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkPostProcessIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkPostProcessIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPlayerScopeComponent::ArkPostProcessIdProperty s_ArkPostProcessIdProperty;
	uint64_t m_PostProcessId;
	
	class ArkZoomDeltaProperty : public ArkProperty // Id=8017215 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkZoomDeltaProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkZoomDeltaProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPlayerScopeComponent::ArkZoomDeltaProperty s_ArkZoomDeltaProperty;
	float m_ZoomDelta;
	
	class ArkFullyZoomedHFOVProperty : public ArkProperty // Id=8017216 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty s_ArkFullyZoomedHFOVProperty;
	float m_FullyZoomedHFOV;
	
	class ArkDefaultZoomHFOVProperty : public ArkProperty // Id=8017217 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty s_ArkDefaultZoomHFOVProperty;
	float m_DefaultZoomHFOV;
	
	class ArkDefaultZoomDurationProperty : public ArkProperty // Id=8017218 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty s_ArkDefaultZoomDurationProperty;
	float m_DefaultZoomDuration;
	
	class ArkZoomingInAudioTriggerNameProperty : public ArkProperty // Id=8017219 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty s_ArkZoomingInAudioTriggerNameProperty;
	string m_ZoomingInAudioTriggerName;
	
	class ArkZoomingOutAudioTriggerNameProperty : public ArkProperty // Id=801721A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty s_ArkZoomingOutAudioTriggerNameProperty;
	string m_ZoomingOutAudioTriggerName;
	
	class ArkOpenAudioTriggerNameProperty : public ArkProperty // Id=801721B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty s_ArkOpenAudioTriggerNameProperty;
	string m_OpenAudioTriggerName;
	
	class ArkCloseAudioTriggerNameProperty : public ArkProperty // Id=801721C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty s_ArkCloseAudioTriggerNameProperty;
	string m_CloseAudioTriggerName;
	
	class ArkArkInputLegendProperty : public ArkProperty // Id=801721D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPlayerScopeComponent::ArkArkInputLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1245CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPlayerScopeComponent::ArkArkInputLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPlayerScopeComponent::ArkArkInputLegendProperty s_ArkArkInputLegendProperty;
	ArkInputLegend m_ArkInputLegend;
	bool m_bScopeEnabled;
	bool m_bScopeOn;
	bool m_bPaused;
	bool m_bZoomInAudio;
	int m_zoomHandle;
	float m_zoomHoldRepeatDelay;
	ArkSimpleTimer m_zoomAudioTimer;
	ArkAudioTrigger m_triggerZoomingIn;
	ArkAudioTrigger m_triggerZoomingOut;
	ArkAudioTrigger m_triggerOpen;
	ArkAudioTrigger m_triggerClose;
	ArkInputLegendHandler m_inputLegendHandler;
	
	ArkPlayerScopeComponent();
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	bool IsScopeOn() const { return FIsScopeOn(this); }
	void Toggle() { FToggle(this); }
	void Open() { FOpen(this); }
	void Close() { FClose(this); }
	void SetScopeEnabled(bool _bEnabled) { FSetScopeEnabled(this,_bEnabled); }
	void ClearZoom() { FClearZoom(this); }
	void StartedSprinting() { FStartedSprinting(this); }
	float GetCurrentZoomRatio() const { return FGetCurrentZoomRatio(this); }
	void UpdateZoom(float _value, float _deltaTime) { FUpdateZoom(this,_value,_deltaTime); }
	bool IsZoomingIn() const { return FIsZoomingIn(this); }
	void StopAudio() { FStopAudio(this); }
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	bool UpdatePaused();
	void SetPostProcessId(uint64_t arg0);
	const uint64_t &GetPostProcessId() const;
	void SetZoomDelta(float arg0);
	const float &GetZoomDelta() const;
	void SetFullyZoomedHFOV(float arg0);
	const float &GetFullyZoomedHFOV() const;
	void SetDefaultZoomHFOV(float arg0);
	const float &GetDefaultZoomHFOV() const;
	void SetDefaultZoomDuration(float arg0);
	const float &GetDefaultZoomDuration() const;
	void SetZoomingInAudioTriggerName(string arg0);
	string const &GetZoomingInAudioTriggerName() const;
	void SetZoomingOutAudioTriggerName(string arg0);
	string const &GetZoomingOutAudioTriggerName() const;
	void SetOpenAudioTriggerName(string arg0);
	string const &GetOpenAudioTriggerName() const;
	void SetCloseAudioTriggerName(string arg0);
	string const &GetCloseAudioTriggerName() const;
	void SetArkInputLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetArkInputLegend() const;
#endif
	
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerScopeComponent *const _this, XmlNodeRef const &_root)>(0x1246210);
	static inline auto FReset = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1246480);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerScopeComponent *const _this, TSerialize _ser)>(0x1246490);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerScopeComponent *const _this, float _frameTime)>(0x1246680);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerScopeComponent *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x1246410);
	static inline auto FIsScopeOn = PreyFunction<bool(ArkPlayerScopeComponent const *const _this)>(0x12461C0);
	static inline auto FToggle = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1246590);
	static inline auto FOpen = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1246330);
	static inline auto FClose = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1245EB0);
	static inline auto FSetScopeEnabled = PreyFunction<void(ArkPlayerScopeComponent *const _this, bool _bEnabled)>(0x12464E0);
	static inline auto FClearZoom = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1245E30);
	static inline auto FStartedSprinting = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1246500);
	static inline auto FGetCurrentZoomRatio = PreyFunction<float(ArkPlayerScopeComponent const *const _this)>(0x1246160);
	static inline auto FUpdateZoom = PreyFunction<void(ArkPlayerScopeComponent *const _this, float _value, float _deltaTime)>(0x1246800);
	static inline auto FIsZoomingIn = PreyFunction<bool(ArkPlayerScopeComponent const *const _this)>(0x12461D0);
	static inline auto FStopAudio = PreyFunction<void(ArkPlayerScopeComponent *const _this)>(0x1246540);
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1245F70);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1246070);
};

