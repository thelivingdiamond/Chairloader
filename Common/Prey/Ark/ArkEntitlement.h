// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkEntitlement.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
#endif
class ArkEntitlement : public ArkReflectedObject // Id=800EFB3 Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=800EFB4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlement::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkEntitlement::ArkIDProperty>(0x2AE6658);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=800EFB5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlement::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEntitlement::ArkNameProperty>(0x2AE6678);
#endif
	string m_Name;
	
	class ArkSteamDlcIDProperty : public ArkProperty // Id=800EFB6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkSteamDlcIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkSteamDlcIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkSteamDlcIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkSteamDlcIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlement::ArkSteamDlcIDProperty s_ArkSteamDlcIDProperty;
#else
	static inline auto s_ArkSteamDlcIDProperty = PreyGlobal<ArkEntitlement::ArkSteamDlcIDProperty>(0x2AE6698);
#endif
	unsigned m_SteamDlcID;
	
	class ArkXboxDlcIDProperty : public ArkProperty // Id=800EFB7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkXboxDlcIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkXboxDlcIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkXboxDlcIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkXboxDlcIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlement::ArkXboxDlcIDProperty s_ArkXboxDlcIDProperty;
#else
	static inline auto s_ArkXboxDlcIDProperty = PreyGlobal<ArkEntitlement::ArkXboxDlcIDProperty>(0x2AE66B8);
#endif
	unsigned m_XboxDlcID;
	
	class ArkPlaystationDlcIDProperty : public ArkProperty // Id=800EFB8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkPlaystationDlcIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkPlaystationDlcIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkPlaystationDlcIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkPlaystationDlcIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlement::ArkPlaystationDlcIDProperty s_ArkPlaystationDlcIDProperty;
#else
	static inline auto s_ArkPlaystationDlcIDProperty = PreyGlobal<ArkEntitlement::ArkPlaystationDlcIDProperty>(0x2AE66D8);
#endif
	unsigned m_PlaystationDlcID;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetSteamDlcID(unsigned arg0);
	const unsigned &GetSteamDlcID() const;
	void SetXboxDlcID(unsigned arg0);
	const unsigned &GetXboxDlcID() const;
	void SetPlaystationDlcID(unsigned arg0);
	const unsigned &GetPlaystationDlcID() const;
	unsigned GetDlcID() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0xD56C80);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0xD56CB0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0xD747A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0xD747D0);
#endif
};

// Header: Exact
// Prey/Ark/arkentitlement.h
class ArkEntitlementLibrary : public ArkReflectedObject // Id=800EFC7 Size=24
{
public:
	class ArkEntitlementsProperty : public ArkProperty // Id=800EFC8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0xD56850);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this, ArkReflectedObject *const _pObject)>(0xD568D0);
		static inline auto FIsArray = PreyFunction<bool(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this, ArkReflectedObject *_pObject)>(0xD568F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0xD74320);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this, ArkReflectedObject* const _pObject)>(0xD743A0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this, ArkReflectedObject* _pObject)>(0xD743C0);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementLibrary::ArkEntitlementsProperty s_ArkEntitlementsProperty;
#else
	static inline auto s_ArkEntitlementsProperty = PreyGlobal<ArkEntitlementLibrary::ArkEntitlementsProperty>(0x2AE66F8);
#endif
	std::vector<ArkEntitlement> m_Entitlements;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	bool Init() { return FInit(this); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkEntitlement> &GetEntitlements();
	std::vector<ArkEntitlement> const &GetEntitlements() const;
	ArkEntitlement const *FindEntitlement(const uint64_t arg0) const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementLibrary *const _this)>(0xD56D50);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementLibrary* const _this)>(0xD74870);
#endif
};
