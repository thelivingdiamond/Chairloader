// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
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
	std::array<std::unordered_map<std::string,CPlayerProfileManager::SSaveGameMetaData>,3> m_cachedMetadata;
	
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
	
	ArkSaveLoadSystem() = default;
	void RequestLevelStateRestore() { FRequestLevelStateRestore(this); }
	void LoadCurrentLevelState(CGameSerialize &_gameSerialize) { FLoadCurrentLevelState(this,_gameSerialize); }
	virtual bool InLevelTransition() const { return FInLevelTransition(this); }
	virtual bool IsRestoringLevelState() const { return FIsRestoringLevelState(this); }
	void RegisterStartNode(CFlowStartNode &_node) { FRegisterStartNode(this,_node); }
	void UnregisterStartNode(CFlowStartNode &_node) { FUnregisterStartNode(this,_node); }
	void SerializePersistentState(TSerialize _serialize) { FSerializePersistentState(this,_serialize); }
	virtual void SetCampaignSlot(const int _slot) { FSetCampaignSlot(this,_slot); }
	virtual int GetCampaignSlot() const { return FGetCampaignSlot(this); }
	void SaveCurrentLevelState(CGameSerialize &_gameSerialize) { FSaveCurrentLevelState(this,_gameSerialize); }
	virtual void RegisterListener(IArkSaveLoadListener *_pListener) { FRegisterListener(this,_pListener); }
	virtual void UnregisterListener(IArkSaveLoadListener *_pListener) { FUnregisterListener(this,_pListener); }
	void SetMetadata(string const &_saveName, CPlayerProfileManager::SSaveGameMetaData &_data) { FSetMetadata(this,_saveName,_data); }
	virtual void SaveNewGamePlusData(int _campaignSlot, Functor1<TSerialize> _gameFunction) { FSaveNewGamePlusData(this,_campaignSlot,_gameFunction); }
	virtual bool LoadNewGamePlusData(int _campaignSlot, Functor1<TSerialize> _gameFunction) { return FLoadNewGamePlusData(this,_campaignSlot,_gameFunction); }
	void SetLevelOrigin(SBasicEntityData &_bed, IEntity const &_entity) const { FSetLevelOrigin(this,_bed,_entity); }
	boost::optional<CPlayerProfileManager::SSaveGameMetaData> GetMetadata(string const &_saveName) const { return FGetMetadata(this,_saveName); }
	virtual void ClearMetadataCache() { FClearMetadataCache(this); }
	
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/playerprofiles/PlayerProfileManager.h>
#include <Prey/CryAction/ILoadGame.h>
#include <Prey/CryAction/ISaveGame.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <_unknown/IArkSaveLoadSystem.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class CArkFlowNodeOnSaveLoaded;
class CFlowStartNode;
class CGameSerialize;
class CPlaySequence_Node;
class CXmlSerializeHelper;
enum ESaveGameReason;
class IArkSaveLoadListener;
class ICrySizer;
struct IEntity;
class IGeneralMemoryHeap;
struct SBasicEntityData;
struct SFlowNodeConfig;
struct SLoadEnvironment;

// ArkFlowNodeResetLevel
// Header:  CryEngine/cryaction/ark/ArkSaveLoadSystem.h
class ArkFlowNodeResetLevel : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		reset = 0,
		name = 1,
	};

	enum class EOutputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeResetLevel(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeResetLevel* const _this, SFlowNodeConfig& _config)>(0x2BF980);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeResetLevel* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x2BFC10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeResetLevel* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkSaveLoadSystem
// Header:  CryEngine/cryaction/ark/ArkSaveLoadSystem.h
class ArkSaveLoadSystem : public IArkSaveLoadSystem
{ // Size=360 (0x168)
public:
	// ArkSaveLoadSystem::LevelOriginInfo
	// Header:  CryEngine/cryaction/ark/ArkSaveLoadSystem.h
	struct LevelOriginInfo
	{ // Size=24 (0x18)
		string originalLevelName;
		unsigned originalId;
		unsigned currentId;
		bool originallyUnremovable;

