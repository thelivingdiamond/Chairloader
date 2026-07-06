// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedarray.h>
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CrySystem/ZLib/IZLibCompressor.h>
#include <Prey/CryThreading/CryThread_win32.h>
#include <_unknown/CryFixedStringT.h>
#include <_unknown/ITelemetryCollector.h>
#include <_unknown/ITelemetryProducer.h>

class CDownloadableResource;
class CStreamedTelemetryProxy;
enum ECryTCPServiceResult;
struct ICVar;
struct IConsoleCmdArgs;
class ICrySizer;
struct ICryTCPService;
struct ILevel;
struct ILevelInfo;
struct IZLibDeflateStream;
struct SCrySessionID;
struct STCPServiceData;

// CTelemetryCollector
// Header:  Prey/GameDll/TelemetryCollector.h
class CTelemetryCollector : public ITelemetryCollector, public ILevelSystemListener
{ // Size=137544 (0x21948)
public:
	// CTelemetryCollector::SQueuedProducer
	// Header:  Prey/GameDll/TelemetryCollector.h
	struct SQueuedProducer
	{ // Size=40 (0x28)
		ITelemetryProducer* pProducer;
		string postHeader;
		void (*callback)(void*, bool, const char*, int);
		void* callbackData;
		unsigned flags;
	};

	// CTelemetryCollector::SLargeFileSubmitData
	// Header:  Prey/GameDll/TelemetryCollector.h
	struct SLargeFileSubmitData
	{ // Size=68664 (0x10C38)
		enum class EState
		{
			k_state_available = 0,
			k_state_chunk_submitted_waiting = 1,
			k_state_chunk_submitted_send_next_one = 2,
			k_state_chunked_transfer_data_available = 3,
			k_state_chunked_transfer_data_ended = 4,
			k_state_submitted = 5,
			k_state_dispatchCallbacksAndClear = 6,
		};

		char m_remoteFileName[2048];
		char m_chunkData[65536];
		char m_postHeaderContents[1024];
		int m_postHeaderSize;
		int m_chunkDataSize;
		ITelemetryProducer* m_pProducer;
		bool m_isFirstChunk;
		unsigned m_flags;
		_smart_ptr<CDownloadableResource> m_pDownloadableResource;
		void (*m_callback)(void*, bool, const char*, int);
		void* m_callbackData;
		CTelemetryCollector::SLargeFileSubmitData::EState m_state;

		void Clear() { FClear(this); }

	#if 0
		SLargeFileSubmitData();
		~SLargeFileSubmitData();
	#endif

		static inline auto FClear = PreyFunction<void(CTelemetryCollector::SLargeFileSubmitData* const _this)>(0x191B630);
	};

	static constexpr const int k_maxHttpHeaderSize = 1024;
	static inline auto s_telemetryCollector = PreyGlobal<CTelemetryCollector*>(0x2D93920);
	ICVar* m_telemetryTransactionRecordings;
	ICVar* m_telemetryEnabled;
	ICVar* m_telemetryServerLogging;
	ICVar* m_telemetryUploadErrorLog;
	ICVar* m_telemetryUploadGameLog;
	ICVar* m_telemetryCompressGameLog;
	ICVar* m_telemetryUploadInProgress;
	string m_curSessionId;
	string m_websafeClientName;
	CryMutex m_largeFileMutex;
	_smart_ptr<CStreamedTelemetryProxy> m_eventsStream;
	CryMutex m_transferCounterMutex;
	int m_transfersCounter;
	int m_lastLevelRotationIndex;
	bool m_previousSessionCrashChecked;
	bool m_previousSessionCrashed;
	_smart_ptr<ICryTCPService> m_pTelemetry;
	std::queue<CTelemetryCollector::SQueuedProducer,std::deque<CTelemetryCollector::SQueuedProducer,std::allocator<CTelemetryCollector::SQueuedProducer> > > m_queuedTransfers;
	static constexpr const int k_maxNumLargeFilesSubmitting = 2;
	static constexpr const int k_largeFileSubmitChunkSize = 65536;
	static constexpr const int k_largeFileSubmitChunkMaxDataSize = 64512;
	CryFixedArray<CTelemetryCollector::SLargeFileSubmitData,2> m_largeFileSubmits;
	ICVar* m_telemetryCompressionLevel;
	ICVar* m_telemetryCompressionWindowBits;
	ICVar* m_telemetryCompressionMemLevel;

