// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryCore/smartptr.h>
#include <Prey/GameDll/gamemechanismmanager/GameMechanismBase.h>
#include <_unknown/IPatchPakManagerListener.h>

class CDownloadableResource;
enum ECryTCPServiceResult;
struct ICryTCPService;
struct IDataListener;
struct STCPServiceData;
class XmlNodeRef;

// CDownloadMgr
// Header:  Prey/GameDll/DownloadMgr.h
class CDownloadMgr : public CGameMechanismBase, public IPatchPakManagerListener
{ // Size=56 (0x38)
public:
	using TResourceVector = std::vector<_smart_ptr<CDownloadableResource>>;

	std::vector<_smart_ptr<CDownloadableResource>> m_resources;

	void DispatchCallbacks() { FDispatchCallbacks(this); }
	virtual void Update(float inDt);
	CDownloadMgr();
	virtual ~CDownloadMgr();
	void Reset() { FReset(this); }
	void Init(const char* pTCPServicesDescriptionFile, const char* pInResourceDescriptionsFile) { FInit(this, pTCPServicesDescriptionFile, pInResourceDescriptionsFile); }
	virtual void UpdatedPermissionsNowAvailable();
	_smart_ptr<CDownloadableResource> FindResourceByName(const char* inResourceName) { alignas(_smart_ptr<CDownloadableResource>) std::byte _return_buf_[sizeof(_smart_ptr<CDownloadableResource>)]; return *FFindResourceByName(this, reinterpret_cast<_smart_ptr<CDownloadableResource>*>(_return_buf_), inResourceName); }

#if 0
	static bool ReceiveDataCallback(ECryTCPServiceResult _arg0_, void* _arg1_, const char* _arg2_, uint64_t _arg3_, bool _arg4_);
	void UpdateRemoveListeners();
	_smart_ptr<CDownloadableResource> FindLocalizedResourceByName(const char* _arg0_);
	void PurgeLocalizedResourceByName(const char* _arg0_);
	void WaitForDownloadsToFinish(const char* * _arg0_, int _arg1_, float _arg2_);
#endif

	static inline auto FDispatchCallbacks = PreyFunction<void(CDownloadMgr* const _this)>(0x17D7D30);
	static inline auto FUpdate = PreyFunction<void(CDownloadMgr* const _this, float inDt)>(0x17D9580);
	static inline auto FCDownloadMgrOv1 = PreyFunction<void(CDownloadMgr* const _this)>(0x17D7580);
	static inline auto FReset = PreyFunction<void(CDownloadMgr* const _this)>(0x17D9130);
	static inline auto FInit = PreyFunction<void(CDownloadMgr* const _this, const char* pTCPServicesDescriptionFile, const char* pInResourceDescriptionsFile)>(0x17D8380);
	static inline auto FUpdatedPermissionsNowAvailable = PreyFunction<void(IPatchPakManagerListener* const _this)>(0x1333E90);
	static inline auto FFindResourceByName = PreyFunction<_smart_ptr<CDownloadableResource>*(CDownloadMgr* const _this, _smart_ptr<CDownloadableResource>* _return_value_, const char* inResourceName)>(0x17D7E80);
};

// CDownloadableResource
// Header:  Prey/GameDll/DownloadMgr.h
class CDownloadableResource : public CMultiThreadRefCount
{ // Size=632 (0x278)
public:
	enum class #unnamed_enum_k_invalidState
	{
		k_invalidState = 0,
		DownloadableResourceStates_neg1 = -1,
		BITINDEX_k_notStarted = 0,
		BITINDEX_k_failedServerUnreachable = 1,
		BITINDEX_k_failedInternalError = 2,
		BITINDEX_k_failedReplyHasBadHeader = 3,
		BITINDEX_k_failedReplyContentTooLong = 4,
		BITINDEX_k_failedReplyContentTruncated = 5,
		BITINDEX_k_failedUnknownResource = 6,
		BITINDEX_k_failedAborted = 7,
		BITINDEX_k_failedReplyTimedOut = 8,
		BITINDEX_k_awaitingHTTPResponse = 9,
		BITINDEX_k_awaitingPayload = 10,
		BITINDEX_k_dataAvailable = 11,
		DownloadableResourceStates_numBits = 12,
		k_notStarted = 1,
		k_failedServerUnreachable = 2,
		k_failedInternalError = 4,
		k_failedReplyHasBadHeader = 8,
		k_failedReplyContentTooLong = 16,
		k_failedReplyContentTruncated = 32,
		k_failedUnknownResource = 64,
		k_failedAborted = 128,
		k_failedReplyTimedOut = 256,
		k_awaitingHTTPResponse = 512,
		k_awaitingPayload = 1024,
		k_dataAvailable = 2048,
	};

	enum class EListenerBroadcastedState
	{
		k_notBroadcasted = 0,
		k_broadcastedSuccess = 1,
		k_broadcastedFail = 2,
	};

	using TState = unsigned;
	using TListenerVector = std::vector<IDataListener*>;

	static constexpr const unsigned k_callbackInProgressMask = 1536;
	static constexpr const unsigned k_dataPermanentFailMask = 510;
	static constexpr const unsigned k_dataSoftFailMask = 258;
	std::vector<IDataListener*> m_listeners;
	std::vector<IDataListener*> m_listenersToRemove;
	CryFixedStringT<32> m_serviceConfigName;
	CryFixedStringT<128> m_urlPrefix;
	CryFixedStringT<128> m_url;
	CryFixedStringT<32> m_descName;
	CryFixedStringT<64> m_server;
	int m_port;
	int m_maxDownloadSize;
	CDownloadableResource::EListenerBroadcastedState m_broadcastedState;
	_smart_ptr<ICryTCPService> m_pService;
	_smart_ptr<CDownloadableResource> m_isLocalisedInstanceOf;
	char* m_pBuffer;
	int m_bufferUsed;
	int m_bufferSize;
	int m_contentLength;
	int m_contentOffset;
	unsigned m_state;
	bool m_abortDownload;
	bool m_doingHTTPParse;

