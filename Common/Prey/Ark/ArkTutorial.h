// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arktutorial.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arktutorial.h
class ArkPsiPowerLiftUniqueProperties : public ArkReflectedObject // Id=80141A0 Size=104
{
public:
	class ArkMinHeightProperty : public ArkProperty // Id=80141A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty s_ArkMinHeightProperty;
	float m_MinHeight;
	
	class ArkMaxRangeProperty : public ArkProperty // Id=80141A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty s_ArkMaxRangeProperty;
	float m_MaxRange;
	
	class ArkMaxRangeZeroGProperty : public ArkProperty // Id=80141A3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty s_ArkMaxRangeZeroGProperty;
	float m_MaxRangeZeroG;
	
	class ArkRadiusProperty : public ArkProperty // Id=80141A4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty s_ArkRadiusProperty;
	float m_Radius;
	
	class ArkGravityProperty : public ArkProperty // Id=80141A5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkGravityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkGravityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkGravityProperty s_ArkGravityProperty;
	float m_Gravity;
	
	class ArkInwardLiftForceProperty : public ArkProperty // Id=80141A6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty s_ArkInwardLiftForceProperty;
	float m_InwardLiftForce;
	
	class ArkUpwardLiftForceProperty : public ArkProperty // Id=80141A7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty s_ArkUpwardLiftForceProperty;
	float m_UpwardLiftForce;
	
	class ArkLiftForceZeroGProperty : public ArkProperty // Id=80141A8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty s_ArkLiftForceZeroGProperty;
	float m_LiftForceZeroG;
	
	class ArkHoverVelocityDampingProperty : public ArkProperty // Id=80141A9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty s_ArkHoverVelocityDampingProperty;
	float m_HoverVelocityDamping;
	
	class ArkHoverVelocityFalloffProperty : public ArkProperty // Id=80141AA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty s_ArkHoverVelocityFalloffProperty;
	float m_HoverVelocityFalloff;
	
	class ArkHoverFalloffDistanceProperty : public ArkProperty // Id=80141AB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty s_ArkHoverFalloffDistanceProperty;
	float m_HoverFalloffDistance;
	
	class ArkParticleEffectProperty : public ArkProperty // Id=80141AC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty s_ArkParticleEffectProperty;
	string m_ParticleEffect;
	
	class ArkTargetingParticleEffectProperty : public ArkProperty // Id=80141AD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty s_ArkTargetingParticleEffectProperty;
	string m_TargetingParticleEffect;
	
	class ArkTargetingParticleEffectLightProperty : public ArkProperty // Id=80141AE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty s_ArkTargetingParticleEffectLightProperty;
	string m_TargetingParticleEffectLight;
	
	class ArkPlayerPostEffectIdProperty : public ArkProperty // Id=80141AF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty s_ArkPlayerPostEffectIdProperty;
	uint64_t m_PlayerPostEffectId;
	
	class ArkPlayerEnterAudioTriggerProperty : public ArkProperty // Id=80141B0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty s_ArkPlayerEnterAudioTriggerProperty;
	string m_PlayerEnterAudioTrigger;
	
	class ArkPlayerExitAudioTriggerProperty : public ArkProperty // Id=80141B1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty s_ArkPlayerExitAudioTriggerProperty;
	string m_PlayerExitAudioTrigger;
	