	#if 0
		LevelOriginInfo();
		LevelOriginInfo(const char* const _arg0_, const unsigned _arg1_, const unsigned _arg2_, const bool _arg3_);
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::vector<CArkFlowNodeOnSaveLoaded*> m_onSaveLoadedNodes;
	std::vector<CFlowStartNode*> m_startNodes;
	std::vector<CPlaySequence_Node*> m_trackViewNodes;
	std::vector<IArkSaveLoadListener*> m_listeners;
	std::array<std::unordered_map<string, CPlayerProfileManager::SSaveGameMetaData>, 3> m_cachedMetadata;
	std::vector<ArkSaveLoadSystem::LevelOriginInfo> m_levelOrigins;
	std::vector<string> m_visitedLevels;
	XmlNodeRef m_captureVolumeStates;
	int m_campaignSlot;
	bool m_bNeedToRestoreLevelState;
	bool m_bRestoringLevelState;

	ArkSaveLoadSystem();
	void RequestLevelStateRestore() { FRequestLevelStateRestore(this); }
	void LoadCurrentLevelState(CGameSerialize& _gameSerialize) { FLoadCurrentLevelState(this, _gameSerialize); }
	virtual bool InLevelTransition() const;
	virtual bool IsRestoringLevelState() const;
	void RegisterStartNode(CFlowStartNode& _node) { FRegisterStartNode(this, _node); }
	void UnregisterStartNode(CFlowStartNode& _node) { FUnregisterStartNode(this, _node); }
	void RegisterOnSaveLoadedNode(CArkFlowNodeOnSaveLoaded& _node) { FRegisterOnSaveLoadedNode(this, _node); }
	void UnregisterOnSaveLoadedNode(CArkFlowNodeOnSaveLoaded& _node) { FUnregisterOnSaveLoadedNode(this, _node); }
	void SerializePersistentState(TSerialize _serialize) { FSerializePersistentState(this, _serialize); }
	virtual void OnSaveGameLoaded();
	virtual void SetCampaignSlot(const int _slot);
	virtual int GetCampaignSlot() const;
	void SaveCurrentLevelState(CGameSerialize& _gameSerialize) { FSaveCurrentLevelState(this, _gameSerialize); }
	virtual void RegisterListener(IArkSaveLoadListener* _pListener);
	virtual void UnregisterListener(IArkSaveLoadListener* _pListener);
	void SetMetadata(const string& _saveName, CPlayerProfileManager::SSaveGameMetaData& _data) { FSetMetadata(this, _saveName, _data); }
	void SetLevelOrigin(SBasicEntityData& _bed, const IEntity& _entity) const { FSetLevelOrigin(this, _bed, _entity); }
	boost::optional<CPlayerProfileManager::SSaveGameMetaData> GetMetadata(const string& _saveName) const { alignas(boost::optional<CPlayerProfileManager::SSaveGameMetaData>) std::byte _return_buf_[sizeof(boost::optional<CPlayerProfileManager::SSaveGameMetaData>)]; return *FGetMetadata(this, reinterpret_cast<boost::optional<CPlayerProfileManager::SSaveGameMetaData>*>(_return_buf_), _saveName); }
	void AddLevelVisitationDataToMetadata(ISaveGame& _saveGame) const { FAddLevelVisitationDataToMetadata(this, _saveGame); }
	void LoadLevelVisitationData(SLoadEnvironment& _loadEnv) { FLoadLevelVisitationData(this, _loadEnv); }
	void ForgetLevel(string _levelName) { FForgetLevel(this, _levelName); }
	virtual void ClearMetadataCache();

#if 0
	void RegisterTrackViewNode(CPlaySequence_Node& _arg0_);
	void UnregisterTrackViewNode(CPlaySequence_Node& _arg0_);
	void DeleteMetadata(const string& _arg0_);
	static XmlNodeRef GetCaptureVolumeStates();
#endif

