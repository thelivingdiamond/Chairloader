// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/smartptr.h>

enum ECryTCPServiceResult;

// STCPServiceData
// Header:  _unknown/STCPServiceData.h
struct STCPServiceData : public CMultiThreadRefCount
{ // Size=80 (0x50)
	void (*tcpServCb)(ECryTCPServiceResult, void*);
	bool (*tcpServReplyCb)(ECryTCPServiceResult, void*, _smart_ptr<STCPServiceData>, const char*, uint64_t, bool);
	float m_quietTimer;
	int m_socketIdx;
	void* pUserArg;
	char* pData;
	uint64_t length;
	uint64_t sent;
	bool ownsData;

	virtual ~STCPServiceData();

#if 0
	STCPServiceData();
	static void* operator new(uint64_t _arg0_);
#endif
};

