#include "LogManager.h"

static LogManager s_LogManager;

LogManager& LogManager::Get()
{
	return s_LogManager;
}

LogManager::LogManager()
{
	m_MainThreadId = CryGetCurrentThreadId();
	m_Messages.reserve(MAX_MSG_COUNT);
}

void LogManager::InitSystem()
{
	if (m_MainThreadId != gEnv->mMainThreadId)
		CryFatalError("LogManager wasn't constructed on the main thread");
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

size_t LogManager::GetMessageCount()
{
	return m_Messages.size();
}

void LogManager::GetMessage(size_t idx, char* buf, size_t bufSize)
{
	cry_strcpy(buf, bufSize, m_Messages[idx].text.data(), m_Messages[idx].text.size());
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
