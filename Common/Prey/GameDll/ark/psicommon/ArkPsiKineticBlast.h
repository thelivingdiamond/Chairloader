// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

class ArkClass;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiKineticBlastProperties
// Header:  Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h
class ArkPsiKineticBlastProperties : public ArkReflectedObject
{ // Size=144 (0x90)
public:
	// ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h
	class ArkBlastPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FArkBlastPropertiesPropertyOv2 = PreyFunction<void(ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty* const _this)>(0x1581D10);
		static inline auto FSetValue = PreyFunction<void(const ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1580AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static inline auto s_ArkBlastPropertiesProperty = PreyGlobal<ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty>(0x2C03390);
	ArkPsiBlastProperties m_BlastProperties;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetBlastProperties(ArkPsiBlastProperties _arg0_);
	const ArkPsiBlastProperties& GetBlastProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15811D0);
};

// CArkPsiKineticBlast
// Header:  Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h
class CArkPsiKineticBlast : public CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >
{ // Size=80 (0x50)
public:
	using BaseType = CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiKineticBlastProperties>;

	CArkPsiKineticBlast(const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>* _pProperties);
	//CArkPsiKineticBlast& operator=(CArkPsiKineticBlast&& _blast) { return FoperatorEq(this, _blast); }
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(const std::vector<IEntity*> _entities) const { FUpdateEffect(this, _entities); }

#if 0
	CArkPsiKineticBlast();
	CArkPsiKineticBlast(CArkPsiKineticBlast&& _arg0_);
#endif

	static inline auto FCArkPsiKineticBlastOv0 = PreyFunction<void(CArkPsiKineticBlast* const _this, const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>* _pProperties)>(0x1581190);
	static inline auto FoperatorEq = PreyFunction<CArkPsiKineticBlast& (CArkPsiKineticBlast* const _this, CArkPsiKineticBlast&& _blast)>(0x15811B0);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(const CArkPsiKineticBlast* const _this)>(0xC36440);
	static inline auto FUpdateEffect = PreyFunction<void(const CArkPsiKineticBlast* const _this, const std::vector<IEntity*> _entities)>(0x15820D0);
};

