// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiTetherProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
class ArkPsiTetherProperties : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkPsiTetherProperties::ArkMaxTethersProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkMaxTethersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxTethersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMaxTethersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMaxTethersProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiTetherProperties::ArkMinDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkMinDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMinDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMinDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiTetherProperties::ArkMaxDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkMaxDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMaxDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMaxDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiTetherProperties::ArkBreakDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkBreakDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBreakDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkBreakDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkBreakDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiTetherProperties::ArkLightningPresetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkLightningPresetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLightningPresetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkLightningPresetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkLightningPresetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiTetherProperties::ArkLightningMaterialProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkLightningMaterialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLightningMaterialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkLightningMaterialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkLightningMaterialProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkStartDrainAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartDrainAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkStopDrainAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStopDrainAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiTetherProperties::ArkDrainAudioRtpcProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
	class ArkDrainAudioRtpcProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDrainAudioRtpcProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkDrainAudioRtpcProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkDrainAudioRtpcProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	static inline auto s_ArkMaxTethersProperty = PreyGlobal<ArkPsiTetherProperties::ArkMaxTethersProperty>(0x2C04748);
	int m_MaxTethers;
	static inline auto s_ArkMinDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkMinDistanceProperty>(0x2C04768);
	float m_MinDistance;
	static inline auto s_ArkMaxDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkMaxDistanceProperty>(0x2C04788);
	float m_MaxDistance;
	static inline auto s_ArkBreakDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkBreakDistanceProperty>(0x2C047A8);
	float m_BreakDistance;
	static inline auto s_ArkLightningPresetProperty = PreyGlobal<ArkPsiTetherProperties::ArkLightningPresetProperty>(0x2C047C8);
	string m_LightningPreset;
	static inline auto s_ArkLightningMaterialProperty = PreyGlobal<ArkPsiTetherProperties::ArkLightningMaterialProperty>(0x2C047E8);
	string m_LightningMaterial;
	static inline auto s_ArkStartDrainAudioTriggerProperty = PreyGlobal<ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty>(0x2C04808);
	string m_StartDrainAudioTrigger;
	static inline auto s_ArkStopDrainAudioTriggerProperty = PreyGlobal<ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty>(0x2C04828);
	string m_StopDrainAudioTrigger;
	static inline auto s_ArkDrainAudioRtpcProperty = PreyGlobal<ArkPsiTetherProperties::ArkDrainAudioRtpcProperty>(0x2C04848);
	string m_DrainAudioRtpc;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMaxTethers(int _arg0_);
	const int& GetMaxTethers() const;
	void SetMinDistance(float _arg0_);
	const float& GetMinDistance() const;
	void SetMaxDistance(float _arg0_);
	const float& GetMaxDistance() const;
	void SetBreakDistance(float _arg0_);
	const float& GetBreakDistance() const;
	void SetLightningPreset(string _arg0_);
	const string& GetLightningPreset() const;
	void SetLightningMaterial(string _arg0_);
	const string& GetLightningMaterial() const;
	void SetStartDrainAudioTrigger(string _arg0_);
	const string& GetStartDrainAudioTrigger() const;
	void SetStopDrainAudioTrigger(string _arg0_);
	const string& GetStopDrainAudioTrigger() const;
	void SetDrainAudioRtpc(string _arg0_);
	const string& GetDrainAudioRtpc() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15AE520);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15AE570);
};

