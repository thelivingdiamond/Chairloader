// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>

class ArkClass;
class ArkReflectedObject;
class ArkSecurityStation;
class ArkUtility;
class ArkUtilityButton;

// Header: Exact
// Prey/Ark/arksecuritystation.h
class ArkSecurityStations : public ArkReflectedLibrary // Id=8016C2C Size=32
{
public:
	class ArkSecurityStationsProperty : public ArkProperty // Id=8016C2D Size=32
	{
	public:
		ArkSecurityStationsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStations::ArkSecurityStationsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107D7A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStations::ArkSecurityStationsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107D840);
		static inline auto FIsArray = PreyFunction<bool(ArkSecurityStations::ArkSecurityStationsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkSecurityStations::ArkSecurityStationsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107D880);
	};

	static ArkSecurityStations::ArkSecurityStationsProperty s_ArkSecurityStationsProperty;
	std::vector<ArkSecurityStation> m_SecurityStations;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkSecurityStation const *Find(const uint64_t _id) const { return FFind(this,_id); }
	ArkUtility const *FindUtility(const uint64_t _id) const { return FFindUtility(this,_id); }
	ArkUtilityButton const *FindUtilityButton(const uint64_t _id) const { return FFindUtilityButton(this,_id); }
	uint64_t GetUtilityButtonOwner(const uint64_t _id) const { return FGetUtilityButtonOwner(this,_id); }
	virtual ~ArkSecurityStations();
	
#if 0
	std::vector<ArkSecurityStation> &GetSecurityStations();
	std::vector<ArkSecurityStation> const &GetSecurityStations() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107E6A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107E950);
	static inline auto FInit = PreyFunction<bool(ArkSecurityStations *const _this)>(0x107EB70);
	static inline auto FFind = PreyFunction<ArkSecurityStation const *(ArkSecurityStations const *const _this, const uint64_t _id)>(0x107E700);
	static inline auto FFindUtility = PreyFunction<ArkUtility const *(ArkSecurityStations const *const _this, const uint64_t _id)>(0x107E730);
	static inline auto FFindUtilityButton = PreyFunction<ArkUtilityButton const *(ArkSecurityStations const *const _this, const uint64_t _id)>(0x107E780);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(ArkSecurityStations const *const _this, const uint64_t _id)>(0x107EA40);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class ArkUtility;
class ArkUtilityButton;
class IArkValueBase;

// ArkSecurityStation
// Header:  Prey/Ark/ArkSecurityStation.h
class ArkSecurityStation : public ArkReflectedObject
{ // Size=120 (0x78)
public:
	// ArkSecurityStation::ArkIDProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkSecurityStation::ArkNameProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkSecurityStation::ArkUserProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkUserProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUserProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkUserProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkUserProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkSecurityStation::ArkLocationProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkLocationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkSecurityStation::ArkEmailsProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkEmailsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEmailsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkEmailsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A7140);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkEmailsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A7160);
		static inline auto FIsArray = PreyFunction<bool(const ArkSecurityStation::ArkEmailsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkSecurityStation::ArkEmailsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A7180);
	};

	// ArkSecurityStation::ArkPersonnelProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkPersonnelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPersonnelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkPersonnelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkPersonnelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073740);
		static inline auto FIsArray = PreyFunction<bool(const ArkSecurityStation::ArkPersonnelProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkSecurityStation::ArkPersonnelProperty* const _this, ArkReflectedObject* _pObject)>(0x1077BE0);
	};

	// ArkSecurityStation::ArkUtilitiesProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkUtilitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkUtilitiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkUtilitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A7190);
		static inline auto FIsArray = PreyFunction<bool(const ArkSecurityStation::ArkUtilitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkSecurityStation::ArkUtilitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x10A71B0);
	};

	// ArkSecurityStation::ArkPersonnelTitleProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkPersonnelTitleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPersonnelTitleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkPersonnelTitleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0B90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkPersonnelTitleProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkSecurityStation::ArkInSatelliteProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkInSatelliteProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInSatelliteProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStation::ArkInSatelliteProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7850);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStation::ArkInSatelliteProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkSecurityStation::ArkIDProperty>(0x2D28010);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkSecurityStation::ArkNameProperty>(0x2D28030);
	string m_Name;
	static inline auto s_ArkUserProperty = PreyGlobal<ArkSecurityStation::ArkUserProperty>(0x2D28050);
	uint64_t m_User;
	static inline auto s_ArkLocationProperty = PreyGlobal<ArkSecurityStation::ArkLocationProperty>(0x2D28070);
	uint64_t m_Location;
	static inline auto s_ArkEmailsProperty = PreyGlobal<ArkSecurityStation::ArkEmailsProperty>(0x2D28090);
	std::vector<uint64_t> m_Emails;
	static inline auto s_ArkPersonnelProperty = PreyGlobal<ArkSecurityStation::ArkPersonnelProperty>(0x2D280B0);
	std::vector<uint64_t> m_Personnel;
	static inline auto s_ArkUtilitiesProperty = PreyGlobal<ArkSecurityStation::ArkUtilitiesProperty>(0x2D280D0);
	std::vector<std::shared_ptr<ArkUtility>> m_Utilities;
	static inline auto s_ArkPersonnelTitleProperty = PreyGlobal<ArkSecurityStation::ArkPersonnelTitleProperty>(0x2D280F0);
	string m_PersonnelTitle;
	static inline auto s_ArkInSatelliteProperty = PreyGlobal<ArkSecurityStation::ArkInSatelliteProperty>(0x2D28110);
	bool m_InSatellite;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkSecurityStation();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetUser(uint64_t _arg0_);
	const uint64_t& GetUser() const;
	void SetLocation(uint64_t _arg0_);
	const uint64_t& GetLocation() const;
	std::vector<uint64_t>& GetEmails();
	const std::vector<uint64_t>& GetEmails() const;
	std::vector<uint64_t>& GetPersonnel();
	const std::vector<uint64_t>& GetPersonnel() const;
	std::vector<std::shared_ptr<ArkUtility>>& GetUtilities();
	const std::vector<std::shared_ptr<ArkUtility>>& GetUtilities() const;
	void SetPersonnelTitle(string _arg0_);
	const string& GetPersonnelTitle() const;
	void SetInSatellite(bool _arg0_);
	const bool& GetInSatellite() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A80A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A8310);
};

