// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkCharacterManager.h
class ArkCharacterManager // Id=80150A5 Size=64
{
public:
	std::unordered_map<unsigned __int64,string> m_alternateNames;
	
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	const char *GetCharacterName(uint64_t _id) const { return FGetCharacterName(this,_id); }
	void SetAlternateName(const uint64_t _id, const char *_altName) { FSetAlternateName(this,_id,_altName); }
	const char *GetAlternateName(const uint64_t _id) const { return FGetAlternateName(this,_id); }
	
	static inline auto FReset = PreyFunction<void(ArkCharacterManager *const _this, bool _bEnteringGameMode)>(0x11521E0);
	static inline auto FSerialize = PreyFunction<void(ArkCharacterManager *const _this, TSerialize ser)>(0x11521F0);
	static inline auto FGetCharacterName = PreyFunction<const char *(ArkCharacterManager const *const _this, uint64_t _id)>(0x1152070);
	static inline auto FSetAlternateName = PreyFunction<void(ArkCharacterManager *const _this, const uint64_t _id, const char *_altName)>(0x1152210);
	static inline auto FGetAlternateName = PreyFunction<const char *(ArkCharacterManager const *const _this, const uint64_t _id)>(0x1152030);
};

