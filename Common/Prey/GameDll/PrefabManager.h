// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/CryGame_tBrushParams.h>
#include <Prey/GameDll/CryGame_tEntityParams.h>
#include <Prey/GameDll/CryGame_tPrefabParams.h>

namespace CryGame
{
class CPrefabLib;
class CRuntimePrefab;
} // namespace CryGame
struct IEntity;
struct SEntitySpawnParams;
class XmlNodeRef;

namespace CryGame
{

// CryGame::CPrefab
// Header:  Prey/GameDll/PrefabManager.h
class CPrefab
{ // Size=200 (0xC8)
public:
	char m_szName[128];
	std::vector<CryGame::tEntityParams> m_lstEntities;
	std::vector<CryGame::tBrushParams> m_lstBrushes;
	std::vector<CryGame::tPrefabParams> m_lstPrefabs;

	void Load(XmlNodeRef& itemNode) { FLoad(this, itemNode); }
	void ExtractTransform(XmlNodeRef& objNode, Matrix34& mat) { FExtractTransform(this, objNode, mat); }
	bool ExtractBrushLoadParams(XmlNodeRef& objNode, CryGame::tBrushParams& loadParams) { return FExtractBrushLoadParams(this, objNode, loadParams); }
	bool ExtractDecalLoadParams(XmlNodeRef& objNode, CryGame::tBrushParams& loadParams) { return FExtractDecalLoadParams(this, objNode, loadParams); }
	bool ExtractDesignerLoadParams(XmlNodeRef& objNode, CryGame::tBrushParams& loadParams) { return FExtractDesignerLoadParams(this, objNode, loadParams); }

#if 0
	CPrefab(const string& _arg0_);
	CPrefab();
	~CPrefab();
	bool ExtractPrefabLoadParams(XmlNodeRef& _arg0_, CryGame::tPrefabParams& _arg1_);
	bool ExtractEntityLoadParams(XmlNodeRef& _arg0_, SEntitySpawnParams& _arg1_);
#endif

#ifndef MOONCRASH
	static inline auto FLoad = PreyFunction<void(CryGame::CPrefab* const _this, XmlNodeRef& itemNode)>(0x17C9920);
	static inline auto FExtractTransform = PreyFunction<void(CryGame::CPrefab* const _this, XmlNodeRef& objNode, Matrix34& mat)>(0x17C90D0);
	static inline auto FExtractBrushLoadParams = PreyFunction<bool(CryGame::CPrefab* const _this, XmlNodeRef& objNode, CryGame::tBrushParams& loadParams)>(0x17C8A00);
	static inline auto FExtractDecalLoadParams = PreyFunction<bool(CryGame::CPrefab* const _this, XmlNodeRef& objNode, CryGame::tBrushParams& loadParams)>(0x17C8C20);
	static inline auto FExtractDesignerLoadParams = PreyFunction<bool(CryGame::CPrefab* const _this, XmlNodeRef& objNode, CryGame::tBrushParams& loadParams)>(0x17C8DC0);
#else
	static inline auto FLoad = PreyFunction<void(CryGame::CPrefab* const _this, XmlNodeRef& itemNode)>(0x18F0C60);
	static inline auto FExtractTransform = PreyFunction<void(CryGame::CPrefab* const _this, XmlNodeRef& objNode, Matrix34& mat)>(0x18F0410);
	static inline auto FExtractBrushLoadParams = PreyFunction<bool(CryGame::CPrefab* const _this, XmlNodeRef& objNode, CryGame::tBrushParams& loadParams)>(0x18EFD40);
	static inline auto FExtractDecalLoadParams = PreyFunction<bool(CryGame::CPrefab* const _this, XmlNodeRef& objNode, CryGame::tBrushParams& loadParams)>(0x18EFF60);
	static inline auto FExtractDesignerLoadParams = PreyFunction<bool(CryGame::CPrefab* const _this, XmlNodeRef& objNode, CryGame::tBrushParams& loadParams)>(0x18F0100);
#endif
};

// CryGame::CPrefabManager
// Header:  Prey/GameDll/PrefabManager.h
class CPrefabManager
{ // Size=72 (0x48)
public:
	std::map<string, CryGame::CPrefabLib*> m_lstPrefabLibs;
	std::map<unsigned int, CryGame::CRuntimePrefab*> m_lstRuntimePrefabs;
	std::map<CryGame::CPrefab*, int> m_lstOccurrences;
	string m_sLastPrefab;
	string m_sCurrentGroup;