// ArkSecurityStations
// Header:  Prey/Ark/ArkSecurityStation.h
class ArkSecurityStations : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkSecurityStations::ArkSecurityStationsProperty
	// Header:  Prey/Ark/ArkSecurityStation.h
	class ArkSecurityStationsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkSecurityStationsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkSecurityStationsPropertyOv2 = PreyFunction<void(ArkSecurityStations::ArkSecurityStationsProperty* const _this)>(0x10A7CC0);
		static inline auto FSetValue = PreyFunction<void(const ArkSecurityStations::ArkSecurityStationsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A71E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkSecurityStations::ArkSecurityStationsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A7310);
		static inline auto FIsArray = PreyFunction<bool(const ArkSecurityStations::ArkSecurityStationsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkSecurityStations::ArkSecurityStationsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A7350);
	};

	static inline auto s_ArkSecurityStationsProperty = PreyGlobal<ArkSecurityStations::ArkSecurityStationsProperty>(0x2D28130);
	std::vector<ArkSecurityStation> m_SecurityStations;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkSecurityStation* Find(const uint64_t _id) const { return FFind(this, _id); }
	const ArkUtility* FindUtility(const uint64_t _id) const { return FFindUtility(this, _id); }
	const ArkUtilityButton* FindUtilityButton(const uint64_t _id) const { return FFindUtilityButton(this, _id); }
	uint64_t GetUtilityButtonOwner(const uint64_t _id) const { return FGetUtilityButtonOwner(this, _id); }

#if 0
	std::vector<ArkSecurityStation>& GetSecurityStations();
	const std::vector<ArkSecurityStation>& GetSecurityStations() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A8100);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A83B0);
	static inline auto FInit = PreyFunction<bool(ArkSecurityStations* const _this)>(0x10A85D0);
	static inline auto FFind = PreyFunction<const ArkSecurityStation* (const ArkSecurityStations* const _this, const uint64_t _id)>(0x10A8160);
	static inline auto FFindUtility = PreyFunction<const ArkUtility* (const ArkSecurityStations* const _this, const uint64_t _id)>(0x10A8190);
	static inline auto FFindUtilityButton = PreyFunction<const ArkUtilityButton* (const ArkSecurityStations* const _this, const uint64_t _id)>(0x10A81E0);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(const ArkSecurityStations* const _this, const uint64_t _id)>(0x10A84A0);
};
#endif // !MOONCRASH
