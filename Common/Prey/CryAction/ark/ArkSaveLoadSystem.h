// Header file automatically created from a PDB.

#pragma once
#include <ChairLoader/pch.h>
#include <Prey/CryGame/IGame.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/CryAction/ark/IArkSaveLoadSystem.h>

class CFlowStartNode;
class CGameSerialize;
class CPlaySequence_Node;
class CPlayerProfileManager{
public:
    struct SSaveGameMetaData// Size=0x38 (Id=1850422)
    {
        class CryStringT<char> levelName;// Offset=0x0 Size=0x8
        class CryStringT<char> gameRules;// Offset=0x8 Size=0x8
        int fileVersion;// Offset=0x10 Size=0x4
        class CryStringT<char> buildVersion;// Offset=0x18 Size=0x8
        int saveTime;// Offset=0x20 Size=0x8
        int loadTime;// Offset=0x28 Size=0x8
        class XmlNodeRef xmlMetaDataNode;// Offset=0x30 Size=0x8
    };
    struct SThumbnail// Size=0x18 (Id=1850323)
    {
        struct DynArray<unsigned char,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > data;// Offset=0x0 Size=0x8
        int width;// Offset=0x8 Size=0x4
        int height;// Offset=0xc Size=0x4
        int depth;// Offset=0x10 Size=0x4
    };
    struct SSaveGameInfo// Size=0x40 (Id=1850424)
    {
        class CryStringT<char> name;// Offset=0x0 Size=0x8
        class CryStringT<char> humanName;// Offset=0x8 Size=0x8
        class CryStringT<char> description;// Offset=0x10 Size=0x8
        class std::shared_ptr<CPlayerProfileManager::SSaveGameMetaData> pMetadata;// Offset=0x18 Size=0x10
        struct CPlayerProfileManager::SThumbnail thumbnail;// Offset=0x28 Size=0x18
    };
    char NOTFINISHED[0xc210];
};
class IArkSaveLoadListener;
class ICrySizer;
struct IEntity;
class IGeneralMemoryHeap;
struct SBasicEntityData;

// Header: Exact
// CryEngine/cryaction/ark/ArkSaveLoadSystem.h
class ArkSaveLoadSystem : public IArkSaveLoadSystem // Id=8005021 Size=320
{
public:
	std::vector<CFlowStartNode *> m_startNodes;
	std::vector<CPlaySequence_Node *> m_trackViewNodes;
	std::vector<IArkSaveLoadListener *> m_listeners;
	std::array<std::unordered_map<string,CPlayerProfileManager::SSaveGameMetaData,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,CPlayerProfileManager::SSaveGameMetaData>>>,3> m_cachedMetadata;
	
	struct LevelOriginInfo // Id=8005123 Size=24
	{
		string originalLevelName;
		unsigned originalId;
		unsigned currentId;
		bool originallyUnremovable;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkSaveLoadSystem::LevelOriginInfo> m_levelOrigins;
	XmlNodeRef m_captureVolumeStates;
	int m_campaignSlot;
	int m_newGameSlot;
	bool m_bNeedToRestoreLevelState;
	bool m_bRestoringLevelState;
	
	ArkSaveLoadSystem();
	void RequestLevelStateRestore() { FRequestLevelStateRestore(this); }
	void LoadCurrentLevelState(CGameSerialize &_gameSerialize) { FLoadCurrentLevelState(this,_gameSerialize); }
	virtual bool InLevelTransition() const;
	virtual bool IsRestoringLevelState() const;
	void RegisterStartNode(CFlowStartNode &_node) { FRegisterStartNode(this,_node); }
	void UnregisterStartNode(CFlowStartNode &_node) { FUnregisterStartNode(this,_node); }
	void SerializePersistentState(TSerialize _serialize) { FSerializePersistentState(this,_serialize); }
	virtual void SetCampaignSlot(const int _slot);
	virtual int GetCampaignSlot() const;
	void SaveCurrentLevelState(CGameSerialize &_gameSerialize) { FSaveCurrentLevelState(this,_gameSerialize); }
	virtual void RegisterListener(IArkSaveLoadListener *_pListener);
	virtual void UnregisterListener(IArkSaveLoadListener *_pListener);
	void SetMetadata(string const &_saveName, CPlayerProfileManager::SSaveGameMetaData &_data) { FSetMetadata(this,_saveName,_data); }
	virtual void SaveNewGamePlusData(int _campaignSlot, Functor1<TSerialize> _gameFunction);
	virtual bool LoadNewGamePlusData(int _campaignSlot, Functor1<TSerialize> _gameFunction);
	void SetLevelOrigin(SBasicEntityData &_bed, IEntity const &_entity) const { FSetLevelOrigin(this,_bed,_entity); }
	boost::optional<CPlayerProfileManager::SSaveGameMetaData> GetMetadata(string const &_saveName) const { return FGetMetadata(this,_saveName); }
	virtual void ClearMetadataCache();
	
#if 0
	int GetNewGameSlot() const;
	void RegisterTrackViewNode(CPlaySequence_Node &arg0);
	void UnregisterTrackViewNode(CPlaySequence_Node &arg0);
	void DeleteMetadata(string const &arg0);
	static XmlNodeRef GetCaptureVolumeStates();
#endif
	
