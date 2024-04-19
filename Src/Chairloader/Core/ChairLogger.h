#pragma once
#include <Chairloader/IChairLogger.h>

class ChairLogger : public IChairLogger
{
public:
	// IChairLogger
	void Log(EChairLogType type, const char* msg, size_t size) override;
    void OverlayLog(EChairLogType type, const char *msg, size_t size) override;

    void FatalError(const char* msg) override;
	const char* GetName() override;
	void SetName(const char* name) override;

private:
	//! Size of the stack-allocatd buffer for the message.
	//! Larger strings will go to the heap.
	static constexpr size_t PRINT_MSG_BUF_SIZE = 256;

	std::string m_Name;
};
