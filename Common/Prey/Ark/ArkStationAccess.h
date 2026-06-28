// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class ArkStationAirlock;

// Header: Exact
// Prey/Ark/arkstationaccess.h
class ArkTransition : public ArkReflectedObject // Id=8013C7A Size=24
{
public:
	class ArkConnectionAProperty : public ArkProperty // Id=8013C7B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTransition::ArkConnectionAProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTransition::ArkConnectionAProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkTransition::ArkConnectionAProperty s_ArkConnectionAProperty;
	uint64_t m_ConnectionA;
	
	class ArkConnectionBProperty : public ArkProperty // Id=8013C7C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTransition::ArkConnectionBProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107F050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTransition::ArkConnectionBProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkTransition::ArkConnectionBProperty s_ArkConnectionBProperty;
	uint64_t m_ConnectionB;
	
	class ArkCostProperty : public ArkProperty // Id=8013C7D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTransition::ArkCostProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTransition::ArkCostProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkTransition::ArkCostProperty s_ArkCostProperty;
	float m_Cost;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetConnectionA(uint64_t arg0);
	const uint64_t &GetConnectionA() const;
	void SetConnectionB(uint64_t arg0);
	const uint64_t &GetConnectionB() const;
	void SetCost(float arg0);
	const float &GetCost() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107F840);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106EAA0);
};

// Header: Exact
// Prey/Ark/arkstationaccess.h
class ArkStationPath : public ArkReflectedObject // Id=8016C35 Size=40
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016C36 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationPath::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationPath::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkStationPath::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016C37 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationPath::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationPath::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkStationPath::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkFlashIDProperty : public ArkProperty // Id=8016C38 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationPath::ArkFlashIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationPath::ArkFlashIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkStationPath::ArkFlashIDProperty s_ArkFlashIDProperty;
	string m_FlashID;
	
	class ArkLocationAProperty : public ArkProperty // Id=8016C39 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationPath::ArkLocationAProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationPath::ArkLocationAProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkStationPath::ArkLocationAProperty s_ArkLocationAProperty;
	uint64_t m_LocationA;
	
	class ArkLocationBProperty : public ArkProperty // Id=8016C3A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationPath::ArkLocationBProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationPath::ArkLocationBProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkStationPath::ArkLocationBProperty s_ArkLocationBProperty;
	uint64_t m_LocationB;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetFlashID(string arg0);
	string const &GetFlashID() const;
	void SetLocationA(uint64_t arg0);
	const uint64_t &GetLocationA() const;
	void SetLocationB(uint64_t arg0);
	const uint64_t &GetLocationB() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107F870);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107FAA0);
};

// Header: Exact
// Prey/Ark/ArkStationAccess.h
class ArkStationAccess : public ArkReflectedLibrary // Id=8016C4D Size=56
{
public:
	class ArkPathsProperty : public ArkProperty // Id=8016C4E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationAccess::ArkPathsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107EE70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationAccess::ArkPathsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107EF30);
		static inline auto FIsArray = PreyFunction<bool(ArkStationAccess::ArkPathsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkStationAccess::ArkPathsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107EF70);
	};

	static ArkStationAccess::ArkPathsProperty s_ArkPathsProperty;
	std::vector<ArkStationPath> m_Paths;
	
	class ArkAirlocksProperty : public ArkProperty // Id=8016C4F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationAccess::ArkAirlocksProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107EFB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationAccess::ArkAirlocksProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107EFF0);
		static inline auto FIsArray = PreyFunction<bool(ArkStationAccess::ArkAirlocksProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkStationAccess::ArkAirlocksProperty const *const _this, ArkReflectedObject *_pObject)>(0x107F030);
	};

	static ArkStationAccess::ArkAirlocksProperty s_ArkAirlocksProperty;
	std::vector<ArkStationAirlock> m_Airlocks;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	uint64_t GetPathIdForConnection(uint64_t _locationA, uint64_t _locationB) const { return FGetPathIdForConnection(this,_locationA,_locationB); }
	ArkStationAirlock const *FindAirlockByLocation(uint64_t _locationId) const { return FFindAirlockByLocation(this,_locationId); }
	ArkStationAirlock const *FindAirlock(uint64_t _airlockId) const { return FFindAirlock(this,_airlockId); }
	virtual ~ArkStationAccess();
	