	CryFixedStringT<257> GetHostName() { alignas(CryFixedStringT<257>) std::byte _return_buf_[sizeof(CryFixedStringT<257>)]; return *FGetHostName(this, reinterpret_cast<CryFixedStringT<257>*>(_return_buf_)); }
	void UpdateClientName() { FUpdateClientName(this); }
	static void SubmitGameLog(IConsoleCmdArgs* inArgs) { FSubmitGameLog(inArgs); }
	static void OutputSessionId(IConsoleCmdArgs* inArgs) { FOutputSessionId(inArgs); }
	bool InitService() { return FInitService(this); }
	bool UploadData(_smart_ptr<STCPServiceData> pData, const char* inReferenceFileName) { return FUploadData(this, pData, inReferenceFileName); }
	int MakePostHeader(const char* inRemoteFileName, int inDataLength, char* outBuffer, int inMaxBufferSize, unsigned inFlags) { return FMakePostHeader(this, inRemoteFileName, inDataLength, outBuffer, inMaxBufferSize, inFlags); }
	void UpdateLargeFileChunkPostHeader(CTelemetryCollector::SLargeFileSubmitData* pInLargeFile, bool inFirstChunk, int inPayloadSize) { FUpdateLargeFileChunkPostHeader(this, pInLargeFile, inFirstChunk, inPayloadSize); }
	void UploadLastGameLogToPreviousSession() { FUploadLastGameLogToPreviousSession(this); }
	static bool SubmitFileTelemetryCallback(ECryTCPServiceResult res, void* arg, _smart_ptr<STCPServiceData> pInUploadData, const char* pData, uint64_t dataLen, bool endOfStream) { return FSubmitFileTelemetryCallback(res, arg, pInUploadData, pData, dataLen, endOfStream); }
	bool TrySubmitTelemetryProducer(ITelemetryProducer* pInProducer, const char* inPostHeader, int inLen, void (*inCallback)(void*, bool, const char*, int), void* inCallbackData, unsigned inFlags) { return FTrySubmitTelemetryProducer(this, pInProducer, inPostHeader, inLen, inCallback, inCallbackData, inFlags); }
	void ThreadSafeClear(CTelemetryCollector::SLargeFileSubmitData* pInData) { FThreadSafeClear(this, pInData); }
	CTelemetryCollector();
	virtual ~CTelemetryCollector();
	virtual bool ShouldSubmitTelemetry();
	virtual void Update();
	void Log(int level, const char* format, ... _arg2_) { FLog(this, level, format, _arg2_); }
	virtual bool SubmitFromMemory(const char* inRemoteFilePath, const char* inDataToStore, const int inDataLength, unsigned inFlags);
	virtual bool SubmitFile(const char* inLocalFilePath, const char* inRemoteFilePath, const char* inHeaderData, const int inHeaderLength);
	virtual bool SubmitLargeFile(const char* inLocalFilePath, const char* inRemoteFilePath, int inLocalFileOffset, const char* inHintFileData, const int inHintFileDataLength, unsigned inFlags);
	bool SubmitTelemetryProducer(ITelemetryProducer* pInProducer, const char* pInRemoteFilePath, void (*inCallback)(void*, bool, const char*, int), void* inCallbackData, unsigned inFlags) { return FSubmitTelemetryProducer(this, pInProducer, pInRemoteFilePath, inCallback, inCallbackData, inFlags); }
	void SubmitChunkOfALargeFile(CTelemetryCollector::SLargeFileSubmitData* pInLargeSubmitData) { FSubmitChunkOfALargeFile(this, pInLargeSubmitData); }
	void UpdateLargeFileSubmitData() { FUpdateLargeFileSubmitData(this); }
	void CreateEventStream() { FCreateEventStream(this); }
	void CloseEventStream() { FCloseEventStream(this); }
	void CreateStatoscopeStream() { FCreateStatoscopeStream(this); }
	void CloseStatoscopeStream() { FCloseStatoscopeStream(this); }
	void LogEvent(const char* eventName, float value) { FLogEvent(this, eventName, value); }
	virtual bool AppendStringToFile(const char* inLocalFilePath, const char* inDataToAppend);
	virtual bool AppendToFile(const char* inRemoteFilePath, const char* inDataToAppend, const int inDataLength);
	virtual void SetNewSessionId(bool includeMatchDetails);
	virtual void OutputMemoryUsage(const char* message, const char* newLevelName);
	virtual string GetSessionId();
	virtual void SetSessionId(string inNewId);
	virtual bool AreTransfersInProgress();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual void OnLevelNotFound(const char* levelName);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo* pLevel);
	virtual void OnLoadingStart(ILevelInfo* pLevel);
	virtual void OnLoadingComplete(ILevel* pLevel);
	virtual void OnLoadingError(ILevelInfo* pLevel, const char* error);
	virtual void OnLoadingProgress(ILevelInfo* pLevel, int progressAmount);
	virtual void OnUnloadComplete(ILevel* pLevel);

