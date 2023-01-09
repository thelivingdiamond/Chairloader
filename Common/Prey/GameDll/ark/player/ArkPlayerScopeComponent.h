// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

class ArkClass;
class CCryName;
class IArkValueBase;
class XmlNodeRef;

// ArkPlayerScopeComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
class ArkPlayerScopeComponent : public ArkReflectedObject
{ // Size=128 (0x80)
public:
	// ArkPlayerScopeComponent::ArkPostProcessIdProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkPostProcessIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostProcessIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkPostProcessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkPostProcessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPlayerScopeComponent::ArkZoomDeltaProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkZoomDeltaProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkZoomDeltaProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkZoomDeltaProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkZoomDeltaProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkFullyZoomedHFOVProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFullyZoomedHFOVProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkDefaultZoomHFOVProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultZoomHFOVProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkDefaultZoomDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultZoomDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkZoomingInAudioTriggerNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkZoomingInAudioTriggerNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkZoomingOutAudioTriggerNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkZoomingOutAudioTriggerNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkOpenAudioTriggerNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOpenAudioTriggerNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkCloseAudioTriggerNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCloseAudioTriggerNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPlayerScopeComponent::ArkArkInputLegendProperty
	// Header:  Prey/GameDll/ark/player/ArkPlayerScopeComponent.h
	class ArkArkInputLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkArkInputLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayerScopeComponent::ArkArkInputLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1245CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayerScopeComponent::ArkArkInputLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	static inline auto s_ArkPostProcessIdProperty = PreyGlobal<ArkPlayerScopeComponent::ArkPostProcessIdProperty>(0x2BD3580);
	uint64_t m_PostProcessId;
	static inline auto s_ArkZoomDeltaProperty = PreyGlobal<ArkPlayerScopeComponent::ArkZoomDeltaProperty>(0x2BD35A0);
	float m_ZoomDelta;
	static inline auto s_ArkFullyZoomedHFOVProperty = PreyGlobal<ArkPlayerScopeComponent::ArkFullyZoomedHFOVProperty>(0x2BD35C0);
	float m_FullyZoomedHFOV;
	static inline auto s_ArkDefaultZoomHFOVProperty = PreyGlobal<ArkPlayerScopeComponent::ArkDefaultZoomHFOVProperty>(0x2BD35E0);
	float m_DefaultZoomHFOV;
	static inline auto s_ArkDefaultZoomDurationProperty = PreyGlobal<ArkPlayerScopeComponent::ArkDefaultZoomDurationProperty>(0x2BD3600);
	float m_DefaultZoomDuration;
	static inline auto s_ArkZoomingInAudioTriggerNameProperty = PreyGlobal<ArkPlayerScopeComponent::ArkZoomingInAudioTriggerNameProperty>(0x2BD3620);
	string m_ZoomingInAudioTriggerName;
	static inline auto s_ArkZoomingOutAudioTriggerNameProperty = PreyGlobal<ArkPlayerScopeComponent::ArkZoomingOutAudioTriggerNameProperty>(0x2BD3640);
	string m_ZoomingOutAudioTriggerName;
	static inline auto s_ArkOpenAudioTriggerNameProperty = PreyGlobal<ArkPlayerScopeComponent::ArkOpenAudioTriggerNameProperty>(0x2BD3660);
	string m_OpenAudioTriggerName;
	static inline auto s_ArkCloseAudioTriggerNameProperty = PreyGlobal<ArkPlayerScopeComponent::ArkCloseAudioTriggerNameProperty>(0x2BD3680);
	string m_CloseAudioTriggerName;
	static inline auto s_ArkArkInputLegendProperty = PreyGlobal<ArkPlayerScopeComponent::ArkArkInputLegendProperty>(0x2BD36A0);
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
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	bool IsScopeOn() const { return FIsScopeOn(this); }
	void Toggle() { FToggle(this); }
	void Open() { FOpen(this); }
	void Close() { FClose(this); }
	void SetScopeEnabled(bool _bEnabled) { FSetScopeEnabled(this, _bEnabled); }
	void ClearZoom() { FClearZoom(this); }
	void StartedSprinting() { FStartedSprinting(this); }
	float GetCurrentZoomRatio() const { return FGetCurrentZoomRatio(this); }
	void UpdateZoom(float _value, float _deltaTime) { FUpdateZoom(this, _value, _deltaTime); }
	bool IsZoomingIn() const { return FIsZoomingIn(this); }
	void StopAudio() { FStopAudio(this); }
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	bool UpdatePaused();
	void SetPostProcessId(uint64_t _arg0_);
	const uint64_t& GetPostProcessId() const;
	void SetZoomDelta(float _arg0_);
	const float& GetZoomDelta() const;
	void SetFullyZoomedHFOV(float _arg0_);
	const float& GetFullyZoomedHFOV() const;
	void SetDefaultZoomHFOV(float _arg0_);
	const float& GetDefaultZoomHFOV() const;
	void SetDefaultZoomDuration(float _arg0_);
	const float& GetDefaultZoomDuration() const;
	void SetZoomingInAudioTriggerName(string _arg0_);
	const string& GetZoomingInAudioTriggerName() const;
	void SetZoomingOutAudioTriggerName(string _arg0_);
	const string& GetZoomingOutAudioTriggerName() const;
	void SetOpenAudioTriggerName(string _arg0_);
	const string& GetOpenAudioTriggerName() const;
	void SetCloseAudioTriggerName(string _arg0_);
	const string& GetCloseAudioTriggerName() const;
	void SetArkInputLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetArkInputLegend() const;
#endif

	static inline auto FArkPlayerScopeComponentOv2 = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1245D50);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerScopeComponent* const _this, const XmlNodeRef& _root)>(0x1246210);
	static inline auto FReset = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1246480);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerScopeComponent* const _this, TSerialize _ser)>(0x1246490);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerScopeComponent* const _this, float _frameTime)>(0x1246680);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerScopeComponent* const _this, const CCryName& _actionId, const int _activationMode, const float _value)>(0x1246410);
	static inline auto FIsScopeOn = PreyFunction<bool(const ArkPlayerScopeComponent* const _this)>(0x12461C0);
	static inline auto FToggle = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1246590);
	static inline auto FOpen = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1246330);
	static inline auto FClose = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1245EB0);
	static inline auto FSetScopeEnabled = PreyFunction<void(ArkPlayerScopeComponent* const _this, bool _bEnabled)>(0x12464E0);
	static inline auto FClearZoom = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1245E30);
	static inline auto FStartedSprinting = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1246500);
	static inline auto FGetCurrentZoomRatio = PreyFunction<float(const ArkPlayerScopeComponent* const _this)>(0x1246160);
	static inline auto FUpdateZoom = PreyFunction<void(ArkPlayerScopeComponent* const _this, float _value, float _deltaTime)>(0x1246800);
	static inline auto FIsZoomingIn = PreyFunction<bool(const ArkPlayerScopeComponent* const _this)>(0x12461D0);
	static inline auto FStopAudio = PreyFunction<void(ArkPlayerScopeComponent* const _this)>(0x1246540);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1245F70);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1246070);
};

