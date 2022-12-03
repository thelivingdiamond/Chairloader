#include <Chairloader/IChairLogger.h>

static std::unique_ptr<IChairLogger> g_pChairLogger = nullptr;

void ModuleInitIChairLogger(const char* modName)
{
	g_pChairLogger = gCL->cl->CreateLogger();
	g_pChairLogger->SetName(modName);
}

void ModuleShutdownIChairLogger()
{
	g_pChairLogger = nullptr;
}

void VCryLog(EChairLogType type, std::string_view format, fmt::format_args args)
{
	char buf[IChairLogger::MSG_BUF_SIZE];
	size_t requiredSize = fmt::vformat_to_n(buf, sizeof(buf), format, args).size;

	if (requiredSize <= sizeof(buf))
	{
		// Message fits into buf
		g_pChairLogger->Log(type, buf, requiredSize);
	}
	else
	{
		// Message was truncated, format again on the heap
		std::string text = fmt::vformat(format, args);
		g_pChairLogger->Log(type, text.c_str(), text.size());
	}
}

void VCryFatalError(std::string_view format, fmt::format_args args)
{
	std::string text = fmt::vformat(format, args);

	if (g_pChairLogger)
		g_pChairLogger->FatalError(text.c_str());
	else if (gEnv && gEnv->pSystem)
		gEnv->pSystem->FatalError("%s", text.c_str());

	std::abort();
}