	CPrefabManager();
	virtual ~CPrefabManager();
	bool LoadPrefabLibrary(const string& sFilename) { return FLoadPrefabLibrary(this, sFilename); }
	void SpawnPrefab(const string& sLibraryFilename, const string& sFullName, unsigned id, unsigned nSeed, unsigned nMaxSpawn) { FSpawnPrefab(this, sLibraryFilename, sFullName, id, nSeed, nMaxSpawn); }
	void MovePrefab(unsigned id) { FMovePrefab(this, id); }
	void DeletePrefab(unsigned id) { FDeletePrefab(this, id); }
	void HidePrefab(unsigned id, bool bHide) { FHidePrefab(this, id, bHide); }
	void Clear(bool bDeleteLibs) { FClear(this, bDeleteLibs); }
	void CallOnSpawn(IEntity* pEntity, int nSeed) { FCallOnSpawn(this, pEntity, nSeed); }
	CryGame::CPrefab* FindPrefab(CryGame::CPrefabLib* pLib, const string& sFullName, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& i, bool bLoadIfNotFound) { return FFindPrefab(this, pLib, sFullName, i, bLoadIfNotFound); }
	void StripLibraryName(const string& sLibraryName, const string& sFullName, string& sResult, bool bApplyGroup) { FStripLibraryName(this, sLibraryName, sFullName, sResult, bApplyGroup); }
	CryGame::CPrefab* FindPrefabInGroup(CryGame::CPrefabLib* pLib, const string& sLibraryName, const string& sFullName, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& i) { return FFindPrefabInGroup(this, pLib, sLibraryName, sFullName, i); }

#if 0
	void SetPrefabGroup(const string& _arg0_);
	CryGame::CPrefab* GetPrefab(const string& _arg0_, const string& _arg1_);
	CryGame::CPrefab* GetRandomPrefab(CryGame::CPrefabLib* _arg0_, const std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& _arg1_, unsigned _arg2_);
#endif

#ifndef MOONCRASH
	static inline auto FCPrefabManagerOv1 = PreyFunction<void(CryGame::CPrefabManager* const _this)>(0x17C7C20);
	static inline auto FBitNotCPrefabManager = PreyFunction<void(CryGame::CPrefabManager* const _this)>(0x17C8220);
	static inline auto FLoadPrefabLibrary = PreyFunction<bool(CryGame::CPrefabManager* const _this, const string& sFilename)>(0x17CA2A0);
	static inline auto FSpawnPrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, const string& sLibraryFilename, const string& sFullName, unsigned id, unsigned nSeed, unsigned nMaxSpawn)>(0x17CA890);
	static inline auto FMovePrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, unsigned id)>(0x17CA840);
	static inline auto FDeletePrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, unsigned id)>(0x17C8920);
	static inline auto FHidePrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, unsigned id, bool bHide)>(0x17C98D0);
	static inline auto FClear = PreyFunction<void(CryGame::CPrefabManager* const _this, bool bDeleteLibs)>(0x17C85F0);
	static inline auto FCallOnSpawn = PreyFunction<void(CryGame::CPrefabManager* const _this, IEntity* pEntity, int nSeed)>(0x17C8460);
	static inline auto FFindPrefab = PreyFunction<CryGame::CPrefab* (CryGame::CPrefabManager* const _this, CryGame::CPrefabLib* pLib, const string& sFullName, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& i, bool bLoadIfNotFound)>(0x17C9380);
	static inline auto FStripLibraryName = PreyFunction<void(CryGame::CPrefabManager* const _this, const string& sLibraryName, const string& sFullName, string& sResult, bool bApplyGroup)>(0x17CAB00);
	static inline auto FFindPrefabInGroup = PreyFunction<CryGame::CPrefab* (CryGame::CPrefabManager* const _this, CryGame::CPrefabLib* pLib, const string& sLibraryName, const string& sFullName, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& i)>(0x17C9710);
#else
	static inline auto FCPrefabManagerOv1 = PreyFunction<void(CryGame::CPrefabManager* const _this)>(0x18EEF60);
	static inline auto FBitNotCPrefabManager = PreyFunction<void(CryGame::CPrefabManager* const _this)>(0x18EF560);
	static inline auto FLoadPrefabLibrary = PreyFunction<bool(CryGame::CPrefabManager* const _this, const string& sFilename)>(0x18F15E0);
	static inline auto FSpawnPrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, const string& sLibraryFilename, const string& sFullName, unsigned id, unsigned nSeed, unsigned nMaxSpawn)>(0x18F1BD0);
	static inline auto FMovePrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, unsigned id)>(0x18F1B80);
	static inline auto FDeletePrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, unsigned id)>(0x18EFC60);
	static inline auto FHidePrefab = PreyFunction<void(CryGame::CPrefabManager* const _this, unsigned id, bool bHide)>(0x18F0C10);
	static inline auto FClear = PreyFunction<void(CryGame::CPrefabManager* const _this, bool bDeleteLibs)>(0x18EF930);
	static inline auto FCallOnSpawn = PreyFunction<void(CryGame::CPrefabManager* const _this, IEntity* pEntity, int nSeed)>(0x18EF7A0);
	static inline auto FFindPrefab = PreyFunction<CryGame::CPrefab* (CryGame::CPrefabManager* const _this, CryGame::CPrefabLib* pLib, const string& sFullName, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& i, bool bLoadIfNotFound)>(0x18F06C0);
	static inline auto FStripLibraryName = PreyFunction<void(CryGame::CPrefabManager* const _this, const string& sLibraryName, const string& sFullName, string& sResult, bool bApplyGroup)>(0x18F1E40);
	static inline auto FFindPrefabInGroup = PreyFunction<CryGame::CPrefab* (CryGame::CPrefabManager* const _this, CryGame::CPrefabLib* pLib, const string& sLibraryName, const string& sFullName, std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CryGame::CPrefab *> > > >& i)>(0x18F0A50);
#endif
};


} // namespace CryGame