#if 0
	static CTelemetryCollector* GetTelemetryCollector();
	CryFixedStringT<257> GetProfileName();
	const char* GetWebSafePlatformName();
	string GetWebSafeClientName();
	string GetWebSafeSessionId();
	int GetIndexOfFirstValidCharInFilePath(const char* _arg0_, const int _arg1_, const bool _arg2_, const bool _arg3_);
	bool MoveLogFileOutOfTheWay(const char* _arg0_, const char* _arg1_);
	bool ShouldUploadGameLog(bool _arg0_);
	bool UploadFileForPreviousSession(const char* _arg0_, const char* _arg1_);
	bool UploadLargeFileForPreviousSession(const char* _arg0_, const char* _arg1_, unsigned _arg2_);
	void CheckForPreviousSessionCrash();
	void UpdateTransfersInProgress(int _arg0_);
	CTelemetryCollector::SLargeFileSubmitData* GetAvailableLargeFileSubmitData();
	CTelemetryCollector::SLargeFileSubmitData* FindLargeFileSubmitDataFromData(const char* _arg0_);
	void UpdateQueuedProducers();
	bool CanLogEvent() const;
	void SetAbortedSessionId(const char* _arg0_, _smart_ptr<SCrySessionID>& _arg1_);
	void SetTestSessionId();
	void OutputTelemetryServerHintFile();
