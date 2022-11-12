#include "LogManager.h"

static LogManager s_LogManager;

LogManager& LogManager::Get()
{
	return s_LogManager;
}

void LogManager::InitSystem()
{
	m_MainThreadId = gEnv->mMainThreadId;
	m_Messages.reserve(MAX_MSG_COUNT);
}

void LogManager::Update()
{
	std::vector<Message> msgs = GetQueuedMessages();
	for (Message& msg : msgs)
	{
		Message& newMsg = GetNewMessage();
		newMsg = std::move(msg);
	}
}

void LogManager::AddMessage(const char* text, size_t size)
{
	if (m_MainThreadId == CryGetCurrentThreadId())
	{
		// Add to the buffer
		Message& msg = GetNewMessage();
		msg.text = std::string(text, size);
	}
	else
	{
		// Push to the queue
		Message msg;
		msg.text = std::string(text, size);
		std::scoped_lock lock(m_ThreadQueueMutex);
		m_ThreadQueue.emplace_back(std::move(msg));
	}
}

LogManager::Message& LogManager::GetNewMessage()
{
	if (m_Messages.size() < MAX_MSG_COUNT)
	{
		// Add new message
		m_MessagesEnd = (m_MessagesEnd + 1) % MAX_MSG_COUNT;
		return m_Messages.emplace_back();
	}
	else
	{
		size_t idx = m_MessagesEnd;
		m_MessagesEnd = (m_MessagesEnd + 1) % MAX_MSG_COUNT;
		return m_Messages[idx];
	}
}

std::vector<LogManager::Message> LogManager::GetQueuedMessages()
{
	std::vector<LogManager::Message> result;
	std::scoped_lock lock(m_ThreadQueueMutex);
	m_ThreadQueue.swap(result);
	return result;
}
