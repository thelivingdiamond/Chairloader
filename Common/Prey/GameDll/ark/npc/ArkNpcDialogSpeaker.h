// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/ArkResponseQuery.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
#include <Prey/GameDll/ark/iface/IArkFactionListener.h>
#include <_unknown/ArkAttentionLevelsChangedListener.h>

struct ArkAttentionLevelChange;
class ArkConversation;
class ArkNpcPlayer;
class ArkSafeScriptTable;
enum class EArkDisposition;
class IArkDialogPlayerExtension;
struct IEntity;

// ArkNpcDialogSpeaker
// Header:  Prey/GameDll/ark/npc/ArkNpcDialogSpeaker.h
class ArkNpcDialogSpeaker : public ArkAttentionLevelsChangedListener, public IArkFactionListener
{ // Size=656 (0x290)
public:
	ArkSpeaker<ArkDialogPlayerNPC> m_arkSpeaker;
	ArkNpcPlayer& m_arkNpcPlayer;
	uint64_t m_characterId;
	ArkSimpleTimer m_playerApproachCDNear;
	ArkSimpleTimer m_playerApproachCDMedium;
	ArkSimpleTimer m_playerApproachCDFar;
	ArkSimpleTimer m_playerLoiterTimer;
	float m_playerApproachDistanceSqrdNear;
	float m_playerApproachDistanceSqrdMedium;
	float m_playerApproachDistanceSqrdFar;
	float m_playerLoiterDistanceSqrd;
	float m_playerVisiblyNearbyDistanceSqrd;
	bool m_bIsPlayerVisiblyNearby;
	bool m_bNearDistanceEntered;
	bool m_bMediumDistanceEntered;
	bool m_bFarDistanceEntered;
	bool m_bDisabled;
	bool m_bRegistered;
	ArkNpcSpeakerEvent m_eCurrentEvent;
	ArkResponseQuery m_currentResponseQuery;
	static inline auto s_eventData = PreyGlobal<std::pair<const char*, int> [71]>(0x2D7BD50);

	ArkNpcDialogSpeaker(ArkNpcPlayer& _npc);
	~ArkNpcDialogSpeaker();
	void PostInit() { FPostInit(this); }
	void Release() { FRelease(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Reset() { FReset(this); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	void LoadOverridesFromTable(const ArkSafeScriptTable& _dialogOverrideTable) { FLoadOverridesFromTable(this, _dialogOverrideTable); }
	ArkResponseQuery BuildResponseQuery() const { alignas(ArkResponseQuery) std::byte _return_buf_[sizeof(ArkResponseQuery)]; return *FBuildResponseQuery(this, reinterpret_cast<ArkResponseQuery*>(_return_buf_)); }
	void Event(ArkNpcSpeakerEvent _event, const void* _pData) { FEvent(this, _event, _pData); }
	ArkConversation* Trigger(const uint64_t _ruleId, const int _paChannel, int _priority) { return FTrigger(this, _ruleId, _paChannel, _priority); }
	void OnDialogAnimationEvent() { FOnDialogAnimationEvent(this); }
	bool HasUseDialog() const { return FHasUseDialog(this); }
	bool IsHostileToPlayer() const { return FIsHostileToPlayer(this); }
	void OnDeath() { FOnDeath(this); }
	void StopAll() { FStopAll(this); }
	void SetPlayerExtension(IArkDialogPlayerExtension* _pExtension) { FSetPlayerExtension(this, _pExtension); }
	bool IsActive() const { return FIsActive(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	virtual void DoOnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange);
	virtual void OnEffectiveEntityToEntityDispositionChange(unsigned _arg0_, unsigned _arg1_, EArkDisposition _arg2_, EArkDisposition _arg3_);
	void UpdateListeners(bool _bRegister) { FUpdateListeners(this, _bRegister); }
	void UpdatePlayerVisibility(IEntity& _entity) { FUpdatePlayerVisibility(this, _entity); }
	static void SetupEventData() { FSetupEventData(); }

#if 0
	ArkSpeaker<ArkDialogPlayerNPC>& GetSpeaker();
	const ArkSpeaker<ArkDialogPlayerNPC>& GetSpeaker() const;
	void SetDisabled(bool _arg0_);
	void Event_Internal();
	bool CanRespond() const;
	Vec3 GetNpcStartRaycastPos();
	Vec3 GetPlayerStopRaycastPos();
#endif

	static inline auto FArkNpcDialogSpeakerOv1 = PreyFunction<void(ArkNpcDialogSpeaker* const _this, ArkNpcPlayer& _npc)>(0x16246E0);
	static inline auto FBitNotArkNpcDialogSpeaker = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1624820);
	static inline auto FPostInit = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1626100);
	static inline auto FRelease = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1626150);
	static inline auto FUpdate = PreyFunction<void(ArkNpcDialogSpeaker* const _this, const float _frameTime)>(0x1626B00);
	static inline auto FReset = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1626190);
	static inline auto FLoadScriptVariables = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x16258A0);
	static inline auto FLoadOverridesFromTable = PreyFunction<void(ArkNpcDialogSpeaker* const _this, const ArkSafeScriptTable& _dialogOverrideTable)>(0x1625730);
	static inline auto FBuildResponseQuery = PreyFunction<ArkResponseQuery*(const ArkNpcDialogSpeaker* const _this, ArkResponseQuery* _return_value_)>(0x1624870);
	static inline auto FEvent = PreyFunction<void(ArkNpcDialogSpeaker* const _this, ArkNpcSpeakerEvent _event, const void* _pData)>(0x1624CC0);
	static inline auto FTrigger = PreyFunction<ArkConversation* (ArkNpcDialogSpeaker* const _this, const uint64_t _ruleId, const int _paChannel, int _priority)>(0x1626A80);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x16260B0);
	static inline auto FHasUseDialog = PreyFunction<bool(const ArkNpcDialogSpeaker* const _this)>(0x1625630);
	static inline auto FIsHostileToPlayer = PreyFunction<bool(const ArkNpcDialogSpeaker* const _this)>(0x16256F0);
	static inline auto FOnDeath = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1626030);
	static inline auto FStopAll = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1626A60);
	static inline auto FSetPlayerExtension = PreyFunction<void(ArkNpcDialogSpeaker* const _this, IArkDialogPlayerExtension* _pExtension)>(0x1626260);
	static inline auto FIsActive = PreyFunction<bool(const ArkNpcDialogSpeaker* const _this)>(0x16256D0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcDialogSpeaker* const _this, TSerialize _ser)>(0x1626210);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcDialogSpeaker* const _this)>(0x1626140);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkNpcDialogSpeaker* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x1624BF0);
	static inline auto FUpdateListeners = PreyFunction<void(ArkNpcDialogSpeaker* const _this, bool _bRegister)>(0x1626EA0);
	static inline auto FUpdatePlayerVisibility = PreyFunction<void(ArkNpcDialogSpeaker* const _this, IEntity& _entity)>(0x1627020);
	static inline auto FSetupEventData = PreyFunction<void()>(0x1626270);
};
#endif // MOONCRASH
