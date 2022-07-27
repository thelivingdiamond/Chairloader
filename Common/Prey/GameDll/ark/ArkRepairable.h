// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkrepairable.h>
#include <Prey/GameDll/ark/arkscripttable.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionInfo;
class IArkRepairableListener;
struct IEntity;
struct IGameObjectExtension;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/arkrepairable.h
class ArkRepairableLite // Id=8014336 Size=48
{
public:
	IEntity *m_pEntity;
	IArkRepairableListener &m_listener;
	bool m_bBroken;
	string m_originalDisplayName;
	string m_brokenDisplayName;
	
	ArkRepairableLite(IArkRepairableListener &_listener);
	virtual ~ArkRepairableLite();
	virtual bool SetBroken(bool _bBroken, bool _bForce);
	virtual void SetEntity(IEntity *_pEntity);
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void HandleScriptEvent(SEntityEvent &_event) { FHandleScriptEvent(this,_event); }
	virtual void LoadProperties();
	virtual void LoadPropertiesFrom(ArkSafeScriptTable _pPropTable);
	
#if 0
	bool IsBroken() const;
#endif
	
	static inline auto FBitNotArkRepairableLite = PreyFunction<void(ArkRepairableLite *const _this)>(0x12556E0);
	static inline auto FSetBroken = PreyFunction<bool(ArkRepairableLite *const _this, bool _bBroken, bool _bForce)>(0x1257000);
	static inline auto FSetEntity = PreyFunction<void(ArkRepairableLite *const _this, IEntity *_pEntity)>(0x414F30);
	static inline auto FSerialize = PreyFunction<void(ArkRepairableLite *const _this, TSerialize _ser)>(0x1256EC0);
	static inline auto FPostSerialize = PreyFunction<void(ArkRepairableLite *const _this)>(0x1256E20);
	static inline auto FHandleScriptEvent = PreyFunction<void(ArkRepairableLite *const _this, SEntityEvent &_event)>(0x1255A40);
	static inline auto FLoadProperties = PreyFunction<void(ArkRepairableLite *const _this)>(0x1255E00);
	static inline auto FLoadPropertiesFrom = PreyFunction<void(ArkRepairableLite *const _this, ArkSafeScriptTable _pPropTable)>(0x1256900);
};

// Header: FromCpp
// Prey/GameDll/ark/ArkRepairable.h
class ArkRepairable : public ArkRepairableLite, public IArkPlayerInteractionListener // Id=8014335 Size=160
{
public:
	IGameObjectExtension *m_pExtension;
	ArkTimeRemaining m_interactTimer;
	bool m_bRepairing;
	bool m_bFortified;
	float m_repairDuration;
	float m_repairIconRange;
	uint64_t m_repairItem;
	int m_repairPartsRequired;
	bool m_bRepairable;
	string m_repairVerb;
	ArkAudioTrigger m_triggerRepairStop;
	ArkAudioTrigger m_triggerRepairLoop;
	float m_fortifyDuration;
	uint64_t m_fortifyItem;
	string m_fortifyVerb;
	int m_fortifyPartsRequired;
	bool m_bFortifiable;
	ArkAudioTrigger m_triggerFortifyStop;
	ArkAudioTrigger m_triggerFortifyLoop;
	bool m_bStartsBroken;
	bool m_bStartsFortified;
	
	ArkRepairable(IArkRepairableListener &_listener, IGameObjectExtension *_pExtension);
	virtual ~ArkRepairable();
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool OnSpecialUseStopped(IEntity *const _pEntity);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	void Initialize() { FInitialize(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	virtual void LoadProperties();
	virtual void LoadPropertiesFrom(ArkSafeScriptTable _pPropTable);
	virtual void SetEntity(IEntity *_pEntity);
	virtual bool SetBroken(bool _bBroken, bool _bForce);
	void AttemptRepair() { FAttemptRepair(this); }
	float AdjustDuration(float _duration) const { return FAdjustDuration(this,_duration); }
	bool TestAndSpendItems(int _count, const uint64_t _itemArchetypeId) const { return FTestAndSpendItems(this,_count,_itemArchetypeId); }
	
#if 0
	bool IsFortified() const;
	void Fortify(bool arg0);
	float GetRepairDuration() const;
	float GetFortifyDuration() const;
#endif
	
	static inline auto FBitNotArkRepairable = PreyFunction<void(ArkRepairable *const _this)>(0x12555F0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkRepairable *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x12569F0);
	static inline auto FOnSpecialUseStopped = PreyFunction<bool(ArkRepairable *const _this, IEntity *const _pEntity)>(0x1256BC0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkRepairable const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1256C20);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkRepairable const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x1256CF0);
	static inline auto FInitialize = PreyFunction<void(ArkRepairable *const _this)>(0x1255AC0);
	static inline auto FUpdate = PreyFunction<void(ArkRepairable *const _this, float _frameTime)>(0x1257250);
	static inline auto FSerialize = PreyFunction<void(ArkRepairable *const _this, TSerialize _ser)>(0x1256E30);
	static inline auto FLoadProperties = PreyFunction<void(ArkRepairable *const _this)>(0x1255B20);
	static inline auto FLoadPropertiesFrom = PreyFunction<void(ArkRepairable *const _this, ArkSafeScriptTable _pPropTable)>(0x1255F40);
	static inline auto FSetEntity = PreyFunction<void(ArkRepairable *const _this, IEntity *_pEntity)>(0x12570A0);
	static inline auto FSetBroken = PreyFunction<bool(ArkRepairable *const _this, bool _bBroken, bool _bForce)>(0x1256F10);
	static inline auto FAttemptRepair = PreyFunction<void(ArkRepairable *const _this)>(0x12559B0);
	static inline auto FAdjustDuration = PreyFunction<float(ArkRepairable const *const _this, float _duration)>(0x12558C0);
	static inline auto FTestAndSpendItems = PreyFunction<bool(ArkRepairable const *const _this, int _count, const uint64_t _itemArchetypeId)>(0x1257130);
};

