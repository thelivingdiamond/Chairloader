// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class CArkWeapon;

// ArkWeaponSkinComponent
// Header:  Prey/GameDll/ark/player/ArkWeaponSkinComponent.h
class ArkWeaponSkinComponent
{ // Size=96 (0x60)
public:
	using TGroupSkins = std::unordered_map<uint64_t, uint64_t>;
	using TWeaponList = std::vector<CArkWeapon*>;

	std::unordered_map<uint64_t, uint64_t> m_groupSkins;
	std::vector<CArkWeapon*> m_weapons;

	ArkWeaponSkinComponent();
	virtual ~ArkWeaponSkinComponent();
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Reset() { FReset(this); }
	void SetGroupWeaponSkin(uint64_t _group, uint64_t _skinId) { FSetGroupWeaponSkin(this, _group, _skinId); }
	uint64_t GetCurrentWeaponSkin(const CArkWeapon& _weapon) const { return FGetCurrentWeaponSkin(this, _weapon); }
	const char* GetWeaponSkinMaterial(uint64_t _archetypeId, uint64_t _entitySkinId) const { return FGetWeaponSkinMaterial(this, _archetypeId, _entitySkinId); }
	void RegisterWeapon(CArkWeapon* _pWeapon) { FRegisterWeapon(this, _pWeapon); }
	void UnregisterWeapon(CArkWeapon* _pWeapon) { FUnregisterWeapon(this, _pWeapon); }

#if 0
	uint64_t GetGroupWeaponSkin(uint64_t _arg0_) const;
	uint64_t GetArchetypeWeaponSkin(uint64_t _arg0_) const;
#endif

	static inline auto FArkWeaponSkinComponentOv1 = PreyFunction<void(ArkWeaponSkinComponent* const _this)>(0x13A1460);
	static inline auto FBitNotArkWeaponSkinComponent = PreyFunction<void(ArkWeaponSkinComponent* const _this)>(0x13A14F0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkWeaponSkinComponent* const _this)>(0x13A16C0);
	static inline auto FSerialize = PreyFunction<void(ArkWeaponSkinComponent* const _this, TSerialize _ser)>(0x13A1910);
	static inline auto FReset = PreyFunction<void(ArkWeaponSkinComponent* const _this)>(0x13A18B0);
	static inline auto FSetGroupWeaponSkin = PreyFunction<void(ArkWeaponSkinComponent* const _this, uint64_t _group, uint64_t _skinId)>(0x13A1930);
	static inline auto FGetCurrentWeaponSkin = PreyFunction<uint64_t(const ArkWeaponSkinComponent* const _this, const CArkWeapon& _weapon)>(0x13A1570);
	static inline auto FGetWeaponSkinMaterial = PreyFunction<const char* (const ArkWeaponSkinComponent* const _this, uint64_t _archetypeId, uint64_t _entitySkinId)>(0x13A1600);
	static inline auto FRegisterWeapon = PreyFunction<void(ArkWeaponSkinComponent* const _this, CArkWeapon* _pWeapon)>(0x13A1890);
	static inline auto FUnregisterWeapon = PreyFunction<void(ArkWeaponSkinComponent* const _this, CArkWeapon* _pWeapon)>(0x1210D90);
};
#endif // MOONCRASH