	static inline auto FRequestLevelStateRestore = PreyFunction<void(ArkSaveLoadSystem *const _this)>(0x2AE870);
	static inline auto FLoadCurrentLevelState = PreyFunction<void(ArkSaveLoadSystem *const _this, CGameSerialize &_gameSerialize)>(0x2ADAF0);
	static inline auto FInLevelTransition = PreyFunction<bool(ArkSaveLoadSystem const *const _this)>(0x2AD940);
	static inline auto FIsRestoringLevelState = PreyFunction<bool(ArkSaveLoadSystem const *const _this)>(0x2ADAE0);
	static inline auto FRegisterStartNode = PreyFunction<void(ArkSaveLoadSystem *const _this, CFlowStartNode &_node)>(0x2AE850);
	static inline auto FUnregisterStartNode = PreyFunction<void(ArkSaveLoadSystem *const _this, CFlowStartNode &_node)>(0x1484970);
	static inline auto FSerializePersistentState = PreyFunction<void(ArkSaveLoadSystem *const _this, TSerialize _serialize)>(0x2AF8C0);
	static inline auto FSetCampaignSlot = PreyFunction<void(ArkSaveLoadSystem *const _this, const int _slot)>(0x2AF910);
	static inline auto FGetCampaignSlot = PreyFunction<int(ArkSaveLoadSystem const *const _this)>(0xE024C0);
	static inline auto FSaveCurrentLevelState = PreyFunction<void(ArkSaveLoadSystem *const _this, CGameSerialize &_gameSerialize)>(0x2AE880);
	static inline auto FRegisterListener = PreyFunction<void(ArkSaveLoadSystem *const _this, IArkSaveLoadListener *_pListener)>(0x2AE800);
	static inline auto FUnregisterListener = PreyFunction<void(ArkSaveLoadSystem *const _this, IArkSaveLoadListener *_pListener)>(0x2AFA40);
	static inline auto FSetMetadata = PreyFunction<void(ArkSaveLoadSystem *const _this, string const &_saveName, CPlayerProfileManager::SSaveGameMetaData &_data)>(0x4C6420);
	static inline auto FSaveNewGamePlusData = PreyFunction<void(ArkSaveLoadSystem *const _this, int _campaignSlot, Functor1<TSerialize> _gameFunction)>(0x2AEFA0);
	static inline auto FLoadNewGamePlusData = PreyFunction<bool(ArkSaveLoadSystem *const _this, int _campaignSlot, Functor1<TSerialize> _gameFunction)>(0x2AE310);
	static inline auto FSetLevelOrigin = PreyFunction<void(ArkSaveLoadSystem const *const _this, SBasicEntityData &_bed, IEntity const &_entity)>(0x2AF920);
	static inline auto FGetMetadata = PreyFunction<boost::optional<CPlayerProfileManager::SSaveGameMetaData>(ArkSaveLoadSystem const *const _this, string const &_saveName)>(0x52E3D0);
	static inline auto FClearMetadataCache = PreyFunction<void(ArkSaveLoadSystem *const _this)>(0x2AD530);
};

class CXmlSerializeHelper;

// Header: FromCpp
// CryEngine/cryaction/ark/arksaveloadsystem.h
class Save : public ISaveGame // Id=800598F Size=48
{
public:
	XmlNodeRef m_root;
	XmlNodeRef m_parentNode;
	
	using TContexts = std::vector<_smart_ptr<CXmlSerializeHelper>>;
	
	std::vector<_smart_ptr<CXmlSerializeHelper>> m_sections;
	
