// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;
class IArkValueBase;

// ArkTutorial
// Header:  Prey/Ark/ArkTutorial.h
class ArkTutorial : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkTutorial::ArkIDProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorial::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorial::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkTutorial::ArkNameProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorial::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorial::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkTutorial::ArkCooldownProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkCooldownProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorial::ArkCooldownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorial::ArkCooldownProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkTutorial::ArkBodyProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkBodyProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBodyProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorial::ArkBodyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorial::ArkBodyProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkTutorial::ArkBodyPCProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkBodyPCProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBodyPCProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorial::ArkBodyPCProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorial::ArkBodyPCProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkTutorial::ArkTypeProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _arg0_, const IArkValueBase* _arg1_) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _arg0_) const;

	#if 0
		ArkTypeProperty();
	#endif
	};

	// ArkTutorial::ArkAudioTriggerProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorial::ArkAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorial::ArkAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkTutorial::ArkIDProperty>(0x2D29050);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkTutorial::ArkNameProperty>(0x2D29070);
	string m_Name;
	static inline auto s_ArkCooldownProperty = PreyGlobal<ArkTutorial::ArkCooldownProperty>(0x2D29090);
	float m_Cooldown;
	static inline auto s_ArkBodyProperty = PreyGlobal<ArkTutorial::ArkBodyProperty>(0x2D290B0);
	string m_Body;
	static inline auto s_ArkBodyPCProperty = PreyGlobal<ArkTutorial::ArkBodyPCProperty>(0x2D290D0);
	string m_BodyPC;
	static inline auto s_ArkTypeProperty = PreyGlobal<ArkTutorial::ArkTypeProperty>(0x0);
	ArkTutorialType m_Type;
	static inline auto s_ArkAudioTriggerProperty = PreyGlobal<ArkTutorial::ArkAudioTriggerProperty>(0x2D290F0);
	string m_AudioTrigger;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkTutorial();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetCooldown(float _arg0_);
	const float& GetCooldown() const;
	void SetBody(string _arg0_);
	const string& GetBody() const;
	void SetBodyPC(string _arg0_);
	const string& GetBodyPC() const;
	void SetType(ArkTutorialType _arg0_);
	const ArkTutorialType& GetType() const;
	void SetAudioTrigger(string _arg0_);
	const string& GetAudioTrigger() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B2120);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B23A0);
};

// ArkCardTutorial
// Header:  Prey/Ark/ArkTutorial.h
class ArkCardTutorial : public ArkTutorial
{ // Size=88 (0x58)
public:
	// ArkCardTutorial::ArkTitleProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkTitleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTitleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCardTutorial::ArkTitleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCardTutorial::ArkTitleProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkCardTutorial::ArkImageProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkImageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkImageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCardTutorial::ArkImageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCardTutorial::ArkImageProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkCardTutorial::ArkDialogProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkDialogProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDialogProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCardTutorial::ArkDialogProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCardTutorial::ArkDialogProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// ArkCardTutorial::ArkDelayProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkDelayProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDelayProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCardTutorial::ArkDelayProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCardTutorial::ArkDelayProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	// ArkCardTutorial::ArkEscapeNoticeProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkEscapeNoticeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEscapeNoticeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCardTutorial::ArkEscapeNoticeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCardTutorial::ArkEscapeNoticeProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
	};

	// ArkCardTutorial::ArkAutoCollectProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkAutoCollectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAutoCollectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCardTutorial::ArkAutoCollectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCardTutorial::ArkAutoCollectProperty* const _this, ArkReflectedObject* const _pObject)>(0x107D580);
	};

	static inline auto s_ArkTitleProperty = PreyGlobal<ArkCardTutorial::ArkTitleProperty>(0x2D29110);
	string m_Title;
	static inline auto s_ArkImageProperty = PreyGlobal<ArkCardTutorial::ArkImageProperty>(0x2D29130);
	string m_Image;
	static inline auto s_ArkDialogProperty = PreyGlobal<ArkCardTutorial::ArkDialogProperty>(0x2D29150);
	uint64_t m_Dialog;
	static inline auto s_ArkDelayProperty = PreyGlobal<ArkCardTutorial::ArkDelayProperty>(0x2D29170);
	float m_Delay;
	static inline auto s_ArkEscapeNoticeProperty = PreyGlobal<ArkCardTutorial::ArkEscapeNoticeProperty>(0x2D29190);
	bool m_EscapeNotice;
	static inline auto s_ArkAutoCollectProperty = PreyGlobal<ArkCardTutorial::ArkAutoCollectProperty>(0x2D291B0);
	bool m_AutoCollect;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkCardTutorial();
	void SetTitle(string _arg0_);
	const string& GetTitle() const;
	void SetImage(string _arg0_);
	const string& GetImage() const;
	void SetDialog(uint64_t _arg0_);
	const uint64_t& GetDialog() const;
	void SetDelay(float _arg0_);
	const float& GetDelay() const;
	void SetEscapeNotice(bool _arg0_);
	const bool& GetEscapeNotice() const;
	void SetAutoCollect(bool _arg0_);
	const bool& GetAutoCollect() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B1FE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B21C0);
};

