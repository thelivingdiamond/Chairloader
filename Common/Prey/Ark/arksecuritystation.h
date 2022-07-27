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

