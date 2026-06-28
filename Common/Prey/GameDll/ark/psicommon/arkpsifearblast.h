// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsifearblast.h
class ArkPsiFearBlastProperties : public ArkReflectedObject // Id=801C87F Size=144
{
public:
	class ArkBlastPropertiesProperty : public ArkProperty // Id=801C880 Size=32
	{
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1581620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiFearBlastProperties::ArkBlastPropertiesProperty s_ArkBlastPropertiesProperty;
	ArkPsiBlastProperties m_BlastProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetBlastProperties(ArkPsiBlastProperties arg0);
	ArkPsiBlastProperties const &GetBlastProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15811D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>
#include <_unknown/CArkPsiBlastProperties.h>

class ArkClass;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiFearBlastProperties
// Header:  Prey/GameDll/ark/psicommon/ArkPsiFearBlast.h
class ArkPsiFearBlastProperties : public ArkReflectedObject
{ // Size=144 (0x90)
public:
	// ArkPsiFearBlastProperties::ArkBlastPropertiesProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFearBlast.h
	class ArkBlastPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FArkBlastPropertiesPropertyOv2 = PreyFunction<void(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty* const _this)>(0x16A89A0);
		static inline auto FSetValue = PreyFunction<void(const ArkPsiFearBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16A8630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFearBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	static inline auto s_ArkBlastPropertiesProperty = PreyGlobal<ArkPsiFearBlastProperties::ArkBlastPropertiesProperty>(0x2D7DBF0);
	ArkPsiBlastProperties m_BlastProperties;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetBlastProperties(ArkPsiBlastProperties _arg0_);
	const ArkPsiBlastProperties& GetBlastProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16A9600);
};

// CArkPsiFearBlast
// Header:  Prey/GameDll/ark/psicommon/ArkPsiFearBlast.h
class CArkPsiFearBlast : public CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >
{ // Size=80 (0x50)
public:
	using BaseType = CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiFearBlastProperties>;

	CArkPsiFearBlast(const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* _pProperties);
	CArkPsiFearBlast& operator=(CArkPsiFearBlast&& _blast) { return FoperatorEq(this, _blast); }
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(const std::vector<IEntity*> _entities) const { FUpdateEffect(this, _entities); }

#if 0
	CArkPsiFearBlast();
	CArkPsiFearBlast(CArkPsiFearBlast&& _arg0_);
#endif

	static inline auto FCArkPsiFearBlastOv1 = PreyFunction<void(CArkPsiFearBlast* const _this, const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* _pProperties)>(0x16A8CE0);
	static inline auto FoperatorEq = PreyFunction<CArkPsiFearBlast& (CArkPsiFearBlast* const _this, CArkPsiFearBlast&& _blast)>(0x16A8220);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(const CArkPsiFearBlast* const _this)>(0x206090);
	static inline auto FUpdateEffect = PreyFunction<void(const CArkPsiFearBlast* const _this, const std::vector<IEntity*> _entities)>(0x16A8D00);
};
#endif // !MOONCRASH