// ArkContextualTutorial
// Header:  Prey/Ark/ArkTutorial.h
class ArkContextualTutorial : public ArkCardTutorial
{ // Size=120 (0x78)
public:
	// ArkContextualTutorial::ArkActionMapProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkActionMapProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionMapProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkContextualTutorial::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkContextualTutorial::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	// ArkContextualTutorial::ArkActionIdProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkActionIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkContextualTutorial::ArkActionIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1AD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkContextualTutorial::ArkActionIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	// ArkContextualTutorial::ArkActionIdPCProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkActionIdPCProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionIdPCProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkContextualTutorial::ArkActionIdPCProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1B50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkContextualTutorial::ArkActionIdPCProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkContextualTutorial::ArkTutorialPromptProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkTutorialPromptProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialPromptProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkContextualTutorial::ArkTutorialPromptProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7850);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkContextualTutorial::ArkTutorialPromptProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkContextualTutorial::ArkActionMapProperty>(0x2D291D0);
	string m_ActionMap;
	static inline auto s_ArkActionIdProperty = PreyGlobal<ArkContextualTutorial::ArkActionIdProperty>(0x2D291F0);
	CCryName m_ActionId;
	static inline auto s_ArkActionIdPCProperty = PreyGlobal<ArkContextualTutorial::ArkActionIdPCProperty>(0x2D29210);
	CCryName m_ActionIdPC;
	static inline auto s_ArkTutorialPromptProperty = PreyGlobal<ArkContextualTutorial::ArkTutorialPromptProperty>(0x2D29230);
	bool m_TutorialPrompt;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkContextualTutorial();
	void SetActionMap(string _arg0_);
	const string& GetActionMap() const;
	void SetActionId(CCryName _arg0_);
	const CCryName& GetActionId() const;
	void SetActionIdPC(CCryName _arg0_);
	const CCryName& GetActionIdPC() const;
	void SetTutorialPrompt(bool _arg0_);
	const bool& GetTutorialPrompt() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B2030);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B2260);
};

// ArkNagTutorial
// Header:  Prey/Ark/ArkTutorial.h
class ArkNagTutorial : public ArkTutorial
{ // Size=64 (0x40)
public:
	// ArkNagTutorial::ArkDurationProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNagTutorial::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNagTutorial::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	static inline auto s_ArkDurationProperty = PreyGlobal<ArkNagTutorial::ArkDurationProperty>(0x2D29250);
	float m_Duration;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	ArkNagTutorial();
	static ArkClass* GetClass();
	void SetDuration(float _arg0_);
	const float& GetDuration() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B2090);
};

// ArkReadyRoomTutorial
// Header:  Prey/Ark/ArkTutorial.h
class ArkReadyRoomTutorial : public ArkTutorial
{ // Size=72 (0x48)
public:
	// ArkReadyRoomTutorial::ArkTitleProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkTitleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTitleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomTutorial::ArkTitleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomTutorial::ArkTitleProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkReadyRoomTutorial::ArkPositionProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkPositionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPositionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomTutorial::ArkPositionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomTutorial::ArkPositionProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	static inline auto s_ArkTitleProperty = PreyGlobal<ArkReadyRoomTutorial::ArkTitleProperty>(0x2D29270);
	string m_Title;
	static inline auto s_ArkPositionProperty = PreyGlobal<ArkReadyRoomTutorial::ArkPositionProperty>(0x2D29290);
	int m_Position;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkReadyRoomTutorial();
	void SetTitle(string _arg0_);
	const string& GetTitle() const;
	void SetPosition(int _arg0_);
	const int& GetPosition() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B20E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B2300);
};

// ArkTutorialLibrary
// Header:  Prey/Ark/ArkTutorial.h
class ArkTutorialLibrary : public ArkReflectedLibrary
{ // Size=40 (0x28)
public:
	// ArkTutorialLibrary::ArkTutorialsProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkTutorialsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkTutorialsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorialLibrary::ArkTutorialsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1BD0);
		static inline auto FIsArray = PreyFunction<bool(const ArkTutorialLibrary::ArkTutorialsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkTutorialLibrary::ArkTutorialsProperty* const _this, ArkReflectedObject* _pObject)>(0x1444080);
	};

	// ArkTutorialLibrary::ArkContextualDisplayTimeProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkContextualDisplayTimeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkContextualDisplayTimeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorialLibrary::ArkContextualDisplayTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorialLibrary::ArkContextualDisplayTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1FF0);
	};

	// ArkTutorialLibrary::ArkNagDisplayTimeProperty
	// Header:  Prey/Ark/ArkTutorial.h
	class ArkNagDisplayTimeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNagDisplayTimeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorialLibrary::ArkNagDisplayTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorialLibrary::ArkNagDisplayTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C8CB0);
	};

	static inline auto s_ArkTutorialsProperty = PreyGlobal<ArkTutorialLibrary::ArkTutorialsProperty>(0x2D292B0);
	std::vector<std::shared_ptr<ArkTutorial>> m_Tutorials;
	static inline auto s_ArkContextualDisplayTimeProperty = PreyGlobal<ArkTutorialLibrary::ArkContextualDisplayTimeProperty>(0x2D292D0);
	float m_ContextualDisplayTime;
	static inline auto s_ArkNagDisplayTimeProperty = PreyGlobal<ArkTutorialLibrary::ArkNagDisplayTimeProperty>(0x2D292F0);
	float m_NagDisplayTime;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkTutorial* FindTutorial(const uint64_t _id) const { return FFindTutorial(this, _id); }
	virtual bool Init();

#if 0
	std::vector<std::shared_ptr<ArkTutorial>>& GetTutorials();
	const std::vector<std::shared_ptr<ArkTutorial>>& GetTutorials() const;
	void SetContextualDisplayTime(float _arg0_);
	const float& GetContextualDisplayTime() const;
	void SetNagDisplayTime(float _arg0_);
	const float& GetNagDisplayTime() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B2160);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B2440);
	static inline auto FFindTutorial = PreyFunction<const ArkTutorial* (const ArkTutorialLibrary* const _this, const uint64_t _id)>(0x1432450);
	static inline auto FInit = PreyFunction<bool(ArkTutorialLibrary* const _this)>(0x10B2530);
};
#endif // !MOONCRASH
