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

