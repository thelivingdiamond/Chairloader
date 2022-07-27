// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDataComponentBase.h>
#include <Prey/GameDll/ark/player/pda/arkrostercomponent.h>

class CArkFlowNodeCharacterPasswordAcquired;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkRosterComponent.h
class ArkRosterComponent : public ArkDataComponentBase // Id=8016FB0 Size=104
{
public:
	std::vector<CArkCharacterStatus> m_characterStatus;
	std::vector<unsigned __int64> m_passwords;
	std::vector<CArkFlowNodeCharacterPasswordAcquired *> m_flowNodeListeners;
	
	static void FormatStringWithPassword(wstring &_input, const uint64_t _id) { FFormatStringWithPassword(_input,_id); }
	void GivePassword(uint64_t _characterId, bool _bShowHUDNotification) { FGivePassword(this,_characterId,_bShowHUDNotification); }
	bool HasPassword(const uint64_t _id) const { return FHasPassword(this,_id); }
	void Reset() { FReset(this); }
	void ResetCollected() { FResetCollected(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	void KillCharacter(const uint64_t _id) { FKillCharacter(this,_id); }
	void SetCharacterWasDiscovered(const uint64_t _characterId) { FSetCharacterWasDiscovered(this,_characterId); }
	const char *GetCharacterName(const uint64_t _characterId) const { return FGetCharacterName(this,_characterId); }
	void AddFlowNodeListener(CArkFlowNodeCharacterPasswordAcquired *_pListener) { FAddFlowNodeListener(this,_pListener); }
	void RemoveFlowNodeListener(CArkFlowNodeCharacterPasswordAcquired *_pListener) { FRemoveFlowNodeListener(this,_pListener); }
	IEntity const *GetEntityForCharacter(const uint64_t _characterId) const { return FGetEntityForCharacter(this,_characterId); }
	CArkCharacterStatus *GetCharacterStatus(const uint64_t _id) { return FGetCharacterStatusOv1(this,_id); }
	CArkCharacterStatus const *GetCharacterStatus(const uint64_t _id) const { return FGetCharacterStatusOv0(this,_id); }
	bool IsPlayerCharacter(const uint64_t _characterId) const { return FIsPlayerCharacter(this,_characterId); }
	
#if 0
	void CollectAllPasswords();
	std::vector<unsigned __int64> const &GetPasswords() const;
#endif
	
	static inline auto FFormatStringWithPassword = PreyFunction<void(wstring &_input, const uint64_t _id)>(0x15B8620);
	static inline auto FGivePassword = PreyFunction<void(ArkRosterComponent *const _this, uint64_t _characterId, bool _bShowHUDNotification)>(0x15B8B80);
	static inline auto FHasPassword = PreyFunction<bool(ArkRosterComponent const *const _this, const uint64_t _id)>(0x15B8D90);
	static inline auto FReset = PreyFunction<void(ArkRosterComponent *const _this)>(0x15B8F10);
	static inline auto FResetCollected = PreyFunction<void(ArkRosterComponent *const _this)>(0x15B90A0);
	static inline auto FSerialize = PreyFunction<void(ArkRosterComponent *const _this, TSerialize ser)>(0x15B90C0);
	static inline auto FKillCharacter = PreyFunction<void(ArkRosterComponent *const _this, const uint64_t _id)>(0x15B8DE0);
	static inline auto FSetCharacterWasDiscovered = PreyFunction<void(ArkRosterComponent *const _this, const uint64_t _characterId)>(0x15B92A0);
	static inline auto FGetCharacterName = PreyFunction<const char *(ArkRosterComponent const *const _this, const uint64_t _characterId)>(0x15B87E0);
	static inline auto FAddFlowNodeListener = PreyFunction<void(ArkRosterComponent *const _this, CArkFlowNodeCharacterPasswordAcquired *_pListener)>(0x15B85D0);
	static inline auto FRemoveFlowNodeListener = PreyFunction<void(ArkRosterComponent *const _this, CArkFlowNodeCharacterPasswordAcquired *_pListener)>(0x15B8EC0);
	static inline auto FGetEntityForCharacter = PreyFunction<IEntity const *(ArkRosterComponent const *const _this, const uint64_t _characterId)>(0x15B8870);
	static inline auto FGetCharacterStatusOv1 = PreyFunction<CArkCharacterStatus *(ArkRosterComponent *const _this, const uint64_t _id)>(0x15B8840);
	static inline auto FGetCharacterStatusOv0 = PreyFunction<CArkCharacterStatus const *(ArkRosterComponent const *const _this, const uint64_t _id)>(0x15B8840);
	static inline auto FIsPlayerCharacter = PreyFunction<bool(ArkRosterComponent const *const _this, const uint64_t _characterId)>(0x15B8DC0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/pda/arkrostercomponent.h
class CArkCharacterStatus // Id=8016FB2 Size=24
{
public:
	uint64_t m_id;
	uint64_t m_location;
	EArkVitalSign m_vitalSign;
	bool m_bIsAlive;
	bool m_bWasDiscovered;
	bool m_bHasTrackingChip;
	
	void NotifyListeners() { FNotifyListeners(this); }
	
#if 0
	void Serialize(TSerialize arg0);
	uint64_t GetID() const;
	uint64_t GetLocation() const;
	bool GetIsAlive() const;
	bool GetWasDiscovered() const;
	bool GetHasTrackingChip() const;
	EArkVitalSign GetVitalSign() const;
	void SetLocation(const uint64_t arg0);
	void SetIsAlive(const bool arg0);
	void SetVitalSign(EArkVitalSign arg0);
	void SetWasDiscovered(const bool arg0);
	void SetHasTrackingChip(const bool arg0);
	bool operator==(const uint64_t arg0) const;
#endif
	
	static inline auto FNotifyListeners = PreyFunction<void(CArkCharacterStatus *const _this)>(0x15B8E40);
};

