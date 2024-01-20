// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CrySystem/TimeValue.h>

struct IConsoleCmdArgs;
class ICrySizer;
struct ILevel;
struct ILevelRotationFile;
struct ILevelSystemListener;
struct ISystem;
class XmlNodeRef;

// CLevelInfo
// Header:  CryEngine/cryaction/LevelSystem.h
// Include: Prey/CryAction/LevelSystem.h
class CLevelInfo : public ILevelInfo
{ // Size=240 (0xF0)
public:
	using TAttributeList = std::map<string, TFlowInputData, stl::less_stricmp<CryStringT<char>>>;
	
	string m_levelName;
	string m_levelPath;
	string m_levelPaks;
	string m_levelDisplayName;
	string m_previewImagePath;
	string m_backgroundImagePath;
	string m_minimapImagePath;
	string m_levelPakFullPath;
	string m_levelMMPakFullPath;
	std::vector<string> m_levelDataPakFullPaths;
	std::vector<string> m_gamerules;
	int m_heightmapSize;
	unsigned m_scanTag;
	unsigned m_levelTag;
	bool m_bMetaDataRead;
	bool m_bIsTalosExterior;
	std::vector<ILevelInfo::TGameTypeInfo> m_gameTypes;
	bool m_isModLevel;
	ILevelInfo::SMinimapInfo m_minimapInfo;
	std::map<string, TFlowInputData, stl::less_stricmp<CryStringT<char>>> m_levelAttributes;
	DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_levelTypeList;
	
	virtual const char* GetName() const;
	virtual const bool IsOfType(const char* sType) const;
	virtual const char* GetPath() const;
	virtual const char* GetPaks() const;
	virtual bool GetIsModLevel() const;
	virtual const unsigned GetScanTag() const;
	virtual const unsigned GetLevelTag() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetPreviewImagePath() const;
	virtual const char* GetBackgroundImagePath() const;
	virtual const char* GetMinimapImagePath() const;
	virtual int GetHeightmapSize() const;
	virtual const bool MetadataLoaded() const;
	virtual const bool IsTalosExterior() const;
	virtual int GetGameTypeCount() const;
	virtual const ILevelInfo::TGameTypeInfo* GetGameType(int gameType) const;
	virtual bool SupportsGameType(const char* gameTypeName) const;
	virtual const ILevelInfo::TGameTypeInfo* GetDefaultGameType() const;
	virtual bool HasGameRules() const;
	virtual const ILevelInfo::SMinimapInfo& GetMinimapInfo() const;
	virtual const char* GetDefaultGameRules() const;
	virtual std::vector<string> GetGameRules() const;
	virtual bool GetAttribute(const char* name, TFlowInputData& val) const;
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	void ReadMetaData() { FReadMetaData(this); }
	bool ReadInfo() { return FReadInfo(this); }
	bool OpenLevelPak() { return FOpenLevelPak(this); }
	void CloseLevelPak() { FCloseLevelPak(this); }
	
#if 0
	CLevelInfo();
#endif
	
