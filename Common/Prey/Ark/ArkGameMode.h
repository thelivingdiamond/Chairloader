// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkGameMode.h
class ArkGameMode : public ArkReflectedObject // Id=8013BC7 Size=24
{
public:
	class ArkNameProperty : public ArkProperty // Id=8013BC8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMode::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMode::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkGameMode::ArkNameProperty s_ArkNameProperty;
	CCryName m_Name;
	
	class ArkMappedPathOverrideProperty : public ArkProperty // Id=8013BC9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMode::ArkMappedPathOverrideProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMode::ArkMappedPathOverrideProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkGameMode::ArkMappedPathOverrideProperty s_ArkMappedPathOverrideProperty;
	string m_MappedPathOverride;
	
	class ArkEntitlementProperty : public ArkProperty // Id=8013BCA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMode::ArkEntitlementProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMode::ArkEntitlementProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkGameMode::ArkEntitlementProperty s_ArkEntitlementProperty;
	uint64_t m_Entitlement;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetName(CCryName arg0);
	CCryName const &GetName() const;
	void SetMappedPathOverride(string arg0);
	string const &GetMappedPathOverride() const;
	void SetEntitlement(uint64_t arg0);
	const uint64_t &GetEntitlement() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10684E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1068520);
};

// Header: Exact
// Prey/Ark/arkgamemode.h
class ArkGameModes : public ArkReflectedObject // Id=8013BD8 Size=24
{
public:
	class ArkGameModesProperty : public ArkProperty // Id=8013BD9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameModes::ArkGameModesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameModes::ArkGameModesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068050);
		static inline auto FIsArray = PreyFunction<bool(ArkGameModes::ArkGameModesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameModes::ArkGameModesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1068070);
	};

	static ArkGameModes::ArkGameModesProperty s_ArkGameModesProperty;
	std::vector<ArkGameMode> m_GameModes;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkGameMode> &GetGameModes();
	std::vector<ArkGameMode> const &GetGameModes() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;
class IArkValueBase;

// ArkGameMode
// Header:  Prey/Ark/ArkGameMode.h
class ArkGameMode : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkGameMode::ArkNameProperty
	// Header:  Prey/Ark/ArkGameMode.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMode::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMode::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkGameMode::ArkMappedPathOverrideProperty
	// Header:  Prey/Ark/ArkGameMode.h
	class ArkMappedPathOverrideProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMappedPathOverrideProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMode::ArkMappedPathOverrideProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMode::ArkMappedPathOverrideProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkGameMode::ArkEntitlementProperty
	// Header:  Prey/Ark/ArkGameMode.h
	class ArkEntitlementProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEntitlementProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMode::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMode::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkNameProperty = PreyGlobal<ArkGameMode::ArkNameProperty>(0x2D243F0);
	CCryName m_Name;
	static inline auto s_ArkMappedPathOverrideProperty = PreyGlobal<ArkGameMode::ArkMappedPathOverrideProperty>(0x2D24410);
	string m_MappedPathOverride;
	static inline auto s_ArkEntitlementProperty = PreyGlobal<ArkGameMode::ArkEntitlementProperty>(0x2D24430);
	uint64_t m_Entitlement;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetName(CCryName _arg0_);
	const CCryName& GetName() const;
	void SetMappedPathOverride(string _arg0_);
	const string& GetMappedPathOverride() const;
	void SetEntitlement(uint64_t _arg0_);
	const uint64_t& GetEntitlement() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108C950);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108C990);
};

// ArkGameModes
// Header:  Prey/Ark/ArkGameMode.h
class ArkGameModes : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkGameModes::ArkGameModesProperty
	// Header:  Prey/Ark/ArkGameMode.h
	class ArkGameModesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkGameModesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameModes::ArkGameModesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108C480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameModes::ArkGameModesProperty* const _this, ArkReflectedObject* const _pObject)>(0x108C520);
		static inline auto FIsArray = PreyFunction<bool(const ArkGameModes::ArkGameModesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkGameModes::ArkGameModesProperty* const _this, ArkReflectedObject* _pObject)>(0x108C540);
	};

	static inline auto s_ArkGameModesProperty = PreyGlobal<ArkGameModes::ArkGameModesProperty>(0x2D24450);
	std::vector<ArkGameMode> m_GameModes;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	std::vector<ArkGameMode>& GetGameModes();
	const std::vector<ArkGameMode>& GetGameModes() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
};
#endif // !MOONCRASH
