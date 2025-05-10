#pragma once

namespace Internal
{

struct ILogManager : IChairService<ILogManager>
{
	static const char* NameImpl() { return "ILogManager"; }

	virtual ~ILogManager() {}

	//! @returns the number of messages in the log manager.
	virtual size_t GetMessageCount() = 0;

	//! Puts idx-th message into the buffer.
	virtual void GetMessage(size_t idx, char* buf, size_t bufSize) = 0;
};

} // namespace Internal
