// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsifearblast.h
#ifdef MOONCRASH
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
#endif
class ArkPsiFearBlastProperties : public ArkReflectedObject // Id=801C87F Size=144
{
public:
	class ArkBlastPropertiesProperty : public ArkProperty // Id=801C880 Size=32
	{
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1581620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FArkBlastPropertiesPropertyOv2 = PreyFunction<void(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty* const _this)>(0x16A89A0);
		static inline auto FSetValue = PreyFunction<void(const ArkPsiFearBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16A8630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFearBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiFearBlastProperties::ArkBlastPropertiesProperty s_ArkBlastPropertiesProperty;
#else
	static inline auto s_ArkBlastPropertiesProperty = PreyGlobal<ArkPsiFearBlastProperties::ArkBlastPropertiesProperty>(0x2D7DBF0);
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
#ifdef MOONCRASH
#include <Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h>
#endif