#endif

	static inline auto FGetHostName = PreyFunction<CryFixedStringT<257>*(CTelemetryCollector* const _this, CryFixedStringT<257>* _return_value_)>(0x191B7D0);
	static inline auto FUpdateClientName = PreyFunction<void(CTelemetryCollector* const _this)>(0x191E810);
	static inline auto FSubmitGameLog = PreyFunction<void(IConsoleCmdArgs* inArgs)>(0x191DA70);
	static inline auto FOutputSessionId = PreyFunction<void(IConsoleCmdArgs* inArgs)>(0x191C110);
	static inline auto FInitService = PreyFunction<bool(CTelemetryCollector* const _this)>(0x191BAF0);
	static inline auto FUploadData = PreyFunction<bool(CTelemetryCollector* const _this, _smart_ptr<STCPServiceData> pData, const char* inReferenceFileName)>(0x191F0D0);
	static inline auto FMakePostHeader = PreyFunction<int(CTelemetryCollector* const _this, const char* inRemoteFileName, int inDataLength, char* outBuffer, int inMaxBufferSize, unsigned inFlags)>(0x191BBF0);
	static inline auto FUpdateLargeFileChunkPostHeader = PreyFunction<void(CTelemetryCollector* const _this, CTelemetryCollector::SLargeFileSubmitData* pInLargeFile, bool inFirstChunk, int inPayloadSize)>(0x191EA00);
	static inline auto FUploadLastGameLogToPreviousSession = PreyFunction<void(CTelemetryCollector* const _this)>(0x191F260);
	static inline auto FSubmitFileTelemetryCallback = PreyFunction<bool(ECryTCPServiceResult res, void* arg, _smart_ptr<STCPServiceData> pInUploadData, const char* pData, uint64_t dataLen, bool endOfStream)>(0x191D4E0);
	static inline auto FTrySubmitTelemetryProducer = PreyFunction<bool(CTelemetryCollector* const _this, ITelemetryProducer* pInProducer, const char* inPostHeader, int inLen, void (*inCallback)(void*, bool, const char*, int), void* inCallbackData, unsigned inFlags)>(0x191E4C0);
	static inline auto FThreadSafeClear = PreyFunction<void(CTelemetryCollector* const _this, CTelemetryCollector::SLargeFileSubmitData* pInData)>(0x191E450);
	static inline auto FCTelemetryCollector = PreyFunction<void(CTelemetryCollector* const _this)>(0x191A920);
	static inline auto FBitNotCTelemetryCollector = PreyFunction<void(CTelemetryCollector* const _this)>(0x191AF20);
	static inline auto FShouldSubmitTelemetry = PreyFunction<bool(CTelemetryCollector* const _this)>(0x191CFA0);
	static inline auto FUpdate = PreyFunction<void(CTelemetryCollector* const _this)>(0x191E6F0);
	static inline auto FLog = PreyFunction<void(CTelemetryCollector* const _this, int level, const char* format, ... _arg2_)>(0x191BBA0);
	static inline auto FSubmitFromMemory = PreyFunction<bool(CTelemetryCollector* const _this, const char* inRemoteFilePath, const char* inDataToStore, const int inDataLength, unsigned inFlags)>(0x191D8E0);
	static inline auto FSubmitFile = PreyFunction<bool(CTelemetryCollector* const _this, const char* inLocalFilePath, const char* inRemoteFilePath, const char* inHeaderData, const int inHeaderLength)>(0x191D1F0);
	static inline auto FSubmitLargeFile = PreyFunction<bool(CTelemetryCollector* const _this, const char* inLocalFilePath, const char* inRemoteFilePath, int inLocalFileOffset, const char* inHintFileData, const int inHintFileDataLength, unsigned inFlags)>(0x191DDD0);
	static inline auto FSubmitTelemetryProducer = PreyFunction<bool(CTelemetryCollector* const _this, ITelemetryProducer* pInProducer, const char* pInRemoteFilePath, void (*inCallback)(void*, bool, const char*, int), void* inCallbackData, unsigned inFlags)>(0x191E1F0);
	static inline auto FSubmitChunkOfALargeFile = PreyFunction<void(CTelemetryCollector* const _this, CTelemetryCollector::SLargeFileSubmitData* pInLargeSubmitData)>(0x191D020);
	static inline auto FUpdateLargeFileSubmitData = PreyFunction<void(CTelemetryCollector* const _this)>(0x191EF10);
	static inline auto FCreateEventStream = PreyFunction<void(CTelemetryCollector* const _this)>(0x1333E90);
	static inline auto FCloseEventStream = PreyFunction<void(CTelemetryCollector* const _this)>(0x1333E90);
	static inline auto FCreateStatoscopeStream = PreyFunction<void(CTelemetryCollector* const _this)>(0x1333E90);
	static inline auto FCloseStatoscopeStream = PreyFunction<void(CTelemetryCollector* const _this)>(0x1333E90);
	static inline auto FLogEvent = PreyFunction<void(CTelemetryCollector* const _this, const char* eventName, float value)>(0x1333E90);
	static inline auto FAppendStringToFile = PreyFunction<bool(CTelemetryCollector* const _this, const char* inLocalFilePath, const char* inDataToAppend)>(0x191B5B0);
	static inline auto FAppendToFile = PreyFunction<bool(CTelemetryCollector* const _this, const char* inRemoteFilePath, const char* inDataToAppend, const int inDataLength)>(0x191B5D0);
	static inline auto FSetNewSessionId = PreyFunction<void(CTelemetryCollector* const _this, bool includeMatchDetails)>(0x191C930);
	static inline auto FOutputMemoryUsage = PreyFunction<void(CTelemetryCollector* const _this, const char* message, const char* newLevelName)>(0x1333E90);
	static inline auto FGetSessionId = PreyFunction<string*(CTelemetryCollector* const _this, string* _return_value_)>(0x191BAC0);
	static inline auto FSetSessionId = PreyFunction<void(CTelemetryCollector* const _this, string inNewId)>(0x191CEA0);
	static inline auto FAreTransfersInProgress = PreyFunction<bool(CTelemetryCollector* const _this)>(0x191B5F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CTelemetryCollector* const _this, ICrySizer* pSizer)>(0x191BA50);
	static inline auto FOnLevelNotFound = PreyFunction<void(ILevelSystemListener* const _this, const char* levelName)>(0x1333E90);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0x1333E90);
	static inline auto FOnLoadingStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0x1333E90);
	static inline auto FOnLoadingComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0x1333E90);
	static inline auto FOnLoadingError = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, const char* error)>(0x1333E90);
	static inline auto FOnLoadingProgress = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, int progressAmount)>(0x1333E90);
	static inline auto FOnUnloadComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0x1333E90);
};

