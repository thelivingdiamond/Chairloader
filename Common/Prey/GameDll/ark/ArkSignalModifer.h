// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkSignalModifer
// Header:  Prey/GameDll/ark/ArkSignalModifer.h
class ArkSignalModifer : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkSignalModifer::ArkIsInboundProperty
	// Header:  Prey/GameDll/ark/ArkSignalModifer.h
	class ArkIsInboundProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsInboundProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalModifer::ArkIsInboundProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2A90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalModifer::ArkIsInboundProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkSignalModifer::ArkModifierIdProperty
	// Header:  Prey/GameDll/ark/ArkSignalModifer.h
	class ArkModifierIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModifierIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSignalModifer::ArkModifierIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSignalModifer::ArkModifierIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkIsInboundProperty = PreyGlobal<ArkSignalModifer::ArkIsInboundProperty>(0x2D20C90);
	bool m_IsInbound;
	static inline auto s_ArkModifierIdProperty = PreyGlobal<ArkSignalModifer::ArkModifierIdProperty>(0x2D20CB0);
	uint64_t m_ModifierId;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkSignalModifer();
	void SetIsInbound(bool _arg0_);
	const bool& GetIsInbound() const;
	void SetModifierId(uint64_t _arg0_);
	const uint64_t& GetModifierId() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1074DE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1075000);
};
#endif // !MOONCRASH
