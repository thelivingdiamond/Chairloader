#include "ChairLogger.h"
#include "LogManager.h"
#include "OverlayLog.h"

static void CryLogf(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	gEnv->pLog->LogV(ILog::eAlways, format, args);
	va_end(args);
}

void ChairLogger::Log(EChairLogType type, const char* msg, size_t size)
{
	CryStackStringT<char, PRINT_MSG_BUF_SIZE> buf;

	// Mod name
	buf.append("[$3");
	buf.append(m_Name.c_str(), m_Name.size());
	buf.append("$0] ");

	// Prefix
	const char* prefix = nullptr;
	switch (type)
	{
	case EChairLogType::Message:
		// None
		break;
	case EChairLogType::Warning:
		prefix = "$6[Warning] ";
		break;
	case EChairLogType::Error:
		prefix = "$4[Error] ";
		break;
	default:
		CryFatalError("[ChairLogger::Log][{}] Unknown log type", m_Name);
		break;
	}

	if (prefix)
		buf.append(prefix);

	buf.append(msg, size);

	// Log to the engine logger
	CryLogf("%s", buf.c_str());

	// Log to the log manager
	LogManager::Get().AddMessage(buf.c_str(), buf.size());
}

void ChairLogger::FatalError(const char* msg)
{
	if (gEnv && gEnv->pSystem)
	{
		gEnv->pSystem->FatalError("[%s] %s", m_Name.c_str(), msg);
	}
	else
	{
		fprintf(stderr, "FATAL ERROR!\n");
		fprintf(stderr, "gEnv->pSystem->FatalError not available!\n");
		fprintf(stderr, "[%s] %s\n", m_Name.c_str(), msg);
	}

	// Must not return
	std::abort();
}

const char* ChairLogger::GetName()
{
	return m_Name.c_str();
}

void ChairLogger::SetName(const char* name)
{
	m_Name = name;
}

void ChairLogger::OverlayLog(EChairLogType type, const char *msg, size_t size) {
    CryStackStringT<char, PRINT_MSG_BUF_SIZE> buf;

    // Mod name
    buf.append("[$3");
    buf.append(m_Name.c_str(), m_Name.size());
    buf.append("$0] ");

    // Prefix
    const char* prefix = nullptr;
    switch (type)
    {
        case EChairLogType::Message:
            // None
            break;
        case EChairLogType::Warning:
            prefix = "$6[Warning] ";
            break;
        case EChairLogType::Error:
            prefix = "$4[Error] ";
            break;
        default:
            CryFatalError("[ChairLogger::Log][{}] Unknown log type", m_Name);
            break;
    }

    if (prefix)
        buf.append(prefix);

    buf.append(msg, size);

    // Log to the engine logger
    CryLogf("%s", buf.c_str());

    // Log to the log manager with overlay
    LogManager::Get().AddMessage(buf.c_str(), buf.size(), true);
}
