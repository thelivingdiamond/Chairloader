// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkAbilityListener.h>
#include <Prey/GameDll/ark/player/IArkMetaTagListener.h>
#include <_unknown/IArkHealthListener.h>

struct IEntityLink;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;
struct phys_geometry;
namespace primitives
{
struct box;
} // namespace primitives

// ArkTyphonGate
// Header:  Prey/GameDll/ark/environment/ArkTyphonGate.h
class ArkTyphonGate
	: public ArkEnvironmentalObject
	, public IArkMetaTagListener
	, public IArkAbilityListener
	, public IArkHealthListener
	, public IArkConversationListener
{ // Size=968 (0x3C8)
public:
	EArkTyphonGateState m_state;
	bool m_bPowered;
	bool m_bWaitingOnDialog;
	ArkSimpleTimer m_suppressTimer;
	ArkSimpleTimer m_activationDelayTimer;
	ArkAutoResetTimer m_playerLoiterTimer;
	ArkAudioTrigger m_proximityStartTrigger;
	ArkAudioTrigger m_proximityStopTrigger;
	ArkSpeaker<ArkDialogPlayer> m_speaker;
	std::vector<unsigned int> m_validTargets;
	std::vector<unsigned int> m_invalidTargets;
	std::vector<unsigned int> m_endCaps;
	std::vector<unsigned int> m_disruptedLinks;
	std::vector<unsigned int> m_lights;
	std::vector<unsigned int> m_kiosks;
	std::unordered_map<unsigned int, ArkLooseEffect> m_proximityVfx;
	std::vector<phys_geometry*> m_geoms;
	string m_surfaceTypeName;
	string m_proximityVfxName;
	uint64_t m_playerMarkedPostEffect;
	float m_proximityRange;
	float m_proximityVfxHalfWidth;
	float m_proximityVfxHalfHeight;
	float m_playerLoiterDist;
	float m_nudgeImpulseScale;
	float m_gateDepth;
	float m_gateHeight;
	float m_gateWidth;
	bool m_bStartsPowered;

	ArkTyphonGate();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void Release();
	virtual void ProcessEvent(SEntityEvent& _event);
	void SetSuppressed() { FSetSuppressed(this); }
	void MarkTyphon() { FMarkTyphon(this); }
	void SetPowered(bool _bPowered) { FSetPowered(this, _bPowered); }
	void SetDisrupted(unsigned _capId, bool _bDisrupted) { FSetDisrupted(this, _capId, _bDisrupted); }
	virtual void OnMetaTagAdded(unsigned _entityId, const uint64_t _tag);
	virtual void OnMetaTagRemoved(unsigned _entityId, const uint64_t _tag);
	virtual void OnMetaTagsAdded(unsigned _entityId);
	virtual void OnAllDynamicMetaTagsRemoved(unsigned _entityId);
	virtual void OnBecomeAlien();
	virtual void OnDead(unsigned _entity);
	virtual void OnConversationComplete(const bool _bComplete);
	bool IsPotentialTarget(unsigned _targetId) const { return FIsPotentialTarget(this, _targetId); }
	void ClearTargets() { FClearTargets(this); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	void ReevaluateActive(bool _bForce) { FReevaluateActive(this, _bForce); }
	void CreateWall(bool _bPhysicalize) { FCreateWall(this, _bPhysicalize); }
	void EnableCollision(bool _bEnable) { FEnableCollision(this, _bEnable); }
	void SetState(EArkTyphonGateState _state, bool _bForce) { FSetState(this, _state, _bForce); }
	bool Speak(const char* _concept, bool _bStopCurrent) { return FSpeak(this, _concept, _bStopCurrent); }
	void PushEntitiesOutOfTheWay() const { FPushEntitiesOutOfTheWay(this); }
	bool AddInvalidTarget(unsigned _targetId) { return FAddInvalidTarget(this, _targetId); }
	bool RemoveInvalidTarget(unsigned _targetId) { return FRemoveInvalidTarget(this, _targetId); }
	bool AddValidTarget(unsigned _targetId) { return FAddValidTarget(this, _targetId); }
	bool RemoveValidTarget(unsigned _targetId) { return FRemoveValidTarget(this, _targetId); }
	void AddLink(IEntityLink* _pLink) { FAddLink(this, _pLink); }
	void UpdateKiosks() { FUpdateKiosks(this); }

#if 0
	float GetWidth() const;
	void AddTarget(unsigned _arg0_);
	void RemoveTarget(unsigned _arg0_);
	bool IsEnabled() const;
	primitives::box BuildWallBox() const;
#endif

	static inline auto FArkTyphonGateOv2 = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D1800);
	static inline auto FPostInit = PreyFunction<void(ArkTyphonGate* const _this, IGameObject* _pGameObject)>(0x11D4BC0);
	static inline auto FFullSerialize = PreyFunction<void(ArkTyphonGate* const _this, TSerialize _ser)>(0x11D2F60);
	static inline auto FPostSerialize = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D4C10);
	static inline auto FUpdate = PreyFunction<void(ArkTyphonGate* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x11D6430);
	static inline auto FRelease = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D5690);
	static inline auto FProcessEvent = PreyFunction<void(ArkTyphonGate* const _this, SEntityEvent& _event)>(0x11D4CB0);
	static inline auto FSetSuppressed = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D61B0);
	static inline auto FMarkTyphon = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D4160);
	static inline auto FSetPowered = PreyFunction<void(ArkTyphonGate* const _this, bool _bPowered)>(0x11D5970);
	static inline auto FSetDisrupted = PreyFunction<void(ArkTyphonGate* const _this, unsigned _capId, bool _bDisrupted)>(0x11D58B0);
	static inline auto FOnMetaTagAdded = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId, const uint64_t _tag)>(0x11D47B0);
	static inline auto FOnMetaTagRemoved = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId, const uint64_t _tag)>(0x11D4880);
	static inline auto FOnMetaTagsAdded = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId)>(0x11D4950);
	static inline auto FOnAllDynamicMetaTagsRemoved = PreyFunction<void(IArkMetaTagListener* const _this, unsigned _entityId)>(0x11D45B0);
	static inline auto FOnBecomeAlien = PreyFunction<void(IArkAbilityListener* const _this)>(0x11D4660);
	static inline auto FOnDead = PreyFunction<void(IArkHealthListener* const _this, unsigned _entity)>(0x11D4780);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x11D4730);
	static inline auto FIsPotentialTarget = PreyFunction<bool(const ArkTyphonGate* const _this, unsigned _targetId)>(0x11D33F0);
	static inline auto FClearTargets = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D2950);
	static inline auto FOnReset = PreyFunction<void(ArkTyphonGate* const _this, bool _bEnteringGameMode)>(0x11D4A00);
	static inline auto FLoadProperties = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D3510);
	static inline auto FReevaluateActive = PreyFunction<void(ArkTyphonGate* const _this, bool _bForce)>(0x11D55B0);
	static inline auto FCreateWall = PreyFunction<void(ArkTyphonGate* const _this, bool _bPhysicalize)>(0x11D2A50);
	static inline auto FEnableCollision = PreyFunction<void(ArkTyphonGate* const _this, bool _bEnable)>(0x11D2E80);
	static inline auto FSetState = PreyFunction<void(ArkTyphonGate* const _this, EArkTyphonGateState _state, bool _bForce)>(0x11D5980);
	static inline auto FSpeak = PreyFunction<bool(ArkTyphonGate* const _this, const char* _concept, bool _bStopCurrent)>(0x11D6370);
	static inline auto FPushEntitiesOutOfTheWay = PreyFunction<void(const ArkTyphonGate* const _this)>(0x11D4E90);
	static inline auto FAddInvalidTarget = PreyFunction<bool(ArkTyphonGate* const _this, unsigned _targetId)>(0x11D26A0);
	static inline auto FRemoveInvalidTarget = PreyFunction<bool(ArkTyphonGate* const _this, unsigned _targetId)>(0x11D56E0);
	static inline auto FAddValidTarget = PreyFunction<bool(ArkTyphonGate* const _this, unsigned _targetId)>(0x11D28B0);
	static inline auto FRemoveValidTarget = PreyFunction<bool(ArkTyphonGate* const _this, unsigned _targetId)>(0x11D5750);
	static inline auto FAddLink = PreyFunction<void(ArkTyphonGate* const _this, IEntityLink* _pLink)>(0x11D2710);
	static inline auto FUpdateKiosks = PreyFunction<void(ArkTyphonGate* const _this)>(0x11D6BF0);
};
#endif // MOONCRASH