	void LoadConfig(XmlNodeRef inNode) { FLoadConfig(this, inNode); }
	void UpdateRemoveListeners() { FUpdateRemoveListeners(this); }
	void BroadcastFail() { FBroadcastFail(this); }
	bool ReceiveHTTPHeader(bool inReceivedEndOfStream) { return FReceiveHTTPHeader(this, inReceivedEndOfStream); }
	static bool ReceiveDataCallback(ECryTCPServiceResult res, void* pArg, _smart_ptr<STCPServiceData> pUpload, const char* pData, uint64_t dataLen, bool endOfStream) { return FReceiveDataCallback(res, pArg, pUpload, pData, dataLen, endOfStream); }
	void InitHTTPParser() { FInitHTTPParser(this); }
	void ReleaseHTTPParser() { FReleaseHTTPParser(this); }
	CDownloadableResource();
	virtual ~CDownloadableResource();
	void StartDownloading() { FStartDownloading(this); }
	unsigned GetRawData(char* * pOutData, int* pOutLen) { return FGetRawData(this, pOutData, pOutLen); }
	unsigned GetDecryptedData(char* pBuffer, int* pOutLen, const char* pDecryptionKey, int decryptionKeyLength, const char* pSigningSalt, int signingSaltLength) { return FGetDecryptedData(this, pBuffer, pOutLen, pDecryptionKey, decryptionKeyLength, pSigningSalt, signingSaltLength); }
	void AddDataListener(IDataListener* pInListener) { FAddDataListener(this, pInListener); }
	void RemoveDataListener(IDataListener* pInListener) { FRemoveDataListener(this, pInListener); }
	void CancelDownload() { FCancelDownload(this); }

#if 0
	bool Validate();
	void BroadcastSuccess();
	bool StoreData(const char* _arg0_, uint64_t _arg1_);
	bool DecryptAndCheckSigning(const char* _arg0_, int _arg1_, char* * _arg2_, int* _arg3_, const char* _arg4_, int _arg5_, const char* _arg6_, int _arg7_);
	void Reset();
	void SetDownloadInfo(const char* _arg0_, const char* _arg1_, const char* _arg2_, const int _arg3_, const int _arg4_, const char* _arg5_);
	void GetUserAgentString(CryFixedStringT<64>& _arg0_);
	unsigned GetState() const;
	unsigned GetProgress(int* _arg0_, int* _arg1_);
	bool HasBroadcastedResults();
	const char* GetDescription();
	const char* GetURL();
	const char* GetURLPrefix();
	const char* GetServer();
	int GetPort();
	int GetMaxSize();
	bool Purge();
	void DispatchCallbacks();
#endif

	static inline auto FLoadConfig = PreyFunction<void(CDownloadableResource* const _this, XmlNodeRef inNode)>(0x17D87B0);
	static inline auto FUpdateRemoveListeners = PreyFunction<void(CDownloadableResource* const _this)>(0x17D9590);
	static inline auto FBroadcastFail = PreyFunction<void(CDownloadableResource* const _this)>(0x17D7C80);
	static inline auto FReceiveHTTPHeader = PreyFunction<bool(CDownloadableResource* const _this, bool inReceivedEndOfStream)>(0x17D8DE0);
	static inline auto FReceiveDataCallback = PreyFunction<bool(ECryTCPServiceResult res, void* pArg, _smart_ptr<STCPServiceData> pUpload, const char* pData, uint64_t dataLen, bool endOfStream)>(0x17D8B50);
	static inline auto FInitHTTPParser = PreyFunction<void(CDownloadableResource* const _this)>(0x17D8790);
	static inline auto FReleaseHTTPParser = PreyFunction<void(CDownloadableResource* const _this)>(0x17D90A0);
	static inline auto FCDownloadableResourceOv1 = PreyFunction<void(CDownloadableResource* const _this)>(0x17D77C0);
	static inline auto FBitNotCDownloadableResource = PreyFunction<void(CDownloadableResource* const _this)>(0x17D7930);
	static inline auto FStartDownloading = PreyFunction<void(CDownloadableResource* const _this)>(0x17D9210);
	static inline auto FGetRawData = PreyFunction<unsigned(CDownloadableResource* const _this, char* * pOutData, int* pOutLen)>(0x17D8320);
	static inline auto FGetDecryptedData = PreyFunction<unsigned(CDownloadableResource* const _this, char* pBuffer, int* pOutLen, const char* pDecryptionKey, int decryptionKeyLength, const char* pSigningSalt, int signingSaltLength)>(0x17D80E0);
	static inline auto FAddDataListener = PreyFunction<void(CDownloadableResource* const _this, IDataListener* pInListener)>(0x17D7C00);
	static inline auto FRemoveDataListener = PreyFunction<void(CDownloadableResource* const _this, IDataListener* pInListener)>(0x17D9110);
	static inline auto FCancelDownload = PreyFunction<void(CDownloadableResource* const _this)>(0x17D7CF0);
};

// IDataListener
// Header:  Prey/GameDll/DownloadMgr.h
struct IDataListener
{ // Size=8 (0x8)
	virtual void DataDownloaded(_smart_ptr<CDownloadableResource> inResource) = 0;
	virtual void DataFailedToDownload(_smart_ptr<CDownloadableResource> inResource) = 0;
	virtual ~IDataListener();

	static inline auto FBitNotIDataListener = PreyFunction<void(IDataListener* const _this)>(0x17D7AE0);
};
#endif // MOONCRASH
