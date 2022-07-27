// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiBlastProperties.h>
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

