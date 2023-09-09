// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkPointOfInterest.h
class ArkPointOfInterest : public ArkReflectedObject // Id=8016B2D Size=24
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016B2E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPointOfInterest::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPointOfInterest::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPointOfInterest::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016B2F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPointOfInterest::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPointOfInterest::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPointOfInterest::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8016B30 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPointOfInterest::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPointOfInterest::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPointOfInterest::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107A1A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107A240);
};

// Header: Exact
// Prey/Ark/arkpointofinterest.h
class ArkPointOfInterestLibrary : public ArkReflectedLibrary // Id=8016B3E Size=32
{
public:
	class ArkPOIsProperty : public ArkProperty // Id=8016B3F Size=32
	{
	public:
		ArkPOIsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPointOfInterestLibrary::ArkPOIsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1079B20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPointOfInterestLibrary::ArkPOIsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1079BC0);
		static inline auto FIsArray = PreyFunction<bool(ArkPointOfInterestLibrary::ArkPOIsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPointOfInterestLibrary::ArkPOIsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1079C00);
	};

	static ArkPointOfInterestLibrary::ArkPOIsProperty s_ArkPOIsProperty;
	std::vector<ArkPointOfInterest> m_POIs;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkPointOfInterestLibrary();
	
#if 0
	std::vector<ArkPointOfInterest> &GetPOIs();
	std::vector<ArkPointOfInterest> const &GetPOIs() const;
	ArkPointOfInterest const *FindPOI(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107A1E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107A2E0);
	static inline auto FInit = PreyFunction<bool(ArkPointOfInterestLibrary *const _this)>(0x107A3D0);
};

