#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkBountyWeapon
// Header:  _unknown/ArkBountyWeapon.h
class ArkBountyWeapon : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkBountyWeapon::ArkWeaponProperty
	// Header:  _unknown/ArkBountyWeapon.h
	class ArkWeaponProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkWeaponProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyWeapon::ArkWeaponProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
	};

	static inline auto s_ArkWeaponProperty = PreyGlobal<ArkBountyWeapon::ArkWeaponProperty>(0x2D21820);
	string m_Weapon;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	ArkBountyWeapon();
	static ArkClass* GetClass();
	void SetWeapon(string _arg0_);
	uint64_t GetWeapon() const;
	const string& GetWeaponString() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107ABF0);
};

#endif // MOONCRASH
