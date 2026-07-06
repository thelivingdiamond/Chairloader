// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkIndicatorIconManager.h
class ArkIndicatorIconManager // Id=80167A7 Size=56
{
public:
	struct IndicatorIcon // Id=80167A8 Size=24
	{
		unsigned m_entityId;
		string m_identifier;
		float m_radius;
		bool m_bWasShownInUI;
		bool m_bClearOnSerialize;
		
		void UpdateIdentifier(const char *_type) { FUpdateIdentifier(this,_type); }
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(unsigned arg0) const;
		bool operator==(ArkIndicatorIconManager::IndicatorIcon const &arg0) const;
#endif
		
		static inline auto FUpdateIdentifier = PreyFunction<void(ArkIndicatorIconManager::IndicatorIcon *const _this, const char *_type)>(0x12F8FE0);
	};

	std::vector<ArkIndicatorIconManager::IndicatorIcon> m_impendingDangers;
	std::vector<ArkIndicatorIconManager::IndicatorIcon> m_repairIcons;
	bool m_bImpendingDangerInRange;
	float m_bufferRange;
	
	ArkIndicatorIconManager();
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset() { FReset(this); }
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	void AddImpendingDanger(unsigned _entityId, float _radius, bool _bClearOnSerialize) { FAddImpendingDanger(this,_entityId,_radius,_bClearOnSerialize); }
	void RemoveImpendingDanger(unsigned _entityId) { FRemoveImpendingDanger(this,_entityId); }
	void AddRepairIcon(unsigned _entityId, float _radius) { FAddRepairIcon(this,_entityId,_radius); }
	void RemoveRepairIcon(unsigned _entityId) { FRemoveRepairIcon(this,_entityId); }
	void RemoveIndicatorIcon(std::vector<ArkIndicatorIconManager::IndicatorIcon> &_icons, unsigned _entityId, const char *_removeFn) { FRemoveIndicatorIcon(this,_icons,_entityId,_removeFn); }
	
#if 0
	bool HasImpendingDangerInRange() const;
#endif
	
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkIndicatorIconManager *const _this)>(0x12F8F30);
	static inline auto FSerialize = PreyFunction<void(ArkIndicatorIconManager *const _this, TSerialize _ser)>(0x12F8DF0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkIndicatorIconManager *const _this)>(0x12F8C20);
	static inline auto FReset = PreyFunction<void(ArkIndicatorIconManager *const _this)>(0x12F8D80);
	static inline auto FLoadConfig = PreyFunction<void(ArkIndicatorIconManager *const _this, XmlNodeRef const &_root)>(0x12F8C00);
	static inline auto FAddImpendingDanger = PreyFunction<void(ArkIndicatorIconManager *const _this, unsigned _entityId, float _radius, bool _bClearOnSerialize)>(0x12F8AD0);
	static inline auto FRemoveImpendingDanger = PreyFunction<void(ArkIndicatorIconManager *const _this, unsigned _entityId)>(0x12F8C30);
	static inline auto FAddRepairIcon = PreyFunction<void(ArkIndicatorIconManager *const _this, unsigned _entityId, float _radius)>(0x12F8B70);
	static inline auto FRemoveRepairIcon = PreyFunction<void(ArkIndicatorIconManager *const _this, unsigned _entityId)>(0x12F8D60);
	static inline auto FRemoveIndicatorIcon = PreyFunction<void(ArkIndicatorIconManager *const _this, std::vector<ArkIndicatorIconManager::IndicatorIcon> &_icons, unsigned _entityId, const char *_removeFn)>(0x12F8C50);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class XmlNodeRef;

// ArkIndicatorIconManager
// Header:  Prey/GameDll/ark/ui/ArkIndicatorIconManager.h
class ArkIndicatorIconManager
{ // Size=56 (0x38)
public:
	// ArkIndicatorIconManager::IndicatorIcon
	// Header:  Prey/GameDll/ark/ui/ArkIndicatorIconManager.h
	struct IndicatorIcon
	{ // Size=24 (0x18)
		unsigned m_entityId;
		string m_identifier;
		float m_radius;
		bool m_bWasShownInUI;
		bool m_bClearOnSerialize;

		void UpdateIdentifier(const char* _type) { FUpdateIdentifier(this, _type); }

	#if 0
		IndicatorIcon();
		IndicatorIcon(const unsigned _arg0_, const float _arg1_, const char* _arg2_, bool _arg3_);
		void Serialize(TSerialize _arg0_);
		bool operator==(unsigned _arg0_) const;
		bool operator==(const ArkIndicatorIconManager::IndicatorIcon& _arg0_) const;
	#endif

		static inline auto FUpdateIdentifier = PreyFunction<void(ArkIndicatorIconManager::IndicatorIcon* const _this, const char* _type)>(0x13D35C0);
	};

	std::vector<ArkIndicatorIconManager::IndicatorIcon> m_impendingDangers;
	std::vector<ArkIndicatorIconManager::IndicatorIcon> m_repairIcons;
	bool m_bImpendingDangerInRange;
	float m_bufferRange;

	ArkIndicatorIconManager();
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset() { FReset(this); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void AddImpendingDanger(unsigned _entityId, float _radius, bool _bClearOnSerialize) { FAddImpendingDanger(this, _entityId, _radius, _bClearOnSerialize); }
	void RemoveImpendingDanger(unsigned _entityId) { FRemoveImpendingDanger(this, _entityId); }
	void AddRepairIcon(unsigned _entityId, float _radius) { FAddRepairIcon(this, _entityId, _radius); }
	void RemoveRepairIcon(unsigned _entityId) { FRemoveRepairIcon(this, _entityId); }
	void RemoveIndicatorIcon(std::vector<ArkIndicatorIconManager::IndicatorIcon>& _icons, unsigned _entityId, const char* _removeFn) { FRemoveIndicatorIcon(this, _icons, _entityId, _removeFn); }

#if 0
	bool HasImpendingDangerInRange() const;
#endif

	static inline auto FArkIndicatorIconManagerOv2 = PreyFunction<void(ArkIndicatorIconManager* const _this)>(0x13D2830);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkIndicatorIconManager* const _this)>(0x13D3510);
	static inline auto FSerialize = PreyFunction<void(ArkIndicatorIconManager* const _this, TSerialize _ser)>(0x13D33D0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkIndicatorIconManager* const _this)>(0x13D3200);
	static inline auto FReset = PreyFunction<void(ArkIndicatorIconManager* const _this)>(0x13D3360);
	static inline auto FLoadConfig = PreyFunction<void(ArkIndicatorIconManager* const _this, const XmlNodeRef& _root)>(0x13D31E0);
	static inline auto FAddImpendingDanger = PreyFunction<void(ArkIndicatorIconManager* const _this, unsigned _entityId, float _radius, bool _bClearOnSerialize)>(0x13D30B0);
	static inline auto FRemoveImpendingDanger = PreyFunction<void(ArkIndicatorIconManager* const _this, unsigned _entityId)>(0x13D3210);
	static inline auto FAddRepairIcon = PreyFunction<void(ArkIndicatorIconManager* const _this, unsigned _entityId, float _radius)>(0x13D3150);
	static inline auto FRemoveRepairIcon = PreyFunction<void(ArkIndicatorIconManager* const _this, unsigned _entityId)>(0x13D3340);
	static inline auto FRemoveIndicatorIcon = PreyFunction<void(ArkIndicatorIconManager* const _this, std::vector<ArkIndicatorIconManager::IndicatorIcon>& _icons, unsigned _entityId, const char* _removeFn)>(0x13D3230);
};
#endif // !MOONCRASH