	virtual bool Init(const char *_pName);
	virtual void AddMetadata(const char *_pTag, const char *_pValue);
	virtual void AddMetadata(const char *_pTag, int _value);
	virtual XmlNodeRef GetMetadata() const;
	virtual TSerialize AddSection(const char *_pSection);
	virtual uint8_t *SetThumbnail(const uint8_t *_pImageData, int _width, int _height, int _depth);
	virtual bool SetThumbnailFromBMP(const char *_pFilename);
	virtual bool Complete(bool _bSuccessfulSoFar);
	virtual const char *GetFileName() const;
	virtual void SetSaveGameReason(ESaveGameReason _reason);
	virtual ESaveGameReason GetSaveGameReason() const;
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
	virtual ~Save();
	
	static inline auto FInit = PreyFunction<bool(Save *const _this, const char *_pName)>(0x2AD9D0);
	static inline auto FAddMetadataOv1 = PreyFunction<void(Save *const _this, const char *_pTag, const char *_pValue)>(0xA13080);
	static inline auto FAddMetadataOv0 = PreyFunction<void(Save *const _this, const char *_pTag, int _value)>(0x2AD410);
	static inline auto FGetMetadata = PreyFunction<XmlNodeRef(Save const *const _this)>(0x13883F0);
	static inline auto FAddSection = PreyFunction<TSerialize(Save *const _this, const char *_pSection)>(0x2AD470);
	static inline auto FSetThumbnail = PreyFunction<uint8_t *(Save *const _this, const uint8_t *_pImageData, int _width, int _height, int _depth)>(0x158AEF0);
	static inline auto FSetThumbnailFromBMP = PreyFunction<bool(Save *const _this, const char *_pFilename)>(0xDD23F0);
	static inline auto FComplete = PreyFunction<bool(Save *const _this, bool _bSuccessfulSoFar)>(0x2AD580);
	static inline auto FGetFileName = PreyFunction<const char *(Save const *const _this)>(0x158AEF0);
	static inline auto FSetSaveGameReason = PreyFunction<void(Save *const _this, ESaveGameReason _reason)>(0xA13080);
	static inline auto FGetSaveGameReason = PreyFunction<ESaveGameReason(Save const *const _this)>(0x1A42CE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(Save const *const _this, ICrySizer *_pSizer)>(0x2AD770);
};

// Header: FromCpp
// CryEngine/cryaction/ark/arksaveloadsystem.h
class Load : public ILoadGame // Id=8005990 Size=40
{
public:
	XmlNodeRef m_root;
	
	using TContexts = std::vector<_smart_ptr<CXmlSerializeHelper>>;
	
	std::vector<_smart_ptr<CXmlSerializeHelper>> m_sections;
	
	virtual bool Init(const char *const _pName);
	virtual unsigned GetPlatformUserId() const;
	virtual IGeneralMemoryHeap *GetHeap();
	virtual const char *GetMetadata(const char *_pTag);
	virtual bool GetMetadata(const char *_pTag, int &_value);
	virtual bool HaveMetadata(const char *_pTag);
	virtual std::unique_ptr<TSerialize> GetSection(const char *_pSection);
	virtual bool HaveSection(const char *_pSection);
	virtual void Complete();
	virtual const char *GetFileName() const;
	virtual ~Load();
	
	static inline auto FInit = PreyFunction<bool(Load *const _this, const char *const _pName)>(0x2AD950);
	static inline auto FGetPlatformUserId = PreyFunction<unsigned(Load const *const _this)>(0xA38740);
	static inline auto FGetHeap = PreyFunction<IGeneralMemoryHeap *(Load *const _this)>(0x158AEF0);
	static inline auto FGetMetadataOv1 = PreyFunction<const char *(Load *const _this, const char *_pTag)>(0x158AEF0);
	static inline auto FGetMetadataOv0 = PreyFunction<bool(Load *const _this, const char *_pTag, int &_value)>(0x2AD7C0);
	static inline auto FHaveMetadata = PreyFunction<bool(Load *const _this, const char *_pTag)>(0x1B933B0);
	static inline auto FGetSection = PreyFunction<std::unique_ptr<TSerialize>(Load *const _this, const char *_pSection)>(0x2AD830);
	static inline auto FHaveSection = PreyFunction<bool(Load *const _this, const char *_pSection)>(0x2AD900);
	static inline auto FComplete = PreyFunction<void(Load *const _this)>(0xA97D40);
	static inline auto FGetFileName = PreyFunction<const char *(Load const *const _this)>(0x158AEF0);
};

