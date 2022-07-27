// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsitethermanager.h
class ArkPsiTetherProperties : public ArkReflectedObject // Id=801C9BD Size=56
{
public:
	class ArkMaxTethersProperty : public ArkProperty // Id=801C9BE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkMaxTethersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkMaxTethersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiTetherProperties::ArkMaxTethersProperty s_ArkMaxTethersProperty;
	int m_MaxTethers;
	
	class ArkMinDistanceProperty : public ArkProperty // Id=801C9BF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkMinDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkMinDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiTetherProperties::ArkMinDistanceProperty s_ArkMinDistanceProperty;
	float m_MinDistance;
	
	class ArkMaxDistanceProperty : public ArkProperty // Id=801C9C0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkMaxDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkMaxDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiTetherProperties::ArkMaxDistanceProperty s_ArkMaxDistanceProperty;
	float m_MaxDistance;
	
	class ArkBreakDistanceProperty : public ArkProperty // Id=801C9C1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkBreakDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkBreakDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiTetherProperties::ArkBreakDistanceProperty s_ArkBreakDistanceProperty;
	float m_BreakDistance;
	
	class ArkLightningPresetProperty : public ArkProperty // Id=801C9C2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkLightningPresetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkLightningPresetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiTetherProperties::ArkLightningPresetProperty s_ArkLightningPresetProperty;
	string m_LightningPreset;
	
	class ArkLightningMaterialProperty : public ArkProperty // Id=801C9C3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkLightningMaterialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkLightningMaterialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiTetherProperties::ArkLightningMaterialProperty s_ArkLightningMaterialProperty;
	string m_LightningMaterial;
	
	class ArkStartDrainAudioTriggerProperty : public ArkProperty // Id=801C9C4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiTetherProperties::ArkStartDrainAudioTriggerProperty s_ArkStartDrainAudioTriggerProperty;
	string m_StartDrainAudioTrigger;
	
	class ArkStopDrainAudioTriggerProperty : public ArkProperty // Id=801C9C5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiTetherProperties::ArkStopDrainAudioTriggerProperty s_ArkStopDrainAudioTriggerProperty;
	string m_StopDrainAudioTrigger;
	
	class ArkDrainAudioRtpcProperty : public ArkProperty // Id=801C9C6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiTetherProperties::ArkDrainAudioRtpcProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiTetherProperties::ArkDrainAudioRtpcProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiTetherProperties::ArkDrainAudioRtpcProperty s_ArkDrainAudioRtpcProperty;
	string m_DrainAudioRtpc;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMaxTethers(int arg0);
	const int &GetMaxTethers() const;
	void SetMinDistance(float arg0);
	const float &GetMinDistance() const;
	void SetMaxDistance(float arg0);
	const float &GetMaxDistance() const;
	void SetBreakDistance(float arg0);
	const float &GetBreakDistance() const;
	void SetLightningPreset(string arg0);
	string const &GetLightningPreset() const;
	void SetLightningMaterial(string arg0);
	string const &GetLightningMaterial() const;
	void SetStartDrainAudioTrigger(string arg0);
	string const &GetStartDrainAudioTrigger() const;
	void SetStopDrainAudioTrigger(string arg0);
	string const &GetStopDrainAudioTrigger() const;
	void SetDrainAudioRtpc(string arg0);
	string const &GetDrainAudioRtpc() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15AE520);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15AE570);
};

