// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/CArkGameObjectExtension.h>

struct IEntity;
struct IEntityLink;
struct IGameObject;
struct SEntityEvent;

// ArkSurfaceHazardLightManager
// Header:  Prey/GameDll/ark/environment/ArkSurfaceHazardLightManager.h
class ArkSurfaceHazardLightManager : public CArkGameObjectExtension<ArkSurfaceHazardLightManager>, public IEntityEventListener
{ // Size=192 (0xC0)
public:
	std::vector<unsigned int> m_lights;
	std::vector<unsigned int> m_surfaceHazards;
	std::vector<unsigned int> m_particles;
	std::vector<unsigned int> m_fogVolumes;
	float m_maxBrightness;
	float m_minBrightness;
	float m_maxStrength;
	float m_minStrength;
	float m_maxFogDensity;
	float m_fogFadeTime;

	virtual void PostInit(IGameObject* _pGameObject);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void LoadProperties() { FLoadProperties(this); }
	void AddLink(IEntityLink* _pLink, bool _bTriggerHazardStateChange) { FAddLink(this, _pLink, _bTriggerHazardStateChange); }
	void ClearLinks() { FClearLinks(this); }
	void OnHazardStateChange() { FOnHazardStateChange(this); }

#if 0
	ArkSurfaceHazardLightManager();
#endif

	static inline auto FPostInit = PreyFunction<void(ArkSurfaceHazardLightManager* const _this, IGameObject* _pGameObject)>(0x11D0D70);
	static inline auto FProcessEvent = PreyFunction<void(ArkSurfaceHazardLightManager* const _this, SEntityEvent& _event)>(0x11D0D90);
	static inline auto FRelease = PreyFunction<void(ArkSurfaceHazardLightManager* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkSurfaceHazardLightManager* const _this, TSerialize _ser)>(0x11D0220);
	static inline auto FPostSerialize = PreyFunction<void(ArkSurfaceHazardLightManager* const _this)>(0x11D0D80);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x11D0820);
	static inline auto FLoadProperties = PreyFunction<void(ArkSurfaceHazardLightManager* const _this)>(0x11D0360);
	static inline auto FAddLink = PreyFunction<void(ArkSurfaceHazardLightManager* const _this, IEntityLink* _pLink, bool _bTriggerHazardStateChange)>(0x11CFF20);
	static inline auto FClearLinks = PreyFunction<void(ArkSurfaceHazardLightManager* const _this)>(0x11D0160);
	static inline auto FOnHazardStateChange = PreyFunction<void(ArkSurfaceHazardLightManager* const _this)>(0x11D0830);
};
#endif // MOONCRASH