// CTelemetryCompressor
// Header:  Prey/GameDll/TelemetryCollector.h
class CTelemetryCompressor : public ITelemetryProducer
{ // Size=40 (0x28)
public:
	ITelemetryProducer* m_pSource;
	ITelemetryProducer::EResult m_lastSourceResult;
	int m_lastUncompressedSize;
	IZLibDeflateStream* m_zstream;
	bool m_dataIncoming;

	virtual ~CTelemetryCompressor();
	virtual ITelemetryProducer::EResult ProduceTelemetry(char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten);

#if 0
	CTelemetryCompressor(ITelemetryProducer* _arg0_);
#endif

	static inline auto FProduceTelemetry = PreyFunction<ITelemetryProducer::EResult(CTelemetryCompressor* const _this, char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten)>(0x191C160);
};

// CTelemetryFileReader
// Header:  Prey/GameDll/TelemetryCollector.h
class CTelemetryFileReader : public ITelemetryProducer
{ // Size=296 (0x128)
public:
	CryFixedStringT<256> m_localFilePath;
	int m_fileOffset;

	virtual ITelemetryProducer::EResult ProduceTelemetry(char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten);

#if 0
	CTelemetryFileReader(const char* _arg0_, int _arg1_);
#endif

	static inline auto FProduceTelemetry = PreyFunction<ITelemetryProducer::EResult(CTelemetryFileReader* const _this, char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten)>(0x191C380);
};

// CTelemetryHTTPPostChunkSplitter
// Header:  Prey/GameDll/TelemetryCollector.h
class CTelemetryHTTPPostChunkSplitter : public ITelemetryProducer
{ // Size=24 (0x18)
public:
	enum class EState
	{
		k_writeChunks = 0,
		k_writeFooter = 1,
		k_writeTerminatingChunkAndFooter = 2,
		k_done = 3,
	};

	ITelemetryProducer* m_producer;
	int m_contentLength;
	CTelemetryHTTPPostChunkSplitter::EState m_state;

	virtual ~CTelemetryHTTPPostChunkSplitter();
	virtual ITelemetryProducer::EResult ProduceTelemetry(char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten);

#if 0
	CTelemetryHTTPPostChunkSplitter(ITelemetryProducer* _arg0_);
#endif

	static inline auto FProduceTelemetry = PreyFunction<ITelemetryProducer::EResult(CTelemetryHTTPPostChunkSplitter* const _this, char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten)>(0x191C5A0);
};

// CTelemetryMD5
// Header:  Prey/GameDll/TelemetryCollector.h
class CTelemetryMD5 : public ITelemetryProducer
{ // Size=112 (0x70)
public:
	enum class EState
	{
		k_producingData = 0,
		k_writingHash = 1,
		k_finished = 2,
	};

	ITelemetryProducer* m_pSource;
	SMD5Context m_context;
	CTelemetryMD5::EState m_state;
	int m_bytesMD5ed;

	virtual ~CTelemetryMD5();
	virtual ITelemetryProducer::EResult ProduceTelemetry(char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten);

#if 0
	CTelemetryMD5(const char* _arg0_, ITelemetryProducer* _arg1_);
#endif

	static inline auto FProduceTelemetry = PreyFunction<ITelemetryProducer::EResult(CTelemetryMD5* const _this, char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten)>(0x191C840);
};
#endif // MOONCRASH
