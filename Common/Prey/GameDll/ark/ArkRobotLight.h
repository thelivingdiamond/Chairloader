// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerRobotLightExtension.h>

class CArkLight;
struct IAttachment;
struct IEntity;
struct IEntityArchetype;

// Header: Override
// Prey/GameDll/ark/ArkRobotLight.h
struct ArkRobotLight // Id=80141D6 Size=96
{
	enum class LightMode
	{
		friendly = 0,
		hostile = 1,
		hacked = 2,
	};

	IEntity *m_pEntity;
	unsigned m_arkLightEntityId;
	ArkRobotLight::LightMode m_lightMode;
	ArkDialogPlayerRobotLightExtension m_dialogExtension;
	ArkSimpleTimer m_lightFlickerDurationTimer;
	ArkSimpleTimer m_lightFlickerToggleTimer;
	float m_flickerToggleMaxTime;
	float m_onBrightness;
	bool m_bActive;
	bool m_bGlowHidden;
	bool m_bEntityHidden;
	bool m_bIsOn;
	bool m_bScriptEnabled;
	bool m_bIsFlickering;
	bool m_bFlickeringForceOff;
	bool m_bRemoved;
	
	ArkRobotLight();
	void Initialize(IEntity &_entity) { FInitialize(this,_entity); }
	void OnStartGame() { FOnStartGame(this); }
	void Deinitialize() { FDeinitialize(this); }
	void RemoveLight() { FRemoveLight(this); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Activate(bool _bActivate) { FActivate(this,_bActivate); }
	void HideGlow(bool _bHideGlow) { FHideGlow(this,_bHideGlow); }
	void HideEntity(bool _bHideEntity) { FHideEntity(this,_bHideEntity); }
	void ScriptEnable(bool _bEnable) { FScriptEnable(this,_bEnable); }
	void StartFlicker(float _flickerDuration) { FStartFlicker(this,_flickerDuration); }
	void StopFlicker() { FStopFlicker(this); }
	void SetHacked() { FSetHacked(this); }
	void UpdateOnBrightness(const float _brightness) { FUpdateOnBrightness(this,_brightness); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void TryChangeLightArchetype() { FTryChangeLightArchetype(this); }
	void TurnOn() { FTurnOn(this); }
	void TurnOff() { FTurnOff(this); }
	void TryChangeLightState() { FTryChangeLightState(this); }
	bool SpawnLight() { return FSpawnLight(this); }
	IAttachment *GetLightAttachment() const { return FGetLightAttachment(this); }
	CArkLight *GetArkLight() const { return FGetArkLight(this); }
	IEntityArchetype *GetDesiredLightArchetype() const { return FGetDesiredLightArchetype(this); }
	
#if 0
	bool IsFlickering() const;
	bool IsActive() const;
	bool IsGlowHidden() const;
	bool IsEntityHidden() const;
	ArkDialogPlayerRobotLightExtension &GetDialogExtension();
	void SetBrightness(float arg0);
	bool ShouldTurnOn() const;
	bool ShouldTurnOff() const;
	void ForceRefresh();
	ColorF const &GetLightColor(bool arg0) const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkRobotLight *const _this, IEntity &_entity)>(0x10BE320);
	static inline auto FOnStartGame = PreyFunction<void(ArkRobotLight *const _this)>(0x13462B0);
	static inline auto FDeinitialize = PreyFunction<void(ArkRobotLight *const _this)>(0x1345FA0);
	static inline auto FRemoveLight = PreyFunction<void(ArkRobotLight *const _this)>(0x1345FA0);
	static inline auto FReset = PreyFunction<void(ArkRobotLight *const _this)>(0x13463D0);
	static inline auto FUpdate = PreyFunction<void(ArkRobotLight *const _this, float _frameTime)>(0x1346C30);
	static inline auto FActivate = PreyFunction<void(ArkRobotLight *const _this, bool _bActivate)>(0x1345F90);
	static inline auto FHideGlow = PreyFunction<void(ArkRobotLight *const _this, bool _bHideGlow)>(0x13462A0);
	static inline auto FHideEntity = PreyFunction<void(ArkRobotLight *const _this, bool _bHideEntity)>(0x1346250);
	static inline auto FScriptEnable = PreyFunction<void(ArkRobotLight *const _this, bool _bEnable)>(0x1346610);
	static inline auto FStartFlicker = PreyFunction<void(ArkRobotLight *const _this, float _flickerDuration)>(0x1346A20);
	static inline auto FStopFlicker = PreyFunction<void(ArkRobotLight *const _this)>(0x1346A50);
	static inline auto FSetHacked = PreyFunction<void(ArkRobotLight *const _this)>(0x1346810);
	static inline auto FUpdateOnBrightness = PreyFunction<void(ArkRobotLight *const _this, const float _brightness)>(0x1346D30);
	static inline auto FSerialize = PreyFunction<void(ArkRobotLight *const _this, TSerialize _ser)>(0x1346620);
	static inline auto FPostSerialize = PreyFunction<void(ArkRobotLight *const _this)>(0x1346320);
	static inline auto FTryChangeLightArchetype = PreyFunction<void(ArkRobotLight *const _this)>(0x1346A60);
	static inline auto FTurnOn = PreyFunction<void(ArkRobotLight *const _this)>(0x1346BB0);
	static inline auto FTurnOff = PreyFunction<void(ArkRobotLight *const _this)>(0x1346B30);
	static inline auto FTryChangeLightState = PreyFunction<void(ArkRobotLight *const _this)>(0x1346AC0);
	static inline auto FSpawnLight = PreyFunction<bool(ArkRobotLight *const _this)>(0x1346830);
	static inline auto FGetLightAttachment = PreyFunction<IAttachment *(ArkRobotLight const *const _this)>(0x1346140);
	static inline auto FGetArkLight = PreyFunction<CArkLight *(ArkRobotLight const *const _this)>(0x1346000);
	static inline auto FGetDesiredLightArchetype = PreyFunction<IEntityArchetype *(ArkRobotLight const *const _this)>(0x13460D0);
};