	static inline auto FGetName = PreyFunction<const char* (const CLevelInfo* const _this)>(0x12AAC70);
	static inline auto FIsOfType = PreyFunction<const bool(const CLevelInfo* const _this, const char* sType)>(0x354D00);
	static inline auto FGetPath = PreyFunction<const char* (const CLevelInfo* const _this)>(0x5BFB50);
	static inline auto FGetPaks = PreyFunction<const char* (const CLevelInfo* const _this)>(0xD87500);
	static inline auto FGetIsModLevel = PreyFunction<bool(const CLevelInfo* const _this)>(0x350260);
	static inline auto FGetScanTag = PreyFunction<const unsigned(const CLevelInfo* const _this)>(0x350270);
	static inline auto FGetLevelTag = PreyFunction<const unsigned(const CLevelInfo* const _this)>(0xF48A0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CLevelInfo* const _this)>(0x1140FE0);
	static inline auto FGetPreviewImagePath = PreyFunction<const char* (const CLevelInfo* const _this)>(0xD87510);
	static inline auto FGetBackgroundImagePath = PreyFunction<const char* (const CLevelInfo* const _this)>(0x862100);
	static inline auto FGetMinimapImagePath = PreyFunction<const char* (const CLevelInfo* const _this)>(0x864AF0);
	static inline auto FGetHeightmapSize = PreyFunction<int(const CLevelInfo* const _this)>(0xE5EFE0);
	static inline auto FMetadataLoaded = PreyFunction<const bool(const CLevelInfo* const _this)>(0x3502A0);
	static inline auto FIsTalosExterior = PreyFunction<const bool(const CLevelInfo* const _this)>(0x350290);
	static inline auto FGetGameTypeCount = PreyFunction<int(const CLevelInfo* const _this)>(0x350230);
	static inline auto FGetGameType = PreyFunction<const ILevelInfo::TGameTypeInfo* (const CLevelInfo* const _this, int gameType)>(0x350210);
	static inline auto FSupportsGameType = PreyFunction<bool(const CLevelInfo* const _this, const char* gameTypeName)>(0x35A0B0);
	static inline auto FGetDefaultGameType = PreyFunction<const ILevelInfo::TGameTypeInfo* (const CLevelInfo* const _this)>(0x354260);
	static inline auto FHasGameRules = PreyFunction<bool(const CLevelInfo* const _this)>(0x350280);
	static inline auto FGetMinimapInfo = PreyFunction<const ILevelInfo::SMinimapInfo& (const CLevelInfo* const _this)>(0x10BDA60);
	static inline auto FGetDefaultGameRules = PreyFunction<const char* (const CLevelInfo* const _this)>(0x3501D0);
	static inline auto FGetGameRules = PreyFunction<std::vector<string>*(const CLevelInfo* const _this, std::vector<string>* _return_value_)>(0x3501F0);
	static inline auto FGetAttribute = PreyFunction<bool(const CLevelInfo* const _this, const char* name, TFlowInputData& val)>(0x354130);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CLevelInfo* const _this, ICrySizer* pSizer)>(0x354710);
	static inline auto FReadMetaData = PreyFunction<void(CLevelInfo* const _this)>(0x358090);
	static inline auto FReadInfo = PreyFunction<bool(CLevelInfo* const _this)>(0x357A70);
	static inline auto FOpenLevelPak = PreyFunction<bool(CLevelInfo* const _this)>(0x357320);
	static inline auto FCloseLevelPak = PreyFunction<void(CLevelInfo* const _this)>(0x353EF0);
};

// CLevelRotation
// Header:  CryEngine/cryaction/LevelSystem.h
// Include: Prey/CryAction/LevelSystem.h
class CLevelRotation : public ILevelRotation
{ // Size=80 (0x50)
public:
	// CLevelRotation::SLevelRotationEntry
	// Header:  CryEngine/cryaction/LevelSystem.h
	struct SLevelRotationEntry
	{ // Size=64 (0x40)
		string levelName;
		std::vector<string> gameRulesNames;
		std::vector<int> gameRulesShuffle;
		int currentModeIndex;
		
	#if 0
		const char* GameModeName() const;
	#endif
	};
	
	using TLevelRotationVector = std::vector<CLevelRotation::SLevelRotationEntry>;
	
	std::vector<CLevelRotation::SLevelRotationEntry> m_rotation;
	uint8_t m_randFlags;
	int m_next;
	std::vector<unsigned int> m_shuffle;
	int m_advancesTaken;
	unsigned m_extInfoId;
	bool m_hasGameModesDecks;
	
	virtual ~CLevelRotation();
	virtual bool Load(ILevelRotationFile* file);
	virtual bool LoadFromXmlRootNode(const XmlNodeRef rootNode, const char* altRootTag);
	virtual void Reset();
	virtual int AddLevel(const char* level);
	virtual int AddLevel(const char* level, const char* gameMode);
	virtual void AddGameMode(int level, const char* gameMode);
	void AddGameMode(CLevelRotation::SLevelRotationEntry& level, const char* gameMode) { FAddGameModeOv0(this, level, gameMode); }
	virtual void Initialise(int nSeed);
	virtual bool First();
	virtual bool Advance();
	virtual bool AdvanceAndLoopIfNeeded();
	virtual const char* GetNextLevel() const;
	virtual const char* GetNextGameRules() const;
	virtual const char* GetLevel(unsigned idx, bool accessShuffled) const;
	virtual int GetNGameRulesForEntry(unsigned idx, bool accessShuffled) const;
	virtual const char* GetGameRules(unsigned idx, unsigned iMode, bool accessShuffled) const;
	virtual const char* GetNextGameRulesForEntry(int idx) const;
	virtual const int NumAdvancesTaken() const;
	virtual void ResetAdvancement();
	virtual int GetLength() const;
	virtual int GetTotalGameModeEntries() const;
	virtual int GetNext() const;
	virtual void ChangeLevel(IConsoleCmdArgs* pArgs);
	virtual bool NextPairMatch() const;
	virtual uint8_t GetRandomisationFlags() const;
	virtual void SetRandomisationFlags(uint8_t randMode);
	virtual bool IsRandom() const;
	void ShallowShuffle() { FShallowShuffle(this); }
	void AddLevelFromNode(const char* levelName, XmlNodeRef& levelNode) { FAddLevelFromNode(this, levelName, levelNode); }
	
#if 0
	CLevelRotation();
	void SetExtendedInfoId(const unsigned _arg0_);
	unsigned GetExtendedInfoId();
	void ModeShuffle();
	int GetRealRotationIndex(unsigned _arg0_, bool _arg1_) const;
#endif
	
