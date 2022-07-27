// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/player/arkplayerlight.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h>

class ArkClass;
class IArkPsiPower;
struct IEntity;
struct IParticleEffect;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h
class ArkPsiPowerTargetingComponentProperties : public ArkReflectedObject // Id=80134C5 Size=80
{
public:
	class ArkMinRangeProperty : public ArkProperty // Id=80134C6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty s_ArkMinRangeProperty;
	float m_MinRange;
	
	class ArkMaxRangeProperty : public ArkProperty // Id=80134C7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty s_ArkMaxRangeProperty;
	float m_MaxRange;
	
	class ArkTargetParticleEffectProperty : public ArkProperty // Id=80134C8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty s_ArkTargetParticleEffectProperty;
	string m_TargetParticleEffect;
	
	class ArkTargetParticleEffectAttachmentProperty : public ArkProperty // Id=80134C9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty s_ArkTargetParticleEffectAttachmentProperty;
	string m_TargetParticleEffectAttachment;
	
	class ArkTargetParticleLightEffectProperty : public ArkProperty // Id=80134CA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty s_ArkTargetParticleLightEffectProperty;
	string m_TargetParticleLightEffect;
	
	class ArkValidTargetClassesProperty : public ArkProperty // Id=80134CB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14690E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1469140);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1469160);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty s_ArkValidTargetClassesProperty;
	std::vector<string> m_ValidTargetClasses;
	
	class ArkValidTargetMetaTagsProperty : public ArkProperty // Id=80134CC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059650);
	};

	static ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty s_ArkValidTargetMetaTagsProperty;
	std::vector<unsigned __int64> m_ValidTargetMetaTags;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMinRange(float arg0);
	const float &GetMinRange() const;
	void SetMaxRange(float arg0);
	const float &GetMaxRange() const;
	void SetTargetParticleEffect(string arg0);
	string const &GetTargetParticleEffect() const;
	void SetTargetParticleEffectAttachment(string arg0);
	string const &GetTargetParticleEffectAttachment() const;
	void SetTargetParticleLightEffect(string arg0);
	string const &GetTargetParticleLightEffect() const;
	std::vector<string> &GetValidTargetClasses();
	std::vector<string> const &GetValidTargetClasses() const;
	std::vector<unsigned __int64> &GetValidTargetMetaTags();
	std::vector<unsigned __int64> const &GetValidTargetMetaTags() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x14694F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1469560);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
class ArkPsiPowerTargetingComponent // Id=80134C4 Size=216
{
public:
	using Properties = ArkPsiPowerTargetingComponentProperties;
	
	IArkPsiPower const *m_pPower;
	ArkPlayerLightVFX m_playerLight;
	IParticleEffect *m_pTargetParticleEffect;
	std::vector<IEntityClass const *> m_validClasses;
	std::vector<unsigned __int64> m_validMetaTags;
	ArkPsiPowerTargetingComponentProperties const *m_pProperties;
	
	static Vec3 GetPsiTargetingPosition(IEntity const *const _pEntity) { return FGetPsiTargetingPosition(_pEntity); }
	static IEntity *GetRedirectedPsiTarget(IEntity *const _pEntity) { return FGetRedirectedPsiTarget(_pEntity); }
	static bool IsLineClear(Vec3 const &_origin, IEntity const &_entity) { return FIsLineClear(_origin,_entity); }
	ArkPsiPowerTargetingComponent(IArkPsiPower const *_pPower);
	virtual ~ArkPsiPowerTargetingComponent();
	void Initialize(ArkPsiPowerTargetingComponentProperties const &_properties) { FInitialize(this,_properties); }
	virtual bool Start();
	virtual void Stop();
	float GetRange() const { return FGetRange(this); }
	
#if 0
	ArkPsiPowerTargetingComponentProperties const &GetProperties() const;
	float GetMinRange() const;
	IArkPsiPower const *GetPower() const;
	IParticleEffect *GetTargetParticleEffect() const;
#endif
	
	static inline auto FGetPsiTargetingPosition = PreyFunction<Vec3(IEntity const *const _pEntity)>(0x1469650);
	static inline auto FGetRedirectedPsiTarget = PreyFunction<IEntity *(IEntity *const _pEntity)>(0x1469780);
	static inline auto FIsLineClear = PreyFunction<bool(Vec3 const &_origin, IEntity const &_entity)>(0x1469A40);
	static inline auto FBitNotArkPsiPowerTargetingComponent = PreyFunction<void(ArkPsiPowerTargetingComponent *const _this)>(0x1469450);
	static inline auto FInitialize = PreyFunction<void(ArkPsiPowerTargetingComponent *const _this, ArkPsiPowerTargetingComponentProperties const &_properties)>(0x14697C0);
	static inline auto FStart = PreyFunction<bool(ArkPsiPowerTargetingComponent *const _this)>(0x1B933B0);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerTargetingComponent *const _this)>(0xA13080);
	static inline auto FGetRange = PreyFunction<float(ArkPsiPowerTargetingComponent const *const _this)>(0x1469770);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h
class ArkAudioLog : public ArkReflectedObject // Id=801354B Size=88
{
public:
	class ArkIDProperty : public ArkProperty // Id=801354C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAudioLog::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=801354D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAudioLog::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=801354E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkAudioLog::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkConversationProperty : public ArkProperty // Id=801354F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkConversationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkConversationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkAudioLog::ArkConversationProperty s_ArkConversationProperty;
	uint64_t m_Conversation;
	
	class ArkKeyCodeProperty : public ArkProperty // Id=8013550 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkKeyCodeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkKeyCodeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkAudioLog::ArkKeyCodeProperty s_ArkKeyCodeProperty;
	uint64_t m_KeyCode;
	
	class ArkPasswordProperty : public ArkProperty // Id=8013551 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkAudioLog::ArkPasswordProperty s_ArkPasswordProperty;
	uint64_t m_Password;
	
	class ArkDateProperty : public ArkProperty // Id=8013552 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkDateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkDateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkAudioLog::ArkDateProperty s_ArkDateProperty;
	string m_Date;
	
	class ArkToProperty : public ArkProperty // Id=8013553 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkToProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkToProperty const *const _this, ArkReflectedObject *const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(ArkAudioLog::ArkToProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAudioLog::ArkToProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059650);
	};

	static ArkAudioLog::ArkToProperty s_ArkToProperty;
	std::vector<unsigned __int64> m_To;
	
	class ArkFromProperty : public ArkProperty // Id=8013554 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLog::ArkFromProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105BA70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLog::ArkFromProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkAudioLog::ArkFromProperty s_ArkFromProperty;
	uint64_t m_From;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetConversation(uint64_t arg0);
	const uint64_t &GetConversation() const;
	void SetKeyCode(uint64_t arg0);
	const uint64_t &GetKeyCode() const;
	void SetPassword(uint64_t arg0);
	const uint64_t &GetPassword() const;
	void SetDate(string arg0);
	string const &GetDate() const;
	std::vector<unsigned __int64> &GetTo();
	std::vector<unsigned __int64> const &GetTo() const;
	void SetFrom(uint64_t arg0);
	const uint64_t &GetFrom() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105A270);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105A370);
};

