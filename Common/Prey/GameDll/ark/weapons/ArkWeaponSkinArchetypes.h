#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkWeaponSkinArchetypes
// Header:  _unknown/ArkWeaponSkinArchetypes.h
class ArkWeaponSkinArchetypes : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkWeaponSkinArchetypes::ArkWeaponProperty
	// Header:  _unknown/ArkWeaponSkinArchetypes.h
	class ArkWeaponProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkWeaponProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkinArchetypes::ArkWeaponProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
	};

	static inline auto s_ArkWeaponProperty = PreyGlobal<ArkWeaponSkinArchetypes::ArkWeaponProperty>(0x2D58698);
	string m_Weapon;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	ArkWeaponSkinArchetypes();
	static ArkClass* GetClass();
	void SetWeapon(string _arg0_);
	uint64_t GetWeapon() const;
	const string& GetWeaponString() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107ABF0);
};

#endif // MOONCRASH
