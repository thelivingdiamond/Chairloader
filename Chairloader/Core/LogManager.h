#pragma once
#include <Prey/CryThreading/CryThread.h>
#include <Chairloader/ILogManager.h>

class LogManager : public Internal::ILogManager
{
public:
	static LogManager& Get();
	LogManager();

	//! Initializes the logger
	void InitSystem();

	//! Processes queue messages from other threads.
	void Update();

	//! Adds a message to the log buffer.
	void AddMessage(const char* text, size_t size);

	size_t GetMessageCount() override;
	void GetMessage(size_t idx, char* buf, size_t bufSize) override;

private:
	//! Size of the message circular buffer.
	static constexpr size_t MAX_MSG_COUNT = 4096;

	struct Message
	{
		std::string text;
	};

	std::vector<Message> m_Messages;
	size_t m_MessagesEnd = 0;

	// Messages from non-main thread
	threadID m_MainThreadId = 0;
	std::mutex m_ThreadQueueMutex;
	std::vector<Message> m_ThreadQueue;

	Message& GetNewMessage();
	std::vector<Message> GetQueuedMessages();
};
