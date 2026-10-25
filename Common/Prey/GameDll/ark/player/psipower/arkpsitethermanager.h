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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMaxTethersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMaxTethersProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMaxTethersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMaxTethersProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMinDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMinDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMinDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMinDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMaxDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMaxDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkMaxDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkMaxDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkBreakDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkBreakDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkBreakDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkBreakDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkLightningPresetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkLightningPresetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkLightningPresetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkLightningPresetProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkLightningMaterialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkLightningMaterialProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkLightningMaterialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkLightningMaterialProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkDrainAudioRtpcProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkDrainAudioRtpcProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiTetherProperties::ArkDrainAudioRtpcProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiTetherProperties::ArkDrainAudioRtpcProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkMaxTethersProperty = PreyGlobal<ArkPsiTetherProperties::ArkMaxTethersProperty>(0x2C04748);
#else
	static inline auto s_ArkMaxTethersProperty = PreyGlobal<ArkPsiTetherProperties::ArkMaxTethersProperty>(0x2D7EFD8);
#endif
	int m_MaxTethers;
#ifndef MOONCRASH
	static inline auto s_ArkMinDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkMinDistanceProperty>(0x2C04768);
#else
	static inline auto s_ArkMinDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkMinDistanceProperty>(0x2D7EFF8);
#endif
	float m_MinDistance;
#ifndef MOONCRASH
	static inline auto s_ArkMaxDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkMaxDistanceProperty>(0x2C04788);
#else
	static inline auto s_ArkMaxDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkMaxDistanceProperty>(0x2D7F018);
#endif
	float m_MaxDistance;
#ifndef MOONCRASH
	static inline auto s_ArkBreakDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkBreakDistanceProperty>(0x2C047A8);
#else
	static inline auto s_ArkBreakDistanceProperty = PreyGlobal<ArkPsiTetherProperties::ArkBreakDistanceProperty>(0x2D7F038);
#endif
	float m_BreakDistance;
#ifndef MOONCRASH
	static inline auto s_ArkLightningPresetProperty = PreyGlobal<ArkPsiTetherProperties::ArkLightningPresetProperty>(0x2C047C8);
#else
	static inline auto s_ArkLightningPresetProperty = PreyGlobal<ArkPsiTetherProperties::ArkLightningPresetProperty>(0x2D7F058);
#endif
	string m_LightningPreset;
#ifndef MOONCRASH
	static inline auto s_ArkLightningMaterialProperty = PreyGlobal<ArkPsiTetherProperties::ArkLightningMaterialProperty>(0x2C047E8);
#else
	static inline auto s_ArkLightningMaterialProperty = PreyGlobal<ArkPsiTetherProperties::ArkLightningMaterialProperty>(0x2D7F078);
#endif
	string m_LightningMaterial;
#ifndef MOONCRASH
	static inline auto s_ArkStartDrainAudioTriggerProperty = PreyGlobal<ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty>(0x2C04808);
#else
	static inline auto s_ArkStartDrainAudioTriggerProperty = PreyGlobal<ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty>(0x2D7F098);
#endif
	string m_StartDrainAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkStopDrainAudioTriggerProperty = PreyGlobal<ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty>(0x2C04828);
#else
	static inline auto s_ArkStopDrainAudioTriggerProperty = PreyGlobal<ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty>(0x2D7F0B8);
#endif
	string m_StopDrainAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkDrainAudioRtpcProperty = PreyGlobal<ArkPsiTetherProperties::ArkDrainAudioRtpcProperty>(0x2C04848);
#else
	static inline auto s_ArkDrainAudioRtpcProperty = PreyGlobal<ArkPsiTetherProperties::ArkDrainAudioRtpcProperty>(0x2D7F0D8);
#endif
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

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15AE520);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15AE570);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16D22F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x16D2340);
#endif
};