	static inline auto FArkSaveLoadSystemOv2 = PreyFunction<void(ArkSaveLoadSystem* const _this)>(0x2C4740);
	static inline auto FRequestLevelStateRestore = PreyFunction<void(ArkSaveLoadSystem* const _this)>(0x2C89E0);
	static inline auto FLoadCurrentLevelState = PreyFunction<void(ArkSaveLoadSystem* const _this, CGameSerialize& _gameSerialize)>(0x2C7950);
	static inline auto FInLevelTransition = PreyFunction<bool(const ArkSaveLoadSystem* const _this)>(0x2C77A0);
	static inline auto FIsRestoringLevelState = PreyFunction<bool(const ArkSaveLoadSystem* const _this)>(0x2C7940);
	static inline auto FRegisterStartNode = PreyFunction<void(ArkSaveLoadSystem* const _this, CFlowStartNode& _node)>(0x2C89C0);
	static inline auto FUnregisterStartNode = PreyFunction<void(ArkSaveLoadSystem* const _this, CFlowStartNode& _node)>(0x2C9930);
	static inline auto FRegisterOnSaveLoadedNode = PreyFunction<void(ArkSaveLoadSystem* const _this, CArkFlowNodeOnSaveLoaded& _node)>(0x2C89A0);
	static inline auto FUnregisterOnSaveLoadedNode = PreyFunction<void(ArkSaveLoadSystem* const _this, CArkFlowNodeOnSaveLoaded& _node)>(0x159C1E0);
	static inline auto FSerializePersistentState = PreyFunction<void(ArkSaveLoadSystem* const _this, TSerialize _serialize)>(0x2C9760);
	static inline auto FOnSaveGameLoaded = PreyFunction<void(ArkSaveLoadSystem* const _this)>(0x2C88F0);
	static inline auto FSetCampaignSlot = PreyFunction<void(ArkSaveLoadSystem* const _this, const int _slot)>(0x2C97B0);
	static inline auto FGetCampaignSlot = PreyFunction<int(const ArkSaveLoadSystem* const _this)>(0x2C7490);
	static inline auto FSaveCurrentLevelState = PreyFunction<void(ArkSaveLoadSystem* const _this, CGameSerialize& _gameSerialize)>(0x2C89F0);
	static inline auto FRegisterListener = PreyFunction<void(ArkSaveLoadSystem* const _this, IArkSaveLoadListener* _pListener)>(0x2C8950);
	static inline auto FUnregisterListener = PreyFunction<void(ArkSaveLoadSystem* const _this, IArkSaveLoadListener* _pListener)>(0x2C98F0);
	static inline auto FSetMetadata = PreyFunction<void(ArkSaveLoadSystem* const _this, const string& _saveName, CPlayerProfileManager::SSaveGameMetaData& _data)>(0x4DF270);
	static inline auto FSetLevelOrigin = PreyFunction<void(const ArkSaveLoadSystem* const _this, SBasicEntityData& _bed, const IEntity& _entity)>(0x2C97C0);
	static inline auto FGetMetadata = PreyFunction<boost::optional<CPlayerProfileManager::SSaveGameMetaData>*(const ArkSaveLoadSystem* const _this, boost::optional<CPlayerProfileManager::SSaveGameMetaData>* _return_value_, const string& _saveName)>(0x547800);
	static inline auto FAddLevelVisitationDataToMetadata = PreyFunction<void(const ArkSaveLoadSystem* const _this, ISaveGame& _saveGame)>(0x2C6FC0);
	static inline auto FLoadLevelVisitationData = PreyFunction<void(ArkSaveLoadSystem* const _this, SLoadEnvironment& _loadEnv)>(0x2C81E0);
	static inline auto FForgetLevel = PreyFunction<void(ArkSaveLoadSystem* const _this, string _levelName)>(0x2C72F0);
	static inline auto FClearMetadataCache = PreyFunction<void(ArkSaveLoadSystem* const _this)>(0x2C7280);
};

// Load
// Header:  CryEngine/cryaction/ark/ArkSaveLoadSystem.h
class Load : public ILoadGame
{ // Size=40 (0x28)
public:
	using TContexts = std::vector<_smart_ptr<CXmlSerializeHelper>>;

	XmlNodeRef m_root;
	std::vector<_smart_ptr<CXmlSerializeHelper>> m_sections;

	virtual bool Init(const char* const _pName);
	virtual unsigned GetPlatformUserId() const;
	virtual IGeneralMemoryHeap* GetHeap();
	virtual const char* GetMetadata(const char* _pTag);
	virtual bool GetMetadata(const char* _pTag, int& _value);
	virtual bool HaveMetadata(const char* _pTag);
	virtual std::unique_ptr<TSerialize> GetSection(const char* _pSection);
	virtual bool HaveSection(const char* _pSection);
	virtual void Complete();
	virtual const char* GetFileName() const;

#if 0
	Load(XmlNodeRef _arg0_);
#endif

