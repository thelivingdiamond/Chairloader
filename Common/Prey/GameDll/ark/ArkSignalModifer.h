// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Override
// Prey/GameDll/ark/ArkSignalModifer.h
class ArkSignalModifer : public ArkReflectedObject // Id=80134E6 Size=16
{
public:
	class ArkIsInboundProperty : public ArkProperty // Id=80134E7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalModifer::ArkIsInboundProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10571E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalModifer::ArkIsInboundProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkSignalModifer::ArkIsInboundProperty s_ArkIsInboundProperty;
	bool m_IsInbound;
	
	class ArkModifierIdProperty : public ArkProperty // Id=80134E8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSignalModifer::ArkModifierIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107F050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSignalModifer::ArkModifierIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkSignalModifer::ArkModifierIdProperty s_ArkModifierIdProperty;
	uint64_t m_ModifierId;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetIsInbound(bool arg0);
	const bool &GetIsInbound() const;
	void SetModifierId(uint64_t arg0);
	const uint64_t &GetModifierId() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10586F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1058910);
};