	static inline auto FLoad = PreyFunction<bool(CLevelRotation* const _this, ILevelRotationFile* file)>(0x354D70);
	static inline auto FLoadFromXmlRootNode = PreyFunction<bool(CLevelRotation* const _this, const XmlNodeRef rootNode, const char* altRootTag)>(0x354DB0);
	static inline auto FReset = PreyFunction<void(CLevelRotation* const _this)>(0x359000);
	static inline auto FAddLevelOv1 = PreyFunction<int(CLevelRotation* const _this, const char* level)>(0x3536F0);
	static inline auto FAddLevelOv0 = PreyFunction<int(CLevelRotation* const _this, const char* level, const char* gameMode)>(0x3536B0);
	static inline auto FAddGameModeOv1 = PreyFunction<void(CLevelRotation* const _this, int level, const char* gameMode)>(0x3536A0);
	static inline auto FAddGameModeOv0 = PreyFunction<void(CLevelRotation* const _this, CLevelRotation::SLevelRotationEntry& level, const char* gameMode)>(0x353580);
	static inline auto FInitialise = PreyFunction<void(CLevelRotation* const _this, int nSeed)>(0x354B90);
	static inline auto FFirst = PreyFunction<bool(CLevelRotation* const _this)>(0x354110);
	static inline auto FAdvance = PreyFunction<bool(CLevelRotation* const _this)>(0x353940);
	static inline auto FAdvanceAndLoopIfNeeded = PreyFunction<bool(CLevelRotation* const _this)>(0x3539C0);
	static inline auto FGetNextLevel = PreyFunction<const char* (const CLevelRotation* const _this)>(0x354AA0);
	static inline auto FGetNextGameRules = PreyFunction<const char* (const CLevelRotation* const _this)>(0x3549C0);
	static inline auto FGetLevel = PreyFunction<const char* (const CLevelRotation* const _this, unsigned idx, bool accessShuffled)>(0x354300);
	static inline auto FGetNGameRulesForEntry = PreyFunction<int(const CLevelRotation* const _this, unsigned idx, bool accessShuffled)>(0x354970);
	static inline auto FGetGameRules = PreyFunction<const char* (const CLevelRotation* const _this, unsigned idx, unsigned iMode, bool accessShuffled)>(0x354280);
	static inline auto FGetNextGameRulesForEntry = PreyFunction<const char* (const CLevelRotation* const _this, int idx)>(0x354A30);
	static inline auto FNumAdvancesTaken = PreyFunction<const int(const CLevelRotation* const _this)>(0xE79B70);
	static inline auto FResetAdvancement = PreyFunction<void(CLevelRotation* const _this)>(0x359050);
	static inline auto FGetLength = PreyFunction<int(const CLevelRotation* const _this)>(0x3542F0);
	static inline auto FGetTotalGameModeEntries = PreyFunction<int(const CLevelRotation* const _this)>(0x354AF0);
	static inline auto FGetNext = PreyFunction<int(const CLevelRotation* const _this)>(0xEB9170);
	static inline auto FChangeLevel = PreyFunction<void(CLevelRotation* const _this, IConsoleCmdArgs* pArgs)>(0x353A00);
	static inline auto FNextPairMatch = PreyFunction<bool(const CLevelRotation* const _this)>(0x356930);
	static inline auto FGetRandomisationFlags = PreyFunction<uint8_t(const CLevelRotation* const _this)>(0x354AE0);
	static inline auto FSetRandomisationFlags = PreyFunction<void(CLevelRotation* const _this, uint8_t randMode)>(0x359F20);
	static inline auto FIsRandom = PreyFunction<bool(const CLevelRotation* const _this)>(0x354D60);
	static inline auto FShallowShuffle = PreyFunction<void(CLevelRotation* const _this)>(0x359F30);
	static inline auto FAddLevelFromNode = PreyFunction<void(CLevelRotation* const _this, const char* levelName, XmlNodeRef& levelNode)>(0x3537C0);
};

