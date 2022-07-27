// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/GameDll/ark/ScriptHandle.h>

struct IEntity;
struct IFunctionHandler;

// Header: FromCpp
// Prey/GameDll/ark/player/scriptbind_arkplayer.h
class CScriptBind_ArkPlayer : public CScriptableBase // Id=801666E Size=96
{
public:
	CScriptBind_ArkPlayer();
	void AttachTo(IEntity const &_entity) { FAttachTo(this,_entity); }
	int IsMaxHealth(IFunctionHandler *_pH) { return FIsMaxHealth(this,_pH); }
	int IsMaxPsi(IFunctionHandler *_pH) { return FIsMaxPsi(this,_pH); }
	int IsMaxOxygen(IFunctionHandler *_pH) { return FIsMaxOxygen(this,_pH); }
	int GetPsiPoints(IFunctionHandler *_pH) { return FGetPsiPoints(this,_pH); }
	int IsMimickingObject(IFunctionHandler *_pH) { return FIsMimickingObject(this,_pH); }
	int SetPsiPoints(IFunctionHandler *_pH, float _value) { return FSetPsiPoints(this,_pH,_value); }
	int UnlockPsiScanning(IFunctionHandler *_pH, bool _bValue) { return FUnlockPsiScanning(this,_pH,_bValue); }
	int ValidateKeyCode(IFunctionHandler *const _pH, const char *_keycodeID, const char *_input) { return FValidateKeyCode(this,_pH,_keycodeID,_input); }
	int HasAbility(IFunctionHandler *const _pH, const char *_abilityID) { return FHasAbility(this,_pH,_abilityID); }
	int GiveNote(IFunctionHandler *const _pH, const char *_noteID) { return FGiveNote(this,_pH,_noteID); }
	int GiveAudioLog(IFunctionHandler *const _pH, const char *_audioLogID, bool _bAutoplay) { return FGiveAudioLog(this,_pH,_audioLogID,_bAutoplay); }
	int GetLocationName(IFunctionHandler *const _pH, const char *_locationID) { return FGetLocationName(this,_pH,_locationID); }
	int SetViewAngles(IFunctionHandler *_pH, Ang3 _angles) { return FSetViewAngles(this,_pH,_angles); }
	int HasKeyCard(IFunctionHandler *_pH, const char *_keycardID) { return FHasKeyCard(this,_pH,_keycardID); }
	int GiveKeyCard(IFunctionHandler *_pH, const char *_keycardID) { return FGiveKeyCard(this,_pH,_keycardID); }
	int HasPassword(IFunctionHandler *_pH, const char *_characterID) { return FHasPassword(this,_pH,_characterID); }
	int GetPasswordLength(IFunctionHandler *_pH, const char *_characterID) { return FGetPasswordLength(this,_pH,_characterID); }
	int GiveDownload(IFunctionHandler *_pH, const char *_downloadID) { return FGiveDownload(this,_pH,_downloadID); }
	int GiveEmail(IFunctionHandler *_pH, const char *_emailID) { return FGiveEmail(this,_pH,_emailID); }
	int EquipWeapon(IFunctionHandler *_pH, ScriptHandle _weaponID) { return FEquipWeapon(this,_pH,_weaponID); }
	int UnequipWeapon(IFunctionHandler *_pH) { return FUnequipWeapon(this,_pH); }
	int AddStatModifier(IFunctionHandler *_pH, const char *_statName, float _modifier) { return FAddStatModifier(this,_pH,_statName,_modifier); }
	int RemoveStatModifier(IFunctionHandler *_pH, unsigned _modId) { return FRemoveStatModifier(this,_pH,_modId); }
	int ApplyStatModifierPackage(IFunctionHandler *_pH, const char *_packageId) { return FApplyStatModifierPackage(this,_pH,_packageId); }
	int RemoveStatModifierPackage(IFunctionHandler *_pH, unsigned _packageId) { return FRemoveStatModifierPackage(this,_pH,_packageId); }
	int QueryStat(IFunctionHandler *_pH, const char *_statName) { return FQueryStat(this,_pH,_statName); }
	int GiveFabricationPlan(IFunctionHandler *_pH, const char *_pId, int _count, bool _bUnlimited) { return FGiveFabricationPlan(this,_pH,_pId,_count,_bUnlimited); }
	int RefillOxygen(IFunctionHandler *_pH) { return FRefillOxygen(this,_pH); }
	int GiveOxygen(IFunctionHandler *_pH, float _oxygen) { return FGiveOxygen(this,_pH,_oxygen); }
	int ExitWorldUIExamination(IFunctionHandler *_pH, bool _bForced) { return FExitWorldUIExamination(this,_pH,_bForced); }
	int IsTraumaActive(IFunctionHandler *_pH, const char *_traumaId) { return FIsTraumaActive(this,_pH,_traumaId); }
	int IsAnyTraumaActive(IFunctionHandler *_pH) { return FIsAnyTraumaActive(this,_pH); }
	int CanHealTrauma(IFunctionHandler *_pH, const char *_traumaId) { return FCanHealTrauma(this,_pH,_traumaId); }
	int PlayFragment(IFunctionHandler *_pH, const char *_fragmentName) { return FPlayFragment(this,_pH,_fragmentName); }
	int IsExternalInventoryOpen(IFunctionHandler *_pH) { return FIsExternalInventoryOpen(this,_pH); }
	int Spawn(IFunctionHandler *_pH, Vec3 _pos, Ang3 _angles) { return FSpawn(this,_pH,_pos,_angles); }
	
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkPlayer *const _this, IEntity const &_entity)>(0x15BA6A0);
	static inline auto FIsMaxHealth = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BB840);
	static inline auto FIsMaxPsi = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BB9B0);
	static inline auto FIsMaxOxygen = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BB900);
	static inline auto FGetPsiPoints = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BAF80);
	static inline auto FIsMimickingObject = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BBA70);
	static inline auto FSetPsiPoints = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, float _value)>(0x15BBE40);
	static inline auto FUnlockPsiScanning = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, bool _bValue)>(0x15BC210);
	static inline auto FValidateKeyCode = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *const _pH, const char *_keycodeID, const char *_input)>(0x15BC260);
	static inline auto FHasAbility = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *const _pH, const char *_abilityID)>(0x15BB3E0);
	static inline auto FGiveNote = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *const _pH, const char *_noteID)>(0x15BB300);
	static inline auto FGiveAudioLog = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *const _pH, const char *_audioLogID, bool _bAutoplay)>(0x15BB010);
	static inline auto FGetLocationName = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *const _pH, const char *_locationID)>(0x15BAD00);
	static inline auto FSetViewAngles = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, Ang3 _angles)>(0x15BBE90);
	static inline auto FHasKeyCard = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_keycardID)>(0x15BB4D0);
	static inline auto FGiveKeyCard = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_keycardID)>(0x15BB270);
	static inline auto FHasPassword = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_characterID)>(0x15BB5C0);
	static inline auto FGetPasswordLength = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_characterID)>(0x15BADF0);
	static inline auto FGiveDownload = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_downloadID)>(0x15BB0B0);
	static inline auto FGiveEmail = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_emailID)>(0x15BB140);
	static inline auto FEquipWeapon = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, ScriptHandle _weaponID)>(0x15BAC70);
	static inline auto FUnequipWeapon = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BC1E0);
	static inline auto FAddStatModifier = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_statName, float _modifier)>(0x15BA3C0);
	static inline auto FRemoveStatModifier = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, unsigned _modId)>(0x15BBDC0);
	static inline auto FApplyStatModifierPackage = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_packageId)>(0x15BA5B0);
	static inline auto FRemoveStatModifierPackage = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, unsigned _packageId)>(0x15BBE00);
	static inline auto FQueryStat = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_statName)>(0x15BBC70);
	static inline auto FGiveFabricationPlan = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_pId, int _count, bool _bUnlimited)>(0x15BB1D0);
	static inline auto FRefillOxygen = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BBD80);
	static inline auto FGiveOxygen = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, float _oxygen)>(0x15BB390);
	static inline auto FExitWorldUIExamination = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, bool _bForced)>(0x15BACB0);
	static inline auto FIsTraumaActive = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_traumaId)>(0x15BBB10);
	static inline auto FIsAnyTraumaActive = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BB6B0);
	static inline auto FCanHealTrauma = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_traumaId)>(0x15BA800);
	static inline auto FPlayFragment = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, const char *_fragmentName)>(0x15BBC00);
	static inline auto FIsExternalInventoryOpen = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH)>(0x15BB7B0);
	static inline auto FSpawn = PreyFunction<int(CScriptBind_ArkPlayer *const _this, IFunctionHandler *_pH, Vec3 _pos, Ang3 _angles)>(0x15BC010);
};