	class ArkEnterLiftSignalPackageIdProperty : public ArkProperty // Id=80141B2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1089080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty s_ArkEnterLiftSignalPackageIdProperty;
	uint64_t m_EnterLiftSignalPackageId;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMinHeight(float arg0);
	const float &GetMinHeight() const;
	void SetMaxRange(float arg0);
	const float &GetMaxRange() const;
	void SetMaxRangeZeroG(float arg0);
	const float &GetMaxRangeZeroG() const;
	void SetRadius(float arg0);
	const float &GetRadius() const;
	void SetGravity(float arg0);
	const float &GetGravity() const;
	void SetInwardLiftForce(float arg0);
	const float &GetInwardLiftForce() const;
	void SetUpwardLiftForce(float arg0);
	const float &GetUpwardLiftForce() const;
	void SetLiftForceZeroG(float arg0);
	const float &GetLiftForceZeroG() const;
	void SetHoverVelocityDamping(float arg0);
	const float &GetHoverVelocityDamping() const;
	void SetHoverVelocityFalloff(float arg0);
	const float &GetHoverVelocityFalloff() const;
	void SetHoverFalloffDistance(float arg0);
	const float &GetHoverFalloffDistance() const;
	void SetParticleEffect(string arg0);
	string const &GetParticleEffect() const;
	void SetTargetingParticleEffect(string arg0);
	string const &GetTargetingParticleEffect() const;
	void SetTargetingParticleEffectLight(string arg0);
	string const &GetTargetingParticleEffectLight() const;
	void SetPlayerPostEffectId(uint64_t arg0);
	const uint64_t &GetPlayerPostEffectId() const;
	void SetPlayerEnterAudioTrigger(string arg0);
	string const &GetPlayerEnterAudioTrigger() const;
	void SetPlayerExitAudioTrigger(string arg0);
	string const &GetPlayerExitAudioTrigger() const;
	void SetEnterLiftSignalPackageId(uint64_t arg0);
	const uint64_t &GetEnterLiftSignalPackageId() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F64A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12F6720);
};

// Header: Exact
// Prey/Ark/ArkTutorial.h
class ArkTutorial : public ArkReflectedObject // Id=801692D Size=56
{
public:
	class ArkIDProperty : public ArkProperty // Id=801692E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorial::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorial::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkTutorial::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=801692F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorial::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorial::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkTutorial::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkCooldownProperty : public ArkProperty // Id=8016930 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorial::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorial::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkTutorial::ArkCooldownProperty s_ArkCooldownProperty;
	float m_Cooldown;
	
	class ArkBodyProperty : public ArkProperty // Id=8016931 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorial::ArkBodyProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorial::ArkBodyProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkTutorial::ArkBodyProperty s_ArkBodyProperty;
	string m_Body;
	
	class ArkBodyPCProperty : public ArkProperty // Id=8016932 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorial::ArkBodyPCProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorial::ArkBodyPCProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkTutorial::ArkBodyPCProperty s_ArkBodyPCProperty;
	string m_BodyPC;
	
	class ArkTypeProperty : public ArkProperty // Id=8016933 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const arg0, IArkValueBase const *arg1) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const arg0) const;
	};

	static ArkTutorial::ArkTypeProperty s_ArkTypeProperty;
	ArkTutorialType m_Type;
	
	class ArkAudioTriggerProperty : public ArkProperty // Id=8016934 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorial::ArkAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorial::ArkAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkTutorial::ArkAudioTriggerProperty s_ArkAudioTriggerProperty;
	string m_AudioTrigger;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetCooldown(float arg0);
	const float &GetCooldown() const;
	void SetBody(string arg0);
	string const &GetBody() const;
	void SetBodyPC(string arg0);
	string const &GetBodyPC() const;
	void SetType(ArkTutorialType arg0);
	ArkTutorialType const &GetType() const;
	void SetAudioTrigger(string arg0);
	string const &GetAudioTrigger() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10867C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10869A0);
};

// Header: Exact
// Prey/Ark/arktutorial.h
class ArkCardTutorial : public ArkTutorial // Id=8016936 Size=88
{
public:
	class ArkTitleProperty : public ArkProperty // Id=8016937 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCardTutorial::ArkTitleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCardTutorial::ArkTitleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkCardTutorial::ArkTitleProperty s_ArkTitleProperty;
	string m_Title;
	
	class ArkImageProperty : public ArkProperty // Id=8016938 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCardTutorial::ArkImageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCardTutorial::ArkImageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkCardTutorial::ArkImageProperty s_ArkImageProperty;
	string m_Image;
	
	class ArkDialogProperty : public ArkProperty // Id=8016939 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCardTutorial::ArkDialogProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCardTutorial::ArkDialogProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkCardTutorial::ArkDialogProperty s_ArkDialogProperty;
	uint64_t m_Dialog;
	
	class ArkDelayProperty : public ArkProperty // Id=801693A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCardTutorial::ArkDelayProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCardTutorial::ArkDelayProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkCardTutorial::ArkDelayProperty s_ArkDelayProperty;
	float m_Delay;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetTitle(string arg0);
	string const &GetTitle() const;
	void SetImage(string arg0);
	string const &GetImage() const;
	void SetDialog(uint64_t arg0);
	const uint64_t &GetDialog() const;
	void SetDelay(float arg0);
	const float &GetDelay() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10866C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1086860);
};