#if 0
	std::vector<ArkStationPath> &GetPaths();
	std::vector<ArkStationPath> const &GetPaths() const;
	std::vector<ArkStationAirlock> &GetAirlocks();
	std::vector<ArkStationAirlock> const &GetAirlocks() const;
	ArkStationPath const *FindPath(uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107F7E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107F910);
	static inline auto FInit = PreyFunction<bool(ArkStationAccess *const _this)>(0x107FB80);
	static inline auto FGetPathIdForConnection = PreyFunction<uint64_t(ArkStationAccess const *const _this, uint64_t _locationA, uint64_t _locationB)>(0x107FB40);
	static inline auto FFindAirlockByLocation = PreyFunction<ArkStationAirlock const *(ArkStationAccess const *const _this, uint64_t _locationId)>(0x107F8E0);
	static inline auto FFindAirlock = PreyFunction<ArkStationAirlock const *(ArkStationAccess const *const _this, uint64_t _airlockId)>(0x107F8B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkStationPath
// Header:  Prey/Ark/ArkStationAccess.h
class ArkStationPath : public ArkReflectedObject
{ // Size=48 (0x30)
public:
	// ArkStationPath::ArkIDProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStationPath::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationPath::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkStationPath::ArkNameProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStationPath::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationPath::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkStationPath::ArkFlashIDProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkFlashIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFlashIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStationPath::ArkFlashIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationPath::ArkFlashIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkStationPath::ArkLocationAProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkLocationAProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationAProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStationPath::ArkLocationAProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationPath::ArkLocationAProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkStationPath::ArkLocationBProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkLocationBProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationBProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStationPath::ArkLocationBProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationPath::ArkLocationBProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkStationPath::ArkStartsLockedProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkStartsLockedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartsLockedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStationPath::ArkStartsLockedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationPath::ArkStartsLockedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkStationPath::ArkIDProperty>(0x2D28390);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkStationPath::ArkNameProperty>(0x2D283B0);
	string m_Name;
	static inline auto s_ArkFlashIDProperty = PreyGlobal<ArkStationPath::ArkFlashIDProperty>(0x2D283D0);
	string m_FlashID;
	static inline auto s_ArkLocationAProperty = PreyGlobal<ArkStationPath::ArkLocationAProperty>(0x2D283F0);
	uint64_t m_LocationA;
	static inline auto s_ArkLocationBProperty = PreyGlobal<ArkStationPath::ArkLocationBProperty>(0x2D28410);
	uint64_t m_LocationB;
	static inline auto s_ArkStartsLockedProperty = PreyGlobal<ArkStationPath::ArkStartsLockedProperty>(0x2D28430);
	bool m_StartsLocked;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetFlashID(string _arg0_);
	const string& GetFlashID() const;
	void SetLocationA(uint64_t _arg0_);
	const uint64_t& GetLocationA() const;
	void SetLocationB(uint64_t _arg0_);
	const uint64_t& GetLocationB() const;
	void SetStartsLocked(bool _arg0_);
	const bool& GetStartsLocked() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A9CE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A9E10);
};

// ArkStationAccess
// Header:  Prey/Ark/ArkStationAccess.h
class ArkStationAccess : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkStationAccess::ArkPathsProperty
	// Header:  Prey/Ark/ArkStationAccess.h
	class ArkPathsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkPathsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkPathsPropertyOv2 = PreyFunction<void(ArkStationAccess::ArkPathsProperty* const _this)>(0x10A99A0);
		static inline auto FSetValue = PreyFunction<void(const ArkStationAccess::ArkPathsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A93B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStationAccess::ArkPathsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A9470);
		static inline auto FIsArray = PreyFunction<bool(const ArkStationAccess::ArkPathsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkStationAccess::ArkPathsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A94B0);
	};

	static inline auto s_ArkPathsProperty = PreyGlobal<ArkStationAccess::ArkPathsProperty>(0x2D28450);
	std::vector<ArkStationPath> m_Paths;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	uint64_t GetPathIdForConnection(uint64_t _locationA, uint64_t _locationB) const { return FGetPathIdForConnection(this, _locationA, _locationB); }

#if 0
	std::vector<ArkStationPath>& GetPaths();
	const std::vector<ArkStationPath>& GetPaths() const;
	const ArkStationPath* FindPath(uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A9C80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A9D20);
	static inline auto FInit = PreyFunction<bool(ArkStationAccess* const _this)>(0x10A9EF0);
	static inline auto FGetPathIdForConnection = PreyFunction<uint64_t(const ArkStationAccess* const _this, uint64_t _locationA, uint64_t _locationB)>(0x10A9EB0);
};
#endif // !MOONCRASH
