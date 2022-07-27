// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

struct IFunctionHandler;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_arkroster.h
class CScriptBind_ArkRoster : public CScriptableBase // Id=801664A Size=96
{
public:
	CScriptBind_ArkRoster();
	int DiscoverCharacter(IFunctionHandler *_pH, const char *_pCharacterId) { return FDiscoverCharacter(this,_pH,_pCharacterId); }
	int GetCharacterName(IFunctionHandler *_pH, const char *_pCharacterId) { return FGetCharacterName(this,_pH,_pCharacterId); }
	int GetCharacterIsAlive(IFunctionHandler *_pH, const char *_pCharacterId) { return FGetCharacterIsAlive(this,_pH,_pCharacterId); }
	int GetCharacterLocated(IFunctionHandler *_pH, const char *_pCharacterId) { return FGetCharacterLocated(this,_pH,_pCharacterId); }
	int GetCharacterVitalSigns(IFunctionHandler *_pH, const char *_pCharacterId) { return FGetCharacterVitalSigns(this,_pH,_pCharacterId); }
	int GetCharacterHasTrackingChip(IFunctionHandler *_pH, const char *_pCharacterId) { return FGetCharacterHasTrackingChip(this,_pH,_pCharacterId); }
	int SetCharacterIsAlive(IFunctionHandler *_pH, const char *_pCharacterId, const bool _bIsAlive) { return FSetCharacterIsAlive(this,_pH,_pCharacterId,_bIsAlive); }
	int SetCharacterVitalSigns(IFunctionHandler *_pH, const char *_pCharacterId, const int _vitalSigns) { return FSetCharacterVitalSigns(this,_pH,_pCharacterId,_vitalSigns); }
	int UpdateTrackingChipLocation(IFunctionHandler *_pH, const char *_pCharacterId) { return FUpdateTrackingChipLocation(this,_pH,_pCharacterId); }
	
	static inline auto FDiscoverCharacter = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CE550);
	static inline auto FGetCharacterName = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CE790);
	static inline auto FGetCharacterIsAlive = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CE690);
	static inline auto FGetCharacterLocated = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CE710);
	static inline auto FGetCharacterVitalSigns = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CE920);
	static inline auto FGetCharacterHasTrackingChip = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CE610);
	static inline auto FSetCharacterIsAlive = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId, const bool _bIsAlive)>(0x15CE9B0);
	static inline auto FSetCharacterVitalSigns = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId, const int _vitalSigns)>(0x15CE9F0);
	static inline auto FUpdateTrackingChipLocation = PreyFunction<int(CScriptBind_ArkRoster *const _this, IFunctionHandler *_pH, const char *_pCharacterId)>(0x15CEA30);
};

