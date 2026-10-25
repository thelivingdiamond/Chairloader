// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/Ark/ArkStationAccess.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arklocation.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
#endif
class ArkMapFloor : public ArkReflectedObject // Id=8013C77 Size=16
{
public:
	class ArkNameProperty : public ArkProperty // Id=8013C78 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMapFloor::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMapFloor::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMapFloor::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMapFloor::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkMapFloor::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkMapFloor::ArkNameProperty>(0x2D25A10);
#endif
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8013C79 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMapFloor::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMapFloor::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMapFloor::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMapFloor::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkMapFloor::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkMapFloor::ArkLabelProperty>(0x2D25A30);
#endif
	string m_Label;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106E840);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106EA00);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10929D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1092BC0);
#endif
};

// Header: Exact
// Prey/Ark/ArkLocation.h
class ArkLocation : public ArkReflectedObject // Id=8013C7E Size=112
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013C7F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkLocation::ArkIDProperty>(0x2D25AB0);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013C80 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkLocation::ArkNameProperty>(0x2D25AD0);
#endif
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8013C81 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkLocation::ArkLabelProperty>(0x2D25AF0);
#endif
	string m_Label;
	
	class ArkStationMapIndexProperty : public ArkProperty // Id=8013C82 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkStationMapIndexProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkStationMapIndexProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkStationMapIndexProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkStationMapIndexProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkStationMapIndexProperty s_ArkStationMapIndexProperty;
#else
	static inline auto s_ArkStationMapIndexProperty = PreyGlobal<ArkLocation::ArkStationMapIndexProperty>(0x2D25B10);
#endif
	unsigned m_StationMapIndex;
	
	class ArkCooldownProperty : public ArkProperty // Id=8013C83 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkCooldownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkCooldownProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkCooldownProperty s_ArkCooldownProperty;
#else
	static inline auto s_ArkCooldownProperty = PreyGlobal<ArkLocation::ArkCooldownProperty>(0x2D25B30);
#endif
	float m_Cooldown;
	
	class ArkTipProperty : public ArkProperty // Id=8013C84 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkTipProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkTipProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkTipProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkTipProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkTipProperty s_ArkTipProperty;
#else
	static inline auto s_ArkTipProperty = PreyGlobal<ArkLocation::ArkTipProperty>(0x2D25B50);
#endif
	uint64_t m_Tip;
	
	class ArkFloorsProperty : public ArkProperty // Id=8013C85 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkFloorsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D580);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkFloorsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D610);
		static inline auto FIsArray = PreyFunction<bool(ArkLocation::ArkFloorsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLocation::ArkFloorsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D630);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkFloorsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10916D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkFloorsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1091760);
		static inline auto FIsArray = PreyFunction<bool(const ArkLocation::ArkFloorsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLocation::ArkFloorsProperty* const _this, ArkReflectedObject* _pObject)>(0x1091780);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkFloorsProperty s_ArkFloorsProperty;
#else
	static inline auto s_ArkFloorsProperty = PreyGlobal<ArkLocation::ArkFloorsProperty>(0x2D25B70);
#endif
	std::vector<ArkMapFloor> m_Floors;
	
	class ArkScreenshotPathProperty : public ArkProperty // Id=8013C93 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkScreenshotPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkScreenshotPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkScreenshotPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkScreenshotPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkScreenshotPathProperty s_ArkScreenshotPathProperty;
#else
	static inline auto s_ArkScreenshotPathProperty = PreyGlobal<ArkLocation::ArkScreenshotPathProperty>(0x2D25B90);
#endif
	string m_ScreenshotPath;
	
	class ArkLevelNameProperty : public ArkProperty // Id=8013C94 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkLevelNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkLevelNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkLevelNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10917B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkLevelNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkLevelNameProperty s_ArkLevelNameProperty;
#else
	static inline auto s_ArkLevelNameProperty = PreyGlobal<ArkLocation::ArkLevelNameProperty>(0x2D25BB0);
