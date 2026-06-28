// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGamePhysicsSettings.h>

struct IPhysicalEntity;

// CGamePhysicsSettings
// Header:  Prey/GameDll/GamePhysicsSettings.h
class CGamePhysicsSettings : public IGamePhysicsSettings
{ // Size=288 (0x120)
public:
	enum class #unnamed_enum_MAX_COLLISION_CLASSES
	{
		MAX_COLLISION_CLASSES = 23,
	};

	const char* m_names[23];
	unsigned m_classIgnoreMap[23];

	virtual ~CGamePhysicsSettings();
	virtual const char* GetCollisionClassName(unsigned bitIndex);
	void Init() { FInit(this); }
	void ExportToLua() { FExportToLua(this); }
	void AddCollisionClassFlags(IPhysicalEntity& physEnt, unsigned gcc_classTypes, const unsigned additionalIgnoreClassTypesOR, const unsigned additionalIgnoreClassTypesAND) { FAddCollisionClassFlags(this, physEnt, gcc_classTypes, additionalIgnoreClassTypesOR, additionalIgnoreClassTypesAND); }

#if 0
	CGamePhysicsSettings();
	int GetBit(unsigned _arg0_);
	void SetIgnoreMap(unsigned _arg0_, const unsigned _arg1_);
	void AddIgnoreMap(unsigned _arg0_, const unsigned _arg1_, const unsigned _arg2_);
	void SetCollisionClassFlags(IPhysicalEntity& _arg0_, unsigned _arg1_, const unsigned _arg2_, const unsigned _arg3_);
	void Debug(const IPhysicalEntity& _arg0_, const bool _arg1_) const;
	int ToString(unsigned _arg0_, char* _arg1_, const int _arg2_, const bool _arg3_) const;
	unsigned GetIgnoreTypes(unsigned _arg0_) const;
#endif

	static inline auto FGetCollisionClassName = PreyFunction<const char* (CGamePhysicsSettings* const _this, unsigned bitIndex)>(0x18365F0);
	static inline auto FInit = PreyFunction<void(CGamePhysicsSettings* const _this)>(0x1836610);
	static inline auto FExportToLua = PreyFunction<void(CGamePhysicsSettings* const _this)>(0x18361E0);
	static inline auto FAddCollisionClassFlags = PreyFunction<void(CGamePhysicsSettings* const _this, IPhysicalEntity& physEnt, unsigned gcc_classTypes, const unsigned additionalIgnoreClassTypesOR, const unsigned additionalIgnoreClassTypesAND)>(0x1836160);
};
#endif // MOONCRASH
