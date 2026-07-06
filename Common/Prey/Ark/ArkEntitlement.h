// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkEntitlement.h
class ArkEntitlement : public ArkReflectedObject // Id=800EFB3 Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=800EFB4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkEntitlement::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=800EFB5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkEntitlement::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkSteamDlcIDProperty : public ArkProperty // Id=800EFB6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkSteamDlcIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkSteamDlcIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkEntitlement::ArkSteamDlcIDProperty s_ArkSteamDlcIDProperty;
	unsigned m_SteamDlcID;
	
	class ArkXboxDlcIDProperty : public ArkProperty // Id=800EFB7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkXboxDlcIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkXboxDlcIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkEntitlement::ArkXboxDlcIDProperty s_ArkXboxDlcIDProperty;
	unsigned m_XboxDlcID;
	
	class ArkPlaystationDlcIDProperty : public ArkProperty // Id=800EFB8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlement::ArkPlaystationDlcIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlement::ArkPlaystationDlcIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkEntitlement::ArkPlaystationDlcIDProperty s_ArkPlaystationDlcIDProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0xD56C80);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0xD56CB0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0xD56850);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this, ArkReflectedObject *const _pObject)>(0xD568D0);
		static inline auto FIsArray = PreyFunction<bool(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEntitlementLibrary::ArkEntitlementsProperty const *const _this, ArkReflectedObject *_pObject)>(0xD568F0);
	};

	static ArkEntitlementLibrary::ArkEntitlementsProperty s_ArkEntitlementsProperty;
	std::vector<ArkEntitlement> m_Entitlements;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	bool Init() { return FInit(this); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkEntitlement> &GetEntitlements();
	std::vector<ArkEntitlement> const &GetEntitlements() const;
	ArkEntitlement const *FindEntitlement(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementLibrary *const _this)>(0xD56D50);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkEntitlement
// Header:  Prey/Ark/ArkEntitlement.h
class ArkEntitlement : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkEntitlement::ArkIDProperty
	// Header:  Prey/Ark/ArkEntitlement.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkEntitlement::ArkNameProperty
	// Header:  Prey/Ark/ArkEntitlement.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkEntitlement::ArkSteamDlcIDProperty
	// Header:  Prey/Ark/ArkEntitlement.h
	class ArkSteamDlcIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSteamDlcIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkSteamDlcIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkSteamDlcIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkEntitlement::ArkXboxDlcIDProperty
	// Header:  Prey/Ark/ArkEntitlement.h
	class ArkXboxDlcIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkXboxDlcIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkXboxDlcIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkXboxDlcIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkEntitlement::ArkPlaystationDlcIDProperty
	// Header:  Prey/Ark/ArkEntitlement.h
	class ArkPlaystationDlcIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlaystationDlcIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEntitlement::ArkPlaystationDlcIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlement::ArkPlaystationDlcIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkEntitlement::ArkIDProperty>(0x2AE6658);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEntitlement::ArkNameProperty>(0x2AE6678);
	string m_Name;
	static inline auto s_ArkSteamDlcIDProperty = PreyGlobal<ArkEntitlement::ArkSteamDlcIDProperty>(0x2AE6698);
	unsigned m_SteamDlcID;
	static inline auto s_ArkXboxDlcIDProperty = PreyGlobal<ArkEntitlement::ArkXboxDlcIDProperty>(0x2AE66B8);
	unsigned m_XboxDlcID;
	static inline auto s_ArkPlaystationDlcIDProperty = PreyGlobal<ArkEntitlement::ArkPlaystationDlcIDProperty>(0x2AE66D8);
	unsigned m_PlaystationDlcID;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkEntitlement();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetSteamDlcID(unsigned _arg0_);
	const unsigned& GetSteamDlcID() const;
	void SetXboxDlcID(unsigned _arg0_);
	const unsigned& GetXboxDlcID() const;
	void SetPlaystationDlcID(unsigned _arg0_);
	const unsigned& GetPlaystationDlcID() const;
	unsigned GetDlcID() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0xD747A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0xD747D0);
};

// ArkEntitlementLibrary
// Header:  Prey/Ark/ArkEntitlement.h
class ArkEntitlementLibrary : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkEntitlementLibrary::ArkEntitlementsProperty
	// Header:  Prey/Ark/ArkEntitlement.h
	class ArkEntitlementsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEntitlementsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0xD74320);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this, ArkReflectedObject* const _pObject)>(0xD743A0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEntitlementLibrary::ArkEntitlementsProperty* const _this, ArkReflectedObject* _pObject)>(0xD743C0);
	};

	static inline auto s_ArkEntitlementsProperty = PreyGlobal<ArkEntitlementLibrary::ArkEntitlementsProperty>(0x2AE66F8);
	std::vector<ArkEntitlement> m_Entitlements;

	static ArkReflectedObject* Create() { return FCreate(); }
	bool Init() { return FInit(this); }

#if 0
	static ArkClass* GetClass();
	std::vector<ArkEntitlement>& GetEntitlements();
	const std::vector<ArkEntitlement>& GetEntitlements() const;
	const ArkEntitlement* FindEntitlement(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementLibrary* const _this)>(0xD74870);
};
#endif // !MOONCRASH
