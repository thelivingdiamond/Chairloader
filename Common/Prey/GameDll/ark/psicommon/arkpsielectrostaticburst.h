// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/psicommon/arkpsifearblast.h>
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
#ifdef MOONCRASH
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
class ArkPsiElectrostaticBurstProperties;
class CArkPsiElectrostaticBurst;
class CArkPsiFearBlast;
#endif
class ArkPsiElectrostaticBurstProperties : public ArkReflectedObject // Id=801C111 Size=144
{
public:
	class ArkBlastPropertiesProperty : public ArkProperty // Id=801C112 Size=32
	{
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1580AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FArkBlastPropertiesPropertyOv2 = PreyFunction<void(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty* const _this)>(0x16A7E60);
		static inline auto FSetValue = PreyFunction<void(const ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16A9060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty s_ArkBlastPropertiesProperty;
#else
	static inline auto s_ArkBlastPropertiesProperty = PreyGlobal<ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty>(0x2D7DB40);
#endif
	ArkPsiBlastProperties m_BlastProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetBlastProperties(ArkPsiBlastProperties arg0);
	ArkPsiBlastProperties const &GetBlastProperties() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15811D0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16A9600);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
class CArkPsiElectrostaticBurst : public CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> > // Id=801C115 Size=80
{
public:
	using BaseType = CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>;
	
	CArkPsiElectrostaticBurst(Vec3 const &_pos, CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> const *_pProperties);
#ifndef MOONCRASH
	CArkPsiElectrostaticBurst &operator=(CArkPsiElectrostaticBurst *_blast) { return FoperatorEq(this,_blast); }
#else
	CArkPsiElectrostaticBurst& operator=(CArkPsiElectrostaticBurst&& _blast) { return FoperatorEq(this, std::move(_blast)); }
#endif
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(std::vector<IEntity *> _entities) const { FUpdateEffect(this,_entities); }
	
#ifndef MOONCRASH
	static inline auto FoperatorEq = PreyFunction<CArkPsiElectrostaticBurst &(CArkPsiElectrostaticBurst *const _this, CArkPsiElectrostaticBurst *_blast)>(0x15811B0);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(CArkPsiElectrostaticBurst const *const _this)>(0x158AEF0);
	static inline auto FUpdateEffect = PreyFunction<void(CArkPsiElectrostaticBurst const *const _this, std::vector<IEntity *> _entities)>(0x1581230);
#else
	static inline auto FCArkPsiElectrostaticBurstOv0 = PreyFunction<void(CArkPsiElectrostaticBurst* const _this, const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* _pProperties)>(0x16A8CE0);
	static inline auto FoperatorEq = PreyFunction<CArkPsiElectrostaticBurst& (CArkPsiElectrostaticBurst* const _this, CArkPsiElectrostaticBurst&& _blast)>(0x16A8220);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(const CArkPsiElectrostaticBurst* const _this)>(0x1CBB0B0);
	static inline auto FUpdateEffect = PreyFunction<void(const CArkPsiElectrostaticBurst* const _this, const std::vector<IEntity*> _entities)>(0x16A8240);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
class CArkPsiFearBlast : public CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> > // Id=801C882 Size=80
{
public:
	using BaseType = CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiFearBlastProperties>;
	
	CArkPsiFearBlast(Vec3 const &_pos, CArkPsiBlastProperties<ArkPsiFearBlastProperties> const *_pProperties);
#ifndef MOONCRASH
	CArkPsiFearBlast &operator=(CArkPsiFearBlast *_blast) { return FoperatorEq(this,_blast); }
#else
	CArkPsiFearBlast& operator=(CArkPsiFearBlast&& _blast) { return FoperatorEq(this, std::move(_blast)); }
#endif
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(std::vector<IEntity *> _entities) const { FUpdateEffect(this,_entities); }
	
#ifndef MOONCRASH
	static inline auto FoperatorEq = PreyFunction<CArkPsiFearBlast &(CArkPsiFearBlast *const _this, CArkPsiFearBlast *_blast)>(0x15811B0);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(CArkPsiFearBlast const *const _this)>(0x10E7940);
	static inline auto FUpdateEffect = PreyFunction<void(CArkPsiFearBlast const *const _this, std::vector<IEntity *> _entities)>(0x15819A0);
#else
	static inline auto FCArkPsiFearBlastOv1 = PreyFunction<void(CArkPsiFearBlast* const _this, const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* _pProperties)>(0x16A8CE0);
	static inline auto FoperatorEq = PreyFunction<CArkPsiFearBlast& (CArkPsiFearBlast* const _this, CArkPsiFearBlast&& _blast)>(0x16A8220);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(const CArkPsiFearBlast* const _this)>(0x206090);
	static inline auto FUpdateEffect = PreyFunction<void(const CArkPsiFearBlast* const _this, const std::vector<IEntity*> _entities)>(0x16A8D00);
#endif
};