// CLevelSystem
// Header:  CryEngine/cryaction/LevelSystem.h
// Include: Prey/CryAction/LevelSystem.h
class CLevelSystem : public ILevelSystem, public ISystem::ILoadingProgressListener
{ // Size=256 (0x100)
public:
	enum class ArkLoadingProgress
	{
		start = 0,
		initialized = 1,
		engine_50 = 2,
		engine_75 = 3,
		engine_done = 4,
		texture_precache = 5,
		done = 6,
	};
	
	using TExtendedLevelRotations = std::vector<CLevelRotation>;
	
	ISystem* m_pSystem;
	std::vector<CLevelInfo> m_levelInfos;
	string m_levelsFolder;
	ILevel* m_pCurrentLevel;
	ILevelInfo* m_pLoadingLevelInfo;
	std::vector<CLevelRotation> m_extLevelRotations;
	CLevelRotation m_levelRotation;
	string m_lastLevelName;
	float m_fLastLevelLoadTime;
	float m_fFilteredProgress;
	float m_fLastTime;
	bool m_bLevelLoaded;
	bool m_bRecordingFileOpens;
	int m_nLoadedLevelsCount;
	CTimeValue m_levelLoadStartTime;
	CLevelSystem::ArkLoadingProgress m_levelLoadProgress;
	static inline auto s_loadCount = PreyGlobal<int>(0x247EB08);
	std::vector<ILevelSystemListener*> m_listeners;
	DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_levelTypeList;
	
	CLevelSystem(ISystem* pSystem, const char* levelsFolder);
	virtual ~CLevelSystem();
	virtual DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >* GetLevelTypeList();
	virtual void Rescan(const char* levelsFolder, const unsigned tag);
	virtual void LoadRotation();
	virtual int GetLevelCount();
	virtual ILevelInfo* GetLevelInfo(int level);
	virtual ILevelInfo* GetLevelInfo(const char* levelName);
	virtual void AddListener(ILevelSystemListener* pListener);
	virtual void RemoveListener(ILevelSystemListener* pListener);
	virtual ILevel* GetCurrentLevel() const;
	virtual ILevel* LoadLevel(const char* _levelName);
	virtual void UnLoadLevel();
	virtual ILevel* SetEditorLoadedLevel(const char* levelName, bool bReadLevelInfoMetaData);
	virtual void PrepareNextLevel(const char* levelName);
	virtual float GetLastLevelLoadTime();
	virtual bool IsLevelLoaded();
	virtual ILevelRotation* GetLevelRotation();
	virtual ILevelRotation* FindLevelRotationForExtInfoId(const unsigned findId);
	virtual bool AddExtendedLevelRotationFromXmlRootNode(const XmlNodeRef rootNode, const char* altRootTag, const unsigned extInfoId);
	virtual void ClearExtendedLevelRotations();
	virtual ILevelRotation* CreateNewRotation(const unsigned id);
	virtual void OnLoadingProgress(int steps);
	virtual void OnLoadingProgress(ILevelInfo* pLevel, int progressAmount);
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	virtual void OnLevelNotFound(const char* levelName);
	virtual void OnLoadingStart(ILevelInfo* pLevelInfo);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo* pLevelInfo);
	virtual void OnLoadingComplete(ILevel* pLevelInfo);
	virtual void OnLoadingError(ILevelInfo* pLevelInfo, const char* error);
	virtual void OnUnloadComplete(ILevel* pLevel);
	void ScanFolder(const char* subfolder, bool modFolder, const unsigned tag) { FScanFolder(this, subfolder, modFolder, tag); }
	void LogLoadingTime() { FLogLoadingTime(this); }
	void SetProgressBar(CLevelSystem::ArkLoadingProgress _progress) { FSetProgressBar(this, _progress); }
	CLevelInfo* GetLevelInfoInternal(const char* levelName) { return FGetLevelInfoInternalOv0(this, levelName); }
	
#if 0
	void Release();
	void SaveOpenedFilesList();
	string& UnifyName(string& _arg0_);
	bool LoadLevelInfo(CLevelInfo& _arg0_);
	CLevelInfo* GetLevelInfoInternal(int _arg0_);
