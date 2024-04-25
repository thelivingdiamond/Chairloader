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
	void AddMessage(const char* text, size_t size, bool inOverlay = false);

	size_t GetMessageCount() override;
    size_t GetOverlayMessageCount();
	void GetMessage(size_t idx, char* buf, size_t bufSize) override;
    void GetOverlayMessage(size_t idx, char* buf, size_t bufSize, uint64_t* time);
    void RemoveOverlayMessage(size_t idx);
private:
	//! Size of the message circular buffer.
	static constexpr size_t MAX_MSG_COUNT = 4096;

	struct Message
	{
		std::string text;
        uint64_t time = 0;
	};

	std::vector<Message> m_Messages;
    std::vector<Message> m_OverlayMessages;
	size_t m_MessagesEnd = 0;

	// Messages from non-main thread
	threadID m_MainThreadId = 0;
	std::mutex m_ThreadQueueMutex;
	std::vector<Message> m_ThreadQueue;
    std::vector<Message> m_OverlayThreadQueue;

	Message& GetNewMessage();
	std::vector<Message> GetQueuedMessages();
    std::vector<Message> GetOverlayQueuedMessages();
};