	static inline auto FInit = PreyFunction<bool(Load* const _this, const char* const _pName)>(0x2C77B0);
	static inline auto FGetPlatformUserId = PreyFunction<unsigned(const Load* const _this)>(0xA554A0);
	static inline auto FGetHeap = PreyFunction<IGeneralMemoryHeap* (Load* const _this)>(0x1CBB0B0);
	static inline auto FGetMetadataOv1 = PreyFunction<const char* (Load* const _this, const char* _pTag)>(0x1CBB0B0);
	static inline auto FGetMetadataOv0 = PreyFunction<bool(Load* const _this, const char* _pTag, int& _value)>(0x2C7620);
	static inline auto FHaveMetadata = PreyFunction<bool(Load* const _this, const char* _pTag)>(0x1A302A0);
	static inline auto FGetSection = PreyFunction<std::unique_ptr<TSerialize>*(Load* const _this, std::unique_ptr<TSerialize>* _return_value_, const char* _pSection)>(0x2C7690);
	static inline auto FHaveSection = PreyFunction<bool(Load* const _this, const char* _pSection)>(0x2C7760);
	static inline auto FComplete = PreyFunction<void(Load* const _this)>(0x3E3960);
	static inline auto FGetFileName = PreyFunction<const char* (const Load* const _this)>(0x1CBB0B0);
};

// Save
// Header:  CryEngine/cryaction/ark/ArkSaveLoadSystem.h
class Save : public ISaveGame
{ // Size=48 (0x30)
public:
	using TContexts = std::vector<_smart_ptr<CXmlSerializeHelper>>;

	XmlNodeRef m_root;
	XmlNodeRef m_parentNode;
	std::vector<_smart_ptr<CXmlSerializeHelper>> m_sections;

	virtual bool Init(const char* _pName);
	virtual void AddMetadata(const char* _pTag, const char* _pValue);
	virtual void AddMetadata(const char* _pTag, int _value);
	virtual XmlNodeRef GetMetadata() const;
	virtual TSerialize AddSection(const char* _pSection);
	virtual uint8_t* SetThumbnail(const uint8_t* _pImageData, int _width, int _height, int _depth);
	virtual bool SetThumbnailFromBMP(const char* _pFilename);
	virtual bool Complete(bool _bSuccessfulSoFar);
	virtual const char* GetFileName() const;
	virtual void SetSaveGameReason(ESaveGameReason _reason);
	virtual ESaveGameReason GetSaveGameReason() const;
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	Save(XmlNodeRef _arg0_);
#endif

	static inline auto FInit = PreyFunction<bool(Save* const _this, const char* _pName)>(0x2C7830);
	static inline auto FAddMetadataOv1 = PreyFunction<void(Save* const _this, const char* _pTag, const char* _pValue)>(0x1333E90);
	static inline auto FAddMetadataOv0 = PreyFunction<void(Save* const _this, const char* _pTag, int _value)>(0x2C7160);
	static inline auto FGetMetadata = PreyFunction<XmlNodeRef*(const Save* const _this, XmlNodeRef* _return_value_)>(0x361570);
	static inline auto FAddSection = PreyFunction<TSerialize*(Save* const _this, TSerialize* _return_value_, const char* _pSection)>(0x2C71C0);
	static inline auto FSetThumbnail = PreyFunction<uint8_t* (Save* const _this, const uint8_t* _pImageData, int _width, int _height, int _depth)>(0x1CBB0B0);
	static inline auto FSetThumbnailFromBMP = PreyFunction<bool(Save* const _this, const char* _pFilename)>(0x13B0900);
	static inline auto FComplete = PreyFunction<bool(Save* const _this, bool _bSuccessfulSoFar)>(0x2C72D0);
	static inline auto FGetFileName = PreyFunction<const char* (const Save* const _this)>(0x1CBB0B0);
	static inline auto FSetSaveGameReason = PreyFunction<void(Save* const _this, ESaveGameReason _reason)>(0x1333E90);
	static inline auto FGetSaveGameReason = PreyFunction<ESaveGameReason(const Save* const _this)>(0x4FD7F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const Save* const _this, ICrySizer* _pSizer)>(0x2C75D0);
};
#endif // !MOONCRASH