#endif
	
	static inline auto FCLevelSystemOv1 = PreyFunction<void(CLevelSystem* const _this, ISystem* pSystem, const char* levelsFolder)>(0x3529E0);
	static inline auto FGetLevelTypeList = PreyFunction<DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >* (CLevelSystem* const _this)>(0x10BD940);
	static inline auto FRescan = PreyFunction<void(CLevelSystem* const _this, const char* levelsFolder, const unsigned tag)>(0x358CD0);
	static inline auto FLoadRotation = PreyFunction<void(CLevelSystem* const _this)>(0x356620);
	static inline auto FGetLevelCount = PreyFunction<int(CLevelSystem* const _this)>(0x354340);
	static inline auto FGetLevelInfoOv1 = PreyFunction<ILevelInfo* (CLevelSystem* const _this, int level)>(0x354370);
	static inline auto FGetLevelInfoOv0 = PreyFunction<ILevelInfo* (CLevelSystem* const _this, const char* levelName)>(0x3543C0);
	static inline auto FAddListener = PreyFunction<void(CLevelSystem* const _this, ILevelSystemListener* pListener)>(0x3538D0);
	static inline auto FRemoveListener = PreyFunction<void(CLevelSystem* const _this, ILevelSystemListener* pListener)>(0x358C60);
	static inline auto FGetCurrentLevel = PreyFunction<ILevel* (const CLevelSystem* const _this)>(0x864AF0);
	static inline auto FLoadLevel = PreyFunction<ILevel* (CLevelSystem* const _this, const char* _levelName)>(0x355040);
	static inline auto FUnLoadLevel = PreyFunction<void(CLevelSystem* const _this)>(0x35A130);
	static inline auto FSetEditorLoadedLevel = PreyFunction<ILevel* (CLevelSystem* const _this, const char* levelName, bool bReadLevelInfoMetaData)>(0x359CC0);
	static inline auto FPrepareNextLevel = PreyFunction<void(CLevelSystem* const _this, const char* levelName)>(0x357960);
	static inline auto FGetLastLevelLoadTime = PreyFunction<float(CLevelSystem* const _this)>(0x4E4250);
	static inline auto FIsLevelLoaded = PreyFunction<bool(CLevelSystem* const _this)>(0x1A3B3E0);
	static inline auto FGetLevelRotation = PreyFunction<ILevelRotation* (CLevelSystem* const _this)>(0x10BD9E0);
	static inline auto FFindLevelRotationForExtInfoId = PreyFunction<ILevelRotation* (CLevelSystem* const _this, const unsigned findId)>(0x3540E0);
	static inline auto FAddExtendedLevelRotationFromXmlRootNode = PreyFunction<bool(CLevelSystem* const _this, const XmlNodeRef rootNode, const char* altRootTag, const unsigned extInfoId)>(0x3533F0);
	static inline auto FClearExtendedLevelRotations = PreyFunction<void(CLevelSystem* const _this)>(0x353E90);
	static inline auto FCreateNewRotation = PreyFunction<ILevelRotation* (CLevelSystem* const _this, const unsigned id)>(0x354020);
	static inline auto FOnLoadingProgressOv1 = PreyFunction<void(ISystem::ILoadingProgressListener* const _this, int steps)>(0x356F30);
	static inline auto FOnLoadingProgressOv0 = PreyFunction<void(CLevelSystem* const _this, ILevelInfo* pLevel, int progressAmount)>(0x356EC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CLevelSystem* const _this, ICrySizer* pSizer)>(0x354840);
	static inline auto FOnLevelNotFound = PreyFunction<void(CLevelSystem* const _this, const char* levelName)>(0x356A90);
	static inline auto FOnLoadingStart = PreyFunction<void(CLevelSystem* const _this, ILevelInfo* pLevelInfo)>(0x357200);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(CLevelSystem* const _this, ILevelInfo* pLevelInfo)>(0x356E60);
	static inline auto FOnLoadingComplete = PreyFunction<void(CLevelSystem* const _this, ILevel* pLevelInfo)>(0x356AF0);
	static inline auto FOnLoadingError = PreyFunction<void(CLevelSystem* const _this, ILevelInfo* pLevelInfo, const char* error)>(0x356DB0);
	static inline auto FOnUnloadComplete = PreyFunction<void(CLevelSystem* const _this, ILevel* pLevel)>(0x3572C0);
	static inline auto FScanFolder = PreyFunction<void(CLevelSystem* const _this, const char* subfolder, bool modFolder, const unsigned tag)>(0x3590A0);
	static inline auto FLogLoadingTime = PreyFunction<void(CLevelSystem* const _this)>(0x356720);
	static inline auto FSetProgressBar = PreyFunction<void(CLevelSystem* const _this, CLevelSystem::ArkLoadingProgress _progress)>(0x359DB0);
	static inline auto FGetLevelInfoInternalOv0 = PreyFunction<CLevelInfo* (CLevelSystem* const _this, const char* levelName)>(0x3543D0);
};


