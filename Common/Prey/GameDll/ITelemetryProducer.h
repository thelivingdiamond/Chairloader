// Header file automatically created from a PDB.
#pragma once

// ITelemetryProducer
// Header:  _unknown/ITelemetryProducer.h
struct ITelemetryProducer
{ // Size=8 (0x8)
	enum EResult
	{
		eTS_Pending = 0,
		eTS_Available = 1,
		eTS_EndOfStream = 2,
	};

	virtual ~ITelemetryProducer();
	virtual ITelemetryProducer::EResult ProduceTelemetry(char* pOutBuffer, int inMinRequired, int inBufferSize, int* pOutWritten) = 0;

#if 0
	static void* operator new(uint64_t _arg0_);
#endif
};

