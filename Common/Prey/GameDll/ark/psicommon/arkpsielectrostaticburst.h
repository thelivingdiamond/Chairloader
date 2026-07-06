// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
class ArkPsiElectrostaticBurstProperties : public ArkReflectedObject // Id=801C111 Size=144
{
public:
	class ArkBlastPropertiesProperty : public ArkProperty // Id=801C112 Size=32
	{
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1580AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty s_ArkBlastPropertiesProperty;
	ArkPsiBlastProperties m_BlastProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetBlastProperties(ArkPsiBlastProperties arg0);
	ArkPsiBlastProperties const &GetBlastProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15811D0);
};

// Header: FromCpp
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
class CArkPsiElectrostaticBurst : public CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> > // Id=801C115 Size=80
{
public:
	using BaseType = CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>;
	
	CArkPsiElectrostaticBurst(Vec3 const &_pos, CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> const *_pProperties);
	CArkPsiElectrostaticBurst &operator=(CArkPsiElectrostaticBurst *_blast) { return FoperatorEq(this,_blast); }
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(std::vector<IEntity *> _entities) const { FUpdateEffect(this,_entities); }
	
	static inline auto FoperatorEq = PreyFunction<CArkPsiElectrostaticBurst &(CArkPsiElectrostaticBurst *const _this, CArkPsiElectrostaticBurst *_blast)>(0x15811B0);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(CArkPsiElectrostaticBurst const *const _this)>(0x158AEF0);
	static inline auto FUpdateEffect = PreyFunction<void(CArkPsiElectrostaticBurst const *const _this, std::vector<IEntity *> _entities)>(0x1581230);
};

// Header: FromCpp
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
class CArkPsiFearBlast : public CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> > // Id=801C882 Size=80
{
public:
	using BaseType = CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiFearBlastProperties>;
	
	CArkPsiFearBlast(Vec3 const &_pos, CArkPsiBlastProperties<ArkPsiFearBlastProperties> const *_pProperties);
	CArkPsiFearBlast &operator=(CArkPsiFearBlast *_blast) { return FoperatorEq(this,_blast); }
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(std::vector<IEntity *> _entities) const { FUpdateEffect(this,_entities); }
	
	static inline auto FoperatorEq = PreyFunction<CArkPsiFearBlast &(CArkPsiFearBlast *const _this, CArkPsiFearBlast *_blast)>(0x15811B0);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(CArkPsiFearBlast const *const _this)>(0x10E7940);
	static inline auto FUpdateEffect = PreyFunction<void(CArkPsiFearBlast const *const _this, std::vector<IEntity *> _entities)>(0x15819A0);
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

// ArkPsiElectrostaticBurstProperties
// Header:  Prey/GameDll/ark/psicommon/ArkPsiElectrostaticBurst.h
class ArkPsiElectrostaticBurstProperties : public ArkReflectedObject
{ // Size=144 (0x90)
public:
	// ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiElectrostaticBurst.h
	class ArkBlastPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FArkBlastPropertiesPropertyOv2 = PreyFunction<void(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty* const _this)>(0x16A7E60);
		static inline auto FSetValue = PreyFunction<void(const ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16A9060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	static inline auto s_ArkBlastPropertiesProperty = PreyGlobal<ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty>(0x2D7DB40);
	ArkPsiBlastProperties m_BlastProperties;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetBlastProperties(ArkPsiBlastProperties _arg0_);
	const ArkPsiBlastProperties& GetBlastProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16A9600);
};

// CArkPsiElectrostaticBurst
// Header:  Prey/GameDll/ark/psicommon/ArkPsiElectrostaticBurst.h
class CArkPsiElectrostaticBurst : public CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >
{ // Size=80 (0x50)
public:
	using BaseType = CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>;

	CArkPsiElectrostaticBurst(const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* _pProperties);
	CArkPsiElectrostaticBurst& operator=(CArkPsiElectrostaticBurst&& _blast) { return FoperatorEq(this, _blast); }
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(const std::vector<IEntity*> _entities) const { FUpdateEffect(this, _entities); }

#if 0
	CArkPsiElectrostaticBurst();
	CArkPsiElectrostaticBurst(CArkPsiElectrostaticBurst&& _arg0_);
#endif

	static inline auto FCArkPsiElectrostaticBurstOv0 = PreyFunction<void(CArkPsiElectrostaticBurst* const _this, const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* _pProperties)>(0x16A8CE0);
	static inline auto FoperatorEq = PreyFunction<CArkPsiElectrostaticBurst& (CArkPsiElectrostaticBurst* const _this, CArkPsiElectrostaticBurst&& _blast)>(0x16A8220);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(const CArkPsiElectrostaticBurst* const _this)>(0x1CBB0B0);
	static inline auto FUpdateEffect = PreyFunction<void(const CArkPsiElectrostaticBurst* const _this, const std::vector<IEntity*> _entities)>(0x16A8240);
};
#endif // !MOONCRASH
