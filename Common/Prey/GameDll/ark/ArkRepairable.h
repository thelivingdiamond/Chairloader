// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/ArkScriptTable.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

class ArkSafeScriptTable;
enum class EArkInteractionMode;
enum class EArkInteractionType;
class IArkRepairableListener;
struct IEntity;
struct IGameObjectExtension;
struct SEntityEvent;

// ArkRepairableLite
// Header:  Prey/GameDll/ark/ArkRepairable.h
class ArkRepairableLite
{ // Size=48 (0x30)
public:
	IEntity* m_pEntity;
	IArkRepairableListener& m_listener;
	bool m_bBroken;
	string m_originalDisplayName;
	string m_brokenDisplayName;

	ArkRepairableLite(IArkRepairableListener& _listener);
	virtual ~ArkRepairableLite();
	virtual bool SetBroken(bool _bBroken, bool _bForce);
	virtual void SetEntity(IEntity* _pEntity);
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void HandleScriptEvent(SEntityEvent& _event) { FHandleScriptEvent(this, _event); }
	virtual void LoadProperties();
	virtual void LoadPropertiesFrom(ArkSafeScriptTable _pPropTable);

#if 0
	bool IsBroken() const;
	const string& GetBrokenDisplayName() const;
#endif

	static inline auto FArkRepairableLiteOv1 = PreyFunction<void(ArkRepairableLite* const _this, IArkRepairableListener& _listener)>(0x12F9310);
	static inline auto FBitNotArkRepairableLite = PreyFunction<void(ArkRepairableLite* const _this)>(0x12F9430);
	static inline auto FSetBroken = PreyFunction<bool(ArkRepairableLite* const _this, bool _bBroken, bool _bForce)>(0x12FB180);
	static inline auto FSetEntity = PreyFunction<void(ArkRepairableLite* const _this, IEntity* _pEntity)>(0x17DB400);
	static inline auto FSerialize = PreyFunction<void(ArkRepairableLite* const _this, TSerialize _ser)>(0x12FB030);
	static inline auto FPostSerialize = PreyFunction<void(ArkRepairableLite* const _this)>(0x12FAF90);
	static inline auto FHandleScriptEvent = PreyFunction<void(ArkRepairableLite* const _this, SEntityEvent& _event)>(0x12F9960);
	static inline auto FLoadProperties = PreyFunction<void(ArkRepairableLite* const _this)>(0x12F9D20);
	static inline auto FLoadPropertiesFrom = PreyFunction<void(ArkRepairableLite* const _this, ArkSafeScriptTable _pPropTable)>(0x12FA820);
};

// ArkRepairable
// Header:  Prey/GameDll/ark/ArkRepairable.h
class ArkRepairable : public ArkRepairableLite, public IArkPlayerInteractionListener
{ // Size=160 (0xA0)
public:
	IGameObjectExtension* m_pExtension;
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

	ArkRepairable(IArkRepairableListener& _listener, IGameObjectExtension* _pExtension);
	virtual ~ArkRepairable();
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool OnSpecialUseStopped(IEntity* const _pEntity);
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	void Initialize() { FInitialize(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void LoadProperties();
	virtual void LoadPropertiesFrom(ArkSafeScriptTable _pPropTable);
	virtual void SetEntity(IEntity* _pEntity);
	virtual bool SetBroken(bool _bBroken, bool _bForce);
	bool CanRepair() const { return FCanRepair(this); }
	void AttemptRepair() { FAttemptRepair(this); }
	float AdjustDuration(float _duration) const { return FAdjustDuration(this, _duration); }
	bool TestAndSpendItems(int _count, const uint64_t _itemArchetypeId) const { return FTestAndSpendItems(this, _count, _itemArchetypeId); }

#if 0
	bool IsFortified() const;
	bool CanFortify() const;
	static int GetMinSpareParts();
	uint64_t GetRepairItem() const;
	int GetRepairItemsRequired() const;
	void Fortify(bool _arg0_);
	float GetRepairDuration() const;
	float GetFortifyDuration() const;
#endif

	static inline auto FArkRepairableOv1 = PreyFunction<void(ArkRepairable* const _this, IArkRepairableListener& _listener, IGameObjectExtension* _pExtension)>(0x12F9250);
	static inline auto FBitNotArkRepairable = PreyFunction<void(ArkRepairable* const _this)>(0x12F9340);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x12FA910);
	static inline auto FOnSpecialUseStopped = PreyFunction<bool(IArkPlayerInteractionListener* const _this, IEntity* const _pEntity)>(0x12FAAE0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x12FAB40);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x12FAC10);
	static inline auto FInitialize = PreyFunction<void(ArkRepairable* const _this)>(0x12F99E0);
	static inline auto FUpdate = PreyFunction<void(ArkRepairable* const _this, float _frameTime)>(0x12FB3C0);
	static inline auto FSerialize = PreyFunction<void(ArkRepairable* const _this, TSerialize _ser)>(0x12FAFA0);
	static inline auto FLoadProperties = PreyFunction<void(ArkRepairable* const _this)>(0x12F9A40);
	static inline auto FLoadPropertiesFrom = PreyFunction<void(ArkRepairable* const _this, ArkSafeScriptTable _pPropTable)>(0x12F9E60);
	static inline auto FSetEntity = PreyFunction<void(ArkRepairable* const _this, IEntity* _pEntity)>(0x12FB220);
	static inline auto FSetBroken = PreyFunction<bool(ArkRepairable* const _this, bool _bBroken, bool _bForce)>(0x12FB080);
	static inline auto FCanRepair = PreyFunction<bool(const ArkRepairable* const _this)>(0x12F9830);
	static inline auto FAttemptRepair = PreyFunction<void(ArkRepairable* const _this)>(0x12F9700);
	static inline auto FAdjustDuration = PreyFunction<float(const ArkRepairable* const _this, float _duration)>(0x12F9610);
	static inline auto FTestAndSpendItems = PreyFunction<bool(const ArkRepairable* const _this, int _count, const uint64_t _itemArchetypeId)>(0x12FB2B0);
};
#endif // !MOONCRASH
