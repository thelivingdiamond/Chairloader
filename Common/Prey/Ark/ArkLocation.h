// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/Ark/ArkStationAccess.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arklocation.h
class ArkMapFloor : public ArkReflectedObject // Id=8013C77 Size=16
{
public:
	class ArkNameProperty : public ArkProperty // Id=8013C78 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMapFloor::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMapFloor::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMapFloor::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8013C79 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMapFloor::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMapFloor::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkMapFloor::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106E840);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106EA00);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkLocation::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013C80 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkLocation::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8013C81 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkLocation::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkStationMapIndexProperty : public ArkProperty // Id=8013C82 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkStationMapIndexProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkStationMapIndexProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkLocation::ArkStationMapIndexProperty s_ArkStationMapIndexProperty;
	unsigned m_StationMapIndex;
	
	class ArkCooldownProperty : public ArkProperty // Id=8013C83 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkLocation::ArkCooldownProperty s_ArkCooldownProperty;
	float m_Cooldown;
	
	class ArkTipProperty : public ArkProperty // Id=8013C84 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkTipProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkTipProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkLocation::ArkTipProperty s_ArkTipProperty;
	uint64_t m_Tip;
	
	class ArkFloorsProperty : public ArkProperty // Id=8013C85 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkFloorsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D580);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkFloorsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D610);
		static inline auto FIsArray = PreyFunction<bool(ArkLocation::ArkFloorsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLocation::ArkFloorsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D630);
	};

	static ArkLocation::ArkFloorsProperty s_ArkFloorsProperty;
	std::vector<ArkMapFloor> m_Floors;
	
	class ArkScreenshotPathProperty : public ArkProperty // Id=8013C93 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkScreenshotPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkScreenshotPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkLocation::ArkScreenshotPathProperty s_ArkScreenshotPathProperty;
	string m_ScreenshotPath;
	
	class ArkLevelNameProperty : public ArkProperty // Id=8013C94 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkLevelNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkLevelNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkLocation::ArkLevelNameProperty s_ArkLevelNameProperty;
	string m_LevelName;
	
	class ArkRichPresenceProperty : public ArkProperty // Id=8013C95 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkRichPresenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkRichPresenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkLocation::ArkRichPresenceProperty s_ArkRichPresenceProperty;
	string m_RichPresence;
	
	class ArkTransitionsProperty : public ArkProperty // Id=8013C96 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLocation::ArkTransitionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D6C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocation::ArkTransitionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D6F0);
		static inline auto FIsArray = PreyFunction<bool(ArkLocation::ArkTransitionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLocation::ArkTransitionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D710);
	};

	static ArkLocation::ArkTransitionsProperty s_ArkTransitionsProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106E770);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106E870);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkLocations::ArkLocationsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLocations::ArkLocationsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D4B0);
		static inline auto FIsArray = PreyFunction<bool(ArkLocations::ArkLocationsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLocations::ArkLocationsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D4F0);
	};

	static ArkLocations::ArkLocationsProperty s_ArkLocationsProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106E7E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106E910);
	static inline auto FInit = PreyFunction<bool(ArkLocations *const _this)>(0x106EB40);
};