#endif
	string m_LevelName;
	
	class ArkRichPresenceProperty : public ArkProperty // Id=8013C95 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkRichPresenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkRichPresenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkRichPresenceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkRichPresenceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkRichPresenceProperty s_ArkRichPresenceProperty;
#else
	static inline auto s_ArkRichPresenceProperty = PreyGlobal<ArkLocation::ArkRichPresenceProperty>(0x2D25BD0);
#endif
	string m_RichPresence;
	
	class ArkTransitionsProperty : public ArkProperty // Id=8013C96 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkTransitionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D6C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkTransitionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D6F0);
		static inline auto FIsArray = PreyFunction<bool(ArkLocation::ArkTransitionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLocation::ArkTransitionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D710);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLocation::ArkTransitionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1091810);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocation::ArkTransitionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1091840);
		static inline auto FIsArray = PreyFunction<bool(const ArkLocation::ArkTransitionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLocation::ArkTransitionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1079660);
#endif
	};

#ifndef MOONCRASH
	static ArkLocation::ArkTransitionsProperty s_ArkTransitionsProperty;
#else
	static inline auto s_ArkTransitionsProperty = PreyGlobal<ArkLocation::ArkTransitionsProperty>(0x2D25BF0);
#endif
	std::vector<ArkTransition> m_Transitions;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetStationMapIndex(unsigned arg0);
	const unsigned &GetStationMapIndex() const;
	void SetCooldown(float arg0);
	const float &GetCooldown() const;
	void SetTip(uint64_t arg0);
	const uint64_t &GetTip() const;
	std::vector<ArkMapFloor> &GetFloors();
	std::vector<ArkMapFloor> const &GetFloors() const;
	void SetScreenshotPath(string arg0);
	string const &GetScreenshotPath() const;
	void SetLevelName(string arg0);
	string const &GetLevelName() const;
	void SetRichPresence(string arg0);
	string const &GetRichPresence() const;
	std::vector<ArkTransition> &GetTransitions();
	std::vector<ArkTransition> const &GetTransitions() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106E770);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106E870);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1092900);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1092A30);
#endif
};

// Header: Exact
// Prey/Ark/arklocation.h
class ArkLocations : public ArkReflectedLibrary // Id=8013CB3 Size=32
{
public:
	class ArkLocationsProperty : public ArkProperty // Id=8013CB4 Size=32
	{
	public:
		ArkLocationsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLocations::ArkLocationsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocations::ArkLocationsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D4B0);
		static inline auto FIsArray = PreyFunction<bool(ArkLocations::ArkLocationsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLocations::ArkLocationsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D4F0);
#else
		static inline auto FArkLocationsPropertyOv2 = PreyFunction<void(ArkLocations::ArkLocationsProperty* const _this)>(0x1092550);
		static inline auto FSetValue = PreyFunction<void(const ArkLocations::ArkLocationsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10915D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLocations::ArkLocationsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1091620);
		static inline auto FIsArray = PreyFunction<bool(const ArkLocations::ArkLocationsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLocations::ArkLocationsProperty* const _this, ArkReflectedObject* _pObject)>(0x1091660);
#endif
	};

#ifndef MOONCRASH
	static ArkLocations::ArkLocationsProperty s_ArkLocationsProperty;
#else
	static inline auto s_ArkLocationsProperty = PreyGlobal<ArkLocations::ArkLocationsProperty>(0x2D25C10);
#endif
	std::vector<ArkLocation> m_Locations;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkLocations();
	
#if 0
	std::vector<ArkLocation> &GetLocations();
	std::vector<ArkLocation> const &GetLocations() const;
	ArkLocation const *FindLocation(const uint64_t arg0) const;
	ArkLocation const *FindLocation(const char *arg0) const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106E7E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106E910);
	static inline auto FInit = PreyFunction<bool(ArkLocations *const _this)>(0x106EB40);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1092970);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1092AD0);
	static inline auto FInit = PreyFunction<bool(ArkLocations* const _this)>(0x1092D00);
#endif
};