// Header: Exact
// Prey/Ark/arktutorial.h
class ArkContextualTutorial : public ArkCardTutorial // Id=8016935 Size=120
{
public:
	class ArkActionMapProperty : public ArkProperty // Id=801693B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkContextualTutorial::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkContextualTutorial::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkContextualTutorial::ArkActionMapProperty s_ArkActionMapProperty;
	string m_ActionMap;
	
	class ArkActionIdProperty : public ArkProperty // Id=801693C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkContextualTutorial::ArkActionIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10860F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkContextualTutorial::ArkActionIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkContextualTutorial::ArkActionIdProperty s_ArkActionIdProperty;
	CCryName m_ActionId;
	
	class ArkActionIdPCProperty : public ArkProperty // Id=801693D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkContextualTutorial::ArkActionIdPCProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkContextualTutorial::ArkActionIdPCProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkContextualTutorial::ArkActionIdPCProperty s_ArkActionIdPCProperty;
	CCryName m_ActionIdPC;
	
	class ArkTutorialPromptProperty : public ArkProperty // Id=801693E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkContextualTutorial::ArkTutorialPromptProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10890A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkContextualTutorial::ArkTutorialPromptProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkContextualTutorial::ArkTutorialPromptProperty s_ArkTutorialPromptProperty;
	bool m_TutorialPrompt;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetActionMap(string arg0);
	string const &GetActionMap() const;
	void SetActionId(CCryName arg0);
	CCryName const &GetActionId() const;
	void SetActionIdPC(CCryName arg0);
	CCryName const &GetActionIdPC() const;
	void SetTutorialPrompt(bool arg0);
	const bool &GetTutorialPrompt() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1086710);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1086900);
};

// Header: Exact
// Prey/Ark/arktutorial.h
class ArkTutorialLibrary : public ArkReflectedLibrary // Id=8016CC0 Size=40
{
public:
	class ArkTutorialsProperty : public ArkProperty // Id=8016CC1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorialLibrary::ArkTutorialsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086200);
		static inline auto FIsArray = PreyFunction<bool(ArkTutorialLibrary::ArkTutorialsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTutorialLibrary::ArkTutorialsProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FE00);
	};

	static ArkTutorialLibrary::ArkTutorialsProperty s_ArkTutorialsProperty;
	std::vector<std::shared_ptr<ArkTutorial>> m_Tutorials;
	
	class ArkContextualDisplayTimeProperty : public ArkProperty // Id=8016CC2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorialLibrary::ArkContextualDisplayTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A63A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorialLibrary::ArkContextualDisplayTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
	};

	static ArkTutorialLibrary::ArkContextualDisplayTimeProperty s_ArkContextualDisplayTimeProperty;
	float m_ContextualDisplayTime;
	
	class ArkNagDisplayTimeProperty : public ArkProperty // Id=8016CC3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorialLibrary::ArkNagDisplayTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086230);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorialLibrary::ArkNagDisplayTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A63C0);
	};

	static ArkTutorialLibrary::ArkNagDisplayTimeProperty s_ArkNagDisplayTimeProperty;
	float m_NagDisplayTime;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkTutorial const *FindTutorial(const uint64_t _id) const { return FFindTutorial(this,_id); }
	virtual bool Init();
	virtual ~ArkTutorialLibrary();
	
#if 0
	std::vector<std::shared_ptr<ArkTutorial>> &GetTutorials();
	std::vector<std::shared_ptr<ArkTutorial>> const &GetTutorials() const;
	void SetContextualDisplayTime(float arg0);
	const float &GetContextualDisplayTime() const;
	void SetNagDisplayTime(float arg0);
	const float &GetNagDisplayTime() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1086800);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1086A40);
	static inline auto FFindTutorial = PreyFunction<ArkTutorial const *(ArkTutorialLibrary const *const _this, const uint64_t _id)>(0x134FB80);
	static inline auto FInit = PreyFunction<bool(ArkTutorialLibrary *const _this)>(0x1086B30);
};

