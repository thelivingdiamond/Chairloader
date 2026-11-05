// Header file automatically created from a PDB.
#pragma once

class ICrySizer;

// ITelemetryCollector
// Header:  _unknown/ITelemetryCollector.h
class ITelemetryCollector
{ // Size=8 (0x8)
public:
	enum
	{
		k_tf_none = 0,
		k_tf_appendToRemoteFile = 1,
		k_tf_gzipRemoteFile = 2,
		k_tf_chunked = 4,
		k_tf_md5Digest = 8,
		k_tf_isStream = 16,
	};

	using TTelemetrySubmitFlags = unsigned;

	virtual ~ITelemetryCollector();
	virtual bool SubmitFromMemory(const char* inRemoteFilePath, const char* inDataToStore, const int inDataLength, unsigned inFlags) = 0;
	virtual bool SubmitFile(const char* inLocalFilePath, const char* inRemoteFilePath, const char* inHeaderData, const int inHeaderLength) = 0;
	virtual bool SubmitLargeFile(const char* inLocalFilePath, const char* inRemoteFilePath, int inLocalFileOffset, const char* inHintFileData, const int inHintFileDataLength, unsigned inFlags) = 0;
	virtual bool AppendStringToFile(const char* inLocalFilePath, const char* inDataToAppend) = 0;
	virtual bool AppendToFile(const char* inRemoteFilePath, const char* inDataToAppend, const int inDataLength) = 0;
	virtual void OutputMemoryUsage(const char* message, const char* newLevelName) = 0;
	virtual void SetNewSessionId(bool includeMatchDetails) = 0;
	virtual string GetSessionId() = 0;
	virtual void SetSessionId(string inNewId) = 0;
	virtual bool ShouldSubmitTelemetry() = 0;
	virtual void Update() = 0;
	virtual bool AreTransfersInProgress() = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
};

